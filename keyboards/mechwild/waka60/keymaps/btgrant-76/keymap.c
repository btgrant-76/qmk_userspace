/* Copyright 2021 Kyle McCreery
 * Copyright 2022 Brian Grant <@btgrant-76>
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
    [_BASE] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
        F1_TD,   F2_TD,   KC_F3,   KC_F4,   KC_F5,   F6_TD,            KC_F7,   KC_F8,   F9_TD,  KC_F10,  KC_F11,  F12_TD,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,SCLN_ALL,QUOT_MEH,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   Z_CTL,   X_ALT,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_N,    KC_M, KC_COMM, DOT_ALT,SLSH_CTL, ENT_SFT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         BACK, KC_LCTL, KC_LALT, KC_LGUI, BS_SYM,  ENT_NUM,  Z_MUTE,MO(_NUM), SPC_NAV, ESC_FUN,SCRN2CLP, SCRN2FL,     FWD
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_SYM] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, RCBR_TD,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,          KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
    _______, KC_LCTL, KC_LALT,  XXXXXXX, XXXXXXX, XXXXXXX,  KC_MPLY, KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_LPRN, RPRN_TD, XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_NUM] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    BACK,     FWD, XXXXXXX, XXXXXXX,          KC_LBRC,    KC_7,    KC_8,    KC_9, RBRC_TD, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RGB_SPI,           KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, KC_PENT,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_HOME, KC_BSLS,    KC_1,    KC_2,    KC_3, GRAV_TD, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, KC_MSTP, XXXXXXX, KC_MINS,    KC_0,  KC_DOT, XXXXXXX, XXXXXXX,  XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_NAV] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, TAB_LFT,    BACK,     FWD, TAB_RGT, XXXXXXX,             REDO,   PASTE,    COPY,     CUT,    UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,          KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LALT, DEL_GUI, KC_BSPC,  KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ),
    [_FUN] = LAYOUT(
  //|-----------------------------------------------------|        |-----------------------------------------------------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  F12_TD,   KC_F7,   KC_F8,   F9_TD, XXXXXXX,         SCRN2CLP, SCRN2FL,  UP_DIR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      LOG_OUT,  KC_F11,   KC_F4,   KC_F5,   F6_TD, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,   F1_TD,   F2_TD,   KC_F3, XXXXXXX, XXXXXXX, AU_TOG,  MU_TOG,  MU_MOD,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,  KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    )
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_SYM]  = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
        [_NUM]  = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
        [_NAV]  = { ENCODER_CCW_CW(BACK, FWD) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRIU, KC_BRID) }
    };
#endif
