package(default_visibility = ["//visibility:public"])

cc_library(
  name = "reverse",
  srcs = [
    "reverse.h",
    "reverse.cc",
  ],
)

cc_library(
  name = "ackermann",
  srcs = [
    "ackermann.h",
    "ackermann.cc",
  ],
)

cc_library(
  name = "linear_search",
  srcs = [
    "linear_search.h",
    "linear_search.cc",
  ],
)

cc_library(
  name = "binary_search",
  srcs = [
    "binary_search.h",
    "binary_search.cc",
  ],
)

cc_test(
    name = "tests",
    srcs = [
      "test.cc"
    ],
    size = "small",
    deps = [
        ":ackermann",
        ":reverse",
        ":linear_search",
        ":binary_search",
        "@googletest//:gtest_main",
    ],
)
