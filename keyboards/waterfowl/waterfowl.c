/* Copyright 2022  CyanDuck
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

#include "quantum.h"
#include "waterfowl.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
            tap_code16(S(KC_TAB));
        } else {
            tap_code(KC_TAB);
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code16(S(KC_MS_WH_DOWN));
        } else {
            tap_code16(S(KC_MS_WH_UP));
        }
    } else if (index == 3) { // Right encoder
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }

    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master() && is_keyboard_left()) {
        return OLED_ROTATION_90;
    } else {
        return OLED_ROTATION_270;
    }
}
bool oled_task_kb(void) {
   if (!oled_task_user()) {
       return false;
   }
   if (is_keyboard_master()) {
       // Host Keyboard Layer Status
       oled_write_P(PSTR("LAYER:\n"), false);
       oled_write_P(PSTR("\n"), false);

       switch (get_highest_layer(layer_state)) {
           case 0:
               oled_write_P(PSTR("DEFAULT\n\n\n\n"), false);
               break;
           case 3:
               oled_write_P(PSTR("FUNCTION\n\n\n\n"), false);
               break;
           case 2:
               oled_write_P(PSTR("SYMBOLS\n\n\n\n"), false);
               break;
           case 1:
               oled_write_P(PSTR("NAVIGATIONAND\nNUMBERS\n"), false);
               break;
           default:
               oled_write_ln_P(PSTR("Undefined"), false);
       }
    } else {
        oled_write_raw_P(my_logo, sizeof(my_logo));
    }
    return true;
}
#endif
