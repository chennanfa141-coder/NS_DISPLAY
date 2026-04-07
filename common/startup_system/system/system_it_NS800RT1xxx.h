/**
  * @file       system_it_NS800RT1xxx.h
  * @author     Haven-X
  * @brief      the header file about 'system_it_NS800RT1xxx.c'.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __SYSTEM_IT_NS800RT1XXX_H__
#define __SYSTEM_IT_NS800RT1XXX_H__


#ifdef __cplusplus
extern "C" {
#endif

#include "NS800RTxxxx.h"


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
 * \brief   NMI interrupt vector Handler
 */
extern void NMI_Handler (void);

/**
 * \brief   HardFault interrupt vector Handler
 */
extern void HardFault_Handler (void);

/**
 * \brief   MemManage interrupt vector Handler
 */
extern void MemManage_Handler (void);

/**
 * \brief   BusFault interrupt vector Handler
 */
extern void BusFault_Handler (void);

/**
 * \brief   UsageFault interrupt vector Handler
 */
extern void UsageFault_Handler (void);

/**
 * \brief   SVC interrupt vector Handler
 */
extern void SVC_Handler (void);

/**
 * \brief   DebugMon interrupt vector Handler
 */
extern void DebugMon_Handler (void);

/**
 * \brief   PendSV interrupt vector Handler
 */
extern void PendSV_Handler (void);

/**
 * \brief   SysTick interrupt vector Handler
 */
extern void SysTick_Handler (void);


#ifdef __cplusplus
}
#endif


#endif /* __SYSTEM_IT_NS800RT1XXX_H__ */
