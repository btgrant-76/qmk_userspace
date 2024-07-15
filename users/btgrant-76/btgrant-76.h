/*
Copyright 2024 Brian Grant <@btgrant-76>

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
  UP_DIR,
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
/** Layer Keys **/
#define TAB_FUN LT(_FUN, KC_TAB)
#define BS_NUM LT(_NUM, KC_BSPC)
#define ESC_SYM LT(_SYM, KC_ESC)
#define ESC_MSE LT(_MSE, KC_ESC)
#define ENT_MOUS LT(_MSE, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)
#define DEL_MED LT(_MED, KC_DEL)

#define LPRN_MSE LT(_MSE, KC_LPRN)

/** Mod Tap Aliases **/
/*** Home Row Mods ***/
#define A_CTL LCTL_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_GUI LGUI_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define L_ALT RALT_T(KC_L)
#define SCLN_CTL RCTL_T(KC_SCLN)
#define ___HRM_L___ KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT
#define ___HRM_R___ KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL

/*** Others ***/
#define ENT_SFT RSFT_T(KC_ENT)
#define SLS_HYPR HYPR_T(KC_SLSH)
#define Z_HYPR HYPR_T(KC_Z)
#define B_MEH MEH_T(KC_B)
#define N_MEH MEH_T(KC_N)

/*** Thumb keys ***/
#define DEL_GUI LGUI_T(KC_DEL)
#define SPC_MEH MEH_T(KC_SPC)

/*** Shortcuts ***/
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define UNDO LGUI(KC_Z)
#define REDO LSG(KC_Z)
#define ___CLIPBOARD_R___ REDO, PASTE, COPY, CUT, UNDO
#define ___CLIPBOARD_L___ UNDO, CUT, COPY, PASTE, REDO

/*** macOS navigation ***/
#define MISS_CTL LCTL(KC_UP)
#define LEFT_SPC LCTL(KC_LEFT)
#define RGHT_SPC LCTL(KC_RIGHT)

/*** Shifted Keys ***/
#define COLON LSFT(KC_SCLN)

/*** Other shortcuts ***/
#define BACK LCMD(KC_LBRC)
#define FWD LCMD(KC_RBRC)
#define TAB_LFT LSG(KC_LBRC)
#define TAB_RGT LSG(KC_RBRC)
#define Z_MUTE HYPR(KC_SPC)

#ifdef TAP_DANCE_ENABLE
// Tap Dances
#define F1_TD TD(TD_F1)
#define F2_TD TD(TD_F2)
#define F6_TD TD(TD_F6)
#define F9_TD TD(TD_F9)
#define F12_TD TD(TD_F12)
#define DOT_TD TD(TD_DOT)
#define ZERO_TD TD(TD_ZERO)
#define TWO_TD TD(TD_TWO)
#define THREE_TD TD(TD_THREE)
#define QUOT_TD TD(TD_QUOT)
#define DASH_TD TD(TD_DASH)
#define GRV_TD TD(TD_GRV)
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
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Q     │  W     │  E     │  R     │  T     │ */
#define ___5BASE_1_L___     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  A/Ctl │  S/Alt │  D/Cmd │  F/Sft │  G     │ */
#define ___5BASE_2_L___     A_CTL,   S_ALT,   D_GUI,   F_SFT,   KC_G
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Z/Hypr │  X     │  C     │  V     │  B/Meh │ */
#define ___5BASE_3_L___     Z_HYPR,   KC_X,    KC_C,    KC_V,   B_MEH
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ Tab/FUN│ BS/NUM │ Esc/MSE│ */
#define ___BASE_THUMB_L___                    TAB_FUN, BS_NUM,  ESC_MSE
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Y     │  U     │  I     │  O     │  P     │ */
#define ___5BASE_1_R___     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  H     │  J/Sft │  K/Cmd │  L/Alt │ ; :/Ctl│ */
#define ___5BASE_2_R___     KC_H,    J_SFT,   K_GUI,   L_ALT,   SCLN_CTL
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  N/Meh │  M     │  , <   │  . >   │/ ?/Hypr│ */
#define ___5BASE_3_R___     N_MEH,   KC_M,    KC_COMM, KC_DOT,  SLS_HYPR
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │Ent/MOUS│ Spc/NAV│ Del/MED│ */
#define ___BASE_THUMB_R___  ENT_MOUS,SPC_NAV, DEL_MED
                        /* ╰────────┴────────┴────────╯ */

/*** number ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___5NUM_1_L___      ___CLIPBOARD_L___
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  S/Alt │  Cmd   │  Shift │Capwd TG│ */
#define ___5NUM_2_L___      KC_LCTL, S_ALT,   KC_LGUI, KC_LSFT, CAPWD_TG
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │   ---  │  ---   │ Leader │ Space  │  BS    │ */
#define ___5NUM_3_L___      XXXXXXX, XXXXXXX, QK_LEAD, KC_SPC,  KC_BSPC
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  Del   │ (hold) │  BS    │ */
#define ___NUM_THUMB_L___                     KC_DEL,  XXXXXXX, KC_BSPC
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  [ {   │  7     │  8     │  9     │  ] }   │ */
#define ___5NUM_1_R___      KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  = +   │  4     │  5     │  6     │  ' "   │ */
#define ___5NUM_2_R___      KC_EQL,  KC_4,    KC_5,    KC_6,    QUOT_TD   // TODO maybe try moving the quote hold to a different key?
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  \ |   │  1     │  2     │  3     │  ` ~   │ */
#define ___5NUM_3_R___      KC_BSLS, KC_1,    TWO_TD,  THREE_TD,GRV_TD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  - _   │  0     │  .     │ */
#define ___NUM_THUMB_R___   KC_MINS, ZERO_TD, DOT_TD
                        /* ╰────────┴────────┴────────╯ */

/*** symbol ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5SYM_1_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Med <==│ Vol Dn │ Vol Up │ Med==> │RGB Spd+│ */
#define ___5SYM_2_L___      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RGB_SPI
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ RGB tog│RGB mod+│RGB hue+│RGB sat+│RGB brt+│ */
#define ___5SYM_3_L___      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  Mute  │Ply/Paus│  Stop  │ */
#define ___SYM_THUMB_L___                     KC_MUTE, KC_MPLY, KC_MSTP
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  {     │  &     │  *     │  )     │  }     │ */
#define ___5SYM_1_R___      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  +     │  $     │  %     │  ^     │  "     │ */
#define ___5SYM_2_R___      KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  |     │  !     │  @     │  #     │  ~     │ */
#define ___5SYM_3_R___      KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  _     │  (     │ (hold) │ */
#define ___SYM_THUMB_R___   KC_UNDS, LPRN_MSE, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** navigation ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Tab Lft│  Back  │ Forward│Tab Rght│  ../   │ */
#define ___5NAV_1_L___      TAB_LFT, BACK,    FWD,     TAB_RGT, UP_DIR
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Alt   │  Cmd   │  Shft  │  ---   │ */
#define ___5NAV_2_L___      ___HRM_L___,                        XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5NAV_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ Del/Cmd│  Bs    │  Ent   │ */
#define ___NAV_THUMB_L___                     DEL_GUI, KC_BSPC, KC_ENT
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │ */
#define ___5NAV_1_R___      ___CLIPBOARD_R___
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Left  │  Down  │  Up    │  Right │  Caps  │ */
#define ___5NAV_2_R___      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_CAPS
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Home  │  PgDn  │  PgUp  │  End   │ Insert │ */
#define ___5NAV_3_R___      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │ (hold) │  ---   │ */
#define ___NAV_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** function ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Log Out│  ---   │Scrn2Clp│ Scrn2Fl│  ---   │ */
#define ___5FUN_1_L___      LOG_OUT, XXXXXXX, SCRN2CLP,SCRN2FL, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Alt   │  Cmd   │  Shft  │ScrnBrt+│ */
#define ___5FUN_2_L___      ___HRM_L___,                        KC_BRIU
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │ScrnBrt-│ */
#define ___5FUN_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ (hold) │  MSE   │  Tab   │ */
#define ___FUN_THUMB_L___                     XXXXXXX, MO(_MSE), XXXXXXX
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  F7    │  F8    │  F9    │  F12   │ */
#define ___5FUN_1_R___      XXXXXXX, KC_F7,   KC_F8,   F9_TD,   F12_TD
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F4    │  F5    │  F6    │  F11   │ */
#define ___5FUN_2_R___      XXXXXXX, KC_F4,   KC_F5,   F6_TD,   KC_F11
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F1    │  F2    │  F3    │  F10   │ */
#define ___5FUN_3_R___      XXXXXXX, F1_TD,   F2_TD,   KC_F3,   KC_F10
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │  ADD   │  ---   │ */
#define ___FUN_THUMB_R___   XXXXXXX, MO(_ADD), XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** mouse ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___5MSE_1_L___      ___CLIPBOARD_L___
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │Button 5│Button 3│Button 1│Button 2│ Wheel D│ */
#define ___5MSE_2_L___      KC_BTN5, KC_BTN3, KC_BTN1, KC_BTN2, KC_WH_D
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Alt   │  Cmd   │  Shft  │ Wheel U│ */
#define ___5MSE_3_L___      ___HRM_L___,                         KC_WH_U
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  ---   │ (hold) │ (hold) │ */
#define ___MSE_THUMB_L___                     XXXXXXX, XXXXXXX, XXXXXXX
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │MseSpd 0│MseSpd 1│MseSpd 2│  ---   │ */
#define ___5MSE_1_R___      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Mouse L│ Mouse D│ Mouse U│ Mouse R│  ---   │ */
#define ___5MSE_2_R___      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Wheel L│ Wheel U│ Wheel D│ Wheel R│  ---   │ */
// wheel up/down are swapped intentionally so the actual directions are synced
// relative to "natural scrolling"
#define ___5MSE_3_R___      KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │ (hold) │ (hold) │  ---   │ */
#define ___MSE_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** additional features ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Bootldr│  ---   │  ---   │DF: BASE│DF: NRM │ */
#define ___5ADD_1_L___      QK_BOOT, XXXXXXX, XXXXXXX, DF(_BASE),DF(_NRM)
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │DynTpRpt│ DynTpDn│ DynTpUp│  ---   │ */
#define ___5ADD_2_L___      XXXXXXX, DT_PRNT, DT_DOWN, DT_UP,   XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │ ASftRpt│ ASft Dn│ ASft Up│  ---   │ */
#define ___5ADD_3_L___      XXXXXXX, AS_RPT,  AS_DOWN, AS_UP,   XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  ---   │  ---   │  ---   │ */
#define ___ADD_THUMB_L___                     XXXXXXX, XXXXXXX, XXXXXXX
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │ */
#define ___5ADD_1_R___      ___CLIPBOARD_R___
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5ADD_2_R___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5ADD_3_R___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │ (hold) │  ---   │ */
#define ___ADD_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/** 12u **/
/*** normie base ***/
                        /* ╭────────┬ */
                        /* │ Tab    │ */
#define ___NRM_1_L___       KC_TAB, ___5BASE_1_L___
                        /* ├────────┼ */
                        /* │ Esc    │ */
#define ___NRM_2_L___       KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G // no tap-holds
                        /* ├────────┼ */
                        /* │ Shift  │ */
#define ___NRM_3_L___      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B // no tap-holds
                        /* ╰────────┴ */
#define ___NRM_THUMB_L___  KC_SPC, MO(_NUM), MO(_SYM)

                                             /* ┬────────╮ */
                                             /* │  Bspc  │ */
#define ___NRM_1_R___      ___5BASE_1_R___,      KC_BSPC
                                             /* ┼────────┤ */
                                             /* │  ' "   │ */
#define ___NRM_2_R___      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT // no tap-holds
                                             /* ┼────────┤ */
                                             /* │ Ent/Sft│ */
#define ___NRM_3_R___      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT // no tap-holds
#define ___NRM_THUMB_R___  MO(_MSE), SPC_NAV, MO(_NAV)

/*** base ***/
                        /* ╭────────┬ */
                        /* │ Tab    │ */
#define ___BASE_1_L___       KC_TAB, ___5BASE_1_L___
                        /* ├────────┼ */
                        /* │ Esc    │ */
#define ___BASE_2_L___       KC_ESC, ___5BASE_2_L___
                        /* ├────────┼ */
                        /* │ Shift  │ */
#define ___BASE_3_L___      KC_LSFT, ___5BASE_3_L___
                        /* ╰────────┴ */

                                             /* ┬────────╮ */
                                             /* │  Bspc  │ */
#define ___BASE_1_R___      ___5BASE_1_R___,      KC_BSPC
                                             /* ┼────────┤ */
                                             /* │  ' "   │ */
#define ___BASE_2_R___      ___5BASE_2_R___,      KC_QUOT
                                             /* ┼────────┤ */
                                             /* │ Ent/Sft│ */
#define ___BASE_3_R___      ___5BASE_3_R___,      ENT_SFT
                                             /* ┴────────╯ */
/*** number ***/
                        /* ╭────────┬ */
                        /* │  ---   │ */
#define ___NUM_1_L___       XXXXXXX, ___5NUM_1_L___
                        /* ├────────┼ */
                        /* │  ---   │ */
#define ___NUM_2_L___       XXXXXXX, ___5NUM_2_L___
                        /* ├────────┼ */
                        /* │        │ */
#define ___NUM_3_L___       _______, ___5NUM_3_L___
                        /* ╰────────┴ */

                                        /* ┬────────╮ */
                                        /* │  Bspc  │ */
#define ___NUM_1_R___       ___5NUM_1_R___, KC_BSPC
                                        /* ┼────────┤ */
                                        /* │  Enter │ */
#define ___NUM_2_R___       ___5NUM_2_R___, KC_PENT
                                        /* ┼────────┤ */
                                        /* │        │ */
#define ___NUM_3_R___       ___5NUM_3_R___, _______
                                        /* ┴────────╯ */

/*** symbol ***/
                        /* ╭────────┬ */
                        /* │  ---   │ */
#define ___SYM_1_L___       XXXXXXX, ___5SYM_1_L___
                        /* ├────────┼ */
                        /* │Caps Loc│ */
#define ___SYM_2_L___       KC_CAPS, ___5SYM_2_L___
                        /* ├────────┼ */
                        /* │        │ */
#define ___SYM_3_L___       _______, ___5SYM_3_L___
                        /* ╰────────┴ */

                                        /* ┬────────╮ */
                                        /* │  Del   │ */
#define ___SYM_1_R___       ___5SYM_1_R___, KC_DEL
                                        /* ┼────────┤ */
                                        /* │  ~     │ */
#define ___SYM_2_R___       ___5SYM_2_R___, KC_TILD
                                        /* ┼────────┤ */
                                        /* │  ---   │ */
#define ___SYM_3_R___       ___5SYM_3_R___, XXXXXXX
                                        /* ┴────────╯ */

/*** navigation ***/
                        /* ╭────────┬ */
                        /* │  ---   │ */
#define ___NAV_1_L___       XXXXXXX, ___5NAV_1_L___
                        /* ├────────┼ */
                        /* │  ---   │ */
#define ___NAV_2_L___       XXXXXXX, ___5NAV_2_L___
                        /* ├────────┼ */
                        /* │        │ */
#define ___NAV_3_L___       _______, ___5NAV_3_L___
                        /* ╰────────┴ */

                                        /* ┬────────╮ */
                                        /* │  ---   │ */
#define ___NAV_1_R___       ___5NAV_1_R___, XXXXXXX
                                        /* ┼────────┤ */
                                        /* │  ---   │ */
#define ___NAV_2_R___       ___5NAV_2_R___, XXXXXXX
                                        /* ┼────────┤ */
                                        /* │        │ */
#define ___NAV_3_R___       ___5NAV_3_R___, _______
                                        /* ┴────────╯ */

/*** function ***/
                        /* ╭────────┬ */
                        /* │  ---   │ */
#define ___FUN_1_L___       XXXXXXX, ___5FUN_1_L___
                        /* ├────────┼ */
                        /* │ Log Out│ */
#define ___FUN_2_L___       LOG_OUT, ___5FUN_2_L___
                        /* ├────────┼ */
                        /* │        │ */
#define ___FUN_3_L___       _______, ___5FUN_3_L___
                        /* ╰────────┴ */

                                        /* ┬────────╮ */
                                        /* │  ---   │ */
#define ___FUN_1_R___       ___5FUN_1_R___, XXXXXXX
                                        /* ┼────────┤ */
                                        /* │  ---   │ */
#define ___FUN_2_R___       ___5FUN_2_R___, XXXXXXX
                                        /* ┼────────┤ */
                                        /* │  ---   │ */
#define ___FUN_3_R___       ___5FUN_3_R___, XXXXXXX
                                        /* ┴────────╯ */

/*** mouse ***/
                        /* ╭────────┬ */
                        /* │  ---   │ */
#define ___MSE_1_L___       XXXXXXX, ___5MSE_1_L___
                        /* ├────────┼ */
                        /* │  ---   │ */
#define ___MSE_2_L___       XXXXXXX, ___5MSE_2_L___
                        /* ├────────┼ */
                        /* │  ---   │ */
#define ___MSE_3_L___       XXXXXXX, ___5MSE_3_L___
                        /* ╰────────┴ */

                                        /* ┬────────╮ */
                                        /* │  ---   │ */
#define ___MSE_1_R___       ___5MSE_1_R___, XXXXXXX
                                        /* ┼────────┤ */
                                        /* │  ---   │ */
#define ___MSE_2_R___       ___5MSE_2_R___, XXXXXXX
                                        /* ┼────────┤ */
                                        /* │  ---   │ */
#define ___MSE_3_R___       ___5MSE_3_R___, XXXXXXX
                                        /* ┴────────╯ */

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
