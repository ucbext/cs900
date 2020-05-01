package(default_visibility = ["//visibility:public"])

cc_library(
  name = "string_reverse",
  srcs = [
    "string_reverse.h",
    "string_reverse.cc",
  ],
)

cc_library(
  name = "word_separator",
  srcs = [
    "word_separator.h",
    "word_separator.cc",
  ],
)

cc_library(
  name = "password_verification",
  srcs = [
    "password_verification.h",
    "password_verification.cc",
  ],
)

cc_library(
  name = "dynamic_array",
  srcs = [
    "dynamic_array.h",
    "dynamic_array.cc",
  ],
)

cc_library(
  name = "retail_store",
  srcs = [
    "person.h",
    "person.cc",
    "customer.h",
    "customer.cc",
    "preferred_customer.h",
    "preferred_customer.cc",
  ],
)

cc_test(
    name = "tests",
    srcs = [
      "test_customer.cc",
      "test_dynamic_array.cc",
      "test_password_verification.cc",
      "test_preferred_customer.cc",
      "test_string_reverse.cc",
      "test_word_separator.cc",
    ],
    size = "small",
    deps = [
        ":string_reverse",
        ":word_separator",
        ":password_verification",
        ":dynamic_array",
        ":retail_store",
        "@googletest//:gtest_main",
    ],
)
