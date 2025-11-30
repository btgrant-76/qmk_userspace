ifeq ($(strip $(FOUR_THUMBS)), yes)
    OPT_DEFS += -DFOUR_THUMBS
endif

ifdef FOUR_THUMBS
  COMBO_ENABLE = yes
endif

KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = no
