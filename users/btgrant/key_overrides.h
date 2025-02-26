#ifdef KEY_OVERRIDE_ENABLE
/* base layer */
const key_override_t esc_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, A_CTL, KC_ESC, ~0, MOD_MASK_SAG);
const key_override_t l_paren_ko = ko_make_basic(MOD_MASK_CTRL, KC_COMM, KC_LPRN);
const key_override_t quote_ko = ko_make_basic(MOD_MASK_CTRL, SCLN_CTL, KC_QUOT);
const key_override_t r_paren_ko = ko_make_basic(MOD_MASK_CTRL, KC_DOT, KC_RPRN);

/* numpad */
const key_override_t grv_slsh_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_GRV, KC_SLSH, ~0);
const key_override_t mins_space_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_MINS, KC_SPC, ~0);
const key_override_t quot_coln_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_QUOT, KC_COLN, ~0);
const key_override_t three_dot_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_3, KC_DOT, ~0);
const key_override_t two_comma_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_2, KC_COMM, ~0);
const key_override_t zero_space_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_0, KC_SPC, ~0);

const key_override_t *key_overrides[] = {
    &esc_ko,
    &grv_slsh_ko,
    &l_paren_ko,
    &mins_space_ko,
    &quot_coln_ko,
    &quote_ko,
    &r_paren_ko,
    &three_dot_ko,
    &two_comma_ko,
    &zero_space_ko
};
#endif
