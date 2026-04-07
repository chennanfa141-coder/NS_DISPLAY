/**
  * @file       adc.c
  * @author     wangxin
  * @brief      Function file for NS800RT1xxx adc module.
  *
  * <h2><center>&copy; Copyright (c) 2024 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "adc.h"


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
  * @brief  Configures the ADC module's reference mode and offset trim
  * @note   In this device, the bandgaps are common for all the ADC instances,
  *         hence common Vref configuration needs to be done for all the ADCs. This
  *         API configures same Vref configuration for all the supported ADCs in the device.
  * @param  base          ADC base address
  *                        - ADCA: ADCA_BASE
  *                        - ADCB: ADCB_BASE
  *                        - ADCC: ADCC_BASE
  * @param  refMode       ADC reference Mode
  *                        This parameter can be one of the following @ref ADC_ReferenceMode:
  * @param  refVoltage    ADC reference Voltage
  *                        This parameter can be one of the following @ref ADC_ReferenceVoltage:
  */
void ADC_setVREF (ADC_TypeDef *base, ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage)
{
    __IO ANASS_TypeDef* mPtr = (ANASS_TypeDef*)ANASS_BASE;

    /* Analog reference mode selection */
    if (refMode == ADC_REFERENCE_INTERNAL)
    {
        CLEAR_BIT(mPtr->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREFSEL_M);
        /* Analog reference voltage level selection */
        if (refVoltage == ADC_REFERENCE_1_65V)
        {
            CLEAR_BIT(mPtr->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
            MODIFY_REG(base->ADCANACTL.WORDVAL, ADC_ADCANACTL_SGAIN_M, ((0x2UL << ADC_ADCANACTL_SGAIN_S)));
        }
        else if ((refVoltage == ADC_REFERENCE_2_5V))
        {
            SET_BIT(mPtr->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
            MODIFY_REG(base->ADCANACTL.WORDVAL, ADC_ADCANACTL_SGAIN_M, ((0x2UL << ADC_ADCANACTL_SGAIN_S)));
        }
        else if((refVoltage == ADC_REFERENCE_3_3V))
        {
            CLEAR_BIT(mPtr->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
            MODIFY_REG(base->ADCANACTL.WORDVAL, ADC_ADCANACTL_SGAIN_M, ((0x1UL << ADC_ADCANACTL_SGAIN_S)));
        } 
        else 
        {
            CLEAR_BIT(mPtr->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREF2P5SEL_M);
            MODIFY_REG(base->ADCANACTL.WORDVAL, ADC_ADCANACTL_SGAIN_M, ((0x2UL << ADC_ADCANACTL_SGAIN_S)));
        }
    }
    else if ((refMode == ADC_REFERENCE_EXTERNAL))
    {
        SET_BIT(mPtr->ANAREFCTL.WORDVAL, ANASS_ANAREFCTL_ANAREFSEL_M);
        MODIFY_REG(base->ADCANACTL.WORDVAL, ADC_ADCANACTL_SGAIN_M, ((0x2UL << ADC_ADCANACTL_SGAIN_S)));
    }

    /* Only single-ended input mode is supported */
    CLEAR_BIT(base->ADCANACTL.WORDVAL, ADC_ADCANACTL_SDIF_M);

    /* normal mode*/
    CLEAR_BIT(base->ADCANATRIM.WORDVAL, ADC_ADCANATRIM_DISH_M);

    /* Set ADC offset trim for the all the ADC instances*/
    ADC_setOffsetTrimAll(refMode, refVoltage);
}

/**
  * @brief  Configures the offset trim for the desired ADC instance
  * @note   This function loads the offset trims for the desired ADC instance.
  * @param  base       ADC base address
  *                     - ADCA: ADCA_BASE
  *                     - ADCB: ADCB_BASE
  *                     - ADCC: ADCC_BASE
  * @param  refMode    ADC reference Mode
  *                     This parameter can be one of the following @ref ADC_ReferenceMode:
  */
void ADC_setOffsetTrim (ADC_TypeDef *base, ADC_ReferenceMode refMode)
{
    /* Configures the offset trim for the desired ADC instance */
    if (refMode == ADC_REFERENCE_INTERNAL)
    {
        MODIFY_REG(base->ADCTRIMPN.WORDVAL, ADC_ADCTRIM_TRIMOFFSET_MASK, \
                   (((8UL | (1UL << 5UL)) << 8UL) & ADC_ADCTRIM_TRIMOFFSET_MASK));
    }
}

/**
  * @brief  Configures All the offset trim for all the ADC instances
  * @note   This function loads the offset trims for all the ADC instances.
  * @param  refMode       ADC reference Mode
  *                        This parameter can be one of the following @ref ADC_ReferenceMode:
  * @param  refVoltage    ADC reference Voltage
  *                        This parameter can be one of the following @ref ADC_ReferenceVoltage:
  */
void ADC_setOffsetTrimAll (ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage)
{
    uint32_t offsetShiftVal;

    /* Offset trim for internal VREF 3.3V is unique and stored in upper byte. */
    if ((refMode == ADC_REFERENCE_INTERNAL) && (refVoltage == ADC_REFERENCE_3_3V))
    {
        offsetShiftVal = 8U;
    }
    else
    {
        offsetShiftVal = 0U;
    }
    MODIFY_REG(ADCA->ADCTRIMPN.WORDVAL, ADC_ADCTRIMPN_OFFSET_M, offsetShiftVal << ADC_ADCTRIMPN_OFFSET_S);
    MODIFY_REG(ADCC->ADCTRIMPN.WORDVAL, ADC_ADCTRIMPN_OFFSET_M, offsetShiftVal << ADC_ADCTRIMPN_OFFSET_S);
}

/**
  * @brief  Sets the windowed trip limits for a PPB.
  * @note   This function sets the windowed trip limits for a PPB. These values set
  *         the digital comparator trip high and low limits.
  *         The trip limits are used to determine when the PPB is tripped.
  * @param  base           ADC base address
  *                         - ADCA: ADCA_BASE
  *                         - ADCB: ADCB_BASE
  *                         - ADCC: ADCC_BASE
  * @param  ppbNumber      ADC PPB Number
  *                         This parameter can be one of the following @ref ADC_PPBNumbe:
  * @param  sybol          ADC PPB Symbol
  *                         This parameter can be one of the following @ref ADC_PPBSymbol:
  * @param  tripHiLimit    ADC PPB Trip Hi Limit,tripHiLimit is the value is the digital comparator trip high limit.
  * @param  tripLoLimit    ADC PPB Trip Lo Limit,tripLoLimit is the value is the digital comparator trip low limit.
  */
void ADC_setPPBTripLimits (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, ADC_PPBSymbol sybol, uint32_t tripHiLimit, uint32_t tripLoLimit)
{
    MODIFY_REG(TYPE32(&(base->ADCPPB1TRIPHI.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1TRIPHI_HSIGN_M, sybol);
    MODIFY_REG(TYPE32(&(base->ADCPPB1TRIPHI.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1TRIPHI_LIMITHI_M, tripHiLimit);

    MODIFY_REG(TYPE32(&(base->ADCPPB1TRIPLO.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1TRIPLO_LSIGN_M, sybol);
    MODIFY_REG(TYPE32(&(base->ADCPPB1TRIPLO.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1TRIPLO_LIMITLO_M, tripLoLimit);
}
