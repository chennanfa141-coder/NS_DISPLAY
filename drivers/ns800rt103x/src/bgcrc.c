/**
  * @file       bgcrc.c
  * @author     yangjun
  * @brief      Function file for NS800RT1xxx bgcrc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "bgcrc.h"


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
  * @brief  Initializes the BGCRC peripheral for 16-bit CRC computation.
  * @param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  * @param  poly             16-bit polynomial
  *                           This parameter can be any value of uint16_t
  * @param  initValue        16-bit initial value
  *                           This parameter can be any value of uint16_t
  * @param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref CRC_OUTPUTXORENABLE
  * @param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref CRC_REVERSEENABLE
  */
extern void BGCRC_initCrc16 (BGCRC_TypeDef *bgcrc, uint16_t poly, uint16_t initValue,
                             BGCRC_OutputXorType xorType, BGCRC_ReverseEnable enableReverse)
{
    WRITE_REG(bgcrc->CTRL.WORDVAL, (uint32_t)enableReverse | (uint32_t)xorType | BGCRC_CTRL_INI_M);
    WRITE_REG(bgcrc->POLY.WORDVAL, poly);
    WRITE_REG(bgcrc->DATA.WORDVAL, initValue);
    CLEAR_BIT(bgcrc->CTRL.WORDVAL, BGCRC_CTRL_INI_M);
}

/**
  * @brief  Initializes the CRC peripheral for 32-bit CRC computation.
  * @param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  * @param  poly             32-bit polynomial
  *                           This parameter can be any value of uint32_t
  * @param  initValue        32-bit initial value
  *                           This parameter can be any value of uint32_t
  * @param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref CRC_OUTPUTXORENABLE
  * @param  enableReverse    Whether to reverse the input and output data
                              This parameter can be any value of @ref CRC_REVERSEENABLE
  */
extern void BGCRC_initCrc32 (BGCRC_TypeDef *bgcrc, uint32_t poly, uint32_t initValue,
                             BGCRC_OutputXorType xorType, BGCRC_ReverseEnable enableReverse)
{
    WRITE_REG(bgcrc->CTRL.WORDVAL, (uint32_t)enableReverse | (uint32_t)xorType | BGCRC_CTRL_INI_M | BGCRC_CTRL_WIDTH_M);
    WRITE_REG(bgcrc->POLY.WORDVAL, poly);
    WRITE_REG(bgcrc->DATA.WORDVAL, initValue);
    CLEAR_BIT(bgcrc->CTRL.WORDVAL, BGCRC_CTRL_INI_M);
}

/**
  * @brief  Writes data to data register.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  */
void BGCRC_writeData (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    while (byteCnt >= 4U)
    {
        WRITE_REG(bgcrc->DATA.WORDVAL, TYPE32(pBuf));
        byteCnt -= 4U;
        pBuf += 4U;
    }

    while (byteCnt)
    {
        WRITE_REG(TYPE8(&bgcrc->DATA.WORDVAL), *pBuf);
        byteCnt--;
        pBuf++;
    }
}

/**
  * @brief  Calculates CRC16/IBM algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Ibm (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x8005U, 0x0000U, BGCRC_OUTPUT_XOR_ALL0, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/MAXIM algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Maxim (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x8005U, 0x0000U, BGCRC_OUTPUT_XOR_ALL1, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/USB algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Usb (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x8005U, 0xFFFFU, BGCRC_OUTPUT_XOR_ALL1, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/MODBUS algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Modbus (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x8005U, 0xFFFFU, BGCRC_OUTPUT_XOR_ALL0, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/CCITT algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Ccitt (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x1021U, 0x0000U, BGCRC_OUTPUT_XOR_ALL0, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/CCITTFALSE algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16CcittFalse (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x1021U, 0xFFFFU, BGCRC_OUTPUT_XOR_ALL0, BGCRC_REVERSE_DISABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_DISABLE);
}

/**
  * @brief  Calculates CRC16/X25 algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16X25 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x1021U, 0xFFFFU, BGCRC_OUTPUT_XOR_ALL1, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_ENABLE);
}

/**
  * @brief  Calculates CRC16/XMODEM algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
uint16_t BGCRC_calcCrc16Xmodem (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc16(bgcrc, 0x1021U, 0x0000U, BGCRC_OUTPUT_XOR_ALL0, BGCRC_REVERSE_DISABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc16Result(bgcrc, BGCRC_REVERSE_DISABLE);
}

/**
  * @brief  Calculates CRC32 algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
uint32_t BGCRC_calcCrc32 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc32(bgcrc, 0x04C11DB7U, 0xFFFFFFFFU, BGCRC_OUTPUT_XOR_ALL1, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc32Result(bgcrc);
}

/**
  * @brief  Calculates CRC32/MPEG2 algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
uint32_t BGCRC_calcCrc32Mpeg2 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc32(bgcrc, 0x04C11DB7U, 0xFFFFFFFFU, BGCRC_OUTPUT_XOR_ALL0, BGCRC_REVERSE_DISABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc32Result(bgcrc);
}

/**
  * @brief  Calculates CRC32/KOOPMAN algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
uint32_t BGCRC_calcCrc32Koopman (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc32(bgcrc, 0x741B8CD7U, 0xFFFFFFFFU, BGCRC_OUTPUT_XOR_ALL1, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc32Result(bgcrc);
}

/**
  * @brief  Calculates CRC32C algorithm.
  * @param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * @param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * @param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * @return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
uint32_t BGCRC_calcCrc32C(BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt)
{
    BGCRC_initCrc32(bgcrc, 0x1EDC6F41U, 0xFFFFFFFFU, BGCRC_OUTPUT_XOR_ALL1, BGCRC_REVERSE_ENABLE);
    BGCRC_writeData(bgcrc, pBuf, byteCnt);
    return BGCRC_getCrc32Result(bgcrc);
}

/**
 * @brief Configures monitor.
 * @param bgcrc            Pointer to a BGCRC_TypeDef structure
 *                          - BGCRC1: BGCRC1 base address index
 * @param enableMonitor    Whether to enable the monitor
 *                          This parameter can be any value of @ref BGCRC_MONITORENABLE
 * @param mode             The mode (reading mode/writing mode) of the monitor
 *                          This parameter can be any value of @ref BGCRC_MONITORMODE
 * @param addr             The address to be continuously monitored
 *                          This parameter can be any value of uint32_t
 * @return Returns the status of function execution
 *                          - True:  The monitor are successfully configured
 *                          - False: Monitor configuration failed
 */
bool BGCRC_configMonitor (BGCRC_TypeDef *bgcrc, BGCRC_MonitorEnable enableMonitor,
                          BGCRC_MonitorMode mode, uint32_t addr)
{
    if ((addr >= BGCRC_MONITOR_ADDR_APB2_MIN) && (addr <= BGCRC_MONITOR_ADDR_APB2_MAX))
    {
        WRITE_REG(bgcrc->MONADDR1.WORDVAL, addr);
        WRITE_REG(bgcrc->MCTRL.WORDVAL, (uint32_t)mode | (uint32_t)enableMonitor | BGCRC_MONITOR_BUS_APB2);
        return true;
    }
    else if ((addr >= BGCRC_MONITOR_ADDR_AHB4_MIN) && (addr <= BGCRC_MONITOR_ADDR_AHB4_MAX))
    {
        WRITE_REG(bgcrc->MONADDR1.WORDVAL, addr);
        WRITE_REG(bgcrc->MCTRL.WORDVAL, (uint32_t)mode | (uint32_t)enableMonitor | BGCRC_MONITOR_BUS_AHB4);
        return true;
    }
    else
    {
        CLEAR_REG(bgcrc->MONADDR1.WORDVAL);
        CLEAR_REG(bgcrc->MCTRL.WORDVAL);
        return false;
    }
}
