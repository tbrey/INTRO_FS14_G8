/**
 * \file
 * \brief Platform implementation module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This implements the platform module. 
 * Here the platform gets initialized, and all platform dependent macros get defined.
 */

#include "Platform.h"
#if PL_HAS_LED
  #include "LED.h"
#endif
#if PL_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_HAS_TIMER
  #include "Timer.h"
#endif

#if PL_HAS_LED
static void PL_LedInit(void) {
  /* all LED's off by default */
  #if PL_NOF_LEDS>=1
  LED1_Off();
  #endif
  #if PL_NOF_LEDS>=2
  LED2_Off();
  #endif
  #if PL_NOF_LEDS>=3
  LED3_Off();
  #endif
  #if PL_NOF_LEDS>=4
  LED4_Off();
  #endif
  #if PL_NOF_LEDS>=5
  LED5_Off();
  #endif
}
#endif /* PL_HAS_LED */

#if PL_HAS_LED
static void PL_LedDeinit(void) {
  /* all LED's off by default */
  #if PL_NOF_LEDS>=1
  LED1_Off();
  #endif
  #if PL_NOF_LEDS>=2
  LED2_Off();
  #endif
  #if PL_NOF_LEDS>=3
  LED3_Off();
  #endif
  #if PL_NOF_LEDS>=4
  LED4_Off();
  #endif
  #if PL_NOF_LEDS>=5
  LED5_Off();
  #endif
}
#endif /* PL_HAS_LED */


void PL_Init(void) {
#if PL_HAS_LED
  PL_LedInit();
#endif  
#if PL_HAS_EVENTS
  EVNT_Init();
#endif
#if PL_HAS_TIMER
  TMR_Init();
#endif
}

void PL_Deinit(void) {
#if PL_HAS_EVENTS
  EVNT_Deinit();
#endif
#if PL_HAS_LED
  PL_LedDeinit();
#endif
#if PL_HAS_TIMER
  TMR_Deinit();
#endif
}
