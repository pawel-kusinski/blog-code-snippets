#include "stack.h"

#include <stdlib.h>
#include <assert.h>

#define X(T) \
struct Stack_ ## T { \
    T* data; \
    size_t capacity; \
    size_t top; \
}; \
 \
 \
Stack_ ## T Stack_ ## T ## _create(size_t capacity) { \
    Stack_ ## T s = malloc(sizeof(struct Stack_ ## T)); \
    s->data = malloc(capacity * sizeof(T)); \
    s->capacity = capacity; \
    s->top = 0; \
    return s; \
} \
 \
void Stack_ ## T ## _destroy(Stack_ ## T  s) { \
    free(s->data); \
    free(s); \
} \
 \
void Stack_ ## T ## _push(Stack_ ## T s, T value) { \
    if (s->top >= s->capacity) { \
        return; \
    } \
 \
    s->data[s->top++] = value; \
} \
 \
void Stack_ ## T ## _pop(Stack_ ## T s) { \
    assert(s->top); \
    s->top--; \
} \
 \
T Stack_ ## T ## _peek(Stack_ ## T s) { \
    assert(s->top); \
    return s->data[s->top - 1]; \
} \
 \
bool Stack_ ## T ## _empty(Stack_ ## T s) { \
    return s->top == 0; \
}

STACK_TYPES

#undef X
