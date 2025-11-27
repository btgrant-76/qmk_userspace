#!/usr/bin/env sh

node ./export_keymap.js
keymap draw keymap-drawer-3x5x3.yaml > ../assets/kd-3-5-3.svg
keymap draw keymap-drawer-3x5x2.yaml > ../assets/kd-3-5-2.svg
