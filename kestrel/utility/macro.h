#pragma once

#ifndef asm
#define asm(...) __asm__ __volatile__(__VA_ARGS__)
#endif

#ifndef static_assert
#define static_assert _Static_assert
#endif

#ifndef add_pointer
#define add_pointer(type, pointer, offset)                                     \
    ((type)(((uint8_t*)(pointer)) + (offset)))
#endif

#ifndef noreturn
#define noreturn __attribute__((noreturn))
#endif

#ifndef format_function
#define format_function(format_index, arguments_index)                         \
    __attribute__((format(printf, format_index, arguments_index)))
#endif

#ifndef unused
#define unused(value) ((void)(value))
#endif
