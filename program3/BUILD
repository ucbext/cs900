package(default_visibility = ["//visibility:public"])

cc_library(
    name = "reverse",
    srcs = [
        "reverse.cc",
        "reverse.h",
    ],
)

cc_library(
    name = "ackermann",
    srcs = [
        "ackermann.cc",
        "ackermann.h",
    ],
)

cc_library(
    name = "linear_search",
    srcs = [
        "linear_search.cc",
        "linear_search.h",
    ],
)

cc_library(
    name = "binary_search",
    srcs = [
        "binary_search.cc",
        "binary_search.h",
    ],
)

cc_test(
    name = "tests",
    size = "small",
    srcs = [
        "test_ackermann.cc",
        "test_binary_search.cc",
        "test_linear_search.cc",
        "test_reverse.cc",
    ],
    deps = [
        ":ackermann",
        ":binary_search",
        ":linear_search",
        ":reverse",
        "@googletest//:gtest_main",
    ],
)
