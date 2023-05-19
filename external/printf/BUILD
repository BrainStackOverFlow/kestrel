cc_library(
    name = "printf",
    srcs = glob(["src/printf/**/*.c"]),
    hdrs = glob(["src/printf/**/*.h"]),
    defines = [
        "PRINTF_SUPPORT_EXPONENTIAL_SPECIFIERS=0",
        "PRINTF_SUPPORT_DECIMAL_SPECIFIERS=0",
    ],
    include_prefix = "external",
    includes = ["src"],
    strip_include_prefix = "src",
    visibility = ["//visibility:public"],
)
