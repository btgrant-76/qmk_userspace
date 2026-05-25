# MCU name
MCU = STM32F072

# Bootloader selection
BOOTLOADER = stm32-dfu

COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = no

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = yes            # Enable N-Key Rollover
LTO_ENABLE = yes
ALLOW_WARNINGS = yes
SPLIT_KEYBOARD = yes
