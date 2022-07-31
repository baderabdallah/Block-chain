load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "block_chain",
    srcs = [
    "block_chain.cpp",
    "block.cpp",],
    hdrs = [
    "block_chain.h",
    "block.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//block_chain/data_types:data_types",
    ],
)
