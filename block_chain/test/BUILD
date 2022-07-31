load("@rules_cc//cc:defs.bzl", "cc_library")

cc_test(
    name = "block_chain_test",
    srcs = ["block_chain_test.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//block_chain:block_chain",
        "//block_chain/data_types:data_types",
        "@com_google_googletest//:gtest_main",
    ],
)
