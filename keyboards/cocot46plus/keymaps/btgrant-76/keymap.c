/*
Copyright 2022 aki27
Copyright 2022 @btgrant-76

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


// Defines names for use in layer keycodes and the keymap
enum layer_number { // TODO use names that are more appropriate
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3,
    _FUNCTION = 4
};

enum custom_keycodes {
    SCRN2CLP = NEW_SAFE_RANGE, // macOS take screenshot to the clip board
    SCRN2FL,   // macOS take screenshot to a file
    Z_MUTE,    // toggle Zoom mute
    BRC_INST,  // type a pair of braces & move the cursor between them
    CBR_INST,  // type a pair of curly braces & move the cursor between them
    CODE_INST, // type a Markdown code fence & move the cursor inside
    GRV_INST,  // type a pair of backticks & move the cursor between them
    PRN_INST,  // type a pair of parens move the cursor between them
    QUO_INST,
    UP_DIR,
    LOG_OUT
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
// TODO crkbd & cocot46plus layers are in different orders; unify them
#define BS_SYM LT(1, KC_BSPC)
#define ENT_NUM LT(2, KC_ENT)
#define SPC_NAV LT(3, KC_SPC)
#define ESC_FUN LT(4, KC_ESC)

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
#define DEL_GUI LGUI_T(KC_DEL)

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

// macOS navigation
#define MISS_CTL LCTL_T(KC_UP)
#define LEFT_SPC LCTL_T(KC_LEFT)
#define RGHT_SPC LCTL_T(KC_RIGHT)

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
  [_BASE] = LAYOUT(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L,SCLN_ALL,QUOT_MEH,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   Z_CTL,   X_ALT,    KC_C,    KC_V,    KC_B,                                            KC_N,    KC_M, KC_COMM, DOT_ALT,SLSH_CTL, ENT_SFT,
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                    BACK, DEL_GUI,  BS_SYM, ENT_NUM,   KC_BTN1, KC_BTN2,     MO(2), SPC_NAV, ESC_FUN,     FWD,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                 KC_PGUP, KC_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, RCBR_TD,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                                         KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,                                         KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BACK,     FWD,        KC_UNDS, KC_LPRN, RPRN_TD, XXXXXXX,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX,    BACK,     FWD, XXXXXXX,                                         KC_LBRC,    KC_7,    KC_8,    KC_9, RBRC_TD, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,                                          KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, KC_PENT,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      _______, RGB_TOG,RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI,                                         KC_BSLS,    KC_1,    KC_2,    KC_3, GRAV_TD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, KC_MUTE, KC_MPLY, KC_MSTP,  KC_BTN4, KC_BTN5,    KC_MINS,    KC_0,  KC_DOT, XXXXXXX,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                  KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_TRACKBALL] = LAYOUT(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      XXXXXXX,SCRN2CLP, SCRN2FL, XXXXXXX, XXXXXXX,  UP_DIR,                                            REDO,   PASTE,    COPY,     CUT,    UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                                         KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,                                         KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                 _______, DEL_GUI, KC_BSPC,  KC_ENT,   KC_BTN1, KC_BTN2,   XXXXXXX, XXXXXXX, XXXXXXX, _______,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                 LEFT_SPC,MISS_CTL,  RGHT_SPC,       XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_FUNCTION] = LAYOUT(
  //|-----------------------------------------------------|                                       |-----------------------------------------------------|
      XXXXXXX,  F12_TD,   KC_F7,   KC_F8,   F9_TD, XXXXXXX,                                         SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      LOG_OUT,  KC_F11,   KC_F4,   KC_F5,   F6_TD, XXXXXXX,                                         SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                                       |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,   F1_TD,   F2_TD,   KC_F3, XXXXXXX,                                         SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX,  KC_SPC,  KC_TAB,  KC_BTN1, KC_BTN2,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             //|-----------------------------------------+--------+------------------------------------------|
                                                                  KC_PGUP, KC_BTN3, KC_PGDN,         XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )
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

void macos_log_out(void) {
    register_code(KC_LGUI);
    register_code(KC_LCTL);
    tap_code(KC_Q);
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
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
// END:  Tap Dance & macro functions

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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    case LOG_OUT:
        if (record->event.pressed) {
            macos_log_out();
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

// from default keymap
keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}


/*
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    int8_t degree = 45;
    int8_t x_rev, y_rev;
    x_rev =  + mouse_report.x * cos(degree) + mouse_report.y * sin(degree);
    y_rev =  - mouse_report.x * sin(degree) + mouse_report.y * cos(degree);
    if (isScrollMode) {
        mouse_report.h = x_rev;
        #ifdef COCOT_DRAGSCROLL_INVERT
                // Invert vertical scroll direction
                mouse_report.v = -y_rev;
        #else
                mouse_report.v = y_rev;
        #endif
        // mouse_report.v = y_rev;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = x_rev;
        mouse_report.y = y_rev;
    }
    return mouse_report;
}
*/

int hue_fst = -1;
int sat_fst = -1;
int val_fst = -1;


layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef RGBLIGHT_ENABLE
    hue_fst = rgblight_get_hue();
    sat_fst = rgblight_get_sat();
    val_fst = rgblight_get_val();
    #endif

    switch (get_highest_layer(state)) {
    case _LOWER:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        #endif
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_PURPLE, 0, 2);
        #endif
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        #endif
        cocot_set_scroll_mode(false);
        break;
    case _FUNCTION:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        #endif
        cocot_set_scroll_mode(false);
        break;
    default:
        #ifdef RGBLIGHT_ENABLE
        // rgblight_sethsv_range( 0, 0, 0, 0, 2);
        rgblight_sethsv_range(hue_fst, sat_fst, val_fst, 0, 2);
        #endif
        cocot_set_scroll_mode(false);
        break;
    }
    #ifdef RGBLIGHT_ENABLE
    rgblight_set_effect_range( 2, 10);
    #endif
  return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

// END from default keymap
