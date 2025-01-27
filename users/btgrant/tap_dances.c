#ifdef TAP_DANCE_ENABLE
#include "macros.h"

// TODO should this be referenced directly?

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
#endif
