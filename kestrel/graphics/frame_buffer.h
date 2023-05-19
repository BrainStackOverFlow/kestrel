#pragma once

#include "external/limine/limine.h"
#include "kestrel/graphics/color.h"
#include "kestrel/graphics/font.h"
#include "kestrel/graphics/position.h"

typedef struct {
    void* address;
    size_t width;
    size_t height;
    size_t pitch;
    size_t pixel_width;
} frame_buffer_t;

void frame_buffer_initialize(
    frame_buffer_t* frame_buffer,
    struct limine_framebuffer* limine_framebuffer
);

void frame_buffer_draw_character(
    const frame_buffer_t* frame_buffer,
    position_t position,
    const font_character_t* font_character,
    color_t foreground_color,
    color_t backound_color
);
