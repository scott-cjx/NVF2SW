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

#ifndef _PKG_R2D
#define _PKG_R2D

#include "pkg.h"
#if PKG_R2D && SMALL_GENERAL

#include "canbus.h"
#include "app_r2d.h"

void setup_pkg();
void task_pkg();
void cb_tim_pkg(TIM_HandleTypeDef *htim);
void cb_can_pkg(canbus_msg rxmsg);

#endif /* PKG_R2D && SMALL_GENERAL */

#endif /* _PKG_R2D */
