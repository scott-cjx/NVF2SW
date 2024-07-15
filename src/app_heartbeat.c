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

#include "pkg_common.h"

#if BIGGER_BRAIN && APP_HEARTBEAT
#pragma message "app_heartbeat.c"

#include "app_heartbeat.h"

void task_heartbeat()
{}

void wdg_heartbeat()
{}


#endif /* BIGGER_BRAIN && APP_HEARTBEAT */
