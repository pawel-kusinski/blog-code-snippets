
#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct Stack* Stack;

Stack Stack_create(size_t capacity, size_t elem_size);
void Stack_destroy(Stack s);

void Stack_push(Stack s, void* value);
void Stack_pop(Stack s);
void* Stack_peek(Stack s);
bool Stack_empty(Stack s);
