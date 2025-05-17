// Copyright 2025 btgrant-76
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"

#include "encoder_map.h"
#include "encoder_press.h"

#ifdef COMBO_ENABLE
#include "combo_defs.h"

combo_t key_combos[] = {
    // thumb keys
    COMBO(MO_FUN, MO(_FUN)),
    COMBO(MO_SYM, MO(_SYM)),

    // 3u bar
    COMBO(MUTE, KC_MUTE),
    COMBO(PLAY, KC_MPLY),
    COMBO(LOG_OUT_CM, LOG_OUT),

    // combo typing reintroduction
    COMBO(QUOT, KC_QUOT),
    COMBO(ESC_Z_X, KC_ESC),
    COMBO(ESC_Q_W, KC_ESC),
    COMBO(ENTER_SLSH_DOT, KC_ENT),
    COMBO(CAPS, KC_CAPS),
};
#endif

#define LAYOUT_btgrant_cain_bars(...)    LAYOUT_cain_bars(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant_cain_bars(
        ___5BASE_1_L___,  KC_VOLU,                   ___5BASE_1_R___,
        ___5BASE_2_L___,  XXXXXXX,                   ___5BASE_2_R___,
        ___5BASE_3_L___,  KC_VOLD,                   ___5BASE_3_R___,
           ___BASE_ALT_THUMB_L___,             ___BASE_ALT_THUMB_R___
    ),
    [_NUM] = LAYOUT_btgrant_cain_bars(
        ___5NUM_1_L___, XXXXXXX,                     ___5NUM_1_R___,
        ___5NUM_2_L___, XXXXXXX,                     ___5NUM_2_R___,
        ___5NUM_3_L___, XXXXXXX,                     ___5NUM_3_R___,
          ___NUM_ALT_THUMB_L___,              ___NUM_ALT_THUMB_R___
    ),
    [_SYM] = LAYOUT_btgrant_cain_bars(
        ___5SYM_1_L___, KC_MNXT,                     ___5SYM_1_R___,
        ___5SYM_2_L___, XXXXXXX,                     ___5SYM_2_R___,
        ___5SYM_3_L___, KC_MPRV,                     ___5SYM_3_R___,
          ___SYM_ALT_THUMB_L___,              ___SYM_ALT_THUMB_R___
    ),
    [_NAV] = LAYOUT_btgrant_cain_bars(
        ___5NAV_1_L___, XXXXXXX,                     ___5NAV_1_R___,
        ___5NAV_2_L___, XXXXXXX,                     ___5NAV_2_R___,
        ___5NAV_3_L___, XXXXXXX,                     ___5NAV_3_R___,
          ___NAV_ALT_THUMB_L___,              ___NAV_ALT_THUMB_R___
    ),
    [_FUN] = LAYOUT_btgrant_cain_bars(
        ___5FUN_1_L___, KC_BRIU,                     ___5FUN_1_R___,
        ___5FUN_2_L___, XXXXXXX,                     ___5FUN_2_R___,
        ___5FUN_3_L___, KC_BRID,                     ___5FUN_3_R___,
          ___FUN_ALT_THUMB_L___,              ___FUN_ALT_THUMB_R___
    ),
    [_MSE] = LAYOUT_btgrant_cain_bars(
        ___5MSE_1_L___, XXXXXXX,                     ___5MSE_1_R___,
        ___5MSE_2_L___, XXXXXXX,                     ___5MSE_2_R___,
        ___5MSE_3_L___, XXXXXXX,                     ___5MSE_3_R___,
          ___MSE_ALT_THUMB_L___,              ___MSE_ALT_THUMB_R___
    ),
    [_ADD] = LAYOUT_btgrant_cain_bars(
        ___5ADD_1_L___, XXXXXXX,                     ___5ADD_1_R___,
        ___5ADD_2_L___, XXXXXXX,                     ___5ADD_2_R___,
        ___5ADD_3_L___, XXXXXXX,                     ___5ADD_3_R___,
          ___ADD_ALT_THUMB_L___,              ___ADD_ALT_THUMB_R___
    )
};
