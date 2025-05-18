/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2025 Brian Grant @btgrant-76
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

/* TODO define some combos
 *  x changing DPI
 *  - mission control
 *  - add a layer
 *  - add a boot key
 */


#define HOLD     XXXXXXX
#define BACK     LCMD(KC_LBRC)
#define FWD      LCMD(KC_RBRC)
#define MISS_CTL LCTL(KC_UP)
#define EXPOSE   LCTL(KC_DOWN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( BACK,    FWD,        KC_BTN3, KC_BTN2,
                  KC_BTN1,                      DRAG_SCROLL
    ),
    [1] = LAYOUT( KC_MPRV, XXXXXXX,    XXXXXXX, KC_MNXT,
                  KC_BTN1,                      KC_BTN2
    ),
    [2] = LAYOUT( XXXXXXX, DPI_CONFIG, XXXXXXX, XXXXXXX,
                  KC_BTN1,                      KC_BTN2
    )
};

#ifdef COMBO_ENABLE

const uint16_t PROGMEM l1[] = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM l2[] = {BACK, FWD, COMBO_END};
const uint16_t PROGMEM play[] = {KC_MNXT, KC_MPRV, COMBO_END};
//const uint16_t PROGMEM MISS[] = {KC_MNXT, KC_MPRV, COMBO_END};


combo_t key_combos[] = {
    COMBO(l1, TG(1)), // TODO this would work better as a toggle
    COMBO(l2, TG(2)), // TODO this would work better as a toggle
    COMBO(play,  KC_MPLY)
};
#endif
