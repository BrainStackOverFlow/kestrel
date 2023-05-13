#include "printf/printf_support.h"

#include "printf/printf.h"

terminal_t* g_terminal = NULL;

void printf_init(terminal_t* terminal)
{
    g_terminal = terminal;
}

void putchar_(char c)
{
    if (NULL != g_terminal) {
        terminal_draw_character(g_terminal, c);
    }
}