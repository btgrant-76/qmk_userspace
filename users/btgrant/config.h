/*
This is the c configuration file for the keymap

Copyright 2025 Brian Grant

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#undef PERMISSIVE_HOLD
#undef RETRO_TAPPING
#undef TAPPING_FORCE_HOLD
#undef TAPPING_TERM

#define TAPPING_TERM 145
#define TAPPING_TERM_DECREASE_SHIFT 40
#define TAPPING_TERM_PER_KEY
#define CHORDAL_HOLD

/* settings for use with permissive hold */
#define PERMISSIVE_HOLD
#undef TAPPING_TERM_PER_KEY

#undef TAPPING_TERM
#define TAPPING_TERM 250
#undef TAPPING_TERM_DECREASE_SHIFT
#define TAPPING_TERM_DECREASE_SHIFT 0
/* */

// Mouse Keys
#define MK_KINETIC_SPEED // use MK_3_SPEED if builds are too large

// start QMK squeezing
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT
// end QMK squeezing

// Caps Word
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 2000  // 2 seconds

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 120
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_TIMEOUT_PER_KEY

// leader key
#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
