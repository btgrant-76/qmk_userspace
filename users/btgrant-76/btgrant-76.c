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

#include "btgrant-76.h"


// Tap Dance & macro functions
void generic_insert(char *text) {
    send_string(text);
    tap_code(KC_LEFT);
}

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
}

void quote_pair_cursor_insertion(void) {
    generic_insert("''");
}

void dquote_pair_cursor_insertion(void) {
    generic_insert("\"\"");
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

#ifdef TAP_DANCE_ENABLE
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
}

void f2_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F2);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_F2);
        unregister_code(KC_LGUI);
    }
}

void f6_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F6);
    } else if (state->count == 2) {
        register_code(KC_LCTL);
        tap_code(KC_T);
        unregister_code(KC_LCTL);
    }
}

void f9_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F9);
    } else if (state->count == 2) {
        register_code(KC_LGUI);
        tap_code(KC_9);
        unregister_code(KC_LGUI);
    }
}

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
}
#endif // TAP_DANCE_ENABLE
// END:  Tap Dance & macro functions

#ifdef TAP_DANCE_ENABLE
// Tap Dance definition
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_F1] = ACTION_TAP_DANCE_FN(f1_tap_dance),
    [TD_F2] = ACTION_TAP_DANCE_FN(f2_tap_dance),
    [TD_F6] = ACTION_TAP_DANCE_FN(f6_tap_dance),
    [TD_F9] = ACTION_TAP_DANCE_FN(f9_tap_dance),
    [TD_F12] = ACTION_TAP_DANCE_FN(f12_tap_dance),
};
#endif // TAP_DANCE_ENABLE

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F_SFT:
        case J_SFT:
            return g_tapping_term - TAPPING_TERM_DECREASE_SHIFT;
        // left tap-hold keys
        case S_ALT:
        case A_CTL:
        case E_MEH:
            return g_tapping_term + TAPPING_TERM_INCREASE_LEFT;
        // right tap-hold keys
        case L_ALT:
        case SCLN_CTL:
        case I_MEH:
            return g_tapping_term + TAPPING_TERM_INCREASE_RIGHT;
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
    }
}
#endif
