/*
Copyright 2025 Brian Grant <@btgrant-76>

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
  _NRM,
  _SYM,
  _NUM,
  _NAV,
  _FUN,
  _MSE,
  _ADD
};

#define _MED _SYM

enum custom_keycodes {
  SCRN2CLP = SAFE_RANGE, // macOS take screenshot to the clip board
  SCRN2FL,               // macOS take screenshot to a file
  QUO_INST,
  UP_DIR,//:../
  LOG_OUT,
  CAPWD_TG,
  NEW_SAFE_RANGE
};

// Tap Dance declarations
enum {
  TD_F1,
  TD_F2,
  TD_F6,
  TD_F9,
  TD_F12,
  TD_DOT,
  TD_ZERO,
  TD_TWO,
  TD_THREE,
  TD_QUOT,
  TD_DASH,
  TD_GRV
};

/* Aliases */
#define HOLD XXXXXXX //:(hold)

/** Layer Keys **/
#define TAB_FUN LT(_FUN, KC_TAB) //:Tab/FUN
#define TAB_MSE LT(_MSE, KC_TAB) //:Tab/MSE
#define BS_NUM LT(_NUM, KC_BSPC) //:BS/NUM
#define ESC_SYM LT(_SYM, KC_ESC) //:Esc/SYM
#define ESC_MSE LT(_MSE, KC_ESC) //:Esc/MSE
#define ESC_FUN LT(_FUN, KC_ESC) //:Esc/FUN
#define ENT_MSE LT(_MSE, KC_ENT) //:Ent/MSE
#define ENT_SYM LT(_SYM, KC_ENT) //:Ent/SYM
#define SPC_NAV LT(_NAV, KC_SPC) //:Spc/NAV
#define DEL_MED LT(_MED, KC_DEL) //:Del/MED
#define DEL_MSE LT(_MSE, KC_DEL) //:Del/MSE

#define LPRN_MSE LT(_MSE, KC_LPRN) // TODO I don't think I'm actually using this in practice

/** Mod Tap Aliases **/
/*** Home Row Mods ***/
#define A_CTL LCTL_T(KC_A) //:A/Ctl
#define S_ALT LALT_T(KC_S) //:S/Alt
#define D_GUI LGUI_T(KC_D) //:D/Cmd
#define F_SFT LSFT_T(KC_F) //:F/Sft
#define J_SFT RSFT_T(KC_J) //:J/Sft
#define K_GUI RGUI_T(KC_K) //:K/Cmd
#define L_ALT RALT_T(KC_L) //:L/Alt
#define SCLN_CTL RCTL_T(KC_SCLN) //:;_:/Ctl // QUOTE_ON_BASE
#define QUOT_CTL RCTL_T(KC_QUOT) //:'_"/Ctl // QUOTE_ON_BASE
#define HRM_L KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT //:Ctl||Opt||GUI||Sft
#define HRM_R KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL //:Sft||GUI||Opt||Ctl

/*** Others ***/
#define ENT_SFT RSFT_T(KC_ENT) //:Ent/Sft
#define SLS_HYPR HYPR_T(KC_SLSH) //:/_?/Hypr
#define Z_HYPR HYPR_T(KC_Z) //:Z/Hypr
#define B_MEH MEH_T(KC_B) //:B/Meh
#define N_MEH MEH_T(KC_N) //:N/Meh

/*** Thumb keys ***/
#define DEL_GUI LGUI_T(KC_DEL) //:Del/Cmd
#define SPC_MEH MEH_T(KC_SPC)

/*** Shortcuts ***/
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define REDO LSG(KC_Z)
#define CLIPBOARD_R REDO, PASTE, COPY, CUT, UNDO //:Redo||Paste||Copy||Cut||Undo
#define CLIPBOARD_L UNDO, CUT, COPY, PASTE, REDO //:Undo||Cut||Copy||Paste||Redo

/*** macOS navigation ***/
#define MISS_CTL LCTL(KC_UP)
#define LEFT_SPC LCTL(KC_LEFT)
#define RGHT_SPC LCTL(KC_RIGHT)

/*** Other shortcuts ***/
#define BACK LCMD(KC_LBRC) //:Back
#define FWD LCMD(KC_RBRC) //:Forward
#define TAB_LFT LSG(KC_LBRC) //:Tab_Lft
#define TAB_RGT LSG(KC_RBRC) //:Tab_Rght
#define Z_MUTE HYPR(KC_SPC) //:Zoom_Mute

#ifdef TAP_DANCE_ENABLE
// Tap Dances
#define F1_TD TD(TD_F1) //:F1
#define F2_TD TD(TD_F2) //:F2
#define F6_TD TD(TD_F6) //:F6
#define F9_TD TD(TD_F9) //:F9
#define F12_TD TD(TD_F12) //:F12
#define DOT_TD TD(TD_DOT) //:.
#define ZERO_TD TD(TD_ZERO) //:0
#define TWO_TD TD(TD_TWO) //:2
#define THREE_TD TD(TD_THREE) //:3
#define QUOT_TD TD(TD_QUOT) //:'_"
#define DASH_TD TD(TD_DASH) //:-__
#define GRV_TD TD(TD_GRV) //:`_~
#else
#define F1_TD KC_F1
#define F2_TD KC_F2
#define F6_TD KC_F6
#define F9_TD KC_F9
#define F12_TD KC_F12
#define DOT_TD KC_DOT
#define ZERO_TD KC_0
#define TWO_TD KC_2
#define THREE_TD KC_3
#define QUOT_TD KC_QUOT
#define DASH_TD KC_MINS
#define GRV_TD KC_GRV
#endif // TAP_DANCE_ENABLE

/* portable keymaps */
/** 10u **/
/*** base ***/
// clang-format off
#define ___5BASE_1_L___     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ___5BASE_2_L___     A_CTL,   S_ALT,   D_GUI,   F_SFT,   KC_G
#define ___5BASE_3_L___     Z_HYPR,  KC_X,    KC_C,    KC_V,    B_MEH
#define ___BASE_THUMB_L___                  TAB_FUN, BS_NUM,  ESC_MSE

#define ___5BASE_1_R___      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ___5BASE_2_R___      KC_H,    J_SFT,   K_GUI,   L_ALT,   QUOT_CTL // QUOTE_ON_BASE  SCLN_CTL
#define ___5BASE_3_R___      N_MEH,   KC_M,    KC_COMM, KC_DOT,  SLS_HYPR
#define ___BASE_THUMB_R___ ENT_MSE, SPC_NAV, DEL_MED

/*** number ***/
#define ___5NUM_1_L___      CLIPBOARD_L
#define ___5NUM_2_L___      KC_LCTL, S_ALT,   KC_LGUI, KC_LSFT, CAPWD_TG
#define ___5NUM_3_L___      KC_ESC,  XXXXXXX, QK_LEAD, KC_SPC,  KC_BSPC
#define ___NUM_THUMB_L___                   KC_DEL,  HOLD,    KC_BSPC

#define ___5NUM_1_R___      KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC
#define ___5NUM_2_R___      KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN // QUOTE_ON_BASE  KC_QUOT
#define ___5NUM_3_R___      KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV
#define ___NUM_THUMB_R___   KC_MINS, KC_0,    KC_DOT

/*** symbol ***/
#define ___5SYM_1_L___      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
#define ___5SYM_2_L___      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RGB_SPI
#define ___5SYM_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___SYM_THUMB_L___                   KC_MUTE, KC_MPLY, KC_MSTP

#define ___5SYM_1_R___      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR
#define ___5SYM_2_R___      KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT
#define ___5SYM_3_R___      KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD
#define ___SYM_THUMB_R___ KC_UNDS, LPRN_MSE, HOLD

/*** navigation ***/
#define ___5NAV_1_L___      TAB_LFT, BACK,    FWD,     TAB_RGT, UP_DIR
#define ___5NAV_2_L___      HRM_L,                              XXXXXXX
#define ___5NAV_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___NAV_THUMB_L___                   DEL_GUI, KC_BSPC, KC_ENT

#define ___5NAV_1_R___      CLIPBOARD_R
#define ___5NAV_2_R___      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_SCLN  // QUOTE_ON_BASE  KC_QUOT
#define ___5NAV_3_R___      KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_ENT
#define ___NAV_THUMB_R___ XXXXXXX, HOLD,    XXXXXXX

/*** function ***/
#define ___5FUN_1_L___      LOG_OUT, XXXXXXX, SCRN2CLP, SCRN2FL, XXXXXXX
#define ___5FUN_2_L___      HRM_L,                               KC_BRIU
#define ___5FUN_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_BRID
#define ___FUN_THUMB_L___                     HOLD,    MO(_MSE), XXXXXXX

#define ___5FUN_1_R___      XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12
#define ___5FUN_2_R___      XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11
#define ___5FUN_3_R___      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10
#define ___FUN_THUMB_R___   XXXXXXX, MO(_ADD), XXXXXXX

/*** mouse ***/
#define ___5MSE_1_L___      CLIPBOARD_L
#define ___5MSE_2_L___      KC_BTN5, KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX
#define ___5MSE_3_L___      KC_ESC,  HRM_L
#define ___MSE_THUMB_L___                     KC_ESC,  HOLD,    HOLD

#define ___5MSE_1_R___      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX
#define ___5MSE_2_R___      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX
// wheel up/down are swapped intentionally so the actual directions are synced
// relative to "natural scrolling"
#define ___5MSE_3_R___      KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX
#define ___MSE_THUMB_R___   HOLD,    HOLD,    XXXXXXX

/*** additional features ***/
#define ___5ADD_1_L___      RGB_SPI, RGB_MOD, RGB_RMOD, RGB_SPD,  RGB_TOG
#define ___5ADD_2_L___      RGB_SAI, RGB_HUI, RGB_HUD, RGB_SAD,  XXXXXXX
#define ___5ADD_3_L___      XXXXXXX, RGB_VAI, RGB_VAD, XXXXXXX,  QK_BOOT
#define ___ADD_THUMB_L___                     XXXXXXX, XXXXXXX,  XXXXXXX

#define ___5ADD_1_R___      CLIPBOARD_R
#define ___5ADD_2_R___      DT_PRNT, DT_UP,   DT_DOWN, XXXXXXX, DF(_NRM)
#define ___5ADD_3_R___      AS_RPT,  AS_UP,   AS_DOWN, XXXXXXX, DF(_BASE)
#define ___ADD_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX

/** 12u **/
/*** normie base ***/
#define ___NRM_1_L___       KC_TAB,  ___5BASE_1_L___
#define ___NRM_2_L___       KC_ESC,  KC_A,    KC_S,   KC_D,   KC_F,   KC_G // no tap-holds
#define ___NRM_3_L___       KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B // no tap-holds
#define ___NRM_THUMB_L___   KC_SPC,  MO(_NUM),MO(_SYM)

#define ___NRM_1_R___       ___5BASE_1_R___,      KC_BSPC
#define ___NRM_2_R___       KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT // no tap-holds
#define ___NRM_3_R___       KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_ENT  // no tap-holds
#define ___NRM_THUMB_R___                        MO(_MSE),SPC_NAV, MO(_NAV)

/*** base ***/
#define ___BASE_1_L___      KC_TAB,  ___5BASE_1_L___
#define ___BASE_2_L___      KC_ESC,  ___5BASE_2_L___
#define ___BASE_3_L___      KC_LSFT, ___5BASE_3_L___

#define ___BASE_1_R___      ___5BASE_1_R___, KC_BSPC
#define ___BASE_2_R___      ___5BASE_2_R___, KC_QUOT
#define ___BASE_3_R___      ___5BASE_3_R___, ENT_SFT
/*** number ***/
#define ___NUM_1_L___       XXXXXXX, ___5NUM_1_L___
#define ___NUM_2_L___       XXXXXXX, ___5NUM_2_L___
#define ___NUM_3_L___       _______, ___5NUM_3_L___

#define ___NUM_1_R___       ___5NUM_1_R___, KC_BSPC
#define ___NUM_2_R___       ___5NUM_2_R___, KC_PENT
#define ___NUM_3_R___       ___5NUM_3_R___, _______

/*** symbol ***/
#define ___SYM_1_L___       XXXXXXX, ___5SYM_1_L___
#define ___SYM_2_L___       KC_CAPS, ___5SYM_2_L___
#define ___SYM_3_L___       _______, ___5SYM_3_L___

#define ___SYM_1_R___       ___5SYM_1_R___, KC_DEL
#define ___SYM_2_R___       ___5SYM_2_R___, KC_TILD
#define ___SYM_3_R___       ___5SYM_3_R___, XXXXXXX

/*** navigation ***/
#define ___NAV_1_L___       XXXXXXX, ___5NAV_1_L___
#define ___NAV_2_L___       XXXXXXX, ___5NAV_2_L___
#define ___NAV_3_L___       _______, ___5NAV_3_L___

#define ___NAV_1_R___       ___5NAV_1_R___, XXXXXXX
#define ___NAV_2_R___       ___5NAV_2_R___, XXXXXXX
#define ___NAV_3_R___       ___5NAV_3_R___, _______

/*** function ***/
#define ___FUN_1_L___       XXXXXXX, ___5FUN_1_L___
#define ___FUN_2_L___       LOG_OUT, ___5FUN_2_L___
#define ___FUN_3_L___       _______, ___5FUN_3_L___

#define ___FUN_1_R___       ___5FUN_1_R___, XXXXXXX
#define ___FUN_2_R___       ___5FUN_2_R___, XXXXXXX
#define ___FUN_3_R___       ___5FUN_3_R___, XXXXXXX

/*** mouse ***/
#define ___MSE_1_L___       XXXXXXX, ___5MSE_1_L___
#define ___MSE_2_L___       XXXXXXX, ___5MSE_2_L___
#define ___MSE_3_L___       XXXXXXX, ___5MSE_3_L___

#define ___MSE_1_R___       ___5MSE_1_R___, XXXXXXX
#define ___MSE_2_R___       ___5MSE_2_R___, XXXXXXX
#define ___MSE_3_R___       ___5MSE_3_R___, XXXXXXX

/** alternate thumbs **/
/*** four thumbs ***/
#define ___BASE_4_THUMB_L___ TAB_MSE, BS_NUM
#define ___BASE_4_THUMB_R___ SPC_NAV, DEL_MSE

#define ___NUM_4_THUMB_L___ KC_BSPC,  HOLD
#define ___NUM_4_THUMB_R___ KC_MINS,  KC_0

#define ___SYM_4_THUMB_L___ KC_MUTE,  KC_MPLY
#define ___SYM_4_THUMB_R___ LPRN_MSE, XXXXXXX

#define ___NAV_4_THUMB_L___ XXXXXXX, XXXXXXX
#define ___NAV_4_THUMB_R___ HOLD,    XXXXXXX

#define ___FUN_4_THUMB_L___ XXXXXXX, MO(_MSE)
#define ___FUN_4_THUMB_R___ MO(_ADD), XXXXXXX

#define ___MSE_4_THUMB_L___ HOLD,    XXXXXXX
#define ___MSE_4_THUMB_R___ XXXXXXX, HOLD

#define ___ADD_4_THUMB_L___ XXXXXXX, XXXXXXX
#define ___ADD_4_THUMB_R___ HOLD,    XXXXXXX

/*** six thumbs shifted ***/
#define ___BASE_ALT_THUMB_L___  ESC_FUN, ___BASE_4_THUMB_L___
#define ___BASE_ALT_THUMB_R___  ___BASE_4_THUMB_R___, ENT_SYM

#define ___NUM_ALT_THUMB_L___  XXXXXXX, ___NUM_4_THUMB_L___
#define ___NUM_ALT_THUMB_R___  ___NUM_4_THUMB_R___, DOT_TD

#define ___SYM_ALT_THUMB_L___  XXXXXXX, ___SYM_4_THUMB_L___
#define ___SYM_ALT_THUMB_R___  ___SYM_4_THUMB_R___, KC_RPRN

#define ___NAV_ALT_THUMB_L___  XXXXXXX, ___NAV_4_THUMB_L___
#define ___NAV_ALT_THUMB_R___  ___NAV_4_THUMB_R___, XXXXXXX

#define ___FUN_ALT_THUMB_L___  HOLD,    ___FUN_4_THUMB_L___
#define ___FUN_ALT_THUMB_R___  ___FUN_4_THUMB_R___, XXXXXXX

#define ___MSE_ALT_THUMB_L___  XXXXXXX, ___MSE_4_THUMB_L___
#define ___MSE_ALT_THUMB_R___  ___MSE_4_THUMB_R___, XXXXXXX

#define ___ADD_ALT_THUMB_L___  XXXXXXX, ___ADD_4_THUMB_L___
#define ___ADD_ALT_THUMB_R___  ___ADD_4_THUMB_R___, XXXXXXX

// clang-format on

/** layout macros **/
#define LAYOUT_btgrant(...)              LAYOUT(__VA_ARGS__)
#define LAYOUT_btgrant_all(...)          LAYOUT_all(__VA_ARGS__)
#define LAYOUT_btgrant_3x5(...)          LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_btgrant_3x6(...)          LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_btgrant_4x12(...)         LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_btgrant_grid(...)         LAYOUT_grid(__VA_ARGS__)
#define LAYOUT_btgrant_planck_grid(...)  LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_btgrant_vault_katana(...) LAYOUT_split_6bars(__VA_ARGS__)
/* portable keymaps end */

#endif // USERSPACE
