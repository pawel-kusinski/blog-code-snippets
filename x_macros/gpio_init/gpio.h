#pragma once

// Mocks Raspberry Pi Pico SDK GPIO module:
// https://github.com/raspberrypi/pico-sdk/blob/master/src/host/hardware_gpio/include/hardware/gpio.h

#include <stdio.h>
#include <stdbool.h>

#define GPIO_OUT 1
#define GPIO_IN 0


typedef unsigned int uint;

static inline void gpio_init(uint gpio) {
    printf("\t%s(%u) called\n", __func__, gpio);
}

static inline void gpio_set_dir(uint gpio, bool out) {
    printf("\t%s(%u, %s) called\n", __func__, gpio, out ? "true" : "false");
}

static inline void gpio_put(uint gpio, int value) {
    printf("\t%s(%u, %d) called\n", __func__, gpio, value);
}

static inline void gpio_pull_up(uint gpio) {
    printf("\t%s(%u) called\n", __func__, gpio);
}

static inline void gpio_pull_down(uint gpio) {
    printf("\t%s(%u) called\n", __func__, gpio);
}


