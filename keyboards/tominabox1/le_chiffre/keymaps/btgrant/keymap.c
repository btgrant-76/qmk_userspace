/* Copyright 2020 tominabox1
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

#include "encoder_map.h"
#include "encoder_press.h"
#include "four_thumb_combos.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(
        ___5BASE_1_L___,              ENC_BASE,                    ___5BASE_1_R___,
        ___5BASE_2_L___,                                           ___5BASE_2_R___,
        ___5BASE_3_L___,                                           ___5BASE_3_R___,
        ___BASE_4_THUMB_L___,                                 ___BASE_4_THUMB_R___
    ),
    [_NUM] = LAYOUT_btgrant(
        ___5NUM_1_L___,                ENC_NUM,                    ___5NUM_1_R___,
        ___5NUM_2_L___,                                            ___5NUM_2_R___,
        ___5NUM_3_L___,                                            ___5NUM_3_R___,
        ___NUM_4_THUMB_L___,                                  ___NUM_4_THUMB_R___
    ),
    [_SYM] = LAYOUT_btgrant(
        ___5SYM_1_L___,                ENC_SYM,                    ___5SYM_1_R___,
        ___5SYM_2_L___,                                            ___5SYM_2_R___,
        ___5SYM_3_L___,                                            ___5SYM_3_R___,
        ___SYM_4_THUMB_L___,                                  ___SYM_4_THUMB_R___
    ),
    [_NAV] = LAYOUT_btgrant(
        ___5NAV_1_L___,                ENC_NAV,                    ___5NAV_1_R___,
        ___5NAV_2_L___,                                            ___5NAV_2_R___,
        ___5NAV_3_L___,                                            ___5NAV_3_R___,
        ___NAV_4_THUMB_L___,                                  ___NAV_4_THUMB_R___
    ),
    [_FUN] = LAYOUT_btgrant(
        ___5FUN_1_L___,                ENC_FUN,                    ___5FUN_1_R___,
        ___5FUN_2_L___,                                            ___5FUN_2_R___,
        ___5FUN_3_L___,                                            ___5FUN_3_R___,
        ___FUN_4_THUMB_L___,                                  ___FUN_4_THUMB_R___
    ),
    [_MSE] = LAYOUT_btgrant(
        ___5MSE_1_L___,                ENC_MSE,                    ___5MSE_1_R___,
        ___5MSE_2_L___,                                            ___5MSE_2_R___,
        ___5MSE_3_L___,                                            ___5MSE_3_R___,
        ___MSE_4_THUMB_L___,                                  ___MSE_4_THUMB_R___
    ),
    [_ADD] = LAYOUT_btgrant(
        ___5ADD_1_L___,                ENC_ADD,                    ___5ADD_1_R___,
        ___5ADD_2_L___,                                            ___5ADD_2_R___,
        ___5ADD_3_L___,                                            ___5ADD_3_R___,
        ___ADD_4_THUMB_L___,                                  ___ADD_4_THUMB_R___
    )
};
