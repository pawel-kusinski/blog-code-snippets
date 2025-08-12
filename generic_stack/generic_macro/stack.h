#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "point.h"

#define STACK_TYPES \
    X(int) \
    X(double) \
    X(long) \
    X(Point)


#define X(T) \
 \
typedef struct Stack_ ## T * Stack_ ## T; \
 \
Stack_ ## T Stack_ ## T ## _create(size_t capacity); \
void Stack_ ## T ## _destroy(Stack_ ## T s); \
void Stack_ ## T ## _push(Stack_ ## T s, T value); \
void Stack_ ## T ## _pop(Stack_ ## T s); \
T Stack_ ## T ## _peek(Stack_ ## T s); \
bool Stack_ ## T ## _empty(Stack_ ## T s);

STACK_TYPES

#undef X


#define Stack_destroy(s) _Generic((s), \
    Stack_long: Stack_long_destroy, \
    Stack_Point: Stack_Point_destroy \
)(s)

#define Stack_push(s, v) _Generic((s), \
    Stack_long: Stack_long_push, \
    Stack_Point: Stack_Point_push \
)(s, v)

#define Stack_pop(s) _Generic((s), \
    Stack_long: Stack_long_pop, \
    Stack_Point: Stack_Point_pop \
)(s)

#define Stack_peek(s) _Generic((s), \
    Stack_long: Stack_long_peek, \
    Stack_Point: Stack_Point_peek \
)(s)

#define Stack_empty(s) _Generic((s), \
    Stack_long: Stack_long_empty, \
    Stack_Point: Stack_Point_empty \
)(s)

