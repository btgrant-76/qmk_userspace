#include QMK_KEYBOARD_H
#include <stdio.h>
#include <math.h>

#define L_DEF 0
#define L_GAM 1
#define L_LOW 2
#define L_RAI 3
#define L_SPC 4
#define L_NAV 5
#define L_NUM 6

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;
};

void oled_render_layer_state(void) {
    oled_write_P(PSTR("\n\nLayer\n"), false);
    switch (layer_state) {
        case L_DEF:
            oled_write_ln_P(PSTR("-Def-"), false);
            break;
        case (int)pow(2,L_GAM):
            oled_write_ln_P(PSTR("-Gam-"), false);
            break;
        case (int)pow(2,L_LOW):
            oled_write_ln_P(PSTR("-Low-"), false);
            break;
        case (int)pow(2,L_RAI):
            oled_write_ln_P(PSTR("-Rai-"), false);
            break;
        case (int)pow(2,L_SPC):
            oled_write_ln_P(PSTR("-Spc-"), false);
            break;
        case (int)pow(2,L_NAV):
            oled_write_ln_P(PSTR("-Nav-"), false);
            break;
        case (int)pow(2,L_NUM):
        case (int)pow(2,L_NUM)|(int)pow(2,L_GAM):
            oled_write_ln_P(PSTR("-Num-"), false);
            break;
        default :
            oled_write_ln_P(PSTR("-MUL-"), false);
    }
}

void oled_render_caps_state(void){
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("\n=CAPS\n") : PSTR("\n    \n\n"), false);
}

bool oled_task_user(void) {
    oled_render_layer_state();
    oled_render_caps_state();
    return true;
};
#endif // OLED_ENABLE

// macros
enum custom_keycodes {
  RPIPE = SAFE_RANGE, RASGN, // R macros
  KORLN,
  CAPZ,CTRLB, // lower row mod alternatives
  VIMSV,VIMQT // vim macros
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {    
  switch (keycode) {    
    case RPIPE:        
      if (record->event.pressed){
        SEND_STRING("%>%");
      } 
      break;    
    case RASGN:        
      if (record->event.pressed){
        SEND_STRING("<-");        
      } 
      break;    
    case KORLN:        
      if (record->event.pressed){
        SEND_STRING(SS_LGUI(" ") SS_DELAY(200) SS_TAP(X_RALT));
      } 
      break;
    case VIMSV:        
      if (record->event.pressed){
        SEND_STRING(":w!");
      } 
      break;
    case VIMQT:        
      if (record->event.pressed){
        SEND_STRING(":q!");
      } 
      break;
    case CAPZ:
      if (record->event.pressed){
        SEND_STRING("Z");
      }
      break;
    case CTRLB:
      if (record->event.pressed){
        SEND_STRING(SS_LCTL("B"));
      }
      break;
  }    
  return true;
};
 
// combos
const uint16_t PROGMEM GUI_combo[] = {KC_A, KC_W, COMBO_END};
const uint16_t PROGMEM ESC_combo[] = {KC_Q, KC_W, COMBO_END};

const uint16_t PROGMEM BSL_combo[] = {KC_O, KC_SCLN, COMBO_END};
const uint16_t PROGMEM ENT_combo[] = {KC_L, KC_SLSH, COMBO_END};
const uint16_t PROGMEM QUO_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM FTW_combo[] = {KC_MINS, KC_RBRC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(GUI_combo,KC_LGUI),
  COMBO(ESC_combo,KC_ESC),
  COMBO(BSL_combo,KC_BSLS),
  COMBO(ENT_combo,KC_ENT),
  COMBO(QUO_combo,KC_QUOT),
  COMBO(FTW_combo,KC_F12),
};
layer_state_t layer_state_set_user(layer_state_t state) {
    combo_enable();
    if (layer_state_cmp(state, L_GAM)) {
        combo_disable();
    }
    return state;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_SPC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G, _______,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
 LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,LCTL_T(KC_B),_______, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
               KC_LALT,LT(L_LOW,KC_TAB),LT(L_NAV,KC_BSPC),_______,KC_SPC,MO(L_RAI),LT(L_SPC,KC_RALT)
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [L_LOW] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
       KC_GRV, _______, _______, _______, _______, _______, _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        _______, _______,  KC_DEL, _______, _______, _______, _______
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [L_RAI] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      KC_TILD, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        _______, _______,  KC_DEL, _______, _______, _______, _______
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [L_SPC] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
      _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLU,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLD,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        KC_LOCK, KC_RSFT, KC_LCTL, KC_SPC,TG(L_NUM),_______,TG(L_SPC)
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [L_NAV] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
        VIMQT,   VIMSV, _______, _______, _______, _______, _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
      KC_LGUI,KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1,_______,_______,KC_LEFT,KC_DOWN, KC_UP,KC_RIGHT,   RPIPE,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
         CAPZ, _______, _______, _______,   CTRLB, _______, _______, _______,   RASGN, _______, _______,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                      TG(L_SPC),_______, _______, KC_PSCR, KC_BSPC, _______,   KORLN
                    //|--------+--------+--------+--------+--------+--------+--------|
  ), [L_NUM] = LAYOUT(
  //|--------------------------------------------|--------|--------------------------------------------|
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
         KC_7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, _______,  KC_F12,    KC_4,    KC_5,    KC_6, KC_BSPC,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______,    KC_0,    KC_1,    KC_2,    KC_3, _______,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        _______, _______, _______, _______, _______, _______,TG(L_NUM)
                    //|--------+--------+--------+--------+--------+--------+--------|
  )

};
// ENCODER
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
      switch(biton32(layer_state)){
        case L_NAV:
          if (clockwise) {
              tap_code(KC_PGDN);
          } else {
              tap_code(KC_PGUP);
          }
          break;
        case L_SPC:
          if (clockwise) {
              tap_code(KC_RIGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;
        case L_GAM:
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
          break;
        default:
          if (clockwise) {
              tap_code(KC_RIGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;
      }
    }
    return false;
}

// MOD TAP settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Favor tapping 
        case LCTL_T(KC_N):
            return false;
        case LCTL_T(KC_B):
            return false;
        case LSFT_T(KC_Z):
            return false;
        // default true
        default:
            return true;
    }
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Favor tapping
        case LT(5,KC_BSPC):
            return false;
        case LCTL_T(KC_N):
            return false;
        case LCTL_T(KC_B):
            return false;
        case LSFT_T(KC_Z):
            return false;
        // default true
        default:
            return true;
    }
}
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_B):
            return false;
        // default true - no auto-hold with double tap, but allow using hold right after using tap
        default:
            return true;
    }
}
// retro tapping
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3,KC_RALT):
            return true;
        case LT(L_LOW,KC_TAB):
            return true;
        // default false - nothing happens when you exceed tapping term but not use hold
        case LSFT_T(KC_Z):
            return false;
        case LCTL_T(KC_B):
            return false;
        default:
            return false;
    }
}
// tapping term 
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) { 
        // low tapping term favors hold
        // high tapping term favors tap
        case LALT_T(KC_ESC):
            return 200;
        case LCTL_T(KC_B):
            return 125;
        case LCTL_T(KC_N):
            return 125;
        case LSFT_T(KC_Z):
            return 125;
        case LSFT_T(KC_X):
            return 125;
        // default
        default:
            return 150;
    }
}

