/**
  * @file       anass.h
  * @author     wangxin
  * @brief      Header file for NS800RT1xxx anass module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __ANASS_H__
#define __ANASS_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_anass.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup ANASS_EXPORTED_TYPES ANASS Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'ANASS' module.
  */

/** @defgroup ANASS_CMPHPMUXSELECT ANASS CMPSS HP Mux Sel  
  * @{
  * @brief  Macro definitions about ANASS cmpss hp mux select
  *         Values that can be passed to ANASS_selectCMPHPMux() as the \e select parameter.
  */ 
typedef enum {
    ANASS_CMPHPMUX_SELECT_1 = 0U,     /*!< CMPHPMUX select 1 */
    ANASS_CMPHPMUX_SELECT_2 = 3U,     /*!< CMPHPMUX select 2 */
    ANASS_CMPHPMUX_SELECT_3 = 6U,     /*!< CMPHPMUX select 3 */
    ANASS_CMPHPMUX_SELECT_4 = 9U      /*!< CMPHPMUX select 4 */
} ANASS_CMPHPMuxSelect;                                      

/**
 * @}
 */
 
/** @defgroup ANASS_CMPLPMUXSELECT ANASS CMPSS LP Mux Sel 
  * @{
  * @brief  Macro definitions about ANASS cmpss lp mux select
  *         Values that can be passed to ANASS_selectCMPLPMux() as the \e select parameter.
  */                                                              
typedef enum {                                                            
    ANASS_CMPLPMUX_SELECT_1 = 0U,     /*!< CMPLPMUX select 1 */
    ANASS_CMPLPMUX_SELECT_2 = 3U,     /*!< CMPLPMUX select 2 */
    ANASS_CMPLPMUX_SELECT_3 = 6U,     /*!< CMPLPMUX select 3 */
    ANASS_CMPLPMUX_SELECT_4 = 9U      /*!< CMPLPMUX select 4 */
} ANASS_CMPLPMuxSelect;

/**
 * @}
 */
 
/** @defgroup ANASS_CMPHNMUXSELECT ANASS CMPSS HN Mux Sel
  * @{
  * @brief  Macro definitions about ANASS cmpss hn mux select
  *         Values that can be passed to ANASS_selectCMPHNMux() as the \e select parameter.
  */ 
typedef enum {                                          
    ANASS_CMPHNMUX_SELECT_1 = 0x0U,     /*!< CMPHNMUX select 1 */
    ANASS_CMPHNMUX_SELECT_2 = 0x2U,     /*!< CMPHNMUX select 2 */
    ANASS_CMPHNMUX_SELECT_3 = 0x4U,     /*!< CMPHNMUX select 3 */
    ANASS_CMPHNMUX_SELECT_4 = 0x6U      /*!< CMPHNMUX select 4 */
} ANASS_CMPHNMuxSelect;

/**
 * @}
 */
 
/** @defgroup ANASS_CMPLNMUXSELECT ANASS CMPSS LN Mux Sel
  * @{
  * @brief  Macro definitions about ANASS cmpss ln mux select
  *         Values that can be passed to ANASS_selectCMPLNMux() as the \e select parameter.
  */
typedef enum {                                          
    ANASS_CMPLNMUX_SELECT_1 = 0x0U,     /*!< CMPLNMUX select 1 */
    ANASS_CMPLNMUX_SELECT_2 = 0x2U,     /*!< CMPLNMUX select 2 */
    ANASS_CMPLNMUX_SELECT_3 = 0x4U,     /*!< CMPLNMUX select 3 */
    ANASS_CMPLNMUX_SELECT_4 = 0x6U      /*!< CMPLNMUX select 4 */
} ANASS_CMPLNMuxSelect;

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
  * \brief  VRBUF Discharge Enable.
  * \param  enable    VRBUF Discharge Enable.
  *                    - 0: No effect
  *                    - 1: Discharge
  */
static inline void ANASS_enableDischarge (bool enable)
{
    if (enable)
    {
        SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_DISCHARGE_M);
    }
    else
    {
        CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_DISCHARGE_M);
    }
}

/**
  * \brief  Set the internal analog voltage reference selection to 2.5V.
  */
static inline void ANASS_setAnalogReference2P5 (void)
{
    SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
}

/**
  * \brief  Set the internal analog voltage reference selection to 1.65V.
  */
static inline void ANASS_setAnalogReference1P65 (void)
{
    CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
}

/**
  * \brief  Set the analog voltage reference selection to internal.
  */
static inline void ANASS_setAnalogReferenceInternal (void)
{
    CLEAR_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREFSEL_M);
}

/**
  * \brief  Set the analog voltage reference selection to external.
  */
static inline void ANASS_setAnalogReferenceExternal (void)
{
    SET_BIT(ANASS->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREFSEL_M);
}

/**
  * \brief  Select the value for CMPHPMXSEL.
  * \param  select    select is of type ANASS_CMPHPMuxSelect.
  *                    This parameter can be any value of @ref ANASS_CMPHPMUXSELECT
  * \param  value     CMPSS HP Mux Sel
  *                    - uint8_t: 0,1,2,3,4,5
  */
static inline void ANASS_selectCMPHPMux (ANASS_CMPHPMuxSelect select, uint8_t value)
{  
    MODIFY_REG(ANASS->CMPHPMXSEL.WORDVAL, (uint32_t)(ANASS_CMPHPMXSEL_CMP1HPMXSEL_M << (uint32_t) select), \
              (uint32_t)(value << (uint32_t)select));                                     
}

/**
  * \brief  Select the value for CMPLPMXSEL.
  * \param  select    select is of type ANASS_CMPLPMuxSelect.
  *                    This parameter can be any value of @ref ANASS_CMPLPMUXSELECT
  * \param  value     CMPSS LP Mux Sel
  *                    - uint8_t: 0,1,2,3,4,5
  */
static inline void ANASS_selectCMPLPMux (ANASS_CMPLPMuxSelect select, uint8_t value)
{
    MODIFY_REG(ANASS->CMPLPMXSEL.WORDVAL, (uint32_t)(ANASS_CMPLPMXSEL_CMP1LPMXSEL_M << (uint32_t) select), \
              (uint32_t)(value << (uint32_t)select));
}

/**
  * \brief  Select the value for CMPHNMXSEL.
  * \param  select    select is of type ANASS_CMPHNMuxSelect.
  *                    This parameter can be can be any value of @ref ANASS_CMPHNMUXSELECT.
  * \param  value     CMPSS HN Mux Sel
  *                    - uint8_t: 0,1,2
  */
static inline void ANASS_selectCMPHNMuxValue (ANASS_CMPHNMuxSelect select, uint8_t value)
{
    MODIFY_REG(ANASS->CMPHNMXSEL.WORDVAL, (uint32_t)(ANASS_CMPHNMXSEL_CMP1HNMXSEL_M << (uint32_t) select), \
              (uint32_t)(value << (uint32_t)select));
}

/**
  * \brief  Select the value for CMPLNMXSEL.
  * \param  select    select is of type ANASS_CMPLNMuxSelect.
  *                    This parameter can be can be any value of @ref ANASS_CMPLNMUXSELECT.
  * \param  value     CMPSS LN Mux Sel
  *                    - uint8_t: 0,1,2
  */
static inline void ANASS_selectCMPLNMuxValue (ANASS_CMPLNMuxSelect select, uint8_t value)
{
    MODIFY_REG(ANASS->CMPLNMXSEL.WORDVAL, (uint32_t)(ANASS_CMPLNMXSEL_CMP1LNMXSEL_M << (uint32_t) select), \
              (uint32_t)(value << (uint32_t)select));
}

/**
  * \brief  Locks the analog reference control register.
  */
static inline void ANASS_lockANAREF (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_ANAREFCTL_M);
}

/**
  * \brief  Locks the CMPHPMXSEL control register.
  */
static inline void ANASS_lockCMPHPMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPHPMXSEL_M);
}

/**
  * \brief  Locks the CMPLPMXSEL control register.
  */
static inline void ANASS_lockCMPLPMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPLPMXSEL_M);
}

/**
  * \brief  Locks the CMPHNMXSEL control register.
  */
static inline void ANASS_lockCMPHNMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPHNMXSEL_M);
}

/**
  * \brief  Locks the CMPLNMXSEL control register.
  */
static inline void ANASS_lockCMPLNMux (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPLNMXSEL_M);
}

/**
  * \brief  Locks the cmpssctl register.
  */
static inline void ANASS_lockCmpssCtl (void)
{
    SET_BIT(ANASS->LOCK.WORDVAL, ANASS_LOCK_CMPSSCTL_M);
}

/**
  * \brief  VRBUF Discharge Enable.
  * \param  enable    VRBUF Discharge Enable.
  *                     - 0: No effect
  *                     - 1: Discharge
  */
static inline void ANASS_enableCmp1DacOut (bool enable)
{
    WRITE_REG(ANASS->CMPSSCTL.WORDVAL, ANASS_CMPSSCTL_CMPSSCTLEN_M); 
    if(enable)
    {
        SET_BIT(ANASS->CMPSSCTL.WORDVAL, ANASS_CMPSSCTL_CMP1LDACOUTEN_M);  
    }
}

#ifdef __cplusplus
}
#endif


#endif /* __ANASS_H__ */
