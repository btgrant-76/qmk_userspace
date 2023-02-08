/*
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

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum layer_names {
    _BASE,
    _SYM,
    _NUM,
    _NAV,
    _FUN
};

enum custom_keycodes {
    SCRN2CLP = SAFE_RANGE, // macOS take screenshot to the clip board (crkbd: y; waka: y; cocot46plus: y)
    SCRN2FL, // macOS take screenshot to a file
    QUO_INST, // TODO set up a tap dance for this
    UP_DIR,
    LOG_OUT,
    NEW_SAFE_RANGE
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_RBRC,
    TD_RCBR,
    TD_RPRN,
    TD_LPRN,
    TD_GRAV,
    TD_F1,
    TD_F2,
    TD_F6,
    TD_F9,
    TD_F12,
};

// Layer Keys
#define DEL_FUN LT(_FUN, KC_DEL)
#define TAB_FUN LT(_FUN, KC_TAB)
#define BS_SYM LT(_SYM, KC_BSPC)
#define BS_NUM LT(_NUM, KC_BSPC)
#define ESC_SYM LT(_SYM,  KC_ESC)
#define ESC_NUM LT(_NUM, KC_ESC)
#define TAB_NUM LT(_NUM, XXXXXXX) // KC_TAB)
#define ENT_MED LT(_NUM, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)
#define BS_MOUS LT(_FUN, XXXXXXX) // KC_BSPC)
#define DEL_MOUS LT(_FUN, KC_DEL)
#define TAB_MOUS LT(_NUM, KC_TAB)

#define ESC_L1 LT(1, KC_ESC)
#define G_NUM LT(_NUM, KC_G)
#define H_SYM LT(_SYM, KC_H)
#define BS_SYM LT(_SYM, KC_BSPC)
#define ESC_FUN LT(_FUN, KC_ESC)
#define ENT_NUM LT(_NUM, KC_ENT)


// Outer columns
#undef ENABLE_QAZ
/// left
#ifdef ENABLE_QAZ
#define TAB XXXXXXX
#define ESC XXXXXXX
#define L_SFT XXXXXXX
#else
#define TAB KC_TAB
#define ESC KC_ESC
#define L_SFT KC_LSFT
#endif

/// right
#ifdef ENABLE_QAZ
#define BSPC XXXXXXX
#define QUOT XXXXXXX
#define ENT XXXXXXX
#define ENT_SFT XXXXXXX
#else
#define BSPC KC_BSPC
#define QUOT KC_QUOT
#define ENT KC_ENT
#define ENT_SFT RSFT_T(KC_ENT)
#endif
// Outer columns end

// Mod Tap
/// Home Row Mods
#define A_CTL LCTL_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_GUI LGUI_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define L_ALT RALT_T(KC_L)
#define SCLN_CTL RCTL_T(KC_SCLN)

/// Others
#define Z_CTL LCTL_T(KC_Z)
#define X_ALT LALT_T(KC_X)
#define DOT_ALT LALT_T(KC_DOT)
#define SLSH_CTL LCTL_T(KC_SLSH)
#define QUOT_MEH MEH_T(KC_QUOT)
#define QUOT_ALL ALL_T(KC_QUOT)
#define SCLN_ALL ALL_T(KC_SCLN)
#define SLSH_ALL ALL_T(KC_SLSH)
#define ESC_MEH MEH_T(KC_ESC)
#define Z_MEH MEH_T(KC_Z)

/// Thumb keys
#define DEL_GUI LGUI_T(KC_DEL)
#define SPC_MEH MEH_T(KC_SPC)

// Shortcuts
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define REDO LSG(KC_Z)

/// macOS navigation
#define MISS_CTL LCTL(KC_UP)
#define LEFT_SPC LCTL(KC_LEFT)
#define RGHT_SPC LCTL(KC_RIGHT)

/// Shifted Keys
#define COLON LSFT(KC_SCLN)

/// Other shortcuts
#define BACK LCMD(KC_LBRC)
#define FWD LCMD(KC_RBRC)
#define TAB_LFT LSG(KC_LBRC)
#define TAB_RGT LSG(KC_RBRC)
#define Z_MUTE MEH_T(KC_SPC)

#ifdef TAP_DANCE_ENABLE
// Tap Dances
#define GRAV_TD TD(TD_GRAV)
#define RPRN_TD TD(TD_RPRN)
#define LPRN_TD TD(TD_LPRN)
#define RBRC_TD TD(TD_RBRC)
#define RCBR_TD TD(TD_RCBR)
#define F1_TD TD(TD_F1)
#define F2_TD TD(TD_F2)
#define F6_TD TD(TD_F6)
#define F9_TD TD(TD_F9)
#define F12_TD TD(TD_F12)
#endif // TAP_DANCE_ENABLE

// portable keymaps
#define ___HRM_L___        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT
#define ___HRM_R___        KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL

// base
#define ___5BASE_1_L___     KC_Q,   KC_W,   KC_E,    KC_R,   KC_T
#define ___5BASE_2_L___     A_CTL,  S_ALT,  D_GUI,   F_SFT,  KC_G
#define ___5BASE_3_L___     Z_MEH,  KC_X,   KC_C,    KC_V,   KC_B
#define ___BASE_THUMB_L___                  TAB_FUN, BS_NUM, ESC_SYM

#define ___BASE_1_L___      TAB,     ___5BASE_1_L___
#define ___BASE_2_L___      ESC,     ___5BASE_2_L___
#define ___BASE_3_L___      L_SFT,   ___5BASE_3_L___

#define ___5BASE_1_R___     KC_Y,    KC_U,    KC_I,    KC_O,   KC_P
#define ___5BASE_2_R___     KC_H,    J_SFT,   K_GUI,   L_ALT,  SCLN_CTL
#define ___5BASE_3_R___     KC_N,    KC_M,    KC_COMM, KC_DOT, SLSH_ALL
#define ___BASE_THUMB_R___  ENT_MED, SPC_NAV, DEL_MOUS

#define ___BASE_1_R___     ___5BASE_1_R___, BSPC
#define ___BASE_2_R___     ___5BASE_2_R___, QUOT
#define ___BASE_3_R___     ___5BASE_3_R___, ENT_SFT

// symbol
#define ___5SYM_1_L___     XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___5SYM_2_L___     ___HRM_L___,                            XXXXXXX
#define ___5SYM_3_L___     XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___SYM_THUMB_L___                        XXXXXXX, XXXXXXX, XXXXXXX

#define ___SYM_1_L___     XXXXXXX, ___5SYM_1_L___
#define ___SYM_2_L___     KC_CAPS, ___5SYM_2_L___
#define ___SYM_3_L___     _______, ___5SYM_3_L___

#define ___5SYM_1_R___     KC_LCBR, KC_AMPR, KC_ASTR, LPRN_TD, RCBR_TD
#define ___5SYM_2_R___     KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT
#define ___5SYM_3_R___     KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD
#define ___SYM_THUMB_R___  KC_UNDS, KC_LPRN, RPRN_TD

#define ___SYM_1_R___      ___5SYM_1_R___, KC_DEL
#define ___SYM_2_R___      ___5SYM_2_R___, KC_TILD
#define ___SYM_3_R___      ___5SYM_3_R___, XXXXXXX

// number
#define ___5NUM_1_L___     KC_MPRV,     KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX
#define ___5NUM_2_L___     ___HRM_L___,                            RGB_SPI
#define ___5NUM_3_L___     RGB_TOG,     RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
#define ___NUM_THUMB_L___                        KC_MUTE, KC_MPLY, KC_MSTP

#define ___NUM_1_L___     XXXXXXX, ___5NUM_1_L___
#define ___NUM_2_L___     XXXXXXX, ___5NUM_2_L___
#define ___NUM_3_L___     _______, ___5NUM_3_L___

#define ___5NUM_1_R___    KC_LBRC, KC_7, KC_8,  KC_9, RBRC_TD
#define ___5NUM_2_R___    KC_EQL,  KC_4, KC_5,  KC_6, KC_QUOT
#define ___5NUM_3_R___    KC_BSLS, KC_1, KC_2,  KC_3, GRAV_TD
#define ___NUM_THUMB_R___ KC_MINS, KC_0, KC_DOT

#define ___NUM_1_R___     ___5NUM_1_R___, KC_BSPC
#define ___NUM_2_R___     ___5NUM_2_R___, KC_PENT
#define ___NUM_3_R___     ___5NUM_3_R___, _______

// navigation
#define ___5NAV_1_L___    TAB_LFT, BACK,    FWD,     TAB_RGT, UP_DIR
#define ___5NAV_2_L___    ___HRM_L___,                        XXXXXXX
#define ___5NAV_3_L___    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___NAV_THUMB_L___                   DEL_GUI, KC_BSPC, KC_ENT

#define ___NAV_1_L___     XXXXXXX, ___5NAV_1_L___
#define ___NAV_2_L___     XXXXXXX, ___5NAV_2_L___
#define ___NAV_3_L___     _______, ___5NAV_3_L___

#define ___5NAV_1_R___    REDO,    PASTE,   COPY,    CUT,      UNDO
#define ___5NAV_2_R___    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_CAPS
#define ___5NAV_3_R___    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_INS
#define ___NAV_THUMB_R___ XXXXXXX, XXXXXXX, XXXXXXX

#define ___NAV_1_R___     ___5NAV_1_R___, XXXXXXX
#define ___NAV_2_R___     ___5NAV_2_R___, XXXXXXX
#define ___NAV_3_R___     ___5NAV_3_R___, _______

// function
#define ___5FUN_1_L___    XXXXXXX, UP_DIR,  SCRN2CLP, SCRN2FL, XXXXXXX
#define ___5FUN_2_L___    XXXXXXX, DT_PRNT, DT_UP,    DT_DOWN
#define ___5FUN_3_L___    XXXXXXX, AS_RPT,  AS_UP,    AS_DOWN, XXXXXXX
#define ___FUN_THUMB_L___                   XXXXXXX,  KC_SPC,  KC_TAB

#define ___FUN_1_L___     XXXXXXX, ___5FUN_1_L___
#define ___FUN_2_L___     LOG_OUT, ___5FUN_2_L___
#define ___FUN_3_L___     _______, ___5FUN_3_L___

#define ___5FUN_1_R___    XXXXXXX, KC_F7,   KC_F8,   F9_TD, F12_TD
#define ___5FUN_2_R___    XXXXXXX, KC_F4,   KC_F5,   F6_TD, KC_F11
#define ___5FUN_3_R___    XXXXXXX, F1_TD,   F2_TD,   KC_F3, KC_F10
#define ___FUN_THUMB_R___ XXXXXXX, XXXXXXX, XXXXXXX

#define ___FUN_1_R___     ___5FUN_1_R___, XXXXXXX
#define ___FUN_2_R___     ___5FUN_2_R___, XXXXXXX
#define ___FUN_3_R___     ___5FUN_3_R___, XXXXXXX

// layout macros
#define LAYOUT_btgrant(...)     LAYOUT(__VA_ARGS__)
#define LAYOUT_btgrant_3x6(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_btgrant_grid(...) LAYOUT_planck_grid(__VA_ARGS__)
// portable keymaps end

#endif
