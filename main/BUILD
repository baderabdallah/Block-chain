load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("@rules_python//python:defs.bzl", "py_binary")
load("@python_deps//:requirements.bzl", "requirement")



cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//block_chain:block_chain",
        "@com_google_googletest//:gtest_main",
    ],
)
