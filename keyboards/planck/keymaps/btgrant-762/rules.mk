USER_NAME := btgrant

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
RGBLIGHT_ENABLE = no
ENCODER_MAP_ENABLE = yes
COMBO_ENABLE = yes
