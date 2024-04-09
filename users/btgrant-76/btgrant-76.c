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

#include "btgrant-76.h"
#include "features/achordion.h"


// Tap Dance & macro functions
void generic_insert(char *text) {
    send_string(text);
    tap_code(KC_LEFT);
};

void braces_insert(void) {
    generic_insert("[]");
};

void braces(void) {
    SEND_STRING("[]");
};

void braces_semi(void) {
    SEND_STRING("[];");
};

void braces_semi_insert(void) {
    SEND_STRING("[];");
    tap_code(KC_LEFT);
    tap_code(KC_LEFT);
};

void curly_braces_insert(void) {
    generic_insert("{}");
};

void curly_braces(void) {
    SEND_STRING("{}");
};

void curly_braces_semi(void) {
    SEND_STRING("{};");
};

void curly_braces_semi_insert(void) {
    SEND_STRING("{};");
    tap_code(KC_LEFT);
    tap_code(KC_LEFT);
};

void parens_insert(void) {
    generic_insert("()");
};

void parens(void) {
    SEND_STRING("()");
};

void parens_semi(void) {
    SEND_STRING("();");
};

void parens_semi_insert(void) {
    SEND_STRING("();");
    tap_code(KC_LEFT);
    tap_code(KC_LEFT);
};

void grave_pair_cursor_insertion(void) {
    generic_insert("``");
};

void quote_pair_cursor_insertion(void) {
    generic_insert("''");
};

void dquote_pair_cursor_insertion(void) {
    generic_insert("\"\"");
};

void macos_log_out(void) {
    register_code(KC_LGUI);
    register_code(KC_LCTL);
    tap_code(KC_Q);
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
};

void code_fence(void) {
    SEND_STRING("```" SS_TAP(X_ENT) SS_TAP(X_ENT) "```" SS_TAP(X_UP));
};

void tag_open_insert(void) {
    generic_insert("<>");
}

void tag_close_insert(void) {
    generic_insert("</>");
}

void tag_void_insert(void) {
    generic_insert("< />");
    tap_code(KC_LEFT);
    tap_code(KC_LEFT);
}

#ifdef TAP_DANCE_ENABLE
void period_or_comma_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        SEND_STRING(",");
    } else {
        int i;
        for (i = 0; i < state->count; i++) {
            SEND_STRING(".");
        }
    }
};

void zero_or_space_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        SEND_STRING(" ");
    } else {
        int i;
        for (i = 0; i < state->count; i++) {
            SEND_STRING("0");
        }
    }
};

void two_or_comma_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        SEND_STRING(",");
    } else {
        int i;
        for (i = 0; i < state->count; i++) {
            SEND_STRING("2");
        }
    }
}

void three_or_period_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        SEND_STRING(".");
    } else {
        int i;
        for (i = 0; i < state->count; i++) {
            SEND_STRING("3");
        }
    }
}

void quot_or_colon_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        SEND_STRING(":");
    } else {
        int i;
        for (i = 0; i < state->count; i++) {
            SEND_STRING("'");
        }
    }
};

// FIXME this breaks caps words; use https://docs.qmk.fm/#/feature_caps_word?id=configure-which-keys-are-word-breaking to detect the tap dance code
//   the other, numeric TD additions will break it too
void dashes_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        // n-dash
        register_code(KC_LALT);
        tap_code(KC_MINS);
        unregister_code(KC_LALT);
    } else if (state->count == 2) {
        // m-dash
        register_code(KC_LALT);
        register_code(KC_LSFT);
        tap_code(KC_MINS);
        unregister_code(KC_LALT);
        unregister_code(KC_LSFT);
    } else {
        SEND_STRING("-");
    }
};

void grav_or_slash_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        SEND_STRING("/");
    } else if (state->count == 3) {
        SEND_STRING("```");
    } else if (state->count == 2) {
        SEND_STRING("``");
    } else {
        SEND_STRING("`");
    }
};

void braces_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        #ifdef AUTO_SHIFT_ENABLE
            SEND_STRING("}");
        #else
            SEND_STRING("]");
        #endif
    } else if (state->count == 2) {
        braces_insert();
    } else {
        SEND_STRING("]");
    }
};

void curly_brace_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        curly_braces_insert();
    } else {
        SEND_STRING("}");
    }
};

void parens_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        parens_insert();
    } else {
        SEND_STRING(")");
    }
};

void l_paren_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        parens_insert();
    } else {
        SEND_STRING("(");
    }
};

void grave_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        #ifdef AUTO_SHIFT_ENABLE
            SEND_STRING("~");
        #else
            SEND_STRING("`");
        #endif
    } else if (state->count == 2) {
        grave_pair_cursor_insertion();
    } else if (state->count == 4) {
        code_fence();
    } else {
        SEND_STRING("`");
    }
};

void f1_tap_dance(tap_dance_state_t *state, void *user_data) {
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
};

void f2_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F2);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_F2);
        unregister_code(KC_LGUI);
    }
};

void f6_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F6);
    } else if (state->count == 2) {
        register_code(KC_LCTL);
        tap_code(KC_T);
        unregister_code(KC_LCTL);
    }
};

void f9_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F9);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_9);
        unregister_code(KC_LGUI);
    }
};

void f12_tap_dance(tap_dance_state_t *state, void *user_data) {
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
};

// Tap Dance definition
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_F1] = ACTION_TAP_DANCE_FN(f1_tap_dance),
    [TD_F2] = ACTION_TAP_DANCE_FN(f2_tap_dance),
    [TD_F6] = ACTION_TAP_DANCE_FN(f6_tap_dance),
    [TD_F9] = ACTION_TAP_DANCE_FN(f9_tap_dance),
    [TD_F12] = ACTION_TAP_DANCE_FN(f12_tap_dance),
    [TD_DOT] = ACTION_TAP_DANCE_FN(period_or_comma_tap_dance),
    [TD_ZERO] = ACTION_TAP_DANCE_FN(zero_or_space_tap_dance),
    [TD_TWO] = ACTION_TAP_DANCE_FN(two_or_comma_tap_dance),
    [TD_THREE] = ACTION_TAP_DANCE_FN(three_or_period_tap_dance),
    [TD_QUOT] = ACTION_TAP_DANCE_FN(quot_or_colon_tap_dance),
    [TD_DASH] = ACTION_TAP_DANCE_FN(dashes_tap_dance),
    [TD_GRV] = ACTION_TAP_DANCE_FN(grav_or_slash_tap_dance),
};
#endif // TAP_DANCE_ENABLE

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

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
        case KC_W:
        case KC_R:
        case S_ALT:
          return true;
      }
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
    case BS_NUM:
    case ESC_SYM:  // helpful for cocot46plus where this key also triggers scroll mode
    case ESC_MSE:
    // right thumb keys
    case ENT_MOUS:
    case SPC_NAV:
    case DEL_MED:
    case LPRN_MSE:
      return 0;  // Bypass Achordion for these keys.

    case F_SFT: // this one specifically allows me to use shift with combos for `'` and Enter. See https://getreuer.info/posts/keyboards/achordion/index.html#compatibility for notes about timing re: Combos and what Achordion can effect.
    case D_GUI:
      return 200;
  }

  return 1000;
};

__attribute__ ((weak))
void matrix_scan_keymap(void) {
  return;
};

void matrix_scan_user(void) {
  achordion_task();
  matrix_scan_keymap();
};

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event  .pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

  if (!process_achordion(keycode, record)) { return false; }

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

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F_SFT:
        case J_SFT:
            return g_tapping_term - TAPPING_TERM_DECREASE_SHIFT;
        case SPC_NAV:
            return g_tapping_term + 20;
        default:
            return g_tapping_term;
    }
}
#endif

#ifdef LEADER_ENABLE
void leader_end_user(void) {
    // parens
    if (leader_sequence_two_keys(KC_P, KC_I)) {
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
    }
};
#endif
