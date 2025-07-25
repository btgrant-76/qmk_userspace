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

#include "btgrant.h"
#include "macros.h"
#ifndef TRY_CHORDAL_HOLD
#include "features/achordion.h"
#endif

// TODO would it work to move all the achordion-related functions into an achordion_int file?
/* ACHORDION INTEGRATION BEGIN */
#ifndef TRY_CHORDAL_HOLD
__attribute__ ((weak))
bool achordion_chord_keymap(uint16_t tap_hold_keycode,
                            keyrecord_t* tap_hold_record,
                            uint16_t other_keycode,
                            keyrecord_t* other_record) {
  return false;
};


bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  if (achordion_chord_keymap(tap_hold_keycode, tap_hold_record, other_keycode, other_record)) {
    return true;
  }

  switch (tap_hold_keycode) {
    case D_GUI:
      switch (other_keycode) {
        case TAB_FUN:
        case TAB_MSE:
        case KC_W:
        case KC_R:
        case S_ALT:
          return true;
      }

    /* 2025-06-20:  commented out because I don't think these are capable of doing anything.
     *   it looks like the intent was to make same-hand layer triggering work so I could move keys like Esc & Enter to layers
    // TODO do these help? Test them out.
    case BS_NUM:
      switch (other_keycode) {
        case Z_HYPR:
        case KC_ESC:
          return true;
      }
    case SPC_NAV:
      switch (other_keycode) {
        case SLS_HYPR:
        case KC_ENT:
          return true;
     }
     */
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
};

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_LGUI:
    case MOD_LALT:
      return true;

    default:
      return false;
  }
};

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    // left thumb keys
    case TAB_FUN:
    case TAB_MSE:
    case BS_NUM:
    case ESC_SYM:  // helpful for cocot46plus where this key also triggers scroll mode
    case ESC_MSE:
    case ESC_FUN:
    // right thumb keys
    case ENT_MSE:
    case ENT_SYM:
    case SPC_NAV:
    case DEL_MED:
    case DEL_MSE:
    case LPRN_MSE:
      return 0;  // Bypass Achordion for these keys.

    case F_SFT: // this one specifically allows me to use shift with combos for `'` and Enter. See https://getreuer.info/posts/keyboards/achordion/index.html#compatibility for notes about timing re: Combos and what Achordion can effect.
    case D_GUI:
      return 200;
  }

  return 1000;
};
#endif
/* ACHORDION INTEGRATION END */

/* MATRIX AND KEYCODE INTERCEPTS BEGIN */
__attribute__ ((weak))
void matrix_scan_keymap(void) {
  return;
};

void matrix_scan_user(void) {
  matrix_scan_keymap();
};

#ifndef TRY_CHORDAL_HOLD
void housekeeping_task_user(void) {
  achordion_task();
};
#endif

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event  .pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif


#ifndef TRY_CHORDAL_HOLD
  if (!process_achordion(keycode, record)) {
      return false;
  }
#endif
  // else

  switch (keycode) {
#ifdef CAPS_WORD_ENABLE
    case CAPWD_TG:
        if (record->event.pressed) {
            caps_word_toggle();
        }
        return false;
#endif // CAPS_WORD_ENABLE
    case SCRN2CLP:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_4);

            unregister_code(KC_LGUI);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_4);
        }
        return false;
    case SCRN2FL:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_4);

            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_4);
        }
        return false;
    case QUO_INST:
        if (record->event.pressed) {
            dquote_pair_cursor_insertion();
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
  return process_record_keymap(keycode, record);
};
/* KEYBOARD AND KEYCODE INTERCEPTS END */

/* KEYBOARD INITIALIZATION BEGIN */
__attribute__ ((weak))
void keyboard_post_init_keymap(void) {
  return;
};

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
    #ifdef CONSOLE_ENABLE
    debug_enable=true;
//    debug_matrix=true;
//    debug_keyboard=true;
//    debug_mouse=true;
    #endif
};
/* KEYBOARD INITIALIZATION END */


#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F_SFT:
        case J_SFT:
            #ifdef DYNAMIC_TAPPING_TERM_ENABLE
            return g_tapping_term - TAPPING_TERM_DECREASE_SHIFT;
            #else
            return TAPPING_TERM - TAPPING_TERM_DECREASE_SHIFT;
            #endif
        case SPC_NAV:
            #ifdef DYNAMIC_TAPPING_TERM_ENABLE
            return g_tapping_term + 20;
            #else
            return TAPPING_TERM + 20;
            #endif
        default:
            #ifdef DYNAMIC_TAPPING_TERM_ENABLE
            return g_tapping_term;
            #else
            return TAPPING_TERM;
            #endif
    }
}
#endif

#ifdef LEADER_ENABLE
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_N) ) {
        new_browser_window_you_jerk();
    // vim
    } else if (leader_sequence_one_key(KC_W) ) {
        vim_write();
    } else if (leader_sequence_two_keys(KC_W, KC_Q)) {
        vim_write_and_quit();
    // parens
    } else if (leader_sequence_two_keys(KC_P, KC_I)) {
        parens_insert();
    } else if (leader_sequence_two_keys(KC_P, KC_A)) {
        parens();
    } else if (leader_sequence_three_keys(KC_P, KC_S, KC_A)) {
        parens_semi();
    } else if (leader_sequence_three_keys(KC_P, KC_S, KC_I)) {
        parens_semi_insert();
    // braces
    } else if (leader_sequence_two_keys(KC_B, KC_I)) {
        braces_insert();
    } else if (leader_sequence_two_keys(KC_B, KC_A)) {
        braces();
    } else if (leader_sequence_three_keys(KC_B, KC_S, KC_A)) {
        braces_semi();
    } else if (leader_sequence_three_keys(KC_B, KC_S, KC_I)) {
        braces_semi_insert();
    // curly braces
    } else if (leader_sequence_two_keys(KC_C, KC_I)) {
        curly_braces_insert();
    } else if (leader_sequence_two_keys(KC_C, KC_A)) {
        curly_braces();
    } else if (leader_sequence_three_keys(KC_C, KC_S, KC_A)) {
        curly_braces_semi();
    } else if (leader_sequence_three_keys(KC_C, KC_S, KC_I)) {
        curly_braces_semi_insert();
    } else if (leader_sequence_two_keys(KC_G, KC_I)) {
    // back-tick/grave
        grave_pair_cursor_insertion();
    } else if (leader_sequence_two_keys(KC_C, KC_F)) {
        code_fence();
    // quotes
    } else if (leader_sequence_two_keys(KC_Q, KC_I)) {
        quote_pair_cursor_insertion();
    } else if (leader_sequence_three_keys(KC_Q, KC_Q, KC_I)) {
        dquote_pair_cursor_insertion();
    // HTML tags
    } else if (leader_sequence_two_keys(KC_T, KC_O)) {
        tag_open_insert();
    } else if (leader_sequence_two_keys(KC_T, KC_C)) {
        tag_close_insert();
    } else if (leader_sequence_two_keys(KC_T, KC_V)) {
        tag_void_insert();
    } else if (leader_sequence_three_keys(KC_L, KC_O, KC_G)) {
        js_console_log();
    // others...
    } else if (leader_sequence_two_keys(KC_A, KC_F)) {
         SEND_STRING("=> {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
    } else if (leader_sequence_two_keys(KC_C, KC_L)) {
        tap_code(KC_CAPS);
    }
};
#endif
