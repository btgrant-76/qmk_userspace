# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
ENCODER_ENABLE = yes
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = yes

CUSTOM_MATRIX = lite
SRC += matrix.c

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = adns5050

OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306

# Disable unnecessary functions to reduce firmware size
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
