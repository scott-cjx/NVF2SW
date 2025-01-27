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

#ifndef _APP_R2D
#define _APP_R2D

#if PKG_R2D

#include <stdint.h>

typedef enum R2D_STATE
{
    STATE_ACTIVE,
    STATE_DEACTIVE,
    STATE_READY,
    STATE_LOSTC,
} R2D_STATE;

typedef enum R2D_STATE_REPORT
{
    RPT_ACTIVE,
    RPT_DEACTIVE,
    RPT_NOCHANGE,
    RPT_ERR = (uint8_t) -1
} R2D_STATE_REPORT;

#if SMALL_GENERAL
    // wdg task is at 20Hz
    #define R2D_BTN_COUNTER_THRH                                30      // f = 1/20 * 30 = 1500ms   (press and hold for 1500ms)
    #define R2D_LED_READY_COUNTER_THRH                          10      // f = 1/20 * 10 = 2Hz      (toggle every 500ms)
    #define R2D_LED_LOSTC_COUNTER_THRH                          30      // f = 1/20 * 30 = 1500ms   (toggle every 1500ms)

    void task_r2d();
    void cb_can_r2d(canbus_msg rxmsg);
    void __tog_r2d_light(uint8_t *counter);
    void wdg_r2d_light();

    #endif /* SMALL_GENERAL */
#endif /* PKG_R2D */

#endif /* _APP_R2D */
