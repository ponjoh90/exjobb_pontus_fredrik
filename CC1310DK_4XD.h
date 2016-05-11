/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       Board.h
 *
 *  @brief      CC1310EM_4XD Board Specific header file.
 *              The project options should point to this file if this is the
 *              CC1310EM you are developing code for.
 *
 *  The CC1310 header file should be included in an application as follows:
 *  @code
 *  #include <Board.h>
 *  @endcode
 *
 *  ============================================================================
 */
#ifndef __CC1310EM_4XD_H__
#define __CC1310EM_4XD_H__

#ifdef __cplusplus
extern "C" {
#endif

/** ============================================================================
 *  Symbol by generic Board.c to include the correct kit specific Board.c
 *  ==========================================================================*/
#define CC1310EM_4XD

/** ============================================================================
 *  Includes
 *  ==========================================================================*/
#include <ti/drivers/PIN.h>
#include <driverlib/ioc.h>

/** ============================================================================
 *  Externs
 *  ==========================================================================*/
extern const PIN_Config BoardGpioInitTable[];

/** ============================================================================
 *  Defines
 *  ==========================================================================*/

/* Mapping of pins to board signals using general board aliases
 *      <board signal alias>                <pin mapping>
 */
///* Leds */
//#define Board_LED_ON                        1 /* LEDs on CC1310 are active high */
//#define Board_LED_OFF                       0
//#define Board_DK_LED1                       PIN_UNASSIGNED
//#define Board_DK_LED2                       PIN_UNASSIGNED
//#define Board_DK_LED3                       IOID_5          /* P1.2  */
//#define Board_DK_LED4                       IOID_6          /* P1.4  */
///* Button Board */
//#define Board_KEY_SELECT                    IOID_7          /* P1.14 */
//#define Board_KEY_UP                        IOID_4          /* P1.10 */
//#define Board_KEY_DOWN                      IOID_3          /* P1.12 */
//#define Board_KEY_LEFT                      PIN_UNASSIGNED
//#define Board_KEY_RIGHT                     PIN_UNASSIGNED
///* LCD  Board */
//#define Board_3V3_EN                        PIN_UNASSIGNED
//#define Board_LCD_MODE                      PIN_UNASSIGNED
//#define Board_LCD_RST                       PIN_UNASSIGNED
//#define Board_LCD_CSN                       PIN_UNASSIGNED
///* UART Board */
//#define Board_UART_RX                       IOID_1          /* P1.7  */
//#define Board_UART_TX                       IOID_2          /* P1.9  */
//#define Board_UART_CTS                      PIN_UNASSIGNED
//#define Board_UART_RTS                      PIN_UNASSIGNED
///* SPI Board */
//#define Board_SPI0_MISO                     IOID_0          /* P1.20 */
//#define Board_SPI0_MOSI                     IOID_9          /* P1.18 */
//#define Board_SPI0_CLK                      IOID_8          /* P1.16 */
//#define Board_SPI0_CSN                      PIN_UNASSIGNED

//Namndefinitioner
/* Mapping of pins to board signals using general board aliases
 *      <board signal alias>                <pin mapping>
 */
/* SPI  */
#define PIN_SPI_CLK                     	IOID_0         	/* P1.8 */
#define PIN_SPI_MISO                    	IOID_1          /* P1.9 */
#define PIN_SPI_MOSI                    	IOID_2          /* P1.10 */
#define PIN_SPI_CSN                     	PIN_UNASSIGNED  /* P1.14, separate CSn for LCD, SDCARD, and ACC */
#define PIN_SPI_SS                     		IOID_5          /* P1.22 */

/* JTAG */
#define PIN_JTAG_TD0                    	IOID_3          /* P1.15 */
#define PIN_JTAG_TD1                    	IOID_4          /* P1.16 */

/* ACCELEROMETER */
#define PIN_ACC_Z                    		IOID_6          /* P1.23 */
#define PIN_ACC_X                    		IOID_7          /* P1.24 */
#define PIN_ACC_Y                    		IOID_8          /* P1.25 */

/* SWITCH MELLAN T�JNINGSGIVARE OCH T�MMA CAP */
#define PIN_SWITCH_9                    	IOID_9          /* P1.26 */


/** ============================================================================
 *  Instance identifiers
 *  ==========================================================================*/
/* Generic SPI instance identifiers */
#define Board_SPI0                  CC1310DK_4XD_SPI0
/* Generic UART instance identifiers */
#define Board_UART                  CC1310DK_4XD_UART0
/* Generic Crypto instance identifiers */
#define Board_CRYPTO                CC1310DK_4XD_CRYPTO0

/** ============================================================================
 *  Number of peripherals and their names
 *  ==========================================================================*/

/*!
 *  @def    CC1310DK_4XD_CryptoName
 *  @brief  Enum of Crypto names on the CC1310 dev board
 */
typedef enum CC1310DK_4XD_CryptoName {
    CC1310DK_4XD_CRYPTO0 = 0,
    CC1310DK_4XD_CRYPTOCOUNT
} CC1310DK_4XD_CryptoName;

/*!
 *  @def    CC1310DK_4XD_SPIName
 *  @brief  Enum of SPI names on the CC1310 dev board
 */
typedef enum CC1310DK_4XD_SPIName {
    CC1310DK_4XD_SPI0 = 0,
    CC1310DK_4XD_SPICOUNT
} CC1310DK_4XD_SPIName;

/*!
 *  @def    CC1310DK_4XD_UARTName
 *  @brief  Enum of UARTs on the CC1310 dev board
 */
typedef enum CC1310DK_4XD_UARTName {
    CC1310DK_4XD_UART0 = 0,
    CC1310DK_4XD_UARTCOUNT
} CC1310DK_4XD_UARTName;

/*!
 *  @def    CC1310DK_4XD_UdmaName
 *  @brief  Enum of DMA buffers
 */
typedef enum CC1310DK_4XD_UdmaName {
    CC1310DK_4XD_UDMA0 = 0,
    CC1310DK_4XD_UDMACOUNT
} CC1310DK_4XD_UdmaName;

#ifdef __cplusplus
}
#endif

#endif /* __CC1310EM_H__ */