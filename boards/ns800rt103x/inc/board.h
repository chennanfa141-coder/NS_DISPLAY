/**
  * @file       board.h
  * @author     Alex-J
  * @brief      Header file of board.c
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __BOARD_H__
#define __BOARD_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "device.h"

#define HW_MINIBOARD_V1P0    1
#define HW_NSSINEPAD_V1P0    2
#define HW_VERSION           HW_NSSINEPAD_V1P0

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup BOARD_LEDx_PIN Board LEDx PIN
  * @{
  * @brief  Defines configuration macros for board ledx pin.
  */
#if (HW_VERSION == HW_MINIBOARD_V1P0)
  #define BOARD_LED2_PIN    GPIO_25
  #define BOARD_LED3_PIN    GPIO_33
  #define BOARD_LED1_PIN    BOARD_LED3_PIN
#elif (HW_VERSION == HW_NSSINEPAD_V1P0)
  #define BOARD_LED1_PIN    GPIO_44
  #define BOARD_LED2_PIN    GPIO_7
#endif

#define BOARD_GPIO34_PIN    GPIO_34
/**
  * @}
  */

/** @defgroup BOARD_SWITCHx_PIN Board SWITCHx PIN
  * @{
  * @brief  Defines configuration macros for board switchx pin.
  */
#if (HW_VERSION == HW_MINIBOARD_V1P0)
  #define BOARD_S1_PIN    GPIO_21
  #define BOARD_S2_PIN    GPIO_13
  #define BOARD_KEY_PIN   BOARD_S1_PIN
#elif (HW_VERSION == HW_NSSINEPAD_V1P0)
  #define BOARD_KEY_PIN    GPIO_41
#endif

/**
  * @}
  */

/** @defgroup SERIAL_COM_PIN Serial Com port Pins
  * @{
  * @brief  Defines configuration macros for serial com port pin.
  */
#define BOARD_SERIALCOM_TX_PIN    GPIO_29
#define BOARD_SERIALCOM_RX_PIN    GPIO_28

/**
  * @}
  */

#define BOARD_SERIALCOM_BAUDRATE    (115200UL)
#define BOARD_SERIALCOM             UART1


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * \brief  Board Initialization.
 * \note   Call this function in your application if you wish to do all module 
 *         initialization.
 *         If you wish to not use some of the initializations, instead of the 
 *         Board_init use the individual Module_inits.
 */
extern void Board_init (void);

/**
 * \brief  PinMux Initialization.
 * \note   Call this function in your application if you want all 
 *         PinMux initialization to be done.
 */
extern void PinMux_init (void);

/**
 * \brief  Board Serial Communication Interface Initialization.
 * \note   Call this function in the application to initialize the SCI serial port 
 *         on the board for outputting debugging information.
 */
extern void SerialCOM_init(void);

/**
 * \brief  Board LED Initialization.
 * \note   Call this function in the application to initialize the LED 
 *         on the board.
 */
extern void LED_init (void);

/**
 * \brief  Board Switch Initialization.
 * \note   Call this function in the application to initialize the Switch 
 *         on the board.
 */
extern void Switch_init (void);


#ifdef __cplusplus
}
#endif


#endif  /* __BOARD_H__ */
