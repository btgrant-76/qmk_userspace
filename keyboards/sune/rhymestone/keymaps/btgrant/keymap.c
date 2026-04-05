/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"
#include "encoder_press.h"

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_btgrant(
        '*',                                           '*',
        'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
        '*', '*', '*', '*', '*',   '*', '*', '*', '*', '*'
    );
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(
        KC_MPLY,                                                                        ENC_BASE,
        ___5BASE_1_L___,                                                         ___5BASE_1_R___,
        ___5BASE_2_L___,                                                         ___5BASE_2_R___,
        ___5BASE_3_L___,                                                         ___5BASE_3_R___,
        XXXXXXX, XXXXXXX, ___BASE_THUMB_L___,               ___BASE_THUMB_R___, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT_btgrant(
        KC_TRNS,                                                                         ENC_NUM,
        ___5NUM_1_L___,                                                           ___5NUM_1_R___,
        ___5NUM_2_L___,                                                           ___5NUM_2_R___,
        ___5NUM_3_L___,                                                           ___5NUM_3_R___,
        XXXXXXX, XXXXXXX, ___NUM_THUMB_L___,                ___NUM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant(
        KC_TRNS,                                                                         ENC_SYM,
        ___5SYM_1_L___,                                                           ___5SYM_1_R___,
        ___5SYM_2_L___,                                                           ___5SYM_2_R___,
        ___5SYM_3_L___,                                                           ___5SYM_3_R___,
        XXXXXXX, XXXXXXX, ___SYM_THUMB_L___,                ___SYM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant(
        KC_TRNS,                                                                         ENC_NAV,
        ___5NAV_1_L___,                                                           ___5NAV_1_R___,
        ___5NAV_2_L___,                                                           ___5NAV_2_R___,
        ___5NAV_3_L___,                                                           ___5NAV_3_R___,
        XXXXXXX, XXXXXXX, ___NAV_THUMB_L___,                ___NAV_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_FUN] = LAYOUT_btgrant(
        KC_TRNS,                                                                         ENC_FUN,
        ___5FUN_1_L___,                                                           ___5FUN_1_R___,
        ___5FUN_2_L___,                                                           ___5FUN_2_R___,
        ___5FUN_3_L___,                                                           ___5FUN_3_R___,
        XXXXXXX, XXXXXXX, ___FUN_THUMB_L___,                ___FUN_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_MSE] = LAYOUT_btgrant(
        KC_TRNS,                                                                         ENC_MSE,
        ___5MSE_1_L___,                                                           ___5MSE_1_R___,
        ___5MSE_2_L___,                                                           ___5MSE_2_R___,
        ___5MSE_3_L___,                                                           ___5MSE_3_R___,
        XXXXXXX, XXXXXXX, ___MSE_THUMB_L___,                ___MSE_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_ADD] = LAYOUT_btgrant(
        KC_TRNS,                                                                         ENC_ADD,
        ___5ADD_1_L___,                                                           ___5ADD_1_R___,
        ___5ADD_2_L___,                                                           ___5ADD_2_R___,
        ___5ADD_3_L___,                                                           ___5ADD_3_R___,
        XXXXXXX, XXXXXXX, ___ADD_THUMB_L___,                ___ADD_THUMB_R___,  XXXXXXX, XXXXXXX
    )
};

#ifdef ENCODER_MAP_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        return false;
    };

    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),     ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
        [_NUM]  = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),     ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
        [_SYM]  = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV),     ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
        [_NAV]  = { ENCODER_CCW_CW(FWD, BACK),            ENCODER_CCW_CW(BACK, FWD) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRIU, KC_BRID),     ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
        [_MSE]  = { ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC),   ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC) },
        [_ADD]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),     ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
    };
#endif
