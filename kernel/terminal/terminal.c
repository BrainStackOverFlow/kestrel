
#include "terminal/terminal.h"

#include "utility/string.h"

void terminal_initialize(terminal_t* terminal, frame_buffer_t* frame_buffer) {
    terminal->frame_buffer = frame_buffer;
    terminal->max_col = frame_buffer->width / FONT_CHARACTER_WIDTH;
    terminal->max_row = frame_buffer->height / FONT_CHARACTER_HEIGHT,
    terminal->col = 0;
    terminal->row = 0;
    terminal->foreground_color = green_color;
    terminal->background_color = black_color;
}

void terminal_draw_character(terminal_t* terminal, char character) {
    if ('\n' == character) {
        terminal->row++;
        terminal->col = 0;
    } else if ('\t' == character) {
        terminal->col += TAB_SIZE;
    } else {
        position_t position = {
            .x = terminal->col * FONT_CHARACTER_WIDTH,
            .y = terminal->row * FONT_CHARACTER_HEIGHT,
        };

        frame_buffer_draw_character(
            terminal->frame_buffer, &position,
            &standard_font_map.characters[(size_t)character],
            terminal->foreground_color, terminal->background_color);

        terminal->col++;
        if (terminal->max_col < terminal->col) {
            terminal->row++;
            terminal->col = 0;
        }
        if (terminal->max_row < terminal->row) {
            terminal->row = 0;
        }
    }
}

void terminal_draw_string(terminal_t* terminal, const char* string) {
    for (size_t i = 0; i < string_length(string); i++) {
        terminal_draw_character(terminal, string[i]);
    }
}
