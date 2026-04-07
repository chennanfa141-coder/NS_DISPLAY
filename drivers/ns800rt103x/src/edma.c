/**
  * @file       edma.c
  * @author     zhenght
  * @brief      Function file for NS800RT1xxx edma module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "edma.h"


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
  * @brief  Configures the EDMA TCD Source Address Register and Destination Address Register.
  * @param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  * @param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x07
  * @param  destAddr    Destnation adddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  * @param  srcAddr     Source address.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr, uint32_t srcAddr)
{
    WRITE_REG(edma->TCD[channel].SADDR.WORDVAL, srcAddr);
    WRITE_REG(edma->TCD[channel].DADDR.WORDVAL, destAddr);
}

/**
  * @brief  Configures the EDMA TCD Source Address Register.
  * @param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * @param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * @param  srcAddr    Source address.
  *                     - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configTcdSrcAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t srcAddr)
{
    WRITE_REG(edma->TCD[channel].SADDR.WORDVAL, srcAddr);
}

/**
  * @brief  Configures the EDMA TCD Destination Address Register.
  * @param  edma        The base address of the EDMA module.
  *                      - EDMA1: EDMA1 base address index
  * @param  channel     Channel num.
  *                      - uint8_t: 0x00 - 0x07
  * @param  destAddr    Destnation adddress.
  *                      - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configTcdDestAddresses (EDMA_TypeDef *edma, uint8_t channel, uint32_t destAddr)
{
    WRITE_REG(edma->TCD[channel].DADDR.WORDVAL, destAddr);
}

/**
  * @brief  Configures the EDMA mode.
  * @param  edma             The base address of the EDMA module.
  *                           - EDMA1: EDMA1 base address index
  * @param  channel          Channel num.
  *                           - uint8_t: 0x00 - 0x07
  * @param  enableTrigger    Enable trigger.
  *                           - bool: 0/1
  * @param  enableDreq       Disable request.
  *                           - bool: 0/1
  */
void EDMA_configMode (EDMA_TypeDef *edma, uint8_t channel, bool enableTrigger, bool enableDreq)
{
    if (enableTrigger == 0)
    {
        if (enableDreq)
        {
            SET_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
        }
        else
        {
            CLEAR_BIT(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_DREQ_M);
        }
    }
}

/**
  * @brief  Configures the EDMA transfer structure configurations.
  * @param  edma          The base address of the EDMA module.
  *                        - EDMA1: EDMA1 base address index
  * @param  channel       Channel num.
  *                        - uint8_t: 0x00 - 0x07
  * @param  srcStep       Source data transfer size.
  *                        - This parameter can be any value of @ref EDMA_TRANSFERSIZE
  * @param  destStep      Destination data transfer size.
  *                        - This parameter can be any value of @ref EDMA_TRANSFERSIZE
  * @param  srcOffset     Source address signed offset.
  *                        - int16_t: -2^15 - 2^15-1
  * @param  destOffset    Destination address signed offset.
  *                        - int16_t: -2^15 - 2^15-1
  */
void EDMA_configTransfer (EDMA_TypeDef *edma, uint8_t channel, EDMA_TransferSize srcStep, \
                         EDMA_TransferSize destStep, int16_t srcOffset, int16_t destOffset)
{
    uint16_t mask;

    MODIFY_REG(edma->TCD[channel].TO.WORDVAL, (EDMA_TCD_TO_DSIZE_S | EDMA_TCD_TO_SSIZE_M), \
               ((uint32_t)(srcStep << EDMA_TCD_TO_SSIZE_S)) | \
               ((uint32_t)(destStep << EDMA_TCD_TO_DSIZE_S)));

    /* Source address signed offset */
    mask = (uint16_t)(srcOffset & (uint16_t)EDMA_TCD_TO_SOFF_M);
    MODIFY_REG(edma->TCD[channel].TO.WORDVAL, (EDMA_TCD_TO_SOFF_M), (uint32_t)mask);

    /* Destination address signed offset */
    mask = (uint16_t)(destOffset & (uint16_t)EDMA_TCD_CITER_ELINKNO_DOFF_M);
    MODIFY_REG(edma->TCD[channel].CITER, EDMA_TCD_CITER_ELINKNO_DOFF_M, (uint32_t)mask);
}

/**
  * @brief  Configures the EDMA TCD Minor Byte Count.
  * @param  edma          The base address of the EDMA module.
  *                        - EDMA1: EDMA1 base address index
  * @param  channel       Channel num.
  *                        - uint8_t: 0x00 - 0x07
  * @param  minorBytes    Minor Byte Transfer Count.
  *                        - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configMinorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t minorBytes)
{
    /* Minor byte transfer count */
    WRITE_REG(edma->TCD[channel].NBYTES, minorBytes);
}

/**
  * @brief  Configures the EDMA TCD Major Loop Count.
  * @param  edma               The base address of the EDMA module.
  *                             - EDMA1: EDMA1 base address index
  * @param  channel            Channel num.
  *                             - uint8_t: 0x00 - 0x07
  * @param  majorLoopCounts    Major Loop Count.
  *                             - uint32_t: 0x00UL - 0xFFFFFFFFUL
  */
void EDMA_configMajorloop (EDMA_TypeDef *edma, uint8_t channel, uint32_t majorLoopCounts)
{
    /* Current major iteration count */
    MODIFY_REG(edma->TCD[channel].CITER, EDMA_TCD_BITER_ELINKNO_BITER_M, \
               (uint32_t)(majorLoopCounts << EDMA_TCD_BITER_ELINKNO_BITER_S));

    /* Starting major iteration count */
    MODIFY_REG(edma->TCD[channel].BITER, EDMA_TCD_BITER_ELINKNO_BITER_M, \
               (uint32_t)(majorLoopCounts << EDMA_TCD_CITER_ELINKNO_CITER_S));
}

/**
  * @brief  Configures the EDMA TCD Last Source Address and Last Destination Address.
  * @param  edma       The base address of the EDMA module.
  *                     - EDMA1: EDMA1 base address index
  * @param  channel    Channel num.
  *                     - uint8_t: 0x00 - 0x07
  * @param  slast      set the SLAST value.
  *                     - int32_t: -2^31 - 2^31-1
  * @param  dlast      set the DLAST value.
  *                     - int32_t: -2^31 - 2^31-1
  */
void EDMA_adjustAddr (EDMA_TypeDef *edma, uint8_t channel, int32_t slast, int32_t dlast)
{
    WRITE_REG(edma->TCD[channel].SLAST.WORDVAL, (uint32_t)slast);
    WRITE_REG(edma->TCD[channel].DLASTSGA.WORDVAL, (uint32_t)dlast);
}

/**
  * @brief  Configure the corresponding EDMA channel.
  * @param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  * @param  config    EDMA transfer config.
  *                    This parameter can be any value of @ref EDMA_TRANSFERCONFIG
  */
void EDMA_configChannel (EDMA_TypeDef *edma, EDMA_TransferConfig *config)
{
    if (config->enMajorInt)
    {
        /* Enable major int. */
        SET_BIT(edma->TCD[config->channel].BITER, EDMA_TCD_BITER_ELINKNO_INTMAJOR_M);
    }
    if (config->enErrInt)
    {
        /* Enable err int. */
        SET_BIT(edma->EEI.WORDVAL, (0x1UL << config->channel));
    }
    EDMA_configMode(edma, config->channel, config->enTrigger, config->enDreq);
    EDMA_configTcdTransfer(edma, (EDMA_TCD_TypeDef *)&(edma->TCD[config->channel]), config, (void *)0);
}

/**
  * @brief  Initialize the basic configuration of the EDMA peripheral.
  * @param  edma      The base address of the EDMA module.
  *                    - EDMA1: EDMA1 base address index
  * @param  config    EDMA common config.
  *                    This parameter can be any value of @ref EDMA_COMMONCONFIG
  */
void EDMA_configModule (EDMA_TypeDef *edma, const EDMA_CommonConfig *config)
{
    uint32_t tmpreg;

    tmpreg = edma->CR.WORDVAL;
    tmpreg &= ~(EDMA_CR_ERCA_M | EDMA_CR_HOE_M | EDMA_CR_CLM_M | EDMA_CR_EDBG_M | EDMA_CR_EMLM_M);
    if (config->enableRoundRobinChnArbitration)
    {
        tmpreg |= EDMA_CR_ERCA_M;
    }
    if (config->enableHaltOnError)
    {
        tmpreg |= EDMA_CR_HOE_M;
    }
    if (config->enableContinuousLinkMode)
    {
        tmpreg |= EDMA_CR_CLM_M;
    }
    if (config->enableDebugMode)
    {
        tmpreg |= EDMA_CR_EDBG_M;
    }
    if (config->enableEmlm)
    {
        tmpreg |= EDMA_CR_EMLM_M;
    }
    WRITE_REG(edma->CR.WORDVAL, tmpreg);
}

/**
  * @brief  Initializes the EDMA peripheral.
  * @param  edma   The base address of the EDMA module.
  *                 - EDMA1: EDMA1 base address index
  */
void EDMA_initialize (EDMA_TypeDef *edma)
{
    /* Init tcd zone */
    memset((void *)&(edma->TCD[0].SADDR), 0x00UL, 256UL);
}
