
#include "kestrel/graphics/frame_buffer.h"

#include <stdbool.h>

#include "kestrel/graphics/pixel.h"
#include "kestrel/utility/macro.h"

static void frame_buffer_draw_pixel(
    frame_buffer_t* framebuffer,
    position_t* position,
    color_t color
);

void frame_buffer_initialize(
    frame_buffer_t* frame_buffer,
    struct limine_framebuffer* limine_framebuffer
)
{
    frame_buffer->address = limine_framebuffer->address;
    frame_buffer->width = limine_framebuffer->width;
    frame_buffer->height = limine_framebuffer->height;
    frame_buffer->pitch = limine_framebuffer->pitch;
    frame_buffer->pixel_width = limine_framebuffer->bpp / 8;
}

void frame_buffer_draw_character(
    frame_buffer_t* frame_buffer,
    position_t* position,
    font_character_t* font_character,
    color_t foreground_color,
    color_t backound_color
)
{
    static const int row_masks[8]
        = { 1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7 };

    for (size_t font_y = 0; font_y < FONT_CHARACTER_HEIGHT; font_y++) {
        for (size_t font_x = 0; font_x < FONT_CHARACTER_WIDTH; font_x++) {
            bool is_foreground_color
                = font_character->rows[font_y] & row_masks[font_x];

            color_t pixel_color
                = is_foreground_color ? foreground_color : backound_color;

            position_t pixel_position = {
                .x = position->x + font_x,
                .y = position->y + font_y,
            };

            frame_buffer_draw_pixel(frame_buffer, &pixel_position, pixel_color);
        }
    }
}

static void frame_buffer_draw_pixel(
    frame_buffer_t* framebuffer,
    position_t* position,
    color_t color
)
{
    size_t framebuffer_offset = (position->y * framebuffer->pitch)
                              + (position->x * framebuffer->pixel_width);
    pixel_t* pixel
        = add_pointer(pixel_t*, framebuffer->address, framebuffer_offset);
    pixel->color = color;
}
