/**
  * @file       system_it_NS800RT1xxx.c
  * @author     Haven-X
  * @brief      system interrupt handler functions.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "system_it_NS800RT1xxx.h"


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
 * @brief   NMI interrupt vector Handler
 */
void NMI_Handler (void)
{
    while (1)
    {
    }
}

/**
 * @brief   HardFault interrupt vector Handler
 */
void HardFault_Handler (void)
{
    while (1)
    {
    }
}

/**
 * @brief   MemManage interrupt vector Handler
 */
void MemManage_Handler (void)
{
    while (1)
    {
    }
}

/**
 * @brief   BusFault interrupt vector Handler
 */
void BusFault_Handler (void)
{
    while (1)
    {
    }
}

/**
 * @brief   UsageFault interrupt vector Handler
 */
void UsageFault_Handler (void)
{
    while (1)
    {
    }
}

/**
 * @brief   SVC interrupt vector Handler
 */
void SVC_Handler (void)
{
}

/**
 * @brief   DebugMon interrupt vector Handler
 */
void DebugMon_Handler (void)
{
}

/**
 * @brief   PendSV interrupt vector Handler
 */
void PendSV_Handler (void)
{
}

/**
 * @brief   SysTick interrupt vector Handler
 */
void SysTick_Handler (void)
{
    /* User codes */
}
