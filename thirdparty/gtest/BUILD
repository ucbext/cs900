package(default_visibility = ["//visibility:public"])

cc_library(
    name = "gtest",
    srcs = [
        "googletest/src/gtest-all.cc",
    ],
    hdrs = glob([
        "**/*.h",
        "googletest/src/*.cc",
    ]),
    includes = [
        "googletest",
        "googletest/include",
    ],
    linkopts = ["-pthread"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "gtest_main",
    srcs = ["googletest/src/gtest_main.cc"],
    linkopts = ["-pthread"],
    visibility = ["//visibility:public"],
    deps = [":gtest"],
)
