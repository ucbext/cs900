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
    "lowest_score.h",
    "lowest_score.cc"
  ],
)

cc_library(
  name = "is_prime",
  srcs = [
    "is_prime.h",
    "is_prime.cc"
  ],
)

cc_binary(
  name = "payroll",
  srcs = ["payroll.cc"],
)

cc_test(
    name = "tests",
    srcs = [
      "test.cc"
    ],
    size = "small",
    deps = [
        ":lowest_score",
        ":is_prime",
        "@googletest//:gtest_main",
    ],
)
