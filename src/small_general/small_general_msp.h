#ifndef _SMALL_GENERAL_MSP
#define _SMALL_GENERAL_MSP

#ifdef SMALL_GENERAL
#include <stm32f0xx_hal.h>

#define A0_PIN                                          GPIO_PIN_0
#define A0_GPIO_PORT                                    GPIOA
#define A1_PIN                                          GPIO_PIN_1
#define A1_GPIO_PORT                                    GPIOA
#define R2D_LED_PIN                                     GPIO_PIN_4
#define R2D_LED_GPIO_PORT                               GPIOA
#define R2D_BTN_NO_PIN                                  GPIO_PIN_5
#define R2D_BTN_NO_GPIO_PORT                            GPIOA
#define R2D_SW_NC_PIN                                   GPIO_PIN_6
#define R2D_SW_NC_GPIO_PORT                             GPIOA
#define R2D_SW_NO_PIN                                   GPIO_PIN_7
#define R2D_SW_NO_GPIO_PORT                             GPIOA
#define SPI_IRQ_PIN                                     GPIO_PIN_0
#define SPI_IRQ_GPIO_PORT                               GPIOB
#define V_SENSE_PIN                                     GPIO_PIN_1
#define V_SENSE_GPIO_PORT                               GPIOB
#define USR_KEY_PIN                                     GPIO_PIN_2
#define USR_KEY_GPIO_PORT                               GPIOB
#define USR_LED_PIN                                     GPIO_PIN_10
#define USR_LED_GPIO_PORT                               GPIOB
#define R8_PIN                                          GPIO_PIN_11
#define R8_GPIO_PORT                                    GPIOB
#define R7_PIN                                          GPIO_PIN_12
#define R7_GPIO_PORT                                    GPIOB
#define R6_PIN                                          GPIO_PIN_13
#define R6_GPIO_PORT                                    GPIOB
#define R5_PIN                                          GPIO_PIN_14
#define R5_GPIO_PORT                                    GPIOB
#define R4_PIN                                          GPIO_PIN_15
#define R4_GPIO_PORT                                    GPIOB
#define R3_PIN                                          GPIO_PIN_8
#define R3_GPIO_PORT                                    GPIOA

void setup_board();

#endif /* SMALL_GENERAL */

#endif /* _SMALL_GENERAL_MSP */
