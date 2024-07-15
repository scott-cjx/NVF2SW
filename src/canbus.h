#ifndef _CANBUS
#define _CANBUS

#include <stdint.h> // uint32_t

typedef struct __canbus_msg {
	uint32_t ts_rx;
	uint32_t ts_tx;
    uint32_t id;
    uint32_t dlc;
    union {
        uint8_t data[8];
        uint32_t data32[2];
    };
    uint8_t which_can;
} canbus_msg;

#endif /* _CANBUS */