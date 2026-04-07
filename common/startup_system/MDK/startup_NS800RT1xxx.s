;********************************************************************************
;* @File Name          : startup_NS800RT1xxx.s
;* @author             : MCD Application Team
;* @Description        : NS800RT1xxx devices vector table for MDK toolchain.
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

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>
Stack_Size      EQU     0x00001000

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00001000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size


__Vectors       DCD     __initial_sp
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
                DCD    DCC1_IRQHandler                 ;< 58 DCC1_IRQn
                DCD    0                               ;< 59 Reserved



__Vectors_End

__Vectors_Size      EQU     __Vectors_End - __Vectors

                    AREA    |.text|, CODE, READONLY

;Reset Handler routine

; Reset Handler routine

Reset_Handler       PROC
                    EXPORT  Reset_Handler                    [WEAK]
                    IMPORT  __main
                    IMPORT  SystemInit

                    LDR     R0, =SystemInit
                    BLX     R0
                    LDR     R0, =__main
                    BX      R0
                    ENDP

NMI_Handler         PROC
                    EXPORT  NMI_Handler                      [WEAK]
                    B       .
                    ENDP

HardFault_Handler   PROC
                    EXPORT  HardFault_Handler                [WEAK]
                    B       .
                    ENDP

MemManage_Handler   PROC
                    EXPORT  MemManage_Handler                [WEAK]
                    B       .
                    ENDP

BusFault_Handler    PROC
                    EXPORT  BusFault_Handler                 [WEAK]
                    B       .
                    ENDP

UsageFault_Handler  PROC
                    EXPORT  UsageFault_Handler               [WEAK]
                    B       .
                    ENDP

DebugMon_Handler    PROC
                    EXPORT  DebugMon_Handler                 [WEAK]
                    B       .
                    ENDP

SVC_Handler         PROC
                    EXPORT  SVC_Handler                      [WEAK]
                    B       .
                    ENDP

PendSV_Handler      PROC
                    EXPORT  PendSV_Handler                   [WEAK]
                    B       .
                    ENDP

SysTick_Handler     PROC
                    EXPORT  SysTick_Handler                  [WEAK]
                    B       .
                    ENDP

Default_Handler     PROC
                    EXPORT    WWDG_IRQHandler                 [weak]    ;< 0  WWDG_IRQn
                    EXPORT    IWDG1_IRQHandler                [weak]    ;< 1  IWDG1_IRQn
                    EXPORT    FLASH_IRQHandler                [weak]    ;< 3  FLASH_IRQn
                    EXPORT    FLASH_ECCERR_IRQHandler         [weak]    ;< 4  FLASH_ECCERR_IRQn
                    EXPORT    RAM_ECCERR_IRQHandler           [weak]    ;< 5  RAM_ECCERR_IRQn
                    EXPORT    RCC_IRQHandler                  [weak]    ;< 6  RCC_IRQn
                    EXPORT    EXTI_GPIO_IRQHandler            [weak]    ;< 7  EXTI_GPIO_IRQn
                    EXPORT    EXTI_CMP_IRQHandler             [weak]    ;< 8  EXTI_CMP_IRQn
                    EXPORT    EXTI_XINT_IRQHandler            [weak]    ;< 9  EXTI_XINT_IRQn
                    EXPORT    EDMA1_CH0_CH1_CH2_CH3_IRQHandler[weak]    ;< 10 EDMA1_CH0_CH1_CH2_CH3_IRQ
                    EXPORT    EDMA1_CH4_CH5_CH6_CH7_IRQHandler[weak]    ;< 11 EDMA1_CH4_CH5_CH6_CH7_IRQ
                    EXPORT    EDMA1_ERR_IRQHandler            [weak]    ;< 12 EDMA1_ERR_IRQn
                    EXPORT    ADCA_CONV_IRQHandler            [weak]    ;< 13 ADCA_CONV_IRQn
                    EXPORT    ADCA_EVENT_IRQHandler           [weak]    ;< 14 ADCA_EVENT_IRQn
                    EXPORT    ADCC_CONV_IRQHandler            [weak]    ;< 15 ADCC_CONV_IRQn
                    EXPORT    ADCC_EVENT_IRQHandler           [weak]    ;< 16 ADCC_EVENT_IRQn
                    EXPORT    EPWM1_TZINT_IRQHandler          [weak]    ;< 17 EPWM1_TZINT_IRQn
                    EXPORT    EPWM2_TZINT_IRQHandler          [weak]    ;< 18 EPWM2_TZINT_IRQn
                    EXPORT    EPWM3_TZINT_IRQHandler          [weak]    ;< 19 EPWM3_TZINT_IRQn
                    EXPORT    EPWM4_TZINT_IRQHandler          [weak]    ;< 20 EPWM4_TZINT_IRQn
                    EXPORT    EPWM5_TZINT_IRQHandler          [weak]    ;< 21 EPWM5_TZINT_IRQn
                    EXPORT    EPWM6_TZINT_IRQHandler          [weak]    ;< 22 EPWM6_TZINT_IRQn
                    EXPORT    EPWM7_TZINT_IRQHandler          [weak]    ;< 23 EPWM7_TZINT_IRQn
                    EXPORT    EPWM1_INT_IRQHandler            [weak]    ;< 24 EPWM1_INT_IRQn
                    EXPORT    EPWM2_INT_IRQHandler            [weak]    ;< 25 EPWM2_INT_IRQn
                    EXPORT    EPWM3_INT_IRQHandler            [weak]    ;< 26 EPWM3_INT_IRQn
                    EXPORT    EPWM4_INT_IRQHandler            [weak]    ;< 27 EPWM4_INT_IRQn
                    EXPORT    EPWM5_INT_IRQHandler            [weak]    ;< 28 EPWM5_INT_IRQn
                    EXPORT    EPWM6_INT_IRQHandler            [weak]    ;< 29 EPWM6_INT_IRQn
                    EXPORT    EPWM7_INT_IRQHandler            [weak]    ;< 30 EPWM7_INT_IRQn
                    EXPORT    ECAP_IRQHandler                 [weak]    ;< 31 ECAP1/2/3_IRQn
                    EXPORT    EQEP_IRQHandler                 [weak]    ;< 32 EQEP1/2_IRQn
                    EXPORT    EPG_IRQHandler                  [weak]    ;< 33 EPG_IRQn
                    EXPORT    LPTIM_IRQHandler                [weak]    ;< 34 LPTIM_IRQn
                    EXPORT    CAN1_IRQHandler                 [weak]    ;< 35 CAN1_IRQn
                    EXPORT    CAN1_ECC_IRQHandler             [weak]    ;< 36 CAN1_ECC_IRQn
                    EXPORT    STIM1_IRQHandler                [weak]    ;< 39 STIM1_IRQn
                    EXPORT    STIM2_IRQHandler                [weak]    ;< 40 STIM2_IRQn
                    EXPORT    STIM3_IRQHandler                [weak]    ;< 41 STIM3_IRQn
                    EXPORT    AWK_IRQHandler                  [weak]    ;< 42 AWK_IRQn
                    EXPORT    LIN1_IRQHandler                 [weak]    ;< 43 LIN1_IRQn
                    EXPORT    I2C1_IRQHandler                 [weak]    ;< 44 I2C1_IRQn
                    EXPORT    SPI1_RX_IRQHandler              [weak]    ;< 47 SPI1_RX_IRQn
                    EXPORT    SPI1_TX_IRQHandler              [weak]    ;< 48 SPI1_TX_IRQn
                    EXPORT    SPI2_RX_IRQHandler              [weak]    ;< 49 SPI2_RX_IRQn
                    EXPORT    SPI2_TX_IRQHandler              [weak]    ;< 50 SPI2_TX_IRQn
                    EXPORT    UART1_TX_IRQHandler             [weak]    ;< 51 UART1_TX_IRQn
                    EXPORT    UART1_RX_IRQHandler             [weak]    ;< 52 UART1_RX_IRQn
                    EXPORT    MMATH_MCM_IRQHandler            [weak]    ;< 57 MMATH_MCM_IRQn
                    EXPORT    DCC1_IRQHandler                 [weak]    ;< 58 DCC1_IRQn



WWDG_IRQHandler                     ; 0  WWDG_IRQn
IWDG1_IRQHandler                    ; 1  IWDG1_IRQn
FLASH_IRQHandler                    ; 3  FLASH_IRQn
FLASH_ECCERR_IRQHandler             ; 4  FLASH_ECCERR_IRQn
RAM_ECCERR_IRQHandler               ; 5  RAM_ECCERR_IRQn
RCC_IRQHandler                      ; 6  RCC_IRQn
EXTI_GPIO_IRQHandler                ; 7  EXTI_GPIO_IRQn
EXTI_CMP_IRQHandler                 ; 8  EXTI_CMP_IRQn
EXTI_XINT_IRQHandler                ; 9  EXTI_XINT_IRQn
EDMA1_CH0_CH1_CH2_CH3_IRQHandler    ; 10 EDMA1_CH0_CH1_CH2_CH3_IRQ
EDMA1_CH4_CH5_CH6_CH7_IRQHandler    ; 11 EDMA1_CH4_CH5_CH6_CH7_IRQ
EDMA1_ERR_IRQHandler                ; 12 EDMA1_ERR_IRQn
ADCA_CONV_IRQHandler                ; 13 ADCA_CONV_IRQn
ADCA_EVENT_IRQHandler               ; 14 ADCA_EVENT_IRQn
ADCC_CONV_IRQHandler                ; 15 ADCC_CONV_IRQn
ADCC_EVENT_IRQHandler               ; 16 ADCC_EVENT_IRQn
EPWM1_TZINT_IRQHandler              ; 17 EPWM1_TZINT_IRQn
EPWM2_TZINT_IRQHandler              ; 18 EPWM2_TZINT_IRQn
EPWM3_TZINT_IRQHandler              ; 19 EPWM3_TZINT_IRQn
EPWM4_TZINT_IRQHandler              ; 20 EPWM4_TZINT_IRQn
EPWM5_TZINT_IRQHandler              ; 21 EPWM5_TZINT_IRQn
EPWM6_TZINT_IRQHandler              ; 22 EPWM6_TZINT_IRQn
EPWM7_TZINT_IRQHandler              ; 23 EPWM7_TZINT_IRQn
EPWM1_INT_IRQHandler                ; 24 EPWM1_INT_IRQn
EPWM2_INT_IRQHandler                ; 25 EPWM2_INT_IRQn
EPWM3_INT_IRQHandler                ; 26 EPWM3_INT_IRQn
EPWM4_INT_IRQHandler                ; 27 EPWM4_INT_IRQn
EPWM5_INT_IRQHandler                ; 28 EPWM5_INT_IRQn
EPWM6_INT_IRQHandler                ; 29 EPWM6_INT_IRQn
EPWM7_INT_IRQHandler                ; 30 EPWM7_INT_IRQn
ECAP_IRQHandler                     ; 31 ECAP1/2/3_IRQn
EQEP_IRQHandler                     ; 32 EQEP1/2_IRQn
EPG_IRQHandler                      ; 33 EPG_IRQn
LPTIM_IRQHandler                    ; 34 LPTIM_IRQn
CAN1_IRQHandler                     ; 35 CAN1_IRQn
CAN1_ECC_IRQHandler                 ; 36 CAN1_ECC_IRQn
STIM1_IRQHandler                    ; 39 STIM1_IRQn
STIM2_IRQHandler                    ; 40 STIM2_IRQn
STIM3_IRQHandler                    ; 41 STIM3_IRQn
AWK_IRQHandler                      ; 42 AWK_IRQn
LIN1_IRQHandler                     ; 43 LIN1_IRQn
I2C1_IRQHandler                     ; 44 I2C1_IRQn
SPI1_RX_IRQHandler                  ; 47 SPI1_RX_IRQn
SPI1_TX_IRQHandler                  ; 48 SPI1_TX_IRQn
SPI2_RX_IRQHandler                  ; 49 SPI2_RX_IRQn
SPI2_TX_IRQHandler                  ; 50 SPI2_TX_IRQn
UART1_TX_IRQHandler                 ; 51 UART1_TX_IRQn
UART1_RX_IRQHandler                 ; 52 UART1_RX_IRQn
MMATH_MCM_IRQHandler                ; 57 MMATH_MCM_IRQn
DCC1_IRQHandler                     ; 58 DCC1_IRQn


                B       .
                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END


;************************ (C) COPYRIGHT Novosns *****END OF FILE*****
