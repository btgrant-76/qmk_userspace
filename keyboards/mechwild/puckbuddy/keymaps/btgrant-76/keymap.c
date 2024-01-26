// Copyright 2022 Kyle McCreery (@kylemccreery)
// Copyright 2023 Brian Grant <@btgrant-76>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

 #undef GLIDEPOINT_DPI_OPTIONS
 #define GLIDEPOINT_DPI_OPTIONS { 1600, 200, 400, 600, 800, 1000, 1200, 1600, 2000, 2400 } // TODO figure out how to integrate this without needing to change the keyboard's definition

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

/* TODO add buttons from the Logitech mouse
 * [x]  media pause/play
 * [ ]  desktop left/right
 * [x]  all windows
 * [x]  all application windows
 */

// TODO integrate with userspace?
// shortcuts
#define BACK LCMD(KC_LBRC)
#define FWD LCMD(KC_RBRC)
#define MISS_CTL LCTL(KC_UP)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_HOME,  XXXXXXX, XXXXXXX, MO(_FN1),         KC_MUTE,
        BACK,                                         FWD,
        KC_WH_D,                                      MISS_CTL,
        KC_WH_U,                                      DPI_FINE, // TODO does this work?
                  KC_BTN1, KC_BTN2, KC_BTN3, LCTL(KC_DOWN)
    ),
    [_FN1] = LAYOUT(
        RGB_TOG, XXXXXXX, XXXXXXX,  XXXXXXX,          KC_MPLY, // TODO TAP_TOG displaced
        DPI_UP,                                       TAP_UP,
        DPI_DN,                                       TAP_DN,
        MO(_FN2),                                     KC_TRNS,
                 KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),
    [_FN2] = LAYOUT(
        KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS,          RGB_TOG,
        KC_TRNS,                                     RGB_MOD,
        KC_TRNS,                                     RGB_RMOD,
        KC_TRNS,                                     KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN3] = LAYOUT(
        KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS,          QK_BOOT,
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
        [_BASE] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_FN1]  = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
        [_FN2]  = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
        [_FN3]  = { ENCODER_CCW_CW(FWD, BACK), ENCODER_CCW_CW(FWD, BACK) },
    };
#endif

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_keymap(void) {
    rgblight_enable(); // Enables RGB, without saving settings
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL); //RGBLIGHT_MODE_CHRISTMAS);
    // rgblight_set_speed(255);
    rgblight_step();
    rgblight_step();
    rgblight_step();
    rgblight_step();
    rgblight_step();

}
#endif
