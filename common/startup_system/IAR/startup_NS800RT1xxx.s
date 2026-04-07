;********************************************************************************
;* @File Name          : startup_NS800RT1xxx.s
;* @author             : MCD Application Team
;* @Description        : NS800RT1xxx devices vector table for IAR toolchain. 
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the Cortex-M processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>
;******************************************************************************
;* @attention
;*
;* Copyright (c) 2025 Novosense Limited.
;* All rights reserved.
;*
;* This software is licensed under terms that can be found in the LICENSE file
;* in the root directory of this software component.
;* If no LICENSE file comes with this software, it is provided AS-IS.
;*
;*******************************************************************************

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table


        DATA
__vector_table
                DCD     sfe(CSTACK)                    ;< Top of Stack
                DCD     Reset_Handler                  ;< -15 Reset Handler
                DCD     NMI_Handler                    ;< -14 NMI Handler
                DCD     HardFault_Handler              ;< -13 Hard Fault Handler
                DCD     MemManage_Handler              ;< -12 MPU Fault Handler
                DCD     BusFault_Handler               ;< -11 Bus Fault Handler
                DCD     UsageFault_Handler             ;< -10 Usage Fault Handler
                DCD     0                              ;< -9 Reserved
                DCD     0                              ;< -8 Reserved
                DCD     0                              ;< -7 Reserved
                DCD     0                              ;< -6 Reserved
                DCD     SVC_Handler                    ;< -5 SVCall Handler
                DCD     DebugMon_Handler               ;< -4 Debug Monitor Handler
                DCD     0                              ;< -3 Reserved
                DCD     PendSV_Handler                 ;< -2 PendSV Handler
                DCD     SysTick_Handler                ;< -1 SysTick Handler


                ; External Interrupts
                DCD    WWDG_IRQHandler                 ;< 0  WWDG_IRQn
                DCD    IWDG1_IRQHandler                ;< 1  IWDG1_IRQn
                DCD    0                               ;< 2  Reserved
                DCD    FLASH_IRQHandler                ;< 3  FLASH_IRQn
                DCD    FLASH_ECCERR_IRQHandler         ;< 4  FLASH_ECCERR_IRQn
                DCD    RAM_ECCERR_IRQHandler           ;< 5  RAM_ECCERR_IRQn
                DCD    RCC_IRQHandler                  ;< 6  RCC_IRQn
                DCD    EXTI_GPIO_IRQHandler            ;< 7  EXTI_GPIO_IRQn
                DCD    EXTI_CMP_IRQHandler             ;< 8  EXTI_CMP_IRQn
                DCD    EXTI_XINT_IRQHandler            ;< 9  EXTI_XINT_IRQn
                DCD    EDMA1_CH0_CH1_CH2_CH3_IRQHandler;< 10  EDMA1_CH0_CH1_CH2_CH3_IRQ
                DCD    EDMA1_CH4_CH5_CH6_CH7_IRQHandler;< 11 EDMA1_CH4_CH5_CH6_CH7_IRQ
                DCD    EDMA1_ERR_IRQHandler            ;< 12 EDMA1_ERR_IRQn
                DCD    ADCA_CONV_IRQHandler            ;< 13 ADCA_CONV_IRQn
                DCD    ADCA_EVENT_IRQHandler           ;< 14 ADCA_EVENT_IRQn
                DCD    ADCC_CONV_IRQHandler            ;< 15 ADCC_CONV_IRQn
                DCD    ADCC_EVENT_IRQHandler           ;< 16 ADCC_EVENT_IRQn
                DCD    EPWM1_TZINT_IRQHandler          ;< 17 EPWM1_TZINT_IRQn
                DCD    EPWM2_TZINT_IRQHandler          ;< 18 EPWM2_TZINT_IRQn
                DCD    EPWM3_TZINT_IRQHandler          ;< 19 EPWM3_TZINT_IRQn
                DCD    EPWM4_TZINT_IRQHandler          ;< 20 EPWM4_TZINT_IRQn
                DCD    EPWM5_TZINT_IRQHandler          ;< 21 EPWM5_TZINT_IRQn
                DCD    EPWM6_TZINT_IRQHandler          ;< 22 EPWM6_TZINT_IRQn
                DCD    EPWM7_TZINT_IRQHandler          ;< 23 EPWM7_TZINT_IRQn
                DCD    EPWM1_INT_IRQHandler            ;< 24 EPWM1_INT_IRQn
                DCD    EPWM2_INT_IRQHandler            ;< 25 EPWM2_INT_IRQn
                DCD    EPWM3_INT_IRQHandler            ;< 26 EPWM3_INT_IRQn
                DCD    EPWM4_INT_IRQHandler            ;< 27 EPWM4_INT_IRQn
                DCD    EPWM5_INT_IRQHandler            ;< 28 EPWM5_INT_IRQn
                DCD    EPWM6_INT_IRQHandler            ;< 29 EPWM6_INT_IRQn
                DCD    EPWM7_INT_IRQHandler            ;< 30 EPWM7_INT_IRQn
                DCD    ECAP_IRQHandler                 ;< 31 ECAP1/2/3_IRQn
                DCD    EQEP_IRQHandler                 ;< 32 EQEP1/2_IRQn
                DCD    EPG_IRQHandler                  ;< 33 EPG_IRQn
                DCD    LPTIM_IRQHandler                ;< 34 LPTIM_IRQn
                DCD    CAN1_IRQHandler                 ;< 35 CAN1_IRQn
                DCD    CAN1_ECC_IRQHandler             ;< 36 CAN1_ECC_IRQn
                DCD    0                               ;< 37 Reserved
                DCD    0                               ;< 38 Reserved
                DCD    STIM1_IRQHandler                ;< 39 STIM1_IRQn
                DCD    STIM2_IRQHandler                ;< 40 STIM2_IRQn
                DCD    STIM3_IRQHandler                ;< 41 STIM3_IRQn
                DCD    AWK_IRQHandler                  ;< 42 AWK_IRQn
                DCD    LIN1_IRQHandler                 ;< 43 LIN1_IRQn
                DCD    I2C1_IRQHandler                 ;< 44 I2C1_IRQn
                DCD    0                               ;< 45 Reserved
                DCD    0                               ;< 46 Reserved
                DCD    SPI1_RX_IRQHandler              ;< 47 SPI1_RX_IRQn
                DCD    SPI1_TX_IRQHandler              ;< 48 SPI1_TX_IRQn
                DCD    SPI2_RX_IRQHandler              ;< 49 SPI2_RX_IRQn
                DCD    SPI2_TX_IRQHandler              ;< 50 SPI2_TX_IRQn
                DCD    UART1_TX_IRQHandler             ;< 51 UART1_TX_IRQn
                DCD    UART1_RX_IRQHandler             ;< 52 UART1_RX_IRQn
                DCD    0                               ;< 53 Reserved
                DCD    0                               ;< 54 Reserved
                DCD    0                               ;< 55 Reserved
                DCD    0                               ;< 56 Reserved
                DCD    MMATH_MCM_IRQHandler            ;< 57 MMATH_MCM_IRQn
                DCD    DCC1_IRQHandler                 ;< 58 DCC_IRQn
                DCD    0                               ;< 59 Reserved


                THUMB
                PUBWEAK Reset_Handler
                SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
                CPSID   I               ; Mask interrupts
        
                ; vector table relocation
                LDR     R0, =0xE000ED08
                LDR     R1, =__vector_table
                STR     R1, [R0]

                ; Initialize the stack pointer
                LDR     R0, =sfe(CSTACK)
                MOV     R13, R0

                CPSIE   I               ; Unmask interrupts

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
                B NMI_Handler

                PUBWEAK HardFault_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
                B HardFault_Handler

                PUBWEAK MemManage_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
MemManage_Handler
                B MemManage_Handler

                PUBWEAK BusFault_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
BusFault_Handler
                B BusFault_Handler

                PUBWEAK UsageFault_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
UsageFault_Handler
                B UsageFault_Handler

                PUBWEAK SVC_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
                B SVC_Handler

                PUBWEAK DebugMon_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DebugMon_Handler
                B DebugMon_Handler

                PUBWEAK PendSV_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler
                B PendSV_Handler

                PUBWEAK SysTick_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
                B SysTick_Handler

                PUBWEAK WWDG_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
WWDG_IRQHandler
                B WWDG_IRQHandler

                PUBWEAK IWDG1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IWDG1_IRQHandler
                B IWDG1_IRQHandler

                PUBWEAK FLASH_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
FLASH_IRQHandler
                B FLASH_IRQHandler

                PUBWEAK FLASH_ECCERR_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
FLASH_ECCERR_IRQHandler
                B FLASH_ECCERR_IRQHandler

                PUBWEAK RAM_ECCERR_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
RAM_ECCERR_IRQHandler
                B RAM_ECCERR_IRQHandler

                PUBWEAK RCC_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
RCC_IRQHandler
                B RCC_IRQHandler

                PUBWEAK EXTI_GPIO_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXTI_GPIO_IRQHandler
                B EXTI_GPIO_IRQHandler

                PUBWEAK EXTI_CMP_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXTI_CMP_IRQHandler
                B EXTI_CMP_IRQHandler

                PUBWEAK EXTI_XINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXTI_XINT_IRQHandler
                B EXTI_XINT_IRQHandler

                PUBWEAK EDMA1_CH0_CH1_CH2_CH3_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EDMA1_CH0_CH1_CH2_CH3_IRQHandler
                B EDMA1_CH0_CH1_CH2_CH3_IRQHandler

                PUBWEAK EDMA1_CH4_CH5_CH6_CH7_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EDMA1_CH4_CH5_CH6_CH7_IRQHandler
                B EDMA1_CH4_CH5_CH6_CH7_IRQHandler

                PUBWEAK EDMA1_ERR_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EDMA1_ERR_IRQHandler
                B EDMA1_ERR_IRQHandler

                PUBWEAK ADCA_CONV_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADCA_CONV_IRQHandler
                B ADCA_CONV_IRQHandler

                PUBWEAK ADCA_EVENT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADCA_EVENT_IRQHandler
                B ADCA_EVENT_IRQHandler

                PUBWEAK ADCC_CONV_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADCC_CONV_IRQHandler
                B ADCC_CONV_IRQHandler

                PUBWEAK ADCC_EVENT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADCC_EVENT_IRQHandler
                B ADCC_EVENT_IRQHandler

                PUBWEAK EPWM1_TZINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM1_TZINT_IRQHandler
                B EPWM1_TZINT_IRQHandler

                PUBWEAK EPWM2_TZINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM2_TZINT_IRQHandler
                B EPWM2_TZINT_IRQHandler

                PUBWEAK EPWM3_TZINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM3_TZINT_IRQHandler
                B EPWM3_TZINT_IRQHandler

                PUBWEAK EPWM4_TZINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM4_TZINT_IRQHandler
                B EPWM4_TZINT_IRQHandler

                PUBWEAK EPWM5_TZINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM5_TZINT_IRQHandler
                B EPWM5_TZINT_IRQHandler

                PUBWEAK EPWM6_TZINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM6_TZINT_IRQHandler
                B EPWM6_TZINT_IRQHandler

                PUBWEAK EPWM7_TZINT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM7_TZINT_IRQHandler
                B EPWM7_TZINT_IRQHandler

                PUBWEAK EPWM1_INT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM1_INT_IRQHandler
                B EPWM1_INT_IRQHandler

                PUBWEAK EPWM2_INT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM2_INT_IRQHandler
                B EPWM2_INT_IRQHandler

                PUBWEAK EPWM3_INT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM3_INT_IRQHandler
                B EPWM3_INT_IRQHandler

                PUBWEAK EPWM4_INT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM4_INT_IRQHandler
                B EPWM4_INT_IRQHandler

                PUBWEAK EPWM5_INT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM5_INT_IRQHandler
                B EPWM5_INT_IRQHandler

                PUBWEAK EPWM6_INT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM6_INT_IRQHandler
                B EPWM6_INT_IRQHandler

                PUBWEAK EPWM7_INT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPWM7_INT_IRQHandler
                B EPWM7_INT_IRQHandler

                PUBWEAK ECAP_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ECAP_IRQHandler
                B ECAP_IRQHandler

                PUBWEAK EQEP_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EQEP_IRQHandler
                B EQEP_IRQHandler

                PUBWEAK EPG_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EPG_IRQHandler
                B EPG_IRQHandler

                PUBWEAK LPTIM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
LPTIM_IRQHandler
                B LPTIM_IRQHandler

                PUBWEAK CAN1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CAN1_IRQHandler
                B CAN1_IRQHandler

                PUBWEAK CAN1_ECC_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CAN1_ECC_IRQHandler
                B CAN1_ECC_IRQHandler

                PUBWEAK STIM1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
STIM1_IRQHandler
                B STIM1_IRQHandler

                PUBWEAK STIM2_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
STIM2_IRQHandler
                B STIM2_IRQHandler

                PUBWEAK STIM3_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
STIM3_IRQHandler
                B STIM3_IRQHandler

                PUBWEAK AWK_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
AWK_IRQHandler
                B AWK_IRQHandler

                PUBWEAK LIN1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
LIN1_IRQHandler
                B LIN1_IRQHandler

                PUBWEAK I2C1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C1_IRQHandler
                B I2C1_IRQHandler

                PUBWEAK SPI1_RX_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI1_RX_IRQHandler
                B SPI1_RX_IRQHandler

                PUBWEAK SPI1_TX_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI1_TX_IRQHandler
                B SPI1_TX_IRQHandler

                PUBWEAK SPI2_RX_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI2_RX_IRQHandler
                B SPI2_RX_IRQHandler

                PUBWEAK SPI2_TX_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI2_TX_IRQHandler
                B SPI2_TX_IRQHandler

                PUBWEAK UART1_TX_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
UART1_TX_IRQHandler
                B UART1_TX_IRQHandler

                PUBWEAK UART1_RX_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
UART1_RX_IRQHandler
                B UART1_RX_IRQHandler

                PUBWEAK MMATH_MCM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
MMATH_MCM_IRQHandler
                B MMATH_MCM_IRQHandler

                PUBWEAK DCC1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DCC1_IRQHandler
                B DCC1_IRQHandler



                END


;************************ (C) COPYRIGHT NOVOSENSE *****END OF FILE*****
