#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X // accommodate the curved overlay

// all modes
// #define CIRQUE_PINNACLE_TAP_ENABLE
// #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

// absolute mode
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
// #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE

// relative mode
//#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
//#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE // only available in relative mode

 /* TAPPING_TERM value is used for the CIRQUE_PINNACLE_TAPPING_TERM as well by default
  * defining it this way allows us to easily modify it with DYNAMIC_TAPPING_TERM_ENABLE
  */
#undef TAPPING_TERM
#define TAPPING_TERM 0
