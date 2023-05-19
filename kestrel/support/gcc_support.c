#include <stdint.h>
#include <string.h>

#include "kestrel/utility/memory.h"
#include "kestrel/utility/string.h"

void* memcpy(void* destination, const void* source, size_t size)
{
    copy_memory(destination, source, size);
    return destination;
}

void* memset(void* memory, int value, size_t size)
{
    set_memory(memory, (uint8_t)value, size);
    return memory;
}

void* memmove(void* destination, const void* source, size_t size)
{
    move_memory(destination, source, size);
    return destination;
}

int memcmp(const void* buffer_1, const void* buffer_2, size_t size)
{
    return compare_memory(buffer_1, buffer_2, size);
}

size_t strlen(const char* string)
{
    return string_length(string);
}
