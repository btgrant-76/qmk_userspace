/*
Copyright 2025 Brian Grant <@btgrant-76>
Copyright 2024 aki27

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
#include <stdio.h>
#include "quantum.h"

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"

#include "combos.h"
#include "encoder_press.h"

#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_btgrant(
      'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', '*', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R',
                '*', '*', '*', '*', '*', '*', '*'
    );
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* TODO look at other functions for the middle column based on other keyboards that have macros in the middle, e.g.
    Vault35 ortho, etc.
*/
  [_BASE] = LAYOUT_btgrant(
    ___5BASE_1_L___,                ___5BASE_1_R___,
    ___5BASE_2_L___,    KC_ESC,     ___5BASE_2_R___,
    ___5BASE_3_L___,                ___5BASE_3_R___,
    ___BASE_THUMB_L___, MS_BTN1, ___BASE_THUMB_R___
  ),
  [_NUM] = LAYOUT_btgrant(
    ___5NUM_1_L___,                  ___5NUM_1_R___,
    ___5NUM_2_L___,     KC_ESC,      ___5NUM_2_R___,
    ___5NUM_3_L___,                  ___5NUM_3_R___,
    ___NUM_THUMB_L___,  MS_BTN1,  ___NUM_THUMB_R___
  ),

  [_SYM] = LAYOUT_btgrant(
    ___5SYM_1_L___,                  ___5SYM_1_R___,
    ___5SYM_2_L___,     KC_ESC,      ___5SYM_2_R___,
    ___5SYM_3_L___,                  ___5SYM_3_R___,
    ___SYM_THUMB_L___,  MS_BTN1,  ___SYM_THUMB_R___
  ),
  [_NAV] = LAYOUT_btgrant(
    ___5NAV_1_L___,                  ___5NAV_1_R___,
    ___5NAV_2_L___,     KC_ESC,      ___5NAV_2_R___,
    ___5NAV_3_L___,                  ___5NAV_3_R___,
    ___NAV_THUMB_L___,  MS_BTN1,  ___NAV_THUMB_R___
  ),
  [_FUN] = LAYOUT_btgrant(
    ___5FUN_1_L___,                  ___5FUN_1_R___,
    ___5FUN_2_L___,     KC_ESC,      ___5FUN_2_R___,
    ___5FUN_3_L___,                  ___5FUN_3_R___,
    ___FUN_THUMB_L___,  MS_BTN1,  ___FUN_THUMB_R___
  ),
  [_MSE] = LAYOUT_btgrant(
    ___5MSE_1_L___,                         ___5MSE_1_R___,
    ___5MSE_2_L___,            MS_BTN2,     ___5MSE_2_R___,
    ___5MSE_3_L___,                         ___5MSE_3_R___,
    XXXXXXX, SCRL_MO, XXXXXXX, MS_BTN1,  ___MSE_THUMB_R___
  ),
  [_ADD] = LAYOUT_btgrant(
    ___5ADD_1_L___,                                 ___5ADD_1_R___,
    ___5ADD_2_L___,             CPI_SW,             ___5ADD_2_R___,
    ___5ADD_3_L___,                                 ___5ADD_3_R___,
    ROT_L15, ROT_R15, SCRL_MO,  SCRL_SW,  SCRL_TO, HOLD, SCRL_IN
    /*
      CPI_SW,  // Change the CPI of the trackball. With the default firmware, each press changes the CPI in the following order:
               // 200 -> 400 -> 800 -> 1600 ->   3200 ->     200....
      SCRL_SW, // Changes the sensitivity of the sensor in scroll mode. The higher the value, the smaller the amount of scrolling.
      ROT_R15, // Turns the Y axis of the mouse sensor 15 degrees clockwise.
      ROT_L15, // Rotate the Y axis of the mouse sensor 15 degrees counterclockwise.
      SCRL_MO, // Enables scroll mode for as long as it is pressed.
      SCRL_TO, // Toggles between scroll mode and mouse mode each time it is pressed.
      SCRL_IN, // Inverts the scroll direction.
      AM_TOG   // Toggle the function of auto mouse layer.
    */
  )
};

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
        [_SYM]  = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
        [_NUM]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_NAV]  = { ENCODER_CCW_CW(BACK,    FWD) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
        [_ADD]  = { ENCODER_CCW_CW(ROT_L15,  ROT_R15) }
    };
#endif

// TODO what is this doing?
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
      case KC_LCTL:
        return true;
      case KC_LSFT:
        return true;
      case SCRL_MO:
        return true;
      default:
        return false;
    }
    return is_mouse_record_user(keycode, record);
}

void keyboard_post_init_user(void) {
  tap_code(SCRL_IN); // the configuration to reverse the scroll direction doesn't seem to persist across resets
  // TODO try setting the value in config.h to 0 instead of false
}

#ifdef RGB_MATRIX_ENABLE
// TODO customize this?
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int is_layer = get_highest_layer(layer_state|default_layer_state);
    HSV hsv = {0, 255, rgblight_get_val()};
    if (is_layer == 1) {
      hsv.h = 11; //CORAL
    } else if (is_layer == 2)  {
      hsv.h = 85; //GREEN
    } else if (is_layer == 3)  {
      hsv.h = 43; //YELLOW
    } else if (is_layer == 4)  {
      hsv.h = 0; //RED
    } else if (is_layer == 5)  {
      hsv.h = 191; //PURPLE
    } else if (is_layer == 6)  {
      hsv.h = 64; //CHARTREUSE
    } else if (is_layer == 7)  {
      hsv.h = 224;
    } else {
      hsv.h = 128; //CYAN
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
};
#endif

