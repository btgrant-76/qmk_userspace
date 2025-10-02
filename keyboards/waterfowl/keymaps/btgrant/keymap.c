/* Copyright 2022  CyanDuck
* Copyright 2025 Brian Grant <@btgrant-76>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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
#include "tap_dances.c"
#include "key_overrides.h"

#include "combos.h"

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_btgrant(
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
    );
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(
                 ___5BASE_1_L___,                         ___5BASE_1_R___,
                 ___5BASE_2_L___,                         ___5BASE_2_R___,
                 ___5BASE_3_L___,                         ___5BASE_3_R___,
        XXXXXXX, ___BASE_THUMB_L___,    KC_MPLY, KC_MUTE, ___BASE_THUMB_R___, KC_4
    ),
    [_NUM] = LAYOUT_btgrant(
                 ___5NUM_1_L___,                         ___5NUM_1_R___,
                 ___5NUM_2_L___,                         ___5NUM_2_R___,
                 ___5NUM_3_L___,                         ___5NUM_3_R___,
        XXXXXXX, ___NUM_THUMB_L___,	XXXXXXX, XXXXXXX, ___NUM_THUMB_R___, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant(
                 ___5SYM_1_L___,                         ___5SYM_1_R___,
                 ___5SYM_2_L___,                         ___5SYM_2_R___,
                 ___5SYM_3_L___,                         ___5SYM_3_R___,
        XXXXXXX, ___SYM_THUMB_L___, XXXXXXX, XXXXXXX, ___SYM_THUMB_R___, XXXXXXX
    ),
    [_NAV] =  LAYOUT_btgrant(
                 ___5NAV_1_L___,                         ___5NAV_1_R___,
                 ___5NAV_2_L___,                         ___5NAV_2_R___,
                 ___5NAV_3_L___,                         ___5NAV_3_R___,
        XXXXXXX, ___NAV_THUMB_L___, XXXXXXX, XXXXXXX, ___NAV_THUMB_R___, XXXXXXX
    ),
    [_FUN] =  LAYOUT_btgrant(
                 ___5FUN_1_L___,                         ___5FUN_1_R___,
                 ___5FUN_2_L___,                         ___5FUN_2_R___,
                 ___5FUN_3_L___,                         ___5FUN_3_R___,
        XXXXXXX, ___FUN_THUMB_L___, XXXXXXX, XXXXXXX, ___FUN_THUMB_R___, XXXXXXX
    ),
    [_MSE] =  LAYOUT_btgrant(
                 ___5MSE_1_L___,                         ___5MSE_1_R___,
                 ___5MSE_2_L___,                         ___5MSE_2_R___,
                 ___5MSE_3_L___,                         ___5MSE_3_R___,
        XXXXXXX, ___MSE_THUMB_L___, XXXXXXX, XXXXXXX, ___MSE_THUMB_R___, XXXXXXX
    ),
    [_ADD] =  LAYOUT_btgrant(
                 ___5ADD_1_L___,                         ___5ADD_1_R___,
                 ___5ADD_2_L___,                         ___5ADD_2_R___,
                 ___5ADD_3_L___,                         ___5ADD_3_R___,
        XXXXXXX, ___ADD_THUMB_L___, XXXXXXX, XXXXXXX, ___ADD_THUMB_R___, XXXXXXX
    )
};


#ifdef ENCODER_MAP_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        return false;
    };

    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        //        { left roller (R, L),                   left knob (L, R),                 right roller (R, L),              right knob (R, L) }
        [_BASE] = { ENCODER_CCW_CW(KC_TAB, LSFT(KC_TAB)), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
        [_NUM]  = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),     ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
        [_SYM]  = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV),     ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
        [_NAV]  = { ENCODER_CCW_CW(FWD, BACK),            ENCODER_CCW_CW(BACK, FWD) },
        [_FUN]  = { ENCODER_CCW_CW(KC_BRIU, KC_BRID),     ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
        [_MSE]  = { ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC),   ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC) },
        [_ADD]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),     ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
    };
#endif

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    if (is_keyboard_master()) {
        oled_write_P(PSTR("LAYER:\n"), false);
        oled_write_P(PSTR("\n"), false);

        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("DEFAULT\n\n\n\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("NUMBERS\n\n\n\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("SYMBOLS\n\n\n\n"), false);
                break;
            case _FUN:
                oled_write_P(PSTR("FUNCTION\n\n\n\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("NAVIGATION\n\n\n\n"), false);
                break;
            case _MSE:
                oled_write_P(PSTR("MOUSE\n\n\n\n"), false);
                break;
            case _ADD:
                oled_write_P(PSTR("ADDITIONAL\n\n\n\n"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Undefined"), false);
        }
        return false;
    } else {
        return true;
    }
};

#endif
