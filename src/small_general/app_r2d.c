
#include "pkg.h"
#if PKG_R2D && SMALL_GENERAL
#pragma message "sg app_r2d.c"

#include "app_r2d.h"
#include "canbus.h"

#include <stdint.h>
#include <stdbool.h>

uint8_t activate_counter = 0;                                       // used to check duration sequence performed
uint8_t state_counter = 0;                                          // used to toggle led, depends on wdg freq + counter thrh
R2D_STATE r2d_state = STATE_DEACTIVE;                               // handled by can cb
R2D_STATE_REPORT r2d_state_rpt = RPT_NOCHANGE;                      // handled by task_r2d
bool sw_nc = 0;
bool sw_no = 0;
bool btn_no = 0;

void __get_r2d_trig()
{
    // once again, assert that r2s_state is ready
    if (r2d_state != STATE_READY) return;

    // if seq done for thrh and longer, continue sending active report; 
    // user should perform for as long as led is still flashing
    if(activate_counter >= R2D_BTN_COUNTER_THRH)
    {
        r2d_state_rpt = RPT_ACTIVE;
    }
}

void __get_r2d_vals()
{
    // by default, no change
    r2d_state_rpt = RPT_NOCHANGE;

    sw_nc = HAL_GPIO_ReadPin(R2D_SW_NC_GPIO_PORT, R2D_SW_NC_PIN);
    sw_no = HAL_GPIO_ReadPin(R2D_SW_NO_GPIO_PORT, R2D_SW_NO_PIN);
    btn_no = HAL_GPIO_ReadPin(R2D_BTN_NO_GPIO_PORT, R2D_BTN_NO_PIN);

    if (sw_nc == sw_no)
    // if scs check failed, rpt err
    {
        r2d_state_rpt = RPT_ERR;
    }

    if (r2d_state == STATE_ACTIVE && (sw_nc))
    // if state is active and switch is turned off, report deactivate 
    // until vcu changes state to deactivated
    {
        r2d_state_rpt = RPT_DEACTIVE;
    }

    if (sw_no && btn_no && (r2d_state == STATE_READY))       // ready and seq
    // if sw_no and btn both closed, counter++, else reset counter
    {
        // sequence in progress
        activate_counter++;
        __get_r2d_trig();           // check if activate counter 
    }
    else
    {
        // sequence not performed
        activate_counter = 0;
        return;
    }
}

void __get_r2d_rpt()
{
    // prep can message and send
}

void task_r2d()
{
    // get vals
    __get_r2d_vals();

    // report status

}

void cb_can_r2d(canbus_msg rxmsg)
{
    // if message is to report r2d status
}

void __tog_r2d_light(uint8_t *counter)
{
    // if counter is max or more, toggle and set to 0
    /**
     * && lostc not implemented
     * possible scenarios:
     * 1. JUST this cycle state changed to READY/ LOSTC        => counter++
     * 2. not first cycle state is READY/ LOSTC                => counter++ until threshold then toggle and set counter = 0
     * 3. JUST this cycle state changed from READY/ LOSTC      => they will set counter = 0
     */
    if((*counter) >= R2D_LED_READY_COUNTER_THRH)
    {
        HAL_GPIO_TogglePin(R2D_LED_GPIO_PORT, R2D_LED_PIN);
        (*counter) = 0;
    }
    (*counter)++;
}

void wdg_r2d_light()
{
    switch (r2d_state)
    {
    case STATE_READY:
    case STATE_LOSTC:
        // toggle light and handle counter
        __tog_r2d_light(&state_counter);
        return;
    case STATE_DEACTIVE:
        // turn off led
        HAL_GPIO_WritePin(R2D_LED_GPIO_PORT, R2D_LED_PIN, 0);
        break;
    case STATE_ACTIVE:
        // turn on led
        HAL_GPIO_WritePin(R2D_LED_GPIO_PORT, R2D_LED_PIN, 1);
        break;
    }

    // set counter to 0.
    state_counter = 0;
}

#endif /* PKG_R2D && SMALL_GENERAL */