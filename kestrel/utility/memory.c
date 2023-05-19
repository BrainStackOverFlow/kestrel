#include "kestrel/utility/memory.h"

#include <stdbool.h>

void copy_memory(void* destination, const void* source, size_t size)
{
    uint8_t* destination_bytes = (uint8_t*)destination;
    const uint8_t* source_bytes = (const uint8_t*)source;

    for (size_t index = 0; index < size; index++) {
        destination_bytes[index] = source_bytes[index];
    }
}

void set_memory(void* memory, uint8_t value, size_t size)
{
    uint8_t* memory_bytes = (uint8_t*)memory;

    for (size_t index = 0; index < size; index++) {
        memory_bytes[index] = value;
    }
}

void move_memory(void* destination, const void* source, size_t size)
{
    uint8_t* destination_bytes = (uint8_t*)destination;
    const uint8_t* source_bytes = (const uint8_t*)source;

    if (source > destination) {
        for (size_t index = 0; index < size; index++) {
            destination_bytes[index] = source_bytes[index];
        }
    } else if (source < destination) {
        for (size_t index = size; index > 0; index--) {
            destination_bytes[index - 1] = source_bytes[index - 1];
        }
    }
}

int compare_memory(const void* buffer_1, const void* buffer_2, size_t size)
{
    const uint8_t* buffer_1_byte = (const uint8_t*)buffer_1;
    const uint8_t* buffer_2_byte = (const uint8_t*)buffer_2;

    for (size_t index = 0; index < size; index++) {
        if (buffer_1_byte[index] != buffer_2_byte[index]) {
            return buffer_1_byte[index] < buffer_2_byte[index] ? -1 : 1;
        }
    }

    return 0;
}
