load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

new_git_repository(
    name = "limine",
    build_file = "limine/BUILD",
    remote = "https://github.com/limine-bootloader/limine.git",
    tag = "v4.20230503.0-binary",
)

new_git_repository(
    name = "printf",
    build_file = "printf/BUILD",
    remote = "https://github.com/eyalroz/printf.git",
    tag = "v6.1.0",
)
