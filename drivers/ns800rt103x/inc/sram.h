/**
  * @file       sram.h
  * @author     Wuxiao
  * @brief      Header file for NS800RT1xxx sram module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SRAM_H__
#define __SRAM_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup SRAM_EXPORTED_TYPES SRAM Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'SRAM' module.
  */

/** @defgroup SRAM_LOCK_TSTCR SRAM KEY TSTCR
  * @{
  * @brief  Macro definitions about sram key and tstcr enable.
  */
#define SRAM_UNLOCK_KEY               ((uint32_t)0x695a0001UL)    /*!< SRAM UNLOCK KEY */
#define SRAM_LOCK_KEY                 ((uint32_t)0x695a0000UL)    /*!< SRAM LOCK KEY */
#define SRAM_TSTCR_BYPASS_EANBLE      ((uint32_t)0x66990001UL)    /*!< Enable SRAM ECCBYPASS */
#define SRAM_TSTCR_BYPASS_DISANBLE    ((uint32_t)0x66990000UL)    /*!< Disable SRAM ECCBYPASS */

/**
  * @}
  */

/** @defgroup ECC_MEMNUM ECC Enable Bit Config
  * @{
  * @brief  Macro definitions about SRAM Bank Ecc Enable ctrl.
  */
typedef enum {
    ITCM_ECC_MEM,    /*!< select itcm memory */
    DTCM_ECC_MEM     /*!< select dtcm memory */
} ECC_MemNum;

/**
  * @}
  */

/** @defgroup RWAIT_MEMNUM RWAIT Enable Bit Config
  * @{
  * @brief  Macro definitions about SRAM Bank Rwait Enable ctrl.
  */
typedef enum {
    ITCM_RWAIT_MEM,             /*!< select itcm memory */
    DTCM_RWAIT_MEM              /*!< select dtcm memory */
} Rwait_MemNum;

/**
  * @}
  */

/** @defgroup SRAM_STNUM SRAM Status 
  * @{
  * @brief  Macro definitions about SRAM status num.
  */
typedef enum {
    ITCMST1  = 0x4U,    /*!< sram itcm status1 */
    ITCMST2,            /*!< sram dtcm status2 */
    D0TCMST1,           /*!< sram dtcm status1 */
    D0TCMST2,           /*!< sram dtcm status2 */
    D1TCMST1,           /*!< sram dtcm status1 */
    D1TCMST2            /*!< sram dtcm status2 */
} SRAM_StNum;

/**
  * @}
  */

/** @defgroup SRAM_CHK typedef SRAM check error 
  * @{
  * @brief    Macro definitions about SRAM check operation error num
  */
typedef enum {
    ITCM_ECC1_OAD = 0x0U,    /*!< select itcm 1bit error */
    ITCM_ECC2_OAD,           /*!< select itcm 2bit error */
    D0TCM_ECC1_OAD,          /*!< select d0tcm 1bit error */
    D0TCM_ECC2_OAD,          /*!< select d0tcm 2bit error */
    D1TCM_ECC1_OAD,          /*!< select d1tcm 1bit error */
    D1TCM_ECC2_OAD           /*!< select d1tcm 2bit error */
} SRAM_Chk;

/**
  * @}
  */

/** @defgroup SRAM_ERROP SRAM error of operation
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    ECC1_NOACK = 0x0U,     /*!< error operation interrupt */ 
    ECC1_INT   = 0x01U,    /*!< SRAM error operation nmi */ 
    ECC2_INT   = 0x0U,     /*!< TCM error operation interrupt */ 
    ECC2_NMI   = 0x01U     /*!< TCM error operation interrupt */
} SRAM_ErrOp;

/**
  * @}
  */


/** @defgroup SRAM_ECCERR_ADR SRAM error of operation
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    ITCM_ECCERR_ADDR = 0x0U,    /*!< select core1 itcm memory */
    D0TCM_ECCERR_ADDR,          /*!< select core1 d0tcm memory */
    D1TCM_ECCERR_ADDR           /*!< select core1 d1tcm memory */
} SRAM_EccErr_Adr;

/**
  * @}
  */

/** @defgroup SRAM_EICTRL SRAM ECC error injection control register
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    ITCM_EI_EN = 0x0U,    /*!< select core1 itcm memory */
    D0TCM_EI_EN,          /*!< select core1 d0tcm memory */
    D1TCM_EI_EN           /*!< select core1 d1tcm memory */
} SRAM_EiCtrl;

/**
  * @}
  */

  /** @defgroup SRAM_ECCERRORINJMASK SRAM ECC error injection data MASK
  * @{
  * @brief    Macro definitions about SRAM operation
  */
typedef enum {
    ITCM_EI_DM_LOW = 0x0U,    /*!< select itcm low memory */
    ITCM_EI_DM_HIGH,          /*!< select itcm high memory */
    ITCM_EI_CHK,              /*!< select itcm chk memory */
    D0TCM_EI_DM,              /*!< select d0tcm  memory */
    D0TCM_EI_CHK,             /*!< select d0tcm chk memory */
    D1TCM_EI_DM,              /*!< select d1tcm  memory */
    D1TCM_EI_CHK              /*!< select d1tcm chk memory */
} SRAM_EccErrorInjMask;
 
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
 * \brief  get sram related register status.
 * \param  sram    SRAM pointer to a SRAM_TypeDef structure
 *                  - SRAM: SRAM base address index
 * \return Returned the value of check registor
 *                  - bit0:    SRAM1ST 
 *                  - bit2:    SRAM2ST1 
 *                  - bit3:    SRAM2ST2 
 *                  - bit4:    DTCMST1 
 *                  - bit5:    DTCMST2 
 *                  - bit6:    ITCMST1 
 *                  - bit7:    ITCMST2 
 */
static inline uint32_t SRAM_getStatusReg (SRAM_TypeDef *sram)
{
    return (uint32_t)sram->CHKCR.WORDVAL;
}

/**
 * \brief  Enable SRAM Registon Backup Sram Parity ctrl.
 * \param  sram       SRAM pointer to a SRAM_TypeDef structure
 *                     - SRAM: SRAM base address index
 */
static inline void SRAM_enableRegionBackupParityCtrl (SRAM_TypeDef *sram)
{
    SET_BIT(sram->CTRL.WORDVAL, (0x01UL<<22));
}

/**
 * @brief  Disable SRAM Registon  Backup Sram Parity ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 */
static inline void SRAM_disableRegionBackupParityCtrl (SRAM_TypeDef *sram)
{
    CLEAR_BIT(sram->CTRL.WORDVAL, (0x01UL<<22));
}

/**
 * \brief  Get SRAM ECC error address register
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  sramStNum    SRAM Reset Flag num of @ref SRAM_ECCERR_ADR 
 * \return Returned the error address
 */
 static inline uint32_t SRAM_getErrorAddress (SRAM_TypeDef *sram, SRAM_EccErr_Adr sramStNum)
 {
    uint32_t tmpreg;
    tmpreg = READ_REG(TYPE32(&sram->ITCM_ECC_ERR_ADDR.WORDVAL) + sramStNum); 
    return tmpreg;
 }


 /**
 * \brief  SRAM ECC error injection control register Enable
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  SRAM_EiCtrl    SRAM Reset Flag num of @ref SRAM_EICTRL 
 * \return Returned the error address
 */
 static inline void SRAM_enableEccInjectionCtrl (SRAM_TypeDef *sram, SRAM_EiCtrl sramStNum)
 {

     SET_BIT(sram->TCM_EI_CTRL.WORDVAL,0x1UL << sramStNum); 

 }

 /**
 * \brief  SRAM ECC error injection control register Disable
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  SRAM_EiCtrl    SRAM Reset Flag num of @ref SRAM_EICTRL 
 * \return Returned the error address
 */
 static inline void SRAM_DisableEccInjectionCtrl (SRAM_TypeDef *sram, SRAM_EiCtrl sramStNum)
 {

     CLEAR_BIT(sram->TCM_EI_CTRL.WORDVAL,0x1UL << sramStNum); 
 }

/**
 * \brief  SRAM ECC error injection data MASK
 * \param  sram               SRAM pointer to a SRAM_TypeDef structure
 *                             - SRAM: SRAM base address index
 * \param  sramStNum          SRAM Reset Flag num of @ref SRAM_ECCERRORINJMASK 
 * \param  EccCheckDataInv    The corresponding bit of ECC check data is inverted.
 * \return Returned the error address
 */
 static inline void SRAM_SetInvEccCheckData (SRAM_TypeDef *sram, SRAM_EccErrorInjMask sramStNum ,uint32_t EccCheckDataInv)
 {
    uint32_t addr;
    addr = (TYPE32(&sram->ITCM_EI_DM_LOW.WORDVAL) + sramStNum);
    if(sramStNum == ITCM_EI_CHK ||sramStNum == D0TCM_EI_CHK ||sramStNum == D1TCM_EI_CHK)
    {
        MODIFY_REG(addr,0xF,EccCheckDataInv);
    }
    else
    {
        MODIFY_REG(addr,0xFFFF,EccCheckDataInv);
    }
 }

/**
 * \brief  Configure the SRAM Read/Write wait cycle
 * \param  sram        SRAM pointer to a SRAM_TypeDef structure
 *                      - SRAM: SRAM base address index
 * \param  sram2Rwt    SRAM Read wait cycle
 *                      - 0: 0 wait cycle
 *                      - 1: 1 wait cycle
 * \param  sram2Wwt    SRAM write wait cycle
 *                      - 0: 0 wait cycle
 *                      - 1: 1 wait cycle
 */
extern void SRAM_configWtCr (SRAM_TypeDef *sram, uint32_t sram2Rwt, uint32_t sram2Wwt);

/**
 * \brief  Configure the SRAM Ecc check enable.
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  chk          SRAM CHKT Typedef
 *                       This parameter can be any value of @ref SRAM_CHK
 * \param  operation    SRAM ERROROPERATION Typedef
 *                       This parameter can be any value of @ref SRAM_ERROP
 */
extern void SRAM_configChkCr (SRAM_TypeDef *sram, SRAM_Chk chk, SRAM_ErrOp operation);

/**
 * \brief  Enable SRAM Registon Ecc ctrl.
 * \param  sram       SRAM pointer to a SRAM_TypeDef structure
 *                     - SRAM: SRAM base address index
 * \param  memSel     memroy select 
 *                     This parameter can be any value of @ref ECC_MEMNUM
 * 
 */
extern void SRAM_enableRegionEccCtrl (SRAM_TypeDef *sram, ECC_MemNum memSel);

/**
 * @brief  Disable SRAM Registon Ecc ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref ECC_MEMNUM
 */
extern void SRAM_disableRegionEccCtrl (SRAM_TypeDef *sram, ECC_MemNum memSel);

/**
 * \brief  Enable SRAM Registon Rwait ctrl.
 * \param  sram       SRAM pointer to a SRAM_TypeDef structure
 *                     - SRAM: SRAM base address index
 * \param  memSel     memroy select 
 *                     This parameter can be any value of @ref RWAIT_MEMNUM
 * 
 */
extern void SRAM_enableRegionRwaitCtrl (SRAM_TypeDef *sram, Rwait_MemNum memSel);

/**
 * @brief  Disable SRAM Registon Rwait ctrl.
 * @param  sram      SRAM pointer to a SRAM_TypeDef structure
 *                    - SRAM: SRAM base address index
 * @param  memSel    memroy select 
 *                    This parameter can be any value of @ref RWAIT_MEMNUM
 */
extern void SRAM_disableRegionRwaitCtrl (SRAM_TypeDef *sram, Rwait_MemNum memSel);

/**
 * \brief  Get SRAM Status from SRAM_CHKSR register.
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  sramStNum    SRAM Reset Flag num of @ref SRAM_STNUM 
 * \return Returned the status of check registor
 *                       - 1: error 
 *                       - 0: no error 
 */
extern uint32_t SRAM_getStatusFlag (SRAM_TypeDef *sram, SRAM_StNum sramStNum);


/**
 * \brief  Clear Status Register.
 * \param  sram         SRAM pointer to a SRAM_TypeDef structure
 *                       - SRAM: SRAM base address index
 * \param  sramStNum    SRAM Reset Flag num of @ref SRAM_STNUM
 */
extern void SRAM_clearStatusFlag (SRAM_TypeDef *sram, SRAM_StNum sramStNum);


#ifdef __cplusplus
}
#endif


#endif
