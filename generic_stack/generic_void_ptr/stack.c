#include "stack.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>


struct Stack {
    char* data;
    size_t capacity;
    size_t top;
    size_t elem_size;
};


Stack Stack_create(size_t capacity, size_t elem_size) {
    Stack s = malloc(sizeof(struct Stack));
    s->data = malloc(capacity * elem_size);
    s->capacity = capacity;
    s->top = 0;
    s->elem_size = elem_size;
    return s;
}

void Stack_destroy(Stack s) {
    free(s->data);
    free(s);
}

void Stack_push(Stack s, void* value) {
    if (s->top >= s->capacity * s->elem_size) {
        return;
    }

    memcpy(&s->data[s->top], value, s->elem_size);
    s->top += s->elem_size;
    printf("push: top: %zu\n", s->top);
}

void Stack_pop(Stack s) {
    assert(s->top);
    s->top -= s->elem_size;
}

void* Stack_peek(Stack s) {
    assert(s->top);
    return (void*)&s->data[s->top - s->elem_size];
}

bool Stack_empty(Stack s) {
    return s->top == 0;
}
