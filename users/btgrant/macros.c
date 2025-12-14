#include "quantum.h"

void braces_insert(void) {
    SEND_STRING("[]" SS_DELAY(100) SS_TAP(X_LEFT));
};

void curly_braces_insert(void) {
    SEND_STRING("{}" SS_DELAY(100) SS_TAP(X_LEFT));
};

void parens_insert(void) {
    SEND_STRING("()" SS_DELAY(100) SS_TAP(X_LEFT));
};


void grave_pair_cursor_insertion(void) {
    SEND_STRING("``" SS_DELAY(100) SS_TAP(X_LEFT));
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
    SEND_STRING("[];" SS_DELAY(100) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
};

void curly_braces(void) {
    SEND_STRING("{}");
};

void curly_braces_semi(void) {
    SEND_STRING("{};");
};

void curly_braces_semi_insert(void) {
    SEND_STRING("{};" SS_DELAY(100) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
};

void parens(void) {
    SEND_STRING("()");
};

void parens_semi(void) {
    SEND_STRING("();");
};

void parens_semi_insert(void) {
    SEND_STRING("();" SS_DELAY(100) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
};

void quote_pair_cursor_insertion(void) {
    SEND_STRING("''" SS_DELAY(100) SS_TAP(X_LEFT));
};

void dquote_pair_cursor_insertion(void) {
    SEND_STRING("\"\"" SS_DELAY(100) SS_TAP(X_LEFT));
};

void macos_log_out(void) {
    register_code(KC_LGUI);
    register_code(KC_LCTL);
    tap_code(KC_Q);
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
};

void vim_write(void) {
    SEND_STRING(SS_TAP(X_ESC) ":w" SS_DELAY(100) SS_TAP(X_ENT));
};

void vim_write_and_quit(void) {
    SEND_STRING(SS_TAP(X_ESC) ":wq" SS_DELAY(100) SS_TAP(X_ENT));
};

void vim_yank_to_clipboard(void) {
    SEND_STRING("\"+y");
};

void new_browser_window_you_jerk(void) {
    SEND_STRING(SS_LGUI("n") SS_DELAY(400) SS_LGUI("t") SS_LGUI("{") SS_LGUI("w"));
};

void tag_open_insert(void) {
    SEND_STRING("<>" SS_DELAY(100) SS_TAP(X_LEFT));
};

void tag_close_insert(void) {
    SEND_STRING("</>" SS_DELAY(100) SS_TAP(X_LEFT));
};

void tag_void_insert(void) {
    SEND_STRING("< />" SS_DELAY(100) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
};

void js_console_log(void) {
    SEND_STRING("console.log('');" SS_DELAY(100) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
};
