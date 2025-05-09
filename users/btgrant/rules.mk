SRC += btgrant.c
SRC += macros.c
SRC += features/achordion.c

ifeq ($(strip $(THUMB_SWAP)), yes)
OPT_DEFS += -DTHUMB_SWAP
  $(info swapping thumbs)
else
  $(info default thumbs)
endif

DYNAMIC_TAPPING_TERM_ENABLE = no
NKRO_ENABLE	= no

CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = no

LEADER_ENABLE = yes

# start space-savings
# https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
# AVR_USE_MINIMAL_PRINTF = yes  # crkbd & cocot46plus need these features for OLED text formatting
MOUSEKEY_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
#KEY_OVERRIDE_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no
# end space-savings
