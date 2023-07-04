SRC += btgrant-76.c
SRC += features/achordion.c

DYNAMIC_TAPPING_TERM_ENABLE = yes
TAP_DANCE_ENABLE = yes
NKRO_ENABLE		= no

CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = no

LEADER_ENABLE = yes

# start space-savings
# https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
LTO_ENABLE      = yes
# AVR_USE_MINIMAL_PRINTF = yes  # crkbd & cocot46plus need these features for OLED text formatting
MOUSEKEY_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_OVERRIDE_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no
# end space-savings
