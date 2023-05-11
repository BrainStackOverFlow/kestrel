
#include "terminal/terminal.h"
#include <limine.h>

void _start(void);

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST, .revision = 0};

static volatile struct limine_entry_point_request entry_request = {
    .id = LIMINE_ENTRY_POINT_REQUEST,
    .revision = 0,
    .entry = _start,
};

static void hcf(void) {
    asm("cli");
    for (;;) {
        asm("hlt");
    }
}

void _start(void) {
    if (framebuffer_request.response == NULL ||
        framebuffer_request.response->framebuffer_count < 1) {
        goto cleanup;
    }

    struct limine_framebuffer* limine_framebuffer =
        framebuffer_request.response->framebuffers[0];

    frame_buffer_t frame_buffer;
    frame_buffer_initialize(&frame_buffer, limine_framebuffer);

    terminal_t terminal;
    terminal_initialize(&terminal, &frame_buffer);

    terminal_draw_string(&terminal, "Hello Kernel Mode!\n");

cleanup:
    hcf();
}
