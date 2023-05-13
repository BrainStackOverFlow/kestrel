#pragma once

#ifndef asm
#define asm(...) __asm__ __volatile__(__VA_ARGS__)
#endif

#ifndef static_assert
#define static_assert(condition, message) _Static_assert(condition, message)
#endif

#ifndef add_pointer
#define add_pointer(type, pointer, offset)                                     \
    ((type)(((uint8_t*)(pointer)) + (offset)))
#endif

#ifndef noreturn
#define noreturn __attribute__((noreturn))
#endif
