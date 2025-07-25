#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
    [_NUM]  = { ENCODER_CCW_CW(KC_PGDN,  KC_PGUP) },
    [_SYM]  = { ENCODER_CCW_CW(KC_MPRV,  KC_MNXT) },
    [_NAV]  = { ENCODER_CCW_CW(BACK,     FWD) },
    [_FUN]  = { ENCODER_CCW_CW(KC_BRID,  KC_BRIU) },
    [_MSE]  = { ENCODER_CCW_CW(LEFT_SPC, RGHT_SPC) },
    [_ADD]  = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [_NRM]  = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) }
};
#endif
