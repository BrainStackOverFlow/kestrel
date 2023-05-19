load(":rules.bzl", "image")

image(
    name = "image",
    srcs = [
        "limine.cfg",
        "//kestrel",
        "@limine//:sys",
    ],
    cd = "@limine//:cd",
    efi = "@limine//:efi",
)

sh_binary(
    name = "emulator",
    srcs = ["emulator.bash"],
    args = [
        "$(location :image)",
        "run",
    ],
    data = ["//image"],
)

sh_binary(
    name = "debuggee",
    srcs = ["emulator.bash"],
    args = [
        "$(location :image)",
        "debug",
    ],
    data = ["//image"],
)

sh_binary(
    name = "debugger",
    srcs = ["debugger.bash"],
    args = ["$(location //kestrel)"],
    data = ["//kestrel"],
)
