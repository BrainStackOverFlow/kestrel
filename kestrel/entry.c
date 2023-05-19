#include <stdbool.h>

#include "external/limine/limine.h"
#include "kestrel/logger/logger.h"
#include "kestrel/terminal/terminal.h"

#define KESTREL_ASCII_ART                                                      \
    "\
 __  __ _______ _______ _______ ______ _______ _____   \n\
|  |/  |    ___|     __|_     _|   __ \\    ___|     |_ \n\
|     <|    ___|__     | |   | |      <    ___|       |\n\
|__|\\__|_______|_______| |___| |___|__|_______|_______|\n\
"

static volatile struct limine_framebuffer_request limine_framebuffer_request;

void entry(void);
static noreturn void halt(void);

void entry(void)
{
    frame_buffer_t frame_buffer = { 0 };
    terminal_t terminal = { 0 };
    struct limine_framebuffer* limine_framebuffer = NULL;

    if ((NULL == limine_framebuffer_request.response)
        || (limine_framebuffer_request.response->framebuffer_count < 1)) {
        goto cleanup;
    }

    limine_framebuffer = limine_framebuffer_request.response->framebuffers[0];
    frame_buffer_initialize(&frame_buffer, limine_framebuffer);
    terminal_initialize(&terminal, &frame_buffer);

    terminal_set_foreground_color(&terminal, white_color);
    terminal_set_background_color(&terminal, black_color);
    terminal_draw_string(&terminal, KESTREL_ASCII_ART);
    terminal_draw_character(&terminal, '\n');

    logger_initialize(&terminal, LOG_LEVEL_TRACE);

    logger_trace("Hello!\n");
    logger_information("Hello!\n");
    logger_debug("Hello!\n");
    logger_warning("Hello!\n");
    logger_error("Hello!\n");
    logger_success("Hello!\n");

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
