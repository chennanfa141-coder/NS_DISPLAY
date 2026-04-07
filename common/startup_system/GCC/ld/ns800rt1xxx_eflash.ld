/******************************************************************************
 * @file     ns800rt1xxx_eflash.ld
 * @brief    GNU Linker Script for Cortex-M7 based device
 ******************************************************************************/
/*
 * Copyright 2025 NOVOSENSE Electronics. All rights reserved.
 */

/*----------------------------------------------------------------------------
 * Flash Configuration
 *----------------------------------------------------------------------------*/
__FLASH_BASE = 0x00400000;
__FLASH_SIZE = 0x00040000;

/*----------------------------------------------------------------------------
 * Embedded RAM Configuration
 *----------------------------------------------------------------------------*/
__ITCM_BASE     = 0x00000000;
__ITCM_SIZE     = 0x0000BF00;
__EXE_ITCM_SIZE = 0x00000100;
__DTCM_BASE     = 0x20000000;
__DTCM_SIZE     = 0x00008000;
__DTCM_VT_SIZE  = 0x00000200;

/*----------------------------------------------------------------------------
 * Stack / Heap Configuration
 *----------------------------------------------------------------------------*/
__STACK_SIZE = DEFINED(__STACK_SIZE__) ? __STACK_SIZE__ : 0x00001000;
__HEAP_SIZE  = DEFINED(__HEAP_SIZE__) ?  __HEAP_SIZE__  : 0x00000C00;

/*----------------------------------------------------------------------------
  Region base & size definition
 *----------------------------------------------------------------------------*/
__TEXT_BASE        = __FLASH_BASE;
__TEXT_SIZE        = __FLASH_SIZE;

__RAM_CODE_BASE    = __ITCM_BASE;
__RAM_CODE_SIZE    = __ITCM_SIZE;

__RAM_DLY_BASE    = __ITCM_BASE + __ITCM_SIZE;
__RAM_DLY_SIZE    = __EXE_ITCM_SIZE;

__RAM_VECTOR_BASE  = __DTCM_BASE;
__RAM_VECTOR_SIZE  = __DTCM_VT_SIZE;

__DATA_BASE        = __DTCM_BASE + __RAM_VECTOR_SIZE;
__DATA_SIZE        = __DTCM_SIZE - __RAM_VECTOR_SIZE;


MEMORY
{
  TEXT       (rx)  : ORIGIN = __TEXT_BASE,        LENGTH = __TEXT_SIZE
  RAM_VECTOR (rwx) : ORIGIN = __RAM_VECTOR_BASE,  LENGTH = __RAM_VECTOR_SIZE
  RAM_TEXT   (rwx) : ORIGIN = __RAM_CODE_BASE,    LENGTH = __RAM_CODE_SIZE
  RAM_DELAY  (rwx) : ORIGIN = __RAM_DLY_BASE,     LENGTH = __RAM_DLY_SIZE
  DATA       (rw)  : ORIGIN = __DATA_BASE,        LENGTH = __DATA_SIZE
}

/*
 * Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions TEXT and DATA.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 */
ENTRY(Reset_Handler)

SECTIONS
{
  .text (READONLY) :
  {
    KEEP(*(.vectors))
    *(.text*)

    KEEP(*(.init))
    KEEP(*(.fini))

    /* .ctors */
    *crtbegin.o(.ctors)
    *crtbegin?.o(.ctors)
    *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
    *(SORT(.ctors.*))
    *(.ctors)

    /* .dtors */
    *crtbegin.o(.dtors)
    *crtbegin?.o(.dtors)
    *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
    *(SORT(.dtors.*))
    *(.dtors)

    *(.rodata*)

    KEEP(*(.eh_frame*))
    . = ALIGN(4);
  } > TEXT

  .ARM.extab (READONLY) :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > TEXT

  .ARM.exidx :
  {
    __exidx_start = .;
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    __exidx_end = .;
  } > TEXT

  .copy.table (READONLY) :
  {
    . = ALIGN(4);
    __copy_table_start__ = .;

    LONG (LOADADDR(.vt_dtcm))
    LONG (ADDR(.vt_dtcm))
    LONG (SIZEOF(.vt_dtcm) / 4)

    LONG (LOADADDR(.dtcm))
    LONG (ADDR(.dtcm))
    LONG (SIZEOF(.dtcm) / 4)

    LONG (LOADADDR(.itcm))
    LONG (ADDR(.itcm))
    LONG (SIZEOF(.itcm) / 4)

    LONG (LOADADDR(.ex_itcm))
    LONG (ADDR(.ex_itcm))
    LONG (SIZEOF(.ex_itcm) / 4)

    LONG (LOADADDR(.data))
    LONG (ADDR(.data))
    LONG (SIZEOF(.data) / 4)

    __copy_table_end__ = .;
  } > TEXT

  .zero.table (READONLY) :
  {
    . = ALIGN(4);
    __zero_table_start__ = .;

    LONG (ADDR(.bss))
    LONG (SIZEOF(.bss) / 4)
/*
    LONG (ADDR(.srambss))
    LONG (SIZEOF(.srambss) / 4)

    LONG (ADDR(.backupbss))
    LONG (SIZEOF(.backupbss) / 4)
*/
    __zero_table_end__ = .;
  } > TEXT

  /**
   * Location counter can end up 2byte aligned with narrow Thumb code but
   * __etext is assumed by startup code to be the LMA of a section in RAM
   * which must be 4byte aligned
   *
   * This __etext variable is kept for backward compatibility with older,
   * ASM based startup files.
   */
  PROVIDE(__etext = LOADADDR(.data));

  .data : ALIGN(4)
  {
    __data_start__ = .;
    *(vtable)
    *(.data)
    *(.data.*)

    . = ALIGN(4);
    /* preinit data */
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP(*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);

    . = ALIGN(4);
    /* init data */
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP(*(SORT(.init_array.*)))
    KEEP(*(.init_array))
    PROVIDE_HIDDEN (__init_array_end = .);

    . = ALIGN(4);
    /* finit data */
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP(*(SORT(.fini_array.*)))
    KEEP(*(.fini_array))
    PROVIDE_HIDDEN (__fini_array_end = .);

    KEEP(*(.jcr*))
    . = ALIGN(4);
    /* All data end */
    __data_end__ = .;
  } > DATA AT > TEXT

  .vt_dtcm : ALIGN(4)
  {
    . = ALIGN(4);
    __vt_dtcm_start__ = .;
    . = ALIGN(4);
    __vt_dtcm_end__ = .;
  } > RAM_VECTOR AT > TEXT
  PROVIDE(__ram_vector = __ram_vector_start__);

  .dtcm : ALIGN(4)
  {
    . = ALIGN(4);
    __dtcm_start__ = .;
    *(.dtcm)
    *(.dtcm.*)
    . = ALIGN(4);
    __dtcm_end__ = .;
  } > DATA AT > DATA

  .itcm : ALIGN(4)
  {
    . = ALIGN(4);
    __itcm_start__ = .;
    *(.itcm)
    *(.itcm.*)
    . = ALIGN(4);
    __itcm_end__ = .;
  } > RAM_TEXT AT > TEXT

  .ex_itcm : ALIGN(4)
  {
    . = ALIGN(4);
    __ex_itcm_start__ = .;
    *(.ex_itcm)
    *(.ex_itcm.*)
    . = ALIGN(4);
    __ex_itcm_end__ = .;
  } > RAM_DELAY AT > TEXT

  .bss :
  {
    . = ALIGN(4);
    __bss_start__ = .;
    *(.bss)
    *(.bss.*)
    . = ALIGN(4);
    __bss_end__ = .;
  } > DATA AT > DATA
/*
  .srambss :
  {
    . = ALIGN(4);
    __sram_bss_start__ = .;
    *(.srambss)
    *(.srambss.*)
    *(COMMON)
    . = ALIGN(4);
    __sram_bss_end__ = .;
  } > DATA AT > DATA
*/
  .heap (COPY) :
  {
    . = ALIGN(8);
    __end__ = .;
    PROVIDE(end = .);
    . = . + __HEAP_SIZE;
    . = ALIGN(8);
    __HeapLimit = .;
  } > DATA

  .stack (ORIGIN(DATA) + LENGTH(DATA) - __STACK_SIZE) (COPY) :
  {
    . = ALIGN(8);
    __StackLimit = .;
    . = . + __STACK_SIZE;
    . = ALIGN(8);
    __StackTop = .;
  } > DATA
  PROVIDE(__stack = __StackTop);

  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  /* Check if data + heap + stack exceeds RAM limit */
  /* ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack") */
}
