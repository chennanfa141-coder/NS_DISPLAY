/**
  * @file       xbar.c
  * @author     wuxiao
  * @brief      Function file for NS800RT1xxx xbar module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "xbar.h"


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
 * @brief  Configure the outputxbar MUX register with OUTPUT1MUX1~OUTPUT8MUX2
 * @param  xbar         X-BAR pointer to a XBAR_TypeDef structure
 *                       - XBAR: X-BAR base address index
 * @param  output       output: the index of Output X-BAR port 
 *                       - This parameter can be any value of @ref XBAR_OUTPUT
 * @param  muxConfig    muxConfig: output mux selection 
 *                       - This parameter can be any value of @ref XBAR_OUTPUTMUXCONFIG
 */
void XBAR_setOutputMuxConfig (XBAR_TypeDef *xbar, XBAR_OutputNum output, XBAR_OutputMuxConfig muxConfig)
{
    /* Calculate the register offset based on the muxConfig and output number. */
    uint32_t offset = ((uint32_t)output << 1UL) + ((((uint32_t)muxConfig & 0x2000UL) != 0UL) ? 4UL : 0UL);
    /* Calculate the bit shift from the muxConfig. */
    uint32_t shift = ((uint32_t)muxConfig >> 8UL) & 0x1FUL;
    /* Calculate the address of the target register. */
    volatile uint32_t *regAddress = (volatile uint32_t *)((uint8_t *)&xbar->OUTPUTXMUX + offset);
    /* Modify the register value with the new mux configuration. */
    MODIFY_REG(TYPE32(regAddress), (0x3UL << shift), (((uint32_t)muxConfig & 0x3UL) << shift));
}

/**
 * @brief  Configure the epwmxbar MUX register with TRIP4MUX1~TRIP12MUX2
 * @param  xbar         X-BAR pointer to a XBAR_TypeDef structure
 *                       - XBAR: X-BAR base address index
 * @param  trip         trip: the trip index of the ePWM X-BAR 
 *                       - This parameter can be any value of @ref XBAR_TRIPNUM
 * @param  muxConfig    muxConfig: ePWM mux selection 
 *                       - This parameter can be any value of @ref XBAR_EPWMMUXCONFIG
 */
void XBAR_setEPWMMuxConfig (XBAR_TypeDef *xbar, XBAR_TripNum trip, XBAR_EPWMMuxConfig muxConfig)
{
    /* Calculate the register offset based on the muxConfig and trip number. */
    uint32_t offset = ((uint32_t)trip << 1UL) + ((((uint32_t)muxConfig & 0x2000UL) != 0UL) ? 4UL : 0UL);
    /* Calculate the bit shift from the muxConfig. */
    uint32_t shift = ((uint32_t)muxConfig >> 8UL) & 0x1FUL;
    /* Calculate the address of the target register. */
    volatile uint32_t *regAddress = (volatile uint32_t *)((uint8_t *)&xbar->TRIP4MUX0TO15CFG.WORDVAL + offset);
    /* Modify the register value with the new mux configuration. */
    MODIFY_REG(TYPE32(regAddress), (0x3UL << shift), (((uint32_t)muxConfig & 0x3UL) << shift));
}

