#ifdef KEY_OVERRIDE_ENABLE
// TODO look at the docs for `layer_state_t` and update accordingly https://docs.qmk.fm/features/key_overrides#reference-for-key_override_t

/* base layer */
const key_override_t esc_ko = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, A_CTL, KC_ESC, ~0, MOD_MASK_SAG);
const key_override_t switcher_esc_ko = ko_make_with_layers_and_negmods(MOD_MASK_ALT, A_CTL, KC_ESC, ~0, MOD_MASK_CTRL);
const key_override_t quote_ko = ko_make_basic(MOD_MASK_CTRL, SCLN_CTL, KC_QUOT); // QUOTE_ON_BASE ; on BASE
const key_override_t scln_ko = ko_make_basic(MOD_MASK_CTRL, QUOT_CTL, KC_SCLN); // QUOTE_ON_BASE ' on BASE
const key_override_t enter_ko = ko_make_basic(MOD_MASK_CTRL, SLS_HYPR, KC_ENT);

/** symbols on base **/
const key_override_t l_brc_ko = ko_make_basic(MOD_MASK_CA, KC_COMM, KC_LBRC);
const key_override_t r_brc_ko = ko_make_basic(MOD_MASK_CA, KC_DOT, KC_RBRC);
const key_override_t l_brc_ko_2 = ko_make_basic(MOD_MASK_CG, KC_COMM, KC_LBRC);
const key_override_t r_brc_ko_2 = ko_make_basic(MOD_MASK_CG, KC_DOT, KC_RBRC);
const key_override_t l_paren_ko = ko_make_basic(MOD_MASK_CTRL, KC_COMM, KC_LPRN);
const key_override_t r_paren_ko = ko_make_basic(MOD_MASK_CTRL, KC_DOT, KC_RPRN);

/* easier access to parens on NUM */
const key_override_t l_brc_paren_ko = ko_make_basic(MOD_MASK_CTRL, KC_LBRC, KC_LPRN);
const key_override_t r_brc_paren_ko = ko_make_basic(MOD_MASK_CTRL, KC_RBRC, KC_RPRN);

/* numpad */
const key_override_t grv_slsh_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_GRV, KC_SLSH, ~0);
const key_override_t mins_space_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_MINS, KC_SPC, ~0);
const key_override_t quot_coln_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_QUOT, KC_COLN, ~0); // QUOTE_ON_BASE ' on NUM
const key_override_t coln_quot_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_SCLN, KC_QUOT, ~0); // QUOTE_ON_BASE ; on NUM
const key_override_t three_dot_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_3, KC_DOT, ~0);
const key_override_t two_comma_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_2, KC_COMM, ~0);
const key_override_t zero_space_ko = ko_make_with_layers(MOD_MASK_CTRL, KC_0, KC_SPC, ~0);

/* encoder */
const key_override_t switcher_fwd = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_TAB);
const key_override_t switcher_back = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, LSFT(KC_TAB));

const key_override_t *key_overrides[] = {
    /* base layer */
    /* DISPLACE TEST BEGIN
    &esc_ko,
    &quote_ko,
    &enter_ko,
    DISPLACE TEST END */
    &scln_ko,
    &switcher_esc_ko,

    /** symbols on base **/
    &l_brc_ko,
    &r_brc_ko,
    &l_brc_ko_2,
    &r_brc_ko_2,
    &l_paren_ko,
    &r_paren_ko,

    /* easier access to parens on NUM */
    &l_brc_paren_ko,
    &r_brc_paren_ko,

    /* numpad */
    &grv_slsh_ko,
    &mins_space_ko,
    &quot_coln_ko,
    &coln_quot_ko,
    &three_dot_ko,
    &two_comma_ko,
    &zero_space_ko,

    /* encoder */
    &switcher_fwd,
    &switcher_back,
};
#endif

//    &two_thumb_esc_ko,
//    &two_thumb_enter_ko,
// TODO these probably won't work without some help from Achordion since they're intended to work same-hand
//const key_override_t two_thumb_esc_ko = ko_make_basic(MOD_MASK_CTRL, BS_NUM, KC_ESC);
//const key_override_t two_thumb_enter_ko = ko_make_basic(MOD_MASK_CTRL, SPC_NAV, KC_ENT);
