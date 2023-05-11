#pragma once

#include <stddef.h>
#include <stdint.h>

void copy_memory(void* destination, const void* source, size_t size);

void set_memory(void* memory, uint8_t value, size_t size);

void move_memory(void* destination, const void* source, size_t size);

int compare_memory(const void* buffer_1, const void* buffer_2, size_t size);
