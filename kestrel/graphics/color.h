#pragma once

#include <stdint.h>

#include "kestrel/utility/macro.h"

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} color_t;

static_assert(
    sizeof(uint32_t) == sizeof(color_t),
    "Color size doesn't match uint32_t size"
);

extern const color_t black_color;
extern const color_t red_color;
extern const color_t green_color;
extern const color_t blue_color;
