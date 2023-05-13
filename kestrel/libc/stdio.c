#include "kestrel/libc/stdio.h"

static terminal_t* default_terminal;

void set_default_terminal(terminal_t* terminal)
{
    default_terminal = terminal;
}

void putchar_(char character)
{
    if (default_terminal == NULL) {
        return;
    }

    terminal_draw_character(default_terminal, character);
}