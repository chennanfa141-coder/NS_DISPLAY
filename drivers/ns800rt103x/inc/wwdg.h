/**
  * @file       wwdg.h
  * @author     yutai.meng
  * @brief      Header file for NS800RT1xxx wwdg module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __WWDG_H__
#define __WWDG_H__


#ifdef __cplusplus
extern "C"{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_wwdg.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup WWDG_EXPORTED_TYPES WWDG Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'WWDG' module.
  */

/** @defgroup WWDG_EWIENABLE WWDG EWI Enablement
  * @{
  * @brief  Definitions about whether to enable early wake-up interrupt.
  */
typedef enum {
    WWDG_EWI_DISABLE = 0x0U,                    /*!< Disable early wake-up interrupt */
    WWDG_EWI_ENABLE = 0x1U << WWDG_CFR_EWI_S    /*!< Enable early wake-up interrupt */
} WWDG_EwiEnable;

/**
  * @}
  */

/** @defgroup WWDG_PRESCALER WWDG Prescaler
  * @{
  * @brief  Definitions about the division factor of the prescaler.
  */
typedef enum {
    WWDG_PRESCALE_DIV1 = 0x0U,                         /*!< The bus clock is not divided */
    WWDG_PRESCALE_DIV2 = 0x1U << WWDG_CFR_WDGTB_S,     /*!< The bus clock is divided by 2 */
    WWDG_PRESCALE_DIV4 = 0x2U << WWDG_CFR_WDGTB_S,     /*!< The bus clock is divided by 4 */
    WWDG_PRESCALE_DIV8 = 0x3U << WWDG_CFR_WDGTB_S,     /*!< The bus clock is divided by 8 */
    WWDG_PRESCALE_DIV16 = 0x4U << WWDG_CFR_WDGTB_S,    /*!< The bus clock is divided by 16 */
    WWDG_PRESCALE_DIV32 = 0x5U << WWDG_CFR_WDGTB_S,    /*!< The bus clock is divided by 32 */
    WWDG_PRESCALE_DIV64 = 0x6U << WWDG_CFR_WDGTB_S,    /*!< The bus clock is divided by 64 */
    WWDG_PRESCALE_DIV128 = 0x7U << WWDG_CFR_WDGTB_S    /*!< The bus clock is divided by 128 */
} WWDG_Prescaler;

/**
  * @}
  */

/**
 * @}
 */

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
  * \brief  Gets the current value in the counter.
  * \param  wwdg    Pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  * \return Returns the current value in the counter
  */
static inline uint32_t WWDG_getCounterValue (WWDG_TypeDef *wwdg)
{
    return READ_BIT(wwdg->CR.WORDVAL, WWDG_CR_T_M);
}

/**
  * \brief  Refreshes watchdog.
  * \param  wwdg         Pointer to a WWDG_TypeDef structure
  *                       - WWDG: WWDG base address index
  * \param  loadValue    The value to be loaded into the counter
  *                       - This parameter is an unsigned integer that is
  *                         greater than or equal to 0x41UL and less than or equal to 0x7FUL
  */
static inline void WWDG_refresh (WWDG_TypeDef *wwdg, uint32_t loadValue)
{
    MODIFY_REG(wwdg->CR.WORDVAL, WWDG_CR_T_M, (loadValue << WWDG_CR_T_S));
}

/**
  * \brief  Gets the status of the EWI Flag.
  * \param  wwdg    Pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  * \return Returns the status of the EWI Flag
  *                  - 0x0U: EWI flag is 0
  *                  - 0x1U: EWI flag is 1
  */
static inline uint32_t WWDG_getEwiFlag (WWDG_TypeDef *wwdg)
{
    return READ_BIT(wwdg->SR.WORDVAL, WWDG_SR_EWIF_M) ? 0x1U : 0x0U;
}

/**
  * \brief  Clears the EWI Flag.
  * \param  wwdg    Pointer to a WWDG_TypeDef structure
  *                  - WWDG: WWDG base address index
  */
static inline void WWDG_clearEwiFlag (WWDG_TypeDef *wwdg)
{
    CLEAR_BIT(wwdg->SR.WORDVAL, WWDG_SR_EWIF_M);
}

/**
  * \brief  Configures the watchdog parameters,
  *         initializes the initial value of the counter and
  *         enables the watchdog output function.
  * \param  wwdg           Pointer to a WWDG_TypeDef structure
  *                         - WWDG: WWDG base address index
  * \param  reloadValue    The value to be loaded into the counter
  *                         - This parameter is an unsigned integer that is
  *                           greater than or equal to 0x41UL and less than or equal to 0x7FUL
  * \param  windowValue    The value to be loaded into the counter
  *                         - This parameter is an unsigned integer that is
  *                           greater than or equal to 0x41UL and less than or equal to reloadValue
  * \param  enableEwi      Whether to enable early wake-up interrupt
  *                         - This parameter can be any value of @ref WWDG_EWIENABLE
  * \param  prescaler      The division factor of the prescaler
  *                         - This parameter can be any value of @ref WWDG_PRESCALER
  * \return Returns the status of function execution
  *                         - True:  The parameters are successfully configured and the watchdog is running
  *                         - False: Parameter configuration failed
  *                                  The user needs to further check the watchdog running status
  */
extern bool WWDG_config (WWDG_TypeDef *wwdg,  uint32_t reloadValue, uint32_t windowValue,
                         WWDG_EwiEnable enableEwi, WWDG_Prescaler prescaler);


#ifdef __cplusplus
}
#endif


#endif /* __WWDG_H__ */
