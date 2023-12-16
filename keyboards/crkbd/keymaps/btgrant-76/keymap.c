/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 Brian Grant <@btgrant-76>

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
#include "btgrant-76.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_btgrant_3x6(
    ___BASE_1_L___,         ___BASE_1_R___,
    ___BASE_2_L___,         ___BASE_2_R___,
    ___BASE_3_L___,         ___BASE_3_R___,
    ___BASE_THUMB_L___, ___BASE_THUMB_R___
  ),
  [_NUM] = LAYOUT_btgrant_3x6(
    ___NUM_1_L___,         ___NUM_1_R___,
    ___NUM_2_L___,         ___NUM_2_R___,
    ___NUM_3_L___,         ___NUM_3_R___,
    ___NUM_THUMB_L___, ___NUM_THUMB_R___
  ),

  [_SYM] = LAYOUT_btgrant_3x6(
    ___SYM_1_L___,         ___SYM_1_R___,
    ___SYM_2_L___,         ___SYM_2_R___,
    ___SYM_3_L___,         ___SYM_3_R___,
    ___SYM_THUMB_L___, ___SYM_THUMB_R___
  ),

  [_NAV] = LAYOUT_btgrant_3x6(
    ___NAV_1_L___,         ___NAV_1_R___,
    ___NAV_2_L___,         ___NAV_2_R___,
    ___NAV_3_L___,         ___NAV_3_R___,
    ___NAV_THUMB_L___, ___NAV_THUMB_R___
  ),

  [_FUN] = LAYOUT_btgrant_3x6(
    ___FUN_1_L___,          ___FUN_1_R___,
    ___FUN_2_L___,          ___FUN_2_R___,
    ___FUN_3_L___,          ___FUN_3_R___,
    ___FUN_THUMB_L___,  ___FUN_THUMB_R___
  ),
  [_MSE] = LAYOUT_btgrant_3x6(
    XXXXXXX, ___5MSE_1_L___,          ___5MSE_1_R___, XXXXXXX,
    XXXXXXX, ___5MSE_2_L___,          ___5MSE_2_R___, XXXXXXX,
    XXXXXXX, ___5MSE_3_L___,          ___5MSE_3_R___, XXXXXXX,
          ___MSE_THUMB_L___,          ___MSE_THUMB_R___
  ),
  [_ADD] = LAYOUT_btgrant_3x6(
      XXXXXXX, ___5ADD_1_L___,         ___5ADD_1_R___, XXXXXXX,
      XXXXXXX, ___5ADD_2_L___,         ___5ADD_2_R___, XXXXXXX,
      XXXXXXX, ___5ADD_3_L___,         ___5ADD_3_R___, XXXXXXX,
            ___ADD_THUMB_L___,         ___ADD_THUMB_R___
  )
};

bool achordion_chord_keymap(uint16_t tap_hold_keycode,
                            keyrecord_t* tap_hold_record,
                            uint16_t other_keycode,
                            keyrecord_t* other_record) {

  switch (tap_hold_record->event.key.row) {
    case 3:
    case 7:
        return true;
    break;
  }

  return false;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
  return rotation;
};

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_NAV)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_SYM)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_NUM)) {
        oled_write_P(raise_layer, false);
    } else if(layer_state_is(_FUN)) {
        oled_write_P(adjust_layer,false);
    } else if(layer_state_is(_MSE)) {
        oled_write_P(adjust_layer,false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);

    if(layer_state_is(_NAV)) {
        oled_write_ln_P(PSTR("Nav"), false);
    } else if(layer_state_is(_SYM)) {
        oled_write_ln_P(PSTR("Symbol"), false);
    } else if(layer_state_is(_NUM)) {
        oled_write_ln_P(PSTR("Number"), false);
    } else if(layer_state_is(_FUN)) {
        oled_write_ln_P(PSTR("Function"), false);
    } else if(layer_state_is(_MSE)) {
        oled_write_ln_P(PSTR("Mouse"), false);
    } else {
        oled_write_ln_P(PSTR("Default"), false);
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        // Renders the current keyboard state (layers and mods)
        render_logo();
        render_space();
        render_layer_state();
        render_space();
        render_mod_status_gui_alt(get_mods()); // |get_oneshot_mods());
        render_mod_status_ctrl_shift(get_mods()); // |get_oneshot_mods());
    }
    return false;
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
    }
}

#endif


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_keymap(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_ORANGE);
  rgblight_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}
#endif
