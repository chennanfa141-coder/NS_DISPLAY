/**
  * @file       edma.h
  * @author     zhenght
  * @brief      Header file for NS800RT1xxx edma module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __EDMA_H__
#define __EDMA_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"
#include "NS800RT1xxx_TI_edma.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup EDMA_EXPORTED_TYPES EDMA Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'EDMA' module.
  */

/** @defgroup EDMA_DCHPRI_CONFIG EDMA Channel Priority Configuration
  * @{
  * @brief  Macro definitions about EDMA channel priority configuration.
  *         Recommending byte-level read and write operations
  */
#define EDMA_DCHPRI_INDEX(channel) ((channel) ^ 0x03UL)                         /*!< Compute the offset unit from DCHPRI0 */
#define EDMA_DCHPRIn(base, channel) \
        ((volatile uint8_t *) &(base->DCHPRI0))[EDMA_DCHPRI_INDEX(channel)]    /*!< Get the pointer of DCHPRIn */

/**
  * @}
  */

/** @defgroup EDMA_TRANSFERSIZE EDMA Source/Destination Data Transfer Size
  * @{
  * @brief  Macro definitions about EDMA source/destination data transfer size.
  *         Values that can be passed to EDMA_configTransfer() as the \e srcStep/destStep parameter.
  */
typedef enum {
    EDMA_TRANSFERSIZE1BYTES  = 0x0U,    /*!< Source/Destination data transfer size is 1 byte every time */
    EDMA_TRANSFERSIZE2BYTES,            /*!< Source/Destination data transfer size is 2 bytes every time */
    EDMA_TRANSFERSIZE4BYTES,            /*!< Source/Destination data transfer size is 4 bytes every time */
    EDMA_TRANSFERSIZE16BYTES = 0x04U    /*!< Source/Destination data transfer size is 16 bytes every time */
} EDMA_TransferSize;

/**
  * @}
  */

/** @defgroup EDMA_INTERRUPTENABLEMASK EDMA Interrupt Enable Mask
  * @{
  * @brief  Macro definitions about EDMA interrupt enable mask.
  *         Values that can be passed to EDMA_enableChannelInterrupts() as the \e mask parameter.
  */
typedef enum {
    EDMA_ERRORINTERRUPTENABLE = 0x1U,    /*!< Enable interrupt while channel error occurs */
    EDMA_MAJORINTERRUPTENABLE = 0x2U,    /*!< Enable interrupt while major count exhausted */
    EDMA_HALFINTERRUPTENABLE  = 0x4U     /*!< Enable interrupt while major count to half value */
} EDMA_InterruptEnableMask;

/**
  * @}
  */

/** @defgroup EDMA_MODULOCFG EDMA Modulo Configuration
  * @{
  * @brief  Macro definitions about EDMA modulo configuration.
  *         Values that can be passed to EDMA_configChannel() as the \e config parameter.
  */
typedef enum {
    EDMA_MODULODISABLE = 0x0U,    /*!< Disable modulo */
    EDMA_MODULO2BYTES,            /*!< Circular buffer size is 2 bytes */
    EDMA_MODULO4BYTES,            /*!< Circular buffer size is 4 bytes */
    EDMA_MODULO8BYTES,            /*!< Circular buffer size is 8 bytes  */
    EDMA_MODULO16BYTES,           /*!< Circular buffer size is 16 bytes */
    EDMA_MODULO32BYTES,           /*!< Circular buffer size is 32 bytes */
    EDMA_MODULO64BYTES,           /*!< Circular buffer size is 64 bytes */
    EDMA_MODULO128BYTES,          /*!< Circular buffer size is 128 bytes */
    EDMA_MODULO256BYTES,          /*!< Circular buffer size is 256 bytes */
    EDMA_MODULO512BYTES,          /*!< Circular buffer size is 512 bytes */
    EDMA_MODULO1KBYTES,           /*!< Circular buffer size is 1 K bytes */
    EDMA_MODULO2KBYTES,           /*!< Circular buffer size is 2 K bytes */
    EDMA_MODULO4KBYTES,           /*!< Circular buffer size is 4 K bytes */
    EDMA_MODULO8KBYTES,           /*!< Circular buffer size is 8 K bytes */
    EDMA_MODULO16KBYTES,          /*!< Circular buffer size is 16 K bytes */
    EDMA_MODULO32KBYTES,          /*!< Circular buffer size is 32 K bytes */
    EDMA_MODULO64KBYTES,          /*!< Circular buffer size is 64 K bytes*/
    EDMA_MODULO128KBYTES,         /*!< Circular buffer size is 128 K bytes */
    EDMA_MODULO256KBYTES,         /*!< Circular buffer size is 256 K bytes */
    EDMA_MODULO512KBYTES,         /*!< Circular buffer size is 512 K bytes */
    EDMA_MODULO1MBYTES,           /*!< Circular buffer size is 1 M bytes */
    EDMA_MODULO2MBYTES,           /*!< Circular buffer size is 2 M bytes */
    EDMA_MODULO4MBYTES,           /*!< Circular buffer size is 4 M bytes */
    EDMA_MODULO8MBYTES,           /*!< Circular buffer size is 8 M bytes */
    EDMA_MODULO16MBYTES,          /*!< Circular buffer size is 16 M bytes */
    EDMA_MODULO32MBYTES,          /*!< Circular buffer size is 32 M bytes */
    EDMA_MODULO64MBYTES,          /*!< Circular buffer size is 64 M bytes */
    EDMA_MODULO128MBYTES,         /*!< Circular buffer size is 128 M bytes */
    EDMA_MODULO256MBYTES,         /*!< Circular buffer size is 256 M bytes */
    EDMA_MODULO512MBYTES,         /*!< Circular buffer size is 512 M bytes */
    EDMA_MODULO1GBYTES,           /*!< Circular buffer size is 1 G bytes */
    EDMA_MODULO2GBYTES            /*!< Circular buffer size is 2 G bytes */
} EDMA_ModuloCfg;

/**
  * @}
  */

/** @defgroup EDMA_CHANNELLINKTYPE EDMA Channel Link Type
  * @{
  * @brief  Macro definitions about EDMA channel link type.
  *         Values that can be passed to EDMA_setChannelLink() as the \e type parameter.
  */
typedef enum {
    EDMA_LINKNONE = 0x0U,    /*!< No channel link */
    EDMA_MINORLINK,          /*!< Channel link after each minor loop */
    EDMA_MAJORLINK           /*!< Channel link while major loop count exhausted */
} EDMA_ChannelLinkType;

/**
  * @}
  */

/** @defgroup EDMA_CHANNELSTATUS EDMA Channel Status
  * @{
  * @brief  Macro definitions about EDMA channel status.
  *         Values that can be passed to EDMA_setChannelLink() as the \e type parameter.
  */
typedef enum {
    EDMA_DONEFLAG      = 0x1U,    /*!< DONE flag, set while transfer finished, CITER value exhausted */
    EDMA_ERRORFLAG     = 0x2U,    /*!< EDMA error flag, an error occurred in a transfer */
    EDMA_INTERRUPTFLAG = 0x4U     /*!< EDMA interrupt flag, set while an interrupt occurred of this channel */
} EDMA_ChannelStatus;

/**
  * @}
  */

/** @defgroup EDMA_MINOROFFSETCONFIG EDMA Minor Loop Mapping Configuration
  * @{
  * @brief  Macro definitions about EDMA minor loop mapping configuration.
  *         Values that can be passed to EDMA_setMinorOffsetConfig() as the \e config parameter.
  */
typedef struct {
    uint8_t enableSrcMinorOffset;     /*!< Enable(true) or Disable(false) source minor loop offset */
    uint8_t enableDestMinorOffset;    /*!< Enable(true) or Disable(false) destination minor loop offset */
    int32_t minorOffset;              /*!< Offset for a minor loop mapping */
} EDMA_MinorOffsetConfig;

/**
  * @}
  */

/** @defgroup EDMA_CHANNELPREEMPTIONCONFIG EDMA Channel Priority Configuration
  * @{
  * @brief  Macro definitions about EDMA channel priority configuration.
  *         Values that can be passed to EDMA_setChannelPreemptionConfig() as the \e config parameter.
  */
typedef struct {
    uint8_t enableChannelPreemption;    /*!< Channel can be suspended by other channel with higher priority */
    uint8_t enablePreemptAbility;       /*!< Channel can suspend other channel with low priority */
    uint8_t channelPriority;            /*!< Channel priority */
} EDMA_ChannelPreemptionConfig;

/**
  * @}
  */

/** @defgroup EDMA_COMMONCONFIG EDMA Common Configuration
  * @{
  * @brief  Macro definitions about EDMA common configuration.
  *         Values that can be passed to EDMA_configModule() as the \e config parameter.
  */
typedef struct {
    uint8_t enableContinuousLinkMode;          /*!< Enable (true) continuous link mode */
    uint8_t enableHaltOnError;                 /*!< Enable (true) transfer halt on error */
    uint8_t enableRoundRobinChnArbitration;    /*!< Enable (true) round robin channel arbitration method or \
                                                    fixed priority arbitration is used for channel selection */
    uint8_t enableDebugMode;                   /*!< Enable(true) EDMA debug mode */
    uint8_t enableEmlm;                        /*!< Enable Minor Loop Mapping */
} EDMA_CommonConfig;

/**
  * @}
  */

/** @defgroup EDMA_TRANSFERCONFIG EDMA Transfer Config struct
  * @{
  * @brief  Macro definitions about EDMA transfer configuration.
  *         Values that can be passed to EDMA_configChannel() as the \e config parameter.
  */
typedef struct {
    uint32_t channel;                      /*!< EDMA channel */
    uint32_t srcAddr;                      /*!< Source data address */
    uint32_t destAddr;                     /*!< Destination data address */
    int16_t  srcOffset;                    /*!< Sign-extended offset applied to the current source address to \
                                                form the next-state value as each source read is completed */
    int16_t  destOffset;                   /*!< Sign-extended offset applied to the current destination address \
                                                to form the next-state value as each destination write is completed */
    uint32_t minorLoopBytes;               /*!< Bytes to transfer in a minor loop */
    uint32_t majorLoopCounts;              /*!< Major loop iteration count */
    int32_t  slast;                        /*!< Last Source Address Adjustment */
    int32_t  dlast;                        /*!< Destination last address adjustment */
    uint8_t  enMajorInt;                   /*!< Enable or disable major interrupt */
    uint8_t  enDreq;                       /*!< Enable or disable request by hardware automatically */
    uint8_t  enTrigger;                    /*!< Enable or disable trigger function */
    uint8_t  enErrInt;                     /*!< Enable or disable err interrupt */
    uint8_t  startMode;                    /*!< 0:soft start  1:hardware start */
    uint8_t  resv;                         /*!< Resv bit */
    EDMA_TransferSize srcTransferSize;     /*!< Source data transfer size */
    EDMA_TransferSize destTransferSize;    /*!< Destination data transfer size */
    EDMA_TCD_TypeDef* nextTcd;             /*!< SCATTER/GATHER next tcd */
} EDMA_TransferConfig;

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
  * \brief  EDMA cancel transfer.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  */
static inline void EDMA_setTransferCx (EDMA_TypeDef *edma)
{
    SET_BIT(edma->CR.WORDVAL, EDMA_CR_CX_M);
}

/**
  * \brief  EDMA error cancel transfer.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  */
static inline void EDMA_setTransferEcx (EDMA_TypeDef *edma)
{
    SET_BIT(edma->CR.WORDVAL, EDMA_CR_ECX_M);
}

/**
  * \brief  Minor Loop Mapping setting.
  * \param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  * \param  enable    Enable Minor Loop Mapping.
  *                    - 0: Dsiable
  *                    - 1: Enable
  */
static inline void EDMA_enableEmlm (EDMA_TypeDef *edma, bool enable)
{
    if (enable)
    {
        SET_BIT(edma->CR.WORDVAL, EDMA_CR_EMLM_M);
    }
    else
    {
        CLEAR_BIT(edma->CR.WORDVAL, EDMA_CR_EMLM_M);
    }
}

/**
  * \brief  Continuous link mode setting.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  * \param  on     Continuous link mode is off/on.
  *                 - 0: Off
  *                 - 1: On
  */
static inline void EDMA_enableClm (EDMA_TypeDef *edma, bool on)
{
    if (on)
    {
        SET_BIT(edma->CR.WORDVAL, EDMA_CR_CLM_M);
    }
    else
    {
        CLEAR_BIT(edma->CR.WORDVAL, EDMA_CR_CLM_M);
    }
}

/**
  * \brief  Halt EDMA Operations.
  * \param  edma    The base address of the EDMA module.
  *                  - EDMA1: EDMA1 base address index
  * \param  halt    Halt EDMA Operations.
  *                  - 0: Normal operation
  *                  - 1: EDMA operations halted
  */
static inline void EDMA_haltTransfer (EDMA_TypeDef *edma, bool halt)
{
    if (halt)
    {
        SET_BIT(edma->CR.WORDVAL, EDMA_CR_HALT_M);
    }
    else
    {
        CLEAR_BIT(edma->CR.WORDVAL, EDMA_CR_HALT_M);
    }
}

/**
  * \brief  Enable Round Robin Channel Arbitration.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  control    Enable Round Robin Channel Arbitration.
  *                     - 0: Fixed priority arbitration within each group
  *                     - 1: Round robin arbitration within each group
  */
static inline void EDMA_enableErca (EDMA_TypeDef *edma, bool control)
{
    if (control)
    {
        SET_BIT(edma->CR.WORDVAL, EDMA_CR_ERCA_M);
    }
    else
    {
        CLEAR_BIT(edma->CR.WORDVAL, EDMA_CR_ERCA_M);
    }
}

/**
  * \brief  Enable debugging and determine the EDMA operation when in debug mode.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  control    Enable Debug mode.
  *                     - 0: When the chip is in Debug mode, the EDMA continues to operate.
  *                     - 1: When the chip is in Debug mode, the EDMA stalls the start of a new channel.
  *                          but executing channels are allowed to complete.
  */
static inline void EDMA_enableEdbg (EDMA_TypeDef *edma, bool control)
{
    if (control)
    {
        SET_BIT(edma->CR.WORDVAL, EDMA_CR_EDBG_M);
    }
    else
    {
        CLEAR_BIT(edma->CR.WORDVAL, EDMA_CR_EDBG_M);
    }
}

/**
  * \brief  Gets the EDMA channel error status flags.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  * \return Returns the status of error status.
  *                 - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
static inline uint32_t EDMA_getErrorStatusFlags (EDMA_TypeDef *edma)
{
    return READ_REG(edma->ES.WORDVAL);
}

/**
  * \brief  Enables the multiple EDMA hardware channel request.
  * \param  edma    The base address of the EDMA module.
  *                  - EDMA1: EDMA1 base address index
  * \param  data    Enable Multi EDMA Request.
  *                  - uint32_t: 0x00UL - 0xFFUL
  */
static inline void EDMA_enableMultiChannelRequest (EDMA_TypeDef *edma, uint32_t data)
{
    WRITE_REG(edma->ERQ.WORDVAL, data);
}

/**
  * \brief  Enables the EDMA hardware channel request.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_enableChannelRequest (EDMA_TypeDef *edma, uint8_t channel)
{
    WRITE_REG(edma->SERQ, channel);
}

/**
  * \brief  Disable the EDMA hardware channel request.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_disableChannelRequest (EDMA_TypeDef *edma, uint8_t channel)
{
    WRITE_REG(edma->CERQ, channel);
}

/**
  * \brief  Enable the interrupt source for the EDMA transfer.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  mask       Interrupt mask.
  *                     This parameter can be any value of @ref EDMA_INTERRUPTENABLEMASK
  */
static inline void EDMA_enableChannelInterrupts (EDMA_TypeDef *edma, \
                                                 uint8_t channel, \
                                                 EDMA_InterruptEnableMask mask)
{
    /* Enable error interrupt */
    if (mask & EDMA_ERRORINTERRUPTENABLE)
    {
        SET_BIT(edma->EEI.WORDVAL, (0x1U << channel));
    }

    /* Enable Major interrupt */
    if (mask & EDMA_MAJORINTERRUPTENABLE)
    {
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTMAJOR_M);
    }

    /* Enable Half major interrupt */
    if (mask & EDMA_HALFINTERRUPTENABLE)
    {
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTHALF_M);
    }
}

/**
  * \brief  Gets the EDMA channel done flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \return Returns the current channel done flag
  *                     - bool: 0/1
  */
static inline bool EDMA_getChannelDoneFlags(EDMA_TypeDef *edma, uint8_t channel)
{
    return (bool)(READ_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DONE_M) >> EDMA_TCD_BITER_ELINKNO_DONE_S);
}

/**
  * \brief  Disable the interrupt source for the EDMA transfer.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  mask       Interrupt mask.
  *                     This parameter can be any value of @ref EDMA_INTERRUPTENABLEMASK
  */
static inline void EDMA_disableChannelInterrupts (EDMA_TypeDef *edma, uint8_t channel, \
                                                  EDMA_InterruptEnableMask mask)
{
    /* Disable error interrupt */
    if (mask & EDMA_ERRORINTERRUPTENABLE)
    {
        CLEAR_BIT(edma->EEI.WORDVAL, (0x1U << channel));
    }

    /* Disable Major interrupt */
    if (mask & EDMA_MAJORINTERRUPTENABLE)
    {
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTMAJOR_M);
    }

    /* Disable Half major interrupt */
    if (mask & EDMA_HALFINTERRUPTENABLE)
    {
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_INTHALF_M);
    }
}

/**
  * \brief  Clears the EDMA channel status done flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_clearChannelStatusDoneFlags (EDMA_TypeDef *edma, uint32_t channel)
{
    /* Clear DONE bit flag */
    MODIFY_REG(edma->CDNE, (uint8_t)0x1FUL, channel);
}

/**
  * \brief  Clears the EDMA channel status error flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_clearChannelStatusErrorFlags (EDMA_TypeDef *edma, uint32_t channel)
{
    /* Clear ERROR bit flag */
    MODIFY_REG(edma->CERR, (uint8_t)0x1FUL, channel);
}

/**
  * \brief  Gets the EDMA all channel error flags.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  * \return Returns the channel error flag.
  *                 - uint32_t: 0x00UL - 0xFFUL
  *                 - bit x: EDMA channel x error flag.
  */
static inline uint32_t EDMA_getAllChannelErrorFlags (EDMA_TypeDef *edma)
{
    return READ_REG(edma->ERR.WORDVAL);
}

/**
  * \brief  Clear the EDMA all channel error flags .
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  */
static inline void EDMA_clearAllChannelErrorFlags (EDMA_TypeDef *edma)
{
    WRITE_REG(edma->ERR.WORDVAL, 0xFFUL);
}

/**
  * \brief  Gets the EDMA all channel hardware request status.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  * \return Returns the channel hardware request status.
  *                 - uint32_t: 0x00UL - 0xFFUL
  *                 - bit x: EDMA channel x hardware request status.
  */
static inline uint32_t EDMA_getAllChannelHardwareRequestStatus (EDMA_TypeDef *edma)
{
    return READ_REG(edma->HRS.WORDVAL);
}

/**
  * \brief  Clears the EDMA channel status int flags.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_clearChannelStatusIntFlags (EDMA_TypeDef *edma, uint32_t channel)
{
    /* Clear INT bit flag */
    MODIFY_REG(edma->CINT, (uint8_t)0x7UL, channel);
}

/**
  * \brief  Start the EDMA transfer.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_startTransfer (EDMA_TypeDef *edma, uint8_t channel)
{
    EDMA_enableChannelRequest(edma, channel);
}

/**
  * \brief  Soft start the EDMA transfer.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_startTransfersoft (EDMA_TypeDef *edma, uint8_t channel)
{
    WRITE_REG(edma->SSRT, channel);
}

/**
  * \brief  Gets the EDMA channel interrupt status flags.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  * \return Returns the EDMA channel interrupt status flags.
  *                 - uint32_t: 0x00UL - 0xFFUL
  */
static inline uint32_t EDMA_getChannelIntStatus (EDMA_TypeDef *edma)
{
    return READ_REG(edma->INT.WORDVAL);
}

/**
  * \brief  Reset the EDMA TCD.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_resetTcd (EDMA_TypeDef *edma, uint8_t channel)
{
    memset((void *)&(edma->TCD[channel]), 0UL, sizeof(EDMA_TCD_TypeDef));
}

/**
  * \brief  Push content of TCD structure into hardware TCD register.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  tcd        Tcd Point to TCD structure.
  *                     This parameter can be any value of @ref EDMA_TCD_TypeDef
  */
static inline void EDMA_installTCD (EDMA_TypeDef *edma, uint32_t channel, EDMA_TCD_TypeDef *tcd)
{
    /* Push tcd into hardware TCD register */
    edma->TCD[channel].SADDR.WORDVAL    = tcd->SADDR.WORDVAL;
    edma->TCD[channel].DADDR.WORDVAL    = tcd->DADDR.WORDVAL;
    edma->TCD[channel].TO.WORDVAL       = tcd->TO.WORDVAL;
    edma->TCD[channel].NBYTES           = tcd->NBYTES;
    edma->TCD[channel].SLAST.WORDVAL    = tcd->SLAST.WORDVAL;
    edma->TCD[channel].DLASTSGA.WORDVAL = tcd->DLASTSGA.WORDVAL;
    edma->TCD[channel].CITER            = tcd->CITER;
    edma->TCD[channel].BITER            = tcd->BITER;
}

/**
  * \brief  Sets the minor offset for the EDMA TCD.
  * \note   This function must call after the EDMA_configChannel, otherwise the value written will be overwritten.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  config     config A pointer to the minor offset configuration structure.
  *                     This parameter can be any value of @ref EDMA_MINOROFFSETCONFIG
  */
static inline void EDMA_setMinorOffsetConfig (EDMA_TypeDef *edma, \
                                              uint8_t channel, \
                                              EDMA_MinorOffsetConfig *config)
{
    uint32_t data = 0UL;
    bool flag = 0;

    data = READ_REG(edma->TCD[channel].NBYTES) & (uint32_t)(EDMA_TCD_NBYTES_MLOFFYES_DMLOE_M | \
                                                            EDMA_TCD_NBYTES_MLOFFYES_SMLOE_M | \
                                                            EDMA_TCD_NBYTES_MLOFFYES_NBYTES_M);
    if (config->enableSrcMinorOffset)
    {
        SET_BIT(data, EDMA_TCD_NBYTES_MLOFFYES_SMLOE_M);
        flag = 1;
    }
    if (config->enableDestMinorOffset)
    {
        SET_BIT(data, EDMA_TCD_NBYTES_MLOFFYES_DMLOE_M);
        flag = 1;
    }
    if (flag)
    {
        data |= (((uint32_t)config->minorOffset) << EDMA_TCD_NBYTES_MLOFFYES_MLOFF_S) & EDMA_TCD_NBYTES_MLOFFYES_MLOFF_M;
        WRITE_REG(edma->TCD[channel].NBYTES, data);
    }
}

/**
  * \brief  Sets the source modulo and the destination modulo for the EDMA TCD.
  * \param  edma          The base address of the EDMA module.
  *                        - EDMA1: EDMA1 base address index
  * \param  channel       Channel num.
  *                        - uint8_t: 0x00 - 0x07
  * \param  srcModulo     srcModulo A source modulo value
  *                        This parameter can be any value of @ref EDMA_MODULOCFG
  * \param  destModulo    destModulo A destination modulo value
  *                        This parameter can be any value of @ref EDMA_MODULOCFG
  */
static inline void EDMA_setModulo (EDMA_TypeDef *edma, uint32_t channel, \
                                   EDMA_ModuloCfg srcModulo, EDMA_ModuloCfg destModulo)
{
    MODIFY_REG(edma->TCD[channel].TO.WORDVAL, (uint32_t)(EDMA_TCD_TO_SMOD_M | EDMA_TCD_TO_DMOD_M), \
               (uint32_t)(srcModulo << EDMA_TCD_TO_SMOD_S) | (uint32_t)(destModulo << EDMA_TCD_TO_DMOD_S));
}

/**
  * \brief  Enable/Disable auto stop requeset.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  enable     Enable or Disable auto stop request
  *                     - 0: The channel's ERQ field is not affected
  *                     - 1: The channel's ERQ field value changes to 0 when the major loop is complete
  */
static inline void EDMA_enableAutoStopRequest (EDMA_TypeDef *edma, uint8_t channel, bool enable)
{
    if (enable)
    {
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
    }
    else
    {
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
    }
}

/**
  * \brief  Configures the EDMA tcd structure and link the next tcd.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  tcd        Tcd Point to TCD structure.
  *                     This parameter can be any value of @ref EDMA_TCD_TypeDef
  * \param  config     Tcd config param.
  *                     This parameter can be any value of @ref EDMA_TRANSFERCONFIG
  * \param  nextTcd    next tcd
  *                     This parameter can be any value of @ref EDMA_TCD_TypeDef
  */
static inline void EDMA_configTcdTransfer (EDMA_TypeDef *edma,
                                           EDMA_TCD_TypeDef *tcd, \
                                           const EDMA_TransferConfig *config, \
                                           EDMA_TCD_TypeDef *nextTcd)
{
    uint32_t mask;

    /* Source address */
    WRITE_REG(tcd->SADDR.WORDVAL, config->srcAddr);

    /* Destination address */
    WRITE_REG(tcd->DADDR.WORDVAL, config->destAddr);

    /* Modify ssize and dsize */
    MODIFY_REG(tcd->TO.WORDVAL, (uint32_t)(EDMA_TCD_TO_SSIZE_M | EDMA_TCD_TO_DSIZE_M), \
               (config->srcTransferSize << EDMA_TCD_TO_SSIZE_S) | \
               (config->destTransferSize << EDMA_TCD_TO_DSIZE_S));

    /* Source address signed offset */
    mask = config->srcOffset & (uint16_t)EDMA_TCD_TO_SOFF_M;
    MODIFY_REG(tcd->TO.WORDVAL, EDMA_TCD_TO_SOFF_M, mask);

    /* Destination address signed offset */
    mask = config->destOffset & (uint16_t)EDMA_TCD_CITER_ELINKNO_DOFF_M;
    MODIFY_REG(tcd->CITER, EDMA_TCD_CITER_ELINKNO_DOFF_M, mask);

    /* Minor byte transfer count */
    if (edma->CR.BIT.EMLM == 0U)
    {
        WRITE_REG(tcd->NBYTES, config->minorLoopBytes);
    }
    else if ((tcd->NBYTES_MLOFFNO.BIT.SMLOE == 0U) && (tcd->NBYTES_MLOFFNO.BIT.DMLOE == 0U))
    {
        mask = (config->minorLoopBytes << EDMA_TCD_NBYTES_MLOFFNO_NBYTES_S) & EDMA_TCD_NBYTES_MLOFFNO_NBYTES_M;
        MODIFY_REG(tcd->NBYTES, EDMA_TCD_NBYTES_MLOFFNO_NBYTES_M, mask);
    }
    else
    {
        mask = (config->minorLoopBytes << EDMA_TCD_NBYTES_MLOFFYES_NBYTES_S) & EDMA_TCD_NBYTES_MLOFFYES_NBYTES_M;
        MODIFY_REG(tcd->NBYTES, EDMA_TCD_NBYTES_MLOFFYES_NBYTES_M, mask);
    }

    /* Current major iteration count */
    if (tcd->CITER_ELINKNO.BIT.ELINK == 0U)
    {
        mask = (config->majorLoopCounts << EDMA_TCD_CITER_ELINKNO_CITER_S) & EDMA_TCD_CITER_ELINKNO_CITER_M;
        MODIFY_REG(tcd->CITER, EDMA_TCD_CITER_ELINKNO_CITER_M, mask);
    }
    else
    {
        mask = (config->majorLoopCounts << EDMA_TCD_CITER_ELINKYES_CITER_S) & EDMA_TCD_CITER_ELINKYES_CITER_M;
        MODIFY_REG(tcd->CITER, EDMA_TCD_CITER_ELINKYES_CITER_M, mask);
    }

    /* Starting major iteration count */
    if (tcd->BITER_ELINKNO.BIT.ELINK == 0U)
    {
        mask = (config->majorLoopCounts << EDMA_TCD_BITER_ELINKNO_BITER_S) & EDMA_TCD_BITER_ELINKNO_BITER_M;
        MODIFY_REG(tcd->BITER, EDMA_TCD_BITER_ELINKNO_BITER_M, mask);
    }
    else
    {
        mask = (config->majorLoopCounts << EDMA_TCD_BITER_ELINKYES_BITER_S) & EDMA_TCD_BITER_ELINKYES_BITER_M;
        MODIFY_REG(tcd->BITER, EDMA_TCD_BITER_ELINKYES_BITER_M, mask);
    }

    WRITE_REG(tcd->SLAST.WORDVAL, (uint32_t)config->slast);
    WRITE_REG(tcd->DLASTSGA.WORDVAL, (uint32_t)config->dlast);

    /* Enable scatter/gather processing */
    if (nextTcd)
    {
        WRITE_REG(tcd->DLASTSGA.WORDVAL, (uint32_t)nextTcd);

        /* Enable Scatter/Gather Processing */
        SET_BIT(tcd->BITER, EDMA_TCD_BITER_ELINKNO_ESG_M);

        /* Clear DREQ */
        CLEAR_BIT(tcd->BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
    }
}

/**
  * \brief  Sets the channel link for the EDMA transfer.
  * \param  edma             The base address of the EDMA module.
  *                           - EDMA1: EDMA1 base address index
  * \param  channel          Channel num.
  *                           - uint8_t: 0x00 - 0x07
  * \param  type             Channel Link type.
  *                           This parameter can be any value of @ref EDMA_CHANNELLINKTYPE
  * \param  linkedChannel    Linked Channel num.
  *                           - uint8_t: 0x00 - 0x07
  */
static inline void EDMA_setChannelLink (EDMA_TypeDef *edma, uint32_t channel, \
                                        EDMA_ChannelLinkType type, uint32_t linkedChannel)
{
    if (type == EDMA_MINORLINK)
    {
        /* Enable minor link */
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_ELINK_M);
        SET_BIT(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKYES_ELINK_M);

        /* Set linked channel */
        MODIFY_REG(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKYES_LINKCH_M, \
                   (uint32_t)(linkedChannel << EDMA_TCD_CITER_ELINKYES_LINKCH_S));
        MODIFY_REG(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_LINKCH_M, \
                   (uint32_t)(linkedChannel << EDMA_TCD_BITER_ELINKYES_LINKCH_S));
    }
    else if (type == EDMA_MAJORLINK)
    {
        /* Enable major link */
        SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_MAJORELINK_M);

        /* Set major linked channel */
        MODIFY_REG(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_MAJORLINKCH_M, \
                   (uint32_t)(linkedChannel << EDMA_TCD_BITER_ELINKYES_MAJORLINKCH_S));
    }
    else
    {
        /* Disable minor link */
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_ELINK_M);
        CLEAR_BIT(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKYES_ELINK_M);

        /* Disable major link */
        CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKYES_MAJORELINK_M);
    }
}

/**
  * \brief  Configures the EDMA channel preemption feature.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPREEMPTIONCONFIG
  */
static inline void EDMA_setChannelPreemption (EDMA_TypeDef *edma, uint32_t channel, \
                                              const EDMA_ChannelPreemptionConfig *config)
{
    uint8_t cfg = 0;

    cfg = EDMA_DCHPRIn(edma, channel);

    if (config->enablePreemptAbility)
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_DPA3_M);
    }
    else
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_DPA3_M);
    }
    if (config->enableChannelPreemption)
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_ECP3_M);
    }
    else
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_ECP3_M);
    }

    EDMA_DCHPRIn(edma, channel) = cfg;
}

/**
  * \brief  Configures the EDMA channel preemption feature.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  type       EDMA channel priority configuration.
  *                     This parameter can be any value of @ref EDMA_CHANNELPREEMPTIONCONFIG
  */
static inline void EDMA_setChannelPreemptionConfig (EDMA_TypeDef *edma, uint32_t channel, \
                                                    const EDMA_ChannelPreemptionConfig *config)
{
    uint8_t cfg = 0;

    if (config->enablePreemptAbility)
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_DPA3_M);
    }
    else
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_DPA3_M);
    }
    if (config->enableChannelPreemption)
    {
        cfg |= (uint8_t)(EDMA_DCHPRI0_ECP3_M);
    }
    else
    {
        cfg &= (uint8_t)(~EDMA_DCHPRI0_ECP3_M);
    }
    cfg |= config->channelPriority;

    EDMA_DCHPRIn(edma, channel) = cfg;
}

/**
  * \brief  Configures the EDMA TCD Source Address Register and Destination Address Register.
  * \param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  * \param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x07
  * \param  destAddr    Destnationadddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  * \param  srcAddr     Source address.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr, uint32_t srcAddr);

/**
  * \brief  Configures the EDMA TCD Source Address Register.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * \param  srcAddr    Source address.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configTcdSrcAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t srcAddr);

/**
  * \brief  Configures the EDMA TCD Destination Address Register.
  * \param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  * \param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x07
  * \param  destAddr    Destnation adddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configTcdDestAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr);

/**
  * @brief  Configures the EDMA mode.
  * @param  dma              The base address of the EDMA module.
  *                           - EDMA1: EDMA1 base address index
  * @param  channel          Channel num.
  *                           - uint8_t: 0x00 - 0x07
  * @param  enableTrigger    Enable trigger.
  *                           - bool: 0 or 1
  * @param  enableDreq       Disable request.
  *                           - bool: 0 or 1
  */
extern void EDMA_configMode (EDMA_TypeDef *edma, uint8_t channel, bool enableTrigger, bool enableDreq);

/**
  * \brief  Configures the EDMA transfer structure configurations.
  * \param  edma          The base address of the EDMA module.
  *                        - EDMA1: EDMA1 base address index
  * \param  channel       Channel num.
  *                        - uint8_t: 0x00 - 0x07
  * \param  srcStep       Source data transfer size.
  *                        - This parameter can be any value of @ref EDMA_TransferSize
  * \param  destStep      Destination data transfer size.
  *                        - This parameter can be any value of @ref EDMA_TransferSize
  * \param  srcOffset     Source address signed offset.
  *                        - int16_t: -2^15 - 2^15-1
  * \param  destOffset    Destination address signed offset.
  *                        - int16_t: -2^15 - 2^15-1
  */
extern void EDMA_configTransfer (EDMA_TypeDef *edma, uint8_t channel, EDMA_TransferSize srcStep, \
                                 EDMA_TransferSize destStep, int16_t srcOffset, int16_t destOffset);

/**
  * \brief  Configures the EDMA TCD Minor Byte Count.
  * \param  edma           The base address of the EDMA module.
  *                         - EDMA1: EDMA1 base address index
  * \param  channel        Channel num.
  *                         - uint8_t: 0x00 - 0x07
  * \param  minor_bytes    Minor Byte Transfer Count.
  *                         - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configMinorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t minor_bytes);

/**
  * \brief  Configures the EDMA TCD Major Loop Count.
  * \param  edma           The base address of the EDMA module.
  *                         - EDMA1: EDMA1 base address index
  * \param  channel        Channel num.
  *                         - uint8_t: 0x00 - 0x07
  * \param  minor_bytes    Minor Byte Transfer Count.
  *                         - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
extern void EDMA_configMajorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t majorLoopCounts);

/**
  * \brief  Configures the EDMA TCD Last Source Address and Last Destination Address.
  * \param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * \param  channel    Channel num.
  * \param  slast      set the SLAST value.
  *                     - int32_t: -2^31 - 2^31-1
  * \param  dlast      set the DLAST value.
  *                     - int32_t: -2^31 - 2^31-1
  */
extern void EDMA_adjustAddr (EDMA_TypeDef *edma, uint8_t channel, int32_t slast, int32_t dlast);

/**
  * \brief  Configure the corresponding EDMA channel.
  * \param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  * \param  config    EDMA transfer config.
  *                    This parameter can be any value of @ref EDMA_TRANSFERCONFIG
  */
extern void EDMA_configChannel (EDMA_TypeDef *edma, EDMA_TransferConfig *config);

/**
  * \brief  Initialize the basic configuration of the EDMA peripheral.
  * \param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  * \param  config    EDMA common config.
  *                    This parameter can be any value of @ref EDMA_COMMONCONFIG
  */
extern void EDMA_configModule (EDMA_TypeDef *edma, const EDMA_CommonConfig *config);

/**
  * \brief  Initializes the EDMA peripheral.
  * \param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  */
extern void EDMA_initialize (EDMA_TypeDef *edma);


#ifdef __cplusplus
}
#endif


#endif /* __EDMA_H__ */
