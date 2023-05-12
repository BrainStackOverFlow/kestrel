#include "libc/stdio.h"
#include "pmm.h"
#include "printf/printf_support.h"
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

struct limine_memmap_request limine_memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0,
    .response = NULL,
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

    printf_init(&terminal);

    printf("Hello Kernel Mode!\n");

    pmm_t pmm;
    pmm_init(&pmm, limine_memmap_request.response);
    void* page = pmm_alloc_pages(&pmm, 1);
    printf("ALLOCATED PAGE: %p\n", page);

cleanup:
    hcf();
}
