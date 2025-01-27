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
    CPI_SW,
    SCRL_SW,
    ROT_R15,
    ROT_L15,
    SCRL_MO,
    SCRL_TO,
    SCRL_IN
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
