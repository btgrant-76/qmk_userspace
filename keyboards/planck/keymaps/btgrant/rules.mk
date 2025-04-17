ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

RGBLIGHT_ENABLE = no
ENCODER_MAP_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = no
