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
#include "combos.h"
#include "encoder_map.h"
#include "encoder_press.h"
#include "tap_dances.c"

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_btgrant_planck_grid(
        ___BASE_1_L___,                                                                             ___BASE_1_R___,
        ___BASE_2_L___,                                                                             ___BASE_2_R___,
        ___BASE_3_L___,                                                                             ___BASE_3_R___,
        ENC_BASE,XXXXXXX, XXXXXXX,        ___BASE_THUMB_L___,        ___BASE_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT_btgrant_planck_grid(
        ___NUM_1_L___,                                                                               ___NUM_1_R___,
        ___NUM_2_L___,                                                                               ___NUM_2_R___,
        ___NUM_3_L___,                                                                               ___NUM_3_R___,
        ENC_NUM, XXXXXXX,  XXXXXXX,        ___NUM_THUMB_L___,         ___NUM_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT_btgrant_planck_grid(
        ___SYM_1_L___,                                                                               ___SYM_1_R___,
        ___SYM_2_L___,                                                                               ___SYM_2_R___,
        ___SYM_3_L___,                                                                               ___SYM_3_R___,
        ENC_SYM, XXXXXXX, XXXXXXX,         ___SYM_THUMB_L___,         ___SYM_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT_btgrant_planck_grid(
        ___NAV_1_L___,                                                                               ___NAV_1_R___,
        ___NAV_2_L___,                                                                               ___NAV_2_R___,
        ___NAV_3_L___,                                                                               ___NAV_3_R___,
        ENC_NAV, XXXXXXX, XXXXXXX,         ___NAV_THUMB_L___,         ___NAV_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FUN] = LAYOUT_btgrant_planck_grid(
        ___FUN_1_L___,                                                                               ___FUN_1_R___,
        ___FUN_2_L___,                                                                               ___FUN_2_R___,
        ___FUN_3_L___,                                                                               ___FUN_3_R___,
        ENC_FUN, XXXXXXX, XXXXXXX,         ___FUN_THUMB_L___,         ___FUN_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MSE] = LAYOUT_btgrant_planck_grid(
        ___MSE_1_L___,                                                                               ___MSE_1_R___,
        ___MSE_2_L___,                                                                               ___MSE_2_R___,
        ___MSE_3_L___,                                                                               ___MSE_3_R___,
        MISS_CTL,XXXXXXX, XXXXXXX,         ___MSE_THUMB_L___,         ___MSE_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_ADD] = LAYOUT_btgrant_planck_grid(
        XXXXXXX, ___5ADD_1_L___,                                                           ___5ADD_1_R___, XXXXXXX,
        XXXXXXX, ___5ADD_2_L___,                                                           ___5ADD_2_R___, XXXXXXX,
        XXXXXXX, ___5ADD_3_L___,                                                           ___5ADD_3_R___, XXXXXXX,
        ENC_FUN, XXXXXXX, XXXXXXX,         ___ADD_THUMB_L___,         ___ADD_THUMB_R___, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool achordion_chord_keymap(uint16_t tap_hold_keycode,
                            keyrecord_t* tap_hold_record,
                            uint16_t other_keycode,
                            keyrecord_t* other_record) {

  switch (tap_hold_keycode) {
    case J_SFT:
    case K_GUI:
    case L_ALT: // as of this writing, this is only for the 12u Planck
      switch (other_keycode) {
        case TAB_FUN:
            return true;
      }
  }

  return false;
}

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
