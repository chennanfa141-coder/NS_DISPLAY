/**
  * @file       mmath.h
  * @author     XuZhongxing
  * @brief      Header file for NS800RT1xxx MMATH module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __MMATH_H__
#define __MMATH_H__


#ifdef __cplusplus
extern "C" {
#endif


typedef float float32_t;


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup MMATH_EXPORTED_TYPES MMATH Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'MMATH' module.
  */

/** @defgroup MMATH_CP_CTRL_BIT MMATH CPCTRL group
  * @{
  * @brief  Macro definitions are used for CPCTRL bit set.
  */
#define MMATH_INV           (0UL << 2UL)              /*!< reciprocal */
#define MMATH_LN            (1UL << 2UL)              /*!< natural log */
#define MMATH_SQRT          (2UL << 2UL)              /*!< square-root */
#define MMATH_INVSQRT       (3UL << 2UL)              /*!< inverse square-root */
#define MMATH_ETOX          (4UL << 2UL)              /*!< natural exponent */
#define MMATH_ETONX         (5UL << 2UL)              /*!< natural exponent with negative parameter */
#define MMATH_DIV           (6UL << 2UL)              /*!< division */
#define MMATH_SIN           (0UL << 2UL)              /*!< trigonometric sine */
#define MMATH_COS           (1UL << 2UL)              /*!< trigonometric cosine */

#define CP_START            (1UL << 6UL)              /*!< start Calc operation */
#define CP_AUTOLOAD         (1UL << 11UL)             /*!< enable auto load calc result to register */
#define CP_AUTOWAIT         (1UL << 12UL)             /*!< enable AHB Bus auto wait */
#define COEFF_EN            (1UL << 13UL)             /*!< enable sine/cossine expand by m coeffcient */

#define MMATH_TRANS         (0UL)                     /*!< transform */
#define MMATH_TRIG          (1UL)                     /*!< trigonometric calc */

#define REGS_MRC_FLOAT32    (0UL << 24UL)             /*!< REGS_MRC float32 */
#define REGS_MRC_FIXEDPT    (16UL << 24UL)            /*!< REGS_MRC fixed point */

#define REGS_FLOAT32        (0UL << 16UL)             /*!< REGS float32 */
#define REGS_FIXEDPT        (16UL << 16UL)            /*!< REGS fixed point */

#define RSV_SEL_READMULTI   (0UL << 10UL)             /*!< MRC operate code : readmulti */
#define RSV_SEL_READADD     (1UL << 10UL)             /*!< MRC operate code : readadd */

#define CP_CORDIC           (1UL << 5UL)              /*!< Decode machine: cordic */
#define CP_MATH             (0UL << 5UL)              /*!< Decode machine: math */

#define CORDIC_ITER(x)      ((uint32_t)(x) << 2UL)    /*!< Decode opcode: cordic iter */
#define CORDIC_MIU(x)       ((uint32_t)(x) << 1UL)    /*!< Decode opcode: cordic MIU */
#define CORDIC_T(x)         ((uint32_t)(x) << 0UL)    /*!< Decode opcode: cordic T */


/**
  * @}
  */

/** @defgroup MMATH_CALC factor group
  * @{
  * @brief  Macro definitions are used for conversion.
  */
#define ATAN_FACTOR      (0.00000002340668927f)    /* atan function factor : PI/0x8000000*/
#define CORDIC_FACTOR    (134217728.0f)            /* atanh function factor : 0x8000000 */

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
 * \brief  Calc the trigonometric sine function for floating-point input.
 * \param  x       input value in radians
 *                  The parameter's range is (-INF, INF)
 * \return Returns the sine value: sin(x)
 *                  The return value's range is [-1, 1]
 */
static inline float32_t MMATH_sinF32 (float32_t x)
{
    float32_t result;

    WRITE_REG(MMATH->SINDATA.WORDVAL, *((uint32_t *)&(x)));

    result = *((float32_t *)&(MMATH->RDATA.WORDVAL));

    __asm volatile("" ::: "memory");

    return result;
}

/**
 * \brief  Calc the trigonometric cosine function for floating-point input.
 * \param  x       input value in radians
 *                  The parameter's range is (-INF, INF)
 * \return Returns the cosine value: cos(x)
 *                  The return value's range is [-1, 1]
 */
static inline float32_t MMATH_cosF32 (float32_t x)
{
    float32_t result;

    WRITE_REG(MMATH->COSDATA.WORDVAL, *((uint32_t *)&(x)));

    result = *((float32_t *)&(MMATH->RDATA.WORDVAL));

    __asm volatile("" ::: "memory");

    return result;
}

/**
 * \brief  Calc the trigonometric arc tangent value for floating-point input.
 * \param  y       floating point Y-axis input,
 *                  The parameter's range is [-16384.0, 16384.0]
 * \param  x       floating point X-axis input
 *                  The parameter's range is [-16384.0, 16384.0]
 * \return Returns the arc tangent value: atanf(y, x)
 *                  The return value's range is [-PI/2, PI/2]
 */
static inline float32_t MMATH_atanF32 (float32_t y, float32_t x)
{
    int32_t result;
    int32_t intY = (int32_t)(y * 0x10000);
    int32_t intX = (int32_t)(x * 0x10000);
    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | CP_START | CP_CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1));

    WRITE_REG(MMATH->WDATA0.WORDVAL, (uint32_t)intX);
    WRITE_REG(MMATH->WDATA1.WORDVAL, (uint32_t)intY);

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    result = READ_REG(MMATH->RDATA.WORDVAL);

    return (float32_t)(result * ATAN_FACTOR);
}

/**
 * \brief  Calc the trigonometric arc tangent function for floating-point input.
 * \param  y       floating point Y-axis input
 *                  The parameter's range is [-16384.0, 16384.0]
 * \param  x       floating point X-axis input
 *                  The parameter's range is [-16384.0, 16384.0]
 * \return Returns the arc tangent value: atan2f(y, x)
 *                  The return value's range is [-PI, PI]
 */
static inline float32_t MMATH_atan2F32 (float32_t y, float32_t x)
{
    int32_t result;
    int32_t intY = (int32_t)(y * 0x10000);
    int32_t intX = (int32_t)(x * 0x10000);
    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | CP_START | CP_CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1));

    WRITE_REG(MMATH->WDATA0.WORDVAL, (uint32_t)intX);
    WRITE_REG(MMATH->WDATA1.WORDVAL, (uint32_t)intY);

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    result = READ_REG(MMATH->RDATA.WORDVAL);

    if (intX < 0)
    {
        if (intY < 0)
        {
            result -= 0x08000000;
        }
        else
        {
            result += 0x08000000;
        }
    }

    return (float32_t)(result * ATAN_FACTOR);
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \return Returns arc tangent value: atan(y, x)
 *                  The return value's range is [-0x4000000, 0x3FFFFFF] stand for [-PI/2, PI/2]
 */
static inline int32_t MMATH_atanQ27 (int32_t y, int32_t x)
{
    int32_t result;

    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | CP_START | CP_CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1));

    WRITE_REG(MMATH->WDATA0.WORDVAL, (uint32_t)x);
    WRITE_REG(MMATH->WDATA1.WORDVAL, (uint32_t)y);

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    result = READ_REG(MMATH->RDATA.WORDVAL);

    return result;
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFFFFF, 0x7FFFFFF]
 * \return Returns arc tangent value: atan2(y, x)
 *                  The return value's range is [-0x8000000, 0x7FFFFFF] stand for [-PI, PI]
 */
static inline int32_t MMATH_atan2Q27 (int32_t y, int32_t x)
{
    int32_t result;

    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | CP_START | CP_CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1));

    WRITE_REG(MMATH->WDATA0.WORDVAL, (uint32_t)x);
    WRITE_REG(MMATH->WDATA1.WORDVAL, (uint32_t)y);

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    result = READ_REG(MMATH->RDATA.WORDVAL);

    if (x < 0)
    {
        if (y < 0)
        {
            result -= 0x08000000;
        }
        else
        {
            result += 0x08000000;
        }
    }

    return result;
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \return Returns arc tangent value: atan(y, x)
 *                  The return value's range is[-0x4000, 0x4000] stand for [-PI/2, PI/2]
 */
static inline int16_t MMATH_atanQ15 (int16_t y, int16_t x)
{
    int32_t result;
    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | CP_START | CP_CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1));

    WRITE_REG(MMATH->WDATA0.WORDVAL, (uint32_t)x);
    WRITE_REG(MMATH->WDATA1.WORDVAL, (uint32_t)y);

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    result = READ_REG(MMATH->RDATA.WORDVAL) >> 12;

    return (int16_t)result;
}

/**
 * \brief  Calc the trigonometric arc tangent value for fix-point input.
 * \param  y       fix point Y-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \param  x       fix point X-axis input
 *                  The parameter's range is [-0x7FFF, 0x7FFF]
 * \return Returns arc tangent value: atan2(y, x)
 *                  The return value's range is[-0x8000, 0x7FFF] stand for [-PI, PI]
 */
static inline int16_t MMATH_atan2Q15 (int16_t y, int16_t x)
{
    int32_t result;

    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | CP_START | CP_CORDIC | CORDIC_ITER(2) | CORDIC_MIU(0) | CORDIC_T(1));

    WRITE_REG(MMATH->WDATA0.WORDVAL, (uint32_t)x);
    WRITE_REG(MMATH->WDATA1.WORDVAL, (uint32_t)y);

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    result = READ_REG(MMATH->RDATA.WORDVAL) >> 12;

    if (x < 0)
    {
        if (y > 0)
        {
            result += 0x7FFF;
        }
        else
        {
            result -= 0x7FFF;
        }
    }

    return (int16_t)result;
}

/**
 * \brief  Calc the squre root value for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is [0, INF)
 * \return Returns squre root value: sqrt(x)
 *                  The return value's range is [0, INF)
 */
static inline float32_t MMATH_sqrtF32 (float32_t x)
{
    uint32_t ctrl = (REGS_MRC_FLOAT32 | REGS_FLOAT32 | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READMULTI | CP_START | MMATH_SQRT | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(MMATH->RDATA.WORDVAL));
}

/**
 * \brief  Calc the square root for fix-point input.
 * \param  x       fix-point data
 *                  The parameter's range is [0, 0x7FFFFFFF]
 * \return Returns square root value: sqrt(x), fix-point data
 *                  The return value's range is [0, 185364)
 */
static inline uint32_t MMATH_sqrtFixed (uint32_t x)
{
    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READMULTI | CP_START | MMATH_SQRT | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((uint32_t *)&(MMATH->RDATA.WORDVAL));
}

/**
 * \brief  Calc the reciprocal square root for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is [0, INF)
 * \return Returns reciprocal square root value: 1/sqrt(x)
 *                  The return value's range is [0, INF)
 */
static inline float32_t MMATH_invSqrtF32 (float32_t x)
{
    uint32_t ctrl = (REGS_MRC_FLOAT32 | REGS_FLOAT32 | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READMULTI | CP_START | MMATH_INVSQRT | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(MMATH->RDATA.WORDVAL));
}

/**
 * \brief  Calc the div value for floating-point input.
 * \param  x1      floating-point data
 *                  The parameter's range is (-INF, INF)
 * \param  x2      floating-point data
 *                  The parameter is not equal to zero
 * \return Returns div value: x1/x2
 *                  The return value's range is (-INF, INF)
 */
static inline float32_t MMATH_divF32 (float32_t x1, float32_t x2)
{
    uint32_t ctrl = (REGS_MRC_FLOAT32 | REGS_FLOAT32 | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READMULTI | CP_START | MMATH_DIV | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x2)));
    WRITE_REG(MMATH->WDATA1.WORDVAL, *((uint32_t *)&(x1)));

    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((float32_t *) &(MMATH->RDATA.WORDVAL));
}

/**
 * \brief  Calc reciprocal for floating-point input.
 * \param  x       floating-point data
 *                  The parameter is not equal to zero
 * \return Returns reciprocal value: 1/x
 *                  The return value's range is (-INF, INF)
 */
static inline float32_t MMATH_invF32 (float32_t x)
{
    uint32_t ctrl = (REGS_MRC_FLOAT32 | REGS_FLOAT32 | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READMULTI | CP_START | MMATH_INV | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(MMATH->RDATA.WORDVAL));
}

/**
 * \brief  Calc natural log for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is (0, INF)
 * \return Returns natural log value: ln(x)
 *                  The return value's range is (-INF, INF)
 */
static inline float32_t MMATH_lnF32 (float32_t x)
{
    uint32_t ctrl = (REGS_MRC_FLOAT32 | REGS_FLOAT32 | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READADD | CP_START | MMATH_LN | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(MMATH->RDATA.WORDVAL));
}

/**
 * \brief  Calc the nature exponential for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is (-INF, INF)
 * \return Returns nature exponential value: e^x
 *                  The return value's range is (0, INF)
 */
static inline float32_t MMATH_etoxF32 (float32_t x)
{
    uint32_t ctrl = (REGS_MRC_FLOAT32 | REGS_FLOAT32 | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READMULTI | CP_START | MMATH_ETOX | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(MMATH->RDATA.WORDVAL));
}

/**
 * \brief  Calc the nature exponential for floating-point input.
 * \param  x       floating-point data
 *                  The parameter's range is (-INF, INF)
 * \return Returns nature exponential value: e^(-x)
 *                  The return value's range is (0, INF)
 */
static inline float32_t MMATH_etonxF32 (float32_t x)
{
    uint32_t ctrl = (REGS_MRC_FLOAT32 | REGS_FLOAT32 | CP_AUTOWAIT | CP_AUTOLOAD | RSV_SEL_READMULTI | CP_START | MMATH_ETONX | MMATH_TRANS);

    WRITE_REG(MMATH->WDATA0.WORDVAL, *((uint32_t *)&(x)));
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    return *((float32_t *)&(MMATH->RDATA.WORDVAL));
}

/*!
 * \brief Calc the inverse tanh transformation value.
 * \param x        floating-point data
 *                  The parameter's range is (-0.806, 0.806).
 * \return Returns inverse tanh transformation: atanh(x)
 *                  The return value's range is [-1.118, 1.118] radians, this function
 *                  is not accurate out of range [-1.118, 1.118]
 */
static inline float32_t MMATH_atanhF32 (float32_t x)
{
    int32_t result;

    uint32_t ctrl = (REGS_MRC_FIXEDPT | REGS_FIXEDPT | CP_AUTOWAIT | CP_AUTOLOAD | CP_CORDIC | CP_START | CORDIC_ITER(2) | CORDIC_MIU(1) | CORDIC_T(1));

    WRITE_REG(MMATH->WDATA0.WORDVAL, (int32_t)(x*CORDIC_FACTOR));
    WRITE_REG(MMATH->WDATA1.WORDVAL, (int32_t)CORDIC_FACTOR);

    /* default iterate 24 times, user can change iterate times to 1,0(stand for 16 times, 8 times) */
    WRITE_REG(MMATH->CTRL.WORDVAL, ctrl);

    __asm volatile("" ::: "memory");

    result = READ_REG(MMATH->RDATA.WORDVAL);

    return (float32_t)(result / CORDIC_FACTOR);
}


#ifdef __cplusplus
}
#endif


#endif  /* __MMATH_H__ */
