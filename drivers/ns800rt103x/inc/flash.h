/**
  * @file       flash.h
  * @author     xiacj
  * @brief       Header file for NS800RT1xxx flash module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __FLASH_H__
#define __FLASH_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_flash.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup FLASH_EXPORTED_TYPES FLASH Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'FLASH' module.
 */

/** @defgroup FLASH_UNLOCK_KEYS FLASH registers unlock keys
  * @{
  * @brief  Macro definitions about the unlock keys of the FLASH registers.
 */
#define FLASH_UNLOCKKEY1       (0x45670123UL)    /*!< FLASH unlock key1 */
#define FLASH_UNLOCKKEY2       (0xCDEF89ABUL)    /*!< FLASH unlock key2 */
#define FLASH_OTPUNLOCKKEY1    (0x192A083BUL)    /*!< FLASH otp unlock key1 */
#define FLASH_OTPUNLOCKKEY2    (0x6E7F4C5DUL)    /*!< FLASH otp unlock key2 */

/**
  * @}
 */

/** @defgroup FLASH_MEMORY_ADDRESS Flash memery addresses
  * @{
  * @brief  Macro definitions about the flash memory address.
 */
#define FLASH_MAIN_STARTADDR           (0x00400000UL)    /*!< Main Block Start Address */
#define FLASH_MAIN_ENDADDR             (0x0043FFFFUL)    /*!< Main Block End Address */
#define FLASH_MAIN_SIZE                (0x00040000UL)    /*!< Main Block Size */
#define FLASH_OPTIONBYTES_STARTADDR    (0x1FFFF800UL)    /*!< Option Bytes Start Address */
#define FLASH_OPTIONBYTES_ENDADDR      (0x1FFFFBFFUL)    /*!< Option Bytes End Address */
#define FLASH_OPTIONBYTES_SIZE         (1024UL)          /*!< Option Bytes Size */
#define FLASH_DATAFLASH_STARTADDR      (0x1FFF0000UL)    /*!< Data Flash Start Address */
#define FLASH_DATAFLASH_ENDADDR        (0x1FFF03FFUL)    /*!< Data Flash End Address */
#define FLASH_DATAFLASH_SIZE           (1024UL)          /*!< Data Flash Size */
#define FLASH_OTPFLASH_STARTADDR       (0x1FFF1000UL)    /*!< OTP Flash Start Address */
#define FLASH_OTPFLASH_ENDADDR         (0x1FFF13FFUL)    /*!< OTP Flash End Address */
#define FLASH_OTPFLASH_SIZE            (1024UL)          /*!< OTP Flash Size */
/**
  * @}
 */

/** @defgroup FLASH_LATENCY FLASH Latency 0-7
  * @{
  * @brief  Macro definitions about FLASH latency 0-7.
  */
typedef enum {
    FLASH_LATENCY_0 = 0UL,    /*!< FLASH Latency = 0 */
    FLASH_LATENCY_1,          /*!< FLASH Latency = 1 */
    FLASH_LATENCY_2,          /*!< FLASH Latency = 2 */
    FLASH_LATENCY_3,          /*!< FLASH Latency = 3 */
    FLASH_LATENCY_4,          /*!< FLASH Latency = 4 */
    FLASH_LATENCY_5,          /*!< FLASH Latency = 5 */
    FLASH_LATENCY_6,          /*!< FLASH Latency = 6 */
    FLASH_LATENCY_7           /*!< FLASH Latency = 7 */
} FLASH_Latency;

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
  * \brief  Set FLASH latency.
  * \param  latency    Flash :Latency
  *                       This parameter can be any value of @ref FLASH_LATENCY
  */
static inline void FLASH_setLatency (FLASH_Latency latency)
{
    __DSB();
    WRITE_REG(FLASH->ACR.WORDVAL, latency);
    __DSB();
}

/**
  * \brief  Unlock FLASH registers.
  */
static inline void FLASH_unlockRegs (void)
{
    WRITE_REG(FLASH->KEYR.WORDVAL, FLASH_UNLOCKKEY1);
    WRITE_REG(FLASH->KEYR.WORDVAL, FLASH_UNLOCKKEY2);
    __DSB();
}

/**
  * \brief  Lock FLASH registers.
  */
static inline void FLASH_lockRegs (void)
{
    __DSB();
    SET_BIT(FLASH->CR.WORDVAL, FLASH_CR_LOCK_M);
    __DSB();
}

/**
  * \brief  Unlock FLASH optionBytes.
  */
static inline void FLASH_unlockOptionBytes (void)
{
    WRITE_REG(FLASH->OPTKEYR.WORDVAL, FLASH_UNLOCKKEY1);
    WRITE_REG(FLASH->OPTKEYR.WORDVAL, FLASH_UNLOCKKEY2);
    __DSB();
}

/**
  * \brief  Lock FLASH OptionBytes.
  */
static inline void FLASH_lockOptionBytes (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR.WORDVAL, FLASH_CR_OPTEWEN_M);
    __DSB();
}

/**
  * \brief  Unlock FLASH OTP area.
  */
static inline void FLASH_unlockOtpArea (void)
{
    WRITE_REG(FLASH->OTPKEYR.WORDVAL, FLASH_OTPUNLOCKKEY1);
    WRITE_REG(FLASH->OTPKEYR.WORDVAL, FLASH_OTPUNLOCKKEY2);
    __DSB();
}

/**
  * \brief  Lock FLASH OTP area.
  */
static inline void FLASH_lockOtpArea (void)
{
    __DSB();
    SET_BIT(FLASH->CR.WORDVAL, FLASH_CR_OTPWEN_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Error Interrupt.
  */
static inline void FLASH_enableErrorInterrupt (void)
{
    __DSB();
    SET_BIT(FLASH->CR.WORDVAL, FLASH_CR_ERRIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Error Interrupt.
  */
static inline void FLASH_disableErrorInterrupt (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR.WORDVAL, FLASH_CR_ERRIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH Option Complete Interrupt.
  */
static inline void FLASH_enableOperationCompleteInterrupt (void)
{
    __DSB();
    SET_BIT(FLASH->CR.WORDVAL, FLASH_CR_EOPIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH Option Complete Interrupt.
  */
static inline void FLASH_disableOperationCompleteInterrupt (void)
{
    __DSB();
    CLEAR_BIT(FLASH->CR.WORDVAL, FLASH_CR_EOPIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH ECC 1 bit Error Interrupt.
  */
static inline void FLASH_enableEcc1BitErrorInterrupt (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_SNIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH ECC 1 bit Error Interrupt.
  */
static inline void FLASH_disableEcc1BitErrorInterrupt (void)
{
    __DSB();
    CLEAR_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_SNIE_M);
    __DSB();
}

/**
  * \brief  Enable FLASH ECC 2 bit Error Interrupt.
  */
static inline void FLASH_enableEcc2BitErrorInterrupt (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_DBIE_M);
    __DSB();
}

/**
  * \brief  Disable FLASH ECC 2 bit Error Interrupt.
  */
static inline void FLASH_disableEcc2BitErrorInterrupt (void)
{
    __DSB();
    CLEAR_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_DBIE_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Option Complete Flag.
  */
static inline void FLASH_clearOperationCompleteFlag (void)
{
    WRITE_REG(FLASH->SR.WORDVAL, FLASH_SR_EOP_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Write Protect Error Flag.
  */
static inline void FLASH_clearProtectErrorFlag (void)
{
    WRITE_REG(FLASH->SR.WORDVAL, FLASH_SR_WRPRTERR_M);
    __DSB();
}

/**
  * \brief  Clear FLASH Program Error Flag.
  */
static inline void FLASH_clearProgramErrorFlag (void)
{
    WRITE_REG(FLASH->SR.WORDVAL, FLASH_SR_PGERR_M);
    __DSB();
}

/**
  * \brief  Clear FLASH ECC 1 bit Error Flag.
  */
static inline void FLASH_clearEcc1BitErrorFlag (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_SNFLAG_M);
    __DSB();
}

/**
  * \brief  Clear FLASH ECC 2 bit Error Flag.
  */
static inline void FLASH_clearEcc2BitErrorFlag (void)
{
    __DSB();
    SET_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_DBFLAG_M);
    __DSB();
}

/**
  * \brief  Get FLASH Option Complete Flag.
  * \return Returns bit value of FLASH_SR.EOP bit
  *           - uint32_t: 0: FLASH_SR.EOP = 0
  *                       x: FLASH_SR.EOP = 1
  */
static inline uint32_t FLASH_getOperationCompleteFlag (void)
{
    return READ_BIT(FLASH->SR.WORDVAL, FLASH_SR_EOP_M);
}

/**
  * \brief  Get FLASH Write Protect Error Flag.
  * \return Returns bit value of FLASH_SR.WRPRTERR bit
  *           - uint32_t: 0: FLASH_SR.WRPRTERR = 0
  *                       x: FLASH_SR.WRPRTERR = 1
  */
static inline uint32_t FLASH_getProtectErrorFlag (void)
{
    return READ_BIT(FLASH->SR.WORDVAL, FLASH_SR_WRPRTERR_M);
}

/**
  * \brief  Get FLASH Program Error Flag.
  * \return Returns bit value of FLASH_SR.PGERR bit
  *           - uint32_t: 0: FLASH_SR.PGERR = 0
  *                       x: FLASH_SR.PGERR = 1
  */
static inline uint32_t FLASH_getProgramErrorFlag (void)
{
    return READ_BIT(FLASH->SR.WORDVAL, FLASH_SR_PGERR_M);
}

/**
  * \brief  Get FLASH ECC 1 bit Error Flag.
  * \return Returns bit value of FLASH_ECCCR.SNECC bit
  *           - uint32_t: 0: FLASH_ECCCR.SNECC = 0
  *                       x: FLASH_ECCCR.SNECC = 1
  */
static inline uint32_t FLASH_getEcc1BitErrorFlag (void)
{
    return READ_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_SNFLAG_M);
}

/**
  * \brief  Get FLASH ECC 2 bit Error Flag.
  * \return Returns bit value of FLASH_ECCCR.DBECC bit
  *           - uint32_t: 0: FLASH_ECCCR.DBECC = 0
  *                       x: FLASH_ECCCR.DBECC = 1
  */
static inline uint32_t FLASH_getEcc2BitErrorFlag (void)
{
    return READ_BIT(FLASH->ECCCR.WORDVAL, FLASH_ECCCR_DBFLAG_M);
}

/**
  * \brief  Get FLASH ECC Error Address.
  * \return Returns ECC error address
  */
static inline uint32_t FLASH_getEccErrorAddr (void)
{
    return READ_REG(FLASH->ECCADDR.WORDVAL);
}

/**
  * \brief  Determine whether Flash is busy or not.
  * \return Returns bit value of FLASH_SR.BSY bit
  *           - uint32_t: 0: FLASH_SR.BSY=0
  *                       x: FLASH_SR.BSY=1
  */
static inline uint32_t FLASH_isBusy (void)
{
    return READ_BIT(FLASH->SR.WORDVAL, FLASH_SR_BUSY_M);
}

/**
  * \brief  Erase all Flash pages except DataFlash
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note    User should disable icache and dcache.
  * \note    User should disable all flash Interrupt.
  * \note    User should link this funtion to RAM.
  */
extern uint8_t FLASH_eraseAllPages (void);

/**
  * \brief  Erase Flash Page or DataFlash Page
  * \param  addr    addr of flash page need to be erased
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note    User should disable icache and dcache.
  * \note    User should disable all flash Interrupt.
  */
extern uint8_t FLASH_erasePage (uint32_t addr);

/**
  * \brief  Check Flash or DataFlash is blank or not
  * \param  addr     Addr of memery need to be check
  * \param  byteCnt  The quantity of data to be checked
  * \return Returns blank status
  *          - bool: 0: not blank
  *                  1: blank
  */
extern uint8_t FLASH_isBlank (uint32_t addr, uint32_t byteCnt);

/**
  * \brief  Write data to Flash or DataFlash
  * \param  addr       Addr of memery need to be write into
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  * \note The value of byteCnt must be a multiple of 8.
  * \note The value of addr must be a multiple of 8.
  */
extern uint8_t FLASH_writeBytes (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Write data to OTP
  * \param  addr       Addr of memery need to be write into
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *          - bool: 0: Fail
  *                  1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  * \note The value of byteCnt must be a multiple of 8.
  * \note The value of addr must be a multiple of 8.
  */
extern uint8_t FLASH_writeBytes2OTP (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Get Write Protect Status.
  * \param  pBuf    Pointer to the write protect status buf
  * \note Returns protect status(16 bytes) at pBuf
  */
extern void FLASH_getWriteProtectStatus (uint8_t *pBuf);

/**
  * \brief  Modify Option Bytes.
  * \param  addr       Addr of option byte memery need to be modify
  * \param  pBuf       Pointer to the data to be writed
  * \param  byteCnt    The quantity of data to be writed
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  */
extern uint8_t FLASH_modifyOptionBytes (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Config readout protect.
  * \param  rdpLevel    readout protect level
  *                       - 0: No protect
  *                       - 1: readout protect level-1
  *                       - 2: readout protect level-2
  * \return Returns current option status
  *           - bool: 0: Fail
  *                   1: Success
  * \note User should disable icache and dcache.
  * \note User should disable all flash Interrupt.
  */
extern uint8_t FLASH_configReadoutProtectLevel (uint32_t rdpLevel);

/**
  * \brief  Get readout protect level.
  * \return Returns readout protect level
  *          - 0: No protect
  *          - 1: readout protect level-1
  *          - 2: readout protect level-2
  */
extern uint8_t FLASH_getReadoutProtectLevel (void);


#ifdef __cplusplus
}
#endif


#endif /* __FLASH_H__ */
