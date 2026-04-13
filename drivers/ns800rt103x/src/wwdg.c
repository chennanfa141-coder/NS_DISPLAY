/**
  * @file       wwdg.c
  * @author     yutai.meng
  * @brief      Function file for NS800RT1xxx wwdg module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "wwdg.h"


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
  * @brief  Configures the watchdog parameters,
  *         initializes the initial value of the counter and
  *         enables the watchdog output function..
  * @param  wwdg           Pointer to a WWDG_TypeDef structure
  *                         - WWDG: WWDG base address index
  * @param  reloadValue    The value to be loaded into the counter
  *                         - This parameter is an unsigned integer that is
  *                           greater than or equal to 0x41UL and less than or equal to 0x7FUL
  * @param  windowValue    The value to be loaded into the counter
  *                         - This parameter is an unsigned integer that is
  *                           greater than or equal to 0x41UL and less than or equal to 0x7FUL
  * @param  enableEwi      Whether to enable early wake-up interrupt
  *                         - This parameter can be any value of @ref WWDG_EWIENABLE
  * @param  prescaler      The division factor of the prescaler
  *                         - This parameter can be any value of @ref WWDG_PRESCALER
  * @return Returns the status of function execution
  *                         - True:  The parameters are successfully configured and the watchdog is running
  *                         - False: Parameter configuration failed
  *                                  The user needs to further check the watchdog running status
  */
extern bool WWDG_config (WWDG_TypeDef *wwdg,  uint32_t reloadValue, uint32_t windowValue,
                         WWDG_EwiEnable enableEwi, WWDG_Prescaler prescaler)
{
    if ((READ_REG(wwdg->CR.WORDVAL) & WWDG_CR_WDGA_M) != 0x0U)
    {
        return false;
    }

    WRITE_REG(wwdg->CR.WORDVAL, WWDG_CR_WDGA_M | ((reloadValue & 0x7FU) << WWDG_CR_T_S));
    __DSB();
    WRITE_REG(wwdg->CFR.WORDVAL, (uint32_t)prescaler | (uint32_t)enableEwi | ((windowValue & 0x7FU) << WWDG_CFR_W_S));

    return true;
}
