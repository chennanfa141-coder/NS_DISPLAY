/**
  * @file       iwdg1.h
  * @author     yutai.meng
  * @brief      Header file for NS800RT1xxx iwdg1 module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __IWDG1_H__
#define __IWDG1_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_iwdg1.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup IWDG1_EXPORTED_TYPES IWDG1 Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'IWDG1' module.
  */

/** @defgroup IWDG1_WINDOWSTARTLOCATION IWDG1 Window Start Location
  * @{
  * @brief  Definitions about start positions of the window (relative to total cycles).
  */
typedef enum {
    IWDG1_WINDOW_START_LOCATION_PERCENT25 = 0x0U,                       /*!< The window starts at 25% of total cycles */
    IWDG1_WINDOW_START_LOCATION_PERCENT50 = 0x1U << IWDG1_CR_RPSS_S,    /*!< The window starts at 50% of total cycles */
    IWDG1_WINDOW_START_LOCATION_PERCENT75 = 0x2U << IWDG1_CR_RPSS_S,    /*!< The window starts at 75% of total cycles */
    IWDG1_WINDOW_START_LOCATION_NONE      = 0x3U << IWDG1_CR_RPSS_S     /*!< The window start location is not set */
} IWDG1_WindowStartLocation;

/**
  * @}
  */

/** @defgroup IWDG1_WINDOWENDLOCATION IWDG1 Window End Location
  * @{
  * @brief  Definitions about end positions of the window (relative to total cycles).
  */
typedef enum {
    IWDG1_WINDOW_END_LOCATION_PERCENT75 = 0x0U,                       /*!< The window ends at 75% of total cycles */
    IWDG1_WINDOW_END_LOCATION_PERCENT50 = 0x1U << IWDG1_CR_RPES_S,    /*!< The window ends at 50% of total cycles */
    IWDG1_WINDOW_END_LOCATION_PERCENT25 = 0x2U << IWDG1_CR_RPES_S,    /*!< The window ends at 25% of total cycles */
    IWDG1_WINDOW_END_LOCATION_NONE      = 0x3U << IWDG1_CR_RPES_S     /*!< The window end location is not set */
} IWDG1_WindowEndLocation;

/**
  * @}
  */

/** @defgroup IWDG1_PRESCALER IWDG1 Prescaler
  * @{
  * @brief  Definitions about division factors of the prescaler.
  */
typedef enum {
    IWDG1_PRESCALE_DIV1 = 0x0U,                        /*!< MIRC1 clock is not divided */
    IWDG1_PRESCALE_DIV2 = 0x1U << IWDG1_CR_CKS_S,      /*!< MIRC1 clock is divided by 2 */
    IWDG1_PRESCALE_DIV4 = 0x2U << IWDG1_CR_CKS_S,      /*!< MIRC1 clock is divided by 4 */
    IWDG1_PRESCALE_DIV8 = 0x3U << IWDG1_CR_CKS_S,      /*!< MIRC1 clock is divided by 8 */
    IWDG1_PRESCALE_DIV16 = 0x4U << IWDG1_CR_CKS_S,     /*!< MIRC1 clock is divided by 16 */
    IWDG1_PRESCALE_DIV32 = 0x5U << IWDG1_CR_CKS_S,     /*!< MIRC1 clock is divided by 32 */
    IWDG1_PRESCALE_DIV128 = 0x8U << IWDG1_CR_CKS_S,    /*!< MIRC1 clock is divided by 128 */
    IWDG1_PRESCALE_DIV256 = 0x9U << IWDG1_CR_CKS_S,    /*!< MIRC1 clock is divided by 256 */
    IWDG1_PRESCALE_DIV512 = 0xAU << IWDG1_CR_CKS_S,    /*!< MIRC1 clock is divided by 512 */
    IWDG1_PRESCALE_DIV1024 = 0xBU << IWDG1_CR_CKS_S,   /*!< MIRC1 clock is divided by 1024 */
    IWDG1_PRESCALE_DIV2048 = 0xCU << IWDG1_CR_CKS_S,   /*!< MIRC1 clock is divided by 2048 */
    IWDG1_PRESCALE_DIV4096 = 0xDU << IWDG1_CR_CKS_S,   /*!< MIRC1 clock is divided by 4096 */
    IWDG1_PRESCALE_DIV8192 = 0xEU << IWDG1_CR_CKS_S,   /*!< MIRC1 clock is divided by 8192 */
    IWDG1_PRESCALE_DIV64 = 0xFU << IWDG1_CR_CKS_S      /*!< MIRC1 clock is divided by 64 */
} IWDG1_Prescaler;

/**
  * @}
  */

/** @defgroup IWDG1_LOWPOWERWORKMODE IWDG1 Work Mode In Low Power Mode
  * @{
  * @brief  Definitions about work modes (keep or stop counting) in low power mode.
  */
typedef enum {
    IWDG1_LOW_POWER_WORK_MODE_RUN = 0x0U,                         /*!< Keep counting */
    IWDG1_LOW_POWER_WORK_MODE_STOP = 0x1U << IWDG1_CR_SLCSTP_S    /*!< Stop counting */
} IWDG1_LowPowerWorkMode;

/**
  * @}
  */

/** @defgroup IWDG1_OUTPUTTYPE IWDG1 Output Type
  * @{
  * @brief  Definitions about output types (reset or interrupt).
  */
typedef enum {
    IWDG1_OUTPUT_TYPE_INTERRUPT = 0x0U,                     /*!< Output interrupt request signal */
    IWDG1_OUTPUT_TYPE_RESET = 0x1U << IWDG1_CR_RSTIRQS_S    /*!< Output reset signal */
} IWDG1_OutputType;

/**
  * @}
  */

/** @defgroup IWDG1_TOTALCYCLES IWDG1 Total Counting Cycles
  * @{
  * @brief  Definitions about total numbers of counter clock cycles in each round of counting,
  *         as the timeout period.
  */
typedef enum {
    IWDG1_TOTAL_CYCLES_1024 = 0x0U,                       /*!< 1024 counter clock cycles */
    IWDG1_TOTAL_CYCLES_4096 = 0x1U << IWDG1_CR_TOPS_S,    /*!< 4096 counter clock cycles */
    IWDG1_TOTAL_CYCLES_8192 = 0x2U << IWDG1_CR_TOPS_S,    /*!< 8192 counter clock cycles */
    IWDG1_TOTAL_CYCLES_16384 = 0x3U << IWDG1_CR_TOPS_S    /*!< 16384 counter clock cycles */
} IWDG1_TotalCycles;

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
  * \brief  Enables watchdog.
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_enable (IWDG1_TypeDef *iwdg1)
{
    WRITE_REG(iwdg1->RR.WORDVAL, 0x55U);
    __DSB();
    WRITE_REG(iwdg1->RR.WORDVAL, 0xAAU);
}

/**
  * \brief  Refreshes watchdog.
  * \param  iwdg    Pointer to a IWDG1_TypeDef structure
  *                  - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_refresh (IWDG1_TypeDef *iwdg1)
{
    WRITE_REG(iwdg1->RR.WORDVAL, 0x00U);
    __DSB();
    WRITE_REG(iwdg1->RR.WORDVAL, 0xFFU);
}

/**
  * \brief  Gets refresh error flag.
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  * \return Returns the status of the refresh error flag
  *                   - 0x0U: Refresh error flag is 0
  *                   - 0x1U: Refresh error flag is 1
  */
static inline uint32_t IWDG1_getRefreshErrorFlag (IWDG1_TypeDef *iwdg1)
{
    return READ_BIT(iwdg1->SR.WORDVAL, IWDG1_SR_REFEF_M) ? 0x1U : 0x0U;
}

/**
  * \brief  Clears refresh error flag.
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_clearRefreshErrorFlag (IWDG1_TypeDef *iwdg1)
{
    CLEAR_BIT(iwdg1->SR.WORDVAL, IWDG1_SR_REFEF_M);
}

/**
  * \brief  Gets underflow flag.
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  * \return Returns the status of the underflow flag
  *                   - 0x0U: Underflow flag is 0
  *                   - 0x1U: Underflow flag is 1
  */
static inline uint32_t IWDG1_getUnderflowFlag (IWDG1_TypeDef *iwdg1)
{
    return READ_BIT(iwdg1->SR.WORDVAL, IWDG1_SR_UNDFF_M) ? 0x1U : 0x0U;
}

/**
  * \brief  Clears underflow flag.
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_clearUnderflowFlag (IWDG1_TypeDef *iwdg1)
{
    CLEAR_BIT(iwdg1->SR.WORDVAL, IWDG1_SR_UNDFF_M);
}

/**
  * \brief  Gets interrupt flag.
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  * \return Returns the status of IWDG1 interrupt flag
  *                   - 0x0U: Interrupt flag is 0
  *                   - 0x1U: Interrupt flag is 1
  */
static inline uint32_t IWDG1_getInterruptFlag (IWDG1_TypeDef *iwdg1)
{
    return READ_BIT(iwdg1->INTSR.WORDVAL, IWDG1_INTSR_IWDG1INT_M) ? 0x1U : 0x0U;
}

/**
  * \brief  Gets current counter value.
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  * \return Return the current counter value
  *                   This parameter is an unsigned integer that is
  *                   greater than or equal to 0x0UL and
  *                   less than or equal to max value of the counter
  *                   which is set in bit field TOPS
  */
static inline uint32_t IWDG1_getCurrentCounterValue (IWDG1_TypeDef *iwdg1)
{
    return READ_BIT(iwdg1->SR.WORDVAL, IWDG1_SR_CNTVAL_M) >> IWDG1_SR_CNTVAL_S;
}

/**
  * \brief  Clears interrupt flag
  * \param  iwdg1    Pointer to a IWDG1_TypeDef structure
  *                   - IWDG1: IWDG1 base address index
  */
static inline void IWDG1_clearInterruptFlag (IWDG1_TypeDef *iwdg1)
{
    SET_BIT(iwdg1->INTCLR.WORDVAL, IWDG1_INTCLR_IWDG1INTCLR_M);
}

/**
  * \brief  Configures parameters.
  * \param  iwdg1                  Pointer to a IWDG1_TypeDef structure
  *                                 - IWDG1: IWDG1 base address index
  * \param  windowStartLocation    Start position of the window (relative to total cycles)
  *                                 - This parameter can be any value of @ref IWDG1_WINDOWSTARTLOCATION
  * \param  windowEndLocation      End position of the window (relative to total cycles)
  *                                 - This parameter can be any value of @ref IWDG1_WINDOWENDLOCATION
  * \param  prescaler              Division factor of the prescaler
  *                                 - This parameter can be any value of @ref IWDG1_PRESCALER
  * \param  lowPowerWorkMode       Work mode (keep or stop counting) in low power mode
  *                                 - This parameter can be any value of @ref IWDG1_LOWPOWERWORKMODE
  * \param  outputType             Output type (reset or interrupt)
  *                                 - This parameter can be any value of @ref IWDG1_OUTPUTTYPE
  * \param  totalCycles            Total number of counter clock cycles in each round of counting
  *                                 - This parameter can be any value of @ref IWDG1_TOTALCYCLES
  * \return Returns the status of function execution
  *                         - True:  The parameters are successfully configured
  *                         - False: Parameter configuration failed
  */
extern bool IWDG1_config (IWDG1_TypeDef *iwdg1,
                          IWDG1_WindowStartLocation windowStartLocation,
                          IWDG1_WindowEndLocation windowEndLocation,
                          IWDG1_Prescaler prescaler,
                          IWDG1_LowPowerWorkMode lowPowerWorkMode,
                          IWDG1_OutputType outputType,
                          IWDG1_TotalCycles totalCycles);


#ifdef __cplusplus
}
#endif


#endif /* __IWDG1_H__ */
