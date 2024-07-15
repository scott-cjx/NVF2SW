#include "small_general/pkg_r2d.h"

#if PKG_R2D && SMALL_GENERAL
#pragma message "pkg_r2d.c"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    cb_tim_pkg(htim);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    static CAN_RxHeaderTypeDef rxHeader;
    canbus_msg rxmsg;
    
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rxHeader, rxmsg.data);
    rxmsg.dlc = rxHeader.DLC;
    rxmsg.canid_type = rxHeader.IDE;
    if (rxmsg.canid_type == CAN_ID_STD)
    {
        rxmsg.id = rxHeader.StdId;
    }
    else
    {
        rxmsg.id = rxHeader.ExtId;
    }
    
    rxmsg.ts_rx = rxHeader.Timestamp;

    cb_can_pkg(rxmsg);
}

void setup_pkg()
{
    // setup_can();
}

void task_pkg()
{
    task_r2d();
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

void cb_can_pkg(canbus_msg rxmsg)
{

}

#endif /* PKG_R2D && SMALL_GENERAL */
