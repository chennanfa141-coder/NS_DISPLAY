/**
  * @file       pwr.h
  * @author     Alex-J
  * @brief      Header file for NS800RT1xxx PWR module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __PWR_H__
#define __PWR_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup PWR_EXPORTED_TYPES PWR Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'PWR' module.
  */

/** @defgroup PWR_PBPECR2_REGBIT PWR PBPECR2 register bits
 * @{
 * @brief  Macro definitions about PWR_PBPECR2 register bits definition.
 */
#define PWR_PBPECR2_PE_M    (PWR_PBPECR2_PE16_M | PWR_PBPECR2_PE17_M)    /*!< Pull Enable Bitfield-Mask */

/**
 * @}
 */

/** @defgroup PWR_PBPSCR2_REGBIT PWR PBPSCR2 register bits
 * @{
 * @brief  Macro definitions about PWR_PBPSCR2 register bits definition.
 */
#define PWR_PBPSCR2_PS_M    (PWR_PBPSCR2_PS16_M | PWR_PBPSCR2_PS17_M)    /*!< Pull Selection Bitfield-Mask */

/**
 * @}
 */

/** @defgroup PWR_LOWPWRMODE PWR Module's Low Power Mode
 * @{
 * @brief  Values are used to control the low power mode of the PWR.
 */
typedef enum {
    PWR_LP_MODE_STOP = 0U,    /*!< Enter STOP mode */
    PWR_LP_MODE_STANDBY       /*!< Enter STANDBY mode  */
} PWR_LowPwrMode;

/**
 * @}
 */

/** @defgroup PWR_MRLDOVOLT PWR Module's Main regulator of LDO Voltage
 * @{
 * @brief  Values are used to control the ldo voltage of the PWR.
 */
typedef enum {
    PWR_STOP_LDO_1_1V = 0U,    /*!< LDO output 1.1v in stop mode */
    PWR_STOP_LDO_0_9V          /*!< LDO output 0.9v in stop mode */
} PWR_MrLdoVolt;

/**
 * @}
 */

/** @defgroup PWR_FLASHPWRDOWN PWR Module's Flash enters Power Down
 * @{
 * @brief  Values are used to control the ldo voltage of the PWR.
 */
typedef enum {
    PWR_STOP_FLASH_NO_PWR_DOWN = 0U,    /*!< Flash doesn't enter power down in stop mode */
    PWR_STOP_FLASH_PWR_DOWN             /*!< Flash enters power down in stop mode */
} PWR_FlashPwrDown;

/**
 * @}
 */

/** @defgroup PWR_WKUPPINPARITY PWR Module's Wakeup Pin Parity
 * @{
 * @brief  Values are used to control the wakeup pin parity 
 *         of the PWR.
 */
typedef enum {
    PWR_WKUP_DETC_HIGH = 0U,    /*!< Detect at high level (rising edge)  */
    PWR_WKUP_DETC_LOW           /*!< Detect at low level (falling edge)  */
} PWR_WkupPinParity;

/**
 * @}
 */


/** @defgroup PWR_WAITMODE PWR Module's Wait Mode
 * @{
 * @brief  Values are used to control the wait mode of the PWR.
 */
typedef enum {
    PWR_WAIT_MODE_WFI = 0U,    /*!< Wait mode using WFI */
    PWR_WAIT_MODE_WFE          /*!< Wait mode using WFE */
} PWR_WaitMode;

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
 * \brief  Sets the PWR Control Register 1 
 * \note   This function sets the control register 1 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 1 configuration.
 */
static inline void PWR_setCtrlReg1 (PWR_TypeDef *pwr, uint8_t config)
{
    SET_BIT (pwr->CR1.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the PWR Control Register 1 
 * \note   This function clears the control register 1 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 1 configuration.
 */
static inline void PWR_clearCtrlReg1 (PWR_TypeDef *pwr, uint8_t config)
{
    CLEAR_BIT (pwr->CR1.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the PWR Control Register 1 .
 * \note   This function returns the value for the PWR Control Register 1.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of Control Register 1.
 */
static inline uint8_t PWR_getCtrlReg1 (PWR_TypeDef *pwr)
{
    return (uint8_t)(pwr->CR1.WORDVAL);
}

/**
 * \brief  Sets the Low Power Mode in PWR Control Register 1 .
 * \note   This function sets the Low Power Mode in Control Register 1 
 *         of the PWR.
 *
 * \param  pwr   pwr pointer to a PWR_TypeDef structure
 *                 - PWR: PWR base address index
 * \param  mode  the value is used to select the low power mode
 */
static inline void PWR_setLowPowerMode (PWR_TypeDef *pwr, PWR_LowPwrMode mode)
{
    MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_LPMODE_M, (uint32_t)mode);
}

/**
 * \brief  Selects the Main Regulator of LDO Voltage Selection .
 * \note   This function selects the main regulator of LDO voltage
 *         in Control Register 1 of the PWR.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ldo  the value is used to select the ldo voltage
 */
static inline void PWR_selectLdoOutputVolt (PWR_TypeDef *pwr, PWR_MrLdoVolt ldo)
{
    MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_MRLVOS_M, ((uint32_t)ldo << PWR_CR1_MRLVOS_S));
}

/**
 * \brief  Selects the Flash to enter power down .
 * \note   This function selects the flash to enter power down
 *         in Control Register 1 of the PWR.
 *
 * \param  pwr       pwr pointer to a PWR_TypeDef structure
 *                     - PWR: PWR base address index
 * \param  flashPwr  the value is used to control the flash power
 */
static inline void PWR_selectFlashPwr (PWR_TypeDef *pwr, PWR_FlashPwrDown flashPwr)
{
    MODIFY_REG(pwr->CR1.WORDVAL, PWR_CR1_FDPDE_M, ((uint32_t)flashPwr << PWR_CR1_FDPDE_S));
}

/**
 * \brief  Sets the PWR Control Register 3 
 * \note   This function sets the control register 3 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 3 configuration.
 */
static inline void PWR_setCtrlReg3 (PWR_TypeDef *pwr, uint16_t config)
{
    SET_BIT(pwr->CR3.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the PWR Control Register 3 
 * \note   This function clears the control register 3 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 3 configuration.
 */
static inline void PWR_clearCtrlReg3 (PWR_TypeDef *pwr, uint16_t config)
{
    CLEAR_BIT(pwr->CR3.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the PWR Control Register 3 .
 * \note   This function returns the value for the PWR Control Register 3.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of Control Register 3.
 */
static inline uint16_t PWR_getCtrlReg3 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->CR3.WORDVAL);
}

/**
 * \brief  Enables Wakeup Pins in PWR Control Register 3.
 * \note   This function enables the wakeup pins in Control Register 3 
 *         of the PWR.
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  wkupNum  the value is used to enable the wakeup pins 
 *                  Range \e 0~3 corresponds to \e WKUPE1~4
 */
static inline void PWR_enableWakeupPin (PWR_TypeDef *pwr, uint8_t wkupNum)
{
    if (wkupNum > 3)
    {
        return;
    }

    SET_BIT(pwr->CR3.WORDVAL, (uint32_t)1 << wkupNum);
}

/**
 * \brief  Disables Wakeup Pins in PWR Control Register 3.
 * \note   This function disables the wakeup pins in Control Register 3 
 *         of the PWR.
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  wkupNum  the value is used to disable the wakeup pins 
 *                  Range \e 0~3 corresponds to \e WKUPE1~4
 */
static inline void PWR_disableWakeupPin (PWR_TypeDef *pwr, uint8_t wkupNum)
{
    if (wkupNum > 3)
    {
        return;
    }

    CLEAR_BIT(pwr->CR3.WORDVAL, (uint32_t)1 << wkupNum);
}

/**
 * \brief  Sets the PWR Control Register 4 
 * \note   This function sets the control register 4 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 4 configuration.
 */
static inline void PWR_setCtrlReg4 (PWR_TypeDef *pwr, uint16_t config)
{
    SET_BIT(pwr->CR4.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Clears the PWR Control Register 4 
 * \note   This function clears the control register 4 of the PWR
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \param  config  a value of control register 4 configuration.
 */
static inline void PWR_clearCtrlReg4 (PWR_TypeDef *pwr, uint16_t config)
{
    CLEAR_BIT(pwr->CR4.WORDVAL, (uint32_t)config);
}

/**
 * \brief  Gets the PWR Control Register 4 .
 * \note   This function returns the value for the PWR Control Register 4.
 *
 * \param  pwr     pwr pointer to a PWR_TypeDef structure
 *                   - PWR: PWR base address index
 * \return Returns the value of Control Register 4.
 */
static inline uint16_t PWR_getCtrlReg4 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->CR4.WORDVAL);
}

/**
 * \brief  Sets Wakeup Pin Parity in PWR Control Register 4.
 * \note   This function sets the wakeup pin parity in Control Register 4 
 *         of the PWR.
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  wkupNum  the value is used to set the wakeup pin parity 
 *                  Range \e 0~3 corresponds to \e WKUPE1~4
 * \param  parity   the value is used to select the parity
 */
static inline void PWR_setWakeupPinParity (PWR_TypeDef *pwr, uint8_t wkupNum, PWR_WkupPinParity parity)
{
    if (wkupNum > 3)
    {
        return;
    }

    MODIFY_REG(pwr->CR4.WORDVAL, ((uint32_t)1 << wkupNum), ((uint32_t)parity << wkupNum));
}

/**
 * \brief  Gets the PWR Status Register 1.
 * \note   This function returns the value for the PWR Status Register 1.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of Status Register 1.
 */
static inline uint16_t PWR_getStatusReg1 (PWR_TypeDef *pwr)
{
    return (uint16_t)(pwr->SR1.WORDVAL);
}

/**
 * \brief  Gets the PWR Status Register 2.
 * \note   This function returns the value for the PWR Status Register 2.
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of Status Register 2.
 */
static inline uint8_t PWR_getStatusReg2 (PWR_TypeDef *pwr)
{
    return (uint8_t)(pwr->SR2.WORDVAL);
}

/**
 * \brief  Sets the PWR Status Clear flag Register 
 * \note   This function sets the status clear flag register of the PWR
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  clrFlag  a value used to clear the status clear flag register.
 */
static inline void PWR_setStatusClr (PWR_TypeDef *pwr, uint16_t clrFlag)
{
    SET_BIT(pwr->SCR.WORDVAL, (uint32_t)clrFlag);
}

/**
 * \brief  Sets the PWR PORT A PULL Enable Control Register 1 
 * \note   This function sets the port A pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortAPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    WRITE_REG(pwr->PAPECR1.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT A PULL Enable Control Register 2 
 * \note   This function sets the port A pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortAPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    WRITE_REG(pwr->PAPECR2.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT A PULL Selection Control Register 1 
 * \note   This function sets the port A pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortAPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    WRITE_REG(pwr->PAPSCR1.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR PORT A PULL Selection Control Register 2 
 * \note   This function sets the port A pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortAPullSelCtrl2 (PWR_TypeDef *pwr, uint16_t ps)
{
    WRITE_REG(pwr->PAPSCR2.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR PORT B PULL Enable Control Register 1 
 * \note   This function sets the port B pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortBPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    WRITE_REG(pwr->PBPECR1.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT B PULL Enable Control Register 2 
 * \note   This function sets the port B pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortBPullEnCtrl2 (PWR_TypeDef *pwr, uint16_t pe)
{
    WRITE_REG(pwr->PBPECR2.WORDVAL, (uint32_t)(pe & PWR_PBPECR2_PE_M));
}

/**
 * \brief  Sets the PWR PORT B PULL Selection Control Register 1 
 * \note   This function sets the port B pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortBPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    WRITE_REG(pwr->PBPSCR1.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR PORT B PULL Selection Control Register 2 
 * \note   This function sets the port B pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortBPullSelCtrl2 (PWR_TypeDef *pwr, uint16_t ps)
{
    WRITE_REG(pwr->PBPSCR2.WORDVAL, (uint32_t)(ps & PWR_PBPSCR2_PS_M));
}

/**
 * \brief  Sets the PWR PORT C PULL Enable Control Register 1 
 * \note   This function sets the port C pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortCPullEnCtrl1 (PWR_TypeDef *pwr, uint8_t pe)
{
    WRITE_REG(pwr->PCPECR1.WORDVAL, (uint32_t)(pe & PWR_PCPECR1_PE_M));
}

/**
 * \brief  Sets the PWR PORT C PULL Selection Control Register 1 
 * \note   This function sets the port C pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortCPullSelCtrl1 (PWR_TypeDef *pwr, uint8_t ps)
{
    WRITE_REG(pwr->PCPSCR1.WORDVAL, (uint32_t)(ps & PWR_PCPSCR1_PS_M));
}

/**
 * \brief  Sets the PWR PORT H PULL Enable Control Register 1 
 * \note   This function sets the port H pull enable control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortHPullEnCtrl1 (PWR_TypeDef *pwr, uint16_t pe)
{
    WRITE_REG(pwr->PHPECR1.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT H PULL Enable Control Register 2 
 * \note   This function sets the port H pull enable control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  pe   a value used to set the pull enable.
 */
static inline void PWR_setPortHPullEnCtrl2 (PWR_TypeDef *pwr, uint8_t pe)
{
    WRITE_REG(pwr->PHPECR2.WORDVAL, (uint32_t)pe);
}

/**
 * \brief  Sets the PWR PORT H PULL Selection Control Register 1 
 * \note   This function sets the port H pull selection control register 1 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortHPullSelCtrl1 (PWR_TypeDef *pwr, uint16_t ps)
{
    WRITE_REG(pwr->PHPSCR1.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR PORT H PULL Selection Control Register 2 
 * \note   This function sets the port H pull selection control register 2 
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \param  ps   a value used to set the pull selection.
 */
static inline void PWR_setPortHPullSelCtrl2 (PWR_TypeDef *pwr, uint8_t ps)
{
    WRITE_REG(pwr->PHPSCR2.WORDVAL, (uint32_t)ps);
}

/**
 * \brief  Sets the PWR BOR Power status Register
 * \note   This function sets the bor power status register
 *         of the PWR
 *
 * \param  pwr  pwr pointer to a PWR_TypeDef structure
 *                - PWR: PWR base address index
 * \return Returns the value of BOR Status Register.
 */
static inline uint8_t PWR_getBorPwrStatus (PWR_TypeDef *pwr)
{
    return (uint8_t)(pwr->BORSR.WORDVAL >> PWR_BORSR_BOREN_S);
}

/**
 * \brief  Sets the PWR Backup Register 0 
 * \note   This function sets the value in backup register 0
 *         of the PWR
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  bpValue  a value used to set the backup register.
 */
static inline void PWR_setBackupRegister0 (PWR_TypeDef *pwr, uint16_t bpValue)
{
    WRITE_REG(pwr->BKREG0.WORDVAL, (uint32_t)bpValue);
}

/**
 * \brief  Sets the PWR Backup Register 1 
 * \note   This function sets the value in backup register 1
 *         of the PWR
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  bpValue  a value used to set the backup register.
 */
static inline void PWR_setBackupRegister1 (PWR_TypeDef *pwr, uint16_t bpValue)
{
    WRITE_REG(pwr->BKREG1.WORDVAL, (uint32_t)bpValue);
}

/**
 * \brief  Sets the PWR Backup Register 2 
 * \note   This function sets the value in backup register 2
 *         of the PWR
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  bpValue  a value used to set the backup register.
 */
static inline void PWR_setBackupRegister2 (PWR_TypeDef *pwr, uint16_t bpValue)
{
    WRITE_REG(pwr->BKREG2.WORDVAL, (uint32_t)bpValue);
}

/**
 * \brief  Sets the PWR Backup Register 3 
 * \note   This function sets the value in backup register 3
 *         of the PWR
 *
 * \param  pwr      pwr pointer to a PWR_TypeDef structure
 *                    - PWR: PWR base address index
 * \param  bpValue  a value used to set the backup register.
 */
static inline void PWR_setBackupRegister3 (PWR_TypeDef *pwr, uint16_t bpValue)
{
    WRITE_REG(pwr->BKREG3.WORDVAL, (uint32_t)bpValue);
}

/**
 * \brief  Enters the PWR module Sleep Mode
 * \note   This function operates the PWR module to enter sleep mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterSleepMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Sleep On Exit Mode
 * \note   This function operates the PWR module to enter sleep 
 *         on exit mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterSleepOnExitMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Stop Mode
 * \note   This function operates the PWR module to enter stop mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStopMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Stop On Exit Mode
 * \note   This function operates the PWR module to enter stop 
 *         on exit mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStopOnExitMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Standby Mode
 * \note   This function operates the PWR module to enter standby mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStandbyMode (PWR_WaitMode mode);

/**
 * \brief  Enters the PWR module Standby On Exit Mode
 * \note   This function operates the PWR module to enter standby 
 *         on exit mode.
 *
 * \param  mode  the value is used to select the mode of WFI or WFE
 */
extern void PWR_enterStandbyOnExitMode (PWR_WaitMode mode);


#ifdef __cplusplus
}
#endif


#endif /* __PWR_H__ */
