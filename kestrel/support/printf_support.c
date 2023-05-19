#include "kestrel/utility/macro.h"

// We are not interest in a global `printf` function.
// We must provide this symbol, though.
void putchar_(char character)
{
    unused(character);
}
