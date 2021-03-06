package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # BSD 3-clause

filegroup(
    name = "license",
    srcs = ["upstream/COPYING"],
)

cc_library(
    name = "leveldb",
    srcs = [
        "upstream/db/builder.cc",
        "upstream/db/c.cc",
        "upstream/db/db_impl.cc",
        "upstream/db/db_iter.cc",
        "upstream/db/dbformat.cc",
        "upstream/db/filename.cc",
        "upstream/db/log_reader.cc",
        "upstream/db/log_writer.cc",
        "upstream/db/memtable.cc",
        "upstream/db/repair.cc",
        "upstream/db/table_cache.cc",
        "upstream/db/version_edit.cc",
        "upstream/db/version_set.cc",
        "upstream/db/write_batch.cc",
        "upstream/helpers/memenv/memenv.cc",
        "upstream/port/port_posix.cc",
        "upstream/port/port_posix_sse.cc",
        "upstream/table/block.cc",
        "upstream/table/block_builder.cc",
        "upstream/table/filter_block.cc",
        "upstream/table/format.cc",
        "upstream/table/iterator.cc",
        "upstream/table/merger.cc",
        "upstream/table/table.cc",
        "upstream/table/table_builder.cc",
        "upstream/table/two_level_iterator.cc",
        "upstream/util/arena.cc",
        "upstream/util/bloom.cc",
        "upstream/util/cache.cc",
        "upstream/util/coding.cc",
        "upstream/util/comparator.cc",
        "upstream/util/crc32c.cc",
        "upstream/util/env.cc",
        "upstream/util/env_posix.cc",
        "upstream/util/filter_policy.cc",
        "upstream/util/hash.cc",
        "upstream/util/histogram.cc",
        "upstream/util/logging.cc",
        "upstream/util/options.cc",
        "upstream/util/status.cc",
    ],
    hdrs = [
        "upstream/db/builder.h",
        "upstream/db/db_impl.h",
        "upstream/db/db_iter.h",
        "upstream/db/dbformat.h",
        "upstream/db/filename.h",
        "upstream/db/log_format.h",
        "upstream/db/log_reader.h",
        "upstream/db/log_writer.h",
        "upstream/db/memtable.h",
        "upstream/db/skiplist.h",
        "upstream/db/snapshot.h",
        "upstream/db/table_cache.h",
        "upstream/db/version_edit.h",
        "upstream/db/version_set.h",
        "upstream/db/write_batch_internal.h",
        "upstream/helpers/memenv/memenv.h",
        "upstream/include/leveldb/c.h",
        "upstream/include/leveldb/cache.h",
        "upstream/include/leveldb/comparator.h",
        "upstream/include/leveldb/db.h",
        "upstream/include/leveldb/env.h",
        "upstream/include/leveldb/filter_policy.h",
        "upstream/include/leveldb/iterator.h",
        "upstream/include/leveldb/options.h",
        "upstream/include/leveldb/slice.h",
        "upstream/include/leveldb/status.h",
        "upstream/include/leveldb/table.h",
        "upstream/include/leveldb/table_builder.h",
        "upstream/include/leveldb/write_batch.h",
        "upstream/port/atomic_pointer.h",
        "upstream/port/port.h",
        "upstream/port/port_example.h",
        "upstream/port/port_posix.h",
        "upstream/port/thread_annotations.h",
        "upstream/port/win/stdint.h",
        "upstream/table/block.h",
        "upstream/table/block_builder.h",
        "upstream/table/filter_block.h",
        "upstream/table/format.h",
        "upstream/table/iterator_wrapper.h",
        "upstream/table/merger.h",
        "upstream/table/two_level_iterator.h",
        "upstream/util/arena.h",
        "upstream/util/coding.h",
        "upstream/util/crc32c.h",
        "upstream/util/env_posix_test_helper.h",
        "upstream/util/hash.h",
        "upstream/util/histogram.h",
        "upstream/util/logging.h",
        "upstream/util/mutexlock.h",
        "upstream/util/posix_logger.h",
        "upstream/util/random.h",
    ],
    copts = [
        "-Wno-non-virtual-dtor",
        "-Wno-unused-variable",
        "-Wno-implicit-fallthrough",
        "-Wno-unused-function",
        "-Wno-sign-compare", # snappy
        "-O2",
        "-DNDEBUG",
        "-DSNAPPY",
        "-Ithird_party/leveldb/upstream",
    ],
    defines = [
        "LEVELDB_PLATFORM_POSIX",
    ],
    includes = ["upstream/include"],
    linkopts = [
        "-lstdc++",
        "-lpthread",
    ],
    deps = ["//third_party/snappy"],
)
