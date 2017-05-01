#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include "leveldb/db.h"
#include "s2/s2latlng.h"

int main(int argc, char **argv)
{
    // Set up database connection information and open database
    std::unique_ptr<leveldb::DB> db;
    {
        leveldb::DB *tmp = nullptr;
        leveldb::Options options;
        options.create_if_missing = true;

        leveldb::Status status = leveldb::DB::Open(options, "./testdb", &tmp);
        if (!status.ok())
        {
            std::cerr << "Unable to open/create test database './testdb'" << std::endl;
            std::cerr << status.ToString() << std::endl;
            return -1;
        }
        db.reset(tmp);
    }

    // Add 256 values to the database
    leveldb::WriteOptions writeOptions;
    for (unsigned int i = 0; i < 256; ++i)
    {
        std::ostringstream keyStream;
        keyStream << "Key" << i;

        S2LatLng x = S2LatLng::FromDegrees(0.1 * i, 0.2 * i);

        std::ostringstream valueStream;
        valueStream << "Test data value: " << x.ToStringInDegrees();

        db->Put(writeOptions, keyStream.str(), valueStream.str());
    }

    // Iterate over each item in the database and print them
    {
        std::unique_ptr<leveldb::Iterator> it(db->NewIterator(leveldb::ReadOptions()));
        for (it->SeekToFirst(); it->Valid(); it->Next())
        {
            std::cout << it->key().ToString() << " : " << it->value().ToString() << std::endl;
        }

        if (!it->status().ok())
        {
            std::cerr << "An error was found during the scan" << std::endl;
            std::cerr << it->status().ToString() << std::endl;
        }
        // Close the iterator
    }
    // Close the database
}

>>> import s2
>>> latlng = s2.S2LatLng.FromDegrees(-30.043800, -51.140220)
>>> cell = s2.S2CellId.FromLatLng(latlng)
>>> cell.level()
30
>>> cell.id()
10743750136202470315
>>> cell.ToToken()
951977d377e723ab