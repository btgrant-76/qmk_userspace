const uint16_t PROGMEM CAPS[] = {F_SFT, J_SFT, COMBO_END};
const uint16_t PROGMEM QUOT[] = {L_ALT, SCLN_CTL, COMBO_END};
const uint16_t PROGMEM D_QUOT[] = {LSFT_T(KC_F), RALT_T(KC_L), RCTL_T(KC_SCLN), COMBO_END};

/* Esc while Cmd-Tabbing */
const uint16_t PROGMEM ESC_2[] = {Z_HYPR, KC_X, COMBO_END};

/* Esc on mouse layer */
const uint16_t PROGMEM ESC_3[] = {KC_BTN1, KC_BTN2, COMBO_END};

/* supporting two-key thumb clusters, e.g. Le Chiffre */
/** replace inner thumb key taps **/
const uint16_t PROGMEM ESC[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ENTER[] = {KC_M, KC_COMM, COMBO_END};

/** trigger layers **/
const uint16_t PROGMEM MO_FUN[] = {TAB_MSE, BS_NUM, COMBO_END};
const uint16_t PROGMEM MO_SYM[] = {SPC_NAV, DEL_MSE, COMBO_END};
