#pragma once

#include "kestrel/terminal/terminal.h"

typedef enum {
    LOG_LEVEL_TRACE,
    LOG_LEVEL_INFORMATION,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_SUCCESS,
} log_level_t;

void logger_initialize(terminal_t* terminal, log_level_t log_level);

void logger_set_level(log_level_t log_level);

void logger_format(log_level_t log_level, const char* format, ...)
    format_function(2, 3);

void logger_format_variadic(
    log_level_t log_level,
    const char* format,
    va_list arguments
);

#define logger_trace(...) logger_format(LOG_LEVEL_TRACE, __VA_ARGS__)

#define logger_information(...)                                                \
    logger_format(LOG_LEVEL_INFORMATION, __VA_ARGS__)

#define logger_debug(...) logger_format(LOG_LEVEL_DEBUG, __VA_ARGS__)

#define logger_warning(...) logger_format(LOG_LEVEL_WARNING, __VA_ARGS__)

#define logger_error(...) logger_format(LOG_LEVEL_ERROR, __VA_ARGS__)

#define logger_success(...) logger_format(LOG_LEVEL_SUCCESS, __VA_ARGS__)
