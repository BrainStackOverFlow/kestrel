load(":rules.bzl", "kestrel_toolchain_config")

package(default_visibility = ["//visibility:public"])

filegroup(name = "empty")

cc_toolchain_suite(
    name = "kestrel_toolchain_suite",
    toolchains = {
        "kestrel_cpu": ":kestrel_toolchain",
        "k8": ":kestrel_toolchain",
    },
)

cc_toolchain(
    name = "kestrel_toolchain",
    all_files = ":empty",
    compiler_files = ":empty",
    dwp_files = ":empty",
    linker_files = ":empty",
    objcopy_files = ":empty",
    strip_files = ":empty",
    supports_param_files = 0,
    toolchain_config = ":kestrel_toolchain_config",
    toolchain_identifier = "kestrel-toolchain",
)

kestrel_toolchain_config(name = "kestrel_toolchain_config")
