#pragma once

#ifndef static_assert
#define static_assert _Static_assert
#endif

#ifndef add_pointer
#define add_pointer(type, pointer, offset)                                     \
    ((type)(((uint8_t*)(pointer)) + (offset)))
#endif
