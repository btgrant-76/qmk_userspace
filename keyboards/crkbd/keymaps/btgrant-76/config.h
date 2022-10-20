/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

// from QMK squeezing...
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT
// end QMK squeezing

//#define USE_MATRIX_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// syncing up with Waka QMK Settings Tap-Hold configuration
// these were the original settings from the Vial
//#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 150
// additional details on these configurations:  https://docs.qmk.fm/#/config_options?id=behaviors-that-can-be-configured
#define TAPPING_TERM 150
#undef PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#undef TAPPING_FORCE_HOLD
#undef RETRO_TAPPING
#define TAP_CODE_DELAY 10
#define TAP_HOLD_CAPS_DELAY 80

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// from soundmonster

#define USE_SERIAL_PD2

#ifdef OLED_ENABLE
#   define SPLIT_LAYER_STATE_ENABLE
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
#   define OLED_FONT_H "keyboards/crkbd/keymaps/soundmonster/glcdfont.c"
#   define OLED_TIMEOUT 30000
#endif
