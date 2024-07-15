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

#ifndef _PKG_COMMON
#define _PKG_COMMON

#include "nvfcan.h"

#include <stdint.h>

/**
 * @ref CanBus Networks
 */
#define CANN_VCUN                           (uint8_t) 0
#define CANN_PDLN                           (uint8_t) 1
#define CANN_R2DN                           (uint8_t) 2
#define CANN_MCCN                           (uint8_t) 3
#define CANN_AMSN                           (uint8_t) 4
#define CANN_NCN                            (uint8_t) -1

#if BIGGER_BRAIN
    #if PKG_VCU
        #define APP_HEARTBEAT               1
        #define APP_R2D                     1

        #define CAN1_NETWORK                CANN_VCUN
        #define CAN1_ID                     CANID_VCU
        #define CAN2_NETWORK                CANN_PDLN
        #define CAN2_ID                     CANID_VCU
        #define CAN3_NETWORK                CANN_R2DN
        #define CAN3_ID                     CANID_VCU

    #elif PKG_MCC
        #define APP_PDL                     1
        #define APP_MCC                     1

        #define CAN1_NETWORK                CANN_VCUN
        #define CAN1_ID                     CANID_MCC
        #define CAN2_NETWORK                CANN_PDLN
        #define CAN2_ID                     CANID_MCC
        #define CAN3_NETWORK                CANN_MCCN
        #define CAN3_ID                     CANID_MCCN_MCC

    #elif PKG_AMSC
        #define APP_AMC                     1

        #define CAN1_NETWORK                CANN_VCUN
        #define CAN1_ID                     CANID_AMSC
        #define CAN2_NETWORK                CANN_AMSN
        #define CAN2_ID                     CANID_AMSC
        #define CAN3_NETWORK                CANN_NCN
        #define CAN3_ID                     CANID_AMSC
        
    #endif /* PKG */
#elif SMALL_GENERAL
    #if PKG_R2D
        #define APP_R2D                     1
        #define CAN_NETWORK                 CANN_R2DN
        #define CAN_ID                      CANID_DBR2D

    #elif PKG_PDL
        #define APP_PDL                     1
        #define CAN_NETWORK                 CANN_PDLN

        #if (PDL_ID == 1)
            #define CAN_ID                  CANID_PDL1
        #elif (PDL_ID == 2)
            #define CAN_ID                  CANID_PDL2
        #elif (PDL_ID == 3)
            #define CAN_ID                  CANID_PDL3
        #endif /* PDL_ID */

    #elif PKG_DB
        #define APP_DB                      1
        #define CAN_NETWORK                 CANN_VCUN

        #if (DB_ID == 1)
            #define CAN_ID                  CANID_DBL

        #elif (DB_ID == 2)
            #define CAN_ID                  CANID_DBR

        #endif /* DB_ID */

    #endif /* PKG */
#endif /* BOARD */

#endif /* _PKG_COMMON */
