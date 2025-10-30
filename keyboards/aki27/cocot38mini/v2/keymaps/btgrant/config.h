#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 6

#define AUTO_MOUSE_TIME 350
// #define AUTO_MOUSE_DELAY 200 // Lockout time after non-mouse key is pressed
// #define AUTO_MOUSE_DEBOUNCE 25 // Time delay from last activation to next update

#ifdef RGB_MATRIX_ENABLE
  #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#endif
