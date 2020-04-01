package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "least_greatest",
    srcs = ["least_greatest.cc"],
)

cc_binary(
    name = "random_number_guessing",
    srcs = ["random_number_guessing.cc"],
)

cc_library(
    name = "lowest_score",
    srcs = [
        "lowest_score.cc",
        "lowest_score.h",
    ],
)

cc_library(
    name = "is_prime",
    srcs = [
        "is_prime.cc",
        "is_prime.h",
    ],
)

cc_binary(
    name = "payroll",
    srcs = ["payroll.cc"],
)

cc_test(
    name = "tests",
    size = "small",
    srcs = [
        "test_is_prime.cc",
        "test_lowest_score.cc",
    ],
    deps = [
        ":is_prime",
        ":lowest_score",
        "@googletest//:gtest_main",
    ],
)
