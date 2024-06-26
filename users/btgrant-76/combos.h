const uint16_t PROGMEM QUOT[] = {L_ALT, SCLN_CTL, COMBO_END};
const uint16_t PROGMEM D_QUOT[] = {LSFT_T(KC_F), RALT_T(KC_L), RCTL_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM ESC_TOP[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM ESC_BOT[] = {Z_HYPR, KC_X, COMBO_END};
const uint16_t PROGMEM ESC_BOT2[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ENTER[] = {HYPR_T(KC_SLSH), KC_DOT, COMBO_END};
const uint16_t PROGMEM ENTER2[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(QUOT, KC_QUOT),
    COMBO(D_QUOT, KC_DQT),
    COMBO(ESC_TOP, KC_ESC),
    COMBO(ESC_BOT, KC_ESC),
    COMBO(ESC_BOT2, KC_ESC),
    COMBO(ENTER, KC_ENT),
    COMBO(ENTER2, KC_ENT)
};
