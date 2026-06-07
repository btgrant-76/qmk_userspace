// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        KC_7,    KC_8,    KC_9,
        KC_4,    KC_5,    KC_6,
        KC_1,    KC_2,    MO(1)
    ),
    [1] = LAYOUT_ortho_3x3(
        KC_A,    KC_B,    KC_C,
        KC_E,    KC_F,    KC_G,
        KC_H,    KC_I,    KC_J
    )
};
