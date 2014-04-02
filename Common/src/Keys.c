/**
 * \file
 * \brief Key/Switch driver implementation.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements a generic keyboard driver for up to 4 Keys.
 * It is using macros for maximum flexibility with minimal code overhead.
 */

#include "Platform.h"
#if PL_HAS_KEYS
  #include "Keys.h"
#if PL_HAS_EVENTS
  #include "Event.h"
#endif

void KEY_Scan(void) {
  /*! \todo Implement handling of keys */
#if PL_NOF_KEYS > 0
	if (KEY1_Get()) {
		WAIT1_Waitms(50); /* simple debounce */
		if (KEY1_Get()) { /* still pressed? */
			EVNT_SetEvent(EVNT_SW1_PRESSED);
			WAIT1_Waitms(200);
		}
	}
#endif
#if PL_NOF_KEYS > 1
	if (KEY2_Get()) {
		WAIT1_Waitms(50); /* simple debounce */
		if (KEY2_Get()) { /* still pressed? */
			EVNT_SetEvent(EVNT_SW2_PRESSED);
			WAIT1_Waitms(200);
		}
	}
#endif
#if PL_NOF_KEYS > 2
	if (KEY3_Get()) {
		WAIT1_Waitms(50); /* simple debounce */
		if (KEY3_Get()) { /* still pressed? */
			EVNT_SetEvent(EVNT_SW3_PRESSED);
		}
	}
#endif
#if PL_NOF_KEYS > 3
	if (KEY4_Get()) {
		WAIT1_Waitms(50); /* simple debounce */
		if (KEY4_Get()) { /* still pressed? */
			EVNT_SetEvent(EVNT_SW4_PRESSED);
		}
	}
#endif
}

#if PL_HAS_KBI
void KEY_OnInterrupt(void) {
  KEY_Scan();
}
#endif

/*! \brief Key driver initialization */
void KEY_Init(void) {
  /* nothing needed for now */
}

/*! \brief Key driver de-initialization */
void KEY_Deinit(void) {
  /* nothing needed for now */
}
#endif /* PL_HAS_KEYS */
