// Copyright 2022 haizeus (@haizeus)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* Define encoder pads */
#define ENCODERS_PAD_A { B5, D1 }
//#define ENCODERS_PAD_B { B6, D0 }

/* Encoder resolution */
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10

/* Set 0 if debouncing isn't needed */
#define Debounce 0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
