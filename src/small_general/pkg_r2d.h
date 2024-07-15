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
