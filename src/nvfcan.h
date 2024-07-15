#ifndef _NVFCAN
#define _NVFCAN

#include <stdint.h>

#define CANID_VCU                   (uint32_t) 0x010
#define CANID_MCC                   (uint32_t) 0x011
#define CANID_DBL                   (uint32_t) 0x021
#define CANID_DBR                   (uint32_t) 0x022
#define CANID_DBR2D                 (uint32_t) 0x023
#define CANID_THR1                  (uint32_t) 0x031
#define CANID_THR2                  (uint32_t) 0x032
#define CANID_THR3                  (uint32_t) 0x032

#define CANID_MCCN_MCC              (uint32_t) 0x03C
#define CANID_MCCN_MC               (uint32_t) 0x011

enum MSGT_ID
{
    ACKNOWLEDGE = 0x00,
    REGISTER,
    REPORT_CAR_METRIC,
    CANID_IMPLAU,
    REPORT_R2D_STATE,
    REPORT_R2D_SENS1,           // DBL -> VCU (R2DN) R2DSW OFF Trigger
};

#endif /* _NVFCAN */
