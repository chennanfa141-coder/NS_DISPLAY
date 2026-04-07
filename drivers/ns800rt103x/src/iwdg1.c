/**
  * @file       iwdg1.c
  * @author     yutai.meng
  * @brief      Function file for NS800RT1xxx iwdg1 module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "iwdg1.h"


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
  * @brief  Configures parameters.
  * @param  iwdg1                  Pointer to a IWDG1_TypeDef structure
  *                                 - IWDG1: IWDG1 base address index
  * @param  windowStartLocation    Start position of the window (relative to total cycles)
  *                                 - This parameter can be any value of @ref IWDG1_WINDOWSTARTLOCATION
  * @param  windowEndLocation      End position of the window (relative to total cycles)
  *                                 - This parameter can be any value of @ref IWDG1_WINDOWENDLOCATION
  * @param  prescaler              Division factor of the prescaler
  *                                 - This parameter can be any value of @ref IWDG1_PRESCALER
  * @param  lowPowerWorkMode       Work mode (keep or stop counting) in low power mode
  *                                 - This parameter can be any value of @ref IWDG1_LOWPOWERWORKMODE
  * @param  outputType             Output type (reset or interrupt)
  *                                 - This parameter can be any value of @ref IWDG1_OUTPUTTYPE
  * @param  totalCycles            Total number of counter clock cycles in each round of counting
  *                                 - This parameter can be any value of @ref IWDG1_TOTALCYCLES
  * @return Returns the status of function execution
  *                         - True:  The parameters are successfully configured
  *                         - False: Parameter configuration failed
  */
bool IWDG1_config (IWDG1_TypeDef *iwdg1,
                   IWDG1_WindowStartLocation windowStartLocation,
                   IWDG1_WindowEndLocation windowEndLocation,
                   IWDG1_Prescaler prescaler,
                   IWDG1_LowPowerWorkMode lowPowerWorkMode,
                   IWDG1_OutputType outputType,
                   IWDG1_TotalCycles totalCycles)
{
    static bool writeEnable = true;

    if (writeEnable == true)
    {
        WRITE_REG(iwdg1->CR.WORDVAL, (uint32_t)windowStartLocation | (uint32_t)windowEndLocation | (uint32_t)prescaler |
                                     (uint32_t)lowPowerWorkMode | (uint32_t)outputType | (uint32_t)totalCycles);
        writeEnable = false;
        return true;
    }
    else
    {
        return false;
    }
}
