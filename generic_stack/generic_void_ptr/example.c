#include <stdio.h>
#include <stddef.h>
#include "stack.h"
#include "point.h"

int main() {
    printf("=== Stack for \"long\" type ===\n");
{
    const size_t capacity = 3;
    Stack s = Stack_create(capacity, sizeof(long));
    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        long val = i * 100;
        printf("Stack_push(s, %ld);\n", val);
        Stack_push(s, &val);
        printf("Stack_peek(s): %ld\n\n", *((long*)Stack_peek(s)));
    }

    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        printf("Stack_peek(s): %ld\n", *((long*)Stack_peek(s)));
        printf("Stack_pop(s);\n\n");
        Stack_pop(s);
    }

    printf("Stack_empty(s): %s\n", Stack_empty(s) ? "true" : "false");
    Stack_destroy(s);
}

    printf("\n=== Stack for \"Point\" type ===\n");
{
    const size_t capacity = 3;
    Stack s = Stack_create(capacity, sizeof(Point));
    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        Point point = {.x = i, .y = i * 0.1};
        printf("Stack_push(s, "); printPoint(&point); printf(");\n");
        Stack_push(s, &point);
        printf("Stack_peek(s): "); printPoint((Point*)Stack_peek(s)); printf(");\n\n");
    }

    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        printf("Stack_peek(s): "); printPoint((Point*)Stack_peek(s)); printf(");\n");
        printf("Stack_pop(s);\n\n");
        Stack_pop(s);
    }

    printf("Stack_empty(s): %s\n", Stack_empty(s) ? "true" : "false");
    Stack_destroy(s);

}
    return 0;
}
