USER_NAME := btgrant-76

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
RGBLIGHT_ENABLE = no
ENCODER_MAP_ENABLE = no
COMBO_ENABLE = yes
