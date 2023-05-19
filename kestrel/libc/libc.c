#include "kestrel/libc/libc.h"

#include "kestrel/libc/stdio.h"

static terminal_t* default_terminal;

void set_default_terminal(terminal_t* terminal)
{
    default_terminal = terminal;
}

void putchar_(char character)
{
    if (NULL == default_terminal) {
        return;
    }

    terminal_draw_character(default_terminal, character);
}
