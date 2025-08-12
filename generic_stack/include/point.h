#pragma once

#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;

static inline void printPoint(const Point* p) {
    printf("{x = %0.1f, y = %0.1f}", p->x, p->y);
}

