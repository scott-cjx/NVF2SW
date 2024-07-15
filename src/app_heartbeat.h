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

#ifndef _APP_HEARTBEAT
#define _APP_HEARTBEAT

#if APP_HEARTBEAT
#include "nvfcan.h"

#define NBR_CAN_INST                3
#define MAX_NODES_P_NETWORK         8

const uint32_t VCUN_NODES[MAX_NODES_P_NETWORK] = {
    CANID_VCU,      // VCU      trx     => R2D State & Node Realibilty & Car Metrics
    CANID_MCC,      // MCC      trx     => agg throttle, using which
    CANID_DBL,      // DB_L     rx
    CANID_DBR,      // DB_R     rx
};

const uint32_t R2DN_NODES[MAX_NODES_P_NETWORK] = {
    CANID_VCU,      // VCU      trx     => R2D State & Node Realibilty & Car Metrics
    CANID_DBL,      // DB_L     rx      => R2D Trigger
};

const uint32_t PDLN_NODES[MAX_NODES_P_NETWORK] = {
    CANID_VCU,      // VCU      rx
    CANID_MCC,      // MCC      rx
    CANID_THR1,     // THR_1    tx      => Thr Request 1
    CANID_THR2,     // THR_2    tx      => Thr Request 2, Brake Pres 1
    CANID_THR3,     // THR_3    tx      => Thr Request 3, Brake Pres 2, Brake SW Trig
};

const uint32_t* ALL_NODES[NBR_CAN_INST] = {
    VCUN_NODES,     // CAN INST 1
    R2DN_NODES,     // CAN INST 2
    PDLN_NODES      // CAN INST 3
};
#endif /* APP_HEARTBEAT */

#endif /* _APP_HEARTBEAT */
