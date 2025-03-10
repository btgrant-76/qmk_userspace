// Copyright 2025 Brian Grant <@btgrant-76>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "btgrant.h"
#include "combos.h"
#include "encoder_map.h"
#include "encoder_press.h"
#include "key_overrides.h"
#include "tap_dances.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_btgrant_vault_katana(
  //|--------------------------------------------|--------|--------------------------------------------|
                                  ___5BASE_1_L___,                                      ___5BASE_1_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                  ___5BASE_2_L___,                                      ___5BASE_2_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                  ___5BASE_3_L___,ENC_BASE,                             ___5BASE_3_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        ESC_FUN, TAB_MSE, BS_NUM,           SPC_NAV, DEL_MSE, ENT_SYM
                    //|--------+--------+--------+--------+--------+--------+--------|
  ),
  [_NUM] = LAYOUT_btgrant_vault_katana(
  //|--------------------------------------------|--------|--------------------------------------------|
                                   ___5NUM_1_L___,                                       ___5NUM_1_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5NUM_2_L___,                                       ___5NUM_2_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5NUM_3_L___, ENC_NUM,                              ___5NUM_3_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX, XXXXXXX,          KC_MINS,    KC_0, DOT_TD
                    //|--------+--------+--------+--------+--------+--------+--------|
  ),
  [_SYM] = LAYOUT_btgrant_vault_katana(
  //|--------------------------------------------|--------|--------------------------------------------|
                                   ___5SYM_1_L___,                                       ___5SYM_1_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5SYM_2_L___,                                       ___5SYM_2_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5SYM_3_L___, ENC_SYM,                              ___5SYM_3_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        XXXXXXX, KC_MUTE, KC_MPLY,         LPRN_MSE, XXXXXXX, KC_RPRN
                    //|--------+--------+--------+--------+--------+--------+--------|
  ),
  [_NAV] = LAYOUT_btgrant_vault_katana(
  //|--------------------------------------------|--------|--------------------------------------------|
                                   ___5NAV_1_L___,                                       ___5NAV_1_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5NAV_2_L___,                                       ___5NAV_2_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5NAV_3_L___, ENC_NAV,                              ___5NAV_3_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
                    //|--------+--------+--------+--------+--------+--------+--------|
  ),
  [_FUN] = LAYOUT_btgrant_vault_katana(
  //|--------------------------------------------|--------|--------------------------------------------|
                                   ___5FUN_1_L___,                                       ___5FUN_1_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5FUN_2_L___,                                       ___5FUN_2_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5FUN_3_L___, ENC_FUN,                              ___5FUN_3_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX,MO(_MSE),         MO(_ADD), XXXXXXX, XXXXXXX
                    //|--------+--------+--------+--------+--------+--------+--------|
  ),
  [_MSE] = LAYOUT_btgrant_vault_katana(
  //|--------------------------------------------|--------|--------------------------------------------|
                                   ___5MSE_1_L___,                                       ___5MSE_1_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5MSE_2_L___,                                       ___5MSE_2_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5MSE_3_L___, ENC_MSE,                              ___5MSE_3_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
                    //|--------+--------+--------+--------+--------+--------+--------|
  ),
  [_ADD] = LAYOUT_btgrant_vault_katana(
  //|--------------------------------------------|--------|--------------------------------------------|
                                   ___5ADD_1_L___,                                       ___5ADD_1_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5ADD_2_L___,                                       ___5ADD_2_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                                   ___5ADD_3_L___, ENC_ADD,                              ___5ADD_3_R___,
  //|--------+--------+--------+--------+--------|--------|--------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
                    //|--------+--------+--------+--------+--------+--------+--------|
  )
};
