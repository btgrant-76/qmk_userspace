/* Copyright 2025 Brian Grant @btgrant-76
 * Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// TODO include btgrant.h?
#define HOLD     XXXXXXX
#define BACK     LCMD(KC_LBRC)
#define FWD      LCMD(KC_RBRC)
#define MISS_CTL LCTL(KC_UP)
#define EXPOSE   LCTL(KC_DOWN)
#define CUT      LGUI(KC_X)
#define COPY     LGUI(KC_C)
#define PASTE    LGUI(KC_V)

//void m3_drag_dance(tap_dance_state_t *state, void *user_data) {
//    if (state->pressed && !state->interrupted) {
//
//    } else {
//        int i;
//        for (i = 0; i < state->count; i++) {
//            SEND_STRING(".");
//        }
//    }
//};

#ifdef TAP_DANCE_ENABLE
// Tap Dance declarations
enum {
    DRAG_M3,
};

tap_dance_action_t tap_dance_actions[] = {
    // since this involves a press-and-hold option, this could be replaced with ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE
    // the initial hold would likely register_code(DRAG_SCROLL) and that state would be cleared by the on_each_release_fn
    // in the short term, I could also try drag scroll toggle
    [DRAG_M3] = ACTION_TAP_DANCE_DOUBLE(DRAG_SCROLL, KC_BTN3), // this does not seem to work for DRAG_SCROLL
};

#define M3_DRAG TD(DRAG_M3)

#else

#define M3_DRAG DRAG_SCROLL

#endif // TAP_DANCE_ENABLE

/* TODO try out the tapdances described here:  https://discord.com/channels/1119347467545219143/1138670557638971433/1381057782693757101
 * TODO what other mouse buttons could be layer taps if I only tap the mouse button in practice?

    TD1. Tap:  Mouse 4/Back; 2x Tap:  M0
    TD2. Tap:  Mouse 5/Fwd; 2x Tap:  M1
    TD3. Hold: Drag Scroll; 2x Tap:  Mouse 3
    TD4. Tap:  Mouse 2; 2x Tap:  DPI

    CB1. KC_BTN1 + TD3 = MO(1)
    CB2. BACK + FWD = TG(2)

    [0] = LAYOUT(     TD1,    TD2,        KC_BTN3, TD4,
                  KC_BTN1,                      M3_DRAG
    ),
    [1] = LAYOUT( KC_MPRV, KC_MNXT,    MISS_CTL,EXPOSE,
                     HOLD,                      HOLD
    ),
    [2] = LAYOUT( XXXXXXX, DPI_CONFIG, XXXXXXX, QK_BOOT,
                  XXXXXXX,                      TG(2)
    )
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( BACK,    FWD,        KC_BTN3, KC_BTN2,
                  KC_BTN1,                      /*M3_DRAG*/ DRAG_SCROLL
    ),
    // btn1_and_back
    [1] = LAYOUT( KC_MPRV, KC_MNXT,    MISS_CTL,EXPOSE,
                  KC_BTN1,                      TG(1)
    ),
    // btn1_and_fwd
    [2] = LAYOUT( XXXXXXX, DPI_CONFIG, XXXXXXX, QK_BOOT,
                  KC_BTN1,                      TG(2)
    )
};

#ifdef COMBO_ENABLE

const uint16_t PROGMEM back_and_fwd[] =      {BACK,    FWD,         COMBO_END};
const uint16_t PROGMEM btn1_and_back[] =     {KC_BTN1, BACK,        COMBO_END};
const uint16_t PROGMEM btn1_and_btn2[] =     {KC_BTN1, KC_BTN2,     COMBO_END};
const uint16_t PROGMEM btn1_and_btn3[] =     {KC_BTN1, KC_BTN3,     COMBO_END};
const uint16_t PROGMEM btn1_and_fwd[] =      {KC_BTN1, FWD,         COMBO_END};
const uint16_t PROGMEM btn1_and_scroll[] =   {KC_BTN1, DRAG_SCROLL, COMBO_END};
const uint16_t PROGMEM med_next_and_prev[] = {KC_MNXT, KC_MPRV,     COMBO_END};

combo_t key_combos[] = {
    COMBO(back_and_fwd,      CUT),
    COMBO(btn1_and_back,     TG(1)),
    COMBO(btn1_and_btn2,     COPY),
    COMBO(btn1_and_btn3,     CUT),
    COMBO(btn1_and_fwd,      TG(2)),
    COMBO(btn1_and_scroll,   PASTE),
    COMBO(med_next_and_prev, KC_MPLY),
};
#endif
