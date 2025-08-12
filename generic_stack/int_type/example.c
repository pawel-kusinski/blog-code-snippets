#include <stdio.h>
#include <stddef.h>
#include "stack.h"

int main() {
    const size_t capacity = 5;
    Stack s = Stack_create(capacity);

    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        printf("Stack_push(s, %zu);\n", i);
        Stack_push(s, i);
        printf("Stack_peek(s): %d\n\n", Stack_peek(s));
    }

    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        printf("Stack_peek(s): %d\n", Stack_peek(s));
        printf("Stack_pop(s);\n\n");
        Stack_pop(s);
    }

    printf("Stack_empty(s): %s\n", Stack_empty(s) ? "true" : "false");
    Stack_destroy(s);
    return 0;
}
