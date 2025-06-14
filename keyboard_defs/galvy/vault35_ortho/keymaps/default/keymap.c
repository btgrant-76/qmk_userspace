#include QMK_KEYBOARD_H
#include <stdio.h>
#include <math.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_MUTE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_SPC,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_BSPC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        KC_LALT,   MO(1), KC_BSPC,  KC_ENT, KC_SPC,    MO(2),   MO(3)
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [1] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
       KC_GRV, _______, _______, _______, _______, _______, _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        _______, _______, _______, _______, _______, _______, _______
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [2] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      KC_TILD, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        _______, _______, _______, _______, _______, _______, _______
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [3] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
      _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLU,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLD,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        _______, _______, _______, _______, _______, _______, _______
                    //|--------+--------+--------+--------+--------+--------+--------|
  )
};

// ENCODER
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      switch(biton32(layer_state)){
        case 0:
          if (clockwise) {
              tap_code(KC_UP);
          } else {
              tap_code(KC_DOWN);
          }
          break;
      }
    }
    if (index == 1) {
      switch(biton32(layer_state)){
        case 0:
          if (clockwise) {
              tap_code(KC_RIGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;
      }
    }
    return false;
}

