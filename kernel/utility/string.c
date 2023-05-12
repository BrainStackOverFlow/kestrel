#include "utility/string.h"

#include <stdbool.h>

size_t string_length(const char* string)
{
    size_t length = 0;

    while (true) {
        if ('\0' == string[length]) {
            break;
        }

        length++;
    }

    return length;
}
