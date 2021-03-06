#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include "leveldb/db.h"
#include "s2/s2latlng.h"
#include "s2/s2cellid.h"

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

    const double kLat = 89.0 / 128.0;
    const double kLng = 179.0 / 128.0;

    // Add 256 values to the database
    leveldb::WriteOptions writeOptions;
    for (int i = 0; i < 256; ++i)
    {
        S2LatLng latlng = S2LatLng::FromDegrees(kLat * (-128 + i), kLng * (-128 + i)).Normalized();
        S2CellId cell = S2CellId::FromLatLng(latlng);

        std::ostringstream keyStream;
        keyStream << cell.ToToken();

        std::ostringstream valueStream;
        valueStream << "Test data value: " << latlng.ToStringInDegrees();

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

