COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = no

# MCU name
MCU = STM32F072 # already defined in keyboard.json

# Bootloader selection
BOOTLOADER = stm32-dfu # already defined in keyboard.json

# Build Options
#   change yes to no to disable
#
# TODO test out the ones that are already defined in keyboard.json
# BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite # already defined in keyboard.json
EXTRAKEY_ENABLE = yes       # Audio control and System control # TODO verify that I need this
# NKRO_ENABLE = yes            # Enable N-Key Rollover # already defined in keyboard.json
LTO_ENABLE = yes # TODO verify that I need this; the firmware size is definitely smaller with it enabled
ALLOW_WARNINGS = yes # TODO verify that I need this;  without this, compiler warnings are treated as errors
# SPLIT_KEYBOARD = yes # already defined in keyboard.json
