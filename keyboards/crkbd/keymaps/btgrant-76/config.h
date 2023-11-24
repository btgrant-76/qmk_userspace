/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2022 Brian Grant <@btgrant-76>

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

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// start from soundmonster
#define USE_SERIAL_PD2

#ifdef OLED_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_OLED_ENABLE
    #define OLED_FONT_H "keyboards/crkbd/keymaps/soundmonster/glcdfont.c"
    #define OLED_TIMEOUT 30000
#endif
// end from soundmonster
