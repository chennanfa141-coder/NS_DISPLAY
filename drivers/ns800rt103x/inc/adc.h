/**
  * @file       adc.h
  * @author     wangxin
  * @brief      Function file for NS800RT1xxx adc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __ADC_H__
#define __ADC_H__


#ifdef __cplusplus
extern "C" {
#endif

#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_adc.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup ADC_EXPORTED_TYPES ADC Exported Types.
  * @{
  * @brief  Macro definitions are used with all files publicly about 'ADC' module.
  */

/** @defgroup ADC_CLKPRESCALE is ADC Clock Prescaler with one group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC Clock Prescaler.
  */
typedef enum {
    ADC_CLK_DIV_1 = 0U,    /*!< ADCCLK = (input clock) / 1 */
    ADC_CLK_DIV_2,         /*!< ADCCLK = (input clock) / 2 */
    ADC_CLK_DIV_3,         /*!< ADCCLK = (input clock) / 3 */
    ADC_CLK_DIV_4,         /*!< ADCCLK = (input clock) / 4 */
    ADC_CLK_DIV_5,         /*!< ADCCLK = (input clock) / 5 */
    ADC_CLK_DIV_6,         /*!< ADCCLK = (input clock) / 6 */
    ADC_CLK_DIV_7,         /*!< ADCCLK = (input clock) / 7 */
    ADC_CLK_DIV_8,         /*!< ADCCLK = (input clock) / 8 */
    ADC_CLK_DIV_9,         /*!< ADCCLK = (input clock) / 9 */
    ADC_CLK_DIV_10,        /*!< ADCCLK = (input clock) / 10 */
    ADC_CLK_DIV_11,        /*!< ADCCLK = (input clock) / 11 */
    ADC_CLK_DIV_12,        /*!< ADCCLK = (input clock) / 12 */
    ADC_CLK_DIV_13,        /*!< ADCCLK = (input clock) / 13 */
    ADC_CLK_DIV_14,        /*!< ADCCLK = (input clock) / 14 */
    ADC_CLK_DIV_15,        /*!< ADCCLK = (input clock) / 15 */
    ADC_CLK_DIV_16,        /*!< ADCCLK = (input clock) / 16 */
    ADC_CLK_DIV_17,        /*!< ADCCLK = (input clock) / 17 */
    ADC_CLK_DIV_18,        /*!< ADCCLK = (input clock) / 18 */
    ADC_CLK_DIV_19,        /*!< ADCCLK = (input clock) / 19 */
    ADC_CLK_DIV_20,        /*!< ADCCLK = (input clock) / 20 */
    ADC_CLK_DIV_21,        /*!< ADCCLK = (input clock) / 21 */
    ADC_CLK_DIV_22,        /*!< ADCCLK = (input clock) / 22 */
    ADC_CLK_DIV_23,        /*!< ADCCLK = (input clock) / 23 */
    ADC_CLK_DIV_24,        /*!< ADCCLK = (input clock) / 24 */
    ADC_CLK_DIV_25,        /*!< ADCCLK = (input clock) / 25 */
    ADC_CLK_DIV_26,        /*!< ADCCLK = (input clock) / 26 */
    ADC_CLK_DIV_27,        /*!< ADCCLK = (input clock) / 27 */
    ADC_CLK_DIV_28,        /*!< ADCCLK = (input clock) / 28 */
    ADC_CLK_DIV_29,        /*!< ADCCLK = (input clock) / 29 */
    ADC_CLK_DIV_30,        /*!< ADCCLK = (input clock) / 30 */
    ADC_CLK_DIV_31,        /*!< ADCCLK = (input clock) / 31 */
    ADC_CLK_DIV_32,        /*!< ADCCLK = (input clock) / 32 */
    ADC_CLK_DIV_33,        /*!< ADCCLK = (input clock) / 33 */
    ADC_CLK_DIV_34,        /*!< ADCCLK = (input clock) / 34 */
    ADC_CLK_DIV_35,        /*!< ADCCLK = (input clock) / 35 */
    ADC_CLK_DIV_36,        /*!< ADCCLK = (input clock) / 36 */
    ADC_CLK_DIV_37,        /*!< ADCCLK = (input clock) / 37 */
    ADC_CLK_DIV_38,        /*!< ADCCLK = (input clock) / 38 */
    ADC_CLK_DIV_39,        /*!< ADCCLK = (input clock) / 39 */
    ADC_CLK_DIV_40,        /*!< ADCCLK = (input clock) / 40 */
    ADC_CLK_DIV_41,        /*!< ADCCLK = (input clock) / 41 */
    ADC_CLK_DIV_42,        /*!< ADCCLK = (input clock) / 42 */
    ADC_CLK_DIV_43,        /*!< ADCCLK = (input clock) / 43 */
    ADC_CLK_DIV_44,        /*!< ADCCLK = (input clock) / 44 */
    ADC_CLK_DIV_45,        /*!< ADCCLK = (input clock) / 45 */
    ADC_CLK_DIV_46,        /*!< ADCCLK = (input clock) / 46 */
    ADC_CLK_DIV_47,        /*!< ADCCLK = (input clock) / 47 */
    ADC_CLK_DIV_48,        /*!< ADCCLK = (input clock) / 48 */
    ADC_CLK_DIV_49,        /*!< ADCCLK = (input clock) / 49 */
    ADC_CLK_DIV_50,        /*!< ADCCLK = (input clock) / 50 */
    ADC_CLK_DIV_51,        /*!< ADCCLK = (input clock) / 51 */
    ADC_CLK_DIV_52,        /*!< ADCCLK = (input clock) / 52 */
    ADC_CLK_DIV_53,        /*!< ADCCLK = (input clock) / 53 */
    ADC_CLK_DIV_54,        /*!< ADCCLK = (input clock) / 54 */
    ADC_CLK_DIV_55,        /*!< ADCCLK = (input clock) / 55 */
    ADC_CLK_DIV_56,        /*!< ADCCLK = (input clock) / 56 */
    ADC_CLK_DIV_57,        /*!< ADCCLK = (input clock) / 57 */
    ADC_CLK_DIV_58,        /*!< ADCCLK = (input clock) / 58 */
    ADC_CLK_DIV_59,        /*!< ADCCLK = (input clock) / 59 */
    ADC_CLK_DIV_60,        /*!< ADCCLK = (input clock) / 60 */
    ADC_CLK_DIV_61,        /*!< ADCCLK = (input clock) / 61 */
    ADC_CLK_DIV_62,        /*!< ADCCLK = (input clock) / 62 */
    ADC_CLK_DIV_63,        /*!< ADCCLK = (input clock) / 63 */
    ADC_CLK_DIV_64         /*!< ADCCLK = (input clock) / 64 */
} ADC_ClkPrescale;

/**
  * @}
  */

/** @defgroup ADC_TRIGGER ADC Interrupt Trigger Source with one group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC interrupt trigger source.
  */
typedef enum {
    ADC_TRIGGER_SW_ONLY = 0U,    /*!< Software only */
    ADC_TRIGGER_CPU1_TINT0,      /*!< CPU1 Timer 0, TINT0 */
    ADC_TRIGGER_CPU1_TINT1,      /*!< CPU1 Timer 1, TINT1 */
    ADC_TRIGGER_CPU1_TINT2,      /*!< CPU1 Timer 2, TINT2 */
    ADC_TRIGGER_INPUT_XBAR5,     /*!< INPUT_XBAR5 */
    ADC_TRIGGER_EPWM1_SOCA,      /*!< ePWM1, ADCSOCA */
    ADC_TRIGGER_EPWM1_SOCB,      /*!< ePWM1, ADCSOCB */
    ADC_TRIGGER_EPWM2_SOCA,      /*!< ePWM2, ADCSOCA */
    ADC_TRIGGER_EPWM2_SOCB,      /*!< ePWM2, ADCSOCB */
    ADC_TRIGGER_EPWM3_SOCA,      /*!< ePWM3, ADCSOCA */
    ADC_TRIGGER_EPWM3_SOCB,      /*!< ePWM3, ADCSOCB */
    ADC_TRIGGER_EPWM4_SOCA,      /*!< ePWM4, ADCSOCA */
    ADC_TRIGGER_EPWM4_SOCB,      /*!< ePWM4, ADCSOCB */
    ADC_TRIGGER_EPWM5_SOCA,      /*!< ePWM5, ADCSOCA */
    ADC_TRIGGER_EPWM5_SOCB,      /*!< ePWM5, ADCSOCB */
    ADC_TRIGGER_EPWM6_SOCA,      /*!< ePWM6, ADCSOCA */
    ADC_TRIGGER_EPWM6_SOCB,      /*!< ePWM6, ADCSOCB */
    ADC_TRIGGER_EPWM7_SOCA,      /*!< ePWM7, ADCSOCA */
    ADC_TRIGGER_EPWM7_SOCB,      /*!< ePWM7, ADCSOCB */
    ADC_TRIGGER_ECAP1,           /*!< ECAP1 */
    ADC_TRIGGER_ECAP2,           /*!< ECAP2 */
    ADC_TRIGGER_ECAP3            /*!< ECAP3 */
} ADC_Trigger;

/**
  * @}
  */

/** @defgroup ADC_BURSTTRIGGER ADC Interrupt Burst Trigger Source with one group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC interrupt Burst trigger source.
  */
typedef enum {
    ADC_BURSTTRIG0_SW_ONLY = 0U,    /*!< Software only */
    ADC_BURSTTRIG1_CPU1_TINT0,      /*!< CPU1 Timer 0, TINT0 */
    ADC_BURSTTRIG2_CPU1_TINT1,      /*!< CPU1 Timer 1, TINT1 */
    ADC_BURSTTRIG3_CPU1_TINT2,      /*!< CPU1 Timer 2, TINT2 */
    ADC_BURSTTRIG4_GPIO_INPUT5,     /*!< GPIO, Input X-Bar INPUT5 */
    ADC_BURSTTRIG5_EPWM1_SOCA,      /*!< ePWM1, ADCSOCA */
    ADC_BURSTTRIG6_EPWM1_SOCB,      /*!< ePWM1, ADCSOCB */
    ADC_BURSTTRIG7_EPWM2_SOCA,      /*!< ePWM2, ADCSOCA */
    ADC_BURSTTRIG8_EPWM2_SOCB,      /*!< ePWM2, ADCSOCB */
    ADC_BURSTTRIG9_EPWM3_SOCA,      /*!< ePWM3, ADCSOCA */
    ADC_BURSTTRIG10_EPWM3_SOCB,     /*!< ePWM3, ADCSOCB */
    ADC_BURSTTRIG11_EPWM4_SOCA,     /*!< ePWM4, ADCSOCA */
    ADC_BURSTTRIG12_EPWM4_SOCB,     /*!< ePWM4, ADCSOCB */
    ADC_BURSTTRIG13_EPWM5_SOCA,     /*!< ePWM5, ADCSOCA */
    ADC_BURSTTRIG14_EPWM5_SOCB,     /*!< ePWM5, ADCSOCB */
    ADC_BURSTTRIG15_EPWM6_SOCA,     /*!< ePWM6, ADCSOCA */
    ADC_BURSTTRIG16_EPWM6_SOCB,     /*!< ePWM6, ADCSOCB */
    ADC_BURSTTRIG17_EPWM7_SOCA,     /*!< ePWM7, ADCSOCA */
    ADC_BURSTTRIG18_EPWM7_SOCB,     /*!< ePWM7, ADCSOCB */
    ADC_BURSTTRIG19_ECAP1,          /*!< eCAP1 */
    ADC_BURSTTRIG20_ECAP2,          /*!< eCAP2 */
    ADC_BURSTTRIG21_ECAP3           /*!< eCAP3 */
} ADC_BurstTrigger;

/**
  * @}
  */

/** @defgroup ADC_CHANNEL ADC Channel Number Selection in group(ADCA/B/C)
  * @{
  * @brief  Macro definitions about ADC channel.
  */
typedef enum {
    ADC_CH_ADCIN0 = 0U,    /*!< ADCIN0 is converted */
    ADC_CH_ADCIN1,         /*!< ADCIN1 is converted */
    ADC_CH_ADCIN2,         /*!< ADCIN2 is converted */
    ADC_CH_ADCIN3,         /*!< ADCIN3 is converted */
    ADC_CH_ADCIN4,         /*!< ADCIN4 is converted */
    ADC_CH_ADCIN5,         /*!< ADCIN5 is converted */
    ADC_CH_ADCIN6,         /*!< ADCIN6 is converted */
    ADC_CH_ADCIN7,         /*!< ADCIN7 is converted */
    ADC_CH_ADCIN8,         /*!< ADCIN8 is converted */
    ADC_CH_ADCIN9,         /*!< ADCIN9 is converted */
    ADC_CH_ADCIN10,        /*!< ADCIN10 is converted */
    ADC_CH_ADCIN11,        /*!< ADCIN11 is converted */
    ADC_CH_ADCIN12,        /*!< ADCIN12 is converted */
    ADC_CH_ADCIN13,        /*!< ADCIN13 is converted */
    ADC_CH_ADCIN14,        /*!< ADCIN14 is converted */
    ADC_CH_ADCIN15,        /*!< ADCIN15 is converted */
    ADC_CH_ADCIN17 = 17U,  /*!< ADCIN17 is converted */
    ADC_CH_ADCIN18         /*!< ADCIN18 is converted */
} ADC_Channel;

/**
  * @}
  */

/** @defgroup ADC_INTNUMBER ADC Interrupt Number Selection
  * @{
  * @brief  Macro definitions about ADC Interrupt Number
  */
typedef enum {
    ADC_INT_NUMBER1 = 0U,    /*!< ADCINT1 Interrupt */
    ADC_INT_NUMBER2,         /*!< ADCINT2 Interrupt */
    ADC_INT_NUMBER3,         /*!< ADCINT3 Interrupt */
    ADC_INT_NUMBER4          /*!< ADCINT4 Interrupt */
} ADC_IntNumber;

/**
  * @}
  */

/** @defgroup ADC_PPBNUMBER ADC Post-processing Block
  * @{
  * @brief  Macro definitions about ADC Post-processing Block Number
  */
typedef enum {
    ADC_PPB_NUMBER1 = 0U,    /*!< Post-processing block 1 */
    ADC_PPB_NUMBER2,         /*!< Post-processing block 2 */
    ADC_PPB_NUMBER3,         /*!< Post-processing block 3 */
    ADC_PPB_NUMBER4          /*!< Post-processing block 4 */
} ADC_PPBNumber;

/**
  * @}
  */

/** @defgroup ADC_SOCNUMBER ADC SOC Number Selection
  * @{
  * @brief  Macro definitions about ADC SOC Number
  */
typedef enum {
    ADC_SOC_NUMBER0 = 0U,    /*!< SOC number 0 */
    ADC_SOC_NUMBER1,         /*!< SOC number 1 */
    ADC_SOC_NUMBER2,         /*!< SOC number 2 */
    ADC_SOC_NUMBER3,         /*!< SOC number 3 */
    ADC_SOC_NUMBER4,         /*!< SOC number 4 */
    ADC_SOC_NUMBER5,         /*!< SOC number 5 */
    ADC_SOC_NUMBER6,         /*!< SOC number 6 */
    ADC_SOC_NUMBER7,         /*!< SOC number 7 */
    ADC_SOC_NUMBER8,         /*!< SOC number 8 */
    ADC_SOC_NUMBER9,         /*!< SOC number 9 */
    ADC_SOC_NUMBER10,        /*!< SOC number 10 */
    ADC_SOC_NUMBER11,        /*!< SOC number 11 */
    ADC_SOC_NUMBER12,        /*!< SOC number 12 */
    ADC_SOC_NUMBER13,        /*!< SOC number 13 */
    ADC_SOC_NUMBER14,        /*!< SOC number 14 */
    ADC_SOC_NUMBER15         /*!< SOC number 15 */
} ADC_SOCNumber;

/**
  * @}
  */

/** @defgroup ADC_INTSOCTRIGGER ADC Interupt Source Selection
  * @{
  * @brief  Macro definitions about ADC Interupt source.
  */
typedef enum {
    ADC_INT_SOC_TRIGGER_NONE = 0U,    /*!< No ADCINT will trigger the SOC */
    ADC_INT_SOC_TRIGGER_ADCINT1,      /*!< ADCINT1 will trigger the SOC */
    ADC_INT_SOC_TRIGGER_ADCINT2       /*!< ADCINT2 will trigger the SOC */
} ADC_IntSOCTrigger;

/**
  * @}
  */

/** @defgroup ADC_PRIORITYMODE ADC Priority Selection
  * @{
  * @brief  Macro definitions about ADC Priority.
  */
typedef enum {
    ADC_PRI_ALL_ROUND_ROBIN = 0U,    /*!< Round robin mode is used for all */
    ADC_PRI_SOC0_HIPRI,              /*!< SOC 0 hi pri, others in round robin */
    ADC_PRI_THRU_SOC1_HIPRI,         /*!< SOC 0-1 hi pri, others in round robin */
    ADC_PRI_THRU_SOC2_HIPRI,         /*!< SOC 0-2 hi pri, others in round robin */
    ADC_PRI_THRU_SOC3_HIPRI,         /*!< SOC 0-3 hi pri, others in round robin */
    ADC_PRI_THRU_SOC4_HIPRI,         /*!< SOC 0-4 hi pri, others in round robin */
    ADC_PRI_THRU_SOC5_HIPRI,         /*!< SOC 0-5 hi pri, others in round robin */
    ADC_PRI_THRU_SOC6_HIPRI,         /*!< SOC 0-6 hi pri, others in round robin */
    ADC_PRI_THRU_SOC7_HIPRI,         /*!< SOC 0-7 hi pri, others in round robin */
    ADC_PRI_THRU_SOC8_HIPRI,         /*!< SOC 0-8 hi pri, others in round robin */
    ADC_PRI_THRU_SOC9_HIPRI,         /*!< SOC 0-9 hi pri, others in round robin */
    ADC_PRI_THRU_SOC10_HIPRI,        /*!< SOC 0-10 hi pri, others in round robin */
    ADC_PRI_THRU_SOC11_HIPRI,        /*!< SOC 0-11 hi pri, others in round robin */
    ADC_PRI_THRU_SOC12_HIPRI,        /*!< SOC 0-12 hi pri, others in round robin */
    ADC_PRI_THRU_SOC13_HIPRI,        /*!< SOC 0-13 hi pri, others in round robin */
    ADC_PRI_THRU_SOC14_HIPRI,        /*!< SOC 0-14 hi pri, SOC15 in round robin */
    ADC_PRI_ALL_HIPRI                /*!< All priorities based on SOC number */
} ADC_PriorityMode;

/**
  * @}
  */

/** @defgroup ADC_REFERENCEMODE ADC Reference Voltage Source Selection
  * @{
  * @brief  Macro definitions about ADC reference voltage source.
  */
typedef enum {
    ADC_REFERENCE_INTERNAL = 0U,    /*!< Internal reference voltage is used */
    ADC_REFERENCE_EXTERNAL          /*!< External reference voltage is used */
} ADC_ReferenceMode;

/**
  * @}
  */

/** @defgroup ADC_REFERENCEVOLTAGE ADC Reference Voltage Value Selection
  * @{
  * @brief  Macro definitions about ADC reference voltage value.
  */
typedef enum {
    ADC_REFERENCE_3_3V = 0U,    /*!< 3.3V is valid when ADC reference */
    ADC_REFERENCE_2_5V,         /*!< 2.5V is valid when ADC reference */
    ADC_REFERENCE_1_65V,        /*!< 1.65V is valid when ADC reference */
    ADC_REFERENCE_VREFHI        /*!< VREFHI is valid when ADC reference */
} ADC_ReferenceVoltage;

/**
  * @}
  */

/** @defgroup ADC_PPBSYMBOL ADC Post-processing Block Symbol Selection
  * @{
  * @brief  Macro definitions about ADC Post-processing Block Symbol
  */
typedef enum {
    ADC_PPB_PosSyb = 0U,    /*Positive numbers */
    ADC_PPB_NegSyb          /*Negative numbers */
} ADC_PPBSymbol;

/**
  * @}
  */

/** @defgroup ADC_PULSEPOSMODE ADC pulseMode parameter Selection
  * @{
  * @brief  Macro definitions about ADC pulseMode parameter
  */
typedef enum {
    ADC_PULSE_END_OF_ACQ_WIN = 0U,    /*!< Occurs at the end of the acquisition window */
    ADC_PULSE_END_OF_CONV             /*!< Occurs at the end of the conversion */
} ADC_PulsePosMode;

/**
  * @}
  */

/** @defgroup ADC_EN ADC function enable or disable Selection
  * @{
  * @brief  Macro definitions about ADC function enable or disable
  */
typedef enum {
    ADC_DISABLE = 0U,    /*!< ADC Function disable */
    ADC_ENABLE           /*!< ADC Function enable */
} ADC_EN;

/**
  * @}
  */

/** @defgroup ADC_SOCMASK ADC ADCSOCFRC1 Register Definition
  * @{
  * @brief  Macro definitions about ADC_SOCMASK Register Definition
  * @note   The ADC_SOCMASK register is used to configure the ADC Software trigger SOCx.
  */
#define ADC_FORCE_SOC0     (0x00000001UL)    /*!< SW trigger ADC SOC 0 */
#define ADC_FORCE_SOC1     (0x00000002UL)    /*!< SW trigger ADC SOC 1 */
#define ADC_FORCE_SOC2     (0x00000004UL)    /*!< SW trigger ADC SOC 2 */
#define ADC_FORCE_SOC3     (0x00000008UL)    /*!< SW trigger ADC SOC 3 */
#define ADC_FORCE_SOC4     (0x00000010UL)    /*!< SW trigger ADC SOC 4 */
#define ADC_FORCE_SOC5     (0x00000020UL)    /*!< SW trigger ADC SOC 5 */
#define ADC_FORCE_SOC6     (0x00000040UL)    /*!< SW trigger ADC SOC 6 */
#define ADC_FORCE_SOC7     (0x00000080UL)    /*!< SW trigger ADC SOC 7 */
#define ADC_FORCE_SOC8     (0x00000100UL)    /*!< SW trigger ADC SOC 8 */
#define ADC_FORCE_SOC9     (0x00000200UL)    /*!< SW trigger ADC SOC 9 */
#define ADC_FORCE_SOC10    (0x00000400UL)    /*!< SW trigger ADC SOC 10 */
#define ADC_FORCE_SOC11    (0x00000800UL)    /*!< SW trigger ADC SOC 11 */
#define ADC_FORCE_SOC12    (0x00001000UL)    /*!< SW trigger ADC SOC 12 */
#define ADC_FORCE_SOC13    (0x00002000UL)    /*!< SW trigger ADC SOC 13 */
#define ADC_FORCE_SOC14    (0x00004000UL)    /*!< SW trigger ADC SOC 14 */
#define ADC_FORCE_SOC15    (0x00008000UL)    /*!< SW trigger ADC SOC 15 */

/**
  * @}
  */
  
/** @defgroup ADC_ADCEVTSEL ADC ADCEVTSEL Register Definition
  * @{
  * @brief  Macro definitions about ADC ADCEVTSEL Register Definition
  * @note   The ADCEVTSEL register is used to configure the event selection, event interrupt selection, and event status for each SOCn.
  */
#define ADC_EVTSEL_MASK       (0x00000007UL)    /*!< ADC_ADCEVTSEL Mask Value */
#define ADC_EVTINTSEL_MASK    (0x00000007UL)    /*!< ADC_EVTINTSEL Mask Value */
#define ADC_EVTSTAT_MASK      (0x00000007UL)    /*!< ADC_EVTSTAT Mask Value */

/**
  * @}
  */

/** @defgroup ADC_INTSEL1N2 ADC INT Register Definition
  * @{
  * @brief  Macro definitions about ADC INT Register Definition
  * @note   The INTSEL1N2 register is used to configure the interrupt selection for each SOCn.
  */
#define ADC_ADCINTSELXNY_INTXE_MASK       (0x00000020UL)    /*!< ADC_ADCINTSELXNY ADCINT Interrupt Enable Mask Value */
#define ADC_ADCINTSELXNY_INTXSEL_MASK     (0x0000001FUL)    /*!< ADC_ADCINTSELXNY EOC Source Select Mask Value */
#define ADC_ADCINTSELXNY_INTXCONT_MASK    (0x00000040UL)    /*!< ADC_ADCINTSELXNY ADCINTX Continue to Interrupt Mode Mask Value */

/**
  * @}
  */

/** @defgroup ADC_INTEN ADC INT Register Definition
  * @{
  * @brief  Macro definitions about ADC INT Register Definition
  * @note   The INTEN register is used to configure each interrupt enable output to NVIC.
  */
#define ADC_ADCINTEN_MASK    (0x00000001UL)    /*!< ADC_ADCINTEN ADCINT Interrupt Enable output to NVIC */

/**
  * @}
  */

/** @defgroup ADC_ADCTRIM ADC ADCTRIM Register Definition
  * @{
  * @brief  Macro definitions about ADC ADCTRIM Register Definition
  * @note   The ADCTRIM register is used to configure the offset value and direction of the ADC trim.
  */
#define ADC_ADCTRIM_TRIMOFFSET_MASK    (0x00001F00UL)    /*!< ADC_ADCTRIM OFFSET Value Mask Value */

/**
  * @}
  */

/** @defgroup ADC_TSENSORCFG Parameter Configuration of ADC Temperature Sensor
  * @{
  * @brief  Macro definitions about reference voltage and conversion coefficient of ADC
  */
#define ADC_TSENSOR_VREH_VOLT                 (3.3F)        /*!< Reference voltage of temperature sensor*/
#define ADC_TSENSOR_CONVERSION_COEFFICIENT    (3.84775F)    /*!< ADC_TSENSOR_CONVERSION_COEFFICIENT=(4096*0.0031/ADC_TSENSOR_VREH_VOLT)*/

/**
  * @}
  */

/**
  * @}
  */
  
  
/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
  * \brief  Configures the analog-to-digital converter module prescaler.
  * \note   clkPrescale parameter specifies the value by which the input clock is divided to make the ADCCLK.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  * \param  clkPrescale    ADC clock prescaler
  *                         This parameter can be any value of @ref ADC_ClkPrescale.
  */
static inline void ADC_setPrescaler (ADC_TypeDef *base, ADC_ClkPrescale clkPrescale)
{
    MODIFY_REG(base->ADCCTL2.WORDVAL, ADC_ADCCTL2_PRESCALE_M, (clkPrescale & ADC_ADCCTL2_PRESCALE_M));
}

/**
  * \brief  Configures a start-of-conversion (SOC) in the ADC.
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  socNumber       ADC SOC number
  *                          This parameter can be any value of @ref ADC_SOCNumber.
  * \param  trigger         ADC trigger source
  *                          This parameter can be any value of @ref ADC_Trigger.
  * \param  channel         ADC channel number
  *                          This parameter can be any value of @ref ADC_Channel.
  * \param  sampleWindow    ADC sample window
  *                          This parameter can be any value of @ref ADC_SampleWindow.
  */
static inline void ADC_setupSOC (ADC_TypeDef *base, ADC_SOCNumber socNumber, ADC_Trigger trigger, \
                                            ADC_Channel channel, uint32_t sampleWindow)
{
    uint32_t temp;

    __IO uint32_t* mSocReg = &(base->ADCSOC0CTL.WORDVAL);
    temp = ((trigger << ADC_ADCSOC0CTL_TRIGSEL_S) | (channel << ADC_ADCSOC0CTL_CHSEL_S) | (sampleWindow - 1UL));
    mSocReg[socNumber] = temp;
}

/**
  * \brief  Configures ADC the interrupt SOC trigger of an SOC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  socNumber    ADC SOC number
  *                       This parameter can be any value of @ref ADC_SOCNumber.
  * \param  trigger      ADC trigger source
  *                       This parameter can be any value of @ref ADC_Trigger.
  */
static inline void ADC_setInterruptSOCTrigger (ADC_TypeDef *base, ADC_SOCNumber socNumber, ADC_IntSOCTrigger trigger)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (socNumber > ADC_SOC_NUMBER7)? 1 : 0;
    addr = (uint32_t *)(&(base->ADCINTSOCSEL1) + temp);
    temp = (socNumber - (temp * 0x8UL)) << 1UL;
    MODIFY_REG(*addr, (ADC_ADCINTSOCSEL1_SOC0INTTRIG_M << temp), (trigger << temp));
}

/**
  * \brief  Sets the timing of the end-of-conversion pulse
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  pulsePosMode    ADC pulse position mode
  *                          This parameter can be any value of @ref ADC_PulsePosMode.
  */
static inline void ADC_setInterruptPulsePosMode (ADC_TypeDef *base, ADC_PulsePosMode pulsePosMode)
{
    MODIFY_REG(base->ADCCTL1.WORDVAL, (ADC_ADCCTL1_INTPULSEPOS_M), \
                                      (pulsePosMode << ADC_ADCCTL1_INTPULSEPOS_S));
}

/**
  * \brief  Sets the timing of early interrupt generation.
  * \param  base           ADC base address
  *                         - ADCA: ADC A base address
  *                         - ADCB: ADC B base address
  *                         - ADCC: ADC C base address
  * \param  cycleOffset    ADC cycle offset
  *                         This parameter can be any value of@ref ADC_CycleOffset.
  */
static inline void ADC_setInterruptCycleOffset (ADC_TypeDef *base, uint32_t cycleOffset)
{
    WRITE_REG(base->ADCINTCYCLE.WORDVAL, cycleOffset);
}

/**
  * \brief  Powers up the analog-to-digital converter core.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_enableConverter (ADC_TypeDef *base)
{
    SET_BIT(base->ADCCTL1.WORDVAL, ADC_ADCCTL1_ADCEN_M);
}

/**
  * \brief  Powers down the analog-to-digital converter module.
  * \note   Allow at least a 500us delay before sampling after calling this API.
  *         If you enable multiple ADCs, you can delay after they all have begun powering up.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_disableConverter (ADC_TypeDef *base)
{
    CLEAR_BIT(base->ADCCTL1.WORDVAL, ADC_ADCCTL1_ADCEN_M);
}

/**
  * \brief  Forces a SOC flag to a 1 in the analog-to-digital converter.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  socNumber    ADC SOC number
  *                       This parameter can be any value of @ref ADC_SOCNumber.
  */
static inline void ADC_forceSOC (ADC_TypeDef *base, ADC_SOCNumber socNumber)
{
    SET_BIT(base->ADCSOCFRC1.WORDVAL, (0x1UL << socNumber));
}

/**
  * \brief  Forces multiple SOC flags to 1 in the analog-to-digital converter.
  * \param  base       ADC base address
  *                     - ADCA: ADC A base address
  *                     - ADCB: ADC B base address
  *                     - ADCC: ADC C base address
  * \param  socMask    ADC mask
  *                     This parameter can be any value of @ref ADC_SOCMask.
  */
static inline void ADC_forceMultipleSOC (ADC_TypeDef *base, uint32_t socMask)
{
    WRITE_REG(base->ADCSOCFRC1.WORDVAL, socMask);
}

/**
  * \brief  Gets the current ADC interrupt status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  * \return Returns the value in the data register for the Interrupt Status.
  *                       - 0: false  the interrupt flag for the specified interrupt number is not set
  *                       - 1: true   the interrupt flag for the specified interrupt number is set
  */
static inline uint32_t ADC_getInterruptStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    return READ_BIT(base->ADCINTFLG.WORDVAL, (0x1UL << adcIntNum))? 1UL : 0UL;
}

/**
  * \brief  Clears the ADC interrupt status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_clearInterruptStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    SET_BIT(base->ADCINTFLGCLR.WORDVAL, (0x1UL << adcIntNum));
}

/**
  * \brief  Gets the ADC interrupt overflow status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  * \return Returns the interrupt overflow status for the given interrupt number
  *                     - 0: false is the interrupt overflow flag for the specified interrupt number is not set
  *                     - 1: true is the interrupt overflow flag for the specified interrupt number is set
  * \note   This function is only valid when the ADC is in burst mode.
  */
static inline uint32_t ADC_getInterruptOverflowStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    return READ_BIT(base->ADCINTOVF.WORDVAL, (0x1UL << adcIntNum))? 1UL : 0UL;
}

/**
  * \brief  Clears the ADC interrupt overflow status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_clearInterruptOverflowStatus (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    SET_BIT(base->ADCINTOVFCLR.WORDVAL, (0x1UL << adcIntNum));
}

/**
  * \brief  Reads the ADC result.
  * \param  resultBase    ADC result base address
  *                        - ADCA: ADC A result base address
  *                        - ADCB: ADC B result base address
  *                        - ADCC: ADC C result base address
  * \param  socNumber     ADC SOC number
  *                        This parameter can be any value of @refADC_SOCNumber.
  * \return Returns the conversion result.
  */
static inline uint32_t ADC_readResult (ADCRESULT_TypeDef *resultBase, ADC_SOCNumber socNumber)
{
    return READ_BIT(TYPE32(&(resultBase->RESULT0.WORDVAL) + socNumber), ADCRESULT_RESULT0_RESULT_M);
}

/**
  * \brief  Checks whether the ADC is busy.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  * \return Returns if the ADC is sampling or all samples are complete
  *                - 0: false all samples are complete
  *                - 1: true is sampling
  */
static inline uint32_t ADC_isBusy (ADC_TypeDef *base)
{
    return READ_BIT(base->ADCCTL1.WORDVAL, ADC_ADCCTL1_ADCBSY_M)? 1UL : 0UL;
}

/**
  * \brief  Sets the burst mode configuration.
  * \param  base            ADC base address
  *                          - ADCA: ADC A base address
  *                          - ADCB: ADC B base address
  *                          - ADCC: ADC C base address
  * \param  burstTrigger    ADC burst trigger
  *                          This parameter can be any value of @ref ADC_BurstTrigger.
  * \param  burstSize       ADC burst size
  *                          This parameter can be any value of @ref ADC_BurstSize.
  */
static inline void ADC_setBurstModeConfig (ADC_TypeDef *base, ADC_BurstTrigger burstTrigger, uint32_t burstSize)
{
    MODIFY_REG(base->ADCBURSTCTL.WORDVAL, ADC_ADCBURSTCTL_BURSTTRIGSEL_M, burstTrigger);
    MODIFY_REG(base->ADCBURSTCTL.WORDVAL, ADC_ADCBURSTCTL_BURSTSIZE_M, (burstSize << ADC_ADCBURSTCTL_BURSTSIZE_S));
}

/**
  * \brief  Enables the burst mode.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_enableBurstMode (ADC_TypeDef *base)
{
    SET_BIT(base->ADCBURSTCTL.WORDVAL, ADC_ADCBURSTCTL_BURSTEN_M);
}

/**
  * \brief  Disables the burst mode.
  * \param  base    ADC base address
  *                  - ADCA: ADC A base address
  *                  - ADCB: ADC B base address
  *                  - ADCC: ADC C base address
  */
static inline void ADC_disableBurstMode (ADC_TypeDef *base)
{
    CLEAR_BIT(base->ADCBURSTCTL.WORDVAL, ADC_ADCBURSTCTL_BURSTEN_M);
}

/**
  * \brief  Sets the ADC SOC priority mode.
  * \param  base       ADC base address
  *                     - ADCA: ADC A base address
  *                     - ADCB: ADC B base address
  *                     - ADCC: ADC C base address
  * \param  priMode    ADC SOC priority mode
  *                     This parameter can be any value of @ref ADC_PriorityMode.
  */
static inline void ADC_setSOCPriority (ADC_TypeDef *base, ADC_PriorityMode priMode)
{
    MODIFY_REG(base->ADCSOCPRICTL.WORDVAL, ADC_ADCSOCPRICTL_SOCPRIORITY_M, priMode);
}

/**
  * \brief  Configures a post-processing block (PPB) in the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \param  socNumber    ADC SOC number
  *                       This parameter can be any value of @ref ADC_SOCNumber.
  */
static inline void ADC_setupPPB (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, ADC_SOCNumber socNumber)
{
    MODIFY_REG(TYPE32(&(base->ADCPPB1CONFIG) + (ppbNumber * 6UL)), ADC_ADCPPB1CONFIG_CONFIG_M, socNumber);
}

/**
  * \brief  Enables individual the ADC PPB event sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parametercan be any value of @ref ADC_PPBNumber.
  * \param  evtFlags     ADC PPB event flags
  *                       This parameter can be any value of @ref ADC_PPBEvtFlags.
  */
static inline void ADC_enablePPBEvent (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t evtFlags)
{
    MODIFY_REG(base->ADCEVTSEL.WORDVAL, (ADC_EVTSEL_MASK << (ppbNumber << 2UL)), \
               ((evtFlags & ADC_EVTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Disables individual the ADC PPB event sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \param  evtFlags     ADC PPB event flags
  *                       This parameter can be any value of @ref ADC_PPBEvtFlags.
  */
static inline void ADC_disablePPBEvent (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t evtFlags)
{
    CLEAR_BIT(base->ADCEVTSEL.WORDVAL, ((evtFlags & ADC_EVTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Enables individual the ADC PPB event interrupt sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  * \param  intFlags     ADC PPB interrupt flags
  *                       This parameter can be any value of @ref ADC_PPBIntFlags.
  */
static inline void ADC_enablePPBEventInterrupt (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t intFlags)
{
    MODIFY_REG(base->ADCEVTINTSEL.WORDVAL, (ADC_EVTINTSEL_MASK << (ppbNumber << 2UL)), \
               ((intFlags & ADC_EVTINTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Disables individual the ADC PPB event interrupt sources.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \param  intFlags     ADC PPB interrupt flags
  *                       This parameter can be any value of @ref ADC_PPBIntFlags.
  */
static inline void ADC_disablePPBEventInterrupt (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t intFlags)
{
    CLEAR_BIT(base->ADCEVTINTSEL.WORDVAL, ((intFlags & ADC_EVTINTSEL_MASK) << (ppbNumber << 2UL)));
}

/**
  * \brief  Gets the ADC PPB event status.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \return Returns the current event status.
  *                     - ADC_EVT_TRIPHI
  *                     - ADC_EVT_TRIPLO
  *                     - ADC_EVT_ZERO
  */
static inline uint32_t ADC_getPPBEventStatus (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    uint32_t temp;

    temp = READ_REG(base->ADCEVTSTAT.WORDVAL) ;
    return (temp >> (ppbNumber * 4UL)) & ADC_EVTSEL_MASK;
}

/**
  * \brief  Clears the ADC PPB event flags.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \param  evtFlags     ADC PPB event flags
  *                       This parameter can be any value of @ref ADC_PPBEvtFlags.
  */
static inline void ADC_clearPPBEventStatus (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t evtFlags)
{
    WRITE_REG(base->ADCEVTCLR.WORDVAL, (evtFlags & ADC_EVTSTAT_MASK) << (ppbNumber << 2UL));
}

/**
  * \brief  Enables cycle-by-cycle clear of ADC PPB event flags.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline void ADC_enablePPBEventCBCClear (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    SET_BIT(TYPE32(&(base->ADCPPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1CONFIG_CBCEN_M);
}
/**
  * \brief  Disables cycle-by-cycle clear of ADC PPB event flags.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber
  */
static inline void ADC_disablePPBEventCBCClear (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    CLEAR_BIT(TYPE32(&(base->ADCPPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1CONFIG_CBCEN_M);
}

/**
  * \brief  Reads the processed conversion result from the PPB.
  * \param  resultBase    ADC result base address
  *                        - ADCA: ADC A result base address
  *                        - ADCB: ADC B result base address
  *                        - ADCC: ADC C result base address
  * \param  ppbNumber     ADC ppbNumber is the number of the post-processing block.
  *                        This parameter can be any value of @ref ADC_PPBNumber.
  * \return Returns the signed 32-bit conversion result.
  */
static inline uint32_t ADC_readPPBResult (ADCRESULT_TypeDef *resultBase, ADC_PPBNumber ppbNumber)
{
    return READ_BIT(TYPE32(&(resultBase->PPB1RESULT.WORDVAL) + ppbNumber), ADCRESULT_RESULT0_RESULT_M);
}

/**
  * \brief  Reads the delay time stamp of the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \return Returns the delay time stamp.
  */
static inline uint32_t ADC_getPPBDelayTimeStamp (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    return READ_REG(TYPE32(&(base->ADCPPB1STAMP.WORDVAL) + (ppbNumber * 6UL)));
}

/**
  * \brief  Sets the post processing block offset correction.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \param  offset       The offset of the PPB.
  *                       This parameter can be any value of @ref ADC_Result.
  */
static inline void ADC_setPPBCalibrationOffset (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, uint32_t offset)
{
    MODIFY_REG(TYPE32(&(base->ADCPPB1OFFCAL.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1OFFCAL_OFFCAL_M, offset);
}

/**
  * \brief  Sets the post processing block reference offset.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  * \param  offset       The reference offset of the PPB
  *                       This parameter can be any value of @ref ADC_Result.
  */
static inline void ADC_setPPBReferenceOffset (ADC_TypeDef *base, ADC_PPBNumber ppbNumber,
                                              uint32_t offset)
{
    MODIFY_REG(TYPE32(&(base->ADCPPB1OFFREF.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1OFFREF_OFFREF_M, \
               offset);
}

/**
  * \brief  Enables the two's complement capability of the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  */
static inline void ADC_enablePPBTwosComplement (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    SET_BIT(TYPE32(&(base->ADCPPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1CONFIG_TWOSCOMPEN_M);
}

/**
  * \brief  Disables the two's complement capability of the PPB.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  ppbNumber    ADC ppbNumber is the number of the post-processing block.
  *                       This parameter can be any value of @ref ADC_PPBNumber.
  */
static inline void ADC_disablePPBTwosComplement (ADC_TypeDef *base, ADC_PPBNumber ppbNumber)
{
    CLEAR_BIT(TYPE32(&(base->ADCPPB1CONFIG.WORDVAL) + (ppbNumber * 6UL)), ADC_ADCPPB1CONFIG_TWOSCOMPEN_M);
}

/**
  * \brief  Enables the interrupt of the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_enableInterrupt (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->ADCINTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    MODIFY_REG(*addr, (ADC_ADCINTSELXNY_INTXE_MASK << temp), (ADC_ADCINTSELXNY_INTXE_MASK << temp));
    MODIFY_REG(base->ADCINTEN.WORDVAL, (ADC_ADCINTEN_MASK << adcIntNum), (ADC_ADCINTEN_MASK << adcIntNum));
}

/**
  * \brief  Disables the interrupt of the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_disableInterrupt (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->ADCINTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    CLEAR_BIT(*addr, (ADC_ADCINTSELXNY_INTXE_MASK << temp));
    CLEAR_BIT(base->ADCINTEN.WORDVAL, (ADC_ADCINTEN_MASK << adcIntNum));
}

/**
  * \brief  Sets the source EOC for an analog-to-digital converter interrupt.
  * \param  base          ADC base address
  *                        - ADCA: ADC A base address
  *                        - ADCB: ADC B base address
  *                        - ADCC: ADC C base address
  * \param  adcIntNum     ADC interrupt number
  *                        This parameter can be any value of @ref ADC_IntNumber.
  * \param  intTrigger    ADC interrupt trigger
  *                        This parameter can be any value of @ref ADC_IntTrigger.
  */
static inline void ADC_setInterruptSource (ADC_TypeDef *base, ADC_IntNumber adcIntNum, uint32_t intTrigger)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->ADCINTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    MODIFY_REG(*addr, (ADC_ADCINTSELXNY_INTXSEL_MASK << temp), ((intTrigger & ADC_ADCINTSELXNY_INTXSEL_MASK) << temp));
}

/**
  * \brief  Enables the continuous mode of the ADC.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_enableContinuousMode (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->ADCINTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    MODIFY_REG(*addr, (ADC_ADCINTSELXNY_INTXCONT_MASK << temp), (ADC_ADCINTSELXNY_INTXCONT_MASK << temp));
}

/**
  * \brief  Disables the continuous mode of the ADC interrupt.
  * \param  base         ADC base address
  *                       - ADCA: ADC A base address
  *                       - ADCB: ADC B base address
  *                       - ADCC: ADC C base address
  * \param  adcIntNum    ADC interrupt number
  *                       This parameter can be any value of @ref ADC_IntNumber.
  */
static inline void ADC_disableContinuousMode (ADC_TypeDef *base, ADC_IntNumber adcIntNum)
{
    uint32_t temp;
    __IO uint32_t *addr;

    temp = (adcIntNum > ADC_INT_NUMBER2)? 1 : 0;
    addr = (uint32_t *)(&(base->ADCINTSEL1N2) + temp);
    temp = (adcIntNum - (temp << 1UL)) << 3UL;
    CLEAR_BIT(*addr, (ADC_ADCINTSELXNY_INTXCONT_MASK << temp));
}

/**
  * \brief  Converts temperature from sensor reading to degrees C
  * \param  tempResult    ADC temp result
  * \param  refVolt       ADC reference voltage
  *                       This parameter can be any value of @ref ADC_IntNumber.
  * \return Returns the temperature sensor reading converted to degrees C.
  */
static inline uint32_t ADC_getTemperatureC (uint32_t tempResult, float refVolt)
{
    uint32_t temperature_data;
    //note:The user can generate calculation methods based on the actual voltage calibration values.
    temperature_data = (uint32_t)(25+(((float)tempResult/4095 * refVolt - 0.925f) * 1000 /3.09f));

    return temperature_data;
}

/**
  * \brief  Configures the ADC module's reference mode and offset trim
  * \note   In this device, the bandgaps are common for all the ADC instances,
  *         hence common Vref configuration needs to be done for all the ADCs. This
  *         API configures same Vref configuration for all the supported ADCs in the device.
  * \param  base          ADC base address
  *                        - ADCA: ADCA_BASE
  *                        - ADCB: ADCB_BASE
  *                        - ADCC: ADCC_BASE
  * \param  refMode       ADC reference Mode
  *                        This parameter can be one of the following @ref ADC_ReferenceMode:
  * \param  refVoltage    ADC reference Voltage
  *                        This parameter can be one of the following @ref ADC_ReferenceVoltage:
  */
extern void ADC_setVREF (ADC_TypeDef *base, ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage);

/**
  * \brief  Configures the offset trim for the desired ADC instance
  * \note   This function loads the offset trims for the desired ADC instance.
  * \param  base       ADC base address
  *                     - ADCA: ADCA_BASE
  *                     - ADCB: ADCB_BASE
  *                     - ADCC: ADCC_BASE
  * \param  refMode    ADC reference Mode
  *                     This parameter can be one of the following @ref ADC_ReferenceMode:
  */
extern void ADC_setOffsetTrim (ADC_TypeDef *base, ADC_ReferenceMode refMode);

/**
  * \brief  Configures All the offset trim for all the ADC instances
  * \note   This function loads the offset trims for all the ADC instances.
  * \param  refMode       ADC reference Mode
  *                        This parameter can be one of the following @ref ADC_ReferenceMode:
  * \param  refVoltage    ADC reference Voltage
  *                        This parameter can be one of the following @ref ADC_ReferenceVoltage:
  */
extern void ADC_setOffsetTrimAll (ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage);

/**
  * \brief  Sets the windowed trip limits for a PPB.
  * \note   This function sets the windowed trip limits for a PPB. These values set
  *         the digital comparator trip high and low limits.
  *         The trip limits are used to determine when the PPB is tripped.
  * \param  base           ADC base address
  *                         - ADCA: ADCA_BASE
  *                         - ADCB: ADCB_BASE
  *                         - ADCC: ADCC_BASE
  * \param  ppbNumber      ADC PPB Number
  *                         This parameter can be one of the following @ref ADC_PPBNumbe:
  * \param  sybol          ADC PPB Symbol
  *                         This parameter can be one of the following @ref ADC_PPBSymbol:
  * \param  tripHiLimit    ADC PPB Trip Hi Limit
  * \param  tripLoLimit    ADC PPB Trip Lo Limit
  */
extern void ADC_setPPBTripLimits (ADC_TypeDef *base, ADC_PPBNumber ppbNumber, ADC_PPBSymbol sybol, \
                                  uint32_t tripHiLimit, uint32_t tripLoLimit);


#ifdef __cplusplus
}
#endif


#endif /*__ADC_H__ */
