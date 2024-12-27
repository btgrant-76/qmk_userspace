/* Copyright 2021 Kyle McCreery
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
#include "encoder_map.h"
#include "encoder_press.h" // TODO make sure all encoder presses are used below
#include "tap_dances.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_btgrant_all(
                                                                             ENC_BASE,
      ___BASE_1_L___,                                                  ___BASE_1_R___,
      ___BASE_2_L___,                                                  ___BASE_2_R___,
      ___BASE_3_L___,                                                  ___BASE_3_R___,
      XXXXXXX, ESC_FUN, TAB_MSE,  BS_NUM, XXXXXXX, SPC_NAV, DEL_MSE, ENT_SYM, XXXXXXX
  ),
  [_NUM] = LAYOUT_btgrant_all(
                                                                              ENC_NUM,
      ___NUM_1_L___,                                                    ___NUM_1_R___,
      ___NUM_2_L___,                                                    ___NUM_2_R___,
      ___NUM_3_L___,                                                    ___NUM_3_R___,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, ZERO_TD, _______, _______
  ),
  [_SYM] = LAYOUT_btgrant_all(
                                                                              ENC_SYM,
      ___SYM_1_L___,                                                    ___SYM_1_R___,
      ___SYM_2_L___,                                                    ___SYM_2_R___,
      ___SYM_3_L___,                                                    ___SYM_3_R___,
      _______, _______, KC_MUTE, KC_MPLY, XXXXXXX,LPRN_MSE, XXXXXXX, _______, _______
  ),
  [_NAV] = LAYOUT_btgrant_all(
                                                                              ENC_NAV,
      ___NAV_1_L___,                                                    ___NAV_1_R___,
      ___NAV_2_L___,                                                    ___NAV_2_R___,
      ___NAV_3_L___,                                                    ___NAV_3_R___,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),
  [_FUN] = LAYOUT_btgrant_all(
                                                                              ENC_FUN,
      ___FUN_1_L___,                                                    ___FUN_1_R___,
      ___FUN_2_L___,                                                    ___FUN_2_R___,
      ___FUN_3_L___,                                                    ___FUN_3_R___,
      _______, _______, XXXXXXX, MO(_MSE),XXXXXXX,MO(_ADD), XXXXXXX, _______, _______
  ),
  [_MSE] = LAYOUT_btgrant_all(
                                                                              ENC_MSE,
      ___MSE_1_L___,                                                    ___MSE_1_R___,
      ___MSE_2_L___,                                                    ___MSE_2_R___,
      ___MSE_3_L___,                                                    ___MSE_3_R___,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),
  [_ADD] = LAYOUT_btgrant_all(
                                                                              ENC_ADD,
      XXXXXXX, ___5ADD_1_L___,                                ___5ADD_1_R___, XXXXXXX,
      XXXXXXX, ___5ADD_2_L___,                                ___5ADD_2_R___, XXXXXXX,
      XXXXXXX, ___5ADD_3_L___,                                ___5ADD_3_R___, XXXXXXX,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),
//  ),
//  [_NRM] = LAYOUT_btgrant_4x12( // TODO add a NRM layer
//  //|-----------------------------------------------------|        |-----------------------------------------------------|
//                                             ___NRM_1_L___,         ___NRM_1_R___,
//  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
//                                             ___NRM_2_L___,         ___NRM_2_R___,
//  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
//                                             ___NRM_3_L___,         ___NRM_3_R___,
//  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
//      KC_LCTL, KC_LALT, KC_LGUI,         ___NRM_THUMB_L___,         ___NRM_THUMB_R___,          KC_RGUI, KC_RALT, KC_RCTL
//  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
  [_NRM] = LAYOUT_btgrant_all(
                                                                             ENC_BASE,
      ___NRM_1_L___,                                                    ___NRM_1_R___,
      ___NRM_2_L___,                                                    ___NRM_2_R___,
      ___NRM_3_L___,                                                    ___NRM_3_R___,
//      XXXXXXX, ESC_FUN, TAB_MSE,  BS_NUM, XXXXXXX, SPC_NAV, DEL_MSE, ENT_SYM, XXXXXXX
      KC_LCTL, KC_LALT, KC_LGUI,  KC_SPC,MO(_NUM), SPC_NAV, KC_RGUI, KC_RALT, KC_RCTL
  )
};
