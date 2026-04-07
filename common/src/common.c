//###########################################################################
//
// FILE:  common.c
//
// TITLE:  common.c
//
//###########################################################################
// $Copyright:
// Copyright (C) 2024 Chipsine Semiconductor -https://www.chipsine.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
// Redistributions of source code must retain the above copyright 
// notice, this list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the 
// documentation and/or other materials provided with the   
// distribution.
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


#include "common.h"
#include "board.h"
#include "string.h"
#include <stdarg.h>
#include "gpio.h"
#include "NS800RTxxxx.h"


#define DEST_CONSOLE                   (1)
#define DEST_STRING                    (2)

#define FLAGS_MINUS                    (0x01)
#define FLAGS_PLUS                     (0x02)
#define FLAGS_SPACE                    (0x04)
#define FLAGS_ZERO                     (0x08)
#define FLAGS_POUND                    (0x10)

#define IS_FLAG_MINUS(a)               (a & FLAGS_MINUS)
#define IS_FLAG_PLUS(a)                (a & FLAGS_PLUS)
#define IS_FLAG_SPACE(a)               (a & FLAGS_SPACE)
#define IS_FLAG_ZERO(a)                (a & FLAGS_ZERO)
#define IS_FLAG_POUND(a)               (a & FLAGS_POUND)

#define LENMOD_h                       (0x01)
#define LENMOD_l                       (0x02)
#define LENMOD_L                       (0x04)

#define IS_LENMOD_h(a)                 (a & LENMOD_h)
#define IS_LENMOD_l(a)                 (a & LENMOD_l)
#define IS_LENMOD_L(a)                 (a & LENMOD_L)

#define FMT_d                          (0x0001)
#define FMT_o                          (0x0002)
#define FMT_x                          (0x0004)
#define FMT_X                          (0x0008)
#define FMT_u                          (0x0010)
#define FMT_c                          (0x0020)
#define FMT_s                          (0x0040)
#define FMT_p                          (0x0080)
#define FMT_n                          (0x0100)

#define IS_FMT_d(a)                    (a & FMT_d)
#define IS_FMT_o(a)                    (a & FMT_o)
#define IS_FMT_x(a)                    (a & FMT_x)
#define IS_FMT_X(a)                    (a & FMT_X)
#define IS_FMT_u(a)                    (a & FMT_u)
#define IS_FMT_c(a)                    (a & FMT_c)
#define IS_FMT_s(a)                    (a & FMT_s)
#define IS_FMT_p(a)                    (a & FMT_p)
#define IS_FMT_n(a)                    (a & FMT_n)


/* Following code ported for IAR print log, don't change it! */


typedef struct
{
    int dest;
    void (*func)(char);
    char *loc;
} PRINTK_INFO;




/***************************************************************************
 * @brief         delay us 
 *
 * @param[in]     us:delay timer 
 *                    - uint32_t
 *
 * @return        
 *
 * @note          
***************************************************************************/
// void delay(uint32_t us) __attribute__((optnone))
// {
//     us = us*5;
//     while(us--);
// }





/***************************************************************************
 * @brief         swo_print_init
 *
 * @return        
 *
 * @note          
***************************************************************************/
#if (ENABLE_SWO_TRACE  == 1)
void swo_print_init(void)
{
    GPIO_setPinConfig(GPIO_37_TRACESWO);
}
#endif



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
void board_putchar (char ch)
{
#if ENABLE_SWO_TRACE == 0
    while(BOARD_SERIALCOM->STAT.BIT.TDRE == 0);
    BOARD_SERIALCOM->DATA.WORDVAL = ch;
#else
    ITM_SendChar(ch);
#endif
}




/***************************************************************************
 * @brief         board wait putchar done 
 *
 * @return        
 *
 * @note          
***************************************************************************/
void board_wait_putchar_done (void)
{
    while(BOARD_SERIALCOM->STAT.BIT.TC == 0);
}



/***************************************************************************
 * @brief         printk 
 *
 * @param[in]     c:printf char 
 *                    - char
 *
 * @param[in]     *count:count pointer 
 *
 * @param[in]     *info: 
 *
 * @return        info pointer 
 *
 * @note          
***************************************************************************/
static void
printk_putc (char c, int *count, PRINTK_INFO *info)
{
    switch (info->dest)
    {
        case DEST_CONSOLE:
            info->func(c);
            break;
        case DEST_STRING:
            *(info->loc) = (unsigned char)c;
            ++(info->loc);
            break;
        default:
            break;
    }
    *count += 1;
}



/***************************************************************************
 * @brief         printk mknumstr 
 *
 * @param[in]     *numstr:mumstr pointer 
 *
 * @param[in]     *nump:nump pointer 
 *
 * @param[in]     neg:neg 
 *                    - int
 *
 * @param[in]     radix:radix 
 *                    - int
 *
 * @return        
 *                    - int
 *
 * @note          
***************************************************************************/
static int
printk_mknumstr (char *numstr, void *nump, int neg, int radix)
{
    int a,b,c;
    unsigned int ua,ub,uc;

    int nlen;
    char *nstrp;

    nlen = 0;
    nstrp = numstr;
    *nstrp++ = '\0';

    if (neg)
    {
        a = *(int *)nump;
        if (a == 0)
        {
            *nstrp = '0';
            ++nlen;
            goto done;
        }
        while (a != 0)
        {
            b = (int)a / (int)radix;
            c = (int)a - ((int)b * (int)radix);
            if (c < 0)
            {
                c = ~c + 1 + '0';
            }
            else
            {
                c = c + '0';
            }
            a = b;
            *nstrp++ = (char)c;
            ++nlen;
        }
    }
    else
    {
        ua = *(unsigned int *)nump;
        if (ua == 0)
        {
            *nstrp = '0';
            ++nlen;
            goto done;
        }
        while (ua != 0)
        {
            ub = (unsigned int)ua / (unsigned int)radix;
            uc = (unsigned int)ua - ((unsigned int)ub * (unsigned int)radix);
            if (uc < 10)
            {
                uc = uc + '0';
            }
            else
            {
                uc = uc - 10 + 'A';
            }
            ua = ub;
            *nstrp++ = (char)uc;
            ++nlen;
        }
    }
    done:
    return nlen;
}



/***************************************************************************
 * @brief         printk pad zero 
 *
 * @param[in]     curlen:curlen 
 *                    - int
 *
 * @param[in]     field_width:field width 
 *                    - int
 *
 * @param[in]     *count:count pointer 
 *
 * @param[in]     *info:info pointer 
 *
 * @return        
 *
 * @note          
***************************************************************************/
static void
printk_pad_zero (int curlen, int field_width, int *count, PRINTK_INFO *info)
{
    int i;

    for (i = curlen; i < field_width; i++)
    {
        printk_putc('0',count, info);
    }
}



/***************************************************************************
 * @brief         printk pad space 
 *
 * @param[in]     curlen:curlen 
 *                    - int
 *
 * @param[in]     field_width:field width 
 *                    - int
 *
 * @param[in]     *count:count pointer 
 *
 * @param[in]     *info:info pointer 
 *
 * @return        
 *
 * @note          
***************************************************************************/
static void
printk_pad_space (int curlen, int field_width, int *count, PRINTK_INFO *info)
{
    int i;

    for (i = curlen; i < field_width; i++)
    {
        printk_putc(' ',count, info);
    }
}




/***************************************************************************
 * @brief         printk 
 *
 * @param[in]     *info:info pointer 
 *
 * @param[in]     *fmt:fmt pointer 
 *
 * @param[in]     ap:va_list 
 *
 * @return        
 *                    - int
 *
 * @note          
***************************************************************************/
static int printk (PRINTK_INFO *info, const char *fmt, va_list ap)
{
    /* va_list ap; */
    char *p;
    char c;

    char vstr[33];
    char *vstrp;
    int vlen;

    int done;
    int count = 0;

    int flags_used;
    int field_width;
#if 0
    int precision_used;
    int precision_width;
    int length_modifier;
#endif

    int ival;
    char schar, dschar;
    int *ivalp;
    char *sval;
    char cval;
    unsigned int uval;

    /*
     * Start parsing apart the format string and display appropriate
     * formats and data.
     */
    for (p = (char *)fmt; (c = *p) != 0; p++)
    {
        /*
         * All formats begin with a '%' marker.  Special chars like
         * '\n' or '\t' are normally converted to the appropriate
         * character by the __compiler__.  Thus, no need for this
         * routine to account for the '\' character.
         */
        if (c != '%')
        {
            /*
             * This needs to be replaced with something like
             * 'board_putchar()' or call an OS routine.
             */
#ifndef UNIX_DEBUG
            if (c != '\n')
            {
                printk_putc(c, &count, info);
            }
            else
            {
                printk_putc(0x0D /* CR */, &count, info);
                printk_putc(0x0A /* LF */, &count, info);
            }
#else
            printk_putc(c, &count, info);
#endif

            /*
             * By using 'continue', the next iteration of the loop
             * is used, skipping the code that follows.
             */
            continue;
        }

        /*
         * First check for specification modifier flags.
         */
        flags_used = 0;
        done = 0;
        while (!done)
        {
            switch (/* c = */ *++p)
            {
                case '-':
                    flags_used |= FLAGS_MINUS;
                    break;
                case '+':
                    flags_used |= FLAGS_PLUS;
                    break;
                case ' ':
                    flags_used |= FLAGS_SPACE;
                    break;
                case '0':
                    flags_used |= FLAGS_ZERO;
                    break;
                case '#':
                    flags_used |= FLAGS_POUND;
                    break;
                default:
                    /* we've gone one char too far */
                    --p;
                    done = 1;
                    break;
            }
        }

        /*
         * Next check for minimum field width.
         */
        field_width = 0;
        done = 0;
        while (!done)
        {
            switch (c = *++p)
            {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    field_width = (field_width * 10) + (c - '0');
                    break;
                default:
                    /* we've gone one char too far */
                    --p;
                    done = 1;
                    break;
            }
        }

        /*
         * Next check for the width and precision field separator.
         */
        if (/* (c = *++p) */ *++p == '.')
        {
            /* precision_used = TRUE; */

            /*
             * Must get precision field width, if present.
             */
            /* precision_width = 0; */
            done = 0;
            while (!done)
            {
                switch (/* c = uncomment if used below */ *++p)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
#if 0
                        precision_width = (precision_width * 10) +
                            (c - '0');
#endif
                        break;
                    default:
                        /* we've gone one char too far */
                        --p;
                        done = 1;
                        break;
                }
            }
        }
        else
        {
            /* we've gone one char too far */
            --p;
#if 0
            precision_used = 0;
            precision_width = 0;
#endif
        }

        /*
         * Check for the length modifier.
         */
        /* length_modifier = 0; */
        switch (/* c = */ *++p)
        {
            case 'h':
                /* length_modifier |= LENMOD_h; */
                break;
            case 'l':
                /* length_modifier |= LENMOD_l; */
                break;
            case 'L':
                /* length_modifier |= LENMOD_L; */
                break;
            default:
                /* we've gone one char too far */
                --p;
                break;
        }

        /*
         * Now we're ready to examine the format.
         */
        switch (c = *++p)
        {
            case 'd':
            case 'i':
                ival = (int)va_arg(ap, int);
                vlen = printk_mknumstr(vstr,&ival,1,10);
                vstrp = &vstr[vlen];

                if (ival < 0)
                {
                    schar = '-';
                    ++vlen;
                }
                else
                {
                    if (IS_FLAG_PLUS(flags_used))
                    {
                        schar = '+';
                        ++vlen;
                    }
                    else
                    {
                        if (IS_FLAG_SPACE(flags_used))
                        {
                            schar = ' ';
                            ++vlen;
                        }
                        else
                        {
                            schar = 0;
                        }
                    }
                }
                dschar = 0;
            
                /*
                 * do the ZERO pad.
                 */
                if (IS_FLAG_ZERO(flags_used))
                {
                    if (schar)
                        printk_putc(schar, &count, info);
                    dschar = 1;
            
                    printk_pad_zero (vlen, field_width, &count, info);
                    vlen = field_width;
                }
                else
                {
                    if (!IS_FLAG_MINUS(flags_used))
                    {
                        printk_pad_space (vlen, field_width, &count, info);
            
                        if (schar)
                            printk_putc(schar, &count, info);
                        dschar = 1;
                    }
                }
            
                /* the string was built in reverse order, now display in */
                /* correct order */
                if (!dschar && schar)
                {
                    printk_putc(schar, &count, info);
                }
                goto cont_xd;

            case 'x':
            case 'X':
                uval = (unsigned int)va_arg(ap, unsigned int);
                vlen = printk_mknumstr(vstr,&uval,0,16);
                vstrp = &vstr[vlen];

                dschar = 0;
                if (IS_FLAG_ZERO(flags_used))
                {
                    if (IS_FLAG_POUND(flags_used))
                    {
                        printk_putc('0', &count, info);
                        printk_putc('x', &count, info);
                        /*vlen += 2;*/
                        dschar = 1;
                    }
                    printk_pad_zero (vlen, field_width, &count, info);
                    vlen = field_width;
                }
                else
                {
                    if (!IS_FLAG_MINUS(flags_used))
                    {
                        if (IS_FLAG_POUND(flags_used))
                        {
                            vlen += 2;
                        }
                        printk_pad_space (vlen, field_width, &count, info);
                        if (IS_FLAG_POUND(flags_used))
                        {
                            printk_putc('0', &count, info);
                            printk_putc('x', &count, info);
                            dschar = 1;
                        }
                    }
                }

                if ((IS_FLAG_POUND(flags_used)) && !dschar)
                {
                    printk_putc('0', &count, info);
                    printk_putc('x', &count, info);
                    vlen += 2;
                }
                goto cont_xd;

            case 'o':
                uval = (unsigned int)va_arg(ap, unsigned int);
                vlen = printk_mknumstr(vstr,&uval,0,8);
                goto cont_u;
            case 'b':
                uval = (unsigned int)va_arg(ap, unsigned int);
                vlen = printk_mknumstr(vstr,&uval,0,2);
                goto cont_u;
            case 'p':
                uval = (unsigned int)va_arg(ap, void *);
                vlen = printk_mknumstr(vstr,&uval,0,16);
                goto cont_u;
            case 'u':
                uval = (unsigned int)va_arg(ap, unsigned int);
                vlen = printk_mknumstr(vstr,&uval,0,10);

                cont_u:
                    vstrp = &vstr[vlen];

                    if (IS_FLAG_ZERO(flags_used))
                    {
                        printk_pad_zero (vlen, field_width, &count, info);
                        vlen = field_width;
                    }
                    else
                    {
                        if (!IS_FLAG_MINUS(flags_used))
                        {
                            printk_pad_space (vlen, field_width, &count, info);
                        }
                    }

                cont_xd:
                    while (*vstrp)
                        printk_putc(*vstrp--, &count, info);

                    if (IS_FLAG_MINUS(flags_used))
                    {
                        printk_pad_space (vlen, field_width, &count, info);
                    }
                break;

            case 'c':
                cval = (char)va_arg(ap, unsigned int);
                printk_putc(cval,&count, info);
                break;
            case 's':
                sval = (char *)va_arg(ap, char *);
                if (sval)
                {
                    vlen = strlen(sval);
                    if (!IS_FLAG_MINUS(flags_used))
                    {
                        printk_pad_space (vlen, field_width, &count, info);
                    }
                    while (*sval)
                        printk_putc(*sval++,&count, info);
                    if (IS_FLAG_MINUS(flags_used))
                    {
                        printk_pad_space (vlen, field_width, &count, info);
                    }
                }
                break;
            case 'n':
                ivalp = (int *)va_arg(ap, int *);
                *ivalp = count;
                break;
            default:
                printk_putc(c,&count, info);
                break;
        }
    }
    return count;
}



/***************************************************************************
 * @brief         printD 
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
int printD (const char *fmt, ...)
{
    va_list ap;
    int rvalue;
    PRINTK_INFO info;
    
  
    info.dest = DEST_CONSOLE;
    info.func = &board_putchar;
    /*
    * Initialize the pointer to the variable length argument list.
    */
    va_start(ap, fmt);
    rvalue = printk(&info, fmt, ap);
    /*
    * Cleanup the variable length argument list.
    */
    va_end(ap);
    
    return rvalue;
}



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
int print_log (const char *fmt, ...)
{
    va_list ap;
    int rvalue;
    PRINTK_INFO info;
    
  
    info.dest = DEST_CONSOLE;
    info.func = &board_putchar;
    /*
    * Initialize the pointer to the variable length argument list.
    */
    va_start(ap, fmt);
    rvalue = printk(&info, fmt, ap);
    /*
    * Cleanup the variable length argument list.
    */
    va_end(ap);
    
    return rvalue;
}




/***************************************************************************
 * @brief         sprintD 
 *
 * @param[in]     *s:s pointer 
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
int sprintD (char *s, const char *fmt, ...)
{
    va_list ap;
    int rvalue = 0;
    PRINTK_INFO info;

    /*
     * Initialize the pointer to the variable length argument list.
     */
    if (s != 0)
    {
        info.dest = DEST_STRING;
        info.loc = s;
        va_start(ap, fmt);
        rvalue = printk(&info, fmt, ap);
        *info.loc = '\0';
        va_end(ap);
    }
    return rvalue;
}


/***************************************************************************
 * @brief         fputc 
 *
 * @param[in]     ch:ch 
 *                    - int
 *
 * @param[in]     *f:f pointer 
 *
 * @return        ch 
 *                    - int
 *
 * @note          
***************************************************************************/
/**
 * @brief      Print character
 * @param ch   Character to print
 * @param f    File descriptor(No used)
 * @return int Equal to 'size'(No used)
 */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
int fputc (int ch, FILE *f)
{
    (void)f;

    while (BOARD_SERIALCOM->STAT.BIT.TDRE == 0)
    {
        ;
    }
    BOARD_SERIALCOM->DATA.WORDVAL = ch;
    while (BOARD_SERIALCOM->STAT.BIT.TC == 0);

    return ch;
}
#elif defined(__GNUC__)
/**
 * @brief          Print string
 * @param fd       File descriptor(No used)
 * @param pBuffer  Buffer address to print
 * @param size     Number of bytes to print
 * @return int     Equal to 'size'(No used)
 */
int _write (int fd, char *pBuffer, int size)
{
    (void)fd;
    setvbuf(stdout, NULL, _IONBF, 0);

    for (int i = 0; i < size; i++)
    {
        while (BOARD_SERIALCOM->STAT.BIT.TDRE == 0)
        {
            ;
        }
        BOARD_SERIALCOM->DATA.WORDVAL = *pBuffer++;
    }
    while (BOARD_SERIALCOM->STAT.BIT.TC == 0);

    return size;
}
#elif defined(__ICCARM__)
/**
 * @brief          Print string
 * @param handle   File descriptor(No used)
 * @param buf      Buffer address to print
 * @param bufSize  Number of bytes to print
 * @return size_t  Equal to 'bufSize'(No used)
 */
size_t __write (int handle, const unsigned char *buf, size_t bufSize)
{
    (void)handle;

    for (uint32_t i = 0; i < bufSize; i++)
    {
        while (BOARD_SERIALCOM->STAT.BIT.TDRE == 0)
        {
            ;
        }
        BOARD_SERIALCOM->DATA.WORDVAL = *(buf + i);
    }
    while (BOARD_SERIALCOM->STAT.BIT.TC == 0);

    return bufSize;
}
#endif





