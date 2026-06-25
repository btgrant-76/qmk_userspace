ifeq ($(strip $(FIVE_COL)), yes)
OPT_DEFS += -DFIVE_COL
  $(info FIVE_COL defined)
else
  $(info FIVE_COL not defined)
endif

CONVERT_TO = helios

COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
MOUSEKEY_ENABLE = yes
RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight.
TAP_DANCE_ENABLE = no

ifdef FIVE_COL
  OLED_ENABLE = no
else
  OLED_ENABLE = yes
  RGB_MATRIX_ENABLE = yes
endif
