package(default_visibility = ["//visibility:public"])

licenses(["notice"])

filegroup(
    name = "license",
    srcs = ["upstream/LICENSE"],
)

cc_library(
    name = "base",
    srcs = glob(["upstream/s2/base/*.cc",
                 "upstream/s2/strings/*.cc",
                 "upstream/s2/util/math/*.cc", 
                 "upstream/s2/util/coding/*.cc", 
                 "upstream/s2/util/hash/*.cc"]),

    hdrs = glob(["upstream/s2/base/*.h",
                 "upstream/s2/strings/*.h",
                 "upstream/s2/util/math/*.h", 
                 "upstream/s2/util/coding/*.h", 
                 "upstream/s2/util/endian/*.h", 
                 "upstream/s2/util/hash/*.h"]),
    copts = [
        "-Wall",
        "-Wwrite-strings",
        "-Woverloaded-virtual",
        "-Wno-sign-compare",
        "-DS2_USE_EXACTFLOAT",
        "-DHASH_NAMESPACE=std",
        "-Wno-absolute-value",
        "-Wno-dynamic-class-memaccess",
        "-Wno-narrowing",
        "-std=c++11",
        "-Ithird_party/s2/upstream/s2",
    ],
    includes = ["upstream/s2"],
)

cc_library(
    name = "s2",
    srcs = [
        "upstream/s2/s1angle.cc",
        "upstream/s2/s1interval.cc",
        "upstream/s2/s2.cc",
        "upstream/s2/s2cap.cc",
        "upstream/s2/s2cell.cc",
        "upstream/s2/s2cellid.cc",
        "upstream/s2/s2cellunion.cc",
        "upstream/s2/s2edgeindex.cc",
        "upstream/s2/s2edgeutil.cc",
        "upstream/s2/s2latlng.cc",
        "upstream/s2/s2latlngrect.cc",
        "upstream/s2/s2loop.cc",
        "upstream/s2/s2pointregion.cc",
        "upstream/s2/s2polygon.cc",
        "upstream/s2/s2polygonbuilder.cc",
        "upstream/s2/s2polyline.cc",
        "upstream/s2/s2r2rect.cc",
        "upstream/s2/s2region.cc",
        "upstream/s2/s2regioncoverer.cc",
        "upstream/s2/s2regionintersection.cc",
        "upstream/s2/s2regionunion.cc",
    ],
    hdrs = glob(["upstream/s2/*.h"]),
    copts = [
        "-Wall",
        "-Wwrite-strings",
        "-Woverloaded-virtual",
        "-Wno-sign-compare",
        "-DS2_USE_EXACTFLOAT",
        "-DHASH_NAMESPACE=std",
        "-Wno-absolute-value",
        "-Wno-dynamic-class-memaccess",
        "-std=c++11",
        "-Ithird_party/s2/upstream",
    ],
    includes = ["upstream"],
    deps = [ ":base" ],
)
