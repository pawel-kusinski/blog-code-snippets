#include <stdio.h>
#include "gpio.h"


// Define  GPIO pin "database" as macro data

/*   label           pin  dir  init_state  pull_up */
#define BUTTON_TEST_BOARD_OUTPUT_PINS \
    X(LED_RED,       0,   OUT,  true,      false) \
    X(LED_GREEN,     2,   OUT,  false,     false)

/*   label           pin  dir  init_state  pull_up */
#define BUTTON_TEST_BOARD_INPUT_PINS  \
    X(OK_BUTTON,     20,  IN,  false,  true) \
    X(CANCEL_BUTTON, 26,  IN,  false,  false)

// Combine both lists into one — so we can initialize all pins together
#define BUTTON_TEST_BOARD_ALL_PINS \
    BUTTON_TEST_BOARD_OUTPUT_PINS \
    BUTTON_TEST_BOARD_INPUT_PINS


/*
 * --- Preprocessor Output of initGpio() ---
 *
 * Here's what initGpio() expands to:
 * This is what the compiler actually sees
 * after the X macros are expanded.
 *
 * void initGpio(void) {
 *     printf("Initializing " "LED_RED" " pin...\n");
 *     gpio_init(0);
 *     gpio_set_dir(0, 1);
 *     gpio_put(0, 1);
 *
 *     printf("Initializing " "LED_GREEN" " pin...\n");
 *     gpio_init(2);
 *     gpio_set_dir(2, 1);
 *     gpio_put(2, 0);
 *
 *     printf("Initializing " "OK_BUTTON" " pin...\n");
 *     gpio_init(20);
 *     gpio_set_dir(20, 0);
 *     gpio_put(20, 0);
 *
 *     printf("Initializing " "CANCEL_BUTTON" " pin...\n");
 *     gpio_init(26);
 *     gpio_set_dir(26, 0);
 *     gpio_put(26, 0);
 *
 *     printf("Initializing pin " "OK_BUTTON" " pull-up/pull-down...\n");
 *     if (1) {
 *         gpio_pull_up(20);
 *     } else {
 *         gpio_pull_down(20);
 *     }
 *
 *     printf("Initializing pin " "CANCEL_BUTTON" " pull-up/pull-down...\n");
 *     if (0) {
 *         gpio_pull_up(26);
 *     } else {
 *         gpio_pull_down(26);
 *     }
 * }
 */
void initGpio(void) {
    // First pass: common setup for both input and output pins.
    // This macro is redefined just for this block.
    //
    // We temporarily define macro `X(...)` to say:
    //   - Print what we're doing
    //   - Call gpio_init
    //   - Set direction (IN or OUT)
    //   - Set initial value (for OUT pins)
    // The macro list `BUTTON_TEST_BOARD_ALL_PINS` will now "call" X(...)
    // oncew per line — expanding into real C code.
#define X(label, pin, direction, init_state, pull_up) \
    printf("Initializing " #label " pin...\n"); \
    gpio_init(pin); \
    gpio_set_dir(pin, GPIO_ ## direction); \
    gpio_put(pin, init_state);

    // Expand each pin using the above X(...) definition
    BUTTON_TEST_BOARD_ALL_PINS

    // Clean up: always undef X after use to avoid accidental reuse
#undef X

    // Second pass: only needed for input pins.
    // So we only iterate over BUTTON_TEST_BOARD_INPUT_PINS.
    // Again, we redefine X(...) with new logic — this time for pull config.
#define X(label, pin, direction, init_state, pull_up) \
    printf("Initializing pin " #label " pull-up/pull-down...\n"); \
    if (pull_up) { \
        gpio_pull_up(pin); \
    } else { \
        gpio_pull_down(pin); \
    }

    // Expand each input pin using the new X(...) logic
    BUTTON_TEST_BOARD_INPUT_PINS

    // Always undef X after use
#undef X
}

int main(void) {
    initGpio();
    return 0;
}
