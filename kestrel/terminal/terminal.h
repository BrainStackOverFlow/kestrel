#pragma once

#include <stdarg.h>

#include "kestrel/graphics/frame_buffer.h"
#include "kestrel/terminal/terminal.h"

#define TAB_SIZE 4

typedef struct {
    frame_buffer_t* frame_buffer;
    size_t max_col;
    size_t max_row;
    size_t col;
    size_t row;
    color_t foreground_color;
    color_t background_color;
} terminal_t;

void terminal_initialize(terminal_t* terminal, frame_buffer_t* frame_buffer);

void terminal_set_foreground_color(terminal_t* terminal, color_t color);

void terminal_set_background_color(terminal_t* terminal, color_t color);

void terminal_draw_character(terminal_t* terminal, char character);

void terminal_draw_string(terminal_t* terminal, const char* string);

void terminal_draw_format(terminal_t* terminal, const char* format, ...)
    format_function(2, 3);

void terminal_draw_format_variadic(
    terminal_t* terminal,
    const char* format,
    va_list arguments
);
