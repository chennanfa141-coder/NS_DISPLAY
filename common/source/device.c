/**
  * @file       device.c
  * @author     Alex-J
  * @brief      Device setup for NS800RTxxx examples.
  *
  * v1.0.1|Haven-X|2025/10/14|Fix the errors in the internal calls of the Device_disableAllPeripherals function.
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "device.h"


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
 * @brief  Function to initialize the device.
 * @note   Mainly initialize the system clock and enable all peripheral clocks.
 */
void Device_init(void)
{
    System_setClock();
    Device_enableAllPeripherals();
}

/**
 * @brief  Set up clock source selection, PLL control, and clock dividers.
 */
void System_setClock (void)
{ 
#ifdef SYSCLK_USE_PLL
#ifdef SYSCLK_SOURCE_USE_HXTL
    RCC_configHxtl(HXTL_CONFIG, RCC_HXTL_NORMAL, RCC_FUN_ON);
#endif
    RCC_configPll(PLL_CONFIG, PLL_EXT_CONFIG, RCC_FUN_ON);
    
    RCC_setClock(RCC_SYSCLKSOURCE_PLL);
#else  // !SYSCLK_USE_PLL
#ifdef SYSCLK_SOURCE_USE_HXTL
    RCC_configHxtl(HXTL_CONFIG, RCC_HXTL_NORMAL, RCC_FUN_ON);
    RCC_setClock(RCC_SYSCLKSOURCE_HXTL);
#endif // SYSCLK_SOURCE_USE_HXTL

#ifdef SYSCLK_SOURCE_USE_MIRC1
    RCC_setClock(RCC_SYSCLKSOURCE_MIRC1);
#endif // SYSCLK_SOURCE_USE_MIRC1

#ifdef SYSCLK_SOURCE_USE_MIRC2
    RCC_setClock(RCC_SYSCLKSOURCE_MIRC2);
#endif // SYSCLK_SOURCE_USE_MIRC2
#endif // SYSCLK_USE_PLL
    RCC_configClockDiv(SYSCLOCK_CFGR_DIV_CONFIG, SYSCLOCK_CFGR2_DIV_CONFIG);

    /* update the system core clock value */
    SystemCoreClockUpdate();
    /* initialize systick(base time) */
    SysTick_Config(SystemCoreClock / SYSTICK_TIME_UNIT);
    /* systick interrupt control */
    Systick_setInterrupt(DISABLE);
}

/**
 * @brief  Enable clocks for all peripherals.
 */
void Device_enableAllPeripherals (void)
{
    RCC_unlockRccRegister();

    RCC_enableAhb1PeripheralClock(RCC_AHB_GPIOHEN_M | RCC_AHB_GPIOCEN_M | RCC_AHB_GPIOBEN_M | RCC_AHB_GPIOAEN_M |
                                  RCC_AHB_MMATHEN_M | RCC_AHB_EDMA1EN_M | RCC_AHB_DMAMUX1EN_M);

    RCC_enableAhb2PeripheralClock(RCC_AHB_CAN1EN_M | RCC_AHB_LIN1EN_M | RCC_AHB_BGCRC1EN_M);

    RCC_enableApb1PeripheralClock(RCC_APB_EQEP2EN_M | RCC_APB_EQEP1EN_M | RCC_APB_ECAP3EN_M | RCC_APB_ECAP2EN_M |
                                  RCC_APB_ECAP1EN_M | RCC_APB_EPWM7EN_M | RCC_APB_EPWM6EN_M | RCC_APB_EPWM5EN_M |
                                  RCC_APB_EPWM4EN_M | RCC_APB_EPWM3EN_M | RCC_APB_EPWM2EN_M | RCC_APB_EPWM1EN_M);

    RCC_enableApb2PeripheralClock(RCC_APB_CMPSS4EN_M | RCC_APB_CMPSS3EN_M | RCC_APB_CMPSS2EN_M | RCC_APB_CMPSS1EN_M |
                                  RCC_APB_XBAREN_M | RCC_APB_ADCCEN_M | RCC_APB_ADCAEN_M);

    RCC_enableApb3PeripheralClock(RCC_APB_ANALOGSSEN_M);

    RCC_enableApb5PeripheralClock(RCC_APB_DCC1EN_M | RCC_APB_WWDGEN_M | RCC_APB_EPGEN_M |
                                  RCC_APB_I2C1EN_M | RCC_APB_SPI2EN_M | RCC_APB_SPI1EN_M | RCC_APB_UART1EN_M);

    RCC_enableApb6PeripheralClock(RCC_APB_STIM3EN_M | RCC_APB_STIM2EN_M | RCC_APB_STIM1EN_M );

    RCC_enableApb8PeripheralClock(RCC_APB_AWKEN_M | RCC_APB_LPTIMEN_M | RCC_APB_IWDG1EN_M | RCC_APB_PWREN_M);

    RCC_lockRccRegister();
}

/**
 * @brief  Unlock all peripheral registers.
 */
void Device_unlockPeriphReg (void)
{
    /* Enable register writing function about ECAP/EPWM/CMPSS/XBAR/ANASS/ADC/GPIO */
    SYSCON->SYSEALLOW1.WORDVAL = 0x0700007F;
    SYSCON->SYSEALLOW2.WORDVAL = 0x000F9005;
    SYSCON->SYSEALLOW3.WORDVAL = 0x00000087;
}

/**
 * @brief  Disable clocks for all peripherals.
 */
void Device_disableAllPeripherals (void)
{
    RCC_unlockRccRegister();

    RCC_disableAhb1PeripheralClock(RCC_AHB_GPIOHEN_M | RCC_AHB_GPIOCEN_M | RCC_AHB_GPIOBEN_M | RCC_AHB_GPIOAEN_M |
                                   RCC_AHB_MMATHEN_M | RCC_AHB_EDMA1EN_M | RCC_AHB_DMAMUX1EN_M);

    RCC_disableAhb2PeripheralClock(RCC_AHB_CAN1EN_M | RCC_AHB_LIN1EN_M | RCC_AHB_BGCRC1EN_M);

    RCC_disableApb1PeripheralClock(RCC_APB_EQEP2EN_M | RCC_APB_EQEP1EN_M | RCC_APB_ECAP3EN_M | RCC_APB_ECAP2EN_M |
                                   RCC_APB_ECAP1EN_M | RCC_APB_EPWM7EN_M | RCC_APB_EPWM6EN_M | RCC_APB_EPWM5EN_M |
                                   RCC_APB_EPWM4EN_M | RCC_APB_EPWM3EN_M | RCC_APB_EPWM2EN_M | RCC_APB_EPWM1EN_M);

    RCC_disableApb2PeripheralClock(RCC_APB_CMPSS4EN_M | RCC_APB_CMPSS3EN_M | RCC_APB_CMPSS2EN_M | RCC_APB_CMPSS1EN_M |
                                   RCC_APB_XBAREN_M | RCC_APB_ADCCEN_M | RCC_APB_ADCAEN_M);

    RCC_disableApb3PeripheralClock(RCC_APB_ANALOGSSEN_M);

    RCC_disableApb5PeripheralClock(RCC_APB_DCC1EN_M | RCC_APB_WWDGEN_M | RCC_APB_EPGEN_M |
                                   RCC_APB_I2C1EN_M | RCC_APB_SPI2EN_M | RCC_APB_SPI1EN_M | RCC_APB_UART1EN_M);

    RCC_disableApb6PeripheralClock(RCC_APB_STIM3EN_M | RCC_APB_STIM2EN_M | RCC_APB_STIM1EN_M);

    RCC_disableApb8PeripheralClock(RCC_APB_AWKEN_M | RCC_APB_LPTIMEN_M | RCC_APB_IWDG1EN_M | RCC_APB_PWREN_M);

    RCC_lockRccRegister();
}

/**
 * @brief  Lock all peripheral registers.
 */
void Device_lockPeriphReg (void)
{
    /* Disable register writing function about ECAP/EPWM/CMPSS/XBAR/ANASS/ADC/GPIO */
    SYSCON->SYSEALLOW1.WORDVAL = 0x00000000;
    SYSCON->SYSEALLOW2.WORDVAL = 0x00000000;
    SYSCON->SYSEALLOW3.WORDVAL = 0x00000000;
}



void InitCpuTimers(void)
{
    // 1. 停止定时器，关闭中断，选择 HCLK/8 时钟源 
    // 对应 TI 的 CpuTimer0Regs.TCR.bit.TSS = 1; 
    // CTRL 寄存器写 0：Bit0(ENABLE)=0, Bit1(TICKINT)=0, Bit2(CLKSOURCE)=0
    SysTick->CTRL = 0x00000000; 

    // 2. 将定时器周期初始化为 24位 最大值
    // 对应 TI 的 CpuTimer0Regs.PRD.all = 0xFFFFFFFF;
    SysTick->LOAD = 0x00FFFFFF;

    // 3. 清空当前计数值，触发重新加载
    // 对应 TI 的 CpuTimer0Regs.TCR.bit.TRB = 1;
    SysTick->VAL = 0x00000000;
}
