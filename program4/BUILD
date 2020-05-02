package(default_visibility = ["//visibility:public"])

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
    size = "small",
    srcs = [
      # "test_dynamic_array.cc",
      "test_password_verification.cc",
      # "test_retail_store.cc",
      "test_word_separator.cc",
    ],
    deps = [
        # ":dynamic_array",
        ":password_verification",
        # ":retail_store",
        ":word_separator",
        "@googletest//:gtest_main",
    ],
)
