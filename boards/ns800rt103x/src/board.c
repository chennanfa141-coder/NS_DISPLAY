/**
  * @file       board.c
  * @author     Havenx-X
  * @brief      Board setup for NS800RTxxx examples.
  * 
  * @note       Board Configurations
  *             Initializes the rest of the modules. 
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * @brief  Board Initialization.
 * @note   Call this function in your application if you wish to do all module 
 *         initialization.
 *         If you wish to not use some of the initializations, instead of the 
 *         Board_init use the individual Module_inits.
 */
void Board_init (void)
{
    PinMux_init();
//    SerialCOM_init();
    LED_init();
//    Switch_init();
}

/**
 * @brief  PinMux Initialization.
 * @note   Call this function in your application if you want all 
 *         PinMux initialization to be done.
 */
void PinMux_init (void)
{
    /* Configure GPIO pins for SCI_COM. */
    GPIO_setPinConfig(GPIO_29_SCIA_TX);
    GPIO_setPinConfig(GPIO_28_SCIA_RX);

  #if (HW_VERSION == HW_MINIBOARD_V1P0)
    /* Configure GPIO pins for LED2 and LED3. */
    GPIO_setPinConfig(GPIO_25_GPIO25);
    GPIO_setPinConfig(GPIO_33_GPIO33);

    /* Configure GPIO pins for S1 and S2. */
    GPIO_setPinConfig(GPIO_21_GPIO21);
    GPIO_setPinConfig(GPIO_13_GPIO13);

  #elif (HW_VERSION == HW_NSSINEPAD_V1P0)
    /* Configure GPIO pins for LED1 and LED2. */
    GPIO_setPinConfig(GPIO_44_GPIO44);
    GPIO_setPinConfig(GPIO_7_GPIO7);
    
    /* Configure GPIO pins for S1. */
    GPIO_setPinConfig(GPIO_41_GPIO41);

  #endif
}

/**
 * @brief  Board Serial Communication Interface Initialization.
 * @note   Call this function in the application to initialize the SCI serial port 
 *         on the board for outputting debugging information.
 */
void SerialCOM_init(void)
{
    /* uart1 rx control */
    GPIO_setAnalogMode(BOARD_SERIALCOM_RX_PIN, GPIO_ANALOG_DISABLED);
    GPIO_setPadConfig(BOARD_SERIALCOM_RX_PIN, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(BOARD_SERIALCOM_RX_PIN, GPIO_QUAL_SYNC);
    GPIO_setQualificationPeriod(BOARD_SERIALCOM_RX_PIN, GPIO_SMP_SYSCLK_DIV_1);
    GPIO_setDirectionMode(BOARD_SERIALCOM_RX_PIN, GPIO_DIR_MODE_IN);
    /* uart1 tx control */
    GPIO_setAnalogMode(BOARD_SERIALCOM_TX_PIN, GPIO_ANALOG_DISABLED);
    GPIO_setPadConfig(BOARD_SERIALCOM_TX_PIN, GPIO_PIN_TYPE_STD);
    GPIO_setDriveLevel(BOARD_SERIALCOM_TX_PIN, GPIO_DRV_LOW);
    GPIO_setPin(BOARD_SERIALCOM_TX_PIN);
    GPIO_setDirectionMode(BOARD_SERIALCOM_TX_PIN, GPIO_DIR_MODE_OUT);
    /* Reset uart before configure it */
    UART_resetModule(BOARD_SERIALCOM);
    /* Set baudrate */
    UART_setBaud(BOARD_SERIALCOM, BOARD_SERIALCOM_BAUDRATE);
    /* Set the number of stop bits */
    UART_setStopBitCount(BOARD_SERIALCOM, UART_ONE_STOP_BIT);
    /* Set MSB bit reverses the order of the bits */
    UART_setMSB(BOARD_SERIALCOM, false);
    /* Config tx fifo */
    UART_enableTxFifo(BOARD_SERIALCOM);
    UART_resetTxFifo(BOARD_SERIALCOM);
    UART_setTxFifoWatermark(BOARD_SERIALCOM, UART_FIFO_TX4);
    
    /* Enable transmitter */
    UART_enableTxModule(BOARD_SERIALCOM);
    /* Enable receiver */
    UART_enableRxModule(BOARD_SERIALCOM);
}

/**
 * @brief  Board LED Initialization.
 * @note   Call this function in the application to initialize the LED 
 *         on the board.
 */
void LED_init (void)
{
  #if (HW_VERSION == HW_MINIBOARD_V1P0)
    /* LED2 initialization */
    GPIO_setAnalogMode(BOARD_LED2_PIN, GPIO_ANALOG_DISABLED);
    GPIO_setDriveLevel(BOARD_LED2_PIN, GPIO_DRV_MAX);
    GPIO_setPin(BOARD_LED2_PIN);
    GPIO_setDirectionMode(BOARD_LED2_PIN, GPIO_DIR_MODE_OUT);
    /* LED3 initialization */
    GPIO_setAnalogMode(BOARD_LED3_PIN, GPIO_ANALOG_DISABLED);
    GPIO_setDriveLevel(BOARD_LED3_PIN, GPIO_DRV_MAX);
    GPIO_setPin(BOARD_LED3_PIN);
    GPIO_setDirectionMode(BOARD_LED3_PIN, GPIO_DIR_MODE_OUT);

  #elif (HW_VERSION == HW_NSSINEPAD_V1P0)
//    /* LED1 initialization */
//    GPIO_setAnalogMode(BOARD_LED1_PIN, GPIO_ANALOG_DISABLED);
//    GPIO_setDriveLevel(BOARD_LED1_PIN, GPIO_DRV_MAX);
//    GPIO_setPin(BOARD_LED1_PIN);
//    GPIO_setDirectionMode(BOARD_LED1_PIN, GPIO_DIR_MODE_OUT);
    /* LED2 initialization */
    GPIO_setAnalogMode(BOARD_LED2_PIN, GPIO_ANALOG_DISABLED);
    GPIO_setDriveLevel(BOARD_LED2_PIN, GPIO_DRV_MAX);
    GPIO_setPin(BOARD_LED2_PIN);
    GPIO_setDirectionMode(BOARD_LED2_PIN, GPIO_DIR_MODE_OUT);

  #endif

}

/**
 * @brief  Board Switch Initialization.
 * @note   Call this function in the application to initialize the Switch 
 *         on the board.
 */
void Switch_init (void)
{
  #if (HW_VERSION == HW_MINIBOARD_V1P0)
    /* S1 initialization */
    GPIO_setAnalogMode(BOARD_S1_PIN, GPIO_ANALOG_DISABLED);
    GPIO_setPadConfig(BOARD_S1_PIN, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationPeriod(BOARD_S1_PIN, GPIO_SMP_SYSCLK_DIV_510);
    GPIO_setQualificationMode(BOARD_S1_PIN, GPIO_QUAL_6SAMPLE);
    GPIO_setDirectionMode(BOARD_S1_PIN, GPIO_DIR_MODE_IN);

    /* S2 initialization */
    GPIO_setAnalogMode(BOARD_S2_PIN, GPIO_ANALOG_DISABLED);
    GPIO_setPadConfig(BOARD_S2_PIN, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationPeriod(BOARD_S2_PIN, GPIO_SMP_SYSCLK_DIV_510);
    GPIO_setQualificationMode(BOARD_S2_PIN, GPIO_QUAL_6SAMPLE);
    GPIO_setDirectionMode(BOARD_S2_PIN, GPIO_DIR_MODE_IN);

  #elif (HW_VERSION == HW_NSSINEPAD_V1P0)
    /* KEY initialization */
//    GPIO_setAnalogMode(BOARD_KEY_PIN, GPIO_ANALOG_DISABLED);
//    GPIO_setPadConfig(BOARD_KEY_PIN, GPIO_PIN_TYPE_OD);
//    GPIO_setQualificationPeriod(BOARD_KEY_PIN, GPIO_SMP_SYSCLK_DIV_510);
//    GPIO_setQualificationMode(BOARD_KEY_PIN, GPIO_QUAL_6SAMPLE);
//    GPIO_setDirectionMode(BOARD_KEY_PIN, GPIO_DIR_MODE_IN);

  #endif
}
