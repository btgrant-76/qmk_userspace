// Copyright 2022 Kyle McCreery (@kylemccreery)
// Copyright 2024 Brian Grant <@btgrant-76>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
// an artifact of the process of upgrading to QMK 0.26
tap_dance_action_t tap_dance_actions[] = {};
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

/*   Physical Layout:
 *   /-------------------\
 *   |ENC| 1 | 2 | 3 |ENC|
 *   |---+---'---'---+---|
 *   | 4 |           | 5 |
 *   |---|           |---|
 *   | 6 |           | 7 |
 *   |---|           |---|
 *   | 8 |           | 9 |
 *   \-----,---,---,-----/
 *     | A | B | C | D |
 *     \---'---'---'---/
 *
 *   Keymap Layout:
 *   ENC, 1, 2, 3,    ENC,
 *   4,               5,
 *   6,               7,
 *   8,   A, B, C, D, 9,
 *
 */

// shortcuts
#define BACK     LCMD(KC_LBRC)
#define FWD      LCMD(KC_RBRC)
#define MISS_CTL LCTL(KC_UP)
#define EXPOSE   LCTL(KC_DOWN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_MUTE,  XXXXXXX, XXXXXXX, MO(_FN1),         KC_MPLY,
        BACK,                                         FWD,
        KC_WH_D,                                      DPI_FINE,
        KC_WH_U,                                      MISS_CTL,
                  KC_BTN1, KC_BTN2, KC_BTN3, EXPOSE
    ),
    [_FN1] = LAYOUT(
        RGB_TOG, XXXXXXX, XXXXXXX,  XXXXXXX,          TAP_TOG,
        DPI_UP,                                       XXXXXXX,
        DPI_DN,                                       XXXXXXX,
        MO(_FN2),                                     XXXXXXX,
                 QK_BOOT, XXXXXXX,  XXXXXXX, XXXXXXX
    ),
    [_FN2] = LAYOUT(
        KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS,          RGB_TOG,
        KC_TRNS,                                     RGB_MOD,
        KC_TRNS,                                     RGB_RMOD,
        KC_TRNS,                                     KC_TRNS,
                 KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),
    [_FN3] = LAYOUT(
        KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS,          KC_TRNS,
        KC_TRNS,                                     KC_TRNS,
        KC_TRNS,                                     KC_TRNS,
        KC_TRNS,                                     KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef ENCODER_MAP_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        return false;
    };

    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
        [_FN1]  = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(TAP_DN,  TAP_UP) },
        [_FN2]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
        [_FN3]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),  ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    };
#endif
