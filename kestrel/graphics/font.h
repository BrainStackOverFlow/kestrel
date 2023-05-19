#pragma once

#include <limits.h>
#include <stdint.h>

#include "kestrel/utility/macro.h"

#define FONT_CHARACTER_WIDTH 8
#define FONT_CHARACTER_HEIGHT 16
#define FONT_CHARACTER_COUNT 128

typedef struct {
    uint8_t rows[FONT_CHARACTER_HEIGHT];
} font_character_t;

static_assert(
    sizeof(uint8_t) * CHAR_BIT == FONT_CHARACTER_WIDTH,
    "Line width doesn't match uint8_t bit count"
);

typedef struct {
    font_character_t characters[FONT_CHARACTER_COUNT];
} font_t;

extern const font_t standard_font;
