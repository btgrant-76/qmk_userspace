/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers { // TODO use names that are more appropriate
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,  // nav?
  _FUNC
};

enum custom_keycodes {
    SCRN2CLP = SAFE_RANGE, // macOS take screenshot to the clip board
    SCRN2FL,   // macOS take screenshot to a file
    Z_MUTE,    // toggle Zoom mute
    BRC_INST,  // type a pair of braces & move the cursor between them
    CBR_INST,  // type a pair of curly braces & move the cursor between them
    CODE_INST, // type a Markdown code fence & move the cursor inside
    GRV_INST,  // type a pair of backticks & move the cursor between them
    PRN_INST,  // type a pair of parens move the cursor between them
    QUO_INST,
    UP_DIR
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_RBRC,
    TD_RCBR,
    TD_RPRN,
    TD_GRAV,
    TD_F1,
    TD_F2,
    TD_F6,
    TD_F9,
    TD_F12,
};

// Layer Keys
//#define ESC_L1 LT(1,KC_ESC)
#define ESC_L1 LT(1,KC_ESC)
#define G_NUM LT(1,KC_G)
#define H_SYM LT(2,KC_H)

// Mod Tap
/// Home Row Mods
#define A_CTL LCTL_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_GUI LGUI_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define L_CTL RALT_T(KC_L)
#define SCLN_CTL RCTL_T(KC_SCLN)

/// Others
#define Z_CTL LCTL_T(KC_Z)
#define X_ALT LALT_T(KC_X)
#define DOT_ALT LALT_T(KC_DOT)
#define SLSH_CTL LCTL_T(KC_SLSH)

#define ENT_SFT RSFT_T(KC_ENT)
#define SPC_MEH MEH_T(KC_SPC)
#define QUOT_MEH MEH_T(KC_QUOT)
#define QUOT_ALL ALL_T(KC_QUOT)
#define SCLN_ALL ALL_T(KC_SCLN)

#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define REDO LSG(KC_Z)

// Shifted Keys
#define COLON LSFT(KC_SCLN)

// Other shortcuts
#define BACK LCMD(KC_LBRC)
#define FWD LCMD(KC_RBRC)

// Tap Dances
#define GRAV_TD TD(TD_GRAV)
#define RPRN_TD TD(TD_RPRN)
#define RBRC_TD TD(TD_RBRC)
#define RCBR_TD TD(TD_RCBR)
#define F1_TD TD(TD_F1)
#define F2_TD TD(TD_F2)
#define F6_TD TD(TD_F6)
#define F9_TD TD(TD_F9)
#define F12_TD TD(TD_F12)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,SCLN_ALL,QUOT_MEH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   Z_CTL,   X_ALT,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM, DOT_ALT,SLSH_CTL, ENT_SFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),   MO(2),     KC_SPC,   MO(3),    MO(4)
                                      //`--------------------------'  `--------------------------'

  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,RGB_RMOD,                      KC_LBRC,    KC_7,    KC_8,    KC_9, RBRC_TD, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, KC_BRIU,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, KC_PENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_VOLD, XXXXXXX, KC_MPRV, KC_MNXT, KC_BRID,                      KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_MPLY, _______,    KC_MINS,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(  // LOWER
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      GRAV_TD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, RCBR_TD,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    KC_UNDS, KC_LPRN, RPRN_TD
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3( // NAV
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         REDO,   PASTE,    COPY,     CUT,    UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  UP_DIR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX, _______,     Z_MUTE, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3( // FUN
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F7,   KC_F8,   F9_TD,  F12_TD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  // TODO move macros in here
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F4,   KC_F5,   F6_TD,  KC_F11, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   F1_TD,   F2_TD,   KC_F3,  KC_F10, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_SPC,   KC_TAB,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

// Tap Dance & macro functions
void braces_insert(void) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
};

void curly_braces_insert(void) {
    SEND_STRING("{}" SS_TAP(X_LEFT));
};

void parens_insert(void) {
    SEND_STRING("()" SS_TAP(X_LEFT));
};

void grave_pair_cursor_insertion(void) {
    SEND_STRING("``" SS_TAP(X_LEFT));
}

void code_fence(void) {
    SEND_STRING("```" SS_TAP(X_ENT) SS_TAP(X_ENT) "```" SS_TAP(X_UP));
}

void braces_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_RBRC);
    } else {
        braces_insert();
    }
};

void curly_brace_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("}");
    } else {
        curly_braces_insert();
    }
};

void parens_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(")");
    } else {
        parens_insert();
    }
};

void grave_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        grave_pair_cursor_insertion();
    } else if (state->count == 4){
        code_fence();
    } else {
        SEND_STRING("`");
    }
};

void f1_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F1);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_1);
        unregister_code(KC_LGUI);
    } else if (state->count == 3) {
        register_code(KC_LALT);
        tap_code(KC_F1);
        unregister_code(KC_LALT);
    }
}

void f2_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F2);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_F2);
        unregister_code(KC_LGUI);
    }
}

void f6_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F6);
    } else if (state->count == 2) {
        register_code(KC_LCTL);
        tap_code(KC_T);
        unregister_code(KC_LCTL);
    }
}

void f9_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F9);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_9);
        unregister_code(KC_LGUI);
    }
}

void f12_tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F12);
    } else if (state->count == 2) {
        register_code(KC_LALT);
        tap_code(KC_F12);
        unregister_code(KC_LALT);
    } else if (state->count == 3) {
        register_code(KC_LGUI);
        tap_code(KC_F12);
        unregister_code(KC_LGUI);
    }
}

// Tap Dance definition
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_RBRC] = ACTION_TAP_DANCE_FN(braces_tap_dance),
    [TD_RCBR] = ACTION_TAP_DANCE_FN(curly_brace_tap_dance),
    [TD_RPRN] = ACTION_TAP_DANCE_FN(parens_tap_dance),
    [TD_GRAV] = ACTION_TAP_DANCE_FN(grave_tap_dance),
    [TD_F1] = ACTION_TAP_DANCE_FN(f1_tap_dance),
    [TD_F2] = ACTION_TAP_DANCE_FN(f2_tap_dance),
    [TD_F6] = ACTION_TAP_DANCE_FN(f6_tap_dance),
    [TD_F9] = ACTION_TAP_DANCE_FN(f9_tap_dance),
    [TD_F12] = ACTION_TAP_DANCE_FN(f12_tap_dance),
};

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
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else if(layer_state_is(_FUNC)) {
        oled_write_P(adjust_layer,false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);

    if(layer_state_is(_ADJUST)) {
        oled_write_ln_P(PSTR("Nav"), false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_ln_P(PSTR("Number"), false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_ln_P(PSTR("Symbol"), false);
    } else if(layer_state_is(_FUNC)) {
        oled_write_ln_P(PSTR("Function"), false);
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

/*void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}*/

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  switch (keycode) {
    case SCRN2CLP:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            register_code(KC_4);

            unregister_code(KC_LGUI);
            unregister_code(KC_LCTRL);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_4);
        }
        return false;
    case SCRN2FL:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSHIFT);
            register_code(KC_4);

            unregister_code(KC_LGUI);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_4);
        }
        return false;
    case Z_MUTE:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSHIFT);
            register_code(KC_A);

            unregister_code(KC_LGUI);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_A);
        }
        return false;
    case BRC_INST:
        if (record->event.pressed) {
            braces_insert();
        }
        return false;
    case CBR_INST:
        if (record->event.pressed) {
            curly_braces_insert();
        }
        return false;
    case PRN_INST:
        if (record->event.pressed) {
            parens_insert();
        }
        return false;
    case GRV_INST:
        if (record->event.pressed) {
            grave_pair_cursor_insertion();
        }
        return false;
    case QUO_INST:
        if (record->event.pressed) {
            SEND_STRING("\"\"");
            tap_code(KC_LEFT);
        }
        return false;
    case UP_DIR:
        if (record->event.pressed) {
            SEND_STRING("../");
        }
        return false;
  }
  return true;
}

#ifdef COMBO_ENABLE
// Combo declarations
enum combos {
    CB_BRC_INST,
    CB_CBR_INST,
    CB_PRN_INST,
    COMBO_LENGTH
};

const uint16_t PROGMEM brc_inst[] = {KC_RBRC, KC_LBRC, COMBO_END};
const uint16_t PROGMEM cbr_inst[] = {KC_RCBR, KC_LCBR, COMBO_END};
const uint16_t PROGMEM prn_inst[] = {KC_RCBR, KC_LCBR, COMBO_END};

uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
    [CB_BRC_INST] = COMBO_ACTION(brc_inst),
    [CB_CBR_INST] = COMBO_ACTION(cbr_inst),
    [CB_PRN_INST] = COMBO_ACTION(prn_inst),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case CB_BRC_INST:
            if (pressed) {
                braces_insert()
            }
            break;
        case CB_CBR_INST:
            if (pressed) {
                curly_braces_insert();
            }
            break;
        case CB_PRN_INST:
            if (pressed) {
                parens_insert();
            }
            break;
    }
};
#endif // COMBO_ENABLED
