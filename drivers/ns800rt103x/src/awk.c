/**
  * @file       awk.c
  * @author     Haven-X
  * @brief      Function file for NS800RT1xxx awk module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "awk.h"


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
  * @brief  Configure the AWK module.
  * @param  awk            AWK pointer to a AWK_TypeDef structure
  *                         - AWK: AWK base address index
  * @param  clockSource    The clock source acts as the input clock for the prescaler
  *                         This parameter can be any value of @ref AWK_CLOCKSOURCE
  *                         This feature can be modified afterwards using unitary function @ref AWK_setClockSource()
  * @param  prescaler      The prescaler value used to divide the AWK clock
  *                         This parameter can be any value of @ref AWK_PRESCALER
  *                         This feature can be modified afterwards using function @ref AWK_setPrescaler()
  * @param  autoReload     The auto-reload value
  *                         This parameter between Min_Data=0 and Max_Data=0xFF.
  *                         This feature can be modified afterwards using function @ref AWK_setAutoReload()
  * @note   If it is necessary to wake up the device from sleep or top mode, after calling this function, it is also
  *         necessary to enable the NVIC interrupt of the AWK.
  */
void AWK_configModule (AWK_TypeDef *awk, AWK_ClockSource clockSource, AWK_Prescaler prescaler, uint16_t autoReload)
{
    /* Reset AWK */
    SET_BIT(PWR->CR3.WORDVAL, 0x1UL << 13U);
    CLEAR_BIT(PWR->CR3.WORDVAL, 0x1UL << 13U);

    /* Config AWK_ARR Reg */
    WRITE_REG(awk->ARR.WORDVAL, autoReload);
    
    /* Config AWK_CR Reg */
    WRITE_REG(awk->CR.WORDVAL, (uint32_t)clockSource | (uint32_t)prescaler | AWK_CR_IE_M | AWK_CR_EN_M);
}
