/* Copyright 2015-2021 Jack Humbert
 * Copyright 2023 Brian Grant <@btgrant-76>
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
#include "btgrant-76.h"

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant_grid(
        ___5BASE_1_L___,                      XXXXXXX, XXXXXXX,                            ___5BASE_1_R___,
        ___5BASE_2_L___,                      XXXXXXX, XXXXXXX,                            ___5BASE_2_R___,
        ___5BASE_3_L___,                      XXXXXXX, XXXXXXX,                            ___5BASE_3_R___,
        XXXXXXX, XXXXXXX,  KC_DEL, ___BASE_THUMB_L___, ENT_MED, SPC_NAV, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),
    [_NUM] = LAYOUT_btgrant_grid(
        ___5NUM_1_L___,                      XXXXXXX, XXXXXXX,                      ___5NUM_1_R___,
        ___5NUM_2_L___,                      XXXXXXX, XXXXXXX,                      ___5NUM_2_R___,
        ___5NUM_3_L___,                      XXXXXXX, XXXXXXX,                      ___5NUM_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX, ___NUM_THUMB_L___, ___NUM_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant_grid(
        ___5SYM_1_L___,                      XXXXXXX, XXXXXXX,                      ___5SYM_1_R___,
        ___5SYM_2_L___,                      XXXXXXX, XXXXXXX,                      ___5SYM_2_R___,
        ___5SYM_3_L___,                      XXXXXXX, XXXXXXX,                      ___5SYM_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX, ___SYM_THUMB_L___, ___SYM_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant_grid(
        ___5NAV_1_L___,                      XXXXXXX, XXXXXXX,                      ___5NAV_1_R___,
        ___5NAV_2_L___,                      XXXXXXX, XXXXXXX,                      ___5NAV_2_R___,
        ___5NAV_3_L___,                      XXXXXXX, XXXXXXX,                      ___5NAV_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX, ___NAV_THUMB_L___, ___NAV_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX

    ),
    [_FUN] = LAYOUT_btgrant_grid(
        ___5FUN_1_L___,                      XXXXXXX, XXXXXXX,                      ___5FUN_1_R___,
        ___5FUN_2_L___,                      XXXXXXX, XXXXXXX, XXXXXXX,             ___5FUN_2_R___,
        ___5FUN_3_L___,                      XXXXXXX, XXXXXXX,                      ___5FUN_3_R___,
        XXXXXXX, XXXXXXX, XXXXXXX, ___FUN_THUMB_L___, ___FUN_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
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

void matrix_scan_user(void) {
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
