/**
  * @file       dcc.h
  * @author     Haven-X
  * @brief      Function file for NS800RT1xxx dcc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __DCC_H__
#define __DCC_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_dcc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup DCC_EXPORTED_TYPES DCC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'DCC' module.
  */

/** @defgroup DCC_CLKSOURCENUM DCC definition about clock sourec
  * @{
  * @brief  Macro definitions about the bit fields in the DCC CR register definition.
  */
typedef enum {
    DCC_CLK_MIRC1 = 0x0U,          /*!< DCC CLK MIRC1 */
    DCC_CLK_MIRC2,                 /*!< DCC CLK MIRC2 */
    DCC_CLK_LIRC,                  /*!< DCC CLK LIRC */
    DCC_CLK_HXT,                   /*!< DCC CLK HXT */
    DCC_CLK_PLL,                   /*!< DCC CLK PLL */
    DCC_CLK_INPUT15,               /*!< DCC CLK INPUT15 */
    DCC_CLK_INPUT16,               /*!< DCC CLK INPUT16 */
    DCC_CLK_AUXCLKIN,              /*!< DCC CLK AUXCLKIN */
    DCC_CLK_CPU_SYSCLK,            /*!< DCC CLK CPU_SYSCLK */
    DCC_CLK_DMA1_CLK = 0x0AU,      /*!< DCC CLK DMA1 Clock */
    DCC_CLK_EPWM_CLK = 0x0CU,      /*!< DCC CLK EPWMCLK */
    DCC_CLK_SPI_UART_CLK,          /*!< DCC CLK SPI and UART Clock */
    DCC_CLK_ADC_CLK,               /*!< DCC CLK ADC Clock */
    DCC_CLK_IWDG1_CLK,             /*!< DCC CLK IWDG1 Clock */
    DCC_CLK_IWDG2_CLK = 0x11U,     /*!< DCC CLK IWDG2 Clock */
    DCC_CLK_WWDG_CLK,              /*!< DCC CLK WWDG Clock */
    DCC_CLK_CAN1_CLK = 0x14U,      /*!< DCC CLK CAN1 Clock */
    DCC_CLK_FLASH_CLK = 0x17U,     /*!< DCC CLK FLASH Clock */
    DCC_CLK_INPUT11,               /*!< DCC CLK INPUT11 */
    DCC_CLK_INPUT12,               /*!< DCC CLK INPUT12 */
} DCC_ClkSourceNum;

/**
  * @}
  */

/** @defgroup DCC_STATEFLAG DCC definition about DCC fualt flag
  * @{
  * @brief  Macro definitions about the bit fields in the DCC IFR register definition.
  */
typedef enum {
    DCC_STATE_STOP          = 0x1U,           /*!< DCC STOP STATE */ 
    DCC_STATE_CALCNT_OVF    = 0x2U,           /*!< DCC CALCNT OVF STATE */
    DCC_STATE_CLK_FAULT     = 0x4U,           /*!< CLOCK FAULT STATE */
    DCC_STATE_ALL_FAULT     = 0x7U
} DCC_StateFlag;

/**
  * @}
  */

/** @defgroup DCC_MODE DCC interrupt or reset mode definition
  * @{
  * @brief  Macro definitions about the bit fields in the DCC CR register definition.
  * @note   Values that can be passed to as the \e DCC_setClockMonitor().
  */
typedef enum {
    DCC_INTERRTUP_MODE = 0U,    /*!< DCC INTERRTUP MODE */
    DCC_RESET_MODE              /*!< DCC RESET MODE */
} DCC_Mode;

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
 * \brief  Get the CALCNT register bits value
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 * \return Returns the REFCNT register uint32_t data
 */
static inline uint32_t DCC_getCalCntValue (DCC_TypeDef *dcc)
{
    return READ_REG(dcc->CALCNT.WORDVAL);
}

/**
 * \brief  Get the REFCNT register bits value
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 * \return Returns the REFCNT register uint32_t data
 */
static inline uint32_t DCC_getRefCntValue (DCC_TypeDef *dcc)
{
    return READ_REG(dcc->REFCNT.WORDVAL);
}

/**
 * \brief  DCC start counting with CR register start bit
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_startCounting (DCC_TypeDef *dcc)
{
    SET_BIT(dcc->CR.WORDVAL, DCC_CR_TRIMSTART_M);
}

/**
 * \brief  DCC stop counting with CR register start bit
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_stopCounting (DCC_TypeDef *dcc)
{
    CLEAR_BIT(dcc->CR.WORDVAL, DCC_CR_TRIMSTART_M);
}

/**
 * \brief  Get the IFR register state value
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  flag    Monitor parameter about DCC state flag
 *                  - This parameter can be any value of @ref DCC_STATEFLAG
 * \return Returns the status of DCC IFR states flag.
 */
static inline uint32_t DCC_getStatusFlags (DCC_TypeDef *dcc, DCC_StateFlag flag)
{
    return READ_BIT(dcc->ISR.WORDVAL, (uint32_t)flag);
}

/**
 * \brief  Clear the clk fault Status Flag
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 */
static inline void DCC_clearClkFaultStatusFlag (DCC_TypeDef *dcc)
{
    WRITE_REG(dcc->ICR.WORDVAL, DCC_STATE_CLK_FAULT);
}

/**
 * \brief  Set the REFCON register value
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  data    Counting initial value
 *                  - This parameter can be any value from 1~0xFFFFFFFF
 */
static inline void DCC_setREFCON (DCC_TypeDef *dcc, uint32_t data)
{
    /* Set value to REFCON register */
    WRITE_REG(dcc->REFCON.WORDVAL, data);
}

/**
 * \brief  Set the HTCR register bits
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  data    Higher limit range data
 *                  - This parameter can be any value from 0~0xFFFFFFFF
 */
static inline void DCC_setHTCR (DCC_TypeDef *dcc, uint32_t data)
{
    /* Set value to REFCON register */
    WRITE_REG(dcc->HTCR.WORDVAL, data);
}

/**
 * \brief  Set the LTCR register bits
 * \param  dcc     DCC pointer to DCC_TypeDef structure
 *                  - DCC: DCC base address index
 * \param  data    Lower limit range data
 *                  - This parameter can be any value from 0~0xFFFFFFFF
 */
static inline void DCC_setLTCR (DCC_TypeDef *dcc, uint32_t data)
{
    /* Set value to REFCON register */
    WRITE_REG(dcc->LTCR.WORDVAL, data);
}

/**
 * \brief  Set the DCC to monitor mode register bits
 * \param  base      DCC pointer to DCC_TypeDef structure
 *                    - DCC: DCC base address index
 * \param  refclk    Monitor parameter about reference clock
 *                    - This parameter can be any value of @ref DCC_CLKSOURCEENUM
 * \param  calclk    Monitor parameter about calibration clock 
 *                    - This parameter can be any value of @ref DCC_CLKSOURCEENUM
 */
static inline void DCC_setMonitorMode (DCC_TypeDef *dcc, DCC_ClkSourceNum refClk, DCC_ClkSourceNum calClk)
{
    /* Set Reference & Calibration clock */ 
    if (refClk != calClk)
    {
        MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_CALCLKSEL_M | DCC_CR_REFCLKSEL_M,
                   ((uint32_t)refClk << DCC_CR_REFCLKSEL_S) | ((uint32_t)calClk << DCC_CR_CALCLKSEL_S) | \
                   DCC_CR_MONEN_M | DCC_CR_CLKEN_M);
    }
}

/**
 * \brief  Set the DCC to trim mode register bits
 * \param  base      DCC pointer to DCC_TypeDef structure
 *                    - DCC: DCC base address index
 * \param  refclk    Trim parameter about reference clock
 *                    - This parameter can be any value of @ref DCC_CLKSOURCEENUM
 * \param  calclk    Trim parameter about calibration clock
 *                    - This parameter can be any value of @ref DCC_CLKSOURCEENUM
 */
static inline void DCC_setTrimMode (DCC_TypeDef *dcc, DCC_ClkSourceNum refclk, DCC_ClkSourceNum calclk)
{
    /* Set Reference & Calibration clock */ 
    if (refclk != calclk)
    {
        MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_CALCLKSEL_M | DCC_CR_REFCLKSEL_M | DCC_CR_MONEN_M,
                   ((uint32_t)refclk << DCC_CR_REFCLKSEL_S) | ((uint32_t)calclk << DCC_CR_CALCLKSEL_S) | DCC_CR_CLKEN_M);
    }
}

/**
 * \brief  DCC enable interrupt register in DCC module 
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_enableInterrupt (DCC_TypeDef *dcc)
{
    MODIFY_REG(dcc->CR.WORDVAL, DCC_CR_RSTIE_M, DCC_CR_IRQEN_M);
}

/**
 * \brief  DCC disable interrupt register in DCC module 
 * \param  dcc    DCC pointer to DCC_TypeDef structure
 *                 - DCC: DCC base address index
 */
static inline void DCC_disableInterrupt (DCC_TypeDef *dcc)
{
    CLEAR_BIT(dcc->CR.WORDVAL, (DCC_CR_RSTIE_M | DCC_CR_IRQEN_M));
}

/**
  * \brief  Set the Clock DCC monitor function
  * \param  dcc       DCC pointer to DCC_TypeDef structure
  *                    - DCC: DCC base address index
  * \param  refclk    DCC CR register REFCLK_SEL value
  *                    - This parameter can be any value of @ref DCC_CLKSOURCENUM
  * \param  calClk    DCC CR register CALCLK_SEL value
  *                    - This parameter can be any value of @ref DCC_CLKSOURCENUM
  * \param  rstEn     DCC CR register RST_IE value
  *                    - This parameter can be any value of @ref DCC_MODE
  * \param  refCon    DCC DCC_REFCON register value
  *                    - This parameter can be any value from 1~0xFFFFFFFF
  * \param  htCr      DCC DCC_HTCR register value
  *                    - This parameter can be any value from 0~0xFFFFFFFF
  * \param  ltCr      DCC DCC_ register value
  *                    - This parameter can be any value from 0~0xFFFFFFFF
  * \return Returns the DCC monitor mode status set whether success
  *                    - true : set success
  *                    - false: set false
  */
extern bool DCC_setClockMonitor (DCC_TypeDef *dcc, DCC_ClkSourceNum refClk, DCC_ClkSourceNum calClk, \
                                    DCC_Mode rstEn, uint32_t refCon, uint32_t htCr, uint32_t ltCr);

/**
  * \brief  Set the Clock DCC trim function
  * \param  dcc          DCC pointer to DCC_TypeDef structure
  *                       - DCC: DCC base address index
  * \param  refclk       DCC CR register REFCLK_SEL value
  *                       - This parameter can be any value of @ref DCC_CLKSOURCENUM
  * \param  calClk       DCC CR register CALCLK_SEL value
  *                       - This parameter can be any value of @ref DCC_CLKSOURCENUM
  * \param  refCon       DCC DCC_REFCOn register value
  *                       - This parameter can be any value from 1~0xFFFFFFFF
  * \param  irqEnable    DCC CR register IRQ_EN value
  *                       - true : ENABLE IRQ
  *                       - false: DISABLE IRQ
  * \return Returns the DCC trim mode status set whether success
  *                       - true : set success
  *                       - false: set false
  */
extern bool DCC_setClockTrim (DCC_TypeDef *dcc, DCC_ClkSourceNum refClk, DCC_ClkSourceNum calClk, \
                              uint32_t refCon, bool irqEnable);


#ifdef __cplusplus
}
#endif


#endif /* __DCC_H__ */
