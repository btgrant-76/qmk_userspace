/* Copyright 2021 Danny Nguyen <danny@keeb.io>
   Copyright 2025 Brian Grant <@btgrant-76>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"

#include "combos.h"
#include "encoder_map.h"
#include "encoder_press.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_btgrant(
    ENC_BASE,  KC_ESC,  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,       KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL,  KC_BSPC,
    KC_PGUP,                                                ___BASE_1_L___,     ___5BASE_1_R___,                             KC_LBRC, KC_RBRC, KC_BSLS,
    KC_PGDN,                                                ___BASE_2_L___,     ___BASE_2_R___,                                                KC_ENT,
    KC_HOME,                                                ___BASE_3_L___,     ___BASE_3_R___,                                       XXXXXXX,
    KC_END,           KC_LCTL, KC_LALT, KC_LGUI,        ___BASE_THUMB_L___,     ___BASE_THUMB_R___,        KC_RGUI, KC_RALT, KC_RCTL
  ),
  [_NUM] = LAYOUT_btgrant(
    ENC_NUM, QK_BOOT, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    BL_STEP,                                                 ___NUM_1_L___,     ___NUM_1_R___,                                        _______, _______,
    RGB_MOD,                                                 ___NUM_2_L___,     ___NUM_2_R___,                                                 _______,
    KC_VOLU,                                                 ___NUM_3_L___,     ___NUM_3_R___,                                        _______,
    KC_VOLD,          _______, _______, _______,         ___NUM_THUMB_L___,     ___NUM_THUMB_R___,         _______, _______, _______
  ),
  [_SYM] = LAYOUT_btgrant(
    ENC_SYM, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,                                                 ___SYM_1_L___,     ___SYM_1_R___,                                        _______, _______,
    _______,                                                 ___SYM_2_L___,     ___SYM_2_R___,                                                 _______,
    _______,                                                 ___SYM_3_L___,     ___SYM_3_R___,                                        _______,
    _______,          _______, _______, _______,         ___SYM_THUMB_L___,     ___SYM_THUMB_R___,         _______, _______, _______
  ),
  [_NAV] = LAYOUT_btgrant(
    ENC_NAV, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,                                                 ___NAV_1_L___,     ___NAV_1_R___,                                        _______, _______,
    _______,                                                 ___NAV_2_L___,     ___NAV_2_R___,                                                 _______,
    _______,                                                 ___NAV_3_L___,     ___NAV_3_R___,                                        _______,
    _______,          _______, _______, _______,         ___NAV_THUMB_L___,     ___NAV_THUMB_R___,         _______, _______, _______
  ),
  [_FUN] = LAYOUT_btgrant(
    ENC_FUN, _______, _______,   TD_F1,   TD_F2,   KC_F3,   KC_F4,   KC_F5,     TD_F6,   KC_F7,   KC_F8,   TD_F9,   KC_F10,   KC_F11,  TD_F12, _______,
    _______,                                                 ___FUN_1_L___,     ___FUN_1_R___,                                        _______, _______,
    _______,                                                 ___FUN_2_L___,     ___FUN_2_R___,                                                 _______,
    _______,                                                 ___FUN_3_L___,     ___FUN_3_R___,                                        _______,
    _______,          _______, _______, _______,         ___FUN_THUMB_L___,     ___FUN_THUMB_R___,         _______, _______, _______
  ),
  [_MSE] = LAYOUT_btgrant(
    ENC_MSE, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX,                                       ___5MSE_1_L___,     ___5MSE_1_R___,                               XXXXXXX,_______, _______,
    _______, XXXXXXX,                                       ___5MSE_2_L___,     ___5MSE_2_R___,                               XXXXXXX,         _______,
    _______, XXXXXXX,                                       ___5MSE_3_L___,     ___5MSE_3_R___,                               XXXXXXX,_______,
    _______,          _______, _______, _______,         ___MSE_THUMB_L___,     ___MSE_THUMB_R___,         _______, _______, _______
  ),
  [_ADD] = LAYOUT_btgrant(
    ENC_ADD, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX,                                       ___5ADD_1_L___,     ___5ADD_1_R___,                               XXXXXXX,_______, _______,
    _______, XXXXXXX,                                       ___5ADD_2_L___,     ___5ADD_2_R___,                               XXXXXXX,         _______,
    _______, XXXXXXX,                                       ___5ADD_3_L___,     ___5ADD_3_R___,                               XXXXXXX,_______,
    _______,          _______, _______, _______,         ___ADD_THUMB_L___,     ___ADD_THUMB_R___,         _______, _______, _______
  ),
  [_NRM] = LAYOUT_btgrant(
    ENC_NRM,  KC_ESC,  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,       KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL,  KC_BSPC,
    KC_PGUP,                                                 ___NRM_1_L___,     ___5BASE_1_R___,                             KC_LBRC, KC_RBRC, KC_BSLS,
    KC_PGDN,                                                 ___NRM_2_L___,     ___NRM_2_R___,                                                 KC_ENT,
    KC_HOME,                                                 ___NRM_3_L___,     ___NRM_3_R___,                                        XXXXXXX,
    KC_END,           KC_LCTL, KC_LALT, KC_LGUI,         ___NRM_THUMB_L___,     ___NRM_THUMB_R___,        KC_RGUI, KC_RALT, KC_RCTL
  ),
};
