/* Copyright 2015-2021 Jack Humbert
 * Copyright 2025 Brian Grant <@btgrant-76>
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

#include "btgrant.h"
#include "key_overrides.h"
#include "tap_dances.c"

#include "encoder_map.h"
#include "encoder_press.h"

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

#ifdef COMBO_ENABLE
#include "combo_defs.h"

combo_t key_combos[] = {
    COMBO(MUTE, KC_MUTE),
    COMBO(PLAY, KC_MPLY),
    /* DISPLACE TEST BEGIN
    COMBO(QUOT, KC_QUOT),
    COMBO(D_QUOT, KC_DQT),
    COMBO(ESC_Z_X, KC_ESC),
    COMBO(ESC_C_V, KC_ESC),
    COMBO(ENTER_M_COMM, KC_ENT),
    DISPLACE TEST END */
    COMBO(CAPS, KC_CAPS),
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant_planck_grid(
        ___5BASE_1_L___,                         BACK,     FWD,                      ___5BASE_1_R___,
        ___5BASE_2_L___,                      XXXXXXX, XXXXXXX,                      ___5BASE_2_R___,
        ___5BASE_3_L___,                      KC_MPRV, KC_MNXT,                      ___5BASE_3_R___,
        ENC_BASE,XXXXXXX, ___BASE_THUMB_L___, KC_VOLD, KC_VOLU, ___BASE_THUMB_R___, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT_btgrant_planck_grid(
        ___5NUM_1_L___,                       XXXXXXX, XXXXXXX,                       ___5NUM_1_R___,
        ___5NUM_2_L___,                       XXXXXXX, XXXXXXX,                       ___5NUM_2_R___,
        ___5NUM_3_L___,                       XXXXXXX, XXXXXXX,                       ___5NUM_3_R___,
        ENC_NUM, XXXXXXX, ___NUM_THUMB_L___,  XXXXXXX, XXXXXXX, ___NUM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant_planck_grid(
        ___5SYM_1_L___,                       XXXXXXX, XXXXXXX,                       ___5SYM_1_R___,
        ___5SYM_2_L___,                       XXXXXXX, XXXXXXX,                       ___5SYM_2_R___,
        ___5SYM_3_L___,                       XXXXXXX, XXXXXXX,                       ___5SYM_3_R___,
        ENC_SYM, XXXXXXX, ___SYM_THUMB_L___,  XXXXXXX, XXXXXXX, ___SYM_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant_planck_grid(
        ___5NAV_1_L___,                       XXXXXXX, XXXXXXX,                       ___5NAV_1_R___,
        ___5NAV_2_L___,                       XXXXXXX, XXXXXXX,                       ___5NAV_2_R___,
        ___5NAV_3_L___,                       XXXXXXX, XXXXXXX,                       ___5NAV_3_R___,
        ENC_NAV,XXXXXXX, ___NAV_THUMB_L___,  XXXXXXX, XXXXXXX, ___NAV_THUMB_R___,  XXXXXXX, XXXXXXX

    ),
    [_FUN] = LAYOUT_btgrant_planck_grid(
        ___5FUN_1_L___,                       XXXXXXX, XXXXXXX,                       ___5FUN_1_R___,
        ___5FUN_2_L___,                       XXXXXXX, XXXXXXX,                       ___5FUN_2_R___,
        ___5FUN_3_L___,                       XXXXXXX, XXXXXXX,                       ___5FUN_3_R___,
        ENC_FUN, XXXXXXX, ___FUN_THUMB_L___,  XXXXXXX, XXXXXXX, ___FUN_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_MSE] = LAYOUT_btgrant_planck_grid(
        ___5MSE_1_L___,                       XXXXXXX, XXXXXXX,                       ___5MSE_1_R___,
        ___5MSE_2_L___,                       XXXXXXX, XXXXXXX,                       ___5MSE_2_R___,
        ___5MSE_3_L___,                       XXXXXXX, XXXXXXX,                       ___5MSE_3_R___,
        MISS_CTL,XXXXXXX, ___MSE_THUMB_L___,  XXXXXXX, XXXXXXX, ___MSE_THUMB_R___,  XXXXXXX, XXXXXXX
    ),
    [_ADD] = LAYOUT_btgrant_planck_grid(
        ___5ADD_1_L___,                       XXXXXXX,  XXXXXXX,                      ___5ADD_1_R___,
        ___5ADD_2_L___,                       XXXXXXX,  XXXXXXX,                      ___5ADD_2_R___,
        ___5ADD_3_L___,                       XXXXXXX,  XXXXXXX,                      ___5ADD_3_R___,
        ENC_FUN, XXXXXXX, ___ADD_THUMB_L___,  XXXXXXX,  XXXXXXX, ___ADD_THUMB_R___, XXXXXXX, XXXXXXX
    )
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_keymap(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return false;
};

bool achordion_chord_keymap(uint16_t tap_hold_keycode,
                            keyrecord_t* tap_hold_record,
                            uint16_t other_keycode,
                            keyrecord_t* other_record) {
/* col, row
  |-----------------------------------------------------------------------------------------------------------|
    0, 0     1, 0     2, 0     3, 0     4, 0   |                 | 1, 4     2, 4     3, 4     4, 4     5, 4
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    0, 1     1, 1     2, 1     3, 1     4, 1   |                 | 1, 5     2, 5     3, 5     4, 5     5, 5
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    0, 2     1, 2     2, 2     3, 2     4, 2   |                 | 1, 6     2, 6     3, 6     4, 6     5, 6
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    ----     ----     2, 3     3, 7     4, 7   |                 | 1, 7     2, 7     3, 3     ----     ----
  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
*/

    #ifdef CONSOLE_ENABLE
    dprintln("achordion_chord_keymap called");
    #endif

    switch (other_record->event.key.row) {
        case 7: // inner, two thumb keys
            switch (other_record->event.key.col) {
                case 3 ... 4:
                    if (tap_hold_record->event.key.row == 5 || tap_hold_record->event.key.row == 6) { // right-side tap-holds
                        #ifdef CONSOLE_ENABLE
                        dprintln("achordion_chord_keymap: return true\n");
                        #endif
                        return true;
                    }
            }
        case 3: // outer thumb keys
            if (tap_hold_record->event.key.row == 1 || tap_hold_record->event.key.row == 2) { // left-side tap-holds
                #ifdef CONSOLE_ENABLE
                dprintln("achordion_chord_keymap: return true\n");
                #endif
                return true;
            }
    }

    #ifdef CONSOLE_ENABLE
    dprintln("achordion_chord_keymap: return false\n");
    #endif
    return false;
};
