cc_binary(
    name = "kestrel",
    srcs = glob([
        "**/*.c",
        "**/*.h",
    ]),
    additional_linker_inputs = [":link.lds"],
    linkopts = ["-Wl,-T$(location :link.lds)"],
    visibility = ["//visibility:public"],
    deps = [
        "@limine",
        "@printf",
    ],
)
