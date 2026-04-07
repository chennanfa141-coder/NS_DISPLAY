/**
  * @file       syscon.h
  * @author     Haven-X
  * @brief      Header file for NS800RT1xxx SYSCON module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SYSCON_H__
#define __SYSCON_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_syscon.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup SYSCON_EXPORTED_TYPES SYSCON Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'SYSCON' module.
  */

/** @defgroup SYSCON_SPI1NCSSEL SYSCON SPI1 NCS Pin Select
  * @{
  * @brief  Macro definitions about SYSCON SPI1 NCS pin select.
  *         Values that can be passed to SYSCON_setSpi1Ncs() as the \e spi1Ncs parameter.
  */
typedef enum {
    SYSCON_SPI1NCS_SEL_HIGH = 0U,    /*!< fixed high level */
    SYSCON_SPI1NCS_SEL_PA0,          /*!< PA0 */
    SYSCON_SPI1NCS_SEL_PA5,          /*!< PA5 */
    SYSCON_SPI1NCS_SEL_PA11,         /*!< PA11 */
    SYSCON_SPI1NCS_SEL_PA19,         /*!< PA19 */
    SYSCON_SPI1NCS_SEL_PA24,         /*!< PA24 */
    SYSCON_SPI1NCS_SEL_PA29,         /*!< PA29 */
    SYSCON_SPI1NCS_SEL_PB3,          /*!< PB3 */
    SYSCON_SPI1NCS_SEL_PB7,          /*!< PB7 */
    SYSCON_SPI1NCS_SEL_PH18          /*!< PH18 */
} SYSCON_Spi1NcsSel;

/**
  * @}
  */

/** @defgroup SYSCON_SPI2NCSSEL SYSCON SPI2 NCS Pin Select
  * @{
  * @brief  Macro definitions about SYSCON SPI2 NCS pin select.
  *         Values that can be passed to SYSCON_setSpi2Ncs() as the \e spi2Ncs parameter.
  */
typedef enum {
    SYSCON_SPI2NCS_SEL_HIGH = 0U,    /*!< fixed high level */
    SYSCON_SPI2NCS_SEL_PA5,          /*!< PA5 */
    SYSCON_SPI2NCS_SEL_PA13,         /*!< PA13 */
    SYSCON_SPI2NCS_SEL_PA14,         /*!< PA14 */
    SYSCON_SPI2NCS_SEL_PA23,         /*!< PA23 */
    SYSCON_SPI2NCS_SEL_PA27,         /*!< PA27  */
    SYSCON_SPI2NCS_SEL_PA29,         /*!< PA29 */
    SYSCON_SPI2NCS_SEL_PB1           /*!< PB1 */
} SYSCON_Spi2NcsSel;

/**
  * @}
  */

/** @defgroup SYSCON_EXTIPINSEL SYSCON EXTI Pin Select
  * @{
  * @brief  Macro definitions about SYSCON EXTI pin select.
  *         Values that can be passed to SYSCON_setExtiSel() as the \e pinSel parameter.
  */
typedef enum {
    SYSCON_EXTI_PINSEL_0 = 0U,    /*!< pin select 0 */
    SYSCON_EXTI_PINSEL_1,         /*!< pin select 1 */
    SYSCON_EXTI_PINSEL_2,         /*!< pin select 2 */
    SYSCON_EXTI_PINSEL_3,         /*!< pin select 3 */
    SYSCON_EXTI_PINSEL_4,         /*!< pin select 4 */
    SYSCON_EXTI_PINSEL_5,         /*!< pin select 5 */
    SYSCON_EXTI_PINSEL_6,         /*!< pin select 6 */
    SYSCON_EXTI_PINSEL_7,         /*!< pin select 7 */
    SYSCON_EXTI_PINSEL_8,         /*!< pin select 8 */
    SYSCON_EXTI_PINSEL_9,         /*!< pin select 9 */
    SYSCON_EXTI_PINSEL_10,        /*!< pin select 10 */
    SYSCON_EXTI_PINSEL_11,        /*!< pin select 11 */
    SYSCON_EXTI_PINSEL_12,        /*!< pin select 12 */
    SYSCON_EXTI_PINSEL_13,        /*!< pin select 13 */
    SYSCON_EXTI_PINSEL_14,        /*!< pin select 14 */
    SYSCON_EXTI_PINSEL_15         /*!< pin select 15 */
} SYSCON_ExtiPinSel;

/**
  * @}
  */

/** @defgroup SYSCON_EXTISEL SYSCON EXTI Select
  * @{
  * @brief  Macro definitions about SYSCON EXTI select.
  *         Values that can be passed to SYSCON_setExtiSel() as the \e extiSel parameter.
  */
typedef enum {
    SYSCON_EXTISEL_0 = 0U,    /*!< exti select 0 */
    SYSCON_EXTISEL_1,         /*!< exti select 1 */
    SYSCON_EXTISEL_2,         /*!< exti select 2 */
    SYSCON_EXTISEL_3,         /*!< exti select 3 */
    SYSCON_EXTISEL_4,         /*!< exti select 4 */
    SYSCON_EXTISEL_5,         /*!< exti select 5 */
    SYSCON_EXTISEL_6,         /*!< exti select 6 */
    SYSCON_EXTISEL_7,         /*!< exti select 7 */
    SYSCON_EXTISEL_8,         /*!< exti select 8 */
    SYSCON_EXTISEL_9,         /*!< exti select 9 */
    SYSCON_EXTISEL_10,        /*!< exti select 10 */
    SYSCON_EXTISEL_11,        /*!< exti select 11 */
    SYSCON_EXTISEL_12,        /*!< exti select 12 */
    SYSCON_EXTISEL_13,        /*!< exti select 13 */
    SYSCON_EXTISEL_14,        /*!< exti select 14 */
    SYSCON_EXTISEL_15         /*!< exti select 15 */
} SYSCON_ExtiSel;

/**
  * @}
  */

/** @defgroup SYSCON_SYNCOUTCRSEL SYSCON SYNCOUT Control
  * @{
  * @brief  Macro definitions about SYSCON SYNCOUT control.
  *         Values that can be passed to SYSCON_setSyncOutSel() as the \e syncOutSel parameter.
  */
typedef enum {
    SYSCON_SYNCOUTSEL_EPWM1 = 0U,       /*!< EPWM1 */
    SYSCON_SYNCOUTSEL_EPWM2,            /*!< EPWM2 */
    SYSCON_SYNCOUTSEL_EPWM3,            /*!< EPWM3 */
    SYSCON_SYNCOUTSEL_EPWM4,            /*!< EPWM4 */
    SYSCON_SYNCOUTSEL_EPWM5,            /*!< EPWM5 */
    SYSCON_SYNCOUTSEL_EPWM6,            /*!< EPWM6 */
    SYSCON_SYNCOUTSEL_EPWM7,            /*!< EPWM7 */
    SYSCON_SYNCOUTSEL_ECAP1 = 0x18U,    /*!< ECAP1 */
    SYSCON_SYNCOUTSEL_ECAP2,            /*!< ECAP2 */
    SYSCON_SYNCOUTSEL_ECAP3             /*!< ECAP3 */
} SYSCON_SyncOutSel;

/**
  * @}
  */

/** @defgroup SYSCON_EPWMSOCAEN SYSCON EPWMSOCA Enable Bit
  * @{
  * @brief  Macro definitions about SYSCON EPWMSOCA enable.
  *         Values that can be passed to SYSCON_enableEpwmSocA() as the \e epwmNum parameter.
  */
typedef enum {
    SYSCON_EPWM1SOCAEN = 0U,    /*!< EPWM1SOCAEN */
    SYSCON_EPWM2SOCAEN,         /*!< EPWM2SOCAEN */
    SYSCON_EPWM3SOCAEN,         /*!< EPWM3SOCAEN */
    SYSCON_EPWM4SOCAEN,         /*!< EPWM4SOCAEN */
    SYSCON_EPWM5SOCAEN,         /*!< EPWM5SOCAEN */
    SYSCON_EPWM6SOCAEN,         /*!< EPWM6SOCAEN */
    SYSCON_EPWM7SOCAEN          /*!< EPWM7SOCAEN */
} SYSCON_EpwmSocAEn;

/**
  * @}
  */

/** @defgroup SYSCON_EPWMSOCBEN SYSCON EPWMSOCB Enable Bit
  * @{
  * @brief  Macro definitions about SYSCON EPWMSOCB enable.
  *         Values that can be passed to SYSCON_enableEpwmSocB() as the \e epwmNum parameter.
  */
typedef enum {
    SYSCON_EPWM1SOCBEN = 0U,    /*!< EPWM1SOCBEN */
    SYSCON_EPWM2SOCBEN,         /*!< EPWM2SOCBEN */
    SYSCON_EPWM3SOCBEN,         /*!< EPWM3SOCBEN */
    SYSCON_EPWM4SOCBEN,         /*!< EPWM4SOCBEN */
    SYSCON_EPWM5SOCBEN,         /*!< EPWM5SOCBEN */
    SYSCON_EPWM6SOCBEN,         /*!< EPWM6SOCBEN */
    SYSCON_EPWM7SOCBEN          /*!< EPWM7SOCBEN */
} SYSCON_EpwmSocBEn;

/**
  * @}
  */

/** @defgroup SYSCON_DOZEMODULEID SYSCON Peripheral DOZE Request Register
  * @{
  * @brief  Macro definitions about SYSCON Peripheral doze Request.
  *         Values that can be passed to SYSCON_setPDozeReq() as the \e id parameter.
  */
typedef enum {
    MODULE_DOZE_CAN1 = 0U    /*!< CAN1 */  
} SYSCON_DozeModuleId;

/**
  * @}
  */

/** @defgroup SYSCON_STOPMODULEID SYSCON Peripheral STOP Request Register
  * @{
  * @brief  Macro definitions about SYSCON Peripheral stop Request.
  *         Values that can be passed to SYSCON_setPStopReq() as the \e id parameter.
  */
typedef enum {
    MODULE_STOP_CAN1 = 0U,    /*!< CAN1 */
    MODULE_STOP_DMA1 = 4U,    /*!< DMA1 */
    MODULE_STOP_LIN1 = 6U     /*!< LIN1 */
} SYSCON_StopModuleId;

/**
  * @}
  */

/** @defgroup SYSCON_COMMON_MACRO SYSCON Common Macro
  * @{
  * @brief  Macro definitions about SYSCON unlcok/lock definition.
  */
#define SYSCON_DEFAULT_KEY         (0x5A690000UL)    /*!< Default key */
#define SYSCON_DEFAULT_KEY_MASK    (0xFFFF0000UL)    /*!< Default key Mask */

/**
  * @}
  */

/** @defgroup SYSCON_NMIFLG SYSCON NMI Flag Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI flag register definition.
  */
#define SYSCON_NMIFLG_NMIINT          SYSCON_NMIFLG_NMIINT_M         /*!< NMI interrupt flag bit */
#define SYSCON_NMIFLG_HXTLSTOP        SYSCON_NMIFLG_HXTLSTOP_M       /*!< HXTL STOP flag */
#define SYSCON_NMIFLG_FLASH_ECCERR    SYSCON_NMIFLG_FLASHECCERR_M    /*!< FLASH_ECCERR flag */
#define SYSCON_NMIFLG_DTCM_ECCERR     SYSCON_NMIFLG_DTCMECCERR_M     /*!< DTCM_ECCERR flag */
#define SYSCON_NMIFLG_ITCM_ECCERR     SYSCON_NMIFLG_ITCMECCERR_M     /*!< ITCM_ECCERR flag */
#define SYSCON_NMIFLG_MCD_NMI         SYSCON_NMIFLG_MCDNMI_M         /*!< MCD_NMI flag */
#define SYSCON_NMIFLG_OSCCLKSTOP      SYSCON_NMIFLG_OSCCLKSTOP_M     /*!< OSCCLK STOP flag */
#define SYSCON_NMIFLG_CAN1NCE         SYSCON_NMIFLG_CAN1NCE_M        /*!< CAN1 NCE flag */
#define SYSCON_NMIFLG_SW_ERR          SYSCON_NMIFLG_SWERR_M          /*!< SW_ERR flag */
#define SYSCON_NMIFLG_VDDRDY_NMI      SYSCON_NMIFLG_VDDRDYNMI_M      /*!< VDDRDY_NMI flag */

/**
  * @}
  */

/** @defgroup SYSCON_NMIFLGCLR SYSCON NMI Flag Clear Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI flag clear register definition.
  */
#define SYSCON_NMIFLGCLR_NMIINT          (SYSCON_NMIFLGCLR_NMIINT_M)         /*!< NMI interrupt flag clear bit */
#define SYSCON_NMIFLGCLR_HXTLSTOP        (SYSCON_NMIFLGCLR_HXTLSTOP_M)       /*!< HXTL STOP flag clear bit */
#define SYSCON_NMIFLGCLR_FLASH_ECCERR    (SYSCON_NMIFLGCLR_FLASHECCERR_M)    /*!< FLASH_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_DTCM_ECCERR     (SYSCON_NMIFLGCLR_DTCMECCERR_M)     /*!< DTCM_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_ITCM_ECCERR     (SYSCON_NMIFLGCLR_ITCMECCERR_M)     /*!< ITCM_ECCERR flag clear bit */
#define SYSCON_NMIFLGCLR_MCD_NMI         (SYSCON_NMIFLGCLR_MCDNMI_M)         /*!< MCD_NMI flag clear bit */
#define SYSCON_NMIFLGCLR_OSCCLKSTOP      (SYSCON_NMIFLGCLR_OSCCLKSTOP_M)     /*!< OSCCLK STOP flag clear bit */
#define SYSCON_NMIFLGCLR_CAN1NCE         (SYSCON_NMIFLGCLR_CAN1NCE_M)        /*!< CAN1NCE flag clear bit */
#define SYSCON_NMIFLGCLR_SW_ERR          (SYSCON_NMIFLGCLR_SWERR_M)          /*!< SW_ERR flag clear bit */
#define SYSCON_NMIFLGCLR_VDDRDY_NMI      (SYSCON_NMIFLGCLR_VDDRDYNMI_M)      /*!< VDDRDY_NMI flag clear bit */

/**
  * @}
  */

/** @defgroup SYSCON_NMIFLGFRC SYSCON NMI Flag Force Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI flag force register definition.
  */
#define SYSCON_NMIFLGFRC_HXTLSTOP        (SYSCON_NMIFLGFRC_HXTLSTOP_M)       /*!< HXTL STOP flag force bit */
#define SYSCON_NMIFLGFRC_FLASH_ECCERR    (SYSCON_NMIFLGFRC_FLASHECCERR_M)    /*!< FLASH_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_DTCM_ECCERR     (SYSCON_NMIFLGFRC_DTCMECCERR_M)     /*!< DTCM_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_ITCM_ECCERR     (SYSCON_NMIFLGFRC_ITCMECCERR_M)     /*!< ITCM_ECCERR flag force bit */
#define SYSCON_NMIFLGFRC_MCD_NMI         (SYSCON_NMIFLGFRC_MCDNMI_M)         /*!< MCD_NMI flag force bit */
#define SYSCON_NMIFLGFRC_OSCCLKSTOP      (SYSCON_NMIFLGFRC_OSCCLKSTOP_M)     /*!< OSCCLK STOP flag force bit */
#define SYSCON_NMIFLGFRC_CAN1NCE         (SYSCON_NMIFLGFRC_CAN1NCE_M)        /*!< CAN1NCE flag force bit */
#define SYSCON_NMIFLGFRC_SW_ERR          (SYSCON_NMIFLGFRC_SWERR_M)          /*!< SW_ERR flag force bit */
#define SYSCON_NMIFLGFRC_VDDRDY_NMI      (SYSCON_NMIFLGFRC_VDDRDYNMI_M)      /*!< VDDRDY_NMI flag force bit */

/**
  * @}
  */
/** @defgroup SYSCON_NMISHDFLG SYSCON NMI Shadow Flag Register
  * @{
  * @brief  Macro definitions about the bit fields in the SYSCON NMI shadow flag register definition.
  */
#define SYSCON_NMISHDFLG_HXTLSTOP        (SYSCON_NMISHDFLG_HXTLSTOP_M)       /*!< HXTL STOP shadow NMI flag */
#define SYSCON_NMISHDFLG_FLASH_ECCERR    (SYSCON_NMISHDFLG_FLASHECCERR_M)    /*!< FLASH_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_DTCM_ECCERR     (SYSCON_NMISHDFLG_DTCMECCERR_M)     /*!< DTCM_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_ITCM_ECCERR     (SYSCON_NMISHDFLG_ITCMECCERR_M)     /*!< ITCM_ECCERR shadow NMI flag */
#define SYSCON_NMISHDFLG_MCD_NMI         (SYSCON_NMISHDFLG_MCDNMI_M)         /*!< MCD_NMI shadow NMI flag */
#define SYSCON_NMISHDFLG_OSCCLKSTOP      (SYSCON_NMISHDFLG_OSCCLKSTOP)       /*!< OSCCLKSTOP shadow NMI flag */
#define SYSCON_NMISHDFLG_CAN1NCE         (SYSCON_NMISHDFLG_CAN1NCE_M)        /*!< CAN1NCE shadow NMI flag */
#define SYSCON_NMISHDFLG_SW_ERR          (SYSCON_NMISHDFLG_SWERR_M)          /*!< SW_ERR shadow NMI flag */
#define SYSCON_NMISHDFLG_VDDRDY_NMI      (SYSCON_NMISHDFLG_VDDRDYNMI_M)      /*!< VDDRDY_NMI shadow NMI flag */

/**
  * @}
  */
/** @defgroup SYSCON_UNLOCK SYSCON UnLock Register
  * @{
  * @brief  Macro definitions about writing register UNLOCK
  */
#define SYSCON_LOCK      SYSCON->UNLOCK.WORDVAL = 0x55AA6698; __DSB()
#define SYSCON_UNLOCK    SYSCON->UNLOCK.WORDVAL = 0x55AA6699; __DSB()

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
  * \brief  Set Cortex-M7 LockUp enable.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - true : LockUp reset enable.
  *                    - false: LockUp reset disable.
  */
static inline void SYSCON_setLockUpReset (SYSCON_TypeDef *syscon, bool en)
{
    WRITE_REG(syscon->CFGR0.WORDVAL, SYSCON_DEFAULT_KEY | (uint32_t)en);
}

/**
  * \brief  Set SPI1 NCS PIN Select.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  spi1Ncs    SPI1_NCS select
  *                     This parameter can be any value of @ref SYSCON_SPI1NCSSEL.
  */
static inline void SYSCON_setSpi1Ncs (SYSCON_TypeDef *syscon, SYSCON_Spi1NcsSel spi1Ncs)
{
    MODIFY_REG(syscon->SPINCSCR.WORDVAL,
               SYSCON_SPINCSCR_SPI1NCS_SEL_M,
               SYSCON_DEFAULT_KEY | ((uint32_t)spi1Ncs << SYSCON_SPINCSCR_SPI1NCS_SEL_S));
}

/**
  * \brief  Set SPI2 NCS PIN Select.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  spi2Ncs    SPI2_NCS select
  *                     This parameter can be any value of @ref SYSCON_SPI2NCSSEL.
  */
static inline void SYSCON_setSpi2Ncs (SYSCON_TypeDef *syscon, SYSCON_Spi2NcsSel spi2Ncs)
{
    MODIFY_REG(syscon->SPINCSCR.WORDVAL,
               SYSCON_SPINCSCR_SPI2NCS_SEL_M,
               SYSCON_DEFAULT_KEY | ((uint32_t)spi2Ncs << SYSCON_SPINCSCR_SPI2NCS_SEL_S));
}

/**
  * \brief  Set the EXTI pin select.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  extiSel   Exti sel.
  *                    This parameter can be any value of @ref SYSCON_EXTISEL.
  * \param  pinSel    Exti pin sel.
  *                    This parameter can be any value of @ref SYSCON_EXTIPINSEL.
  */
static inline void SYSCON_setExtiSel (SYSCON_TypeDef *syscon, SYSCON_ExtiSel extiSel, SYSCON_ExtiPinSel pinSel)
{
    volatile uint32_t *pExtiCr = (volatile uint32_t *)(&(syscon->EXTICR1) + (extiSel >> 3));
    uint32_t shift = (extiSel & 0x7UL) << 2;

    MODIFY_REG(*pExtiCr, SYSCON_EXTICR1_EXTI0SEL_M << shift, (uint32_t)pinSel << shift);
}

/**
  * \brief  Set the EPWM clock fail brake.
  * \param  syscon             The base address of the SYSCON module.
  *                             - SYSCON: SYSCON base address index
  * \param  clockFailBrkEn     Enable Control for EPWM braking triggered by CLKFAIL.
  *                             - true : CLKFAIL brake epwm enabled.
  *                             - false: CLKFAIL brake epwm disabled.
  * \param  hxtlStopBrkEn      Enable Control for EPWM braking triggered by HXTL STOP.
  *                             - true : HXTLSTOP brake epwm enabled.
  *                             - false: HXTLSTOP brake epwm disabled.
  * \param  mirc2StopBrkEn     Enable Control for EPWM braking triggered by MIRC2 STOP.
  *                             - true : MIRC2STOP brake epwm enabled.
  *                             - false: MIRC2STOP brake epwm disabled.
  * \param  oscClkStopBrkEn    Enable Control for EPWM braking triggered by OSCCLK STOP.
  *                             - true : OSCCLKSTOP brake epwm enabled.
  *                             - false: OSCCLKSTOP brake epwm disabled.
  */
static inline void SYSCON_setEpwmBrkCr (SYSCON_TypeDef *syscon, \
                                        bool clockFailBrkEn, \
                                        bool hxtlStopBrkEn, \
                                        bool mirc2StopBrkEn,
                                        bool oscClkStopBrkEn)
{
    WRITE_REG(syscon->EPWMBRKCR.WORDVAL, SYSCON_DEFAULT_KEY | \
              ((uint32_t)clockFailBrkEn << SYSCON_EPWMBRKCR_CLKFAILBRKEN_S) | \
              ((uint32_t)hxtlStopBrkEn << SYSCON_EPWMBRKCR_HXTLSTOPBRKEN_S) | \
              ((uint32_t)mirc2StopBrkEn << SYSCON_EPWMBRKCR_MIRC2STOPBRKEN_S | \
              ((uint32_t)oscClkStopBrkEn << SYSCON_EPWMBRKCR_OSCCLKSTOPBRKEN_S)));
}

/**
  * \brief  Set the SYNCOUT Control.
  * \param  syscon        The base address of the SYSCON module.
  *                        - SYSCON: SYSCON base address index
  * \param  syncOutCyc    The SYNCOUT extension PCLK CYCLE count.
  *                        - uint8_t: 0x00 - 0x1F
  * \param  syncOutOe     SYNCOUT output enabled.
  *                        - true : SYNCOUT output enabled.
  *                        - false: SYNCOUT output disabled.
  * \param  syncOutSel    SYNCOUT source selection.
  *                        This parameter can be any value of @ref SYSCON_SYNCOUTSEL.
  */
static inline void SYSCON_setSyncOutSel (SYSCON_TypeDef *syscon, \
                                         uint8_t syncOutCyc, \
                                         bool syncOutOe, \
                                         SYSCON_SyncOutSel syncOutSel)
{
    WRITE_REG(syscon->SYNCOUTCR.WORDVAL, SYSCON_DEFAULT_KEY | \
              ((uint32_t)syncOutCyc << SYSCON_SYNCOUTCR_SYNCOUTCYC_S) | \
              ((uint32_t)syncOutOe << SYSCON_SYNCOUTCR_SYNCOUTOE_S) | \
              ((uint32_t)syncOutSel << SYSCON_SYNCOUTCR_SYNCOUTSEL_S));
}

/**
  * \brief  Get the SYNCOUT widening Status.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the SYNCOUT widening status bit.
  *                    - true : during SyncOut widenin status
  *                    - false: not during SyncOut widening status

  */
static inline bool SYSCON_getSyncOutStatus (SYSCON_TypeDef *syscon)
{
    return (READ_BIT(syscon->SYNCOUTCR.WORDVAL, SYSCON_SYNCOUTCR_SYNCOUTST_M) ? true : false);
}

/**
  * \brief  Set the SOCAOUT extension PCLK CYCLE count.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  cyc       CYCLE count.
  *                    - uint8_t: 0x00 - 0x1F
  */
static inline void SYSCON_setSocAOutCyc (SYSCON_TypeDef *syscon, uint8_t cyc)
{
    MODIFY_REG(syscon->SOCAOUTCR.WORDVAL, SYSCON_SOCAOUTCR_SOCAOUTCYC_M, ((uint32_t)cyc << SYSCON_SOCAOUTCR_SOCAOUTCYC_S));
}

/**
  * \brief  Set SOCA output enabled.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable SOCA output.
  *                    - true : Enable SOCA output.
  *                    - false: Disable SOCA output.
  */
static inline void SYSCON_setSocAOE (SYSCON_TypeDef *syscon, bool en)
{
    if (en)
    {
        SET_BIT(syscon->SOCAOUTCR.WORDVAL, SYSCON_SOCAOUTCR_SOCAOUTOE_M);
    }
    else
    {
        CLEAR_BIT(syscon->SOCAOUTCR.WORDVAL, SYSCON_SOCAOUTCR_SOCAOUTOE_M);
    }
}

/**
  * \brief  Set the EPWMSOCA enable/disable bit about EPWM.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  epwmNum    Epwm number.
  *                     This parameter can be any value of @ref SYSCON_EPWMSOCAEN.
  * \param  en         Enable or disable.
  *                     - true : Enable EPWMxSOCA.
  *                     - false: Disable EPWMxSOCA.
  */
static inline void SYSCON_setEpwmSocAEn (SYSCON_TypeDef *syscon, SYSCON_EpwmSocAEn epwmNum, bool en)
{
    if (en)
    {
        SET_BIT(syscon->SOCAOUTCR.WORDVAL, (0x1U << (uint32_t)epwmNum));
    }
    else
    {
        CLEAR_BIT(syscon->SOCAOUTCR.WORDVAL, (0x1U << (uint32_t)epwmNum));
    }
}

/**
  * \brief  Get the SOCAOUT widening status.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the SOCAOUT widening status.
  *                    - true : during SOCAOUT widening status.
  *                    - false: not during SOCAOUT widening status.
  * 
  */
static inline bool SYSCON_getSocAOutStatus (SYSCON_TypeDef *syscon)
{
    return (READ_BIT(syscon->SOCAOUTCR.WORDVAL, SYSCON_SOCAOUTCR_SOCAOUTST_M) ? true : false);
}

/**
  * \brief  Set the SOCBOUT extension PCLK CYCLE count.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  cyc       CYCLE coun.
  *                    - uint8_t: 0x00 - 0x1F
  */
static inline void SYSCON_setSocBOutCyc (SYSCON_TypeDef *syscon, uint8_t cyc)
{
    MODIFY_REG(syscon->SOCBOUTCR.WORDVAL, SYSCON_SOCBOUTCR_SOCBOUTCYC_M, ((uint32_t)cyc << SYSCON_SOCBOUTCR_SOCBOUTCYC_S));
}

/**
  * \brief  Set SOCB output enabled.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable.
  *                    - true : Enable SOCB output.
  *                    - false: Disable SOCB output.
  */
static inline void SYSCON_setSocBOE (SYSCON_TypeDef *syscon, bool en)
{
    if (en)
    {
        SET_BIT(syscon->SOCBOUTCR.WORDVAL, SYSCON_SOCBOUTCR_SOCBOUTOE_M);
    }
    else
    {
        CLEAR_BIT(syscon->SOCBOUTCR.WORDVAL, SYSCON_SOCBOUTCR_SOCBOUTOE_M);
    }
}

/**
  * \brief  Set the EPWMSOCB enable/disable bit about EPWM.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  epwmNum    Epwm number.
  *                     This parameter can be any value of @ref SYSCON_EPWMSOCBEN.
  * \param  en         Enable or disable.
  *                    - true : Enable EPWMxSOCB.
  *                    - false: Disable EPWMxSOCB.
  */
static inline void SYSCON_setEpwmSocBEn (SYSCON_TypeDef *syscon, SYSCON_EpwmSocBEn epwmNum, bool en)
{
    if (en)
    {
        SET_BIT(syscon->SOCBOUTCR.WORDVAL, (0x1U << (uint32_t)epwmNum));
    }
    else
    {
        CLEAR_BIT(syscon->SOCBOUTCR.WORDVAL, (0x1U << (uint32_t)epwmNum));
    }
}

/**
  * \brief  Get the SOCBOUT widening status.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the SOCBOUT widening status bit.
  *                    - true : during SOCBOUT widenin status.
  *                    - false: not during SOCBOUT widening status.
  */
static inline bool SYSCON_getSocBOutStatus (SYSCON_TypeDef *syscon)
{
    return (READ_BIT(syscon->SOCBOUTCR.WORDVAL, SYSCON_SOCBOUTCR_SOCBOUTST_M) ? true : false);
}

/**
  * \brief  Enable TIMER BASE Clock Synchronizatin.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        TBCLKSYNC enable bit.
  *                    - true : TBCLKSYNC enabled.
  *                    - false: TBCLKSYNC disabled.
  */
static inline void SYSCON_setTbClkSync (SYSCON_TypeDef *syscon, bool en)
{
    WRITE_REG(syscon->TBCLKSYNCCR.WORDVAL, SYSCON_DEFAULT_KEY | (uint32_t)en);
}

/**
  * \brief  GPIOA Low Power Mode Wake Up Selecting.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  lpmPins    Set the GPIOA pin for waking up the low-power mode.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline void SYSCON_setGpioALpmSel (SYSCON_TypeDef *syscon, uint32_t lpmPins)
{
    WRITE_REG(syscon->GPIOLPMSELA.WORDVAL, lpmPins);
}

/**
  * \brief  GPIOB Low Power Mode Wake Up Selecting.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  lpmPins    Set the GPIOB pin for waking up the low-power mode.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline void SYSCON_setGpioBLpmSel (SYSCON_TypeDef *syscon, uint32_t lpmPins)
{
    WRITE_REG(syscon->GPIOLPMSELB.WORDVAL, lpmPins);
}

/**
  * \brief  GPIOC Low Power Mode Wake Up Selecting.
  * \param  syscon     The base address of the SYSCON module.
  *                     - SYSCON: SYSCON base address index
  * \param  lpmPins    Set the GPIOC pin for waking up the low-power mode.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline void SYSCON_setGpioCLpmSel (SYSCON_TypeDef *syscon, uint32_t lpmPins)
{
    WRITE_REG(syscon->GPIOLPMSELC.WORDVAL, lpmPins);
}

/**
  * \brief  GPIOH Low Power Mode Wake Up Selecting.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  lpmPins    Set the GPIOH pin for waking up the low-power mode.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline void SYSCON_setGpioHLpmSel (SYSCON_TypeDef *syscon, uint32_t lpmPins)
{
    WRITE_REG(syscon->GPIOLPMSELH.WORDVAL, lpmPins);
}

/**
  * \brief  Set the CAN1 Software Reset.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  reset     CAN1 software reset.
  *                    - true : CAN1 software reset.
  *                    - false: CAN1 exit the software reset.
  */
static inline void SYSCON_resetCan1 (SYSCON_TypeDef *syscon, bool reset)
{
    MODIFY_REG(syscon->CANSWRCR.WORDVAL, SYSCON_CANSWRCR_CAN1SWR_M, SYSCON_DEFAULT_KEY | (uint32_t)reset);
}

/**
  * \brief  Enable the NMI Global interrupt bit.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  en        Enable or disable NMI global interrupt.
  *                    - true : Enable NMI global interrupt.
  *                    - false: Disable NMI global interrupt.
  */
static inline void SYSCON_enableNmiGlobalInterrupt (SYSCON_TypeDef *syscon, bool en)
{
    WRITE_REG(syscon->NMICFG.WORDVAL, SYSCON_DEFAULT_KEY | (uint32_t)en);
}

/**
  * \brief  Read the current state of NMI interrupt.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns Value of NMIFLG register.
  *                    - uint32_t: 0x0 - 0xFFFFFFFF
  */
static inline uint32_t SYSCON_getNmiStatus (SYSCON_TypeDef *syscon)
{
    return (READ_REG(syscon->NMIFLG.WORDVAL));
}

/**
  * \brief  Read the current state of individual NMI interrupts.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiflags    This parameter can be any value of @ref SYSCON_NMIFLG. 
  *                     These parameters can be combined together.
  *                      - SYSCON_NMIFLG_NMIINT
  *                      - SYSCON_NMIFLG_HXTLSTOP
  *                      - SYSCON_NMIFLG_FLASH_ECCERR
  *                      - SYSCON_NMIFLG_DTCM_ECCERR
  *                      - SYSCON_NMIFLG_ITCM_ECCERR
  *                      - SYSCON_NMIFLG_MCD_NMI
  *                      - SYSCON_NMIFLG_OSCCLKSTOP
  *                      - SYSCON_NMIFLG_CAN1NCE
  *                      - SYSCON_NMIFLG_SW_ERR
  *                      - SYSCON_NMIFLG_VDDRDY_NMI
  * \return Returns the Value of true or false.
  *                      - true: The NMI flags is set.
  *                      - false: The NMI flags is not set.
  */
static inline bool SYSCON_isNmiFlagSet (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    return (READ_BIT(syscon->NMIFLG.WORDVAL, nmiFlags) ? true : false);
}

/**
  * \brief  Function to clear individual NMI interrupts.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiflags    NMIFlags Bit mask of the NMI interrupts that user wants to clear.
  *                     This parameter can be any value of @ref SYSCON_NMIFLG. 
  *                     These parameters can be combined together.
  *                      - SYSCON_NMIFLGCLR_NMIINT
  *                      - SYSCON_NMIFLGCLR_HXTLSTOP
  *                      - SYSCON_NMIFLGCLR_FLASH_ECCERR
  *                      - SYSCON_NMIFLGCLR_DTCM_ECCERR
  *                      - SYSCON_NMIFLGCLR_ITCM_ECCERR
  *                      - SYSCON_NMIFLGCLR_MCD_NMI 
  *                      - SYSCON_NMIFLGCLR_OSCCLKSTOP
  *                      - SYSCON_NMIFLGCLR_CAN1NCE
  *                      - SYSCON_NMIFLGCLR_SW_ERR
  *                      - SYSCON_NMIFLGCLR_VDDRDY_NMI
  */
static inline void SYSCON_clearNmiStatus (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    WRITE_REG(syscon->NMIFLGCLR.WORDVAL, nmiFlags);
}

/**
  * \brief  Clear all the NMI Flags that are currently set.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  */
static inline void SYSCON_clearAllNmiFlags (SYSCON_TypeDef *syscon)
{
    volatile uint32_t nmiFlags;

    nmiFlags = SYSCON_getNmiStatus(syscon);
    WRITE_REG(syscon->NMIFLGCLR.WORDVAL, nmiFlags);
}

/**
  * \brief  Function to force individual NMI interrupt fail flags.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiFlags    NMIFlags Bit mask of the NMI interrupts that user wants to force.
  *                      - SYSCON_NMIFLGFRC_HXTLSTOP
  *                      - SYSCON_NMIFLGFRC_FLASH_ECCERR
  *                      - SYSCON_NMIFLGFRC_DTCM_ECCERR
  *                      - SYSCON_NMIFLGFRC_ITCM_ECCERR
  *                      - SYSCON_NMIFLGFRC_MCD_NMI
  *                      - SYSCON_NMIFLGFRC_OSCCLKSTOP
  *                      - SYSCON_NMIFLGFRC_CAN1NCE
  *                      - SYSCON_NMIFLGFRC_SW_ERR
  *                      - SYSCON_NMIFLGFRC_VDDRDY_NMI
  */
static inline void SYSCON_forceNmiFlags (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    WRITE_REG(syscon->NMIFLGFRC.WORDVAL, nmiFlags);
}

/**
  * \brief  Gets the NMI watchdog counter value.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the NMI watchdog counter register's current value.
  *                    - uint16_t: 0x00-0xFFFF
  */
static inline uint16_t SYSCON_getNmiWatchdogCounter (SYSCON_TypeDef *syscon)
{
    return ((uint16_t)syscon->NMIWDGCNT.WORDVAL);
}

/**
  * \brief  Sets the NMI watchdog period value.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  wdPeriod    wdPeriod is the 16-bit value at which a reset is generated.
  *                      - uint16_t: 0x00 - 0xFFFF
  */
static inline void SYSCON_setNmiWatchdogPeriod (SYSCON_TypeDef *syscon, uint16_t wdPeriod)
{
    WRITE_REG(syscon->NMIWDGPRD.WORDVAL, SYSCON_DEFAULT_KEY | wdPeriod);
}

/**
  * \brief  Gets the NMI watchdog period value.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the NMI watchdog period register's current value.
  *                    - uint16_t: 0x00 - 0xFFFF
  */
static inline uint16_t SYSCON_getNmiWatchdogPeriod (SYSCON_TypeDef *syscon)
{
    return ((uint16_t)syscon->NMIWDGPRD.WORDVAL);
}

/**
  * \brief  Read the current state of individual NMI interrupts.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \return Returns the value of NMISHDFLG register.
  *                    - uint32_t: 0x0 - 0xFFFFFFFF
  */
static inline uint32_t SYSCON_getNmiShadowFlagStatus (SYSCON_TypeDef *syscon)
{
    return (syscon->NMISHDFLG.WORDVAL);
}

/**
  * \brief  Check if the individual NMI shadow flags are set.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  nmiFlags    NMIFlags Bit mask of the NMI shadow flag.
  *                      - SYSCON_NMISHDFLG_HXTLSTOP
  *                      - SYSCON_NMISHDFLG_FLASH_ECCERR
  *                      - SYSCON_NMISHDFLG_DTCM_ECCERR
  *                      - SYSCON_NMISHDFLG_ITCM_ECCERR
  *                      - SYSCON_NMISHDFLG_MCD_NMI
  *                      - SYSCON_NMISHDFLG_OSCCLKSTOP
  *                      - SYSCON_NMISHDFLG_CAN1NCE
  *                      - SYSCON_NMISHDFLG_SW_ERR
  *                      - SYSCON_NMISHDFLG_VDDRDY_NMI
  *
  * \return Returns the current state of NMI shadow flags.
  *                      - true : Any of the NMI asked for in the parameter bit mask is set.
  *                      - false: None of the NMI requested in the parameter bit mask are.
  */
static inline bool SYSCON_isNmiShadowFlagSet (SYSCON_TypeDef *syscon, uint32_t nmiFlags)
{
    return (READ_BIT(syscon->NMISHDFLG.WORDVAL, nmiFlags) ? true : false);
}

/**
  * \brief  Set the Peripheral DOZE Request.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  moduleId    Peripheral module id.
  *                      This parameter can be any value of @ref SYSCON_DOZEMODULEID.
  * \param  reqEn       Enable or Diasble DOZE mode peripheral request.
  *                      - true : Enable DOZE mode peripheral request.
  *                      - false: Dsiable DOZE mode peripheral request.
  */
static inline void SYSCON_setPDozeReq (SYSCON_TypeDef *syscon, SYSCON_DozeModuleId moduleId, bool reqEn)
{
    MODIFY_REG(syscon->PDOZEREQR.WORDVAL, 
               (uint32_t)(1UL << moduleId), 
               SYSCON_DEFAULT_KEY | (uint32_t)(reqEn << moduleId));
}

/**
  * \brief  Set the Peripheral STOP Request.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  moduleId    Peripheral module id.
  *                      This parameter can be any value of @ref SYSCON_STOPMODULEID.
  * \param  reqEn       Enable or Disable STOP mode peripheral request.
  *                     - true : Enable STOP mode peripheral request.
  *                     - false: Disable STOP mode peripheral request.
  */
static inline void SYSCON_setPStopReq (SYSCON_TypeDef *syscon, SYSCON_StopModuleId moduleId, bool reqEn)
{
    MODIFY_REG(syscon->PSTOPREQR.WORDVAL, 
               (uint32_t)(1UL << moduleId), 
               SYSCON_DEFAULT_KEY | (uint32_t)(reqEn << moduleId));
}

/**
  * \brief  Get the Peripheral STOP Acknowledge.
  * \param  syscon      The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  moduleId    Peripheral module id.
  *                      This parameter can be any value of @ref SYSCON_STOPMODULEID.
  * \return Returns the stop acknowledgeBit.
  *                      - true : Stop mode acknowledge.
  *                      - false: Stop mode not acknowledge.
  */
static inline bool SYSCON_getPStopAck (SYSCON_TypeDef *syscon, SYSCON_StopModuleId moduleId)
{
    return (READ_BIT(syscon->PSTOPACKR.WORDVAL, (uint32_t)(1UL << moduleId)) ? true : false);
}

/**
  * \brief  Set the allowed configuration state of EPWM1.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ePWM1 config.
  *                       - true : Enable ePWM1 config.
  *                       - false: Disable ePWM1 config.
  */
static inline void SYSCON_setEpwm1Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM1EALLOW_M, ((uint32_t)allowedEn << 0UL));
}

/**
  * \brief  Set the allowed configuration state of EPWM2.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ePWM2 config.
  *                       - true : Enable ePWM2 config.
  *                       - false: Disable ePWM2 config.
  */
static inline void SYSCON_setEpwm2Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM2EALLOW_M, ((uint32_t)allowedEn << 1UL));
}

/**
  * \brief  Set the allowed configuration state of EPWM3.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ePWM3 config.
  *                       - true : Enable ePWM3 config.
  *                       - false: Disable ePWM3 config.
  */
static inline void SYSCON_setEpwm3Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM3EALLOW_M, ((uint32_t)allowedEn << 2UL));
}

/**
  * \brief  Set the allowed configuration state of EPWM4.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ePWM4 config.
  *                       - true : Enable ePWM4 config.
  *                       - false: Disable ePWM4 config.
  */
static inline void SYSCON_setEpwm4Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM4EALLOW_M, ((uint32_t)allowedEn << 3UL));
}

/**
  * \brief  Set the allowed configuration state of EPWM5.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ePWM5 config.
  *                       - true : Enable ePWM5 config.
  *                       - false: Disable ePWM5 config.
  */
static inline void SYSCON_setEpwm5Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM5EALLOW_M, ((uint32_t)allowedEn << 4UL));
}

/**
  * \brief  Set the allowed configuration state of EPWM6.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ePWM6 config.
  *                       - true : Enable ePWM6 config.
  *                       - false: Disable ePWM6 config.
  */
static inline void SYSCON_setEpwm6Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM6EALLOW_M, ((uint32_t)allowedEn << 5UL));
}

/**
  * \brief  Set the allowed configuration state of EPWM7.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ePWM7 config.
  *                       - true : Enable ePWM7 config.
  *                       - false: Disable ePWM7 config.
  */
static inline void SYSCON_setEpwm7Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_EPWM7EALLOW_M, ((uint32_t)allowedEn << 6UL));
}

/**
  * \brief  Set the allowed configuration state of ECAP1.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable eCAP1 config.
  *                       - true : Enable eCAP1 config.
  *                       - false: Disable eCAP1 config.
  */
static inline void SYSCON_setEcap1Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP1EALLOW_M, ((uint32_t)allowedEn << 24UL));
}

/**
  * \brief  Set the allowed configuration state of ECAP2.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable eCAP2 config.
  *                       - true : Enable eCAP2 config.
  *                       - false: Disable eCAP2 config.
  */
static inline void SYSCON_setEcap2Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP2EALLOW_M, ((uint32_t)allowedEn << 25UL));
}

/**
  * \brief  Set allowed configuration state of ECAP3.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable eCAP3 config.
  *                       - true : Enable eCAP3 config.
  *                       - false: Disable eCAP3 config.
  */
static inline void SYSCON_setEcap3Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW1.WORDVAL, SYSCON_SYSEALLOW1_ECAP3EALLOW_M, ((uint32_t)allowedEn << 26UL));
}

/**
  * \brief  Set allowed configuration state of ADCA.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ADCA config.
  *                       - true : Enable ADCA config.
  *                       - false: Disable ADCA config.
  */
static inline void SYSCON_setAdcaEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ADCAEALLOW_M, ((uint32_t)allowedEn << 0UL));
}

/**
  * \brief  Set allowed configuration state of ADCC.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ADCC config.
  *                       - true : Enable ADCC config.
  *                       - false: Disable ADCC config.
  */
static inline void SYSCON_setAdccEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ADCCEALLOW_M, ((uint32_t)allowedEn << 2UL));
}

/**
  * \brief  Set allowed configuration state of ANASS.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable ANASS config.
  *                       - true : Enable ANASS config.
  *                       - false: Disable ANASS config.
  */
static inline void SYSCON_setAnassEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_ANASSEALLOW_M, ((uint32_t)allowedEn << 12UL));
}

/**
  * \brief  Set allowed configuration state of XBAR.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable XBAR config.
  *                       - true : Enable XBAR config.
  *                       - false: Disable XBAR config.
  */
static inline void SYSCON_setXbarEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_XBAREALLOW_M, ((uint32_t)allowedEn << 15UL));
}

/**
  * \brief  Set allowed configuration state of CMPSS1.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable CMPSS1 config.
  *                       - true : Enable CMPSS1 config.
  *                       - false: Disable CMPSS1 config.
  */
static inline void SYSCON_setCmpss1Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS1EALLOW_M, ((uint32_t)allowedEn << 16UL));
}

/**
  * \brief  Set allowed configuration state of CMPSS2.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable CMPSS2 config.
  *                       - true : Enable CMPSS2 config.
  *                       - false: Disable CMPSS2 config.
  */
static inline void SYSCON_setCmpss2Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS2EALLOW_M, ((uint32_t)allowedEn << 17UL));
}

/**
  * \brief  Set allowed configuration state of CMPSS3.
  * \param  syscon       The base address of the SYSCON module.
  *                      - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable CMPSS3 config.
  *                       - true : Enable CMPSS3 config.
  *                       - false: Disable CMPSS3 config.
  */
static inline void SYSCON_setCmpss3Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS3EALLOW_M, ((uint32_t)allowedEn << 18UL));
}

/**
  * \brief  Set allowed configuration state of CMPSS4.
  * \param  syscon    The base address of the SYSCON module.
  *                    - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable CMPSS4 config.
  *                       - true : Enable CMPSS4 config.
  *                       - false: Disable CMPSS4 config.
  */
static inline void SYSCON_setCmpss4Eallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW2.WORDVAL, SYSCON_SYSEALLOW2_CMPSS4EALLOW_M, ((uint32_t)allowedEn << 19UL));
}

/**
  * \brief  Set allowed configuration state of GPIOA.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable GPIOA config.
  *                       - true : Enable GPIOA config.
  *                       - false: Disable GPIOA config.
  */
static inline void SYSCON_setGpioAEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOAEALLOW_M, ((uint32_t)allowedEn << 0UL));
}

/**
  * \brief  Set allowed configuration state of GPIOB.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable GPIOB config.
  *                       - true : Enable GPIOB config.
  *                       - false: Disable GPIOB config.
  */
static inline void SYSCON_setGpioBEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOBEALLOW_M, ((uint32_t)allowedEn << 1UL));
}

/**
  * \brief  Set allowed configuration state of GPIOC.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable GPIOC config.
  *                       - true : Enable GPIOC config.
  *                       - false: Disable GPIOC config.
  */
static inline void SYSCON_setGpioCEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOCEALLOW_M, ((uint32_t)allowedEn << 2UL));
}

/**
  * \brief  Set allowed configuration state of GPIOH.
  * \param  syscon       The base address of the SYSCON module.
  *                       - SYSCON: SYSCON base address index
  * \param  allowedEn    Enable or disable GPIOH config.
  *                       - true : Enable GPIOH config.
  *                       - false: Disable GPIOH config.
  */
static inline void SYSCON_setGpioHEallow (SYSCON_TypeDef *syscon, bool allowedEn)
{
    MODIFY_REG(syscon->SYSEALLOW3.WORDVAL, SYSCON_SYSEALLOW3_GPIOHEALLOW_M, ((uint32_t)allowedEn << 7UL));
}


#ifdef __cplusplus
}
#endif


#endif /* __SYSCON_H__ */
