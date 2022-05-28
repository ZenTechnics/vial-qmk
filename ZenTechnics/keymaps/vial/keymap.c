#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "quantum.h"

// 224x64
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 2, 1, 0, NO_LED },
  { 3, 4, 5, NO_LED },
}, {
  // LED Index to Physical Position
    { 224,0}, { 112, 0}, { 0, 0 },
    { 0, 64}, { 112,64 }, { 224, 64},
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4
} };

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
       	KC_B, KC_D, KC_F, ____,
        KC_A, KC_C, KC_E, KC_G
    ),

    [1] = LAYOUT(
        ____, ____, ____, ____,
        ____, ____, ____, ____
    ),

    [2] = LAYOUT(
        ____, ____, ____, ____,
        ____, ____, ____, ____
    ),

    [3] = LAYOUT(
        ____, ____, ____, ____,
        ____, ____, ____, ____

    ),

};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const int led_index = 2;
    switch(get_highest_layer(layer_state)) {
        case 1:
            rgb_matrix_set_color(led_index, RGB_WHITE);
            break;
        case 2:
            rgb_matrix_set_color(led_index, RGB_BLUE);
            break;
        case 3:
            rgb_matrix_set_color(led_index, RGB_GREEN);
            break;
        default:
            break;
    }
}

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    if(data[0] == 0xFC){
        switch (data[1]) {
            case 0x01:{
                // move to layer
                data[1] = 0xFD;
                layer_move(data[2]);
                break;
            }
            case 0x02:{
                // turn on layer
                data[1] = 0xFD;
                layer_on(data[2]);
                break;
            }
            case 0x03:{
                // turn off layer
                data[1] = 0xFD;
                layer_off(data[2]);
                break;
            }
        }
    }
    raw_hid_send(data, length);
}