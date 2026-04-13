/**
  * @file       spi.c
  * @author     zhoukai
  * @brief      Function file for NS800RT1xxx spi module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#include "spi.h"


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
 * @brief  SPI set config
 * @param  spi          SPI pointer to a SPI_TypeDef structure
 *                       - SPI1: SPI1 base address index
 *                       - SPI2: SPI2 base address index
 * @param  protocol     SPI transfer protocol
 *                       This parameter can be any value of @ref SPI_TRANSFERPROTOCOL
 * @param  mode         SPI Work mode
 *                       This parameter can be any value of @ref SPI_MODE
 * @param  commmode     SPI Communication mode
 *                       This parameter can be any value of @ref SPI_COMMMODE
 * @param  bitRate      SPI Transfer bitRate
 *                       This parameter is an unsigned integer that is greater
 *                       than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 * @param  dataWidth    SPI transfer data width
 *                       This parameter can be any value of @ref SPI_BitWidth_t
 * @return returned SPI config status
 *                       This parameter is an unsigned integer which means 
 *                       spi init config set failed unless it equal to 0UL.
 */
uint32_t SPI_setConfig (SPI_TypeDef *spi, SPI_TransferProtocol protocol, SPI_Mode mode, 
                        SPI_CommMode commmode, uint32_t bitRate, SPI_BitWidth dataWidth)
{
    uint32_t config_status = 0;
    /* SPI disable */
    SPI_disableModule(spi);
    SPI_resetFIFO(spi);

    WRITE_REG(spi->SPCR1.WORDVAL, (spi->SPCR1.WORDVAL & ~(SPI_SPCR1_MSTR_M | SPI_SPCR1_TXMD_M)) | \
              (mode << SPI_SPCR1_MSTR_S) | (commmode << SPI_SPCR1_TXMD_S));

    WRITE_REG(spi->SPCMD0.WORDVAL, (spi->SPCMD0.WORDVAL & ~(SPI_SPCMD0_CPHA_M | SPI_SPCMD0_CPOL_M | SPI_SPCMD0_SPB_M)) | \
              (protocol << SPI_SPCMD0_CPHA_S) | (dataWidth << SPI_SPCMD0_SPB_S));
    
    /* Set the baudrate. */
    config_status = SPI_setBaudRate(spi, bitRate);

    return config_status;
}

/**
 * @brief  SPI set baudrate
 * @param  spi         SPI pointer to a SPI_TypeDef structure
 *                      - SPI1: SPI1 base address index
 *                      - SPI2: SPI2 base address index
 * @param  bitRate     SPI bitrate
 *                      This parameter is an unsigned integer that is greater
 *                      than or equal to 0x0UL and less than or equal to lspclkHz divided by 2
 * @return returned spi baudrate status
 *                      This parameter is an unsigned integer which means 
 *                      spi baudrate set failed unless it equal to 0UL.
 */
uint32_t SPI_setBaudRate (SPI_TypeDef *spi, uint32_t bitRate)
{
    uint32_t spr = 0UL;
    uint32_t brdv = 0UL;

    /* SPI disable */
    SPI_disableModule(spi);

    /* Calculate the clock.*/
    uint32_t desired_divider = RCC_getPclk2Frequency() / bitRate;
    if (desired_divider > SPI_CLK_MAX_DIV)
    {
        return 1;
    }

    if (desired_divider < SPI_CLK_MIN_DIV)
    {
        /* Configure max bitrate (SPI_CLK / 2) */
        brdv = 0;
        spr = 0;
    }
    else
    {
        uint8_t i;
        for (i = 0; i < 4; i++)
        {
            if (desired_divider <= (SPI_CLK_N_DIV_MULTIPLIER << i))
            {
                break;
            }
        }

        brdv = i & 0x03U;

        uint32_t spbr_divisor = (2U * (1U << i));
        spr = (uint8_t) ((desired_divider / spbr_divisor) - 1U) & 0xFFUL;
    }

    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPR_M, (spr << SPI_SPCR3_SPR_S));
    MODIFY_REG(spi->SPCMD0.WORDVAL, SPI_SPCMD0_BRDV_M, (brdv << SPI_SPCMD0_BRDV_S));

    return 0;
}

/**
 * \brief  SPI enable interrupt
 * \param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 * \param  cmd_len    SPI cmnd length
 *                     This parameter can be any value of @ref SPI_CmndSequence
 */
extern void SPI_configMultiCmnds (SPI_TypeDef *spi, SPI_CmndSequence cmd_len)
{
    if(cmd_len == SPI_CMND_SEQUENCE_0_0)
    {
        return;
    }
    
    if(spi->SPCR1.BIT.MSTR == 1 && spi->SPCR1.BIT.SPE == 1)
    {
        while(spi->SPSR.BIT.IDLNF  != 0)
        {
        }
    }

    /* SPI disable */
    SPI_disableModule(spi);
    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPSLN_M, (cmd_len << SPI_SPCR3_SPSLN_S));

    volatile uint32_t *base = &spi->SPCMD0.WORDVAL;
    for(uint8_t i = SPI_CMND_SEQUENCE_0_1; i <= cmd_len; i++)
    {
        WRITE_REG(base[i], base[0]);
    }
}

/**
 * \brief  SPI enable Multi-cmnds into Burst Mode
 * \param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 * \param  cmd_len    SPI cmnd length
 *                     This parameter can be any value of @ref SPI_CmndSequence
 */
extern void SPI_enableBurstMode (SPI_TypeDef *spi, SPI_CmndSequence cmd_len)
{
    if(spi->SPCR1.BIT.MSTR == 1 && spi->SPCR1.BIT.SPE == 1)
    {
        while(spi->SPSR.BIT.IDLNF  != 0)
        {
        }
    }

    volatile uint32_t *base = &spi->SPCMD0.WORDVAL;
    /* SPI disable */
    SPI_disableModule(spi);
    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPSLN_M, (cmd_len << SPI_SPCR3_SPSLN_S));

    for(uint8_t i = SPI_CMND_SEQUENCE_0_0; i < cmd_len; i++)
    {
        SET_BIT(base[i], SPI_SPCMD0_SSLKP_M);
    }

    CLEAR_BIT(base[cmd_len], SPI_SPCMD0_SSLKP_M);
}

/**
 * \brief  SPI disable Burst Mode
 * \param  spi        SPI pointer to a SPI_TypeDef structure
 *                     - SPI1: SPI1 base address index
 *                     - SPI2: SPI2 base address index
 * \param  cmd_len    SPI cmnd length
 *                     This parameter can be any value of @ref SPI_CmndSequence
 */
extern void SPI_disableBurstMode (SPI_TypeDef *spi, SPI_CmndSequence cmd_len)
{
    if(spi->SPCR1.BIT.MSTR == 1 && spi->SPCR1.BIT.SPE == 1)
    {
        while(spi->SPSR.BIT.IDLNF  != 0)
        {
        }
    }

    volatile uint32_t *base = &spi->SPCMD0.WORDVAL;
    /* SPI disable */
    SPI_disableModule(spi);
    MODIFY_REG(spi->SPCR3.WORDVAL, SPI_SPCR3_SPSLN_M, (cmd_len << SPI_SPCR3_SPSLN_S));

    for(uint8_t i = SPI_CMND_SEQUENCE_0_0; i <= cmd_len; i++)
    {
        CLEAR_BIT(base[i], SPI_SPCMD0_SSLKP_M);
    }
}


/**
 * @brief  SPI enable interrupt
 * @param  spi         SPI pointer to a SPI_TypeDef structure
 *                      - SPI1: SPI1 base address index
 *                      - SPI2: SPI2 base address index
 * @param  intFlags    SPI interrupt flags
 *                      This parameter is the gather of SPI interrupt source,
 *                      interrupt source can be any value of SPI interrupt type
 */
void SPI_enableInterrupt (SPI_TypeDef *spi, uint32_t intFlags)
{
    /* Enable the specified non-FIFO interrupts.*/
    if ((intFlags & SPI_INT_RX_DATA_TX_EMPTY) != 0UL)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPTIE_M | SPI_SPCR1_SPRIE_M);
    }

    if ((intFlags & SPI_INT_TXEF) != 0UL)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPTIE_M);
    }

    if ((intFlags & SPI_INT_RXFF) != 0UL)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPRIE_M);
    }

    if ((intFlags & SPI_INT_RXFF_OVERFLOW) != 0UL)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPEIE_M);
    }

    if ((intFlags & SPI_INT_CEND) != 0UL)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_CENDIE_M);
    }

    if ((intFlags & SPI_INT_IDLE) != 0UL)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPIIE_M);
    }

    if ((intFlags & SPI_INT_OTHER_ERROR) != 0UL)
    {
        SET_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPEIE_M | SPI_SPCR1_MODFEN_M);
    }
}

/**
 * @brief  SPI disable interrupt
 * @param  spi         SPI pointer to a SPI_TypeDef structure
 *                      - SPI1: SPI1 base address index
 *                      - SPI2: SPI2 base address index
 * @param  intFlags    SPI interrupt flags
 *                      This parameter is the gather of SPI interrupt source,
 *                      interrupt source can be any value of SPI interrupt type
 */
void SPI_disableInterrupt (SPI_TypeDef *spi, uint32_t intFlags)
{
    if ((intFlags & SPI_INT_RX_DATA_TX_EMPTY) != 0UL)
    {
        CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPTIE_M | SPI_SPCR1_SPRIE_M);
    }

    if ((intFlags & SPI_INT_RXFF_OVERFLOW) != 0UL)
    {
        CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPEIE_M);
    }

    if ((intFlags & SPI_INT_TXEF) != 0UL)
    {
        CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPTIE_M);
    }

    if ((intFlags & SPI_INT_RXFF) != 0UL)
    {
        CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPRIE_M);
    }

    if ((intFlags & SPI_INT_CEND) != 0UL)
    {
        CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_CENDIE_M);
    }

    if ((intFlags & SPI_INT_IDLE) != 0UL)
    {
        CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPIIE_M);
    }

    if ((intFlags & SPI_INT_OTHER_ERROR) != 0UL)
    {
        CLEAR_BIT(spi->SPCR1.WORDVAL, SPI_SPCR1_SPEIE_M | SPI_SPCR1_MODFEN_M);
    }
}

/**
 * @brief  SPI get interrupt status
 * @param  spi    SPI pointer to a SPI_TypeDef structure
 *                 - SPI1: SPI1 base address index
 *                 - SPI2: SPI2 base address index
 * @return returned spi interrupt status
 *                 This parameter is an unsigned integer that is greater
 *                 than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
uint32_t SPI_getInterruptStatus (SPI_TypeDef *spi)
{
    uint32_t temp = 0UL;

    if ((READ_REG(spi->SPSR.WORDVAL) & (SPI_SPRF_FLAG | SPI_SPTEF_FLAG)) == (SPI_SPRF_FLAG | SPI_SPTEF_FLAG))
    {
        temp |= SPI_INT_RX_DATA_TX_EMPTY;
    }

    if ((READ_REG(spi->SPSR.WORDVAL) & SPI_SPTEF_FLAG) != 0UL)
    {
        temp |= SPI_INT_TXEF;
    }

    if ((READ_REG(spi->SPSR.WORDVAL) & SPI_SPRF_FLAG) != 0UL)
    {
        temp |= SPI_INT_RXFF;
    }

    if ((READ_REG(spi->SPSR.WORDVAL) & SPI_CENDF_FLAG) != 0UL)
    {
        temp |= SPI_INT_CEND;
    }

    if ((READ_REG(spi->SPSR.WORDVAL) & SPI_OVRF_FLAG) != 0UL)
    {
        temp |= SPI_INT_RXFF_OVERFLOW;
    }

    if ((READ_REG(spi->SPSR.WORDVAL) & (SPI_MODF_FLAG | SPI_PERF_FLAG | SPI_UDRF_FLAG)) != 0UL)
    {
        temp |= SPI_INT_OTHER_ERROR;
    }

    return (temp);
}

/**
 * @brief  SPI clear interrupt status
 * @param  spi         SPI pointer to a SPI_TypeDef structure
 *                      - SPI1: SPI1 base address index
 *                      - SPI2: SPI2 base address index
 * @param  intFlags    SPI interrupt flags
 *                      This parameter is an unsigned integer that is greater
 *                      than or equal to 0x0UL and less than or equal to 0xFFUL
 */
void SPI_clearInterruptStatus (SPI_TypeDef *spi, uint32_t intFlags)
{
    /* Clear the specified non-FIFO interrupt sources */
    if ((intFlags & SPI_INT_RX_DATA_TX_EMPTY) != 0UL)
    {
        SET_BIT(spi->SPSCR.WORDVAL, SPI_SPTEFC_FLAG | SPI_SPRFC_FLAG);
    }

    if ((intFlags & SPI_INT_RXFF_OVERFLOW) != 0UL)
    {
        SET_BIT(spi->SPSCR.WORDVAL, SPI_OVRFC_FLAG);
    }

    if ((intFlags & SPI_INT_TXEF) != 0UL)
    {
        SET_BIT(spi->SPSCR.WORDVAL, SPI_SPTEFC_FLAG);
    }

    if ((intFlags & SPI_INT_RXFF) != 0UL)
    {
        SET_BIT(spi->SPSCR.WORDVAL, SPI_SPRFC_FLAG);
    }

    if ((intFlags & SPI_INT_CEND) != 0UL)
    {
        SET_BIT(spi->SPSCR.WORDVAL, SPI_CENDFC_FLAG);
    }

    if ((intFlags & SPI_INT_OTHER_ERROR) != 0UL)
    {
        SET_BIT(spi->SPSCR.WORDVAL, SPI_OVRFC_FLAG | SPI_PERFC_FLAG | SPI_UDRFC_FLAG | SPI_MODFC_FLAG);
    }
}

/**
 * @brief  SPI polling fifo transaction
 * @param  spi           SPI pointer to a SPI_TypeDef structure
 *                        - SPI1: SPI1 base address index
 *                        - SPI2: SPI2 base address index
 * @param  *pTxBuffer    SPI Tx Buffer pointer
 * @param  *pRxBuffer    SPI Rx Buffer pointer
 * @param  numOfWords    SPI Transfer data length
 *                        This parameter is an unsigned integer that is greater
 *                        than or equal to 0x0UL and less than or equal to 0xFFFFFFFFUL
 */
void SPI_pollingFIFOTransaction (SPI_TypeDef *spi, uint32_t *pTxBuffer,\
                                  uint32_t *pRxBuffer, uint32_t numOfWords)                           
{
    /* Determine the number of 16-level words from number of words to be */
    /* transmitted / received */
    uint32_t numOfSixteenWords = numOfWords / (uint32_t)SPI_FIFO_TXEMPTY;

    /* Determine the number of remaining words from number of words to be */
    /* transmitted / received */
    uint32_t remainingWords = numOfWords % (uint32_t)SPI_FIFO_TXEMPTY;

    uint32_t count = 0UL;
    uint32_t i = 0UL;
    uint32_t txBuffer_pos = 0UL;
    uint32_t rxBuffer_pos = 0UL;

    /* Number of transactions is based on numOfSixteenWords */
    /* Each transaction will transmit and receive 16 words. */
    while (count < numOfSixteenWords)
    {
        /* Fill-up the SPI Transmit FIFO buffers */
        for (i = 1UL; i <= (uint32_t)SPI_FIFO_TXEMPTY; i++)
        {
            SPI_writeDataBlockingFIFO(spi, pTxBuffer[txBuffer_pos]);
            txBuffer_pos++;
        }

        /* Wait till SPI Receive FIFO buffer is full */
        while (SPI_getRxFIFOStatus(spi) < SPI_FIFO_RXFULL)
        {
        }

        /* Read the SPI Receive FIFO buffers */
        for (i = 1UL; i <= (uint32_t)SPI_FIFO_RXFULL; i++)
        {
            if (pRxBuffer == NULL)
            {
                SPI_readDataBlockingFIFO(spi);
            }
            else
            {
                pRxBuffer[rxBuffer_pos] = SPI_readDataBlockingFIFO(spi);
                rxBuffer_pos++;
            }
        }
        count++;
    }

    /* Number of transactions is based on remainingWords */
    for (i = 0UL; i < remainingWords; i++)
    {
        SPI_writeDataBlockingFIFO(spi, pTxBuffer[txBuffer_pos]);
        txBuffer_pos++;
    }

    /* Wait till SPI Receive FIFO buffer remaining words */
    while ((uint32_t)SPI_getRxFIFOStatus(spi) < remainingWords)
    {
    }

    /* Read the SPI Receive FIFO buffers */
    for (i = 0UL; i < remainingWords; i++)
    {
        if (pRxBuffer == NULL)
        {
            SPI_readDataBlockingFIFO(spi);
        }
        else
        {
            pRxBuffer[rxBuffer_pos] = SPI_readDataBlockingFIFO(spi);
            rxBuffer_pos++;
        }
    }
}
