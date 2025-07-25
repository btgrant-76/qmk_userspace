#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses

    #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255

    #undef RGB_MATRIX_DEFAULT_VAL
    #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set

    #undef RGB_MATRIX_DEFAULT_MODE
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_PIXEL_RAIN
    #undef RGB_MATRIX_DEFAULT_SPD
#endif

#ifdef TRY_CHORDAL_HOLD
    #define CHORDAL_HOLD
#endif
