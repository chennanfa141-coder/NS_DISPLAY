/**
  * @file       bgcrc.h
  * @author     yangjun
  * \brief      Header file for NS800RT1xxx bgcrc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __BGCRC_H__
#define __BGCRC_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_bgcrc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup BGCRC_EXPORTED_TYPES BGCRC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'BGCRC' module.
  */

/** @defgroup BGCRC_MONITORADDRLIMITS BGCRC Monitor Address Limits
  * @{
  * @brief  Macro definitions about minimum and maximum address values (of diffrent bus) for monitoring.
  */
#define BGCRC_MONITOR_ADDR_AHB4_MIN    (0x40080000UL)    /*!< Minimum address value of AHB4 bus */
#define BGCRC_MONITOR_ADDR_AHB4_MAX    (0x4008BFFFUL)    /*!< Maximum address value of AHB4 bus */
#define BGCRC_MONITOR_ADDR_APB2_MIN    (0x40042000UL)    /*!< Minimum address value of APB2 bus */
#define BGCRC_MONITOR_ADDR_APB2_MAX    (0x40059FFFUL)    /*!< Maximum address value of APB2 bus */

/**
  * @}
  */

/** @defgroup BGCRC_OUTPUTXORTYPE BGCRC Output Xor Operation Type
  * @{
  * @brief  Definitions about the XOR binary sequence type applied to output data.
  */
typedef enum {
    BGCRC_OUTPUT_XOR_ALL0 = 0x0UL,                       /*!< The output data is XORed operated with
                                                              all-zero binary sequence of the same bit length */
    BGCRC_OUTPUT_XOR_ALL1 = 0x1UL << BGCRC_CTRL_XOR_S    /*!< The output data is XORed operated with
                                                              all-one binary sequence of the same bit length */
} BGCRC_OutputXorType;

/**
  * @}
  */

/** @defgroup BGCRC_REVERSEENABLE BGCRC Reverse Enablement
  * @{
  * @brief  Definitions about whether to enable reversing function.
  * @note   Reverse the input data: Reverses the order of the bits within a byte
  *         without reversing the order of the bytes,
  *         starting calculation with the byte at the lowest memory address.
  * @note   Reverse the output data: Reverses the order of all bits
            in a 32-bit word or a 16-bit halfword.
  */
typedef enum {
    BGCRC_REVERSE_DISABLE = 0xCUL << BGCRC_CTRL_REVERSE_S,    /*!< Disable Reverse */
    BGCRC_REVERSE_ENABLE = 0xAUL << BGCRC_CTRL_REVERSE_S      /*!< Enable Reverse */
} BGCRC_ReverseEnable;

/**
  * @}
  */

/** @defgroup BGCRC_MONITORENABLE BGCRC Monitor Enablement
  * @{
  * @brief  Definitions about whether to enable monitor function.
  */
typedef enum {
    BGCRC_MONITOR_DISABLE = 0x0UL,                         /*!< Disable monitor */
    BGCRC_MONITOR_ENABLE = 0x1UL << BGCRC_MCTRL_MONEN_S    /*!< Enable monitor */
} BGCRC_MonitorEnable;

/**
  * @}
  */

/** @defgroup BGCRC_MONITORMODE BGCRC Monitor Mode
  * @{
  * @brief  Definitions about the working mode (reading mode/writing mode) of the monitor.
  */
typedef enum {
    BGCRC_MONITOR_MODE_READ = 0x0UL,                            /*!< Reading mode */
    BGCRC_MONITOR_MODE_WRITE = 0x1UL << BGCRC_MCTRL_MONSRC_S    /*!< Writing mode */
} BGCRC_MonitorMode;

/**
  * @}
  */

/** @defgroup BGCRC_MONITORBUSTYPE BGCRC Monitor Bus Type
  * @{
  * @brief  Definitions about the type of bus on which the monitored register resides.
  */
typedef enum {
    BGCRC_MONITOR_BUS_NONE = 0x0UL,                           /*!< Do not monitor any addresses */
    BGCRC_MONITOR_BUS_AHB4 = 0x2UL << BGCRC_MCTRL_ADDR2_S,    /*!< AHB4 (Register Address Value: 0x40080000UL ~ 0x4008BFFFUL) */
    BGCRC_MONITOR_BUS_APB2 = 0x3UL << BGCRC_MCTRL_ADDR2_S     /*!< APB2 (Register Address Value: 0x40042000UL ~ 0x40059FFFUL) */
} BGCRC_MonitorBusType;

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
  * \brief  ​​Selects the XOR binary sequence type applied to output data.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  xorType    Definitions about the XOR binary sequence type applied to output data.
  *                     This parameter can be any value of @ref BGCRC_OUTPUTXORTYPE
  */
static inline void BGCRC_selectOutputXorType (BGCRC_TypeDef *bgcrc, BGCRC_OutputXorType xorType)
{
    if (xorType == BGCRC_OUTPUT_XOR_ALL1)
    {
        SET_BIT(bgcrc->CTRL.WORDVAL, BGCRC_CTRL_XOR_M);
    }
    else
    {
        CLEAR_BIT(bgcrc->CTRL.WORDVAL, BGCRC_CTRL_XOR_M);
    }
}

/**
  * \brief  Enables reversing function.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  */
static inline void BGCRC_enableReverse (BGCRC_TypeDef *bgcrc)
{
    MODIFY_REG(bgcrc->CTRL.WORDVAL, BGCRC_CTRL_REVERSE_M, BGCRC_REVERSE_ENABLE);
}

/**
  * \brief  Disables reversing function.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  */
static inline void BGCRC_disableReverse (BGCRC_TypeDef *bgcrc)
{
    MODIFY_REG(bgcrc->CTRL.WORDVAL, BGCRC_CTRL_REVERSE_M, BGCRC_REVERSE_DISABLE);
}

/**
  * \brief  Gets CRC-16 result.
  * \param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  * \param  enableReverse    Definitions about whether to enable reversing function
  *                           This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
static inline uint16_t BGCRC_getCrc16Result (BGCRC_TypeDef *bgcrc, BGCRC_ReverseEnable enableReverse)
{
    if (enableReverse == BGCRC_REVERSE_ENABLE)
    {
        return READ_REG(bgcrc->DATA.WORDVAL) >> 16U;
    }
    else
    {
        return READ_REG(bgcrc->DATA.WORDVAL);
    }
}

/**
  * \brief  Gets CRC-32 result.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  */
static inline uint32_t BGCRC_getCrc32Result (BGCRC_TypeDef *bgcrc)
{
    return READ_REG(bgcrc->DATA.WORDVAL);
}

/**
  * \brief  Enables the function of moniter.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  */
static inline void BGCRC_enableMonitor (BGCRC_TypeDef *bgcrc)
{
    SET_BIT(bgcrc->MCTRL.WORDVAL, BGCRC_MCTRL_MONEN_M);
}

/**
  * \brief  Disables the function of monitor.
  * \param  bgcrc    Pointer to a BGCRC_TypeDef structure
  *                   - BGCRC1: BGCRC1 base address index
  */
static inline void BGCRC_disableMonitor (BGCRC_TypeDef *bgcrc)
{
    CLEAR_BIT(bgcrc->MCTRL.WORDVAL, BGCRC_MCTRL_MONEN_M);
}

/**
  * \brief  Sets the working mode of the monitor.
  * \param  bgcrc     Pointer to a BGCRC_TypeDef structure
  *                    - BGCRC1: BGCRC1 base address index
  * \param  mode      The working mode of the monitor
  *                    This parameter can be any value of @ref BGCRC_MONITORMODE
  */
static inline void BGCRC_setMonitorMode (BGCRC_TypeDef *bgcrc, BGCRC_MonitorMode mode)
{
    if (mode == BGCRC_MONITOR_MODE_READ)
    {
        CLEAR_BIT(bgcrc->MCTRL.WORDVAL, BGCRC_MCTRL_MONSRC_M);
    }
    else
    {
        SET_BIT(bgcrc->MCTRL.WORDVAL, BGCRC_MCTRL_MONSRC_M);
    }
}

/**
  * \brief  Initializes the BGCRC peripheral for CRC-16.
  * \param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  * \param  poly             16-bit polynomial
  *                           This parameter can be any value of uint16_t
  * \param  initValue        16-bit initial value
  *                           This parameter can be any value of uint16_t
  * \param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref BGCRC_OUTPUTXORENABLE
  * \param  enableReverse    Select whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
extern void BGCRC_initCrc16 (BGCRC_TypeDef *bgcrc, uint16_t poly, uint16_t initValue,
                             BGCRC_OutputXorType xorType, BGCRC_ReverseEnable enableReverse);

/**
  * \brief  Initializes the BGCRC peripheral for CRC-32.
  * \param  bgcrc            Pointer to a BGCRC_TypeDef structure
  *                           - BGCRC1: BGCRC1 base address index
  * \param  poly             32-bit polynomial
  *                           This parameter can be any value of uint32_t
  * \param  initValue        32-bit initial value
  *                           This parameter can be any value of uint32_t
  * \param  xorType          The binary sequence for XOR operation with output data
                              This parameter can be any value of @ref BGCRC_OUTPUTXORENABLE
  * \param  enableReverse    Whether to reverse the input and output data
                              This parameter can be any value of @ref BGCRC_REVERSEENABLE
  */
extern void BGCRC_initCrc32 (BGCRC_TypeDef *crc, uint32_t poly, uint32_t initValue,
                             BGCRC_OutputXorType xorType, BGCRC_ReverseEnable enableReverse);

/**
  * \brief  Writes data to data register.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  */
extern void BGCRC_writeData (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/IBM algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Ibm (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/MAXIM algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Maxim (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/USB algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Usb (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/MODBUS algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Modbus (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/CCITT algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Ccitt (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/CCITTFALSE algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16CcittFalse (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/X25 algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16X25 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC16/XMODEM algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint16_t
  */
extern uint16_t BGCRC_calcCrc16Xmodem (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC32 algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
extern uint32_t BGCRC_calcCrc32 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC32/MPEG2 algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
extern uint32_t BGCRC_calcCrc32Mpeg2 (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * /brief  Calculates CRC32/KOOPMAN algorithm.
  * /param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * /param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * /param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * /return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
uint32_t BGCRC_calcCrc32Koopman (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
  * \brief  Calculates CRC32C algorithm.
  * \param  bgcrc      Pointer to a BGCRC_TypeDef structure
  *                     - BGCRC1: BGCRC1 base address index
  * \param  pBuf       Pointer to starting data
  *                     This pointer points to an 8-bit unsigned integer
  * \param  byteCnt    The number of bytes contained in the data
  *                     This parameter can be any value of uint32_t
  * \return Returns the calculation result
  *                     The return value can be any value of uint32_t
  */
extern uint32_t BGCRC_calcCrc32C (BGCRC_TypeDef *bgcrc, uint8_t *pBuf, uint32_t byteCnt);

/**
 * \brief Configures monitor.
 * \param bgcrc            Pointer to a BGCRC_TypeDef structure
 *                          - BGCRC1: BGCRC1 base address index
 * \param enableMonitor    Whether to enable the monitor
 *                          This parameter can be any value of @ref BGCRC_MONITORENABLE
 * \param mode             The mode (reading mode/writing mode) of the monitor
 *                          This parameter can be any value of @ref BGCRC_MONITORMODE
 * \param addr             The address to be continuously monitored
 *                          This parameter can be any value of uint32_t
 * \return Returns the status of function execution
 *                          - True:  The monitor are successfully configured
 *                          - False: Monitor configuration failed
 */
extern bool BGCRC_configMonitor (BGCRC_TypeDef *bgcrc, BGCRC_MonitorEnable enableMonitor,
                                 BGCRC_MonitorMode mode, uint32_t addr);

#ifdef __cplusplus
}
#endif


#endif /* __BGCRC_H__ */
