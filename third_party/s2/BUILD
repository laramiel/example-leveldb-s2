package(default_visibility = ["//visibility:public"])

licenses(["notice"])

filegroup(
    name = "license",
    srcs = ["upstream/LICENSE"],
)

cc_library(
    name = "s2",
    srcs = [
        "upstream/base/logging.cc",
        "upstream/strings/split.cc",
        "upstream/strings/stringprintf.cc",
        "upstream/strings/strtoint.cc",
        "upstream/strings/strutil.cc",
        # "upstream/util/math/exactfloat/exactfloat.cc",
        "upstream/util/math/mathlimits.cc",
        "upstream/util/math/mathutil.cc",
        "upstream/s1angle.cc",
        "upstream/s1interval.cc",
        "upstream/s2.cc",
        "upstream/s2cap.cc",
        "upstream/s2cell.cc",
        "upstream/s2cellid.cc",
        "upstream/s2cellunion.cc",
        "upstream/s2edgeindex.cc",
        "upstream/s2edgeutil.cc",
        "upstream/s2latlng.cc",
        "upstream/s2latlngrect.cc",
        "upstream/s2loop.cc",
        "upstream/s2pointregion.cc",
        "upstream/s2polygon.cc",
        "upstream/s2polygonbuilder.cc",
        "upstream/s2polyline.cc",
        "upstream/s2r2rect.cc",
        "upstream/s2region.cc",
        "upstream/s2regioncoverer.cc",
        "upstream/s2regionintersection.cc",
        "upstream/s2regionunion.cc",
    ],
    hdrs = glob(["upstream/*.h", 
                 "upstream/base/*.h",
                 "upstream/strings/*.h",
                 "upstream/util/math/*.h"]) + 
          ["upstream/util/hash/hash_jenkins_lookup2.h"],
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
)
