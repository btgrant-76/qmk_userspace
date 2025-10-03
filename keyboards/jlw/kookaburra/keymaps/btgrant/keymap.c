// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"

#include "combos.h"

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_btgrant_3x5(
        'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
                  '*', '*', '*',   '*', '*', '*'
    );
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant_3x5(
        ___5BASE_1_L___,                                ___5BASE_1_R___,
        ___5BASE_2_L___,                                ___5BASE_2_R___,
        ___5BASE_3_L___,                                ___5BASE_3_R___,
                    ___BASE_THUMB_L___,  ___BASE_THUMB_R___
    ),
    [_NUM] = LAYOUT_btgrant_3x5(
        ___5NUM_1_L___,                                 ___5NUM_1_R___,
        ___5NUM_2_L___,                                 ___5NUM_2_R___,
        ___5NUM_3_L___,                                 ___5NUM_3_R___,
                    ___NUM_THUMB_L___,   ___NUM_THUMB_R___
    ),
    [_SYM] = LAYOUT_btgrant_3x5(
        ___5SYM_1_L___,                                 ___5SYM_1_R___,
        ___5SYM_2_L___,                                 ___5SYM_2_R___,
        ___5SYM_3_L___,                                 ___5SYM_3_R___,
                    ___SYM_THUMB_L___,   ___SYM_THUMB_R___
    ),
    [_NAV] = LAYOUT_btgrant_3x5(
        ___5NAV_1_L___,                                 ___5NAV_1_R___,
        ___5NAV_2_L___,                                 ___5NAV_2_R___,
        ___5NAV_3_L___,                                 ___5NAV_3_R___,
                    ___NAV_THUMB_L___,  ___NAV_THUMB_R___
    ),
    [_FUN] = LAYOUT_btgrant_3x5(
        ___5FUN_1_L___,                                 ___5FUN_1_R___,
        ___5FUN_2_L___,                                 ___5FUN_2_R___,
        ___5FUN_3_L___,                                 ___5FUN_3_R___,
                    ___FUN_THUMB_L___,   ___FUN_THUMB_R___
    ),
    [_MSE] = LAYOUT_btgrant_3x5(
        ___5MSE_1_L___,                                 ___5MSE_1_R___,
        ___5MSE_2_L___,                                 ___5MSE_2_R___,
        ___5MSE_3_L___,                                 ___5MSE_3_R___,
                    ___MSE_THUMB_L___,   ___MSE_THUMB_R___
    ),
    [_ADD] = LAYOUT_btgrant_3x5(
        ___5ADD_1_L___,                                 ___5ADD_1_R___,
        ___5ADD_2_L___,                                 ___5ADD_2_R___,
        ___5ADD_3_L___,                                             ___5ADD_3_R___,
                    ___ADD_THUMB_L___,   ___ADD_THUMB_R___
    )
};
