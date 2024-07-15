const uint16_t PROGMEM QUOT[] = {L_ALT, SCLN_CTL, COMBO_END};
const uint16_t PROGMEM D_QUOT[] = {LSFT_T(KC_F), RALT_T(KC_L), RCTL_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM ESC[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ESC_2[] = {Z_HYPR, KC_X, COMBO_END};
const uint16_t PROGMEM ESC_3[] = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM ENTER[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM CAPS[] = {F_SFT, J_SFT, COMBO_END};

combo_t key_combos[] = {
    COMBO(QUOT, KC_QUOT),
    COMBO(D_QUOT, KC_DQT),
    COMBO(ESC, KC_ESC),
    COMBO(ESC_2, KC_ESC),
    COMBO(ESC_3, KC_ESC),
    COMBO(ENTER, KC_ENT),
    COMBO(CAPS, KC_CAPS)
};
