#include "pkg_r2d.h"

#if PKG_R2D && SMALL_GENERAL
#pragma message "pkg_r2d.c"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    cb_tim_pkg(htim);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	static CAN_RxHeaderTypeDef rxHeader;
       
}

void setup_pkg()
{
    // setup_can();
}

void task_pkg()
{

}

void cb_tim_app(TIM_HandleTypeDef *htim)
{
    // 
    if(0) {}
    else if(htim->Instance == TIM16)
    {
        task_pkg();
    }
}

void cb_can_pkg(CAN_HandleTypeDef *hcan)
{

}

#endif /* PKG_R2D && SMALL_GENERAL */
