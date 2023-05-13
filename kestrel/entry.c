#include <stdbool.h>

#include "external/limine/limine.h"
#include "external/printf/src/printf/printf.h"
#include "kestrel/libc/stdio.h"
#include "kestrel/terminal/terminal.h"

static volatile struct limine_framebuffer_request limine_framebuffer_request;
static volatile struct limine_entry_point_request entry_request;

void entry(void);
static noreturn void halt(void);

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

    terminal_draw_string(&terminal, "Hello, world!\n");

    // terminal_draw_format(&terminal, "%x\n", 0x69);

    // set_default_terminal(&terminal);
    // printf("A");

cleanup:

    halt();
}

static noreturn void halt(void)
{
    asm("cli");
    while (true) {
        asm("hlt");
    }
}

static volatile struct limine_framebuffer_request limine_framebuffer_request
    = { .id = LIMINE_FRAMEBUFFER_REQUEST, .revision = 0 };
static volatile struct limine_entry_point_request entry_request = {
    .id = LIMINE_ENTRY_POINT_REQUEST,
    .revision = 0,
    .entry = entry,
};
