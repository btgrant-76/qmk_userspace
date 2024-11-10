// Copyright 2024 btgrant-76
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "btgrant-76.h"

#ifdef ENCODER_MAP_ENABLE
#   include "encoder_map.h"
#   include "encoder_press.h"
#endif

#ifdef COMBO_ENABLE
#   include "combo_defs.h"

const uint16_t PROGMEM MUTE[] = {KC_VOLU, KC_VOLD, COMBO_END};
const uint16_t PROGMEM PLAY[] = {KC_MNXT, KC_MPRV, COMBO_END};

combo_t key_combos[] = {
    COMBO(QUOT, KC_QUOT),
    COMBO(D_QUOT, KC_DQT),
    COMBO(ESC, KC_ESC),
    COMBO(ESC_2, KC_ESC),
    COMBO(ESC_3, KC_ESC),
    COMBO(ENTER, KC_ENT),
    COMBO(CAPS, KC_CAPS),
    COMBO(MO_FUN, MO(_FUN)),
    COMBO(MUTE, KC_MUTE),
    COMBO(PLAY, KC_MPLY),
    COMBO(MO_SYM, MO(_SYM)),
    COMBO(ENTER, KC_ENT),
    COMBO(ESC, KC_ESC)
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant_cain_bars(
        ___5BASE_1_L___,  KC_VOLU,                                                         ___5BASE_1_R___,
        ___5BASE_2_L___,  XXXXXXX,                                                         ___5BASE_2_R___,
        ___5BASE_3_L___,  KC_VOLD,                                                         ___5BASE_3_R___,
        ESC_FUN, TAB_MSE,  BS_NUM,      SPC_NAV, DEL_MSE,  ENT_SYM
    ),
    [_NUM] = LAYOUT_btgrant_cain_bars(
        ___5NUM_1_L___, XXXXXXX,                                                          ___5NUM_1_R___,
        ___5NUM_2_L___, XXXXXXX,                                                          ___5NUM_2_R___,
        ___5NUM_3_L___, XXXXXXX,                                                          ___5NUM_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX,      KC_MINS, ZERO_TD, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant_cain_bars(
        ___5SYM_1_L___,       KC_MNXT,         ___5SYM_1_R___,
        ___5SYM_2_L___,       XXXXXXX,         ___5SYM_2_R___,
        ___5SYM_3_L___,       KC_MPRV,         ___5SYM_3_R___,
        XXXXXXX, KC_MUTE, KC_MPLY, LPRN_MSE, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant_cain_bars(
        ___5NAV_1_L___, XXXXXXX,                                                          ___5NAV_1_R___,
        ___5NAV_2_L___, XXXXXXX,                                                          ___5NAV_2_R___,
        ___5NAV_3_L___, XXXXXXX,                                                          ___5NAV_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FUN] = LAYOUT_btgrant_cain_bars(
        ___5FUN_1_L___, XXXXXXX,                                                          ___5FUN_1_R___,
        ___5FUN_2_L___, XXXXXXX,                                                          ___5FUN_2_R___,
        ___5FUN_3_L___, XXXXXXX,                                                          ___5FUN_3_R___,
        XXXXXXX, XXXXXXX,MO(_MSE),     MO(_ADD), XXXXXXX, XXXXXXX
    ),
    [_MSE] = LAYOUT_btgrant_cain_bars(
        ___5MSE_1_L___, XXXXXXX,                                                          ___5MSE_1_R___,
        ___5MSE_2_L___, XXXXXXX,                                                          ___5MSE_2_R___,
        ___5MSE_3_L___, XXXXXXX,                                                          ___5MSE_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_ADD] = LAYOUT_btgrant_cain_bars(
        ___5ADD_1_L___, XXXXXXX,                                                          ___5ADD_1_R___,
        ___5ADD_2_L___, XXXXXXX,                                                          ___5ADD_2_R___,
        ___5ADD_3_L___, XXXXXXX,                                                          ___5ADD_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
    )
};
