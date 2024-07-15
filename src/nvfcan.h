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
