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

#ifdef COMBO_ENABLE
#   include "combos.h"
#endif

#ifdef ENCODER_MAP_ENABLE
#   include "encoder_map.h"
#   include "encoder_press.h"
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_btgrant_all(
                                                                                                                  ENC_BASE,
      ___BASE_1_L___,               ___BASE_1_R___,
      ___BASE_2_L___,               ___BASE_2_R___,
      ___BASE_3_L___,               ___BASE_3_R___,
      KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,  KC_SPC,           KC_SPC,           KC_RALT, MO(2),            KC_RCTL ), // TODO space bars same as Le Chiffre

  [_NUM] = LAYOUT_btgrant_all(
                                                                                                                  ENC_NUM,
      ___NUM_1_L___,               ___NUM_1_R___,
      ___NUM_2_L___,               ___NUM_2_R___,
      ___NUM_3_L___,               ___NUM_3_R___,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_HOME, KC_TRNS,          KC_END,           KC_LEFT, KC_DOWN,          KC_RIGHT ),

  [_SYM] = LAYOUT_btgrant_all(
                                                                                                                  ENC_SYM,
      ___SYM_1_L___,               ___SYM_1_R___,
      ___SYM_2_L___,               ___SYM_2_R___,
      ___SYM_3_L___,               ___SYM_3_R___,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS ),

  [_NAV] = LAYOUT_btgrant_all(
                                                                                                                  ENC_NAV,
      ___NAV_1_L___,               ___NAV_1_R___,
      ___NAV_2_L___,               ___NAV_2_R___,
      ___NAV_3_L___,               ___NAV_3_R___,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS ),

  [_FUN] = LAYOUT_btgrant_all(
                                                                                                                  ENC_FUN,
      ___FUN_1_L___,               ___FUN_1_R___,
      ___FUN_2_L___,               ___FUN_2_R___,
      ___FUN_3_L___,               ___FUN_3_R___,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS ),

  [_MSE] = LAYOUT_btgrant_all(
                                                                                                                  ENC_MSE,
      ___MSE_1_L___,               ___MSE_1_R___,
      ___MSE_2_L___,               ___MSE_2_R___,
      ___MSE_3_L___,               ___MSE_3_R___,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS ),

  [_ADD] = LAYOUT_btgrant_all(
                                                                                                                  ENC_ADD,
      XXXXXXX, ___5ADD_1_L___,               ___5ADD_1_R___, XXXXXXX,
      XXXXXXX, ___5ADD_2_L___,               ___5ADD_2_R___, XXXXXXX,
      XXXXXXX, ___5ADD_3_L___,               ___5ADD_3_R___, XXXXXXX,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS )
};
