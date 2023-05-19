#include "kestrel/logger/logger.h"

#include <stdarg.h>

#include "kestrel/graphics/color.h"
#include "kestrel/terminal/terminal.h"

typedef struct {
    terminal_t* terminal;
    log_level_t log_level;
} logger_t;

static logger_t logger = { 0 };

static const char* log_level_get_string(log_level_t log_level);
static color_t log_level_get_color(log_level_t log_level);

void logger_initialize(terminal_t* terminal, log_level_t log_level)
{
    logger.terminal = terminal;
    logger.log_level = log_level;

    terminal_set_foreground_color(logger.terminal, white_color);
    terminal_set_background_color(logger.terminal, black_color);
}

void logger_set_level(log_level_t log_level)
{
    logger.log_level = log_level;
}

void logger_format(log_level_t log_level, const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    logger_format_variadic(log_level, format, arguments);
    va_end(arguments);
}

void logger_format_variadic(
    log_level_t log_level,
    const char* format,
    va_list arguments
)
{
    if (logger.log_level > log_level) {
        return;
    }

    terminal_set_foreground_color(
        logger.terminal,
        log_level_get_color(log_level)
    );
    terminal_draw_format(
        logger.terminal,
        "[%-12s] ",
        log_level_get_string(log_level)
    );

    terminal_set_foreground_color(logger.terminal, white_color);
    terminal_draw_format_variadic(logger.terminal, format, arguments);
}

static const char* log_level_get_string(log_level_t log_level)
{
    switch (log_level) {
    case LOG_LEVEL_TRACE:
        return "TRACE";

    case LOG_LEVEL_INFORMATION:
        return "INFORMATION";

    case LOG_LEVEL_DEBUG:
        return "DEBUG";

    case LOG_LEVEL_WARNING:
        return "WARNING";

    case LOG_LEVEL_ERROR:
        return "ERROR";

    case LOG_LEVEL_SUCCESS:
        return "SUCCESS";

    default:
        return NULL;
    }
}

static color_t log_level_get_color(log_level_t log_level)
{
    switch (log_level) {
    case LOG_LEVEL_TRACE:
        return gray_color;

    case LOG_LEVEL_INFORMATION:
        return white_color;

    case LOG_LEVEL_DEBUG:
        return blue_color;

    case LOG_LEVEL_WARNING:
        return yellow_color;

    case LOG_LEVEL_ERROR:
        return red_color;

    case LOG_LEVEL_SUCCESS:
        return green_color;

    default:
        return black_color;
    }
}