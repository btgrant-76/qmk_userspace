/*
Copyright 2022 aki27

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

#include "quantum.h"
#include "btgrant.h"

typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
        report_mouse_t last_mouse;
    };
} cocot_config_t;

extern cocot_config_t cocot_config;

enum cocot_keycodes {
    COCOT_SAFE_RANGE = NEW_SAFE_RANGE,
//    COCOT_SAFE_RANGE = SAFE_RANGE,

    CPI_SW,  // Change the CPI of the trackball. With the default firmware, each press changes the CPI in the following order: 200 -> 400 -> 800 -> 1600 -> 3200 -> 200....
    SCRL_SW, // Changes the sensitivity of the sensor in scroll mode. The higher the value, the smaller the amount of scrolling.
    ROT_R15, // Turns the Y axis of the mouse sensor 15 degrees clockwise.
    ROT_L15, // Rotate the Y axis of the mouse sensor 15 degrees counterclockwise.
    SCRL_MO, // Enables scroll mode for as long as it is pressed.
    SCRL_TO, // Toggles between scroll mode and mouse mode each time it is pressed.
    SCRL_IN  // Inverts the scroll direction.
};


#ifdef VIA_ENABLE
    #define CPI_SW USER00
    #define SCRL_SW USER01
    #define ROT_R15 USER02
    #define ROT_L15 USER03
    #define SCRL_MO USER04
    #define SCRL_TO USER05
    #define SCRL_IN USER06
#endif

bool encoder_update_user(uint8_t index, bool clockwise);
bool encoder_update_kb(uint8_t index, bool clockwise);
bool cocot_get_scroll_mode(void);
void cocot_set_scroll_mode(bool mode);

void render_logo(void);
void oled_write_layer_state(void);
