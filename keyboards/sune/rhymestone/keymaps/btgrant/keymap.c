/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"
#include "encoder_press.h"

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_btgrant(
        '*', '*',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
    );
#endif

// TODO re-assign the encoder taps; refer to Waterfowl
// TODO re-assign the encoder map; refer to Waterfowl

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(
        KC_MPLY, KC_MUTE,
        ___5BASE_1_L___,                                                         ___5BASE_1_R___,
        ___5BASE_2_L___,                                                         ___5BASE_2_R___,
        ___5BASE_3_L___,                                                         ___5BASE_3_R___,
        BACK,    ESC_FUN, TAB_MSE, XXXXXXX,  BS_NUM, SPC_NAV, XXXXXXX, DEL_MSE, ENT_SYM,     FWD
    ),
    [_NUM] = LAYOUT_btgrant(
        KC_TRNS, KC_TRNS,
        ___5NUM_1_L___,                                                           ___5NUM_1_R___,
        ___5NUM_2_L___,                                                           ___5NUM_2_R___,
        ___5NUM_3_L___,                                                           ___5NUM_3_R___,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX,    KC_0, _______, _______
    ),
    [_SYM] = LAYOUT_btgrant(
        KC_TRNS, KC_TRNS,
        ___5SYM_1_L___,                                                           ___5SYM_1_R___,
        ___5SYM_2_L___,                                                           ___5SYM_2_R___,
        ___5SYM_3_L___,                                                           ___5SYM_3_R___,
        _______, _______, KC_MUTE, XXXXXXX, KC_MPLY,LPRN_MSE, XXXXXXX, XXXXXXX, _______, _______
    ),
    [_NAV] = LAYOUT_btgrant(
        KC_TRNS, KC_TRNS,
        ___5NAV_1_L___,                                                           ___5NAV_1_R___,
        ___5NAV_2_L___,                                                           ___5NAV_2_R___,
        ___5NAV_3_L___,                                                           ___5NAV_3_R___,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
    ),
    [_FUN] = LAYOUT_btgrant(
        KC_TRNS, KC_TRNS,
        ___5FUN_1_L___,                                                           ___5FUN_1_R___,
        ___5FUN_2_L___,                                                           ___5FUN_2_R___,
        ___5FUN_3_L___,                                                           ___5FUN_3_R___,
        _______, _______, XXXXXXX, XXXXXXX,MO(_MSE),MO(_ADD), XXXXXXX, XXXXXXX, _______, _______
    ),
    [_MSE] = LAYOUT_btgrant(
        KC_TRNS, KC_TRNS,
        ___5MSE_1_L___,                                                           ___5MSE_1_R___,
        ___5MSE_2_L___,                                                           ___5MSE_2_R___,
        ___5MSE_3_L___,                                                           ___5MSE_3_R___,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
    ),
    [_ADD] = LAYOUT_btgrant(
        KC_TRNS, KC_TRNS,
        ___5ADD_1_L___,                                                           ___5ADD_1_R___,
        ___5ADD_2_L___,                                                           ___5ADD_2_R___,
        ___5ADD_3_L___,                                                           ___5ADD_3_R___,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
    )
};

#ifdef ENCODER_MAP_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        return false;
    };

    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
        [_NUM]  = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),     ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
        [_SYM]  = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV),     ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
        [_NAV]  = { ENCODER_CCW_CW(FWD, BACK),            ENCODER_CCW_CW(BACK, FWD) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRIU, KC_BRID),     ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
        [_MSE]  = { ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC),   ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC) },
        [_ADD]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),     ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
    };
#endif
