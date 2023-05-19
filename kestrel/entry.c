#include <stdbool.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#include "external/limine/limine.h"
#pragma GCC diagnostic pop

#include "kestrel/libc/libc.h"
#include "kestrel/libc/stdio.h"
#include "kestrel/terminal/terminal.h"

static volatile struct limine_framebuffer_request limine_framebuffer_request;

void entry(void);
static noreturn void halt(void);

void entry(void)
{
    struct limine_framebuffer* limine_framebuffer = NULL;
    frame_buffer_t frame_buffer = { 0 };
    terminal_t terminal = { 0 };

    if ((NULL == limine_framebuffer_request.response)
        || (limine_framebuffer_request.response->framebuffer_count < 1)) {
        goto cleanup;
    }

    limine_framebuffer = limine_framebuffer_request.response->framebuffers[0];
    frame_buffer_initialize(&frame_buffer, limine_framebuffer);
    terminal_initialize(&terminal, &frame_buffer);

    set_default_terminal(&terminal);
    printf("Hello, world!\n");

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
