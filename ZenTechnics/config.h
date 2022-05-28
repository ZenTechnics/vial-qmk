#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xEEEE
#define PRODUCT_ID      0x2019
#define DEVICE_VER		0x0001
#define MANUFACTURER    ZenTechnics
#define PRODUCT         ZenTechnics

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { F6, B2 }
#define MATRIX_COL_PINS { F7, B1, B3, B4 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN F4
#define DRIVER_LED_TOTAL 6
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define VIAL_KEYBOARD_UID {0xF5, 0xDB, 0x34, 0xDF, 0x72, 0x39, 0x72, 0xE5}
#define VIAL_UNLOCK_COMBO_ROWS { 1, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define ENCODERS_PAD_A { D0 }
#define ENCODERS_PAD_B { D1 }
#define VIAL_ENCODER_DEFAULT { KC_1, KC_2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }