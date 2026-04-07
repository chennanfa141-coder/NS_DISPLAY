/**
  * @file       xbar.h
  * @author     wuxiao
  * @brief      Function file for NS800RT1xxx xbar module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __XBAR_H__
#define __XBAR_H__


#ifdef __cplusplus
extern "C"
{
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_xbar.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup XBAR_EXPORTED_TYPES X-BAR Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'XBAR' module.
  */

/** @defgroup XBAR_OUTPUTNUM OUTPUTXBAR number of values
  * @{
  * @brief  The following values define the \e output parameter for
  *         XBAR_setOutputMuxConfig(), XBAR_enableOutputMux(), and
  *         XBAR_disableOutputMux().
  */
typedef enum {
    XBAR_OUTPUT1 = 0U,     /*!< OUTPUT1 of the Output X-BAR */
    XBAR_OUTPUT2 = 4U,     /*!< OUTPUT2 of the Output X-BAR */
    XBAR_OUTPUT3 = 8U,     /*!< OUTPUT3 of the Output X-BAR */
    XBAR_OUTPUT4 = 12U,    /*!< OUTPUT4 of the Output X-BAR */
    XBAR_OUTPUT5 = 16U,    /*!< OUTPUT5 of the Output X-BAR */
    XBAR_OUTPUT6 = 20U,    /*!< OUTPUT6 of the Output X-BAR */
    XBAR_OUTPUT7 = 24U,    /*!< OUTPUT7 of the Output X-BAR */
    XBAR_OUTPUT8 = 28U     /*!< OUTPUT8 of the Output X-BAR */
} XBAR_OutputNum;

/**
  * @}
  */

/** @defgroup XBAR_TRIPNUM ePWM X-BAR trip number of values
  * @{
  * @brief  The following values define the \e trip parameter for
  *         XBAR_setEPWMMuxConfig(), XBAR_invertEPWMSignal(), XBAR_enableEPWMMux(),
  *         and XBAR_disableEPWMMux().
  */
typedef enum {
    XBAR_TRIP4  = 0U,     /*!< TRIP4 of the ePWM X-BAR */
    XBAR_TRIP5  = 4U,     /*!< TRIP5 of the ePWM X-BAR */
    XBAR_TRIP7  = 8U,     /*!< TRIP7 of the ePWM X-BAR */
    XBAR_TRIP8  = 12U,    /*!< TRIP8 of the ePWM X-BAR */
    XBAR_TRIP9  = 16U,    /*!< TRIP9 of the ePWM X-BAR */
    XBAR_TRIP10 = 20U,    /*!< TRIP10 of the ePWM X-BAR */
    XBAR_TRIP11 = 24U,    /*!< TRIP11 of the ePWM X-BAR */
    XBAR_TRIP12 = 28U     /*!< TRIP12 of the ePWM X-BAR */
} XBAR_TripNum;

/**
  * @}
  */

/** @defgroup XBAR_INPUTNUM Definition of INPUTXBAR address offset number
  * @{
  * @brief  
  * @note   The following values define the \e input parameter for XBAR_setInputPin().
  */
typedef enum {
    /* INPUT-XBAR */
    XBAR_INPUT1  = 0x0U,    /*!< INPUT ePWM[TZ1], ePWM[TRIP1], X-BARs, eCAPs */
    XBAR_INPUT2  = 0x1U,    /*!< INPUT ePWM[TZ2], ePWM[TRIP2], X-BARs, eCAPs */
    XBAR_INPUT3  = 0x2U,    /*!< INPUT ePWM[TZ3], ePWM[TRIP3], X-BARs, eCAPs */
    XBAR_INPUT4  = 0x3U,    /*!< INPUT ADC wrappers, X-BARs, XINT1, eCAPs */
    XBAR_INPUT5  = 0x4U,    /*!< INPUT EXTSYNCIN1, X-BARs, XINT2, eCAPs */
    XBAR_INPUT6  = 0x5U,    /*!< INPUT EXTSYNCIN2, ePWM[TRIP6], X-BARs, XINT3, eCAPs */
    XBAR_INPUT7  = 0x6U,    /*!< INPUT X-BARs, eCAPs */
    XBAR_INPUT8  = 0x7U,    /*!< INPUT X-BARs, eCAPs */
    XBAR_INPUT9  = 0x8U,    /*!< INPUT X-BARs, eCAPs */
    XBAR_INPUT10 = 0x9U,    /*!< INPUT X-BARs, eCAPs */
    XBAR_INPUT11 = 0xAU,    /*!< INPUT X-BARs, eCAPs */
    XBAR_INPUT12 = 0xBU,    /*!< INPUT X-BARs, eCAPs */
    XBAR_INPUT13 = 0xCU,    /*!< INPUT XINT4, X-BARs, eCAPs */
    XBAR_INPUT14 = 0xDU,    /*!< INPUT XINT5, X-BARs, eCAPs */
    XBAR_INPUT15 = 0xEU,    /*!< INPUT eCAPs */
    XBAR_INPUT16 = 0xFU     /*!< INPUT eCAPs */
} XBAR_InputNum;

/**
  * @}
  */

/** @defgroup XBAR_INPUTGPIOPIN Definition of INPUTXBAR MUX function set
  * @{
  * @brief  Macro definitions about the bit fields in the XBAR INPUT register definition.
  * @note   Values that can be passed to all X-BAR gpio as the \e XBAR_setInputPin()
  *          parameter use below.
  */
typedef enum {
    XBAR_INPUT_GPIO_00      = 44u,
    XBAR_INPUT_GPIO_01      = 7U,
    XBAR_INPUT_GPIO_02      = 22U,
    XBAR_INPUT_GPIO_03      = 41U,
    XBAR_INPUT_GPIO_04      = 0U,
    XBAR_INPUT_GPIO_05      = 1U,
    XBAR_INPUT_GPIO_06      = 32U,
    XBAR_INPUT_GPIO_07      = 35U,
    XBAR_INPUT_GPIO_08      = 27U,
    XBAR_INPUT_GPIO_09      = 17U,
    XBAR_INPUT_GPIO_10      = 23U,
    XBAR_INPUT_GPIO_11      = 68U,
    XBAR_INPUT_GPIO_12      = 65U,
    XBAR_INPUT_GPIO_13      = 9U,
    XBAR_INPUT_GPIO_14      = 10U,
    XBAR_INPUT_GPIO_15      = 5U,
    XBAR_INPUT_GPIO_16      = 37U,
    XBAR_INPUT_GPIO_17      = 26U,
    XBAR_INPUT_GPIO_18      = 25U,
    XBAR_INPUT_GPIO_19      = 39U,
    XBAR_INPUT_GPIO_20      = 34U,
    XBAR_INPUT_GPIO_21      = 15U,
    XBAR_INPUT_GPIO_22      = 6U,
    XBAR_INPUT_GPIO_23      = 29U,
    XBAR_INPUT_GPIO_24      = 14U,
    XBAR_INPUT_GPIO_25      = 64U,
    XBAR_INPUT_GPIO_26      = 16U,
    XBAR_INPUT_GPIO_27      = 13U,
    XBAR_INPUT_GPIO_28      = 24U,
    XBAR_INPUT_GPIO_29      = 33U,
    XBAR_INPUT_GPIO_30      = 11U,
    XBAR_INPUT_GPIO_31      = 12U,
    XBAR_INPUT_GPIO_32      = 30U,
    XBAR_INPUT_GPIO_33      = 31U,
    XBAR_INPUT_GPIO_34      = 45U,
    XBAR_INPUT_GPIO_35      = 3U,
    XBAR_INPUT_GPIO_36      = 2U,
    XBAR_INPUT_GPIO_37      = 4U,
    XBAR_INPUT_GPIO_38      = 8U, 
    XBAR_INPUT_GPIO_39      = 42U, 
    XBAR_INPUT_GPIO_40      = 40U,  
    XBAR_INPUT_GPIO_41      = 67U,
    XBAR_INPUT_GPIO_42      = 28U,
    XBAR_INPUT_GPIO_43      = 46U,
    XBAR_INPUT_GPIO_44      = 66U,
    XBAR_INPUT_GPIO_224     = 0xE0U,
    XBAR_INPUT_GPIO_225,
    XBAR_INPUT_GPIO_230     = 0xE6U,
    XBAR_INPUT_GPIO_231,
    XBAR_INPUT_GPIO_232,
    XBAR_INPUT_GPIO_233,
    XBAR_INPUT_GPIO_237     = 0xEDU,
    XBAR_INPUT_GPIO_238,
    XBAR_INPUT_GPIO_239,
    XBAR_INPUT_GPIO_241     = 0xF1U,
    XBAR_INPUT_GPIO_242,
    XBAR_INPUT_GPIO_244     = 0xF4U,
    XBAR_INPUT_GPIO_245,
    XBAR_INPUT_GPIO_252     = 18U,    
    XBAR_INPUT_GPIO_253     = 19U,    
    XBAR_INPUT_GPIO_254     = 20U,    
    XBAR_INPUT_GPIO_255     = 21U,      /*!< X-BAR INPUT HIGH LEVEL //notice!*/
    XBAR_INPUT_LOW_LEVEL    = 0xFFU     /*!< X-BAR INPUT LOW LEVEL //notice!*/
} XBAR_InputGPIOPin;

/**
  * @}
  */

/** @defgroup XBAR_OUTPUTMUXCONFIG Definition of OUTPUTXBAR MUX function set
  * @{
  * @brief  Macro definitions about the bit fields in the XBAR OUTPUTMUX register definition.
  * @note   The following values define the \e muxConfig parameter for
  *          XBAR_setOutputMuxConfig().
  */
typedef enum {
    /* OUTPUTXBAR */
    XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH       = 0x0000U,    /*!< X-BAR OUT MUX00 CMPSS1 CTRIPOUTH */
    XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH_OR_L  = 0x0001U,    /*!< X-BAR OUT MUX00 CMPSS1 CTRIPOUTH OR L*/
    XBAR_OUT_MUX00_ADCAEVT1               = 0x0002U,    /*!< X-BAR OUT MUX00 ADCAEVT1 */
    XBAR_OUT_MUX00_ECAP1_OUT              = 0x0003U,    /*!< X-BAR OUT MUX00 ECAP1 OUT */
    XBAR_OUT_MUX01_CMPSS1_CTRIPOUTL       = 0x0200U,    /*!< X-BAR OUT MUX01 CMPSS1 CTRIPOUTL */
    XBAR_OUT_MUX01_INPUTXBAR1             = 0x0201U,    /*!< X-BAR OUT MUX01 INPUTXBAR1 */
    XBAR_OUT_MUX01_ADCCEVT1               = 0x0203U,    /*!< X-BAR OUT MUX01 ADCCEVT1 */
    XBAR_OUT_MUX02_CMPSS2_CTRIPOUTH       = 0x0400U,    /*!< X-BAR OUT MUX02 CMPSS2 CTRIPOUTH */
    XBAR_OUT_MUX02_CMPSS2_CTRIPOUTH_OR_L  = 0x0401U,    /*!< X-BAR OUT MUX02 CMPSS2 CTRIPOUTH OR L */
    XBAR_OUT_MUX02_ADCAEVT2               = 0x0402U,    /*!< X-BAR OUT MUX02 ADCAEVT2 */
    XBAR_OUT_MUX02_ECAP2_OUT              = 0x0403U,    /*!< X-BAR OUT MUX02 ECAP2 OUT */
    XBAR_OUT_MUX03_CMPSS2_CTRIPOUTL       = 0x0600U,    /*!< X-BAR OUT MUX03 CMPSS2 CTRIPOUTL */
    XBAR_OUT_MUX03_INPUTXBAR2             = 0x0601U,    /*!< X-BAR OUT MUX03 INPUTXBAR2 */
    XBAR_OUT_MUX03_ADCCEVT2               = 0x0603U,    /*!< X-BAR OUT MUX03 ADCCEVT2 */
    XBAR_OUT_MUX04_CMPSS3_CTRIPOUTH       = 0x0800U,    /*!< X-BAR OUT MUX04 CMPSS3 CTRIPOUTH */
    XBAR_OUT_MUX04_CMPSS3_CTRIPOUTH_OR_L  = 0x0801U,    /*!< X-BAR OUT MUX04 CMPSS3 CTRIPOUTH OR L */
    XBAR_OUT_MUX04_ADCAEVT3               = 0x0802U,    /*!< X-BAR OUT MUX04 ADCAEVT3 */
    XBAR_OUT_MUX05_CMPSS3_CTRIPOUTL       = 0x0A00U,    /*!< X-BAR OUT MUX05 CMPSS3 CTRIPOUTL */
    XBAR_OUT_MUX05_INPUTXBAR3             = 0x0A01U,    /*!< X-BAR OUT MUX05 INPUTXBAR3 */
    XBAR_OUT_MUX05_ADCCEVT3               = 0x0A03U,    /*!< X-BAR OUT MUX05 ADCCEVT3 */
    XBAR_OUT_MUX06_CMPSS4_CTRIPOUTH       = 0x0C00U,    /*!< X-BAR OUT MUX06 CMPSS4 CTRIPOUTH */
    XBAR_OUT_MUX06_CMPSS4_CTRIPOUTH_OR_L  = 0x0C01U,    /*!< X-BAR OUT MUX06 CMPSS4 CTRIPOUTH OR L */
    XBAR_OUT_MUX06_ADCAEVT4               = 0x0C02U,    /*!< X-BAR OUT MUX06 ADCAEVT4 */
    XBAR_OUT_MUX07_CMPSS4_CTRIPOUTL       = 0x0E00U,    /*!< X-BAR OUT MUX07 CMPSS4 CTRIPOUTL */
    XBAR_OUT_MUX07_INPUTXBAR4             = 0x0E01U,    /*!< X-BAR OUT MUX07 INPUTXBAR4 */
    XBAR_OUT_MUX07_ADCCEVT4               = 0x0E03U,    /*!< X-BAR OUT MUX07 ADCCEVT4 */
    XBAR_OUT_MUX09_INPUTXBAR5             = 0x1201U,    /*!< X-BAR OUT MUX09 INPUTXBAR5 */
    XBAR_OUT_MUX11_INPUTXBAR6             = 0x1601U,    /*!< X-BAR OUT MUX11 INPUTXBAR6 */
    XBAR_OUT_MUX13_ADCSOCA                = 0x1A01U,    /*!< X-BAR OUT MUX13 ADCSOCA */
    XBAR_OUT_MUX14_EXTSYNCOUT             = 0x1C03U,    /*!< X-BAR OUT MUX14 EXTSYNCOUT */
    XBAR_OUT_MUX15_ADCSOCBO               = 0x1E01U,    /*!< X-BAR OUT MUX15 ADCSOCBO */
    XBAR_OUT_MUX19_ERROR_STS              = 0x2603U,    /*!< X-BAR OUT MUX19 ERROR STS */
    XBAR_OUT_MUX30_EPG1_OUT0              = 0x3C03U,    /*!< X-BAR OUT MUX30 EPG1 OUT0 */
    XBAR_OUT_MUX31_ERRSTS                 = 0x3E02U,    /*!< X-BAR OUT MUX31 ERRSTS */
    XBAR_OUT_MUX31_EPG1_OUT1              = 0x3E03U     /*!< X-BAR OUT MUX31 EPG1 OUT1 */
} XBAR_OutputMuxConfig;

/**
  * @}
  */

/** @defgroup XBAR_EPWMMUXCONFIG Definition of EPWMXBAR MUX function set
  * @{
  * @brief  Macro definitions about the bit fields in the XBAR EPWMOUTPUTMUX register definition.
  * @note   The following values define the \e muxConfig parameter for
  *          XBAR_setEPWMMuxConfig().
  */
typedef enum {
    XBAR_EPWM_MUX00_CMPSS1_CTRIPH          = 0x0000U,    /*!< X-BAR EPWM MUX00 CMPSS1 CTRIPOUTH */
    XBAR_EPWM_MUX00_CMPSS1_CTRIPH_OR_L     = 0x0001U,    /*!< X-BAR EPWM MUX00 CMPSS1 CTRIPOUTH OR L */
    XBAR_EPWM_MUX00_ADCAEVT1               = 0x0002U,    /*!< X-BAR EPWM MUX00 ADCAEVT1 */
    XBAR_EPWM_MUX00_ECAP1_OUT              = 0x0003U,    /*!< X-BAR EPWM MUX00 ECAP1 OUT */
    XBAR_EPWM_MUX01_CMPSS1_CTRIPL          = 0x0200U,    /*!< X-BAR EPWM MUX01 CMPSS1 CTRIPL */
    XBAR_EPWM_MUX01_INPUTXBAR1             = 0x0201U,    /*!< X-BAR EPWM MUX01 INPUTXBAR1 */
    XBAR_EPWM_MUX01_ADCCEVT1               = 0x0203U,    /*!< X-BAR EPWM MUX01 ADCCEVT1 */
    XBAR_EPWM_MUX02_CMPSS2_CTRIPH          = 0x0400U,    /*!< X-BAR EPWM MUX02 CMPSS2 CTRIPH */
    XBAR_EPWM_MUX02_CMPSS2_CTRIPH_OR_L     = 0x0401U,    /*!< X-BAR EPWM MUX02 CMPSS2 CTRIPH OR L */
    XBAR_EPWM_MUX02_ADCAEVT2               = 0x0402U,    /*!< X-BAR EPWM MUX02 ADCAEVT2 */
    XBAR_EPWM_MUX02_ECAP2_OUT              = 0x0403U,    /*!< X-BAR EPWM MUX02 ECAP2 OUT */
    XBAR_EPWM_MUX03_CMPSS2_CTRIPL          = 0x0600U,    /*!< X-BAR EPWM MUX03 CMPSS2 CTRIPL */
    XBAR_EPWM_MUX03_INPUTXBAR2             = 0x0601U,    /*!< X-BAR EPWM MUX03 INPUTXBAR2 */
    XBAR_EPWM_MUX03_ADCCEVT2               = 0x0603U,    /*!< X-BAR EPWM MUX03 ADCCEVT2 */
    XBAR_EPWM_MUX04_CMPSS3_CTRIPH          = 0x0800U,    /*!< X-BAR EPWM MUX04 CMPSS3 CTRIPH */
    XBAR_EPWM_MUX04_CMPSS3_CTRIPH_OR_L     = 0x0801U,    /*!< X-BAR EPWM MUX04 CMPSS3 CTRIPH OR L */
    XBAR_EPWM_MUX04_ADCAEVT3               = 0x0802U,    /*!< X-BAR EPWM MUX04 ADCAEVT3 */
    XBAR_EPWM_MUX05_CMPSS3_CTRIPL          = 0x0A00U,    /*!< X-BAR EPWM MUX05 CMPSS3 CTRIPL */
    XBAR_EPWM_MUX05_INPUTXBAR3             = 0x0A01U,    /*!< X-BAR EPWM MUX05 INPUTXBAR3 */
    XBAR_EPWM_MUX05_ADCCEVT3               = 0x0A03U,    /*!< X-BAR EPWM MUX05 ADCCEVT3 */
    XBAR_EPWM_MUX06_CMPSS4_CTRIPH          = 0x0C00U,    /*!< X-BAR EPWM MUX06 CMPSS4 CTRIPH */
    XBAR_EPWM_MUX06_CMPSS4_CTRIPH_OR_L     = 0x0C01U,    /*!< X-BAR EPWM MUX06 CMPSS4 CTRIPH OR L */
    XBAR_EPWM_MUX06_ADCAEVT4               = 0x0C02U,    /*!< X-BAR EPWM MUX06 CMPSS4 ADCAEVT4 */
    XBAR_EPWM_MUX07_CMPSS4_CTRIPL          = 0x0E00U,    /*!< X-BAR EPWM MUX07 CMPSS4 CTRIPL */
    XBAR_EPWM_MUX07_INPUTXBAR4             = 0x0E01U,    /*!< X-BAR EPWM MUX07 INPUTXBAR4 */
    XBAR_EPWM_MUX07_ADCCEVT4               = 0x0E03U,    /*!< X-BAR EPWM MUX07 ADCCEVT4 */
    XBAR_EPWM_MUX09_INPUTXBAR5             = 0x1201U,    /*!< X-BAR EPWM MUX09 INPUTXBAR5 */
    XBAR_EPWM_MUX11_INPUTXBAR6             = 0x1601U,    /*!< X-BAR EPWM MUX11 INPUTXBAR6 */
    XBAR_EPWM_MUX13_ADCSOCA                = 0x1A01U,    /*!< X-BAR EPWM MUX13 ADCSOCA */
    XBAR_EPWM_MUX14_EXTSYNCOUT             = 0x1C03U,    /*!< X-BAR EPWM MUX14 EXTSYNCOUT */
    XBAR_EPWM_MUX15_ADCSOCBO               = 0x1E01U,    /*!< X-BAR EPWM MUX15 ADCSOCBO */
    XBAR_EPWM_MUX17_INPUTXBAR7             = 0x2201U,    /*!< X-BAR EPWM MUX17 INPUTXBAR7 */
    XBAR_EPWM_MUX19_INPUTXBAR8             = 0x2601U,    /*!< X-BAR EPWM MUX19 INPUTXBAR8 */
    XBAR_EPWM_MUX19_ERRORSTS               = 0x2603U,    /*!< X-BAR EPWM MUX19 ERRORSTS */
    XBAR_EPWM_MUX21_INPUTXBAR9             = 0x2A01U,    /*!< X-BAR EPWM MUX21 INPUTXBAR9 */
    XBAR_EPWM_MUX23_INPUTXBAR10            = 0x2E01U,    /*!< X-BAR EPWM MUX23 INPUTXBAR10 */
    XBAR_EPWM_MUX25_INPUTXBAR11            = 0x3201U,    /*!< X-BAR EPWM MUX25 INPUTXBAR11 */
    XBAR_EPWM_MUX27_INPUTXBAR12            = 0x3601U,    /*!< X-BAR EPWM MUX27 INPUTXBAR12 */
    XBAR_EPWM_MUX29_INPUTXBAR13            = 0x3A01U,    /*!< X-BAR EPWM MUX29 INPUTXBAR13 */
    XBAR_EPWM_MUX31_INPUTXBAR14            = 0x3E01U,    /*!< X-BAR EPWM MUX31 INPUTXBAR14 */
    XBAR_EPWM_MUX31_ERRORSTS               = 0x3E02U     /*!< X-BAR EPWM MUX31 ERRORSTS */ 
} XBAR_EPWMMuxConfig;

/**
  * @}
  */

/** @defgroup Definition of X-BAR MUX(OUTPUT1MUXEN~OUTPUT8MUXEN / TRIP4MUXEN~TRIP12MUXEN Registers)
  * @{
  * @brief  Macro definitions about the bit fields in the XBARMUX register definition.
  * @note   The following values define the muxes parameter for XBAR_enableEPWMMux(),
  *          XBAR_enableOutputMux(), XBAR_disableEPWMMux(), and XBAR_disableOutputMux().
  */
#define XBAR_MUX00    (0x00000001UL)    /*!< Mask for X-BAR mux 0 */
#define XBAR_MUX01    (0x00000002UL)    /*!< Mask for X-BAR mux 1 */
#define XBAR_MUX02    (0x00000004UL)    /*!< Mask for X-BAR mux 2 */
#define XBAR_MUX03    (0x00000008UL)    /*!< Mask for X-BAR mux 3 */
#define XBAR_MUX04    (0x00000010UL)    /*!< Mask for X-BAR mux 4 */
#define XBAR_MUX05    (0x00000020UL)    /*!< Mask for X-BAR mux 5 */
#define XBAR_MUX06    (0x00000040UL)    /*!< Mask for X-BAR mux 6 */
#define XBAR_MUX07    (0x00000080UL)    /*!< Mask for X-BAR mux 7 */
#define XBAR_MUX08    (0x00000100UL)    /*!< Mask for X-BAR mux 8 */
#define XBAR_MUX09    (0x00000200UL)    /*!< Mask for X-BAR mux 9 */
#define XBAR_MUX10    (0x00000400UL)    /*!< Mask for X-BAR mux 10 */
#define XBAR_MUX11    (0x00000800UL)    /*!< Mask for X-BAR mux 11 */
#define XBAR_MUX12    (0x00001000UL)    /*!< Mask for X-BAR mux 12 */
#define XBAR_MUX13    (0x00002000UL)    /*!< Mask for X-BAR mux 13 */
#define XBAR_MUX14    (0x00004000UL)    /*!< Mask for X-BAR mux 14 */
#define XBAR_MUX15    (0x00008000UL)    /*!< Mask for X-BAR mux 15 */
#define XBAR_MUX16    (0x00010000UL)    /*!< Mask for X-BAR mux 16 */
#define XBAR_MUX17    (0x00020000UL)    /*!< Mask for X-BAR mux 17 */
#define XBAR_MUX18    (0x00040000UL)    /*!< Mask for X-BAR mux 18 */
#define XBAR_MUX19    (0x00080000UL)    /*!< Mask for X-BAR mux 19 */
#define XBAR_MUX20    (0x00100000UL)    /*!< Mask for X-BAR mux 20 */
#define XBAR_MUX21    (0x00200000UL)    /*!< Mask for X-BAR mux 21 */
#define XBAR_MUX22    (0x00400000UL)    /*!< Mask for X-BAR mux 22 */
#define XBAR_MUX23    (0x00800000UL)    /*!< Mask for X-BAR mux 23 */
#define XBAR_MUX24    (0x01000000UL)    /*!< Mask for X-BAR mux 24 */
#define XBAR_MUX25    (0x02000000UL)    /*!< Mask for X-BAR mux 25 */
#define XBAR_MUX26    (0x04000000UL)    /*!< Mask for X-BAR mux 26 */
#define XBAR_MUX27    (0x08000000UL)    /*!< Mask for X-BAR mux 27 */
#define XBAR_MUX28    (0x10000000UL)    /*!< Mask for X-BAR mux 28 */
#define XBAR_MUX29    (0x20000000UL)    /*!< Mask for X-BAR mux 29 */
#define XBAR_MUX30    (0x40000000UL)    /*!< Mask for X-BAR mux 30 */
#define XBAR_MUX31    (0x80000000UL)    /*!< Mask for X-BAR mux 31 */

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
 * \brief  Enables the Output X-BAR mux values to be passed to the output signal. 
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output    output is the X-BAR output being configured 
 *                    - This parameter can be any value of @ref XBAR_OUTPUTNUM
 * \param  muxes     muxes is a bit field of the muxes to be enabled. 
 *                    - uint32_t XBAR_MUX00~XBAR_MUX31,ENABLE MUX0~MUX31 as the OUTPUTMUX signel
 */
static inline void XBAR_enableOutputMux (XBAR_TypeDef *xbar, XBAR_OutputNum output, uint32_t muxes)
{
    /* Set the enable bit. */ 
    WRITE_REG(TYPE32((uint8_t *)(&xbar->OUTPUTXMUXEN) + output), muxes);
}

/**
 * \brief  Disables the Output X-BAR mux values to be passed to the output signal. 
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output    output is the X-BAR output being configured 
 *                    - This parameter can be any value of @ref XBAR_OUTPUTNUM
 * \param  muxes     muxes:muxes is a bit field of the muxes to be enabled. 
 *                    - uint32_t XBAR_MUX00~XBAR_MUX31,ENABLE MUX0~MUX31 as the OUTPUTMUX signel
 */
static inline void XBAR_disableOutputMux (XBAR_TypeDef *xbar, XBAR_OutputNum output, uint32_t muxes)
{
    /* Clear the enable bit. */
    CLEAR_BIT(TYPE32((uint8_t *)(&xbar->OUTPUTXMUXEN) + output), muxes);
}

/**
 * \brief  Set Output X-BAR latch mode enable or disable with OUTPUTLATCHENABLE register
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output    output is the X-BAR output being configured 
 *                    - This parameter can be any value of @ref XBAR_OUTPUTNUM
 * \param  enable    enable or disable status set 
 *                    - bool: 0: DISABLE
 *                            1: ENABLE
 */
static inline void XBAR_setOutputLatchMode (XBAR_TypeDef *xbar, XBAR_OutputNum output, bool enable)
{
    /* Set or clear the latch setting bit xbard on the enable parameter. */
    if (enable)
    {
        SET_BIT(TYPE32(xbar->OUTPUTLATCHENABLE.WORDVAL), ((0x1UL) << ((uint16_t)output / 4UL)));
    }
    else
    {
        CLEAR_BIT(TYPE32(xbar->OUTPUTLATCHENABLE.WORDVAL), ((0x1UL) << ((uint16_t)output / 4UL)));
    }
}

/**
 * \brief  Get Output X-BAR latch mode status with OUTPUTLATCH register
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output    output is the X-BAR output being configured 
 *                    - This parameter can be any value of @ref XBAR_OUTPUTNUM
 * \return Returns the xbar get current latch status whether it has been set up or not
 *                    - bool: 0: NOT SETUP
 *                            1: SET
 */
static inline bool XBAR_getOutputLatchStatus (XBAR_TypeDef *xbar, XBAR_OutputNum output)
{
    /* Get the status of the Output XBAR output latch. */ 
    return (READ_BIT((xbar->OUTPUTLATCH.WORDVAL), ((0x1UL) << ((uint16_t)output / 4UL))) != 0UL );
}

/**
 * \brief  Clear Output X-BAR latch flag with OUTPUTLATCHCLR register
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output    output is the X-BAR output being configured 
 *                    - This parameter can be any value of @ref XBAR_OUTPUTNUM
 */
static inline void XBAR_clearOutputLatch (XBAR_TypeDef *xbar, XBAR_OutputNum output)
{
    /* Set the bit that clears the corresponding OUTPUTLATCH bit. */ 
    SET_BIT(TYPE32(xbar->OUTPUTLATCHCLR.WORDVAL), ((0x1UL) << ((uint16_t)output / 4UL)));
}

/**
 * \brief  Force Output X-BAR latch feature with OUTPUTLATCHFRC register
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output    Output X-BAR port index 
 *                    - This parameter can be any value of @ref XBAR_OUTPUTNUM
 */
static inline void XBAR_forceOutputLatch (XBAR_TypeDef *xbar, XBAR_OutputNum output)
{
    /* Set the bit that forces the corresponding OUTPUTLATCH bit. */ 
    WRITE_REG(TYPE32(xbar->OUTPUTLATCHFRC.WORDVAL), ((uint32_t)(0x1UL) << ((uint16_t)output / 4UL)));
}

/**
 * \brief  Set Output X-BAR invert signal with OUTPUTINV register
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output    Output X-BAR port index 
 *                    - This parameter can be any value of @ref XBAR_OUTPUTNUM
 * \param  invert    invert signal required to be set or not set
 *                    - bool: 0:Positive polarity output
 *                            1:Reverse polarity output
 */
static inline void XBAR_invertOutputSignal (XBAR_TypeDef *xbar, XBAR_OutputNum output, bool invert)
{
    /* Set or clear the polarity setting bit xbard on the invert parameter. */ 
    if (invert)
    {
        SET_BIT(TYPE32(xbar->OUTPUTINV.WORDVAL), ((0x1UL) << ((uint32_t)output / 4UL)));
    }
    else
    {
        CLEAR_BIT(TYPE32(xbar->OUTPUTINV.WORDVAL), ((0x1UL) << ((uint32_t)output / 4UL)));
    }
}

/**
 * \brief  Enables the EPWM X-BAR mux values to be passed to an ePWM t Output X-BAR invert signal module. 
 * \param  xbar     X-BAR pointer to a XBAR_TypeDef structure
 *                   - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  trip     trip is the X-BAR output being configured 
 *                   - This parameter can be any value of @ref XBAR_TRIPNUM
 * \param  muxes    muxes is a bit field of the muxes to be enabled. 
 *                   - uint32_t XBAR_MUX00~XBAR_MUX31,ENABLE MUX0~MUX31 as the ePWMMUX input signel
 */
static inline void XBAR_enableEPWMMux (XBAR_TypeDef *xbar, XBAR_TripNum trip, uint32_t muxes)
{
    /* Set the enable bit. */ 
    SET_BIT(TYPE32((uint8_t *)(&xbar->TRIP4MUXEN.WORDVAL) + trip), muxes);
}

/**
 * \brief  Disables the EPWM X-BAR mux values to be passed to an ePWM module 
 * \param  xbar     X-BAR pointer to a XBAR_TypeDef structure
 *                   - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  trip     trip index number
 *                   - This parameter can be any value of @ref XBAR_TRIPNUM
 * \param  muxes    muxes is a bit field of the muxes to be enabled. 
 *                   - uint32_t XBAR_MUX00~XBAR_MUX31,ENABLE MUX0~MUX31 as the ePWMMUX input signel
 */
static inline void XBAR_disableEPWMMux (XBAR_TypeDef *xbar, XBAR_TripNum trip, uint32_t muxes)
{
    /* Clear the enable bit. */   
    CLEAR_BIT(TYPE32((uint8_t *)(&xbar->TRIP4MUXEN.WORDVAL) + trip), muxes);
}

/**
 * \brief   Set EPWM X-BAR invert signal with TRIPOUTINV register
 * \param  xbar      X-BAR pointer to a XBAR_TypeDef structure
 *                    - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  trip      trip index number
 *                    - This parameter can be any value of @ref XBAR_TRIPNUM
 * \param  invert    invert signal required to be set or not set
 *                    - bool 0:Positive polarity output
 *                           1:Reverse polarity output
 */
static inline void XBAR_invertEPWMSignal (XBAR_TypeDef *xbar, XBAR_TripNum trip, bool invert)
{
    /* Set or clear the polarity setting bit xbard on the invert parameter. */ 
    if (invert)
    {
        SET_BIT(TYPE32(xbar->TRIPOUTINV.WORDVAL), ((0x1UL) << ((uint16_t)trip / 4UL)));
    }
    else
    {
        CLEAR_BIT(TYPE32(xbar->TRIPOUTINV.WORDVAL), ((0x1UL) << ((uint16_t)trip / 4UL)));
    }
}

/**
 * \brief  Set input X-BAR pin in INPUT1SEL~INPUT16SEL register 
 * \param  xbar     X-BAR pointer to a XBAR_TypeDef structure
 *                   - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  input    X-BAR Input index 
 *                   - This parameter can be any value of @ref XBAR_INPUTNUM
 * \param  pin      GPIO pin number
 *                   - This parameter can be any value of @ref XBAR_INPUTGPIOPIN
 */
static inline void XBAR_setInputPin (XBAR_TypeDef *xbar, XBAR_InputNum input, XBAR_InputGPIOPin pin)
{
    /* Write the requested pin to the appropriate input select register. */ 
    WRITE_REG(TYPE32((uint8_t *)(&xbar->INPUTXSEL) + (uint32_t)input*4UL), pin);
}

/**
 * \brief  Lock the input X-BAR status with the INPUTSELECTLOCK register 
 * \param  xbar     X-BAR pointer to a XBAR_TypeDef structure
 *                   - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  input    X-BAR Input index 
 *                   - This parameter can be any value of @ref XBAR_INPUTNUM
 */ 
static inline void XBAR_lockInput (XBAR_TypeDef *xbar, XBAR_InputNum input)
{
    /* lock the input in the INPUTSELLOCK register. */ 
    WRITE_REG(TYPE32(xbar->INPUTSELLOCK.WORDVAL), (uint32_t)(1UL << (uint32_t)input));
}

/**
 * \brief  Lock the Output X-BAR with the OUTPUTLOCK register 
 * \param  xbar    X-BAR pointer to a XBAR_TypeDef structure
 *                  - XBAR_TypeDef *xbar: X-BAR base address index
 */
static inline void XBAR_lockOutput (XBAR_TypeDef *xbar)
{
    /* Write key 0x5A5A to the KEY bits and 1 to LOCK bit. */
    WRITE_REG(TYPE32(xbar->OUTPUTLOCK.WORDVAL), (((uint32_t)0x5A5AUL << XBAR_OUTPUTLOCK_KEY_S) | \
             (uint32_t)XBAR_OUTPUTLOCK_LOCK));
}

/**
 * \brief  Lock the EPWM X-BAR with the TRIPLOCK register 
 * \param  xbar    X-BAR pointer to a XBAR_TypeDef structure
 *                  - XBAR_TypeDef *xbar: X-BAR base address index
 */
static inline void XBAR_lockEPWM (XBAR_TypeDef *xbar)
{
    /* Write key 0x5A5A to the KEY bits and 1 to LOCK bit. */ 
    WRITE_REG(TYPE32(xbar->TRIPLOCK.WORDVAL), (((uint32_t)0x5A5AUL << XBAR_TRIPLOCK_KEY_S) | \
             (uint32_t)XBAR_TRIPLOCK_LOCK));
}

/**
 * \brief  Configure the outputxbar MUX register with OUTPUT1MUX1~OUTPUT8MUX2
 * \param  xbar         X-BAR pointer to a XBAR_TypeDef structure
 *                       - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  output       output: the index of Output X-BAR port 
 *                       - This parameter can be any value of @ref XBAR_OUTPUTNUM
 * \param  muxConfig    muxConfig: output mux selection 
 *                       - This parameter can be any value of @ref XBAR_OUTPUTMUXCONFIG
 */
extern void XBAR_setOutputMuxConfig (XBAR_TypeDef *xbar, XBAR_OutputNum output, XBAR_OutputMuxConfig muxConfig);

/**
 * \brief  Configure the epwmxbar MUX register with TRIP4MUX1~TRIP12MUX2
 * \param  xbar         X-BAR pointer to a XBAR_TypeDef structure
 *                       - XBAR_TypeDef *xbar: X-BAR base address index
 * \param  trip         trip: the trip index of the EPWM X-BAR 
 *                       - This parameter can be any value of @ref XBAR_TRIPNUM
 * \param  muxConfig    muxConfig: ePWM mux selection 
 *                       - This parameter can be any value of @ref XBAR_EPWMMUXCONFIG
 */
extern void XBAR_setEPWMMuxConfig (XBAR_TypeDef *xbar, XBAR_TripNum trip, XBAR_EPWMMuxConfig muxConfig);


#ifdef __cplusplus
}
#endif


#endif /* __XBAR_H__ */
