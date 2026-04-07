/****************************************************************************
 * @file     startup_NS800RT1xxx.S
 * @author   MCD Application Team
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device NOVOSENSE
 ******************************************************************************/
/*
 * Copyright (c) 2025 Novosense Limited.
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

                .syntax  unified
                .arch    armv7e-m

                .section .vectors
                .align   2
                .globl   __Vectors
                .globl   __Vectors_End
                .globl   __Vectors_Size
__Vectors:
                /* Internal Interrupts */
                .long    __StackTop                         /*     Initial Stack Pointer */
                .long    Reset_Handler                      /* -15 Reset Handler */
                .long    NMI_Handler                        /* -14 NMI Handler */
                .long    HardFault_Handler                  /* -13 Hard Fault Handler */
                .long    MemManage_Handler                  /* -12 MPU Fault Handler */
                .long    BusFault_Handler                   /* -11 Bus Fault Handler */
                .long    UsageFault_Handler                 /* -10 Usage Fault Handler */
                .long    0                                  /* -9  Reserved */
                .long    0                                  /* -8  Reserved */
                .long    0                                  /* -7  Reserved */
                .long    0                                  /* -6  Reserved */
                .long    SVC_Handler                        /* -5  SVCall Handler */
                .long    DebugMon_Handler                   /* -4  Debug Monitor Handler */
                .long    0                                  /* -3  Reserved */
                .long    PendSV_Handler                     /* -2  PendSV Handler */
                .long    SysTick_Handler                    /* -1  SysTick Handler */


                /* External Interrupts */
                .long    WWDG_IRQHandler                    /* 0  WWDG_IRQn */
                .long    IWDG1_IRQHandler                   /* 1  IWDG1_IRQn */
                .long    0                                  /* 2  Reserved */
                .long    FLASH_IRQHandler                   /* 3  FLASH_IRQn */
                .long    FLASH_ECCERR_IRQHandler            /* 4  FLASH_ECCERR_IRQn */
                .long    RAM_ECCERR_IRQHandler              /* 5  RAM_ECCERR_IRQn */
                .long    RCC_IRQHandler                     /* 6  RCC_IRQn */
                .long    EXTI_GPIO_IRQHandler               /* 7  EXTI_GPIO_IRQn */
                .long    EXTI_CMP_IRQHandler                /* 8  EXTI_CMP_IRQn */
                .long    EXTI_XINT_IRQHandler               /* 9  EXTI_XINT_IRQn */
                .long    EDMA1_CH0_CH1_CH2_CH3_IRQHandler   /* 10  EDMA1_CH0_CH1_CH2_CH3_IRQn */
                .long    EDMA1_CH4_CH5_CH6_CH7_IRQHandler   /* 11 EDMA1_CH4_CH5_CH6_CH7_IRQn */
                .long    EDMA1_ERR_IRQHandler               /* 12 EDMA1_ERR_IRQn */
                .long    ADCA_CONV_IRQHandler               /* 13 ADCA_CONV_IRQn */
                .long    ADCA_EVENT_IRQHandler              /* 14 ADCA_EVENT_IRQn */
                .long    ADCC_CONV_IRQHandler               /* 15 ADCC_CONV_IRQn */
                .long    ADCC_EVENT_IRQHandler              /* 16 ADCC_EVENT_IRQn */
                .long    EPWM1_TZINT_IRQHandler             /* 17 EPWM1_TZINT_IRQn */
                .long    EPWM2_TZINT_IRQHandler             /* 18 EPWM2_TZINT_IRQn */
                .long    EPWM3_TZINT_IRQHandler             /* 19 EPWM3_TZINT_IRQn */
                .long    EPWM4_TZINT_IRQHandler             /* 20 EPWM4_TZINT_IRQn */
                .long    EPWM5_TZINT_IRQHandler             /* 21 EPWM5_TZINT_IRQn */
                .long    EPWM6_TZINT_IRQHandler             /* 22 EPWM6_TZINT_IRQn */
                .long    EPWM7_TZINT_IRQHandler             /* 23 EPWM7_TZINT_IRQn */
                .long    EPWM1_INT_IRQHandler               /* 24 EPWM1_INT_IRQn */
                .long    EPWM2_INT_IRQHandler               /* 25 EPWM2_INT_IRQn */
                .long    EPWM3_INT_IRQHandler               /* 26 EPWM3_INT_IRQn */
                .long    EPWM4_INT_IRQHandler               /* 27 EPWM4_INT_IRQn */
                .long    EPWM5_INT_IRQHandler               /* 28 EPWM5_INT_IRQn */
                .long    EPWM6_INT_IRQHandler               /* 29 EPWM6_INT_IRQn */
                .long    EPWM7_INT_IRQHandler               /* 30 EPWM7_INT_IRQn */
                .long    ECAP_IRQHandler                    /* 31 ECAP1/2/3_IRQn */
                .long    EQEP_IRQHandler                    /* 32 EQEP1/2_IRQn */
                .long    EPG_IRQHandler                     /* 33 EPG_IRQn */
                .long    LPTIM_IRQHandler                   /* 34 LPTIM_IRQn */
                .long    CAN1_IRQHandler                    /* 35 CAN1_IRQn */
                .long    CAN1_ECC_IRQHandler                /* 36 CAN1_ECC_IRQ */
                .long    0                                  /* 37 Reserved */
                .long    0                                  /* 38 Reserved */
                .long    STIM1_IRQHandler                   /* 39 STIM1_IRQn */
                .long    STIM2_IRQHandler                   /* 40 STIM2_IRQn */
                .long    STIM3_IRQHandler                   /* 41 STIM3_IRQn */
                .long    AWK_IRQHandler                     /* 42 AWK_IRQn */
                .long    LIN1_IRQHandler                    /* 43 LIN1_IRQn */
                .long    I2C1_IRQHandler                    /* 44 I2C1_IRQn */
                .long    0                                  /* 45 Reserved */
                .long    0                                  /* 46 Reserved */
                .long    SPI1_RX_IRQHandler                 /* 47 SPI1_RX_IRQn */
                .long    SPI1_TX_IRQHandler                 /* 48 SPI1_TX_IRQn */
                .long    SPI2_RX_IRQHandler                 /* 49 SPI2_RX_IRQn */
                .long    SPI2_TX_IRQHandler                 /* 50 SPI2_TX_IRQn */
                .long    UART1_TX_IRQHandler                /* 51 UART1_TX_IRQn */
                .long    UART1_RX_IRQHandler                /* 52 UART1_RX_IRQn */
                .long    0                                  /* 53 Reserved */
                .long    0                                  /* 54 Reserved */
                .long    0                                  /* 55 Reserved */
                .long    0                                  /* 56 Reserved */
                .long    MMATH_MCM_IRQHandler               /* 57 MMATH_MCM_IRQn */
                .long    DCC1_IRQHandler                    /* 58 DCC_IRQn */
                .long    0                                  /* 59 Reserved */


__Vectors_End:
                .equ     __Vectors_Size, __Vectors_End - __Vectors
                .size    __Vectors, . - __Vectors

                .thumb
                .section .text
                .align   2

                .thumb_func
                .type    Reset_Handler, %function
                .globl   Reset_Handler
                .fnstart
                .equ     VTOR, 0xE000ED08
Reset_Handler:
                cpsid    i                                  /* Mask interrupts */
                ldr      r0, =VTOR
                ldr      r1, =__Vectors
                str      r1, [r0]                           /* Set VTOR */
                ldr      r2, [r1]
                msr      msp, r2                            /* Set MSP */
                ldr      r0, =SystemInit
                blx      r0
                cpsie    i                                  /* Unmask interrupts */

                ldr      r4, =__copy_table_start__
                ldr      r5, =__copy_table_end__

.copy_start:
                cmp      r4, r5
                bge      .copy_done
                ldr      r1, [r4]                           /* Source address */
                ldr      r2, [r4, #4]                       /* Destination address */
                ldr      r3, [r4, #8]                       /* Word count */
                lsls     r3, r3, #2                         /* Byte count */

.copy_one_data:
                subs     r3, #4                             /* Decrement byte count */
                ittt     ge
                ldrge    r0, [r1, r3]
                strge    r0, [r2, r3]
                bge      .copy_one_data

                adds     r4, #12
                b        .copy_start
.copy_done:

                ldr      r3, =__zero_table_start__
                ldr      r4, =__zero_table_end__

.zero_start:
                cmp      r3, r4
                bge      .zero_done
                ldr      r1, [r3]                           /* Destination address */
                ldr      r2, [r3, #4]                       /* Word count */
                lsls     r2, r2, #2                         /* Byte count */
                movs     r0, 0

.zero_one_data:
                subs     r2, #4                             /* Decrement byte count */
                itt      ge
                strge    r0, [r1, r2]
                bge      .zero_one_data

                adds     r3, #8
                b        .zero_start
.zero_done:

                bl       main

                .fnend
                .size    Reset_Handler, . - Reset_Handler

/*
 * The default macro is not used for HardFault_Handler.
 * Because this results in a poor debug illusion.
 */
                .thumb_func
                .type    HardFault_Handler, %function
                .weak    HardFault_Handler
                .fnstart
HardFault_Handler:
                b        .
                .fnend
                .size    HardFault_Handler, . - HardFault_Handler

/* The default handler */
                .thumb_func
                .type    Default_Handler, %function
                .weak    Default_Handler
                .fnstart
Default_Handler:
                b        .
                .fnend
                .size    Default_Handler, . - Default_Handler

/*
 * Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols with an endless loop,
 * which will be overwritten by SDK handlers.
 * Users can read the SDK handlers,
 * and learn how to write their own exception/interrupt handlers.
 */
                .macro   Set_Default_Handler  Handler_Name
                .weak    \Handler_Name
                .set     \Handler_Name, Default_Handler
                .endm

/* Default exception/interrupt  handler */
                Set_Default_Handler  NMI_Handler
                Set_Default_Handler  MemManage_Handler
                Set_Default_Handler  BusFault_Handler
                Set_Default_Handler  UsageFault_Handler
                Set_Default_Handler  SVC_Handler
                Set_Default_Handler  DebugMon_Handler
                Set_Default_Handler  PendSV_Handler
                Set_Default_Handler  SysTick_Handler

                Set_Default_Handler  WWDG_IRQHandler
                Set_Default_Handler  IWDG1_IRQHandler
                Set_Default_Handler  FLASH_IRQHandler
                Set_Default_Handler  FLASH_ECCERR_IRQHandler
                Set_Default_Handler  RAM_ECCERR_IRQHandler
                Set_Default_Handler  RCC_IRQHandler
                Set_Default_Handler  EXTI_GPIO_IRQHandler 
                Set_Default_Handler  EXTI_CMP_IRQHandler
                Set_Default_Handler  EXTI_XINT_IRQHandler
                Set_Default_Handler  EDMA1_CH0_CH1_CH2_CH3_IRQHandler
                Set_Default_Handler  EDMA1_CH4_CH5_CH6_CH7_IRQHandler
                Set_Default_Handler  EDMA1_ERR_IRQHandler
                Set_Default_Handler  ADCA_CONV_IRQHandler
                Set_Default_Handler  ADCA_EVENT_IRQHandler
                Set_Default_Handler  ADCC_CONV_IRQHandler
                Set_Default_Handler  ADCC_EVENT_IRQHandler
                Set_Default_Handler  EPWM1_TZINT_IRQHandler
                Set_Default_Handler  EPWM2_TZINT_IRQHandler
                Set_Default_Handler  EPWM3_TZINT_IRQHandler
                Set_Default_Handler  EPWM4_TZINT_IRQHandler
                Set_Default_Handler  EPWM5_TZINT_IRQHandler
                Set_Default_Handler  EPWM6_TZINT_IRQHandler
                Set_Default_Handler  EPWM7_TZINT_IRQHandler 
                Set_Default_Handler  EPWM1_INT_IRQHandler
                Set_Default_Handler  EPWM2_INT_IRQHandler
                Set_Default_Handler  EPWM3_INT_IRQHandler
                Set_Default_Handler  EPWM4_INT_IRQHandler
                Set_Default_Handler  EPWM5_INT_IRQHandler
                Set_Default_Handler  EPWM6_INT_IRQHandler
                Set_Default_Handler  EPWM7_INT_IRQHandler
                Set_Default_Handler  ECAP_IRQHandler
                Set_Default_Handler  EQEP_IRQHandler
                Set_Default_Handler  EPG_IRQHandler
                Set_Default_Handler  LPTIM_IRQHandler
                Set_Default_Handler  CAN1_IRQHandler
                Set_Default_Handler  CAN1_ECC_IRQHandler
                Set_Default_Handler  STIM1_IRQHandler
                Set_Default_Handler  STIM2_IRQHandler
                Set_Default_Handler  STIM3_IRQHandler
                Set_Default_Handler  AWK_IRQHandler
                Set_Default_Handler  LIN1_IRQHandler
                Set_Default_Handler  I2C1_IRQHandler
                Set_Default_Handler  SPI1_RX_IRQHandler
                Set_Default_Handler  SPI1_TX_IRQHandler
                Set_Default_Handler  SPI2_RX_IRQHandler
                Set_Default_Handler  SPI2_TX_IRQHandler
                Set_Default_Handler  UART1_TX_IRQHandler
                Set_Default_Handler  UART1_RX_IRQHandler
                Set_Default_Handler  MMATH_MCM_IRQHandler
                Set_Default_Handler  DCC1_IRQHandler

                .end
