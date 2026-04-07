/**
  * @file       dmamux.h
  * @author     zhenght
  * @brief      Header file for NS800RT1xxx dmamux module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __DMAMUX_H__
#define __DMAMUX_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup  DMAMUX_EXPORTED_TYPES DMAMUX Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'DMAMUX' module.
  */

/** @defgroup DMAMUX1_REQ DMAMUX Dmamux1 Req Source
  * @{.
  * @brief  Macro definitions about DMAMUX dmamux1 request source.
  *         Values that can be passed to DMAMUX_setSource() as the \e source parameter.
  */
typedef enum {
    DMAMUX1_ADCA1_REQ = 1U,          /*!< ADCA1 REQUEST */
    DMAMUX1_ADCA2_REQ,               /*!< ADCA2 REQUEST */
    DMAMUX1_ADCA3_REQ,               /*!< ADCA3 REQUEST */
    DMAMUX1_ADCA4_REQ,               /*!< ADCA4 REQUEST */
    DMAMUX1_ADCA5_REQ,               /*!< ADCA5 REQUEST */
    DMAMUX1_SPI1TX_REQ = 7U,         /*!< SPI1TX REQUEST */
    DMAMUX1_SPI1RX_REQ,              /*!< SPI1RX REQUEST */
    DMAMUX1_SPI2TX_REQ,              /*!< SPI2TX REQUEST */
    DMAMUX1_SPI2RX_REQ,              /*!< SPI2RX REQUEST */
    DMAMUX1_ADCC1_REQ,               /*!< ADCA1 REQUEST */
    DMAMUX1_ADCC2_REQ,               /*!< ADCA2 REQUEST */
    DMAMUX1_ADCC3_REQ,               /*!< ADCA3 REQUEST */
    DMAMUX1_ADCC4_REQ,               /*!< ADCA4 REQUEST */
    DMAMUX1_ADCC5_REQ,               /*!< ADCA5 REQUEST */
    DMAMUX1_EPWM1_SOCA_REQ,          /*!< EPWM1_SOCA REQUEST */
    DMAMUX1_EPWM2_SOCA_REQ,          /*!< EPWM2_SOCA REQUEST */
    DMAMUX1_EPWM3_SOCA_REQ,          /*!< EPWM3_SOCA REQUEST */
    DMAMUX1_EPWM4_SOCA_REQ,          /*!< EPWM4_SOCA REQUEST */
    DMAMUX1_EPWM5_SOCA_REQ,          /*!< EPWM5_SOCA REQUEST */
    DMAMUX1_EPWM6_SOCA_REQ,          /*!< EPWM6_SOCA REQUEST */
    DMAMUX1_EPWM7_SOCA_REQ,          /*!< EPWM7_SOCA REQUEST */
    DMAMUX1_EPWM1_SOCB_REQ = 24U,    /*!< EPWM1_SOCB REQUEST */
    DMAMUX1_EPWM2_SOCB_REQ,          /*!< EPWM2_SOCB REQUEST */
    DMAMUX1_EPWM3_SOCB_REQ,          /*!< EPWM3_SOCB REQUEST */
    DMAMUX1_EPWM4_SOCB_REQ,          /*!< EPWM4_SOCB REQUEST */
    DMAMUX1_EPWM5_SOCB_REQ,          /*!< EPWM5_SOCB REQUEST */
    DMAMUX1_EPWM6_SOCB_REQ,          /*!< EPWM6_SOCB REQUEST */
    DMAMUX1_EPWM7_SOCB_REQ,          /*!< EPWM7_SOCB REQUEST */
    DMAMUX1_ECAP1_REQ = 32U,         /*!< ECAP1 REQUEST */
    DMAMUX1_ECAP2_REQ,               /*!< ECAP2 REQUEST */
    DMAMUX1_ECAP3_REQ,               /*!< ECAP3 REQUEST */
    DMAMUX1_EPG_REQ,                 /*!< EPG  REQUEST */
    DMAMUX1_I2C1_TX_REQ,             /*!< I2C1 TX REQUEST */
    DMAMUX1_I2C1_RX_REQ,             /*!< I2C1 RX REQUEST */
    DMAMUX1_UART1_TX_REQ = 42U,      /*!< UART1 TX REQUEST */
    DMAMUX1_UART1_RX_REQ = 45U,      /*!< UART1 RX REQUEST */
    DMAMUX1_XINT1_REQ = 48U,         /*!< XINT1 REQUEST */
    DMAMUX1_XINT2_REQ,               /*!< XINT2 REQUEST */
    DMAMUX1_XINT3_REQ,               /*!< XINT3 REQUEST */
    DMAMUX1_XINT4_REQ,               /*!< XINT4 REQUEST */
    DMAMUX1_XINT5_REQ,               /*!< XINT5 REQUEST */
    DMAMUX1_LIN1_TX_REQ = 55U,       /*!< LIN1 TX REQUEST */
    DMAMUX1_LIN1_RX_REQ,             /*!< LIN1 RX REQUEST */
    DMAMUX1_CAN1_REQ                 /*!< CAN1 REQUEST */
} DMAMUX1_Req;

/**
  * @}
  */

/** @defgroup DMAMUX_CHCONFIG DMAMUX Channel Configuration
  * @{
  * @brief  Macro definitions about the bit fields in the DMAMUX channel configuration register definition.
  */
#define DMAMUX_CHCONFIG_MASK    (DMAMUX_CHCONFIG_EN_M | DMAMUX_CHCONFIG_TRIG_M | \
                                 DMAMUX_CHCONFIG_ALWAYSON_M | DMAMUX_CHCONFIG_SOURCE_M)    /*!< CHCONFIG byte Mask */

/**
  * @}
  */

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
 * \brief  Enables the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 */
static inline void DMAMUX_enableChannel (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    SET_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_EN_M);
}

/**
 * \brief  Disable the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 */
static inline void DMAMUX_disableChannel (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_EN_M);
}

/**
 * \brief  Enable the DMAMUX trigger function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 */
static inline void DMAMUX_enableTrigger (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    SET_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_TRIG_M);
}

/**
 * \brief  Disable the DMAMUX trigger function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 */
static inline void DMAMUX_disableTrigger (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_TRIG_M);
}

/**
 * \brief  Enable the DMAMUX always-on function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 */
static inline void DMAMUX_enableAlwaysOn (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    SET_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_ALWAYSON_M);
}

/**
 * \brief  Disable the DMAMUX always-on function.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 */
static inline void DMAMUX_disableAlwaysOn (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_ALWAYSON_M);
}

/**
 * \brief  Reset the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 * \param  source     SOURCE specifies which DMA source.
 *                     This parameter can be any value of @ref DMAMUX1_REQ
 */
static inline void DMAMUX_setSource (DMAMUX_TypeDef *dmamux, uint8_t channel, uint8_t source)
{
    MODIFY_REG(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_SOURCE_M, source);
}

/**
 * \brief  Reset the DMAMUX all channel.
 * \param  dmamux    The base address of the DMAMUX module.
 *                    - DMAMUX1: DMAMUX1 base address index
 */
static inline void DMAMUX_resetAllChannel (DMAMUX_TypeDef *dmamux)
{
    for (uint32_t channel = 0; channel < 8; channel ++)
    {
        WRITE_REG(dmamux->CHCONFIG[channel].WORDVAL, 0UL);
    }
}

/**
 * \brief  Reset the DMAMUX channel.
 * \param  dmamux     The base address of the DMAMUX module.
 *                     - DMAMUX1: DMAMUX1 base address index
 * \param  channel    Channel num.
 *                     - uint8_t: channel num is range from 0 to 7
 */
static inline void DMAMUX_resetChannel (DMAMUX_TypeDef *dmamux, uint8_t channel)
{
    CLEAR_BIT(dmamux->CHCONFIG[channel].WORDVAL, DMAMUX_CHCONFIG_MASK);
}

/**
 * \brief  Initializes the DMAMUX peripheral.
 * \param  dmamux    The base address of the DMAMUX module.
 *                    - DMAMUX1: DMAMUX1 base address index
 */
extern void DMAMUX_configModule (DMAMUX_TypeDef *dmamux);


#ifdef __cplusplus
}
#endif


#endif /* __DMAMUX_H__ */
