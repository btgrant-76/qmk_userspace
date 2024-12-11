/* Copyright 2021 Nathan Spears
 * Copyright 2024 Brian Grant <@btgrant-76>
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
#include "combos.h"
#include "tap_dances.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_btgrant_grid(
  //|--------------------------------------------------------------------------------------------------------------------------------------------------------|
       KC_ESC, KC_PSLS, KC_PAST, KC_PENT,                                       ___BASE_1_L___, KC_PGUP,                                       ___BASE_1_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_7,    KC_8,    KC_9, KC_PMNS,                                       ___BASE_2_L___, KC_PGDN,                                       ___BASE_2_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_4,    KC_5,    KC_6, KC_PPLS,                                       ___BASE_3_L___, KC_HOME,                                       ___BASE_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_1,  TWO_TD,THREE_TD, ZERO_TD, KC_LCTL, KC_LALT, KC_LGUI,        ___BASE_THUMB_L___,  KC_END,        ___BASE_THUMB_R___, KC_RALT,    BACK,     FWD
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
),
[_NUM] = LAYOUT_btgrant_grid(
  //|--------------------------------------------------------------------------------------------------------------------------------------------------------|
      _______, _______, _______, _______,                                        ___NUM_1_L___, _______,                                        ___NUM_1_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___NUM_2_L___, _______,                                        ___NUM_2_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___NUM_3_L___, _______,                                        ___NUM_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,         ___NUM_THUMB_L___, _______,         ___NUM_THUMB_R___, _______, _______, _______
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
),
[_SYM] = LAYOUT_btgrant_grid(
  //|--------------------------------------------------------------------------------------------------------------------------------------------------------|
      _______, _______, _______, _______,                                        ___SYM_1_L___, _______,                                        ___SYM_1_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___SYM_2_L___, _______,                                        ___SYM_2_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___SYM_3_L___, _______,                                        ___SYM_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,         ___SYM_THUMB_L___, _______,         ___SYM_THUMB_R___, _______, _______, _______
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
),
[_NAV] = LAYOUT_btgrant_grid(
  //|--------------------------------------------------------------------------------------------------------------------------------------------------------|
      _______, _______, _______, _______,                                        ___NAV_1_L___, _______,                                        ___NAV_1_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___NAV_2_L___, _______,                                        ___NAV_2_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___NAV_3_L___, _______,                                        ___NAV_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,         ___NAV_THUMB_L___, _______,         ___NAV_THUMB_R___, _______, _______, _______
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
),
[_FUN] = LAYOUT_btgrant_grid(
  //|--------------------------------------------------------------------------------------------------------------------------------------------------------|
      _______, _______, _______, _______,                                        ___FUN_1_L___, _______,                                        ___FUN_1_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___FUN_2_L___, _______,                                        ___FUN_2_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___FUN_3_L___, _______,                                        ___FUN_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,         ___FUN_THUMB_L___, _______,         ___FUN_THUMB_R___, _______, _______, _______
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
),
[_MSE] = LAYOUT_btgrant_grid(
  //|--------------------------------------------------------------------------------------------------------------------------------------------------------|
      _______, _______, _______, _______,                                        ___MSE_1_L___, _______,                                        ___MSE_1_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___MSE_2_L___, _______,                                        ___MSE_2_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,                                        ___MSE_3_L___, _______,                                        ___MSE_3_R___,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,         ___MSE_THUMB_L___, _______,         ___MSE_THUMB_R___, _______, _______, _______
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
),
[_ADD] = LAYOUT_btgrant_grid(
  //|--------------------------------------------------------------------------------------------------------------------------------------------------------|
      _______, _______, _______, _______, _______,                              ___5ADD_1_L___, _______,                              ___5ADD_1_R___, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                              ___5ADD_2_L___, _______,                              ___5ADD_2_R___, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                              ___5ADD_3_L___, _______,                              ___5ADD_3_R___, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,         ___ADD_THUMB_L___, _______,         ___ADD_THUMB_R___, _______, _______, _______
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
)
};

bool achordion_chord_keymap(uint16_t tap_hold_keycode,
                            keyrecord_t* tap_hold_record,
                            uint16_t other_keycode,
                            keyrecord_t* other_record) {
/* col, row
  |--------------------------------------------------------------------------------------------------------------------------------------------------------|
    0, 0     0, 1     1, 0     1, 1   | 2, 0   | 2, 1     3, 0     3, 1     4, 0     4, 1   | 5, 0   | 5, 1     6, 0     6, 1     7, 0     7, 1   | 8, 1
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    0, 2     0, 3     1, 2     1, 3   | 2, 2   |[2, 3]   [3, 2]   [3, 3]   [4, 2]    4, 3   | 5, 2   | 5, 3    [6, 2]   [6, 3]   [7, 2]   [7, 3]  | 8, 3
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    0, 4     0, 5     1, 4     1, 5   | 2, 4   |[2, 5]    3, 4     3, 5     4, 4    [4, 5]  | 5, 4   |[5, 5]    6, 4     6, 5     7, 4    [7, 5]  | 8, 5
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    0, 6     0, 7     1, 6     1, 7   | 2, 6   | 2, 7     3, 6    [3, 7]   [4, 6]   [4, 7]  | 5, 6   |[5, 7]   [6, 6]   [6, 7]    7, 6     7, 7   | 8, 7
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
*/
    dprintln("achordion_chord_keymap called");

    if (tap_hold_record->event.key.row >= 6) {
        #ifdef CONSOLE_ENABLE
        dprintln("achordion_chord_keymap: triggered thumb cluster\n");
        #endif
        return true; // thumb clusters
    }

    switch (tap_hold_record->event.key.col) {
        case 4:
            if (other_record->event.key.col >= 5) {
                return true; // B/Meh with opposite hand
            }
        case 5:
        case 6:
        case 7:
            if (other_record->event.key.col == 4) {
                return true; // right HRM with T column
            }
    }

    #ifdef CONSOLE_ENABLE
    dprintln("achordion_chord_keymap: return false\n");
    #endif
    return false;
};
