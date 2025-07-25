// Copyright 2023 sporkus
// Copyright 2025 btgrant-76
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"

#include "four_thumb_combos.h"

#define BLOCKER XXXXXXX

#ifdef TRY_CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_btgrant(
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
    );
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant(
        ___5BASE_1_L___,                                                         ___5BASE_1_R___,
        ___5BASE_2_L___,                                                         ___5BASE_2_R___,
        ___5BASE_3_L___,                                                         ___5BASE_3_R___,
#ifdef FOUR_THUMBS
        BACK,    ESC_FUN, TAB_MSE, XXXXXXX,  BS_NUM, SPC_NAV, XXXXXXX, DEL_MSE, ENT_SYM,     FWD
#else
        BLOCKER, XXXXXXX, ___BASE_THUMB_L___,               ___BASE_THUMB_R___, XXXXXXX, BLOCKER
#endif
    ),
    [_NUM] = LAYOUT_btgrant(
        ___5NUM_1_L___,                                                           ___5NUM_1_R___,
        ___5NUM_2_L___,                                                           ___5NUM_2_R___,
        ___5NUM_3_L___,                                                           ___5NUM_3_R___,
#ifdef FOUR_THUMBS
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX,    KC_0, _______, _______
#else
        BLOCKER, XXXXXXX, ___NUM_THUMB_L___,                ___NUM_THUMB_R___,  XXXXXXX, BLOCKER
#endif
    ),
    [_SYM] = LAYOUT_btgrant(
        ___5SYM_1_L___,                                                           ___5SYM_1_R___,
        ___5SYM_2_L___,                                                           ___5SYM_2_R___,
        ___5SYM_3_L___,                                                           ___5SYM_3_R___,
#ifdef FOUR_THUMBS
        _______, _______, KC_MUTE, XXXXXXX, KC_MPLY,LPRN_MSE, XXXXXXX, XXXXXXX, _______, _______
#else
        BLOCKER, XXXXXXX, ___SYM_THUMB_L___,                ___SYM_THUMB_R___,  XXXXXXX, BLOCKER
#endif
    ),
    [_NAV] = LAYOUT_btgrant(
        ___5NAV_1_L___,                                                           ___5NAV_1_R___,
        ___5NAV_2_L___,                                                           ___5NAV_2_R___,
        ___5NAV_3_L___,                                                           ___5NAV_3_R___,
#ifdef FOUR_THUMBS
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
#else
        BLOCKER, XXXXXXX, ___NAV_THUMB_L___,                ___NAV_THUMB_R___,  XXXXXXX, BLOCKER
#endif
    ),
    [_FUN] = LAYOUT_btgrant(
        ___5FUN_1_L___,                                                           ___5FUN_1_R___,
        ___5FUN_2_L___,                                                           ___5FUN_2_R___,
        ___5FUN_3_L___,                                                           ___5FUN_3_R___,
#ifdef FOUR_THUMBS
        _______, _______, XXXXXXX, XXXXXXX,MO(_MSE),MO(_ADD), XXXXXXX, XXXXXXX, _______, _______
#else
        BLOCKER, XXXXXXX, ___FUN_THUMB_L___,                ___FUN_THUMB_R___,  XXXXXXX, BLOCKER
#endif
    ),
    [_MSE] = LAYOUT_btgrant(
        ___5MSE_1_L___,                                                           ___5MSE_1_R___,
        ___5MSE_2_L___,                                                           ___5MSE_2_R___,
        ___5MSE_3_L___,                                                           ___5MSE_3_R___,
#ifdef FOUR_THUMBS
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
#else
        BLOCKER, XXXXXXX, ___MSE_THUMB_L___,                ___MSE_THUMB_R___,  XXXXXXX, BLOCKER
#endif
    ),
    [_ADD] = LAYOUT_btgrant(
        ___5ADD_1_L___,                                                           ___5ADD_1_R___,
        ___5ADD_2_L___,                                                           ___5ADD_2_R___,
        ___5ADD_3_L___,                                                           ___5ADD_3_R___,
#ifdef FOUR_THUMBS
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
#else
        BLOCKER, XXXXXXX, ___ADD_THUMB_L___,                ___ADD_THUMB_R___, XXXXXXX, BLOCKER
#endif
    )
};

#ifdef RGB_MATRIX_ENABLE

#define RGB_LAYER_INDICATOR_ENABLE
#define RGB_MODS_INDICATOR_ENABLE
#define RGB_INDICATOR_BRIGHTNESS 69

#define LED_RIGHT 1
#define LED_LEFT 0

#define LAYER_R layer_colors[layer][0] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_G layer_colors[layer][1] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_B layer_colors[layer][2] *  RGB_INDICATOR_BRIGHTNESS / 255

#define MODS_ACTIVE(mods) ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? RGB_INDICATOR_BRIGHTNESS:0)
#define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? RGB_INDICATOR_BRIGHTNESS/4:0)
#define MODS_R MODS_ACTIVE(CTRL) + SHIFT_ACTIVE
#define MODS_G MODS_ACTIVE(GUI) + SHIFT_ACTIVE
#define MODS_B MODS_ACTIVE(ALT) + SHIFT_ACTIVE

const uint8_t PROGMEM layer_colors[][3] = {
    {RGB_OFF},
    {RGB_RED},
    {RGB_GREEN},
    {RGB_BLUE},
    {RGB_YELLOW},
    {RGB_PURPLE},
    {RGB_PINK},
    {RGB_TEAL}
};

void set_rgb_matrix_indicators(uint8_t led_min, uint8_t led_max) {
    #if defined(RGB_LAYER_INDICATOR_ENABLE)
    int layer = get_highest_layer(layer_state|default_layer_state);
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_RIGHT, LAYER_R, LAYER_G, LAYER_B);
    /* uprintf("layer RGB: (%u, %u, %u)\n", LAYER_R, LAYER_G, LAYER_B); */
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_RIGHT, 0, 0, 0);
    #endif

    #if defined(RGB_MODS_INDICATOR_ENABLE)
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_LEFT, MODS_R, MODS_G, MODS_B);
    /* uprintf("mod RGB: (%u, %u, %u)\n", MODS_R, MODS_G, MODS_B); */
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_LEFT, 0, 0, 0);
    #endif
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    set_rgb_matrix_indicators(led_min, led_max);
    return false;
}

#endif
