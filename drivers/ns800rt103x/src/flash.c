/**
  * @file       flash.c
  * @author     xiacj
  * @brief      Function file for NS800RT1xxx flash module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "flash.h"


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
 * @brief  Erase all Flash pages except DataFlash
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note   User should disable icache and dcache.
 * @note   User should disable all flash Interrupt.
 * @note   User should link this funtion to RAM.
 */
uint8_t FLASH_eraseAllPages (void)
{
    FLASH_unlockRegs();
    FLASH_clearOperationCompleteFlag();

    uint32_t Bak = READ_REG(FLASH->CR.WORDVAL);
    Bak &= ~(FLASH_CR_PG_M | FLASH_CR_PER_M | FLASH_CR_MER_M | FLASH_CR_OPTPG_M | FLASH_CR_OPTER_M | FLASH_CR_OTPWEN_M);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_MER_M);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_MER_M | FLASH_CR_START_M);
    __DSB();
    while (FLASH_isBusy()){;}
    WRITE_REG(FLASH->CR.WORDVAL, Bak);

    FLASH_lockRegs();

    return !!FLASH_getOperationCompleteFlag();
}

/**
 * @brief  Erase Flash Page or DataFlash Page
 * @param  addr  addr of flash page need to be erased
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_erasePage (uint32_t addr)
{
    FLASH_unlockRegs();
    FLASH_clearOperationCompleteFlag();

    uint32_t Bak = READ_REG(FLASH->CR.WORDVAL);
    Bak &= ~(FLASH_CR_PG_M | FLASH_CR_PER_M | FLASH_CR_MER_M | FLASH_CR_OPTPG_M | FLASH_CR_OPTER_M | FLASH_CR_OTPWEN_M);
    WRITE_REG(FLASH->AR.WORDVAL, addr);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_PER_M);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_PER_M | FLASH_CR_START_M);
    __DSB();
    while (FLASH_isBusy()){;}
    WRITE_REG(FLASH->CR.WORDVAL, Bak);

    FLASH_lockRegs();

    return !!FLASH_getOperationCompleteFlag();
}

/**
 * @brief  Check Flash or DataFlash is blank or not
 * @param  addr     Addr of memery need to be check
 * @param  byteCnt  The quantity of data to be checked
 * @return Returns blank status
 *          - bool: 0: not blank
 *                  1: blank
 */
uint8_t FLASH_isBlank (uint32_t addr, uint32_t byteCnt)
{
    for (uint32_t i = 0; i < byteCnt; i++)
    {
        if ((*((__IO uint8_t *)(addr + i))) != 0xFF)
        {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief  Write data to Flash or DataFlash
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytes (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    if ((byteCnt % 8) || (addr % 8))
    {
        return 0;
    }
    if (((addr < FLASH_MAIN_STARTADDR)      || ((addr + byteCnt - 1) > FLASH_MAIN_ENDADDR)) && \
        ((addr < FLASH_DATAFLASH_STARTADDR) || ((addr + byteCnt - 1) > FLASH_DATAFLASH_ENDADDR)))
    {
        return 0;
    }

    FLASH_unlockRegs();
    uint32_t Bak = READ_REG(FLASH->CR.WORDVAL);
    Bak &= ~(FLASH_CR_PG_M | FLASH_CR_PER_M | FLASH_CR_MER_M | FLASH_CR_OPTPG_M | FLASH_CR_OPTER_M | FLASH_CR_OTPWEN_M);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_PG_M);
    __DSB();

    while (byteCnt)
    {
        uint64_t tmp64 = (((uint64_t)pBuf[0]) << 0 ) | (((uint64_t)pBuf[1]) << 8 ) |\
                         (((uint64_t)pBuf[2]) << 16) | (((uint64_t)pBuf[3]) << 24) |\
                         (((uint64_t)pBuf[4]) << 32) | (((uint64_t)pBuf[5]) << 40) |\
                         (((uint64_t)pBuf[6]) << 48) | (((uint64_t)pBuf[7]) << 56);
        *((__IO uint64_t *)addr) = tmp64;
        __DSB();
        while (FLASH_isBusy()){;}
        if ( *((__IO uint64_t *)addr) != tmp64 )
        {
            WRITE_REG(FLASH->CR.WORDVAL, Bak);
            FLASH_lockRegs();
            return 0;
        }
        byteCnt -= 8;
        addr += 8;
        pBuf += 8;
    }

    WRITE_REG(FLASH->CR.WORDVAL, Bak);
    FLASH_lockRegs();
    return 1;
}

/**
 * @brief  Modify Option Bytes.
 * @param  addr       Addr of option byte memery need to be modify
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_modifyOptionBytes (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    uint8_t BakUpBuf[FLASH_OPTIONBYTES_SIZE];

    if ((addr < FLASH_OPTIONBYTES_STARTADDR) || ((addr + byteCnt - 1) > FLASH_OPTIONBYTES_ENDADDR))
    {
        return 0;
    }

    /* Bakup Option Bytes */
    for (uint32_t i = 0; i < FLASH_OPTIONBYTES_SIZE; i++)
    {
        BakUpBuf[i] = *((uint8_t *)(FLASH_OPTIONBYTES_STARTADDR + i));
    }

    /* Modify BakupBuf to Object Values */
    uint32_t Offset = addr - FLASH_OPTIONBYTES_STARTADDR;
    for (uint32_t i = 0; i < byteCnt; i++)
    {
        BakUpBuf[i + Offset] = pBuf[i];
    }

    /* Prepare Complement Values */
    for ( uint32_t i = 0; i < 0x50; i += 8)
    {
        *((uint32_t *)(&BakUpBuf[i + 4])) = ~(*((uint32_t *)(&BakUpBuf[i + 0])));
    }

    /* Erase Option Bytes page */
    FLASH_unlockRegs();
    FLASH_unlockOptionBytes();
    FLASH_clearOperationCompleteFlag();

    uint32_t Bak = READ_REG(FLASH->CR.WORDVAL);
    Bak &= ~(FLASH_CR_PG_M | FLASH_CR_PER_M | FLASH_CR_MER_M | FLASH_CR_OPTPG_M | FLASH_CR_OPTER_M | FLASH_CR_OTPWEN_M);
    WRITE_REG(FLASH->AR.WORDVAL, FLASH_OPTIONBYTES_STARTADDR);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_OPTER_M);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_OPTER_M | FLASH_CR_START_M);
    __DSB();
    while (FLASH_isBusy()){;}
    WRITE_REG(FLASH->CR.WORDVAL, Bak);

    FLASH_lockOptionBytes();
    FLASH_lockRegs();

    if (FLASH_getOperationCompleteFlag() == 0)
    {
        return 0;
    }

    /* Write new Option Bytes to this page */
    FLASH_unlockRegs();
    FLASH_unlockOptionBytes();
    Bak = READ_REG(FLASH->CR.WORDVAL);
    Bak &= ~(FLASH_CR_PG_M | FLASH_CR_PER_M | FLASH_CR_MER_M | FLASH_CR_OPTPG_M | FLASH_CR_OPTER_M | FLASH_CR_OTPWEN_M);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_OPTPG_M);
    __DSB();

    uint32_t wrAddr;
    uint64_t wrData;
    for (uint32_t i = 8; i < FLASH_OPTIONBYTES_SIZE; i += 8)
    {
        wrData = (((uint64_t)BakUpBuf[i+0]) << 0 ) | (((uint64_t)BakUpBuf[i+1]) << 8 ) |\
                 (((uint64_t)BakUpBuf[i+2]) << 16) | (((uint64_t)BakUpBuf[i+3]) << 24) |\
                 (((uint64_t)BakUpBuf[i+4]) << 32) | (((uint64_t)BakUpBuf[i+5]) << 40) |\
                 (((uint64_t)BakUpBuf[i+6]) << 48) | (((uint64_t)BakUpBuf[i+7]) << 56);
        wrAddr = FLASH_OPTIONBYTES_STARTADDR + i;
        *((__IO uint64_t *)wrAddr) = wrData;
        __DSB();
        while (FLASH_isBusy()){;}
        if ( *((__IO uint64_t *)wrAddr) != wrData )
        {
            WRITE_REG(FLASH->CR.WORDVAL, Bak);
            FLASH_lockOptionBytes();
            FLASH_lockRegs();
            return 0;
        }
    }

    /* Write RPD to this page */
    wrData = (((uint64_t)BakUpBuf[0]) << 0 ) | (((uint64_t)BakUpBuf[1]) << 8 ) |\
             (((uint64_t)BakUpBuf[2]) << 16) | (((uint64_t)BakUpBuf[3]) << 24) |\
             (((uint64_t)BakUpBuf[4]) << 32) | (((uint64_t)BakUpBuf[5]) << 40) |\
             (((uint64_t)BakUpBuf[6]) << 48) | (((uint64_t)BakUpBuf[7]) << 56);
    wrAddr = FLASH_OPTIONBYTES_STARTADDR + 0;
    *((__IO uint64_t *)wrAddr) = wrData;
    __DSB();
    while (FLASH_isBusy()){;}
    if ( *((__IO uint64_t *)wrAddr) != wrData )
    {
        WRITE_REG(FLASH->CR.WORDVAL, Bak);
        FLASH_lockOptionBytes();
        FLASH_lockRegs();
        return 0;
    }

    WRITE_REG(FLASH->CR.WORDVAL, Bak);
    FLASH_lockOptionBytes();
    FLASH_lockRegs();
    return 1;
}

/**
 * @brief  Write data to OTP
 * @param  addr       Addr of memery need to be write into
 * @param  pBuf       Pointer to the data to be writed
 * @param  byteCnt    The quantity of data to be writed
 * @return Returns current option status
 *          - bool: 0: Fail
 *                  1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 * @note The value of byteCnt must be a multiple of 8.
 * @note The value of addr must be a multiple of 8.
 */
uint8_t FLASH_writeBytes2OTP (uint32_t addr, uint8_t *pBuf, uint32_t byteCnt)
{
    if ((byteCnt % 8) || (addr % 8))
    {
        return 0;
    }
    if ((addr < FLASH_OTPFLASH_STARTADDR) || ((addr + byteCnt - 1) > FLASH_OTPFLASH_ENDADDR))
    {
        return 0;
    }
    for (uint32_t i = 0; i < byteCnt; i++)
    {
        if ( *((__IO uint8_t *)(addr + i)) != 0xFF )
        {
            return 0;
        }
    }

    FLASH_unlockRegs();
    FLASH_unlockOtpArea();
    uint32_t Bak = READ_REG(FLASH->CR.WORDVAL);
    Bak &= ~(FLASH_CR_PG_M | FLASH_CR_PER_M | FLASH_CR_MER_M | FLASH_CR_OPTPG_M | FLASH_CR_OPTER_M | FLASH_CR_OTPWEN_M);
    WRITE_REG(FLASH->CR.WORDVAL, Bak | FLASH_CR_PG_M);
    __DSB();

    while (byteCnt)
    {
        uint64_t tmp64 = (((uint64_t)pBuf[0]) << 0 ) | (((uint64_t)pBuf[1]) << 8 ) |\
                         (((uint64_t)pBuf[2]) << 16) | (((uint64_t)pBuf[3]) << 24) |\
                         (((uint64_t)pBuf[4]) << 32) | (((uint64_t)pBuf[5]) << 40) |\
                         (((uint64_t)pBuf[6]) << 48) | (((uint64_t)pBuf[7]) << 56);
        *((__IO uint64_t *)addr) = tmp64;
        __DSB();
        while (FLASH_isBusy()){;}
        if ( *((__IO uint64_t *)addr) != tmp64 )
        {
            WRITE_REG(FLASH->CR.WORDVAL, Bak);
            FLASH_lockOtpArea();
            FLASH_lockRegs();
            return 0;
        }
        byteCnt -= 8;
        addr += 8;
        pBuf += 8;
    }

    WRITE_REG(FLASH->CR.WORDVAL, Bak);
    FLASH_lockOtpArea();
    FLASH_lockRegs();
    return 1;
}

/**
 * @brief  Config readout protect level.
 * @param  rdpLevel    readout protect level
 *                      - 0: No protect
 *                      - 1: readout protect level-1
 *                      - 2: readout protect level-2
 * @return Returns current option status
 *                      - bool: 0: Fail
 *                              1: Success
 * @note User should disable icache and dcache.
 * @note User should disable all flash Interrupt.
 */
uint8_t FLASH_configReadoutProtectLevel (uint32_t rdpLevel)
{
    uint8_t tmp = 0x00;
    uint8_t RpdKeys[] = {0xAA, 0x11, 0xCC};

    if (rdpLevel <= 2)
    {
        tmp = FLASH_modifyOptionBytes(FLASH_OPTIONBYTES_STARTADDR, &RpdKeys[rdpLevel], 1);
    }

    return tmp;
}

/**
 * @brief  Get readout protect level.
 * @return Returns readout protect level
 *          - 0: No protect
 *          - 1: readout protect level-1
 *          - 2: readout protect level-2
 */
uint8_t FLASH_getReadoutProtectLevel (void)
{
    uint32_t tmp32a = *((__IO uint32_t *)(FLASH_OPTIONBYTES_STARTADDR + 0));
    uint32_t tmp32b = *((__IO uint32_t *)(FLASH_OPTIONBYTES_STARTADDR + 4));
    if (tmp32a == ~tmp32b)
    {
        tmp32a &= 0xFF;
        if (tmp32a == 0xAA)
        {
            return 0;
        }
        if (tmp32a == 0xCC)
        {
            return 2;
        }
    }

    return 1;
}
