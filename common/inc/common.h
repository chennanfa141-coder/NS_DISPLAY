//###########################################################################
//
// FILE:  common.h
//
// TITLE:  common.h
//
//###########################################################################
// $Copyright:
// Copyright (C) 2024 Chipsine Semiconductor -https://www.chipsine.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//Redistributions of source code must retain the above copyright 
//notice, this list of conditions and the following disclaimer.
//
//Redistributions in binary form must reproduce the above copyright
//notice, this list of conditions and the following disclaimer in the 
//documentation and/or other materials provided with the   
//distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
//###########################################################################


#ifndef  __CPS_COMMON_H__
#define  __CPS_COMMON_H__

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"


#define ENABLE_SWO_TRACE               0


/***************************************************************************
 * @brief         disable interrupts 
 *
 * @return        STATUS_S_SUCCESS 
 *                    - uint16_t
 *
 * @note          
***************************************************************************/
extern uint16_t __disable_interrupts(void);


/***************************************************************************
 * @brief         enable interrupts 
 *
 * @return        STATUS_S_SUCCESS 
 *                    - uint16_t
 *
 * @note          
***************************************************************************/
extern uint16_t __enable_interrupts(void);



/***************************************************************************
 * @brief         delay us 
 *
 * @param[in]     count:delay timer 
 *                    - uint32_t
 *
 * @return        
 *
 * @note          
***************************************************************************/
// void delay(uint32_t count);






/***************************************************************************
 * @brief         print_log 
 *
 * @param[in]     *fmt:fmt pointer 
 *
 * @param[in]     ...: 
 *
 * @return        rvalue 
 *                    - int
 *
 * @note          
***************************************************************************/
extern int print_log (const char *fmt, ...);




/***************************************************************************
 * @brief         board wait putchar done 
 *
 * @return        
 *
 * @note          
***************************************************************************/
extern void board_wait_putchar_done(void);



/***************************************************************************
 * @brief         Print init 
 *
 * @return        
 *
 * @note          
***************************************************************************/
extern void Print_init(void);




/***************************************************************************
 * @brief         printf 
 *
 * @param[in]     ch:printf char 
 *                    - char
 *
 * @return        
 *
 * @note          
***************************************************************************/
extern void board_putchar (char ch);




#if (ENABLE_SWO_TRACE  == 1)
/***************************************************************************
 * @brief         swo_print_init
 *
 * @return        
 *
 * @note          
***************************************************************************/
extern void swo_print_init(void);
#endif



#endif