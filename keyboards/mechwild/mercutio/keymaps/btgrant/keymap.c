/* Copyright 2021 Kyle McCreery
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

#include "combos.h"
#include "encoder_map.h"
#include "encoder_press.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_btgrant_all(
                                                                             ENC_BASE,
      ___BASE_1_L___,                                                  ___BASE_1_R___,
      ___BASE_2_L___,               KC_H,   J_SFT,   K_GUI,   L_ALT, XXXXXXX,SCLN_CTL,
      KC_LSFT, XXXXXXX, ___5BASE_3_L___,                              ___5BASE_3_R___,
      XXXXXXX, ESC_FUN, TAB_MSE,  BS_NUM, ENT_SYM, SPC_NAV, DEL_MSE, ENT_SYM, XXXXXXX
  ),
  [_NUM] = LAYOUT_btgrant_all(
                                                                              ENC_NUM,
      ___NUM_1_L___,                                                    ___NUM_1_R___,
      ___NUM_2_L___,              KC_EQL,    KC_4,    KC_5,    KC_6, XXXXXXX, KC_QUOT,
      _______, XXXXXXX, ___5NUM_3_L___,                                ___5NUM_3_R___,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,    KC_0, _______, _______
  ),
  [_SYM] = LAYOUT_btgrant_all(
                                                                              ENC_SYM,
      ___SYM_1_L___,                                                    ___SYM_1_R___,
      ___SYM_2_L___,             KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, XXXXXXX,  KC_DQT,
      _______, XXXXXXX, ___5SYM_3_L___,                                ___5SYM_3_R___,
      _______, _______, KC_MUTE, KC_MPLY, XXXXXXX,LPRN_MSE, XXXXXXX, _______, _______
  ),
  [_NAV] = LAYOUT_btgrant_all(
                                                                              ENC_NAV,
      ___NAV_1_L___,                                                    ___NAV_1_R___,
      ___NAV_2_L___,             KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  XXXXXXX, KC_QUOT,
      _______, XXXXXXX, ___5NAV_3_L___,                                ___5NAV_3_R___,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),
  [_FUN] = LAYOUT_btgrant_all(
                                                                              ENC_FUN,
      ___FUN_1_L___,                                                    ___FUN_1_R___,
      ___FUN_2_L___,              XXXXXXX,  KC_F4,   KC_F5,   F6_TD, XXXXXXX,  KC_F11,
      _______, XXXXXXX, ___5FUN_3_L___,                                ___5FUN_3_R___,
      _______, _______, XXXXXXX, MO(_MSE),XXXXXXX,MO(_ADD), XXXXXXX, _______, _______
  ),
  [_MSE] = LAYOUT_btgrant_all(
                                                                              ENC_MSE,
      ___MSE_1_L___,                                                    ___MSE_1_R___,
      ___MSE_2_L___,               MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, ___5MSE_3_L___,                                ___5MSE_3_R___,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),
  [_ADD] = LAYOUT_btgrant_all(
                                                                              ENC_ADD,
      XXXXXXX, ___5ADD_1_L___,                                ___5ADD_1_R___, XXXXXXX,
      XXXXXXX, ___5ADD_2_L___,                                ___5ADD_2_R___, XXXXXXX,
      XXXXXXX, XXXXXXX, ___5ADD_3_L___,                                ___5ADD_3_R___,
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),
  [_NRM] = LAYOUT_btgrant_all(
                                                                                       ENC_NRM,
      ___NRM_1_L___,                                                             ___NRM_1_R___,
      ___NRM_2_L___,                                  KC_H, KC_J, KC_K, KC_L, XXXXXXX, KC_SCLN,
      KC_LSFT, XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B,              KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
      KC_LCTL, KC_LALT, KC_LGUI,  KC_SPC,MO(_NUM), SPC_NAV, KC_RGUI, KC_RALT, KC_RCTL
  )
};
