"""
This file defines toolchain-related rules.
"""

load(
    "@bazel_tools//tools/cpp:cc_toolchain_config_lib.bzl",
    "feature",
    "flag_group",
    "flag_set",
    "tool_path",
)
load("@bazel_tools//tools/build_defs/cc:action_names.bzl", "ACTION_NAMES")

def kestrel_toolchain_config_implementation(ctx):
    """
    Implement the Kestrel toolchain.

    Args:
        ctx: Context

    Returns:
        Kestrel toolchain information
    """

    tool_paths = [
        tool_path(
            name = "gcc",
            path = "/usr/bin/gcc",
        ),
        tool_path(
            name = "ld",
            path = "/usr/bin/ld",
        ),
        tool_path(
            name = "ar",
            path = "/usr/bin/ar",
        ),
        tool_path(
            name = "cpp",
            path = "/bin/false",
        ),
        tool_path(
            name = "nm",
            path = "/bin/false",
        ),
        tool_path(
            name = "objdump",
            path = "/bin/false",
        ),
        tool_path(
            name = "strip",
            path = "/bin/false",
        ),
    ]

    builtin_include_directories = [
        "/usr/lib/gcc/x86_64-linux-gnu/11/include/",
        "/usr/include/",
    ]

    compile_actions = [
        ACTION_NAMES.c_compile,
        ACTION_NAMES.cpp_compile,
    ]

    link_actions = [
        ACTION_NAMES.cpp_link_executable,
        ACTION_NAMES.cpp_link_dynamic_library,
        ACTION_NAMES.cpp_link_nodeps_dynamic_library,
    ]

    features = [
        feature(
            name = "default_compile_flags",
            enabled = True,
            flag_sets = [
                flag_set(
                    actions = compile_actions,
                    flag_groups = ([
                        flag_group(
                            flags = [
                                "-nostdlib",
                                "-nodefaultlibs",
                                "-Werror",
                                "-Wall",
                                "-Wextra",
                                "-Wpedantic",
                                "-std=c2x",
                                "-ffreestanding",
                                "-fno-stack-protector",
                                "-fno-stack-check",
                                "-fno-pie",
                                "-fno-pic",
                                "-fno-plt",
                                "-m64",
                                "-march=x86-64",
                                "-mabi=sysv",
                                "-mno-80387",
                                "-mno-mmx",
                                "-mno-sse",
                                "-mno-sse2",
                                "-mno-red-zone",
                                "-mcmodel=kernel",
                            ],
                        ),
                    ]),
                ),
            ],
        ),
        feature(
            name = "default_link_flags",
            enabled = True,
            flag_sets = [
                flag_set(
                    actions = link_actions,
                    flag_groups = ([
                        flag_group(flags = [
                            "-nostdlib",
                            "-no-pie",
                        ]),
                    ]),
                ),
            ],
        ),
    ]

    return cc_common.create_cc_toolchain_config_info(
        ctx = ctx,
        features = features,
        cxx_builtin_include_directories = builtin_include_directories,
        toolchain_identifier = "kestrel-toolchain",
        host_system_name = "local",
        target_system_name = "local",
        target_cpu = "kestrel_cpu",
        target_libc = "unknown",
        compiler = "gcc",
        abi_version = "unknown",
        abi_libc_version = "unknown",
        tool_paths = tool_paths,
    )

kestrel_toolchain_config = rule(
    attrs = {},
    provides = [CcToolchainConfigInfo],
    implementation = kestrel_toolchain_config_implementation,
)
