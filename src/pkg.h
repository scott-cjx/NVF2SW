#ifndef _PKG
#define _PKG

#include "pkg_common.h"

#if BIGGER_BRAIN
    #include "stm32h7xx_hal.h"
    #include "bigger_brain/bigger_brain_msp.h"

#elif SMALL_GENERAL
    #include "stm32f0xx_hal.h"
    #include "small_general/small_general_msp.h"

#endif /* BOARD */

#if APP_HEARTBEAT
    #include "app_heartbeat.h"
#endif /* APP_HEARTBEAT */

#if APP_PDL
    #include "app_pdl.h"
#endif /* APP_PDL */

#if APP_R2D
    // #include "app_r2d.h"
#endif /* APP_R2D */

#if APP_MC
    #include "app_mc.h"
#endif /* APP_MC */

#if APP_DB
    #include "app_db.h"
#endif /* APP_DB */


#if PKG_R2D
    #include "pkg_r2d.h"
#endif /* PKG_R2D */

void setup_pkg();

#endif /* _PKG */
