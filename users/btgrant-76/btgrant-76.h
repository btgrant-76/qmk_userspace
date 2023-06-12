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
    _FUN,
    _MSE
};

#define _MED _SYM

enum custom_keycodes {
    SCRN2CLP = SAFE_RANGE, // macOS take screenshot to the clip board
    SCRN2FL, // macOS take screenshot to a file
    QUO_INST,
    UP_DIR,
    LOG_OUT,
    CAPWD_TG,
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
#define TAB_FUN LT(_FUN, KC_TAB)
#define BS_NUM LT(_NUM, KC_BSPC)
#define ESC_SYM LT(_SYM,  KC_ESC)
#define ENT_MED LT(_MSE, KC_ENT) // TODO rename
#define SPC_NAV LT(_NAV, KC_SPC)
#define DEL_MOUS LT(_MED, KC_DEL) // TODO rename

#define G_NUM LT(_NUM, KC_G)
#define H_SYM LT(_SYM, KC_H)

// Mod Tap Aliases
/// Home Row Mods
#define A_CTL LCTL_T(KC_A)
#define S_ALT LALT_T(KC_S)
#define D_GUI LGUI_T(KC_D)
#define F_SFT LSFT_T(KC_F)
#define J_SFT RSFT_T(KC_J)
#define K_GUI RGUI_T(KC_K)
#define L_ALT RALT_T(KC_L)
#define SCLN_CTL RCTL_T(KC_SCLN)
#define ___HRM_L___        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT
#define ___HRM_R___        KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL

/// Others
#define ENT_SFT RSFT_T(KC_ENT)
#define SLSH_ALL ALL_T(KC_SLSH)
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
#define ___CLIPBOARD_R___ REDO, PASTE, COPY, CUT, UNDO
#define ___CLIPBOARD_L___ UNDO, CUT, COPY, PASTE, REDO

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
#define Z_MUTE HYPR(KC_SPC)

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
/// base
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Q     │  W     │  E     │  R     │  T     │ */
#define ___5BASE_1_L___     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  A/Ctl │  S/Alt │  D/Gui │  F/Sft │  G     │ */
#define ___5BASE_2_L___     A_CTL,   S_ALT,   D_GUI,   F_SFT,   KC_G
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Z/Meh  │  X     │  C     │  V     │  B     │ */
#define ___5BASE_3_L___     Z_MEH,   KC_X,    KC_C,    KC_V,    KC_B
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ Tab/FUN│ BS/NUM │ Esc/SYM│ */
#define ___BASE_THUMB_L___                    TAB_FUN, BS_NUM,  ESC_SYM
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Y     │  U     │  I     │  O     │  P     │ */
#define ___5BASE_1_R___     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  H     │  J/Sft │  K/Gui │  L/Alt │ ; :/Ctl│ */
#define ___5BASE_2_R___     KC_H,    J_SFT,   K_GUI,   L_ALT,   SCLN_CTL
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  N     │  M     │  , <   │  . >   │/ ?/Hypr│ */
#define ___5BASE_3_R___     KC_N,    KC_M,    KC_COMM, KC_DOT,  SLSH_ALL
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │ Ent/SYM│ Spc/NAV│ Del/FUN│ */
#define ___BASE_THUMB_R___  ENT_MED, SPC_NAV, DEL_MOUS
                        /* ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Tab    │  Q     │  W     │  E     │  R     │  T     │ */
#define ___BASE_1_L___       KC_TAB, ___5BASE_1_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Esc    │  A/Ctl │  S/Alt │  D/Gui │  F/Sft │  G     │ */
#define ___BASE_2_L___       KC_ESC, ___5BASE_2_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Shift  │ Z/Meh  │  X     │  C     │  V     │  B     │ */
#define ___BASE_3_L___      KC_LSFT, ___5BASE_3_L___
                        /* ╰────────┴────────┴────────┼────────┼────────┼────────┤ */
                        /*                            │ Tab/FUN│ BS/NUM │ Esc/SYM│ */
                        /*                            ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Y     │  U     │  I     │  O     │  P     │  Bspc  │ */
#define ___BASE_1_R___      ___5BASE_1_R___,                             KC_BSPC
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  H     │  J/Sft │  K/Gui │  L/Alt │ ; :/Ctl│  ' "   │ */
#define ___BASE_2_R___      ___5BASE_2_R___,                             KC_QUOT
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  N     │  M     │  , <   │  . >   │  / ?   │ Ent/Sft│ */
#define ___BASE_3_R___      ___5BASE_3_R___,                             ENT_SFT
                        /* ├────────┼────────┼────────┼────────┴────────┴────────╯ */
                        /* │ Ent/SYM│ Spc/NAV│ Del/FUN│ */
                        /* ╰────────┴────────┴────────╯ */

/// number
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___5NUM_1_L___      ___CLIPBOARD_L___
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Opt   │  Cmd   │  Shift │Capwd TG│ */
#define ___5NUM_2_L___      ___HRM_L___,                        CAPWD_TG
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ leader │  ---   │ leader │  ---   │  ---   │ */
#define ___5NUM_3_L___      QK_LEAD, XXXXXXX, QK_LEAD, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  ---   │  ---   │  ---   │ */
#define ___NUM_THUMB_L___                     XXXXXXX, XXXXXXX, XXXXXXX
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  [ {   │  7     │  8     │  9     │  ] }   │ */
#define ___5NUM_1_R___      KC_LBRC, KC_7,    KC_8,    KC_9,    RBRC_TD
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  = +   │  4     │  5     │  6     │  ' "   │ */
#define ___5NUM_2_R___      KC_EQL,  KC_4,    KC_5,    KC_6,    KC_QUOT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  \ |   │  1     │  2     │  3     │  ` ~   │ */
#define ___5NUM_3_R___      KC_BSLS, KC_1,    KC_2,    KC_3,    GRAV_TD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  - _   │  0     │  .     │ */
#define ___NUM_THUMB_R___   KC_MINS, KC_0,    KC_DOT
                        /* ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___NUM_1_L___       XXXXXXX, ___5NUM_1_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  Ctl   │  Opt   │  Cmd   │  Shft  │Capwd TG│ */
#define ___NUM_2_L___       XXXXXXX, ___5NUM_2_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │        │ Leader │  ---   │ Leader │  ---   │  ---   │ */
#define ___NUM_3_L___       _______, ___5NUM_3_L___
                        /* ╰────────┴────────┴────────┼────────┼────────┼────────┤ */
                        /*                            │  ---   │  ---   │  ---   │ */
                        /*                            ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  [ {   │  7     │  8     │  9     │  ] }   │  Bspc  │ */
#define ___NUM_1_R___       ___5NUM_1_R___,                              KC_BSPC
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  = +   │  4     │  5     │  6     │  ' "   │  Enter │ */
#define ___NUM_2_R___       ___5NUM_2_R___,                              KC_PENT
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  \ |   │  1     │  2     │  3     │  ` ~   │        │ */
#define ___NUM_3_R___       ___5NUM_3_R___,                              _______
                        /* ├────────┼────────┼────────┼────────┴────────┴────────╯ */
                        /* │  - _   │  0     │  .     │ */
                        /* ╰────────┴────────┴────────╯ */
/// symbol
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5SYM_1_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Med <==│ Vol Up │ Vol Dn │ Med==> │RGB Spd+│ */
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
#define ___5SYM_1_R___      KC_LCBR, KC_AMPR, KC_ASTR, LPRN_TD, RCBR_TD
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  +     │  $     │  %     │  ^     │  "     │ */
#define ___5SYM_2_R___      KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  |     │  !     │  @     │  #     │  ~     │ */
#define ___5SYM_3_R___      KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  _     │  (     │  )     │ */
#define ___SYM_THUMB_R___   KC_UNDS, KC_LPRN, RPRN_TD
                        /* ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___SYM_1_L___       XXXXXXX, ___5SYM_1_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │Caps Loc│Track Bk│ Vol Up │ Vol Dn │TrackFwd│RGB Spd+│ */
#define ___SYM_2_L___       KC_CAPS, ___5SYM_2_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │        │ RGB tog│RGB hue+│RGB hue+│RGB sat+│RGB brt+│ */
#define ___SYM_3_L___       _______, ___5SYM_3_L___
                        /* ╰────────┴────────┴────────┼────────┼────────┼────────┤ */
                        /*                            │  Mute  │Ply/Paus│  Stop  │ */
                        /*                            ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  {     │  &     │  *     │  )     │  }     │  Del   │ */
#define ___SYM_1_R___       ___5SYM_1_R___,                              KC_DEL
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  +     │  $     │  %     │  ^     │  "     │  ~     │ */
#define ___SYM_2_R___       ___5SYM_2_R___,                              KC_TILD
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  |     │  !     │  @     │  #     │  ~     │  ---   │ */
#define ___SYM_3_R___       ___5SYM_3_R___,                              XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────┴────────╯ */
                        /* │  _     │  (     │  )     │ */
                        /* ╰────────┴────────┴────────╯ */

/// navigation
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Tab Lft│  Back  │ Forward│Tab Rght│  ../   │ */
#define ___5NAV_1_L___      TAB_LFT, BACK,    FWD,     TAB_RGT, UP_DIR
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Opt   │  Cmd   │  Shft  │  ---   │ */
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
                        /* │  ---   │  ---   │  ---   │ */
#define ___NAV_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │ Tab Lft│  Back  │ Forward│Tab Rght│  ../   │ */
#define ___NAV_1_L___       XXXXXXX, ___5NAV_1_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  Ctl   │  Opt   │  Cmd   │  Shft  │  ---   │ */
#define ___NAV_2_L___       XXXXXXX, ___5NAV_2_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │        │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___NAV_3_L___       _______, ___5NAV_3_L___
                        /* ╰────────┴────────┴────────┼────────┼────────┼────────┤ */
                        /*                            │ Del/Cmd│  Bs    │  Ent   │ */
                        /*                            ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │  ---   │ */
#define ___NAV_1_R___       ___5NAV_1_R___,                              XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Left  │  Down  │  Up    │  Right │  Caps  │  ---   │ */
#define ___NAV_2_R___       ___5NAV_2_R___,                              XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Home  │  PgDn  │  PgUp  │  End   │ Insert │        │ */
#define ___NAV_3_R___       ___5NAV_3_R___,                              _______
                        /* ├────────┼────────┼────────┼────────┴────────┴────────╯ */
                        /* │  ---   │  ---   │  ---   │ */
                        /* ╰────────┴────────┴────────╯ */

/// function
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Bootldr│  ../   │Scrn2Clp│ Scrn2Fl│  ---   │ */
#define ___5FUN_1_L___      QK_BOOT, UP_DIR,  SCRN2CLP,SCRN2FL, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Log Out│DynTpRpt│ DynTpDn│ DynTpUp│  ---   │ */
#define ___5FUN_2_L___      LOG_OUT, DT_PRNT, DT_DOWN, DT_UP,   XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │ ASftRpt│ ASft Dn│ ASft Up│  ---   │ */
#define ___5FUN_3_L___      XXXXXXX, AS_RPT,  AS_DOWN, AS_UP,   XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  ---   │  Space │  Tab   │ */
#define ___FUN_THUMB_L___                     XXXXXXX, KC_SPC,  KC_TAB
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
                        /* │  ---   │  ---   │  ---   │ */
#define ___FUN_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │ Bootldr│  ../   │Scrn2Clp│ Scrn2Fl│  ---   │ */
#define ___FUN_1_L___       XXXXXXX, ___5FUN_1_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Log Out│ Log Out│DynTpRpt│ DynTpDn│ DynTpUp│  ---   │ */
#define ___FUN_2_L___       LOG_OUT, ___5FUN_2_L___
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │        │  ---   │ ASftRpt│ ASft Dn│ ASft Up│  ---   │ */
#define ___FUN_3_L___       _______, ___5FUN_3_L___
                        /* ╰────────┴────────┴────────┼────────┼────────┼────────┤ */
                        /*                            │  ---   │  Space │  Tab   │ */
                        /*                            ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  F7    │  F8    │  F9    │  F12   │  ---   │ */
#define ___FUN_1_R___       ___5FUN_1_R___,                              XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F4    │  F5    │  F6    │  F11   │  ---   │ */
#define ___FUN_2_R___       ___5FUN_2_R___,                              XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F1    │  F2    │  F3    │  F10   │  ---   │ */
#define ___FUN_3_R___       ___5FUN_3_R___,                              XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────┴────────╯ */
                        /* │  ---   │  ---   │  ---   │ */
                        /* ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___5MSE_1_L___      ___CLIPBOARD_L___
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Mouse L│ Mouse U│ Mouse D│ Mouse U│  ---   │ */
#define ___5MSE_2_L___      KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Wheel L│ Wheel D│ Wheel U│ Wheel R│  ---   │ */
#define ___5MSE_3_L___      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │Button 3│Button 1│Button 2│ */
#define ___MSE_THUMB_L___                     KC_BTN3, KC_BTN1, KC_BTN2
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │MseSpd 0│MseSpd 1│MseSpd 2│  ---   │ */
#define ___5MSE_1_R___      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  Shift │  Cmd   │  Opt   │  Ctrl  │ */
#define ___5MSE_2_R___      XXXXXXX, ___HRM_R___
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5MSE_3_R___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │  ---   │  ---   │ */
#define ___MSE_THUMB_R___   XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

#define ___MSE_1_L___ XXXXXXX, ___5MSE_1_L___
#define ___MSE_2_L___ XXXXXXX, ___5MSE_2_L___
#define ___MSE_3_L___ XXXXXXX, ___5MSE_3_L___

#define ___MSE_1_R___ ___5MSE_1_R___, XXXXXXX
#define ___MSE_2_R___ ___5MSE_2_R___, XXXXXXX
#define ___MSE_3_R___ ___5MSE_3_R___, XXXXXXX

/// layout macros
#define LAYOUT_btgrant(...)      LAYOUT(__VA_ARGS__)
#define LAYOUT_btgrant_3x6(...)  LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_btgrant_grid(...) LAYOUT_planck_grid(__VA_ARGS__)
// portable keymaps end

#endif
