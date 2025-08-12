#include "stack.h"

#include <stdlib.h>
#include <assert.h>


struct Stack {
    int* data;
    size_t capacity;
    size_t top;
};


Stack Stack_create(size_t capacity) {
    Stack s = malloc(sizeof(struct Stack));
    s->data = malloc(capacity * sizeof(int));
    s->capacity = capacity;
    s->top = 0;
    return s;
}

void Stack_destroy(Stack s) {
    free(s->data);
    free(s);
}

void Stack_push(Stack s, int value) {
    if (s->top >= s->capacity) {
        return;
    }

    s->data[s->top++] = value;
}

void Stack_pop(Stack s) {
    assert(s->top);
    s->top--;
}

int Stack_peek(Stack s) {
    assert(s->top);
    return s->data[s->top - 1];
}

bool Stack_empty(Stack s) {
    return s->top == 0;
}
