#pragma once

#include <limine.h>

#include "graphics/color.h"
#include "graphics/font.h"
#include "graphics/position.h"

typedef struct {
    void* address;
    size_t width;
    size_t height;
    size_t pitch;
    size_t pixel_width;
} frame_buffer_t;

void frame_buffer_initialize(frame_buffer_t* frame_buffer,
                             struct limine_framebuffer* limine_frame_buffer);

void frame_buffer_draw_character(frame_buffer_t* frame_buffer,
                                 position_t* position,
                                 font_character_t* font_character,
                                 color_t foreground_color,
                                 color_t backound_color);
