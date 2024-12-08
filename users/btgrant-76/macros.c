#include "quantum.h"

// TODO most of these could probably be replaced with send_string("[" SS_TAP(X_LEFT) "]") and
void generic_insert(char *text) {
    send_string(text); // TODO move the keystroke into send_string
    tap_code(KC_LEFT);
};

void braces_insert(void) {
    generic_insert("[]");
};

void curly_braces_insert(void) {
    generic_insert("{}");
};

void parens_insert(void) {
    generic_insert("()");
};

void grave_pair_cursor_insertion(void) {
    generic_insert("``");
};

void code_fence(void) {
    SEND_STRING("```" SS_TAP(X_ENT) SS_TAP(X_ENT) "```" SS_TAP(X_UP) SS_TAP(X_UP));
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

void vim_write(void) {
    SEND_STRING(SS_TAP(X_ESC) ":w" SS_TAP(X_ENT));
};

void new_browser_window_you_jerk(void) {
    SEND_STRING(SS_LGUI("n") SS_DELAY(2000) SS_LGUI("t") SS_LGUI("{") SS_LGUI("w"));
};

void tag_open_insert(void) {
    generic_insert("<>");
};

void tag_close_insert(void) {
    generic_insert("</>");
};

void tag_void_insert(void) {
    generic_insert("< />");
    tap_code(KC_LEFT);
    tap_code(KC_LEFT);
};
