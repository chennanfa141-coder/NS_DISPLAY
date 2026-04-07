/**
  * @file       device.h
  * @author     Alex-J
  * @brief      Header file of device.c
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */

#ifndef __DEVICE_H__
#define __DEVICE_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup HXTL_CONFIG High-Speed Crystal Oscillator (HXTL) Configuration
  * @{
  * @brief  Defines configuration macros for the High-Speed Crystal Oscillator (HXTL).
  */
#ifdef SYSCLK_SOURCE_USE_HXTL
#define HXTL_CONFIG    ((RCC_HXTL_FILT_ENABLE << 15) | \
                        (RCC_HXTL_RF_0_8M << 13) | \
                        (RCC_HXTL_RF_ENABLE << 12) | \
                        (RCC_HXTL_STS_16384 << 8) | \
                        RCC_HXTL_16M_AGC_DISABLE)

#else
#define HXTL_CONFIG    0U
#endif

/**
  * @}
  */

/** @defgroup PLL_CONFIG PLL Configuration
  * @{
  * @brief  Defines configuration macros for the Phase-Locked Loop (PLL).
  * @note   Will configure the clock as follows:
  *          PLL_SYSCLK = PLLSOURCE  * PLLM / ( (PLLN+1) * (2 * (PLLP+1))) 
  * 
  *          PLLSOURCE optional: \b HXTL_FREQ_VALUE
  *                              \b MIRC1_FREQ_VALUE
  *                              \b MIRC2_FREQ_VALUE
  *          Example: 
  *           if PLLSOURCE = HXTL_FREQ_VALUE = 20Mhz, PLLM_20, PLLN_DIV1, PLLP_DIV2,
  *         
  *             PLL_SYSCLK = 20Mhz * 20 / ( (0+1) * (2 * (0+1)) ) = 200MHz
  */
#ifdef SYSCLK_USE_PLL
#ifdef PLLCLK_SOURCE_USE_HTXL

#define PLL_CONFIG    ((RCC_PLLM_20 << 8) | \
											  (RCC_PLLN_DIV1 << 4) | \
											  (RCC_PLLP_DIV2 << 17) | \
											  (RCC_PLLSOURCE_HXTL))

#else  // ndef PLLCLK_SOURCE_USE_HTXL
#ifdef PLLCLK_SOURCE_USE_MIRC2
#define PLL_CONFIG    ((RCC_PLLM_40 << 8) | \
                       (RCC_PLLN_DIV1 << 4) | \
                       (RCC_PLLP_DIV2 << 17) | \
                       (RCC_PLLSOURCE_MIRC2))
#else  // ndef PLLCLK_SOURCE_USE_MIRC2
#define PLL_CONFIG    ((RCC_PLLM_40 << 8) | \
                       (RCC_PLLN_DIV1 << 4) | \
                       (RCC_PLLP_DIV2 << 17) | \
                       (RCC_PLLSOURCE_MIRC1))
#endif  // PLLCLK_SOURCE_USE_MIRC2
#endif  // PLLCLK_SOURCE_USE_HTXL
#else  // ndef SYSCLK_USE_PLL
#define PLL_CONFIG    0U
#endif  // SYSCLK_USE_PLL

/**
  * @}
  */
#define StartCpuTimer1()   (SysTick->CTRL |= 0x01)



/** @defgroup PLL_EXT_CONFIG PLL Extended Configuration
  * @{
  * @brief  Defines configuration macros for the Phase-Locked Loop (PLL) extended settings.
  */
#ifdef SYSCLK_USE_PLL
#define PLL_EXT_CONFIG    ((RCC_PLLQ_DIV8 << 27) | \
                           (RCC_PLLR_DIV8 << 22) | \
                           (RCC_PLL_FORCELK_DISABLE << 18) | \
                           (RCC_PLL_LKDT_SEL_0 << 16) | \
                           (RCC_LOOP_FILTER_CAP_84PF << 8) | \
                           (RCC_ICP_2UA << 4) | \
                           (RCC_LOOP_FILTER_RES_10K << 2) | \
                           (RCC_VCO_200_400M))
#else
#define PLL_EXT_CONFIG   0U
#endif

/**
  * @}
  */

 /** @defgroup SYS_CLOCK_DIV_CONFIG Systerm Clock Division Configuration
  * @{
  * @brief  Defines macros for configuring system clock division settings.
  */
#ifdef SYSCLK_USE_PLL

#define SYSCLOCK_CFGR_DIV_CONFIG    ((RCC_APB5_HCLK_DIV4 << 28) | \
                                     (RCC_APB2_4_HCLK_DIV2 << 24) | \
                                     (RCC_APB1_3_HCLK_DIV1 << 20) | \
                                     (RCC_SYSCLK_DIV1 << 8))  
#define SYSCLOCK_CFGR2_DIV_CONFIG    ((RCC_FLASH_DIV_2 << 0) | \
                                      (RCC_TRACE_DIV_2 << 4) | \
                                      (RCC_EPWM_DIV_1 << 12))   

#else 
#define SYSCLOCK_CFGR_DIV_CONFIG    ((RCC_APB5_HCLK_DIV1 << 28) | \
                                     (RCC_APB2_4_HCLK_DIV1 << 24) | \
                                     (RCC_APB1_3_HCLK_DIV1 << 20) | \
                                     (RCC_SYSCLK_DIV1 << 8))
#define SYSCLOCK_CFGR2_DIV_CONFIG    ((RCC_FLASH_DIV_1 << 0) | \
                                      (RCC_TRACE_DIV_1 << 4) | \
                                      (RCC_EPWM_DIV_1 << 12))
#endif


/**
  * @}
  */
  
#define SYSTICK_TIME_UNIT    (1000000UL)    /*!< Uint: 1M */  


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * \brief  Function to initialize the device.
 * \note   Mainly initialize the system clock and enable all peripheral clocks.
 */
extern void Device_init(void);

/**
 * \brief  Set up clock source selection, PLL control, and clock dividers.
 */
extern void System_setClock(void);

/**
 * \brief  Enable clocks for all peripherals.
 */
extern void Device_enableAllPeripherals(void);

/**
 * \brief  Unlock all peripheral registers.
 */
extern void Device_unlockPeriphReg (void);

/**
 * \brief  Disable clocks for all peripherals.
 */
extern void Device_disableAllPeripherals (void);

/**
 *\@brief  Lock all peripheral registers.
 */
extern void Device_lockPeriphReg (void);

/**
 *\@brief  All peripherals are hung on the CUP1
 */
extern void Device_enableAllPeripheralsInCpu1 (void);


extern void InitSysCtrl(void);   

extern void InitCpuTimers(void);

extern void InitPeripherals(void);
#ifdef __cplusplus
}
#endif


#endif /* __DEVICE_H__ */
