#pragma once

#include_next <mcuconf.h>

// Can only enable one of the below. Comment out the unused RGB system.

// settings for RGB Matrix
#undef STM32_PWM_USE_TIM16
#define STM32_PWM_USE_TIM16 TRUE
#define STM32_TIM16_SUPPRESS_ISR
#define WS2812_PWM_DRIVER PWMD16
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL 1

// settings for RGB Light
//#undef STM32_PWM_USE_TIM17
//#define STM32_PWM_USE_TIM17 TRUE
//#define STM32_TIM17_SUPPRESS_ISR
//#define WS2812_PWM_DRIVER PWMD17
//#define WS2812_PWM_CHANNEL 1
//#define WS2812_PWM_PAL_MODE 2
//#define WS2812_DMA_STREAM STM32_DMA1_STREAM1
//#define WS2812_DMA_CHANNEL 1
