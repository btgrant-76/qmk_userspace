SRC += btgrant-76.c

DYNAMIC_TAPPING_TERM_ENABLE = yes
TAP_DANCE_ENABLE = yes
NKRO_ENABLE		= yes
LTO_ENABLE      = yes

CAPS_WORD_ENABLE = yes

# start space-savings
# AVR_USE_MINIMAL_PRINTF = yes  # crkbd & cocot46plus need these features for OLED text formatting
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_OVERRIDE_ENABLE = no
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no
# end space-savings
