/*
 * Copyright (C) 2024 Scott CJX
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

// #if APP_HEARTBEAT
//     #include "app_heartbeat.h"
// #endif /* APP_HEARTBEAT */

// #if APP_PDL
//     #include "app_pdl.h"
// #endif /* APP_PDL */

// #if APP_R2D
//     #include "small_general/app_r2d.h"
// #endif /* APP_R2D */

// #if APP_MC
//     #include "app_mc.h"
// #endif /* APP_MC */

// #if APP_DB
//     #include "app_db.h"
// #endif /* APP_DB */

#if PKG_R2D
    #include "small_general/pkg_r2d.h"
#endif /* PKG_R2D */

void setup_pkg();

#endif /* _PKG */
