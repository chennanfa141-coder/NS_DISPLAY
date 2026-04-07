/**
  * @file       debug.h
  * @author     qing.zhang
  * @brief      Header file for NS800RT1xxx debug module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __DEBUG_H__
#define __DEBUG_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_debug.h"


/*******************************************************************************
 * Definitions 
 ******************************************************************************/
/** @defgroup DEBUG_EXPORTED_TYPES DEBUG Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'DEBUG' module.
  */

/** @defgroup DEBUG_APBFZ DEBUG IP Number with DEBUG
  * @{
  * @brief  Macro definitions about DEBUG IPs.
  */
typedef enum {
    DEBUG_SLEEP = 0UL,          /*!< DBG_SLEEP Enable/Disable when Debug */
    DEBUG_STOP,                 /*!< DBG_STOP Enable/Disable when Debug */
    DEBUG_STANDBY,              /*!< DBG_STANDBY Enable/Disable when Debug */
    DEBUG_IWDG1 = 4UL,          /*!< IWDG1_DBGSTOP Enable/Disable when Debug */
    DEBUG_WWDG = 6UL,           /*!< WWDG_DBGSTOP Enable/Disable when Debug */
    DEBUG_LPTIM = 10UL,         /*!< LPTIM_DBGSTOP Enable/Disable when Debug */
    DEBUG_STIM1 = 12UL,         /*!< STIM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_STIM2,                /*!< STIM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_STIM3,                /*!< STIM3_DBGSTOP Enable/Disable when Debug */
    DEBUG_I2C1 = 20UL,          /*!< I2C1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CAN1 = 24UL,          /*!< CAN1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CMPSS1 = 32UL,        /*!< CMPSS1_DBGSTOP Enable/Disable when Debug */
    DEBUG_CMPSS2,               /*!< CMPSS2_DBGSTOP Enable/Disable when Debug */
    DEBUG_CMPSS3,               /*!< CMPSS3_DBGSTOP Enable/Disable when Debug */
    DEBUG_CMPSS4,               /*!< CMPSS4_DBGSTOP Enable/Disable when Debug */
    DEBUG_BGCRC1 = 48UL,        /*!< BGCRC1_DBGSTOP Enable/Disable when Debug */
    DEBUG_NMIWD = 50UL,         /*!< NMIWD_DBGSTOP Enable/Disable when Debug */
    DEBUG_EDMA1 = 52UL,         /*!< EDMA1_DBGSTOP Enable/Disable when Debug */
    DEBUG_EPWM1 = 64UL,         /*!< EPWM1_DBGSTOP Enable/Disable when Debug */
    DEBUG_EPWM2,                /*!< EPWM2_DBGSTOP Enable/Disable when Debug */
    DEBUG_EPWM3,                /*!< EPWM3_DBGSTOP Enable/Disable when Debug */
    DEBUG_EPWM4,                /*!< EPWM4_DBGSTOP Enable/Disable when Debug */
    DEBUG_EPWM5,                /*!< EPWM5_DBGSTOP Enable/Disable when Debug */
    DEBUG_EPWM6,                /*!< EPWM6_DBGSTOP Enable/Disable when Debug */
    DEBUG_EPWM7,                /*!< EPWM7_DBGSTOP Enable/Disable when Debug */
    DEBUG_ECAP1 = 96UL,         /*!< ECAP1_DBGSTOP Enable/Disable when Debug */
    DEBUG_ECAP2,                /*!< ECAP2_DBGSTOP Enable/Disable when Debug */
    DEBUG_ECAP3,                /*!< ECAP3_DBGSTOP Enable/Disable when Debug */
    DEBUG_EQEP1 = 112UL,        /*!< EQEP1_DBGSTOP Enable/Disable when Debug */
    DEBUG_EQEP2,                /*!< EQEP2_DBGSTOP Enable/Disable when Debug */
} DEBUG_ApbFz;

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
  * \brief  Enbale the ip to stop when the chip enters debug mode
  * \param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - debug: DEBUG base address index
  * \param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_APBFZ
  */
static inline void DEBUG_setApbStop (DBG_TypeDef *debug, DEBUG_ApbFz debugType)
{
    SET_BIT(TYPE32(&(debug->APBFZ_1) + (debugType >> 5UL)),0x1UL << (debugType - (debugType >> 5UL) * 32UL));
}

/**
  * \brief  Enbale the core1 ip to run when the chip enters debug mode
  * \param  debug        DEBUG pointer to a DEBUG_TypeDef structure
  *                       - debug: DEBUG base address index
  * \param  debugType    the ip number
  *                       This parameter can be any value of @ref DEBUG_APBFZ
  */
static inline void DEBUG_setApbRun (DBG_TypeDef *debug, DEBUG_ApbFz debugType)
{
    CLEAR_BIT(TYPE32(&(debug->APBFZ_1) + (debugType >> 5UL)),0x1UL << (debugType - (debugType >> 5UL) * 32UL));
}
#ifdef __cplusplus
}
#endif


#endif /*__DEBUG_H__ */
