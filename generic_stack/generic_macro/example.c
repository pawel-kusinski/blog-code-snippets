#include <stdio.h>
#include <stddef.h>
#include "stack.h"
#include "point.h"

int main() {

    printf("=== Stack for \"long\" type ===\n");
{
    const size_t capacity = 3;
    Stack_long s = Stack_long_create(capacity);
    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        long val = i * 100;
        printf("Stack_push(s, %ld);\n", val);
        Stack_push(s, val);
        printf("Stack_peek(s): %ld\n\n", Stack_peek(s));
    }

    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        printf("Stack_peek(s): %ld\n", Stack_peek(s));
        printf("Stack_pop(s);\n\n");
        Stack_pop(s);
    }

    printf("Stack_empty(s): %s\n", Stack_empty(s) ? "true" : "false");
    Stack_destroy(s);
}

    printf("\n=== Stack for \"Point\" type ===\n");
{
    const size_t capacity = 3;
    Stack_Point s = Stack_Point_create(capacity);
    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        Point point = {.x = i, .y = i * 0.1};
        printf("Stack_push(s, "); printPoint(&point); printf(");\n");
        Stack_push(s, point);
        const Point peek_point = Stack_peek(s);
        printf("Stack_peek(s): ");
        printPoint(&peek_point);
        printf(");\n\n");
    }

    printf("Stack_empty(s): %s\n\n", Stack_empty(s) ? "true" : "false");

    for (size_t i = 0; i < capacity; ++i) {
        const Point peek_point = Stack_peek(s);
        printf("Stack_peek(s): ");
        printPoint(&peek_point);
        printf(");\n");
        printf("Stack_pop(s);\n\n");
        Stack_pop(s);
    }

    printf("Stack_empty(s): %s\n", Stack_empty(s) ? "true" : "false");
    Stack_destroy(s);
}
    return 0;
}
