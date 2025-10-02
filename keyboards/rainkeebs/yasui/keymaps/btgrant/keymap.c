/* Copyright 2021 Regan Palmer
 * Copyright 2025 Brian Grant <@btgrant-76>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"

#include "four_thumb_combos.h"

#define BLOCKER XXXXXXX
#define BAR XXXXXXX

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_btgrant(
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
    );
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(
        ___5BASE_1_L___,                                                         ___5BASE_1_R___,
        ___5BASE_2_L___,                                                         ___5BASE_2_R___,
        ___5BASE_3_L___,                                                         ___5BASE_3_R___,
        ESC_FUN, BLOCKER, TAB_MSE,  BS_NUM,     BAR,     BAR, SPC_NAV, DEL_MSE, BLOCKER,  ENT_SYM
    ),
    [_NUM] = LAYOUT_btgrant(
        ___5NUM_1_L___,                                                           ___5NUM_1_R___,
        ___5NUM_2_L___,                                                           ___5NUM_2_R___,
        ___5NUM_3_L___,                                                           ___5NUM_3_R___,
        XXXXXXX, BLOCKER, XXXXXXX, XXXXXXX,     BAR,     BAR, KC_MINS,    KC_0, BLOCKER, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant(
        ___5SYM_1_L___,                                                           ___5SYM_1_R___,
        ___5SYM_2_L___,                                                           ___5SYM_2_R___,
        ___5SYM_3_L___,                                                           ___5SYM_3_R___,
        XXXXXXX, BLOCKER, KC_MUTE, KC_MPLY,     BAR,     BAR,LPRN_MSE, XXXXXXX, BLOCKER, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant(
        ___5NAV_1_L___,                                                           ___5NAV_1_R___,
        ___5NAV_2_L___,                                                           ___5NAV_2_R___,
        ___5NAV_3_L___,                                                           ___5NAV_3_R___,
        XXXXXXX, BLOCKER, XXXXXXX, XXXXXXX,     BAR,     BAR, XXXXXXX, XXXXXXX, BLOCKER, XXXXXXX
    ),
    [_FUN] = LAYOUT_btgrant(
        ___5FUN_1_L___,                                                           ___5FUN_1_R___,
        ___5FUN_2_L___,                                                           ___5FUN_2_R___,
        ___5FUN_3_L___,                                                           ___5FUN_3_R___,
        XXXXXXX, BLOCKER, XXXXXXX,MO(_MSE),     BAR,     BAR,MO(_ADD), XXXXXXX, BLOCKER, XXXXXXX
    ),
    [_MSE] = LAYOUT_btgrant(
        ___5MSE_1_L___,                                                           ___5MSE_1_R___,
        ___5MSE_2_L___,                                                           ___5MSE_2_R___,
        ___5MSE_3_L___,                                                           ___5MSE_3_R___,
        XXXXXXX, BLOCKER, XXXXXXX, XXXXXXX,     BAR,     BAR, XXXXXXX, XXXXXXX, BLOCKER, XXXXXXX
    ),
    [_ADD] = LAYOUT_btgrant(
        ___5ADD_1_L___,                                                           ___5ADD_1_R___,
        ___5ADD_2_L___,                                                           ___5ADD_2_R___,
        ___5ADD_3_L___,                                                           ___5ADD_3_R___,
        XXXXXXX, BLOCKER, XXXXXXX, XXXXXXX,     BAR,     BAR, XXXXXXX, XXXXXXX, BLOCKER, XXXXXXX
    )
};
