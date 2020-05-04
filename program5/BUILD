package(default_visibility = ["//visibility:public"])

cc_library(
  name = "dynamic_array",
  srcs = [
    "dynamic_array.h",
    "dynamic_array.cc",
  ],
)

cc_test(
    name = "tests",
    size = "small",
    srcs = [
      "test_dynamic_array.cc",
    ],
    deps = [
        ":dynamic_array",
        "@googletest//:gtest_main",
    ],
)
