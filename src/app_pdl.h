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

#ifndef _APP_PDL
#define _APP_PDL

#include "pkg_common.h"

#if APP_PEDAL

    /**
     * @ref PDL Readings
     */
    #define PDL_THR1                        (uint8_t) 0
    #define PDL_THR2                        (uint8_t) 1
    #define PDL_THR3                        (uint8_t) 2
    #define PDL_BRP1                        (uint8_t) 3
    #define PDL_BRP2                        (uint8_t) 4
    #define PDL_BRS1                        (uint8_t) 5
    #define PDL_BRS2                        (uint8_t) 6
    #define PDL_NCN                         (uint8_t) -1

    const uint8_t SENS_PDL_1[4] = {
        PDL_THR1,
        PDL_NCN,
        PDL_NCN,
        PDL_NCN
    };

    const uint8_t SENS_PDL_2[4] = {
        PDL_THR2,
        PDL_BRP1,
        PDL_NCN,
        PDL_NCN
    };

    const uint8_t SENS_PDL_3[4] = {
        PDL_THR3,
        PDL_BRP2,
        PDL_BRS1,
        PDL_BRS2
    };

    const uint8_t* SENS_PDL[3] = {
        SENS_PDL_1,
        SENS_PDL_2,
        SENS_PDL_3,
    };

    void setup_pedal();
    void task_pedal();
    void wdg_pedal();

    #if SMALL_GENERAL
    
    #elif BIGGER_BRAIN

    #endif
#endif /* APP_PEDAL */

#endif /* _APP_PDL */
