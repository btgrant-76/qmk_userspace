ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

RGBLIGHT_ENABLE = no
ENCODER_MAP_ENABLE = yes
