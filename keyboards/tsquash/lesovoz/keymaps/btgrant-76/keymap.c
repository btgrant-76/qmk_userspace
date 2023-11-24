/* Copyright 2022 Caleb Lightfoot
 * Copyright 2023 Brian Grant <@btgrant-76>
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
#include "btgrant-76.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(
        ___5BASE_1_L___,                                            ___5BASE_1_R___,
        ___5BASE_2_L___,                                            ___5BASE_2_R___,
        ___5BASE_3_L___,                                            ___5BASE_3_R___,
        XXXXXXX, XXXXXXX, ___BASE_THUMB_L___,  ___BASE_THUMB_R___, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT_btgrant(
        ___5NUM_1_L___,                                              ___5NUM_1_R___,
        ___5NUM_2_L___,                                              ___5NUM_2_R___,
        ___5NUM_3_L___,                                              ___5NUM_3_R___,
        XXXXXXX, XXXXXXX, ___NUM_THUMB_L___,   ___NUM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant(
        ___5SYM_1_L___,                                              ___5SYM_1_R___,
        ___5SYM_2_L___,                                              ___5SYM_2_R___,
        ___5SYM_3_L___,                                              ___5SYM_3_R___,
        XXXXXXX, XXXXXXX, ___SYM_THUMB_L___,   ___SYM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant(
        ___5NAV_1_L___,                                              ___5NAV_1_R___,
        ___5NAV_2_L___,                                              ___5NAV_2_R___,
        ___5NAV_3_L___,                                              ___5NAV_3_R___,
        XXXXXXX, XXXXXXX, ___NAV_THUMB_L___,   ___NAV_THUMB_R___,  XXXXXXX, XXXXXXX

    ),
    [_FUN] = LAYOUT_btgrant(
        ___5FUN_1_L___,                                              ___5FUN_1_R___,
        ___5FUN_2_L___,                                              ___5FUN_2_R___,
        ___5FUN_3_L___,                                              ___5FUN_3_R___,
        XXXXXXX, XXXXXXX, ___FUN_THUMB_L___,   ___FUN_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_MSE] = LAYOUT_btgrant(
        ___5MSE_1_L___,                                              ___5MSE_1_R___,
        ___5MSE_2_L___,                                              ___5MSE_2_R___,
        ___5MSE_3_L___,                                              ___5MSE_3_R___,
        XXXXXXX, XXXXXXX, ___MSE_THUMB_L___,   ___MSE_THUMB_R___,  XXXXXXX, XXXXXXX
    )
};

bool achordion_chord_keymap(uint16_t tap_hold_keycode,
                            keyrecord_t* tap_hold_record,
                            uint16_t other_keycode,
                            keyrecord_t* other_record) {

  return tap_hold_record->event.key.row == 3;
}
