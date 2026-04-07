/**
  * @file       mcm.h
  * @author     bilang.xiong
  * @brief      Header file for NS800RT1xxx gpio module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __MCM_H__
#define __MCM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 *******************************************************************************/

/** @defgroup CPU_CACHEERRINTSEL CPU MCM cache error interrupt selection
  * @{
  * @brief  Macro definitions about CPU MCM cache error interrupt selection.
  */
typedef enum {
    CPU_CACHE_TAG_RAM_CORRECT_INT = 0U,    /*!< Cache tag RAM correctable error interrupt */
    CPU_CACHE_TAG_RAM_UNCORRECT_INT,       /*!< Cache tag RAM uncorrectable error interrupt */
    CPU_CACHE_DATA_RAM_CORRECT_INT,        /*!< Cache data RAM correctable error interrupt */
    CPU_CACHE_DATA_RAM_UNCORRECT_INT       /*!< Cache data RAM uncorrectable error interrupt */
} CPU_CacheErrIntSel;

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup CPU_ITCM_VRTLADDR CPU ITCM Virtual Address
  * @{
  * @brief  Macro definitions about CPU itcm virtual address.
  */
#define CPU_ITCM_VRTLADDR_START    (0x00000000UL)    /*!< CPU ITCM Virtual Start Address */
#define CPU_ITCM_VRTLADDR_END      (0x0001FFFFUL)    /*!< CPU ITCM Virtual End Address */

/**
  * @}
  */

/** @defgroup CPUx_DTCM_VRTLADDR CPU DTCM Virtual Address (x = 1 or 2)
  * @{
  * @brief  Macro definitions about CPU dtcm virtual address.
  */
#define CPU_DTCM_VRTLADDR_START    (0x20000000UL)    /*!< CPU DTCM Virtual Start Address */
#define CPU_DTCM_VRTLADDR_END      (0x2001FFFFUL)    /*!< CPU DTCM Virtual End Address */

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
 * \brief  Sets the CPU software higher priority in AHB bus.
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 */
static inline void MCM_setCoreAhbHighPriIsSW (MCM_TypeDef *mcm)
{
    CLEAR_BIT(mcm->CPCR.WORDVAL, (MCM_CPCR_AHBSPRI_M << MCM_CPCR_AHBSPRI_S));
}

/**
 * \brief  Sets the CPU interface higher priority in AHB bus.
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 */
static inline void MCM_setCoreAhbHighPriIsIF (MCM_TypeDef *mcm)
{
    SET_BIT(mcm->CPCR.WORDVAL, (MCM_CPCR_AHBSPRI_M << MCM_CPCR_AHBSPRI_S));
}

/**
 * \brief  Gets the CPU AHB bus priority.
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 * \return Returns the CPU AHB bus priority.
 *               - 0: software high priority
 *               - 1: interface high priority
 */
static inline uint32_t MCM_getCoreAhbPriCfg (MCM_TypeDef *mcm)
{
    return READ_BIT((mcm->CPCR.WORDVAL >> MCM_CPCR_AHBSPRI_S), MCM_CPCR_AHBSPRI_M);
}

/**
 * \brief  CPU MCM get status.
 *
 * \param  mcm     mcm pointer to a MCM_TypeDef structure
 *                  - MCM: MCM base address index
 * \return Returns the CPU MCM status.
 */
static inline uint16_t MCM_getStatus (MCM_TypeDef *mcm)
{
    uint16_t status_msk = (MCM_ISCR_ICDET_M | MCM_ISCR_DCDET_M | MCM_ISCR_WABS_M | MCM_ISCR_WABSO_M | 
                          MCM_ISCR_FIOC_M | MCM_ISCR_FDZC_M | MCM_ISCR_FOFC_M | MCM_ISCR_FUFC_M | 
                          MCM_ISCR_FIXC_M | MCM_ISCR_FIDC_M );

    return (uint16_t)(READ_BIT(mcm->ISCR.WORDVAL, status_msk));
}

/**
 * \brief  Clear the CPU MCM error status.
 *
 * \param  mcm    mcm pointer to a MCM_TypeDef structure
 *                 - MCM: MCM base address index
 * \param  clear  the value is used to clear MCM error status
 *                  This parameter can be one of the following \b @ref MCM_ISCRREGBIT:
 *                        MCM_ISCR_ICDET_M
 *                        MCM_ISCR_DCDET_M
 *                        MCM_ISCR_WABS_M
 */
static inline void MCM_clearErrorStatus (MCM_TypeDef *mcm, uint8_t clear)
{
    uint8_t status_msk = (MCM_ISCR_ICDET_M | MCM_ISCR_DCDET_M | MCM_ISCR_WABS_M);

    SET_BIT(mcm->ISCR.WORDVAL, (uint32_t)(clear & status_msk));
}

/**
 * \brief  Enable the CPU MCM interrupt.
 *
 * \param  mcm     mcm pointer to a MCM_TypeDef structure
 *                  - MCM: MCM base address index
 * \param  enable  the value is used to enable MCM interrupt
 *                  his parameter can be one of the following \b @ref MCM_ISCRREGBIT:
 *                        MCM_ISCR_WABE_M
 *                        MCM_ISCR_FIOCE_M
 *                        MCM_ISCR_FDZCE_M
 *                        MCM_ISCR_FOFCE_M
 *                        MCM_ISCR_FUFCE_M
 *                        MCM_ISCR_FIXCE_M
 *                        MCM_ISCR_FIDCE_M
 */
static inline void MCM_enableCoreMCMInterrupt (MCM_TypeDef *mcm, uint32_t enable)
{
    uint32_t en_msk = (MCM_ISCR_WABE_M | MCM_ISCR_FIOCE_M | MCM_ISCR_FDZCE_M | MCM_ISCR_FOFCE_M | MCM_ISCR_FUFCE_M |
                       MCM_ISCR_FIXCE_M | MCM_ISCR_FIDCE_M);

    WRITE_REG(mcm->ISCR.WORDVAL, (enable & en_msk));
}

/**
 * \brief  Disable the CPU MCM interrupt.
 *
 * \param  mcm     mcm pointer to a MCM_TypeDef structure
 *                  - MCM: MCM base address index
 * \param  enable  the value is used to disable MCM interrupt
 *                  his parameter can be one of the following \b @ref MCM_ISCRREGBIT:
 *                        MCM_ISCR_WABE_M
 *                        MCM_ISCR_FIOCE_M
 *                        MCM_ISCR_FDZCE_M
 *                        MCM_ISCR_FOFCE_M
 *                        MCM_ISCR_FUFCE_M
 *                        MCM_ISCR_FIXCE_M
 *                        MCM_ISCR_FIDCE_M
 */
static inline void MCM_disableCoreMCMInterrupt (MCM_TypeDef *mcm, uint32_t disable)
{
    uint32_t dis_msk = (MCM_ISCR_WABE_M | MCM_ISCR_FIOCE_M | MCM_ISCR_FDZCE_M | MCM_ISCR_FOFCE_M | MCM_ISCR_FUFCE_M |
                        MCM_ISCR_FIXCE_M | MCM_ISCR_FIDCE_M);

    CLEAR_BIT(mcm->ISCR.WORDVAL, ((disable & dis_msk) | MCM_ISCR_ICDET_M | MCM_ISCR_DCDET_M | MCM_ISCR_WABS_M));
}

/**
 * \brief  Set MCM tick calibration
 *
 * \param  mcm    mcm pointer to a MCM_TypeDef structure
 *                 - MCM: MCM base address index
 * \param  calib  the value is used to set tick calibration.
 */
static inline void MCM_setTickCalibration (MCM_TypeDef *mcm, uint32_t calib)
{
    WRITE_REG(mcm->CSTC.WORDVAL, (calib & MCM_CSTC_STCALIB_M));
}

/**
 * \brief  Get MCM tick calibration
 *
 * \param  mcm    mcm pointer to a MCM_TypeDef structure
 *                 - MCM: MCM base address index
 * \return the value of the tick calibration.
 */
static inline uint32_t MCM_getTickCalibration (MCM_TypeDef *mcm)
{
    return READ_BIT(mcm->CSTC.WORDVAL, MCM_CSTC_STCALIB_M);
}

/**
 * \brief  Set I-Cache error interrupt enable
 *
 * \param  mcm  mcm pointer to a MCM_TypeDef structure
 *               - MCM: MCM base address index
 * \param  sel  the value is used to select cache error interrupt enable.
 */
static inline void MCM_setICacheErrorInterrupt (MCM_TypeDef *mcm, CPU_CacheErrIntSel sel)
{
    MODIFY_REG(mcm->CECR.WORDVAL, MCM_CECR_ICDETCE_M, (uint32_t)sel);
}

#ifdef __cplusplus
}
#endif


#endif /* __MCM_H__ */
