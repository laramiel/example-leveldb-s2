package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = [ "main.cpp" ],
    deps = [
        "//third_party/leveldb",
        "//external:s2",
    ],
    linkopts = [
        "-lssl",
        "-lcrypto",
    ],
)
