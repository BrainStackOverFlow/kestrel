
#include "terminal/terminal.h"
#include <limine.h>

void entry(void);

static volatile struct limine_framebuffer_request limine_framebuffer_request
    = { .id = LIMINE_FRAMEBUFFER_REQUEST, .revision = 0 };

static volatile struct limine_entry_point_request entry_request = {
    .id = LIMINE_ENTRY_POINT_REQUEST,
    .revision = 0,
    .entry = entry,
};

static void hcf(void)
{
    asm("cli");
    for (;;) {
        asm("hlt");
    }
}

void entry(void)
{
    if (limine_framebuffer_request.response == NULL
        || limine_framebuffer_request.response->framebuffer_count < 1) {
        goto cleanup;
    }

    struct limine_framebuffer* limine_framebuffer
        = limine_framebuffer_request.response->framebuffers[0];

    frame_buffer_t frame_buffer;
    frame_buffer_initialize(&frame_buffer, limine_framebuffer);

    terminal_t terminal;
    terminal_initialize(&terminal, &frame_buffer);

    terminal_draw_string(&terminal, "Hello Kernel Mode!\n");

cleanup:
    hcf();
}
