/**
  * @file       rcc.h
  * @author     Jun.Yang, Alex-J
  * @brief      Header file for NS800RT1xxx rcc module.
  *
  * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
  * All rights reserved.</center></h2>
  */
#ifndef __RCC_H__
#define __RCC_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "NS800RTxxxx.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** @defgroup RCC_EXPORTED_TYPES RCC Exported Types
  * @{
  * @brief  Macro definitions are used with all files publicly about 'RCC' module.
  */

/** @defgroup RCC_FUNON RCC FUNCTIONAL STATE
  * @{
  * @brief  Functional State.
  */
typedef enum {
    RCC_FUN_OFF = 0U,    /*!< Disable the function */
    RCC_FUN_ON           /*!< Enable the function */
} RCC_FunOn;

/**
  * @}
  */

// /** @defgroup RCC_MCOSEL RCC MCO Selection
//   * @{
//   * @brief  Macro definitions for selecting the MCO output source.
//   */
// typedef enum {
//     RCC_MCO1 = 0U,    /*!< MCO1 output source */
//     RCC_MCO2          /*!< MCO2 output source */
// } RCC_McoSel;

/**
  * @}
  */

/** @defgroup RCC_HXTLBYPASSSEL RCC HXTL Bypass Selection
  * @{
  * @brief  Macro definitions for selecting the HXTL mode.
  */
typedef enum {
    RCC_HXTL_NORMAL = 0U,    /*!< Normal state of the crystal oscillator */
    RCC_HXTL_BYPASS          /*!< Bypass state of the crystal oscillator */
} RCC_HxtlBypassSel;

/**
  * @}
  */

/** @defgroup RCC_MCOSOURCESEL RCC MCO Output Clock Source Selection
  * @{
  * @brief  Macro definitions for selecting the MCO output clock source.
  */
typedef enum {
    RCC_MCO_SEL_SYSCLK = 0U,    /*!< Selects system clock as MCO output */
    RCC_MCO_SEL_HXTL,           /*!< Selects high-speed external crystal oscillator as MCO output */
    RCC_MCO_SEL_LIRC,           /*!< Selects low-speed internal RC oscillator as MCO output */
    RCC_MCO_SEL_MIRC1,          /*!< Selects Medium-Speed internal RC oscillator 1 as MCO output */
    RCC_MCO_SEL_MIRC2,          /*!< Selects Medium-Speed internal RC oscillator 2 as MCO output */
    RCC_MCO_SEL_PLL,            /*!< Selects PLL as MCO output */
    RCC_MCO_SEL_NONE            /*!< No clock selected for MCO output */
} RCC_McoSourceSel;

/**
  * @}
  */

/** @defgroup RCC_MCODIVSEL RCC MCO Clock Division Selection
  * @{
  * @brief  Macro definitions about MCO clock division.
  */
typedef enum {
    RCC_MCO_DIV_1 = 0U,    /*!< No division (divide by 1) */
    RCC_MCO_DIV_2,         /*!< Divide by 2 */
    RCC_MCO_DIV_4,         /*!< Divide by 4 */
    RCC_MCO_DIV_6,         /*!< Divide by 6 */
    RCC_MCO_DIV_8,         /*!< Divide by 8 */
    RCC_MCO_DIV_10,        /*!< Divide by 10 */
    RCC_MCO_DIV_12,        /*!< Divide by 12 */
    RCC_MCO_DIV_14,        /*!< Divide by 14 */
    RCC_MCO_DIV_16,        /*!< Divide by 16 */
    RCC_MCO_DIV_18,        /*!< Divide by 18 */
    RCC_MCO_DIV_20,        /*!< Divide by 20 */
    RCC_MCO_DIV_22,        /*!< Divide by 22 */
    RCC_MCO_DIV_24,        /*!< Divide by 24 */
    RCC_MCO_DIV_26,        /*!< Divide by 26 */
    RCC_MCO_DIV_28,        /*!< Divide by 28 */
    RCC_MCO_DIV_30,        /*!< Divide by 30 */
    RCC_MCO_DIV_32,        /*!< Divide by 32 */
    RCC_MCO_DIV_34,        /*!< Divide by 34 */
    RCC_MCO_DIV_36,        /*!< Divide by 36 */
    RCC_MCO_DIV_38,        /*!< Divide by 38 */
    RCC_MCO_DIV_40,        /*!< Divide by 40 */
    RCC_MCO_DIV_42,        /*!< Divide by 42 */
    RCC_MCO_DIV_44,        /*!< Divide by 44 */
    RCC_MCO_DIV_46,        /*!< Divide by 46 */
    RCC_MCO_DIV_48,        /*!< Divide by 48 */
    RCC_MCO_DIV_50,        /*!< Divide by 50 */
    RCC_MCO_DIV_52,        /*!< Divide by 52 */
    RCC_MCO_DIV_54,        /*!< Divide by 54 */
    RCC_MCO_DIV_56,        /*!< Divide by 56 */
    RCC_MCO_DIV_58,        /*!< Divide by 58 */
    RCC_MCO_DIV_60,        /*!< Divide by 60 */
    RCC_MCO_DIV_62,        /*!< Divide by 62 */
    RCC_MCO_DIV_64,        /*!< Divide by 64 */
    RCC_MCO_DIV_66,        /*!< Divide by 66 */
    RCC_MCO_DIV_68,        /*!< Divide by 68 */
    RCC_MCO_DIV_70,        /*!< Divide by 70 */
    RCC_MCO_DIV_72,        /*!< Divide by 72 */
    RCC_MCO_DIV_74,        /*!< Divide by 74 */
    RCC_MCO_DIV_76,        /*!< Divide by 76 */
    RCC_MCO_DIV_78,        /*!< Divide by 78 */
    RCC_MCO_DIV_80,        /*!< Divide by 80 */
    RCC_MCO_DIV_82,        /*!< Divide by 82 */
    RCC_MCO_DIV_84,        /*!< Divide by 84 */
    RCC_MCO_DIV_86,        /*!< Divide by 86 */
    RCC_MCO_DIV_88,        /*!< Divide by 88 */
    RCC_MCO_DIV_90,        /*!< Divide by 90 */
    RCC_MCO_DIV_92,        /*!< Divide by 92 */
    RCC_MCO_DIV_94,        /*!< Divide by 94 */
    RCC_MCO_DIV_96,        /*!< Divide by 96 */
    RCC_MCO_DIV_98,        /*!< Divide by 98 */
    RCC_MCO_DIV_100,       /*!< Divide by 100 */
    RCC_MCO_DIV_102,       /*!< Divide by 102 */
    RCC_MCO_DIV_104,       /*!< Divide by 104 */
    RCC_MCO_DIV_106,       /*!< Divide by 106 */
    RCC_MCO_DIV_108,       /*!< Divide by 108 */
    RCC_MCO_DIV_110,       /*!< Divide by 110 */
    RCC_MCO_DIV_112,       /*!< Divide by 112 */
    RCC_MCO_DIV_114,       /*!< Divide by 114 */
    RCC_MCO_DIV_116,       /*!< Divide by 116 */
    RCC_MCO_DIV_118,       /*!< Divide by 118 */
    RCC_MCO_DIV_120,       /*!< Divide by 120 */
    RCC_MCO_DIV_122,       /*!< Divide by 122 */
    RCC_MCO_DIV_124,       /*!< Divide by 124 */
    RCC_MCO_DIV_126,       /*!< Divide by 126 */
    RCC_MCO_DIV_128,       /*!< Divide by 128 */
    RCC_MCO_DIV_130,       /*!< Divide by 130 */
    RCC_MCO_DIV_132,       /*!< Divide by 132 */
    RCC_MCO_DIV_134,       /*!< Divide by 134 */
    RCC_MCO_DIV_136,       /*!< Divide by 136 */
    RCC_MCO_DIV_138,       /*!< Divide by 138 */
    RCC_MCO_DIV_140,       /*!< Divide by 140 */
    RCC_MCO_DIV_142,       /*!< Divide by 142 */
    RCC_MCO_DIV_144,       /*!< Divide by 144 */
    RCC_MCO_DIV_146,       /*!< Divide by 146 */
    RCC_MCO_DIV_148,       /*!< Divide by 148 */
    RCC_MCO_DIV_150,       /*!< Divide by 150 */
    RCC_MCO_DIV_152,       /*!< Divide by 152 */
    RCC_MCO_DIV_154,       /*!< Divide by 154 */
    RCC_MCO_DIV_156,       /*!< Divide by 156 */
    RCC_MCO_DIV_158,       /*!< Divide by 158 */
    RCC_MCO_DIV_160,       /*!< Divide by 160 */
    RCC_MCO_DIV_162,       /*!< Divide by 162 */
    RCC_MCO_DIV_164,       /*!< Divide by 164 */
    RCC_MCO_DIV_166,       /*!< Divide by 166 */
    RCC_MCO_DIV_168,       /*!< Divide by 168 */
    RCC_MCO_DIV_170,       /*!< Divide by 170 */
    RCC_MCO_DIV_172,       /*!< Divide by 172 */
    RCC_MCO_DIV_174,       /*!< Divide by 174 */
    RCC_MCO_DIV_176,       /*!< Divide by 176 */
    RCC_MCO_DIV_178,       /*!< Divide by 178 */
    RCC_MCO_DIV_180,       /*!< Divide by 180 */
    RCC_MCO_DIV_182,       /*!< Divide by 182 */
    RCC_MCO_DIV_184,       /*!< Divide by 184 */
    RCC_MCO_DIV_186,       /*!< Divide by 186 */
    RCC_MCO_DIV_188,       /*!< Divide by 188 */
    RCC_MCO_DIV_190,       /*!< Divide by 190 */
    RCC_MCO_DIV_192,       /*!< Divide by 192 */
    RCC_MCO_DIV_194,       /*!< Divide by 194 */
    RCC_MCO_DIV_196,       /*!< Divide by 196 */
    RCC_MCO_DIV_198,       /*!< Divide by 198 */
    RCC_MCO_DIV_200,       /*!< Divide by 200 */
    RCC_MCO_DIV_202,       /*!< Divide by 202 */
    RCC_MCO_DIV_204,       /*!< Divide by 204 */
    RCC_MCO_DIV_206,       /*!< Divide by 206 */
    RCC_MCO_DIV_208,       /*!< Divide by 208 */
    RCC_MCO_DIV_210,       /*!< Divide by 210 */
    RCC_MCO_DIV_212,       /*!< Divide by 212 */
    RCC_MCO_DIV_214,       /*!< Divide by 214 */
    RCC_MCO_DIV_216,       /*!< Divide by 216 */
    RCC_MCO_DIV_218,       /*!< Divide by 218 */
    RCC_MCO_DIV_220,       /*!< Divide by 220 */
    RCC_MCO_DIV_222,       /*!< Divide by 222 */
    RCC_MCO_DIV_224,       /*!< Divide by 224 */
    RCC_MCO_DIV_226,       /*!< Divide by 226 */
    RCC_MCO_DIV_228,       /*!< Divide by 228 */
    RCC_MCO_DIV_230,       /*!< Divide by 230 */
    RCC_MCO_DIV_232,       /*!< Divide by 232 */
    RCC_MCO_DIV_234,       /*!< Divide by 234 */
    RCC_MCO_DIV_236,       /*!< Divide by 236 */
    RCC_MCO_DIV_238,       /*!< Divide by 238 */
    RCC_MCO_DIV_240,       /*!< Divide by 240 */
    RCC_MCO_DIV_242,       /*!< Divide by 242 */
    RCC_MCO_DIV_244,       /*!< Divide by 244 */
    RCC_MCO_DIV_246,       /*!< Divide by 246 */
    RCC_MCO_DIV_248,       /*!< Divide by 248 */
    RCC_MCO_DIV_250,       /*!< Divide by 250 */
    RCC_MCO_DIV_252,       /*!< Divide by 252 */
    RCC_MCO_DIV_254,       /*!< Divide by 254 */
    RCC_MCO_DIV_256,       /*!< Divide by 256 */
    RCC_MCO_DIV_258,       /*!< Divide by 258 */
    RCC_MCO_DIV_260,       /*!< Divide by 260 */
    RCC_MCO_DIV_262,       /*!< Divide by 262 */
    RCC_MCO_DIV_264,       /*!< Divide by 264 */
    RCC_MCO_DIV_266,       /*!< Divide by 266 */
    RCC_MCO_DIV_268,       /*!< Divide by 268 */
    RCC_MCO_DIV_270,       /*!< Divide by 270 */
    RCC_MCO_DIV_272,       /*!< Divide by 272 */
    RCC_MCO_DIV_274,       /*!< Divide by 274 */
    RCC_MCO_DIV_276,       /*!< Divide by 276 */
    RCC_MCO_DIV_278,       /*!< Divide by 278 */
    RCC_MCO_DIV_280,       /*!< Divide by 280 */
    RCC_MCO_DIV_282,       /*!< Divide by 282 */
    RCC_MCO_DIV_284,       /*!< Divide by 284 */
    RCC_MCO_DIV_286,       /*!< Divide by 286 */
    RCC_MCO_DIV_288,       /*!< Divide by 288 */
    RCC_MCO_DIV_290,       /*!< Divide by 290 */
    RCC_MCO_DIV_292,       /*!< Divide by 292 */
    RCC_MCO_DIV_294,       /*!< Divide by 294 */
    RCC_MCO_DIV_296,       /*!< Divide by 296 */
    RCC_MCO_DIV_298,       /*!< Divide by 298 */
    RCC_MCO_DIV_300,       /*!< Divide by 300 */
    RCC_MCO_DIV_302,       /*!< Divide by 302 */
    RCC_MCO_DIV_304,       /*!< Divide by 304 */
    RCC_MCO_DIV_306,       /*!< Divide by 306 */
    RCC_MCO_DIV_308,       /*!< Divide by 308 */
    RCC_MCO_DIV_310,       /*!< Divide by 310 */
    RCC_MCO_DIV_312,       /*!< Divide by 312 */
    RCC_MCO_DIV_314,       /*!< Divide by 314 */
    RCC_MCO_DIV_316,       /*!< Divide by 316 */
    RCC_MCO_DIV_318,       /*!< Divide by 318 */
    RCC_MCO_DIV_320,       /*!< Divide by 320 */
    RCC_MCO_DIV_322,       /*!< Divide by 322 */
    RCC_MCO_DIV_324,       /*!< Divide by 324 */
    RCC_MCO_DIV_326,       /*!< Divide by 326 */
    RCC_MCO_DIV_328,       /*!< Divide by 328 */
    RCC_MCO_DIV_330,       /*!< Divide by 330 */
    RCC_MCO_DIV_332,       /*!< Divide by 332 */
    RCC_MCO_DIV_334,       /*!< Divide by 334 */
    RCC_MCO_DIV_336,       /*!< Divide by 336 */
    RCC_MCO_DIV_338,       /*!< Divide by 338 */
    RCC_MCO_DIV_340,       /*!< Divide by 340 */
    RCC_MCO_DIV_342,       /*!< Divide by 342 */
    RCC_MCO_DIV_344,       /*!< Divide by 344 */
    RCC_MCO_DIV_346,       /*!< Divide by 346 */
    RCC_MCO_DIV_348,       /*!< Divide by 348 */
    RCC_MCO_DIV_350,       /*!< Divide by 350 */
    RCC_MCO_DIV_352,       /*!< Divide by 352 */
    RCC_MCO_DIV_354,       /*!< Divide by 354 */
    RCC_MCO_DIV_356,       /*!< Divide by 356 */
    RCC_MCO_DIV_358,       /*!< Divide by 358 */
    RCC_MCO_DIV_360,       /*!< Divide by 360 */
    RCC_MCO_DIV_362,       /*!< Divide by 362 */
    RCC_MCO_DIV_364,       /*!< Divide by 364 */
    RCC_MCO_DIV_366,       /*!< Divide by 366 */
    RCC_MCO_DIV_368,       /*!< Divide by 368 */
    RCC_MCO_DIV_370,       /*!< Divide by 370 */
    RCC_MCO_DIV_372,       /*!< Divide by 372 */
    RCC_MCO_DIV_374,       /*!< Divide by 374 */
    RCC_MCO_DIV_376,       /*!< Divide by 376 */
    RCC_MCO_DIV_378,       /*!< Divide by 378 */
    RCC_MCO_DIV_380,       /*!< Divide by 380 */
    RCC_MCO_DIV_382,       /*!< Divide by 382 */
    RCC_MCO_DIV_384,       /*!< Divide by 384 */
    RCC_MCO_DIV_386,       /*!< Divide by 386 */
    RCC_MCO_DIV_388,       /*!< Divide by 388 */
    RCC_MCO_DIV_390,       /*!< Divide by 390 */
    RCC_MCO_DIV_392,       /*!< Divide by 392 */
    RCC_MCO_DIV_394,       /*!< Divide by 394 */
    RCC_MCO_DIV_396,       /*!< Divide by 396 */
    RCC_MCO_DIV_398,       /*!< Divide by 398 */
    RCC_MCO_DIV_400,       /*!< Divide by 400 */
    RCC_MCO_DIV_402,       /*!< Divide by 402 */
    RCC_MCO_DIV_404,       /*!< Divide by 404 */
    RCC_MCO_DIV_406,       /*!< Divide by 406 */
    RCC_MCO_DIV_408,       /*!< Divide by 408 */
    RCC_MCO_DIV_410,       /*!< Divide by 410 */
    RCC_MCO_DIV_412,       /*!< Divide by 412 */
    RCC_MCO_DIV_414,       /*!< Divide by 414 */
    RCC_MCO_DIV_416,       /*!< Divide by 416 */
    RCC_MCO_DIV_418,       /*!< Divide by 418 */
    RCC_MCO_DIV_420,       /*!< Divide by 420 */
    RCC_MCO_DIV_422,       /*!< Divide by 422 */
    RCC_MCO_DIV_424,       /*!< Divide by 424 */
    RCC_MCO_DIV_426,       /*!< Divide by 426 */
    RCC_MCO_DIV_428,       /*!< Divide by 428 */
    RCC_MCO_DIV_430,       /*!< Divide by 430 */
    RCC_MCO_DIV_432,       /*!< Divide by 432 */
    RCC_MCO_DIV_434,       /*!< Divide by 434 */
    RCC_MCO_DIV_436,       /*!< Divide by 436 */
    RCC_MCO_DIV_438,       /*!< Divide by 438 */
    RCC_MCO_DIV_440,       /*!< Divide by 440 */
    RCC_MCO_DIV_442,       /*!< Divide by 442 */
    RCC_MCO_DIV_444,       /*!< Divide by 444 */
    RCC_MCO_DIV_446,       /*!< Divide by 446 */
    RCC_MCO_DIV_448,       /*!< Divide by 448 */
    RCC_MCO_DIV_450,       /*!< Divide by 450 */
    RCC_MCO_DIV_452,       /*!< Divide by 452 */
    RCC_MCO_DIV_454,       /*!< Divide by 454 */
    RCC_MCO_DIV_456,       /*!< Divide by 456 */
    RCC_MCO_DIV_458,       /*!< Divide by 458 */
    RCC_MCO_DIV_460,       /*!< Divide by 460 */
    RCC_MCO_DIV_462,       /*!< Divide by 462 */
    RCC_MCO_DIV_464,       /*!< Divide by 464 */
    RCC_MCO_DIV_466,       /*!< Divide by 466 */
    RCC_MCO_DIV_468,       /*!< Divide by 468 */
    RCC_MCO_DIV_470,       /*!< Divide by 470 */
    RCC_MCO_DIV_472,       /*!< Divide by 472 */
    RCC_MCO_DIV_474,       /*!< Divide by 474 */
    RCC_MCO_DIV_476,       /*!< Divide by 476 */
    RCC_MCO_DIV_478,       /*!< Divide by 478 */
    RCC_MCO_DIV_480,       /*!< Divide by 480 */
    RCC_MCO_DIV_482,       /*!< Divide by 482 */
    RCC_MCO_DIV_484,       /*!< Divide by 484 */
    RCC_MCO_DIV_486,       /*!< Divide by 486 */
    RCC_MCO_DIV_488,       /*!< Divide by 488 */
    RCC_MCO_DIV_490,       /*!< Divide by 490 */
    RCC_MCO_DIV_492,       /*!< Divide by 492 */
    RCC_MCO_DIV_494,       /*!< Divide by 494 */
    RCC_MCO_DIV_496,       /*!< Divide by 496 */
    RCC_MCO_DIV_498,       /*!< Divide by 498 */
    RCC_MCO_DIV_500,       /*!< Divide by 500 */
    RCC_MCO_DIV_502,       /*!< Divide by 502 */
    RCC_MCO_DIV_504,       /*!< Divide by 504 */
    RCC_MCO_DIV_506,       /*!< Divide by 506 */
    RCC_MCO_DIV_508,       /*!< Divide by 508 */
    RCC_MCO_DIV_510        /*!< Divide by 510 */
} RCC_McoDivSel;

/**
  * @}
  */

/** @defgroup RCC_APB5SRC RCC APB5 Clock Source Selection
  * @{
  * @brief  Macro definitions about APB5 clock source.
  */
typedef enum {
    RCC_APB5_HCLK_DIV1 = 0U,    /*!< APB5 Clock From HCLK divided by 1 */
    RCC_APB5_HCLK_DIV2,         /*!< APB5 Clock From HCLK divided by 2 */
    RCC_APB5_HCLK_DIV4,         /*!< APB5 Clock From HCLK divided by 4 */
    RCC_APB5_HCLK_DIV8,         /*!< APB5 Clock From HCLK divided by 8 */
    RCC_APB5_HCLK_DIV16         /*!< APB5 Clock From HCLK divided by 16 */
} RCC_Apb5Src;

/**
  * @}
  */

/** @defgroup RCC_APB2AND4SRC RCC APB2 and APB4 Clock Source Selection
  * @{
  * @brief  Macro definitions for APB2 and APB4 clock source selection.
  */
typedef enum {
    RCC_APB2_4_HCLK_DIV1 = 0U,    /*!< APB2 and APB4 Clock From HCLK divided by 1 */
    RCC_APB2_4_HCLK_DIV2,         /*!< APB2 and APB4 Clock From HCLK divided by 2 */
    RCC_APB2_4_HCLK_DIV4,         /*!< APB2 and APB4 Clock From HCLK divided by 4 */
    RCC_APB2_4_HCLK_DIV8,         /*!< APB2 and APB4 Clock From HCLK divided by 8 */
    RCC_APB2_4_HCLK_DIV16         /*!< APB2 and APB4 Clock From HCLK divided by 16 */
} RCC_Apb2And4Src;

/**
  * @}
  */

/** @defgroup RCC_APB1AND3SRC RCC APB1 and APB3 Clock Source Selection
  * @{
  * @brief  Macro definitions for APB1 and APB3 clock source selection.
  */
typedef enum {
    RCC_APB1_3_HCLK_DIV1 = 0U,    /*!< APB1 and APB3 Clock From HCLK divided by 1 */
    RCC_APB1_3_HCLK_DIV2,         /*!< APB1 and APB3 Clock From HCLK divided by 2 */
    RCC_APB1_3_HCLK_DIV4,         /*!< APB1 and APB3 Clock From HCLK divided by 4 */
    RCC_APB1_3_HCLK_DIV8,         /*!< APB1 and APB3 Clock From HCLK divided by 8 */
    RCC_APB1_3_HCLK_DIV16         /*!< APB1 and APB3 Clock From HCLK divided by 16 */
} RCC_Apb1And3Src;

/**
  * @}
  */

/** @defgroup RCC_HCLKSEL RCC BUS Clock Source Selection
  * @{
  * @brief  Macro definitions for BUS clock source selection.
  */
typedef enum {
    RCC_HCLKSOURCE_CPUCLK = 0U,    /*!< BUS Clock divided by 1 */
    RCC_HCLKSOURCE_CPUCLK_2,       /*!< BUS Clock divided by 2 */
} RCC_HclkSel;


/**
  * @}
  */

/** @defgroup RCC_SYSCLKDIVSEL RCC System Clock Division Selection
  * @{
  * @brief  Macro definitions for system clock division selection.
  */
typedef enum {
    RCC_SYSCLK_DIV1 = 0U,    /*!< System Clock From SYSCLK divided by 1 */
    RCC_SYSCLK_DIV2,         /*!< System Clock From SYSCLK divided by 2 */
    RCC_SYSCLK_DIV4,         /*!< System Clock From SYSCLK divided by 4 */
    RCC_SYSCLK_DIV8,         /*!< System Clock From SYSCLK divided by 8 */
    RCC_SYSCLK_DIV16,        /*!< System Clock From SYSCLK divided by 16 */
    RCC_SYSCLK_DIV32,        /*!< System Clock From SYSCLK divided by 32 */
    RCC_SYSCLK_DIV64,        /*!< System Clock From SYSCLK divided by 64 */
    RCC_SYSCLK_DIV128,       /*!< System Clock From SYSCLK divided by 128 */
    RCC_SYSCLK_DIV256,       /*!< System Clock From SYSCLK divided by 256 */
    RCC_SYSCLK_DIV512        /*!< System Clock From SYSCLK divided by 512 */
} RCC_SysclkDivSel;

/**
  * @}
  */

/** @defgroup RCC_SYSCLKSTATUS RCC System Clock Status
  * @{
  * @brief  Macro definitions for system clock status.
  */
typedef enum {
    RCC_SYSCLKSTATUS_MIRC2 = 0U,    /*!< System Clock from MIRC2 */
    RCC_SYSCLKSTATUS_HXTL,          /*!< System Clock from HXTL */
    RCC_SYSCLKSTATUS_PLL,           /*!< System Clock from PLL */
    RCC_SYSCLKSTATUS_MIRC1          /*!< System Clock from MIRC1 */
} RCC_SysclkStatus;

/**
  * @}
  */

/** @defgroup RCC_SYSCLKSRC RCC System Clock Source Selection
  * @{
  * @brief  Macro definitions for system clock source selection.
  */
typedef enum {
    RCC_SYSCLKSOURCE_MIRC2 = 0U,    /*!< Select System Clock from MIRC2 */
    RCC_SYSCLKSOURCE_HXTL,          /*!< Select System Clock from HXTL */
    RCC_SYSCLKSOURCE_PLL,           /*!< Select System Clock from PLL */
    RCC_SYSCLKSOURCE_MIRC1          /*!< Select System Clock from MIRC1 */
} RCC_SysclkSrc;

/**
  * @}
  */

/** @defgroup RCC_PLLSRC RCC PLL Clock Source Selection
  * @{
  * @brief  Macro definitions for PLL clock source selection.
  */
typedef enum {
    RCC_PLLSOURCE_MIRC2 = 0U,    /*!< Select PLL Clock from MIRC2 */
    RCC_PLLSOURCE_HXTL,          /*!< Select PLL Clock from HXTL */
    RCC_PLLSOURCE_MIRC1          /*!< Select PLL Clock from MIRC1 */
} RCC_PllSrc;

/**
  * @}
  */

/** @defgroup RCC_OSCCLKINTSELECTION RCC OSCCLK Stop interruption source Selection
  * @{
  * @brief  When OSCCLK Stops, NMI/CMU interrupt is generated.
  */
typedef enum {
    RCC_OSCCLKSTOPINTSEL_NMI = 0x0U,    /*!< When OSCCLK Stops, NMI interrupt is generated. */
    RCC_OSCCLKSTOPINTSEL_CMU            /*!< When OSCCLK Stops, CMU interrupt is generated. */
} RCC_OscclkIntSelection;

/**
  * @}
  */

/** @defgroup RCC_CAN1PCLKSOURCE CAN1 Peripheral Clock Source Selection
  * @{
  * @brief  Macro definitions for selecting the clock source for the CAN1 peripheral.
  */
typedef enum {
    RCC_CAN1PCLK_SOURCE_OSC = 0U,    /*!< Select OSC (Oscillator) as the CAN1 peripheral clock source */
    RCC_CAN1PCLK_SOURCE_PERIPHERAL   /*!< Select PERIPHERAL (Peripheral Clock) as the CAN1 peripheral clock source */
} RCC_Can1PclkSource;

/**
  * @}
  */

/** @defgroup RCC_CAN1TIMECLKDIV CAN1 Time Base Clock Division Selection
  * @{
  * @brief  Macro definitions for CAN1 time base clock division selection.
  */
typedef enum {
    RCC_CAN1_TIMECLK_DIV8 = 0U,    /*!< Divide the CAN1 time base clock by 8 */
    RCC_CAN1_TIMECLK_DIV16,        /*!< Divide the CAN1 time base clock by 16 */
    RCC_CAN1_TIMECLK_DIV24,        /*!< Divide the CAN1 time base clock by 24 */
    RCC_CAN1_TIMECLK_DIV48         /*!< Divide the CAN1 time base clock by 48 */
} RCC_Can1TimeclkDiv;

/**
  * @}
  */

/** @defgroup RCC_CAN1OSCCLK CAN1 Oscillator Clock Source Selection
  * @{
  * @brief  Macro definitions for CAN1 oscillator clock source selection.
  */
typedef enum {
    RCC_CAN1_OSCCLK_SEL_MIRC2KER = 0U,    /*!< Select MIRC2 as the CAN1 oscillator clock source */
    RCC_CAN1_OSCCLK_SEL_HXTLKER,          /*!< Select HXTL as the CAN1 oscillator clock source */
    RCC_CAN1_OSCCLK_SEL_AUX               /*!< Select AUX as the CAN1 oscillator clock source */
} RCC_Can1OscClk;

/**
  * @}
  */

/** @defgroup RCC_CAN1PERIPHERALCLK CAN1 Peripheral Clock Source Selection
  * @{
  * @brief  Macro definitions for CAN1 peripheral clock source selection.
  */
typedef enum {
    RCC_CAN1_PERIPHERAL_CLK_SEL_HCLK = 0U,    /*!< Select HCLK as the CAN1 peripheral clock source */
    RCC_CAN1_PERIPHERAL_CLK_SEL_PLL_CLKR,     /*!< Select PLL_CLKR as the CAN1 peripheral clock source */
} RCC_Can1PeripheralClk;

/**
  * @}
  */

/** @defgroup RCC_PLLMSELECTION RCC PLLM Selection
  * @{
  * @brief  Macro definitions for selecting the PLLM doubling factor.
  */
typedef enum {
    RCC_PLLM_2 = 2U,    /*!< Select PLLM doubling factor as 2 */
    RCC_PLLM_3,         /*!< Select PLLM doubling factor as 3 */
    RCC_PLLM_4,         /*!< Select PLLM doubling factor as 4 */
    RCC_PLLM_5,         /*!< Select PLLM doubling factor as 5 */
    RCC_PLLM_6,         /*!< Select PLLM doubling factor as 6 */
    RCC_PLLM_7,         /*!< Select PLLM doubling factor as 7 */
    RCC_PLLM_8,         /*!< Select PLLM doubling factor as 8 */
    RCC_PLLM_9,         /*!< Select PLLM doubling factor as 9 */
    RCC_PLLM_10,        /*!< Select PLLM doubling factor as 10 */
    RCC_PLLM_11,        /*!< Select PLLM doubling factor as 11 */
    RCC_PLLM_12,        /*!< Select PLLM doubling factor as 12 */
    RCC_PLLM_13,        /*!< Select PLLM doubling factor as 13 */
    RCC_PLLM_14,        /*!< Select PLLM doubling factor as 14 */
    RCC_PLLM_15,        /*!< Select PLLM doubling factor as 15 */
    RCC_PLLM_16,        /*!< Select PLLM doubling factor as 16 */
    RCC_PLLM_17,        /*!< Select PLLM doubling factor as 17 */
    RCC_PLLM_18,        /*!< Select PLLM doubling factor as 18 */
    RCC_PLLM_19,        /*!< Select PLLM doubling factor as 19 */
    RCC_PLLM_20,        /*!< Select PLLM doubling factor as 20 */
    RCC_PLLM_21,        /*!< Select PLLM doubling factor as 21 */
    RCC_PLLM_22,        /*!< Select PLLM doubling factor as 22 */
    RCC_PLLM_23,        /*!< Select PLLM doubling factor as 23 */
    RCC_PLLM_24,        /*!< Select PLLM doubling factor as 24 */
    RCC_PLLM_25,        /*!< Select PLLM doubling factor as 25 */
    RCC_PLLM_26,        /*!< Select PLLM doubling factor as 26 */
    RCC_PLLM_27,        /*!< Select PLLM doubling factor as 27 */
    RCC_PLLM_28,        /*!< Select PLLM doubling factor as 28 */
    RCC_PLLM_29,        /*!< Select PLLM doubling factor as 29 */
    RCC_PLLM_30,        /*!< Select PLLM doubling factor as 30 */
    RCC_PLLM_31,        /*!< Select PLLM doubling factor as 31 */
    RCC_PLLM_32,        /*!< Select PLLM doubling factor as 32 */
    RCC_PLLM_33,        /*!< Select PLLM doubling factor as 33 */
    RCC_PLLM_34,        /*!< Select PLLM doubling factor as 34 */
    RCC_PLLM_35,        /*!< Select PLLM doubling factor as 35 */
    RCC_PLLM_36,        /*!< Select PLLM doubling factor as 36 */
    RCC_PLLM_37,        /*!< Select PLLM doubling factor as 37 */
    RCC_PLLM_38,        /*!< Select PLLM doubling factor as 38 */
    RCC_PLLM_39,        /*!< Select PLLM doubling factor as 39 */
    RCC_PLLM_40,        /*!< Select PLLM doubling factor as 40 */
    RCC_PLLM_41,        /*!< Select PLLM doubling factor as 41 */
    RCC_PLLM_42,        /*!< Select PLLM doubling factor as 42 */
    RCC_PLLM_43,        /*!< Select PLLM doubling factor as 43 */
    RCC_PLLM_44,        /*!< Select PLLM doubling factor as 44 */
    RCC_PLLM_45,        /*!< Select PLLM doubling factor as 45 */
    RCC_PLLM_46,        /*!< Select PLLM doubling factor as 46 */
    RCC_PLLM_47,        /*!< Select PLLM doubling factor as 47 */
    RCC_PLLM_48,        /*!< Select PLLM doubling factor as 48 */
    RCC_PLLM_49,        /*!< Select PLLM doubling factor as 49 */
    RCC_PLLM_50,        /*!< Select PLLM doubling factor as 50 */
    RCC_PLLM_51,        /*!< Select PLLM doubling factor as 51 */
    RCC_PLLM_52,        /*!< Select PLLM doubling factor as 52 */
    RCC_PLLM_53,        /*!< Select PLLM doubling factor as 53 */
    RCC_PLLM_54,        /*!< Select PLLM doubling factor as 54 */
    RCC_PLLM_55,        /*!< Select PLLM doubling factor as 55 */
    RCC_PLLM_56,        /*!< Select PLLM doubling factor as 56 */
    RCC_PLLM_57,        /*!< Select PLLM doubling factor as 57 */
    RCC_PLLM_58,        /*!< Select PLLM doubling factor as 58 */
    RCC_PLLM_59,        /*!< Select PLLM doubling factor as 59 */
    RCC_PLLM_60,        /*!< Select PLLM doubling factor as 60 */
    RCC_PLLM_61,        /*!< Select PLLM doubling factor as 61 */
    RCC_PLLM_62,        /*!< Select PLLM doubling factor as 62 */
    RCC_PLLM_63,        /*!< Select PLLM doubling factor as 63 */
    RCC_PLLM_64,        /*!< Select PLLM doubling factor as 64 */
    RCC_PLLM_65,        /*!< Select PLLM doubling factor as 65 */
    RCC_PLLM_66,        /*!< Select PLLM doubling factor as 66 */
    RCC_PLLM_67,        /*!< Select PLLM doubling factor as 67 */
    RCC_PLLM_68,        /*!< Select PLLM doubling factor as 68 */
    RCC_PLLM_69,        /*!< Select PLLM doubling factor as 69 */
    RCC_PLLM_70,        /*!< Select PLLM doubling factor as 70 */
    RCC_PLLM_71,        /*!< Select PLLM doubling factor as 71 */
    RCC_PLLM_72,        /*!< Select PLLM doubling factor as 72 */
    RCC_PLLM_73,        /*!< Select PLLM doubling factor as 73 */
    RCC_PLLM_74,        /*!< Select PLLM doubling factor as 74 */
    RCC_PLLM_75,        /*!< Select PLLM doubling factor as 75 */
    RCC_PLLM_76,        /*!< Select PLLM doubling factor as 76 */
    RCC_PLLM_77,        /*!< Select PLLM doubling factor as 77 */
    RCC_PLLM_78,        /*!< Select PLLM doubling factor as 78 */
    RCC_PLLM_79,        /*!< Select PLLM doubling factor as 79 */
    RCC_PLLM_80,        /*!< Select PLLM doubling factor as 80 */
    RCC_PLLM_81,        /*!< Select PLLM doubling factor as 81 */
    RCC_PLLM_82,        /*!< Select PLLM doubling factor as 82 */
    RCC_PLLM_83,        /*!< Select PLLM doubling factor as 83 */
    RCC_PLLM_84,        /*!< Select PLLM doubling factor as 84 */
    RCC_PLLM_85,        /*!< Select PLLM doubling factor as 85 */
    RCC_PLLM_86,        /*!< Select PLLM doubling factor as 86 */
    RCC_PLLM_87,        /*!< Select PLLM doubling factor as 87 */
    RCC_PLLM_88,        /*!< Select PLLM doubling factor as 88 */
    RCC_PLLM_89,        /*!< Select PLLM doubling factor as 89 */
    RCC_PLLM_90,        /*!< Select PLLM doubling factor as 90 */
    RCC_PLLM_91,        /*!< Select PLLM doubling factor as 91 */
    RCC_PLLM_92,        /*!< Select PLLM doubling factor as 92 */
    RCC_PLLM_93,        /*!< Select PLLM doubling factor as 93 */
    RCC_PLLM_94,        /*!< Select PLLM doubling factor as 94 */
    RCC_PLLM_95,        /*!< Select PLLM doubling factor as 95 */
    RCC_PLLM_96,        /*!< Select PLLM doubling factor as 96 */
    RCC_PLLM_97,        /*!< Select PLLM doubling factor as 97 */
    RCC_PLLM_98,        /*!< Select PLLM doubling factor as 98 */
    RCC_PLLM_99,        /*!< Select PLLM doubling factor as 99 */
    RCC_PLLM_100,       /*!< Select PLLM doubling factor as 100 */
    RCC_PLLM_101,       /*!< Select PLLM doubling factor as 101 */
    RCC_PLLM_102,       /*!< Select PLLM doubling factor as 102 */
    RCC_PLLM_103,       /*!< Select PLLM doubling factor as 103 */
    RCC_PLLM_104,       /*!< Select PLLM doubling factor as 104 */
    RCC_PLLM_105,       /*!< Select PLLM doubling factor as 105 */
    RCC_PLLM_106,       /*!< Select PLLM doubling factor as 106 */
    RCC_PLLM_107,       /*!< Select PLLM doubling factor as 107 */
    RCC_PLLM_108,       /*!< Select PLLM doubling factor as 108 */
    RCC_PLLM_109,       /*!< Select PLLM doubling factor as 109 */
    RCC_PLLM_110,       /*!< Select PLLM doubling factor as 110 */
    RCC_PLLM_111,       /*!< Select PLLM doubling factor as 111 */
    RCC_PLLM_112,       /*!< Select PLLM doubling factor as 112 */
    RCC_PLLM_113,       /*!< Select PLLM doubling factor as 113 */
    RCC_PLLM_114,       /*!< Select PLLM doubling factor as 114 */
    RCC_PLLM_115,       /*!< Select PLLM doubling factor as 115 */
    RCC_PLLM_116,       /*!< Select PLLM doubling factor as 116 */
    RCC_PLLM_117,       /*!< Select PLLM doubling factor as 117 */
    RCC_PLLM_118,       /*!< Select PLLM doubling factor as 118 */
    RCC_PLLM_119,       /*!< Select PLLM doubling factor as 119 */
    RCC_PLLM_120,       /*!< Select PLLM doubling factor as 120 */
    RCC_PLLM_121,       /*!< Select PLLM doubling factor as 121 */
    RCC_PLLM_122,       /*!< Select PLLM doubling factor as 122 */
    RCC_PLLM_123,       /*!< Select PLLM doubling factor as 123 */
    RCC_PLLM_124,       /*!< Select PLLM doubling factor as 124 */
    RCC_PLLM_125,       /*!< Select PLLM doubling factor as 125 */
    RCC_PLLM_126,       /*!< Select PLLM doubling factor as 126 */
    RCC_PLLM_127,       /*!< Select PLLM doubling factor as 127 */
    RCC_PLLM_128,       /*!< Select PLLM doubling factor as 128 */
    RCC_PLLM_129,       /*!< Select PLLM doubling factor as 129 */
    RCC_PLLM_130,       /*!< Select PLLM doubling factor as 130 */
    RCC_PLLM_131,       /*!< Select PLLM doubling factor as 131 */
    RCC_PLLM_132,       /*!< Select PLLM doubling factor as 132 */
    RCC_PLLM_133,       /*!< Select PLLM doubling factor as 133 */
    RCC_PLLM_134,       /*!< Select PLLM doubling factor as 134 */
    RCC_PLLM_135,       /*!< Select PLLM doubling factor as 135 */
    RCC_PLLM_136,       /*!< Select PLLM doubling factor as 136 */
    RCC_PLLM_137,       /*!< Select PLLM doubling factor as 137 */
    RCC_PLLM_138,       /*!< Select PLLM doubling factor as 138 */
    RCC_PLLM_139,       /*!< Select PLLM doubling factor as 139 */
    RCC_PLLM_140,       /*!< Select PLLM doubling factor as 140 */
    RCC_PLLM_141,       /*!< Select PLLM doubling factor as 141 */
    RCC_PLLM_142,       /*!< Select PLLM doubling factor as 142 */
    RCC_PLLM_143,       /*!< Select PLLM doubling factor as 143 */
    RCC_PLLM_144,       /*!< Select PLLM doubling factor as 144 */
    RCC_PLLM_145,       /*!< Select PLLM doubling factor as 145 */
    RCC_PLLM_146,       /*!< Select PLLM doubling factor as 146 */
    RCC_PLLM_147,       /*!< Select PLLM doubling factor as 147 */
    RCC_PLLM_148,       /*!< Select PLLM doubling factor as 148 */
    RCC_PLLM_149,       /*!< Select PLLM doubling factor as 149 */
    RCC_PLLM_150,       /*!< Select PLLM doubling factor as 150 */
    RCC_PLLM_151,       /*!< Select PLLM doubling factor as 151 */
    RCC_PLLM_152,       /*!< Select PLLM doubling factor as 152 */
    RCC_PLLM_153,       /*!< Select PLLM doubling factor as 153 */
    RCC_PLLM_154,       /*!< Select PLLM doubling factor as 154 */
    RCC_PLLM_155,       /*!< Select PLLM doubling factor as 155 */
    RCC_PLLM_156,       /*!< Select PLLM doubling factor as 156 */
    RCC_PLLM_157,       /*!< Select PLLM doubling factor as 157 */
    RCC_PLLM_158,       /*!< Select PLLM doubling factor as 158 */
    RCC_PLLM_159,       /*!< Select PLLM doubling factor as 159 */
    RCC_PLLM_160,       /*!< Select PLLM doubling factor as 160 */
    RCC_PLLM_161,       /*!< Select PLLM doubling factor as 161 */
    RCC_PLLM_162,       /*!< Select PLLM doubling factor as 162 */
    RCC_PLLM_163,       /*!< Select PLLM doubling factor as 163 */
    RCC_PLLM_164,       /*!< Select PLLM doubling factor as 164 */
    RCC_PLLM_165,       /*!< Select PLLM doubling factor as 165 */
    RCC_PLLM_166,       /*!< Select PLLM doubling factor as 166 */
    RCC_PLLM_167,       /*!< Select PLLM doubling factor as 167 */
    RCC_PLLM_168,       /*!< Select PLLM doubling factor as 168 */
    RCC_PLLM_169,       /*!< Select PLLM doubling factor as 169 */
    RCC_PLLM_170,       /*!< Select PLLM doubling factor as 170 */
    RCC_PLLM_171,       /*!< Select PLLM doubling factor as 171 */
    RCC_PLLM_172,       /*!< Select PLLM doubling factor as 172 */
    RCC_PLLM_173,       /*!< Select PLLM doubling factor as 173 */
    RCC_PLLM_174,       /*!< Select PLLM doubling factor as 174 */
    RCC_PLLM_175,       /*!< Select PLLM doubling factor as 175 */
    RCC_PLLM_176,       /*!< Select PLLM doubling factor as 176 */
    RCC_PLLM_177,       /*!< Select PLLM doubling factor as 177 */
    RCC_PLLM_178,       /*!< Select PLLM doubling factor as 178 */
    RCC_PLLM_179,       /*!< Select PLLM doubling factor as 179 */
    RCC_PLLM_180,       /*!< Select PLLM doubling factor as 180 */
    RCC_PLLM_181,       /*!< Select PLLM doubling factor as 181 */
    RCC_PLLM_182,       /*!< Select PLLM doubling factor as 182 */
    RCC_PLLM_183,       /*!< Select PLLM doubling factor as 183 */
    RCC_PLLM_184,       /*!< Select PLLM doubling factor as 184 */
    RCC_PLLM_185,       /*!< Select PLLM doubling factor as 185 */
    RCC_PLLM_186,       /*!< Select PLLM doubling factor as 186 */
    RCC_PLLM_187,       /*!< Select PLLM doubling factor as 187 */
    RCC_PLLM_188,       /*!< Select PLLM doubling factor as 188 */
    RCC_PLLM_189,       /*!< Select PLLM doubling factor as 189 */
    RCC_PLLM_190,       /*!< Select PLLM doubling factor as 190 */
    RCC_PLLM_191,       /*!< Select PLLM doubling factor as 191 */
    RCC_PLLM_192,       /*!< Select PLLM doubling factor as 192 */
    RCC_PLLM_193,       /*!< Select PLLM doubling factor as 193 */
    RCC_PLLM_194,       /*!< Select PLLM doubling factor as 194 */
    RCC_PLLM_195,       /*!< Select PLLM doubling factor as 195 */
    RCC_PLLM_196,       /*!< Select PLLM doubling factor as 196 */
    RCC_PLLM_197,       /*!< Select PLLM doubling factor as 197 */
    RCC_PLLM_198,       /*!< Select PLLM doubling factor as 198 */
    RCC_PLLM_199,       /*!< Select PLLM doubling factor as 199 */
    RCC_PLLM_200,       /*!< Select PLLM doubling factor as 200 */
    RCC_PLLM_201,       /*!< Select PLLM doubling factor as 201 */
    RCC_PLLM_202,       /*!< Select PLLM doubling factor as 202 */
    RCC_PLLM_203,       /*!< Select PLLM doubling factor as 203 */
    RCC_PLLM_204,       /*!< Select PLLM doubling factor as 204 */
    RCC_PLLM_205,       /*!< Select PLLM doubling factor as 205 */
    RCC_PLLM_206,       /*!< Select PLLM doubling factor as 206 */
    RCC_PLLM_207,       /*!< Select PLLM doubling factor as 207 */
    RCC_PLLM_208,       /*!< Select PLLM doubling factor as 208 */
    RCC_PLLM_209,       /*!< Select PLLM doubling factor as 209 */
    RCC_PLLM_210,       /*!< Select PLLM doubling factor as 210 */
    RCC_PLLM_211,       /*!< Select PLLM doubling factor as 211 */
    RCC_PLLM_212,       /*!< Select PLLM doubling factor as 212 */
    RCC_PLLM_213,       /*!< Select PLLM doubling factor as 213 */
    RCC_PLLM_214,       /*!< Select PLLM doubling factor as 214 */
    RCC_PLLM_215,       /*!< Select PLLM doubling factor as 215 */
    RCC_PLLM_216,       /*!< Select PLLM doubling factor as 216 */
    RCC_PLLM_217,       /*!< Select PLLM doubling factor as 217 */
    RCC_PLLM_218,       /*!< Select PLLM doubling factor as 218 */
    RCC_PLLM_219,       /*!< Select PLLM doubling factor as 219 */
    RCC_PLLM_220,       /*!< Select PLLM doubling factor as 220 */
    RCC_PLLM_221,       /*!< Select PLLM doubling factor as 221 */
    RCC_PLLM_222,       /*!< Select PLLM doubling factor as 222 */
    RCC_PLLM_223,       /*!< Select PLLM doubling factor as 223 */
    RCC_PLLM_224,       /*!< Select PLLM doubling factor as 224 */
    RCC_PLLM_225,       /*!< Select PLLM doubling factor as 225 */
    RCC_PLLM_226,       /*!< Select PLLM doubling factor as 226 */
    RCC_PLLM_227,       /*!< Select PLLM doubling factor as 227 */
    RCC_PLLM_228,       /*!< Select PLLM doubling factor as 228 */
    RCC_PLLM_229,       /*!< Select PLLM doubling factor as 229 */
    RCC_PLLM_230,       /*!< Select PLLM doubling factor as 230 */
    RCC_PLLM_231,       /*!< Select PLLM doubling factor as 231 */
    RCC_PLLM_232,       /*!< Select PLLM doubling factor as 232 */
    RCC_PLLM_233,       /*!< Select PLLM doubling factor as 233 */
    RCC_PLLM_234,       /*!< Select PLLM doubling factor as 234 */
    RCC_PLLM_235,       /*!< Select PLLM doubling factor as 235 */
    RCC_PLLM_236,       /*!< Select PLLM doubling factor as 236 */
    RCC_PLLM_237,       /*!< Select PLLM doubling factor as 237 */
    RCC_PLLM_238,       /*!< Select PLLM doubling factor as 238 */
    RCC_PLLM_239,       /*!< Select PLLM doubling factor as 239 */
    RCC_PLLM_240,       /*!< Select PLLM doubling factor as 240 */
    RCC_PLLM_241,       /*!< Select PLLM doubling factor as 241 */
    RCC_PLLM_242,       /*!< Select PLLM doubling factor as 242 */
    RCC_PLLM_243,       /*!< Select PLLM doubling factor as 243 */
    RCC_PLLM_244,       /*!< Select PLLM doubling factor as 244 */
    RCC_PLLM_245,       /*!< Select PLLM doubling factor as 245 */
    RCC_PLLM_246,       /*!< Select PLLM doubling factor as 246 */
    RCC_PLLM_247,       /*!< Select PLLM doubling factor as 247 */
    RCC_PLLM_248,       /*!< Select PLLM doubling factor as 248 */
    RCC_PLLM_249,       /*!< Select PLLM doubling factor as 249 */
    RCC_PLLM_250,       /*!< Select PLLM doubling factor as 250 */
    RCC_PLLM_251,       /*!< Select PLLM doubling factor as 251 */
    RCC_PLLM_252,       /*!< Select PLLM doubling factor as 252 */
    RCC_PLLM_253,       /*!< Select PLLM doubling factor as 253 */
    RCC_PLLM_254,       /*!< Select PLLM doubling factor as 254 */
    RCC_PLLM_255        /*!< Select PLLM doubling factor as 255 */
} RCC_PllmSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLNSELECTION RCC PLLN Selection
  * @{
  * @brief Macro definitions for selecting the PLLN division factor.
  */
typedef enum {
    RCC_PLLN_DIV1 = 0U,    /*!< Select PLLN division factor as 1 */
    RCC_PLLN_DIV2,         /*!< Select PLLN division factor as 2 */
    RCC_PLLN_DIV3,         /*!< Select PLLN division factor as 3 */
    RCC_PLLN_DIV4,         /*!< Select PLLN division factor as 4 */
    RCC_PLLN_DIV5,         /*!< Select PLLN division factor as 5 */
    RCC_PLLN_DIV6,         /*!< Select PLLN division factor as 6 */
    RCC_PLLN_DIV7,         /*!< Select PLLN division factor as 7 */
    RCC_PLLN_DIV8,         /*!< Select PLLN division factor as 8 */
    RCC_PLLN_DIV9,         /*!< Select PLLN division factor as 9 */
    RCC_PLLN_DIV10,        /*!< Select PLLN division factor as 10 */
    RCC_PLLN_DIV11,        /*!< Select PLLN division factor as 11 */
    RCC_PLLN_DIV12,        /*!< Select PLLN division factor as 12 */
    RCC_PLLN_DIV13,        /*!< Select PLLN division factor as 13 */
    RCC_PLLN_DIV14,        /*!< Select PLLN division factor as 14 */
    RCC_PLLN_DIV15,        /*!< Select PLLN division factor as 15 */
    RCC_PLLN_DIV16         /*!< Select PLLN division factor as 16 */
} RCC_PllnSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLPSELECTION RCC PLLP Selection
  * @{
  * @brief Macro definitions for selecting the PLLP division factor.
  */
typedef enum {
    RCC_PLLP_DIV2 = 0U,    /*!< Select PLLP division factor as 2 */
    RCC_PLLP_DIV4,         /*!< Select PLLP division factor as 4 */
    RCC_PLLP_DIV6,         /*!< Select PLLP division factor as 6 */
    RCC_PLLP_DIV8,         /*!< Select PLLP division factor as 8 */
    RCC_PLLP_DIV10,        /*!< Select PLLP division factor as 10 */
    RCC_PLLP_DIV12,        /*!< Select PLLP division factor as 12 */
    RCC_PLLP_DIV14,        /*!< Select PLLP division factor as 14 */
    RCC_PLLP_DIV16,        /*!< Select PLLP division factor as 16 */
    RCC_PLLP_DIV18,        /*!< Select PLLP division factor as 18 */
    RCC_PLLP_DIV20,        /*!< Select PLLP division factor as 20 */
    RCC_PLLP_DIV22,        /*!< Select PLLP division factor as 22 */
    RCC_PLLP_DIV24,        /*!< Select PLLP division factor as 24 */
    RCC_PLLP_DIV26,        /*!< Select PLLP division factor as 26 */
    RCC_PLLP_DIV28,        /*!< Select PLLP division factor as 28 */
    RCC_PLLP_DIV30,        /*!< Select PLLP division factor as 30 */
    RCC_PLLP_DIV32,        /*!< Select PLLP division factor as 32 */
    RCC_PLLP_DIV34,        /*!< Select PLLP division factor as 34 */
    RCC_PLLP_DIV36,        /*!< Select PLLP division factor as 36 */
    RCC_PLLP_DIV38,        /*!< Select PLLP division factor as 38 */
    RCC_PLLP_DIV40,        /*!< Select PLLP division factor as 40 */
    RCC_PLLP_DIV42,        /*!< Select PLLP division factor as 42 */
    RCC_PLLP_DIV44,        /*!< Select PLLP division factor as 44 */
    RCC_PLLP_DIV46,        /*!< Select PLLP division factor as 46 */
    RCC_PLLP_DIV48,        /*!< Select PLLP division factor as 48 */
    RCC_PLLP_DIV50,        /*!< Select PLLP division factor as 50 */
    RCC_PLLP_DIV52,        /*!< Select PLLP division factor as 52 */
    RCC_PLLP_DIV54,        /*!< Select PLLP division factor as 54 */
    RCC_PLLP_DIV56,        /*!< Select PLLP division factor as 56 */
    RCC_PLLP_DIV58,        /*!< Select PLLP division factor as 58 */
    RCC_PLLP_DIV60,        /*!< Select PLLP division factor as 60 */
    RCC_PLLP_DIV62         /*!< Select PLLP division factor as 62 */
} RCC_PllpSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLQSELECTION RCC PLLQ Selection
  * @{
  * @brief Macro definitions for selecting the PLLQ division factor.
  */
typedef enum {
    RCC_PLLQ_DIV2 = 0U,    /*!< Select PLLQ division factor as 2 */
    RCC_PLLQ_DIV4,         /*!< Select PLLQ division factor as 4 */
    RCC_PLLQ_DIV6,         /*!< Select PLLQ division factor as 6 */
    RCC_PLLQ_DIV8,         /*!< Select PLLQ division factor as 8 */
    RCC_PLLQ_DIV10,        /*!< Select PLLQ division factor as 10 */
    RCC_PLLQ_DIV12,        /*!< Select PLLQ division factor as 12 */
    RCC_PLLQ_DIV14,        /*!< Select PLLQ division factor as 14 */
    RCC_PLLQ_DIV16,        /*!< Select PLLQ division factor as 16 */
    RCC_PLLQ_DIV18,        /*!< Select PLLQ division factor as 18 */
    RCC_PLLQ_DIV20,        /*!< Select PLLQ division factor as 20 */
    RCC_PLLQ_DIV22,        /*!< Select PLLQ division factor as 22 */
    RCC_PLLQ_DIV24,        /*!< Select PLLQ division factor as 24 */
    RCC_PLLQ_DIV26,        /*!< Select PLLQ division factor as 26 */
    RCC_PLLQ_DIV28,        /*!< Select PLLQ division factor as 28 */
    RCC_PLLQ_DIV30,        /*!< Select PLLQ division factor as 30 */
    RCC_PLLQ_DIV32,        /*!< Select PLLQ division factor as 32 */
    RCC_PLLQ_DIV34,        /*!< Select PLLQ division factor as 34 */
    RCC_PLLQ_DIV36,        /*!< Select PLLQ division factor as 36 */
    RCC_PLLQ_DIV38,        /*!< Select PLLQ division factor as 38 */
    RCC_PLLQ_DIV40,        /*!< Select PLLQ division factor as 40 */
    RCC_PLLQ_DIV42,        /*!< Select PLLQ division factor as 42 */
    RCC_PLLQ_DIV44,        /*!< Select PLLQ division factor as 44 */
    RCC_PLLQ_DIV46,        /*!< Select PLLQ division factor as 46 */
    RCC_PLLQ_DIV48,        /*!< Select PLLQ division factor as 48 */
    RCC_PLLQ_DIV50,        /*!< Select PLLQ division factor as 50 */
    RCC_PLLQ_DIV52,        /*!< Select PLLQ division factor as 52 */
    RCC_PLLQ_DIV54,        /*!< Select PLLQ division factor as 54 */
    RCC_PLLQ_DIV56,        /*!< Select PLLQ division factor as 56 */
    RCC_PLLQ_DIV58,        /*!< Select PLLQ division factor as 58 */
    RCC_PLLQ_DIV60,        /*!< Select PLLQ division factor as 60 */
    RCC_PLLQ_DIV62         /*!< Select PLLQ division factor as 62 */
} RCC_PllqSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLRSELECTION RCC PLLR Selection
  * @{
  * @brief Macro definitions for selecting the PLLR division factor.
  */
typedef enum {
    RCC_PLLR_DIV2 = 0U,    /*!< Select PLLR division factor as 2 */
    RCC_PLLR_DIV4,         /*!< Select PLLR division factor as 4 */
    RCC_PLLR_DIV6,         /*!< Select PLLR division factor as 6 */
    RCC_PLLR_DIV8,         /*!< Select PLLR division factor as 8 */
    RCC_PLLR_DIV10,        /*!< Select PLLR division factor as 10 */
    RCC_PLLR_DIV12,        /*!< Select PLLR division factor as 12 */
    RCC_PLLR_DIV14,        /*!< Select PLLR division factor as 14 */
    RCC_PLLR_DIV16,        /*!< Select PLLR division factor as 16 */
    RCC_PLLR_DIV18,        /*!< Select PLLR division factor as 18 */
    RCC_PLLR_DIV20,        /*!< Select PLLR division factor as 20 */
    RCC_PLLR_DIV22,        /*!< Select PLLR division factor as 22 */
    RCC_PLLR_DIV24,        /*!< Select PLLR division factor as 24 */
    RCC_PLLR_DIV26,        /*!< Select PLLR division factor as 26 */
    RCC_PLLR_DIV28,        /*!< Select PLLR division factor as 28 */
    RCC_PLLR_DIV30,        /*!< Select PLLR division factor as 30 */
    RCC_PLLR_DIV32,        /*!< Select PLLR division factor as 32 */
    RCC_PLLR_DIV34,        /*!< Select PLLR division factor as 34 */
    RCC_PLLR_DIV36,        /*!< Select PLLR division factor as 36 */
    RCC_PLLR_DIV38,        /*!< Select PLLR division factor as 38 */
    RCC_PLLR_DIV40,        /*!< Select PLLR division factor as 40 */
    RCC_PLLR_DIV42,        /*!< Select PLLR division factor as 42 */
    RCC_PLLR_DIV44,        /*!< Select PLLR division factor as 44 */
    RCC_PLLR_DIV46,        /*!< Select PLLR division factor as 46 */
    RCC_PLLR_DIV48,        /*!< Select PLLR division factor as 48 */
    RCC_PLLR_DIV50,        /*!< Select PLLR division factor as 50 */
    RCC_PLLR_DIV52,        /*!< Select PLLR division factor as 52 */
    RCC_PLLR_DIV54,        /*!< Select PLLR division factor as 54 */
    RCC_PLLR_DIV56,        /*!< Select PLLR division factor as 56 */
    RCC_PLLR_DIV58,        /*!< Select PLLR division factor as 58 */
    RCC_PLLR_DIV60,        /*!< Select PLLR division factor as 60 */
    RCC_PLLR_DIV62         /*!< Select PLLR division factor as 62 */
} RCC_PllrSelection;

/**
  * @}
  */

/** @defgroup RCC_PLLFORCELKDT RCC PLL LKDT Selection
  * @{
  * @brief Configuration for Force PLL Lock Detection.
  */

typedef enum {
    RCC_PLL_FORCELK_DISABLE = 0U,    /*!< Disable Force Lock Detection */
    RCC_PLL_FORCELK_ENABLE           /*!< Enable Force Lock Detection */
} RCC_PllForceLkdt;

/**
  * @}
  */

/** @defgroup RCC_PLLLKDTSELECTION RCC PLL LKDT Selection
  * @{
  * @brief PLL Lock and Unlock Deviation Value Configuration Bits.
  */
typedef enum {
    RCC_PLL_LKDT_SEL_0 = 0U,    /*!< Lock Count Deviation Value 2%, Unlock Count Deviation Value 4% */
    RCC_PLL_LKDT_SEL_1,         /*!< Lock Count Deviation Value 4%, Unlock Count Deviation Value 8% */
    RCC_PLL_LKDT_SEL_2,         /*!< Lock Count Deviation Value 6%, Unlock Count Deviation Value 12% */
    RCC_PLL_LKDT_SEL_3          /*!< Lock Count Deviation Value 10%, Unlock Count Deviation Value 20% */
} RCC_PllLkdtSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLAWKDIVSELECTION RCC HXTL AWK Div Selection
  * @{
  * @brief Configuration bits for AWK HXTL clock prescaler.
  */

typedef enum {
    RCC_HXTL_AWK_DIV_1 = 0U,    /*!< HXTL clock divided by 1 (no division) */
    RCC_HXTL_AWK_DIV_2,         /*!< HXTL clock divided by 2 */
    RCC_HXTL_AWK_DIV_3,         /*!< HXTL clock divided by 3 */
    RCC_HXTL_AWK_DIV_4,         /*!< HXTL clock divided by 4 */
    RCC_HXTL_AWK_DIV_5,         /*!< HXTL clock divided by 5 */
    RCC_HXTL_AWK_DIV_6,         /*!< HXTL clock divided by 6 */
    RCC_HXTL_AWK_DIV_7,         /*!< HXTL clock divided by 7 */
    RCC_HXTL_AWK_DIV_8,         /*!< HXTL clock divided by 8 */
    RCC_HXTL_AWK_DIV_9,         /*!< HXTL clock divided by 9 */
    RCC_HXTL_AWK_DIV_10,        /*!< HXTL clock divided by 10 */
    RCC_HXTL_AWK_DIV_11,        /*!< HXTL clock divided by 11 */
    RCC_HXTL_AWK_DIV_12,        /*!< HXTL clock divided by 12 */
    RCC_HXTL_AWK_DIV_13,        /*!< HXTL clock divided by 13 */
    RCC_HXTL_AWK_DIV_14,        /*!< HXTL clock divided by 14 */
    RCC_HXTL_AWK_DIV_15,        /*!< HXTL clock divided by 15 */
    RCC_HXTL_AWK_DIV_16,        /*!< HXTL clock divided by 16 */
    RCC_HXTL_AWK_DIV_17,        /*!< HXTL clock divided by 17 */
    RCC_HXTL_AWK_DIV_18,        /*!< HXTL clock divided by 18 */
    RCC_HXTL_AWK_DIV_19,        /*!< HXTL clock divided by 19 */
    RCC_HXTL_AWK_DIV_20,        /*!< HXTL clock divided by 20 */
    RCC_HXTL_AWK_DIV_21,        /*!< HXTL clock divided by 21 */
    RCC_HXTL_AWK_DIV_22,        /*!< HXTL clock divided by 22 */
    RCC_HXTL_AWK_DIV_23,        /*!< HXTL clock divided by 23 */
    RCC_HXTL_AWK_DIV_24,        /*!< HXTL clock divided by 24 */
    RCC_HXTL_AWK_DIV_25,        /*!< HXTL clock divided by 25 */
    RCC_HXTL_AWK_DIV_26,        /*!< HXTL clock divided by 26 */
    RCC_HXTL_AWK_DIV_27,        /*!< HXTL clock divided by 27 */
    RCC_HXTL_AWK_DIV_28,        /*!< HXTL clock divided by 28 */
    RCC_HXTL_AWK_DIV_29,        /*!< HXTL clock divided by 29 */
    RCC_HXTL_AWK_DIV_30,        /*!< HXTL clock divided by 30 */
    RCC_HXTL_AWK_DIV_31,        /*!< HXTL clock divided by 31 */
    RCC_HXTL_AWK_DIV_32,        /*!< HXTL clock divided by 32 */
    RCC_HXTL_AWK_DIV_33,        /*!< HXTL clock divided by 33 */
    RCC_HXTL_AWK_DIV_34,        /*!< HXTL clock divided by 34 */
    RCC_HXTL_AWK_DIV_35,        /*!< HXTL clock divided by 35 */
    RCC_HXTL_AWK_DIV_36,        /*!< HXTL clock divided by 36 */
    RCC_HXTL_AWK_DIV_37,        /*!< HXTL clock divided by 37 */
    RCC_HXTL_AWK_DIV_38,        /*!< HXTL clock divided by 38 */
    RCC_HXTL_AWK_DIV_39,        /*!< HXTL clock divided by 39 */
    RCC_HXTL_AWK_DIV_40,        /*!< HXTL clock divided by 40 */
    RCC_HXTL_AWK_DIV_41,        /*!< HXTL clock divided by 41 */
    RCC_HXTL_AWK_DIV_42,        /*!< HXTL clock divided by 42 */
    RCC_HXTL_AWK_DIV_43,        /*!< HXTL clock divided by 43 */
    RCC_HXTL_AWK_DIV_44,        /*!< HXTL clock divided by 44 */
    RCC_HXTL_AWK_DIV_45,        /*!< HXTL clock divided by 45 */
    RCC_HXTL_AWK_DIV_46,        /*!< HXTL clock divided by 46 */
    RCC_HXTL_AWK_DIV_47,        /*!< HXTL clock divided by 47 */
    RCC_HXTL_AWK_DIV_48,        /*!< HXTL clock divided by 48 */
    RCC_HXTL_AWK_DIV_49,        /*!< HXTL clock divided by 49 */
    RCC_HXTL_AWK_DIV_50,        /*!< HXTL clock divided by 50 */
    RCC_HXTL_AWK_DIV_51,        /*!< HXTL clock divided by 51 */
    RCC_HXTL_AWK_DIV_52,        /*!< HXTL clock divided by 52 */
    RCC_HXTL_AWK_DIV_53,        /*!< HXTL clock divided by 53 */
    RCC_HXTL_AWK_DIV_54,        /*!< HXTL clock divided by 54 */
    RCC_HXTL_AWK_DIV_55,        /*!< HXTL clock divided by 55 */
    RCC_HXTL_AWK_DIV_56,        /*!< HXTL clock divided by 56 */
    RCC_HXTL_AWK_DIV_57,        /*!< HXTL clock divided by 57 */
    RCC_HXTL_AWK_DIV_58,        /*!< HXTL clock divided by 58 */
    RCC_HXTL_AWK_DIV_59,        /*!< HXTL clock divided by 59 */
    RCC_HXTL_AWK_DIV_60,        /*!< HXTL clock divided by 60 */
    RCC_HXTL_AWK_DIV_61,        /*!< HXTL clock divided by 61 */
    RCC_HXTL_AWK_DIV_62,        /*!< HXTL clock divided by 62 */
    RCC_HXTL_AWK_DIV_63,        /*!< HXTL clock divided by 63 */
    RCC_HXTL_AWK_DIV_64,        /*!< HXTL clock divided by 64 */
    RCC_HXTL_AWK_DIV_65,        /*!< HXTL clock divided by 65 */
    RCC_HXTL_AWK_DIV_66,        /*!< HXTL clock divided by 66 */
    RCC_HXTL_AWK_DIV_67,        /*!< HXTL clock divided by 67 */
    RCC_HXTL_AWK_DIV_68,        /*!< HXTL clock divided by 68 */
    RCC_HXTL_AWK_DIV_69,        /*!< HXTL clock divided by 69 */
    RCC_HXTL_AWK_DIV_70,        /*!< HXTL clock divided by 70 */
    RCC_HXTL_AWK_DIV_71,        /*!< HXTL clock divided by 71 */
    RCC_HXTL_AWK_DIV_72,        /*!< HXTL clock divided by 72 */
    RCC_HXTL_AWK_DIV_73,        /*!< HXTL clock divided by 73 */
    RCC_HXTL_AWK_DIV_74,        /*!< HXTL clock divided by 74 */
    RCC_HXTL_AWK_DIV_75,        /*!< HXTL clock divided by 75 */
    RCC_HXTL_AWK_DIV_76,        /*!< HXTL clock divided by 76 */
    RCC_HXTL_AWK_DIV_77,        /*!< HXTL clock divided by 77 */
    RCC_HXTL_AWK_DIV_78,        /*!< HXTL clock divided by 78 */
    RCC_HXTL_AWK_DIV_79,        /*!< HXTL clock divided by 79 */
    RCC_HXTL_AWK_DIV_80,        /*!< HXTL clock divided by 80 */
    RCC_HXTL_AWK_DIV_81,        /*!< HXTL clock divided by 81 */
    RCC_HXTL_AWK_DIV_82,        /*!< HXTL clock divided by 82 */
    RCC_HXTL_AWK_DIV_83,        /*!< HXTL clock divided by 83 */
    RCC_HXTL_AWK_DIV_84,        /*!< HXTL clock divided by 84 */
    RCC_HXTL_AWK_DIV_85,        /*!< HXTL clock divided by 85 */
    RCC_HXTL_AWK_DIV_86,        /*!< HXTL clock divided by 86 */
    RCC_HXTL_AWK_DIV_87,        /*!< HXTL clock divided by 87 */
    RCC_HXTL_AWK_DIV_88,        /*!< HXTL clock divided by 88 */
    RCC_HXTL_AWK_DIV_89,        /*!< HXTL clock divided by 89 */
    RCC_HXTL_AWK_DIV_90,        /*!< HXTL clock divided by 90 */
    RCC_HXTL_AWK_DIV_91,        /*!< HXTL clock divided by 91 */
    RCC_HXTL_AWK_DIV_92,        /*!< HXTL clock divided by 92 */
    RCC_HXTL_AWK_DIV_93,        /*!< HXTL clock divided by 93 */
    RCC_HXTL_AWK_DIV_94,        /*!< HXTL clock divided by 94 */
    RCC_HXTL_AWK_DIV_95,        /*!< HXTL clock divided by 95 */
    RCC_HXTL_AWK_DIV_96,        /*!< HXTL clock divided by 96 */
    RCC_HXTL_AWK_DIV_97,        /*!< HXTL clock divided by 97 */
    RCC_HXTL_AWK_DIV_98,        /*!< HXTL clock divided by 98 */
    RCC_HXTL_AWK_DIV_99,        /*!< HXTL clock divided by 99 */
    RCC_HXTL_AWK_DIV_100,       /*!< HXTL clock divided by 100 */
    RCC_HXTL_AWK_DIV_101,       /*!< HXTL clock divided by 101 */
    RCC_HXTL_AWK_DIV_102,       /*!< HXTL clock divided by 102 */
    RCC_HXTL_AWK_DIV_103,       /*!< HXTL clock divided by 103 */
    RCC_HXTL_AWK_DIV_104,       /*!< HXTL clock divided by 104 */
    RCC_HXTL_AWK_DIV_105,       /*!< HXTL clock divided by 105 */
    RCC_HXTL_AWK_DIV_106,       /*!< HXTL clock divided by 106 */
    RCC_HXTL_AWK_DIV_107,       /*!< HXTL clock divided by 107 */
    RCC_HXTL_AWK_DIV_108,       /*!< HXTL clock divided by 108 */
    RCC_HXTL_AWK_DIV_109,       /*!< HXTL clock divided by 109 */
    RCC_HXTL_AWK_DIV_110,       /*!< HXTL clock divided by 110 */
    RCC_HXTL_AWK_DIV_111,       /*!< HXTL clock divided by 111 */
    RCC_HXTL_AWK_DIV_112,       /*!< HXTL clock divided by 112 */
    RCC_HXTL_AWK_DIV_113,       /*!< HXTL clock divided by 113 */
    RCC_HXTL_AWK_DIV_114,       /*!< HXTL clock divided by 114 */
    RCC_HXTL_AWK_DIV_115,       /*!< HXTL clock divided by 115 */
    RCC_HXTL_AWK_DIV_116,       /*!< HXTL clock divided by 116 */
    RCC_HXTL_AWK_DIV_117,       /*!< HXTL clock divided by 117 */
    RCC_HXTL_AWK_DIV_118,       /*!< HXTL clock divided by 118 */
    RCC_HXTL_AWK_DIV_119,       /*!< HXTL clock divided by 119 */
    RCC_HXTL_AWK_DIV_120,       /*!< HXTL clock divided by 120 */
    RCC_HXTL_AWK_DIV_121,       /*!< HXTL clock divided by 121 */
    RCC_HXTL_AWK_DIV_122,       /*!< HXTL clock divided by 122 */
    RCC_HXTL_AWK_DIV_123,       /*!< HXTL clock divided by 123 */
    RCC_HXTL_AWK_DIV_124,       /*!< HXTL clock divided by 124 */
    RCC_HXTL_AWK_DIV_125,       /*!< HXTL clock divided by 125 */
    RCC_HXTL_AWK_DIV_126,       /*!< HXTL clock divided by 126 */
    RCC_HXTL_AWK_DIV_127,       /*!< HXTL clock divided by 127 */
    RCC_HXTL_AWK_DIV_128,       /*!< HXTL clock divided by 128 */
    RCC_HXTL_AWK_DIV_129,       /*!< HXTL clock divided by 129 */
    RCC_HXTL_AWK_DIV_130,       /*!< HXTL clock divided by 130 */
    RCC_HXTL_AWK_DIV_131,       /*!< HXTL clock divided by 131 */
    RCC_HXTL_AWK_DIV_132,       /*!< HXTL clock divided by 132 */
    RCC_HXTL_AWK_DIV_133,       /*!< HXTL clock divided by 133 */
    RCC_HXTL_AWK_DIV_134,       /*!< HXTL clock divided by 134 */
    RCC_HXTL_AWK_DIV_135,       /*!< HXTL clock divided by 135 */
    RCC_HXTL_AWK_DIV_136,       /*!< HXTL clock divided by 136 */
    RCC_HXTL_AWK_DIV_137,       /*!< HXTL clock divided by 137 */
    RCC_HXTL_AWK_DIV_138,       /*!< HXTL clock divided by 138 */
    RCC_HXTL_AWK_DIV_139,       /*!< HXTL clock divided by 139 */
    RCC_HXTL_AWK_DIV_140,       /*!< HXTL clock divided by 140 */
    RCC_HXTL_AWK_DIV_141,       /*!< HXTL clock divided by 141 */
    RCC_HXTL_AWK_DIV_142,       /*!< HXTL clock divided by 142 */
    RCC_HXTL_AWK_DIV_143,       /*!< HXTL clock divided by 143 */
    RCC_HXTL_AWK_DIV_144,       /*!< HXTL clock divided by 144 */
    RCC_HXTL_AWK_DIV_145,       /*!< HXTL clock divided by 145 */
    RCC_HXTL_AWK_DIV_146,       /*!< HXTL clock divided by 146 */
    RCC_HXTL_AWK_DIV_147,       /*!< HXTL clock divided by 147 */
    RCC_HXTL_AWK_DIV_148,       /*!< HXTL clock divided by 148 */
    RCC_HXTL_AWK_DIV_149,       /*!< HXTL clock divided by 149 */
    RCC_HXTL_AWK_DIV_150,       /*!< HXTL clock divided by 150 */
    RCC_HXTL_AWK_DIV_151,       /*!< HXTL clock divided by 151 */
    RCC_HXTL_AWK_DIV_152,       /*!< HXTL clock divided by 152 */
    RCC_HXTL_AWK_DIV_153,       /*!< HXTL clock divided by 153 */
    RCC_HXTL_AWK_DIV_154,       /*!< HXTL clock divided by 154 */
    RCC_HXTL_AWK_DIV_155,       /*!< HXTL clock divided by 155 */
    RCC_HXTL_AWK_DIV_156,       /*!< HXTL clock divided by 156 */
    RCC_HXTL_AWK_DIV_157,       /*!< HXTL clock divided by 157 */
    RCC_HXTL_AWK_DIV_158,       /*!< HXTL clock divided by 158 */
    RCC_HXTL_AWK_DIV_159,       /*!< HXTL clock divided by 159 */
    RCC_HXTL_AWK_DIV_160,       /*!< HXTL clock divided by 160 */
    RCC_HXTL_AWK_DIV_161,       /*!< HXTL clock divided by 161 */
    RCC_HXTL_AWK_DIV_162,       /*!< HXTL clock divided by 162 */
    RCC_HXTL_AWK_DIV_163,       /*!< HXTL clock divided by 163 */
    RCC_HXTL_AWK_DIV_164,       /*!< HXTL clock divided by 164 */
    RCC_HXTL_AWK_DIV_165,       /*!< HXTL clock divided by 165 */
    RCC_HXTL_AWK_DIV_166,       /*!< HXTL clock divided by 166 */
    RCC_HXTL_AWK_DIV_167,       /*!< HXTL clock divided by 167 */
    RCC_HXTL_AWK_DIV_168,       /*!< HXTL clock divided by 168 */
    RCC_HXTL_AWK_DIV_169,       /*!< HXTL clock divided by 169 */
    RCC_HXTL_AWK_DIV_170,       /*!< HXTL clock divided by 170 */
    RCC_HXTL_AWK_DIV_171,       /*!< HXTL clock divided by 171 */
    RCC_HXTL_AWK_DIV_172,       /*!< HXTL clock divided by 172 */
    RCC_HXTL_AWK_DIV_173,       /*!< HXTL clock divided by 173 */
    RCC_HXTL_AWK_DIV_174,       /*!< HXTL clock divided by 174 */
    RCC_HXTL_AWK_DIV_175,       /*!< HXTL clock divided by 175 */
    RCC_HXTL_AWK_DIV_176,       /*!< HXTL clock divided by 176 */
    RCC_HXTL_AWK_DIV_177,       /*!< HXTL clock divided by 177 */
    RCC_HXTL_AWK_DIV_178,       /*!< HXTL clock divided by 178 */
    RCC_HXTL_AWK_DIV_179,       /*!< HXTL clock divided by 179 */
    RCC_HXTL_AWK_DIV_180,       /*!< HXTL clock divided by 180 */
    RCC_HXTL_AWK_DIV_181,       /*!< HXTL clock divided by 181 */
    RCC_HXTL_AWK_DIV_182,       /*!< HXTL clock divided by 182 */
    RCC_HXTL_AWK_DIV_183,       /*!< HXTL clock divided by 183 */
    RCC_HXTL_AWK_DIV_184,       /*!< HXTL clock divided by 184 */
    RCC_HXTL_AWK_DIV_185,       /*!< HXTL clock divided by 185 */
    RCC_HXTL_AWK_DIV_186,       /*!< HXTL clock divided by 186 */
    RCC_HXTL_AWK_DIV_187,       /*!< HXTL clock divided by 187 */
    RCC_HXTL_AWK_DIV_188,       /*!< HXTL clock divided by 188 */
    RCC_HXTL_AWK_DIV_189,       /*!< HXTL clock divided by 189 */
    RCC_HXTL_AWK_DIV_190,       /*!< HXTL clock divided by 190 */
    RCC_HXTL_AWK_DIV_191,       /*!< HXTL clock divided by 191 */
    RCC_HXTL_AWK_DIV_192,       /*!< HXTL clock divided by 192 */
    RCC_HXTL_AWK_DIV_193,       /*!< HXTL clock divided by 193 */
    RCC_HXTL_AWK_DIV_194,       /*!< HXTL clock divided by 194 */
    RCC_HXTL_AWK_DIV_195,       /*!< HXTL clock divided by 195 */
    RCC_HXTL_AWK_DIV_196,       /*!< HXTL clock divided by 196 */
    RCC_HXTL_AWK_DIV_197,       /*!< HXTL clock divided by 197 */
    RCC_HXTL_AWK_DIV_198,       /*!< HXTL clock divided by 198 */
    RCC_HXTL_AWK_DIV_199,       /*!< HXTL clock divided by 199 */
    RCC_HXTL_AWK_DIV_200,       /*!< HXTL clock divided by 200 */
    RCC_HXTL_AWK_DIV_201,       /*!< HXTL clock divided by 201 */
    RCC_HXTL_AWK_DIV_202,       /*!< HXTL clock divided by 202 */
    RCC_HXTL_AWK_DIV_203,       /*!< HXTL clock divided by 203 */
    RCC_HXTL_AWK_DIV_204,       /*!< HXTL clock divided by 204 */
    RCC_HXTL_AWK_DIV_205,       /*!< HXTL clock divided by 205 */
    RCC_HXTL_AWK_DIV_206,       /*!< HXTL clock divided by 206 */
    RCC_HXTL_AWK_DIV_207,       /*!< HXTL clock divided by 207 */
    RCC_HXTL_AWK_DIV_208,       /*!< HXTL clock divided by 208 */
    RCC_HXTL_AWK_DIV_209,       /*!< HXTL clock divided by 209 */
    RCC_HXTL_AWK_DIV_210,       /*!< HXTL clock divided by 210 */
    RCC_HXTL_AWK_DIV_211,       /*!< HXTL clock divided by 211 */
    RCC_HXTL_AWK_DIV_212,       /*!< HXTL clock divided by 212 */
    RCC_HXTL_AWK_DIV_213,       /*!< HXTL clock divided by 213 */
    RCC_HXTL_AWK_DIV_214,       /*!< HXTL clock divided by 214 */
    RCC_HXTL_AWK_DIV_215,       /*!< HXTL clock divided by 215 */
    RCC_HXTL_AWK_DIV_216,       /*!< HXTL clock divided by 216 */
    RCC_HXTL_AWK_DIV_217,       /*!< HXTL clock divided by 217 */
    RCC_HXTL_AWK_DIV_218,       /*!< HXTL clock divided by 218 */
    RCC_HXTL_AWK_DIV_219,       /*!< HXTL clock divided by 219 */
    RCC_HXTL_AWK_DIV_220,       /*!< HXTL clock divided by 220 */
    RCC_HXTL_AWK_DIV_221,       /*!< HXTL clock divided by 221 */
    RCC_HXTL_AWK_DIV_222,       /*!< HXTL clock divided by 222 */
    RCC_HXTL_AWK_DIV_223,       /*!< HXTL clock divided by 223 */
    RCC_HXTL_AWK_DIV_224,       /*!< HXTL clock divided by 224 */
    RCC_HXTL_AWK_DIV_225,       /*!< HXTL clock divided by 225 */
    RCC_HXTL_AWK_DIV_226,       /*!< HXTL clock divided by 226 */
    RCC_HXTL_AWK_DIV_227,       /*!< HXTL clock divided by 227 */
    RCC_HXTL_AWK_DIV_228,       /*!< HXTL clock divided by 228 */
    RCC_HXTL_AWK_DIV_229,       /*!< HXTL clock divided by 229 */
    RCC_HXTL_AWK_DIV_230,       /*!< HXTL clock divided by 230 */
    RCC_HXTL_AWK_DIV_231,       /*!< HXTL clock divided by 231 */
    RCC_HXTL_AWK_DIV_232,       /*!< HXTL clock divided by 232 */
    RCC_HXTL_AWK_DIV_233,       /*!< HXTL clock divided by 233 */
    RCC_HXTL_AWK_DIV_234,       /*!< HXTL clock divided by 234 */
    RCC_HXTL_AWK_DIV_235,       /*!< HXTL clock divided by 235 */
    RCC_HXTL_AWK_DIV_236,       /*!< HXTL clock divided by 236 */
    RCC_HXTL_AWK_DIV_237,       /*!< HXTL clock divided by 237 */
    RCC_HXTL_AWK_DIV_238,       /*!< HXTL clock divided by 238 */
    RCC_HXTL_AWK_DIV_239,       /*!< HXTL clock divided by 239 */
    RCC_HXTL_AWK_DIV_240,       /*!< HXTL clock divided by 240 */
    RCC_HXTL_AWK_DIV_241,       /*!< HXTL clock divided by 241 */
    RCC_HXTL_AWK_DIV_242,       /*!< HXTL clock divided by 242 */
    RCC_HXTL_AWK_DIV_243,       /*!< HXTL clock divided by 243 */
    RCC_HXTL_AWK_DIV_244,       /*!< HXTL clock divided by 244 */
    RCC_HXTL_AWK_DIV_245,       /*!< HXTL clock divided by 245 */
    RCC_HXTL_AWK_DIV_246,       /*!< HXTL clock divided by 246 */
    RCC_HXTL_AWK_DIV_247,       /*!< HXTL clock divided by 247 */
    RCC_HXTL_AWK_DIV_248,       /*!< HXTL clock divided by 248 */
    RCC_HXTL_AWK_DIV_249,       /*!< HXTL clock divided by 249 */
    RCC_HXTL_AWK_DIV_250,       /*!< HXTL clock divided by 250 */
    RCC_HXTL_AWK_DIV_251,       /*!< HXTL clock divided by 251 */
    RCC_HXTL_AWK_DIV_252,       /*!< HXTL clock divided by 252 */
    RCC_HXTL_AWK_DIV_253,       /*!< HXTL clock divided by 253 */
    RCC_HXTL_AWK_DIV_254,       /*!< HXTL clock divided by 254 */
    RCC_HXTL_AWK_DIV_255,       /*!< HXTL clock divided by 255 */
    RCC_HXTL_AWK_DIV_256        /*!< HXTL clock divided by 256 */
} RCC_HxtlAwkDivSelection;

/**
  * @}
  */

/** @defgroup RCC_TRACECLOCKDIVSELECTION RCC TRACE Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the TRACE clock divider relative to HCLK.
  */
typedef enum {
    RCC_TRACE_DIV_1 = 0U,    /*!< TRACE clock divided by HCLK 1 */
    RCC_TRACE_DIV_2,         /*!< TRACE clock divided by HCLK 2 */
    RCC_TRACE_DIV_4,         /*!< TRACE clock divided by HCLK 4 */
    RCC_TRACE_DIV_8,         /*!< TRACE clock divided by HCLK 8 */
    RCC_TRACE_DIV_16         /*!< TRACE clock divided by HCLK 16 */
} RCC_TraceClockDivSelection;

/**
  * @}
  */

  /** @defgroup RCC_EMIFCLOCKDIVSELECTION RCC EMIF Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the EMIF clock divider relative to HCLK.
  */
typedef enum {
    RCC_EMIF_DIV_1 = 0U,    /*!< EMIF clock divided by HCLK 1 */
    RCC_EMIF_DIV_2,         /*!< EMIF clock divided by HCLK 2 */
    RCC_EMIF_DIV_4,         /*!< EMIF clock divided by HCLK 4 */
    RCC_EMIF_DIV_8,         /*!< EMIF clock divided by HCLK 8 */
    RCC_EMIF_DIV_16         /*!< EMIF clock divided by HCLK 16 */
} RCC_EmifClockDivSelection;

/**
  * @}
  */

/** @defgroup EPWMCLKDIV RCC FLASH Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the EPWMCLK clock divider relative to HCLK.
  */
typedef enum {
    RCC_EPWM_DIV_1 = 0U,    /*!< FLASH clock divided by HCLK 1 */
    RCC_EPWM_DIV_2          /*!< FLASH clock divided by HCLK 2 */
} RCC_EPWMClockDivSelection;

/**
  * @}
  */

/** @defgroup RCC_FLASHCLOCKDIVSELECTION RCC FLASH Clock Divider Selection
  * @{
  * @brief  Defines the possible values for configuring the FLASH clock divider relative to HCLK.
  */
typedef enum {
    RCC_FLASH_DIV_1 = 0U,    /*!< FLASH clock divided by HCLK 1 */
    RCC_FLASH_DIV_2,         /*!< FLASH clock divided by HCLK 2 */
    RCC_FLASH_DIV_4,         /*!< FLASH clock divided by HCLK 4 */
    RCC_FLASH_DIV_8,         /*!< FLASH clock divided by HCLK 8 */
    RCC_FLASH_DIV_16         /*!< FLASH clock divided by HCLK 16 */
} RCC_FlashClockDivSelection;

/**
  * @}
  */

/** @defgroup RCC_LOOPFILTERCAPSELECTION RCC loopFilterCap Selection
  * @{
  * @brief  Defines the possible values for configuring the loopFilterCap.
  */
typedef enum {
    RCC_LOOP_FILTER_CAP_40PF   = 4U,    /*!< Loop Filter Capacitance: 40 pF */
    RCC_LOOP_FILTER_CAP_64_5PF = 6U,    /*!< Loop Filter Capacitance: 64.5 pF */
    RCC_LOOP_FILTER_CAP_84PF   = 7U     /*!< Loop Filter Capacitance: 84 pF */
} RCC_LoopFilterCapSelection;

/**
  * @}
  */

/** @defgroup RCC_CHARGEPUMPCURRENTSELECTION RCC Charge Pump Current Selection
  * @{
  * @brief  Defines the possible values for configuring the Charge Pump Current.
  */
typedef enum {
    RCC_ICP_2UA = 0U,    /*!< Charge Pump Current: 2 µA */
    RCC_ICP_1UA,         /*!< Charge Pump Current: 1 µA */
    RCC_ICP_4UA          /*!< Charge Pump Current: 4 µA */
} RCC_ChargePumpCurrentSelection;

/**
  * @}
  */

/** @defgroup RCC_LOOPFILTERRESSELECTION RCC loopFilterRes Selection
  * @{
  * @brief  Defines the possible values for configuring the loopFilterRes.
  */
typedef enum {
    RCC_LOOP_FILTER_RES_45K = 0U,    /*!< Loop Filter Resistor: 45 kΩ */
    RCC_LOOP_FILTER_RES_20K = 2U,    /*!< Loop Filter Resistor: 20 kΩ */
    RCC_LOOP_FILTER_RES_10K = 3U     /*!< Loop Filter Resistor: 10 kΩ */
} RCC_LoopFilterResSelection;

/**
  * @}
  */

/** @defgroup RCC_VCOFREQUENCYSELECTION RCC VCO Frequency Selection
  * @{
  * @brief  Defines the possible values for configuring the vco frequency.
  */
typedef enum {
    RCC_VCO_200_400M = 0U,    /*!< VCO Frequency Range: 200 MHz to 400 MHz */
    RCC_VCO_200_600M,         /*!< VCO Frequency Range: 200 MHz to 600 MHz */
    RCC_VCO_300_750M,         /*!< VCO Frequency Range: 300 MHz to 750 MHz */
    RCC_VCO_400_800M          /*!< VCO Frequency Range: 400 MHz to 800 MHz */
} RCC_VcoFrequencySelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLFILTENABLESELECTION RCC HXTL Filter Enable Selection
  * @{
  * @brief  Defines the possible values for enabling or disabling the HXTL filter.
  */
typedef enum {
    RCC_HXTL_FILT_DISABLE = 0U,    /*!< HXTL Filter: Disabled */
    RCC_HXTL_FILT_ENABLE          /*!< HXTL Filter: Enabled */
} RCC_HxtlFiltEnableSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLRFENABLESELECTION RCC HXTL Feedback Resistor Enable Selection
  * @{
  * @brief  Defines the possible values for enabling or disabling the HXTL feedback resistor.
  */
typedef enum {
    RCC_HXTL_RF_DISABLE = 0U,    /*!< HXTL Feedback Resistor: Disabled */
    RCC_HXTL_RF_ENABLE           /*!< HXTL Feedback Resistor: Enabled */
} RCC_HxtlRfEnableSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLRFSELECTION RCC hxtlRf Selection
  * @{
  * @brief  Defines the possible values for configuring the hxtlRf.
  */
typedef enum {
    RCC_HXTL_RF_1_4M = 0U,    /*!< HXTL Feedback Resistor: 1.4 M, the usage frequency range is from 8~15MHz. */
    RCC_HXTL_RF_0_8M          /*!< HXTL Feedback Resistor: 0.8 M, the usage frequency range is from 16~32MHz. */
} RCC_HxtlRfSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLPORTSELECTION RCC hxtlRf Selection
  * @{
  * @brief  Defines the possible values for configuring the hxtlRf.
  */
typedef enum {
    RCC_HXTL_PORT_GPIO = 0U,    /*!< HXTL GPIO function mode (digital function) */
    RCC_HXTL_PORT_HXT           /*!< HXTL HXT Pin Mode (Analog Function) */
} RCC_HxtlPortSelection;

/**
  * @}
  */

/** @defgroup RCC_HXTLSTSSELECTION  RCC hxtlSts Selection
  * @{
  * @brief  Defines the possible values for configuring the hxtlSts.
  */
typedef enum {
    RCC_HXTL_STS_1024 = 0U,    /*!< HXTL Stabilization Time: 1024 cycles */
    RCC_HXTL_STS_2048,         /*!< HXTL Stabilization Time: 2048 cycles */
    RCC_HXTL_STS_4096,         /*!< HXTL Stabilization Time: 4096 cycles */
    RCC_HXTL_STS_16384         /*!< HXTL Stabilization Time: 16384 cycles */
} RCC_HxtlStsSelection;

/**
  * @}
  */

 /** @defgroup RCC_HXTLMFSELECTION RCC hxtlMf Selection
  * @{
  * @brief  Defines the possible values for configuring the hxtlMf.
  */
typedef enum {
    RCC_HXTL_8M_AGC_DISABLE  = 0x54U,    /*!< HXTL Frequency: 8 MHz, AGC Disabled */
    RCC_HXTL_12M_AGC_DISABLE = 0x76U,    /*!< HXTL Frequency: 12 MHz, AGC Disabled */
    RCC_HXTL_16M_AGC_DISABLE = 0x98U,    /*!< HXTL Frequency: 16 MHz, AGC Disabled */
    RCC_HXTL_24M_AGC_DISABLE = 0xBAU,    /*!< HXTL Frequency: 24 MHz, AGC Disabled */
    RCC_HXTL_32M_AGC_DISABLE = 0xDCU,    /*!< HXTL Frequency: 32 MHz, AGC Disabled */
    RCC_HXTL_8M_AGC_ENABLE   = 0x44U,    /*!< HXTL Frequency: 8 MHz, AGC Enabled */
    RCC_HXTL_12M_AGC_ENABLE  = 0x66U,    /*!< HXTL Frequency: 12 MHz, AGC Enabled */
    RCC_HXTL_16M_AGC_ENABLE  = 0x88U,    /*!< HXTL Frequency: 16 MHz, AGC Enabled */
    RCC_HXTL_24M_AGC_ENABLE  = 0xAAU,    /*!< HXTL Frequency: 24 MHz, AGC Enabled */
    RCC_HXTL_32M_AGC_ENABLE  = 0xCCU     /*!< HXTL Frequency: 32 MHz, AGC Enabled */
} RCC_HxtlMfSelection;

/**
  * @}
  */

 /** @defgroup RCC_MIRC1MIRC2CYCSELECTION RCC mirc1Mirc2Cyc Selection
  * @{
  * @brief  Defines the possible values for configuring the Mirc1 Mirc2 Cyc.
  */
typedef enum {
    RCC_MIRC1_8192_MIRC2_256 = 0x0U,    /*!< MIRC1: 8192 cycles, MIRC2: 256 cycles */
    RCC_MIRC1_16384_MIRC2_512,          /*!< MIRC1: 16384 cycles, MIRC2: 512 cycles */
    RCC_MIRC1_32768_MIRC2_1024,         /*!< MIRC1: 32768 cycles, MIRC2: 1024 cycles */
    RCC_MIRC1_65536_MIRC2_2048,         /*!< MIRC1: 65536 cycles, MIRC2: 2048 cycles */
    RCC_MIRC1_131072_MIRC2_4096,        /*!< MIRC1: 131072 cycles, MIRC2: 4096 cycles */
    RCC_MIRC1_262144_MIRC2_8192,        /*!< MIRC1: 262144 cycles, MIRC2: 8192 cycles */
    RCC_MIRC1_524288_MIRC2_16384,       /*!< MIRC1: 524288 cycles, MIRC2: 16384 cycles */
    RCC_MIRC1_1048576_MIRC2_32768       /*!< MIRC1: 1048576 cycles, MIRC2: 32768 cycles */
} RCC_Mirc1Mirc2CycSelection;

/**
  * @}
  */

/** @defgroup RCC_MCDINTSELECTION RCC Fault interruption source Selection
  * @{
  * @brief  When MCD fails, NMI/CMU interrupt is generated.
  */
typedef enum {
    RCC_MCDINTSEL_NMI = 0x0U,    /*!< When MCD fails, NMI interrupt is generated. */
    RCC_MCDINTSEL_CMU            /*!< When MCD fails, CMU interrupt is generated. */
} RCC_McdIntSelection;

/**
  * @}
  */

/** @defgroup RCC_INTSOURCESELECTION RCC Interrupt Source Selection
  * @{
  * @brief  Defines the possible values for configuring the RCC interrupt sources.
  */
typedef enum {
    RCC_MIRC2RDY    = 0x00000002U,    /*!< MIRC2 Ready Interrupt */
    RCC_MIRC1RDY    = 0x00000200U,    /*!< MIRC1 Ready Interrupt */
    RCC_LIRCRDY     = 0x00008000U,    /*!< Low Impedance Reference Ready Interrupt */
    RCC_HXTLRDY     = 0x00020000U,    /*!< High-Speed Crystal Oscillator Ready Interrupt */
    RCC_HXTLFAIL    = 0x00100000U,    /*!< High-Speed Crystal Oscillator Failure Interrupt */
    RCC_PLL_LKDT    = 0x02000000U,    /*!< PLL Lock Detection Interrupt */
    RCC_PLL_LOL     = 0x20000000U,    /*!< PLL Loss of Lock Interrupt */
    RCC_OSCCLK_STOP = 0x80000000U     /*!< OSCCLK Stop Interrupt */
} RCC_IntSourceSelection;

/**
  * @}
  */

/** @defgroup RCC_CRMASKS RCC_CR Masks
  * @{
  * @brief  Macro definitions about RCC_CR mask definition.
  */
#define RCC_PLLLOL_RST_M      (0x1UL << 27)    /*!< PLL lock loss reset enable bit */
#define RCC_PLL_LKDT_M        (0x1UL << 25)    /*!< PLL lock detect enable bit */
#define RCC_PLLEN_M           (0x1UL << 24)    /*!< PLL enable bit */
#define RCC_HXTLKEREN_M       (0x1UL << 23)    /*!< High-speed external crystal oscillator kernel enable bit */
#define RCC_HXTLFAIL_RST_M    (0x1UL << 21)    /*!< High-speed external crystal oscillator failure reset enable bit */
#define RCC_HXTLDETEN_M       (0x1UL << 19)    /*!< High-speed external crystal oscillator detection enable bit */
#define RCC_HXTLBYP_M         (0x1UL << 18)    /*!< High-speed external crystal oscillator bypass enable bit */
#define RCC_HXTLRDY_M         (0x1UL << 17)    /*!< High-speed external crystal oscillator ready bit */
#define RCC_HXTLEN_M          (0x1UL << 16)    /*!< High-speed external crystal oscillator enable bit */
#define RCC_LIRCRDY_M         (0x1UL << 15)    /*!< Low-speed internal RC oscillator ready bit */
#define RCC_LIRCEN_M          (0x1UL << 14)    /*!< Low-speed internal RC oscillator enable bit */
#define RCC_MIRC1KEREN_M      (0x1UL << 11)    /*!< Medium-speed internal RC oscillator 1 kernel enable bit */
#define RCC_MIRC1RDY_M        (0x1UL << 9)     /*!< Medium-speed internal RC oscillator 1 ready bit */
#define RCC_MIRC1EN_M         (0x1UL << 8)     /*!< Medium-speed internal RC oscillator 1 enable bit */
#define RCC_MIRC2KEREN_M      (0x1UL << 3)     /*!< Medium-speed internal RC oscillator 2 kernel enable bit */
#define RCC_MIRC2RDY_M        (0x1UL << 1)     /*!< Medium-speed internal RC oscillator 2 ready bit */
#define RCC_MIRC2EN_M         (0x1UL << 0)     /*!< Medium-speed internal RC oscillator 2 enable bit */

/**
  * @}
  */

/** @defgroup RCC_MCOCRMASKS RCC_MCOCR Masks
  * @{
  * @brief  Macro definitions about RCC_MCOCR mask definition.
  */
#define RCC_MCO2EN_S     (28UL)            /*!< Microcontroller Clock Output 2 enable shift */
#define RCC_MCO2EN_M     (0x1UL << 28)     /*!< Microcontroller Clock Output 2 enable bit */
#define RCC_MCO2SEL_S    (24UL)            /*!< Microcontroller Clock Output 2 source selection shift */
#define RCC_MCO2SEL_M    (0x7UL << 24)     /*!< Microcontroller Clock Output 2 source selection mask */
#define RCC_MCO2DIV_S    (16UL)            /*!< Microcontroller Clock Output 2 prescaler shift */
#define RCC_MCO2DIV_M    (0xFFUL << 16)    /*!< Microcontroller Clock Output 2 prescaler mask */
#define RCC_MCO1EN_S     (12UL)            /*!< Microcontroller Clock Output 1 enable shift */
#define RCC_MCO1EN_M     (0x1UL << 12)     /*!< Microcontroller Clock Output 1 enable bit */
#define RCC_MCO1SEL_S    (8UL)             /*!< Microcontroller Clock Output 1 source selection shift */
#define RCC_MCO1SEL_M    (0x7UL << 8)      /*!< Microcontroller Clock Output 1 source selection mask */
#define RCC_MCO1DIV_S    (0UL)             /*!< Microcontroller Clock Output 1 prescaler shift */
#define RCC_MCO1DIV_M    (0xFFUL << 0)     /*!< Microcontroller Clock Output 1 prescaler mask */

/**
  * @}
  */

/** @defgroup RCC_CFGRMASKS RCC_CFGR Masks
  * @{
  * @brief  Macro definitions about RCC_CFGR mask definition.
  */
#define RCC_APB5DIV_S    (28UL)           /*!< APB5 clock division shift */
#define RCC_APB5DIV_M    (0x7UL << 28)    /*!< APB5 clock division mask */
#define RCC_APB2DIV_S    (24UL)           /*!< APB2 clock division shift */
#define RCC_APB2DIV_M    (0x7UL << 24)    /*!< APB2 clock division mask */
#define RCC_APB1DIV_S    (20UL)           /*!< APB1 clock division shift */
#define RCC_APB1DIV_M    (0x7UL << 20)    /*!< APB1 clock division mask */
#define RCC_SYSDIV_S     (8UL)            /*!< System clock division shift */
#define RCC_SYSDIV_M     (0xFUL << 8)     /*!< System clock division mask */
#define RCC_SWSTA_S      (4UL)            /*!< System switch status shift */
#define RCC_SWSTA_M      (0x3UL << 4)     /*!< System switch status mask */
#define RCC_SWSEL_S      (0UL)            /*!< System switch selection shift */
#define RCC_SWSEL_M      (0x3UL << 0)     /*!< System switch selection mask */

/**
  * @}
  */

/** @defgroup RCC_PLLCRMASK RCC_PLLCR Mask
  * @{
  * @brief  Macro definitions about RCC_PLLCR mask definition.
  */
#define RCC_OFDRDYS_M        (0x1UL << 28)    /*!< OSCCLK fault detection status mask */
#define RCC_OSCCLKDETEN_M    (0x1UL << 3)     /*!< OSCCLK fault detection enable mask */
#define RCC_PLLSRC_M         (0x3UL << 0)     /*!< PLL source selection mask */

/**
  * @}
  */

/** @defgroup RCC_IERMASKS RCC_IER Masks
  * @{
  * @brief  Macro definitions about RCC_IER mask definition.
  */
#define RCC_PLL_OSCCLKSTOPIE_M     (0x1UL << 31)    /*!< OSCCLK stop interrupt enable bit */
#define RCC_PLL_OSCCLKSTOPSEL_S    (30UL)           /*!< OSCCLK interrupt selection shift */
#define RCC_PLL_OSCCLKSTOPSEL_M    (0x1UL << 30)    /*!< OSCCLK interrupt selection bit */
#define RCC_PLL_LOLIE_M            (0x1UL << 29)    /*!< PLL Loss of Lock interrupt enable bit */
#define RCC_PLL_LKDTIE_M           (0x1UL << 25)    /*!< PLL Locked Detection Timer interrupt enable bit */
#define RCC_HXTLFAILIE_M           (0x1UL << 20)    /*!< High-speed external clock failure interrupt enable bit */
#define RCC_HXTLRDYIE_M            (0x1UL << 17)    /*!< High-speed external clock ready interrupt enable bit */
#define RCC_HXTLNFSEL_M            (0x1UL << 16)    /*!< High-speed external clock not selected interrupt enable bit */
#define RCC_LIRCRDYIE_M            (0x1UL << 15)    /*!< Low internal reference clock ready interrupt enable bit */
#define RCC_MIRC1RDYIE_M           (0x1UL << 9)     /*!< Medium internal RC oscillator 1 ready interrupt enable bit */
#define RCC_MIRC2RDYIE_M           (0x1UL << 1)     /*!< Medium internal RC oscillator 2 ready interrupt enable bit */

/**
  * @}
  */

/** @defgroup RCC_IFRMASKS RCC_IFR Masks
  * @{
  * @brief  Macro definitions about RCC_IFR mask definition.
  */
#define RCC_PLL_LOSCCLKSTOPIF_M    (0x1UL << 31)    /*!< OSCCLK stop interrupt flag */
#define RCC_PLL_LOLIF_M            (0x1UL << 29)    /*!< PLL Loss of Lock interrupt flag */
#define RCC_PLL_LKDTIF_M           (0x1UL << 25)    /*!< PLL Locked Detection Timer interrupt flag */
#define RCC_HXTLFAILIF_M           (0x1UL << 20)    /*!< High-speed external clock failure interrupt flag */
#define RCC_HXTLRDYIF_M            (0x1UL << 17)    /*!< High-speed external clock ready interrupt flag */
#define RCC_LIRCRDYIF_M            (0x1UL << 15)    /*!< Low internal reference clock ready interrupt flag */
#define RCC_MIRC1RDYIF_M           (0x1UL << 9)     /*!< Medium internal RC oscillator 1 ready interrupt flag */
#define RCC_MIRC2RDYIF_M           (0x1UL << 1)     /*!< Medium internal RC oscillator 2 ready interrupt flag */

/**
  * @}
  */

/** @defgroup RCC_CLRMASKS RCC_CLR Masks
  * @{
  * @brief  Macro definitions about RCC_CLR mask definition.
  */
#define RCC_PLL_OSCCLKSTOPCLR_M    (0x1UL << 31)    /*!< OSCCLK stop interrupt clear bit */
#define RCC_PLL_LOLCLR_M           (0x1UL << 29)    /*!< PLL Loss of Lock interrupt clear bit */
#define RCC_PLL_LKDTCLR_M          (0x1UL << 25)    /*!< PLL Locked Detection Timer interrupt clear bit */
#define RCC_HXTLFAILCLR_M          (0x1UL << 20)    /*!< High-speed external clock failure interrupt clear bit */
#define RCC_HXTLRDYCLR_M           (0x1UL << 17)    /*!< High-speed external clock ready interrupt clear bit */
#define RCC_LIRCRDYCLR_M           (0x1UL << 15)    /*!< Low internal reference clock ready interrupt clear bit */
#define RCC_MIRC1RDYCLR_M          (0x1UL << 9)     /*!< Medium internal RC oscillator 1 ready interrupt clear bit */
#define RCC_MIRC2RDYCLR_M          (0x1UL << 1)     /*!< Medium internal RC oscillator 2 ready interrupt clear bit */

/**
  * @}
  */

/** @defgroup RCC_IPCLKSELMASKS RCC_IPCLKSEL Masks
  * @{
  * @brief  Macro definitions about RCC_IPCLKSEL mask definition.
  */
#define RCC_AUXCLKEN_M            (0x1UL << 31)    /*!< Auxiliary Clock Enable Mask */
#define RCC_AUXCLKRST_M           (0x1UL << 30)    /*!< Auxiliary Clock Reset Mask */
#define RCC_DLL_CLKEN_M           (0x1UL << 13)    /*!< DLL Clock Enable Mask */
#define RCC_HRPWM_CLKEN_M         (0x1UL << 12)    /*!< High-Resolution PWM Clock Enable Mask */
#define RCC_CAN1_PCLK_ST_M        (0x1UL << 5)     /*!< CAN1 Peripheral Clock Status Mask */
#define RCC_CAN1_TIMECLK_DIV_S    (3UL)            /*!< CAN1 Timebase Clock Divider Shift */
#define RCC_CAN1_TIMECLK_DIV_M    (0x3UL << 3)     /*!< CAN1 Timebase Clock Divider Mask */
#define RCC_CAN1_OSC_SEL_S        (1UL)            /*!< CAN1 Oscillator Selection Shift */
#define RCC_CAN1_OSC_SEL_M        (0x3UL << 1)     /*!< CAN1 Oscillator Selection Mask */
#define RCC_CAN1_CLK_SEL_S        (0UL)            /*!< CAN1 Clock Source Selection Shift */
#define RCC_CAN1_CLK_SEL_M        (0x1UL << 0)     /*!< CAN1 Clock Source Selection Mask */

/**
  * @}
  */

/** @defgroup RCC_PLLCR1MASKS RCC_PLLCR1 Masks
  * @{
  * @brief  Macro definitions for PLL configuration masks.
  * @note   These masks are used to configure the PLL parameters.
  */
#define RCC_PLLM_S    (8UL)            /*!< PLL M multiplier Shift */
#define RCC_PLLM_M    (0xFFUL << 8)    /*!< PLL M multiplier mask */
#define RCC_PLLN_S    (4UL)            /*!< PLL N division Shift */
#define RCC_PLLN_M    (0xFUL << 4)     /*!< PLL N division mask */

/**
  * @}
  */

/** @defgroup RCC_PLLCR2MASKS RCC_PLLCR2 Masks
  * @{
  * @brief  Macro definitions for PLL configuration masks.
  * @note   These masks are used to configure the PLL parameters.
  */
#define RCC_PLLP_S      (17UL)            /*!< PLL P division Shift */
#define RCC_PLLP_M      (0x1FUL << 17)    /*!< PLL P division mask */
#define RCC_PLLPEN_S    (16UL)            /*!< PLL P enable Shift */
#define RCC_PLLPEN_M    (0x1UL << 16)     /*!< PLL P enable mask */
#define RCC_PLLQ_S      (9UL)             /*!< PLL Q division Shift */
#define RCC_PLLQ_M      (0x1FUL << 9)     /*!< PLL Q division mask */
#define RCC_PLLQEN_S    (8UL)             /*!< PLL Q enable Shift */
#define RCC_PLLQEN_M    (0x1UL << 8)      /*!< PLL Q enable mask */
#define RCC_PLLR_S      (1UL)             /*!< PLL R division Shift */
#define RCC_PLLR_M      (0x1FUL << 1)     /*!< PLL R division mask */
#define RCC_PLLREN_S    (0UL)             /*!< PLL R enable Shift */
#define RCC_PLLREN_M    (0x1UL << 0)      /*!< PLL R enable mask */

/**
  * @}
  */

/** @defgroup RCC_PLLCR3MASKS RCC_PLLCR3 Masks
  * @{
  * @brief  Macro definitions for PLL configuration masks.
  * @note   These masks are used to configure the PLL parameters.
  */
#define RCC_FORCELKEN_S     (4UL)           /*!< Force Lock Enable Shift */
#define RCC_FORCELKEN_M     (0x1UL << 4)    /*!< Force Lock Enable mask */
#define RCC_PLLLKDTSET_S    (0UL)           /*!< PLL Lock Detect Time Set Shift */
#define RCC_PLLLKDTSET_M    (0x3UL << 0)    /*!< PLL Lock Detect Time Set mask */

/**
  * @}
  */

/** @defgroup RCC_AHBRST1MASKS RCC_AHBRST1 Masks
  * @{
  * @brief  Macro definitions for AHB1 peripheral reset masks.
  * @note   These masks are used to reset various AHB1 peripherals.
  */
#define RCC_AHB_GPIOHRST_M      (0x1UL << 23)    /*!< GPIOH reset mask */
#define RCC_AHB_GPIOCRST_M      (0x1UL << 18)    /*!< GPIOC reset mask */
#define RCC_AHB_GPIOBRST_M      (0x1UL << 17)    /*!< GPIOB reset mask */
#define RCC_AHB_GPIOARST_M      (0x1UL << 16)    /*!< GPIOA reset mask */
#define RCC_AHB_MMATHRST_M      (0x1UL << 15)    /*!< MMATH reset mask */
#define RCC_AHB_EDMA1RST_M      (0x1UL << 8)     /*!< EDMA1 reset mask */
#define RCC_AHB_DMAMUX1RST_M    (0x1UL << 4)     /*!< DMAMUX1 reset mask */

/**
  * @}
  */

/** @defgroup RCC_AHBRST2MASKS RCC_AHBRST2 Masks
  * @{
  * @brief  Macro definitions for AHB2 peripheral reset masks.
  * @note   These masks are used to reset various AHB2 peripherals.
  */
#define RCC_AHB_CAN1RST_M      (0x1UL << 12)    /*!< CAN1 reset mask */
#define RCC_AHB_LIN1RST_M      (0x1UL << 8)     /*!< LIN1 reset mask */
#define RCC_AHB_BGCRC1RST_M    (0x1UL << 2)     /*!< BGCRC1 reset mask */

/**
  * @}
  */

/** @defgroup RCC_APBRST1MASKS RCC_APBRST1 Masks
  * @{
  * @brief  Macro definitions for APB1 peripheral reset masks.
  * @note   These masks are used to reset various APB1 peripherals.
  */
#define RCC_APB_EQEP2RST_M    (0x1UL << 25)    /*!< EQEP2 reset mask */
#define RCC_APB_EQEP1RST_M    (0x1UL << 24)    /*!< EQEP1 reset mask */
#define RCC_APB_ECAP3RST_M    (0x1UL << 18)    /*!< ECAP3 reset mask */
#define RCC_APB_ECAP2RST_M    (0x1UL << 17)    /*!< ECAP2 reset mask */
#define RCC_APB_ECAP1RST_M    (0x1UL << 16)    /*!< ECAP1 reset mask */
#define RCC_APB_EPWM7RST_M    (0x1UL << 6)     /*!< EPWM7 reset mask */
#define RCC_APB_EPWM6RST_M    (0x1UL << 5)     /*!< EPWM6 reset mask */
#define RCC_APB_EPWM5RST_M    (0x1UL << 4)     /*!< EPWM5 reset mask */
#define RCC_APB_EPWM4RST_M    (0x1UL << 3)     /*!< EPWM4 reset mask */
#define RCC_APB_EPWM3RST_M    (0x1UL << 2)     /*!< EPWM3 reset mask */
#define RCC_APB_EPWM2RST_M    (0x1UL << 1)     /*!< EPWM2 reset mask */
#define RCC_APB_EPWM1RST_M    (0x1UL << 0)     /*!< EPWM1 reset mask */

/**
  * @}
  */

/** @defgroup RCC_APBRST2MASKS RCC_APBRST2 Masks
  * @{
  * @brief  Macro definitions for APB2 peripheral reset masks.
  * @note   These masks are used to reset various APB2 peripherals.
  */
#define RCC_APB_CMPSS4RST_M    (0x1UL << 19)    /*!< CMPSS4 reset mask */
#define RCC_APB_CMPSS3RST_M    (0x1UL << 18)    /*!< CMPSS3 reset mask */
#define RCC_APB_CMPSS2RST_M    (0x1UL << 17)    /*!< CMPSS2 reset mask */
#define RCC_APB_CMPSS1RST_M    (0x1UL << 16)    /*!< CMPSS1 reset mask */
#define RCC_APB_XBARRST_M      (0x1UL << 15)    /*!< XBAR reset mask */
#define RCC_APB_ADCCRST_M      (0x1UL << 10)    /*!< ADC C reset mask */
#define RCC_APB_ADCARST_M      (0x1UL << 8)     /*!< ADC A reset mask */

/**
  * @}
  */

/** @defgroup RCC_APBRST3MASKS RCC_APBRST3 Masks
  * @{
  * @brief  Macro definitions for APB3 peripheral reset masks.
  * @note   These masks are used to reset various APB3 peripherals.
  */
#define RCC_APB_ANALOGSSRST_M    (0x1UL << 16)    /*!< Analog subsystem reset mask */

/**
  * @}
  */

/** @defgroup RCC_APBRST5MASKS RCC_APBRST5 Masks
  * @{
  * @brief  Macro definitions for APB5 peripheral reset masks.
  * @note   These masks are used to reset various APB5 peripherals.
  */
#define RCC_APB_DCC1RST_M     (0x1UL << 31)    /*!< DCC1 reset mask */
#define RCC_APB_EPGRST_M      (0x1UL << 24)    /*!< EPG reset mask */
#define RCC_APB_I2C1RST_M     (0x1UL << 16)    /*!< I2C1 reset mask */
#define RCC_APB_SPI2RST_M     (0x1UL << 9)     /*!< SPI2 reset mask */
#define RCC_APB_SPI1RST_M     (0x1UL << 8)     /*!< SPI1 reset mask */
#define RCC_APB_UART1RST_M    (0x1UL << 0)     /*!< UART1 reset mask */

/**
  * @}
  */

/** @defgroup RCC_APBRST6MASKS RCC_APBRST6 Masks
  * @{
  * @brief  Macro definitions for APB6 peripheral reset masks.
  * @note   These masks are used to reset various APB6 peripherals.
  */
#define RCC_APB_STIM3RST_M    (0x1UL << 18)    /*!< CPU1 STIM3 reset mask */
#define RCC_APB_STIM2RST_M    (0x1UL << 17)    /*!< CPU1 STIM2 reset mask */
#define RCC_APB_STIM1RST_M    (0x1UL << 16)    /*!< CPU1 STIM1 reset mask */

/**
  * @}
  */

/** @defgroup RCC_APBRST8MASKS RCC_APBRST8 Masks
  * @{
  * @brief  Macro definitions for APB8 peripheral reset masks.
  * @note   These masks are used to reset various APB8 peripherals.
  */
#define RCC_APB_LPTIMRST_M      (0x1UL << 4)     /*!< LPTIM reset mask */
#define RCC_APB_PWRRST_M        (0x1UL << 0)     /*!< PWR reset mask */

/**
  * @}
  */

/** @defgroup RCC_HCLKEN1MASKS RCC_HCLKEN1 Masks
  * @{
  * @brief  Macro definitions for AHB1 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the AHB1 bus.
  */
#define RCC_AHB_GPIOHEN_M      (0x1UL << 23)    /*!< GPIOH clock enable mask */
#define RCC_AHB_GPIOCEN_M      (0x1UL << 18)    /*!< GPIOC clock enable mask */
#define RCC_AHB_GPIOBEN_M      (0x1UL << 17)    /*!< GPIOB clock enable mask */
#define RCC_AHB_GPIOAEN_M      (0x1UL << 16)    /*!< GPIOA clock enable mask */
#define RCC_AHB_MMATHEN_M      (0x1UL << 15)    /*!< MMATH clock enable mask */
#define RCC_AHB_EDMA1EN_M      (0x1UL << 8)     /*!< EDMA1 clock enable mask */
#define RCC_AHB_DMAMUX1EN_M    (0x1UL << 4)     /*!< DMAMUX1 clock enable mask */

/**
  * @}
  */

/** @defgroup RCC_HCLKEN2MASKS RCC_HCLKEN2 Masks
  * @{
  * @brief  Macro definitions for AHB2 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the AHB2 bus.
  */
#define RCC_AHB_CAN1EN_M      (0x1UL << 12)    /*!< CAN1 clock enable mask */
#define RCC_AHB_LIN1EN_M      (0x1UL << 8)     /*!< LIN1 clock enable mask */
#define RCC_AHB_BGCRC1EN_M    (0x1UL << 2)     /*!< BGCRC1 clock enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKEN1MASKS RCC_PCLKEN1 Masks
  * @{
  * @brief  Macro definitions for APB1 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the APB1 bus.
  */
#define RCC_APB_EQEP2EN_M    (0x1UL << 25)    /*!< EQEP2 clock enable mask */
#define RCC_APB_EQEP1EN_M    (0x1UL << 24)    /*!< EQEP1 clock enable mask */
#define RCC_APB_ECAP3EN_M    (0x1UL << 18)    /*!< ECAP3 clock enable mask */
#define RCC_APB_ECAP2EN_M    (0x1UL << 17)    /*!< ECAP2 clock enable mask */
#define RCC_APB_ECAP1EN_M    (0x1UL << 16)    /*!< ECAP1 clock enable mask */
#define RCC_APB_EPWM7EN_M    (0x1UL << 6)     /*!< EPWM7 clock enable mask */
#define RCC_APB_EPWM6EN_M    (0x1UL << 5)     /*!< EPWM6 clock enable mask */
#define RCC_APB_EPWM5EN_M    (0x1UL << 4)     /*!< EPWM5 clock enable mask */
#define RCC_APB_EPWM4EN_M    (0x1UL << 3)     /*!< EPWM4 clock enable mask */
#define RCC_APB_EPWM3EN_M    (0x1UL << 2)     /*!< EPWM3 clock enable mask */
#define RCC_APB_EPWM2EN_M    (0x1UL << 1)     /*!< EPWM2 clock enable mask */
#define RCC_APB_EPWM1EN_M    (0x1UL << 0)     /*!< EPWM1 clock enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKEN2MASKS RCC_PCLKEN2 Masks
  * @{
  * @brief  Macro definitions for APB2 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the APB2 bus.
  */
#define RCC_APB_CMPSS4EN_M    (0x1UL << 19)    /*!< CMPSS4 clock enable mask */
#define RCC_APB_CMPSS3EN_M    (0x1UL << 18)    /*!< CMPSS3 clock enable mask */
#define RCC_APB_CMPSS2EN_M    (0x1UL << 17)    /*!< CMPSS2 clock enable mask */
#define RCC_APB_CMPSS1EN_M    (0x1UL << 16)    /*!< CMPSS1 clock enable mask */
#define RCC_APB_XBAREN_M      (0x1UL << 15)    /*!< XBAR clock enable mask */
#define RCC_APB_ADCCEN_M      (0x1UL << 10)    /*!< ADC C clock enable mask */
#define RCC_APB_ADCAEN_M      (0x1UL << 8)     /*!< ADC A clock enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKEN3MASKS RCC_PCLKEN3 Masks
  * @{
  * @brief  Macro definitions for APB3 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the APB3 bus.
  */
#define RCC_APB_ANALOGSSEN_M    (0x1UL << 16)    /*!< ANALOGSSEN clock enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKEN5MASKS RCC_PCLKEN5 Masks
  * @{
  * @brief  Macro definitions for APB5 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the APB5 bus.
  */
#define RCC_APB_DCC1EN_M     (0x1UL << 31)    /*!< DCC1 enable mask */
#define RCC_APB_WWDGEN_M     (0x1UL << 28)    /*!< WWDG enable mask */
#define RCC_APB_EPGEN_M      (0x1UL << 24)    /*!< EPG enable mask */
#define RCC_APB_I2C1EN_M     (0x1UL << 16)    /*!< I2C1 enable mask */
#define RCC_APB_SPI2EN_M     (0x1UL << 9)     /*!< SPI2 enable mask */
#define RCC_APB_SPI1EN_M     (0x1UL << 8)     /*!< SPI1 enable mask */
#define RCC_APB_UART1EN_M    (0x1UL << 0)     /*!< UART1 enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKEN6MASKS RCC_PCLKEN6 Masks
  * @{
  * @brief  Macro definitions for APB6 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the APB6 bus.
  */
#define RCC_APB_STIM3EN_M    (0x1UL << 18)    /*!< STIM3 enable mask */
#define RCC_APB_STIM2EN_M    (0x1UL << 17)    /*!< STIM2 enable mask */
#define RCC_APB_STIM1EN_M    (0x1UL << 16)    /*!< STIM1 enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKEN8MASKS RCC_PCLKEN8 Masks
  * @{
  * @brief  Macro definitions for APB8 peripheral enable masks.
  * @note   These masks are used to enable various peripherals on the APB8 bus.
  */
#define RCC_APB_AWKEN_M      (0x1UL << 6)    /*!< AWK enable mask */
#define RCC_APB_LPTIMEN_M    (0x1UL << 4)    /*!< LPTIM enable mask */
#define RCC_APB_IWDG1EN_M    (0x1UL << 1)    /*!< CPUx IWDG1 enable mask */
#define RCC_APB_PWREN_M      (0x1UL << 0)    /*!< PWR enable mask */

/**
  * @}
  */

/** @defgroup RCC_HCLKLPEN1MASKS RCC_HCLKLPEN1 Masks
  * @{
  * @brief  Macro definitions for AHB1 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the AHB1 bus in sleep mode.
  */
#define RCC_AHB_GPIOHLPEN_M      (0x1UL << 23)    /*!< GPIOH Low Power enable mask */
#define RCC_AHB_GPIOCLPEN_M      (0x1UL << 18)    /*!< GPIOC Low Power enable mask */
#define RCC_AHB_GPIOBLPEN_M      (0x1UL << 17)    /*!< GPIOB Low Power enable mask */
#define RCC_AHB_GPIOALPEN_M      (0x1UL << 16)    /*!< GPIOA Low Power enable mask */
#define RCC_AHB_MMATHLPEN_M      (0x1UL << 15)    /*!< MMATH Low Power enable mask */
#define RCC_AHB_EDMA1LPEN_M      (0x1UL << 8)     /*!< EDMA1 Low Power enable mask */
#define RCC_AHB_DMAMUX1LPEN_M    (0x1UL << 4)     /*!< DMAMUX1 Low Power enable mask */
#define RCC_AHB_AONLPEN_M        (0x1UL << 0)     /*!< AON Low Power enable mask */

/**
  * @}
  */

/** @defgroup RCC_HCLKLPEN2MASKS RCC_HCLKLPEN2 Masks
  * @{
  * @brief  Macro definitions for AHB2 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the AHB2 bus in sleep mode.
  */
#define RCC_AHB_CAN1LPEN_M      (0x1UL << 12)    /*!< CAN1 Low Power enable mask */
#define RCC_AHB_LIN1LPEN_M      (0x1UL << 8)     /*!< LIN1 Low Power enable mask */
#define RCC_AHB_BGCRC1LPEN_M    (0x1UL << 2)     /*!< BGCRC1 Low Power enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKLPEN1MASKS RCC_PCLKLPEN1 Masks
  * @{
  * @brief  Macro definitions for APB1 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the APB1 bus in sleep mode.
  */
#define RCC_APB_EQEP2LPEN_M    (0x1UL << 25)    /*!< EQEP2 Low Power enable mask */
#define RCC_APB_EQEP1LPEN_M    (0x1UL << 24)    /*!< EQEP1 Low Power enable mask */
#define RCC_APB_ECAP3LPEN_M    (0x1UL << 18)    /*!< ECAP3 Low Power enable mask */
#define RCC_APB_ECAP2LPEN_M    (0x1UL << 17)    /*!< ECAP2 Low Power enable mask */
#define RCC_APB_ECAP1LPEN_M    (0x1UL << 16)    /*!< ECAP1 Low Power enable mask */
#define RCC_APB_EPWM7LPEN_M    (0x1UL << 6)     /*!< EPWM7 Low Power enable mask */
#define RCC_APB_EPWM6LPEN_M    (0x1UL << 5)     /*!< EPWM6 Low Power enable mask */
#define RCC_APB_EPWM5LPEN_M    (0x1UL << 4)     /*!< EPWM5 Low Power enable mask */
#define RCC_APB_EPWM4LPEN_M    (0x1UL << 3)     /*!< EPWM4 Low Power enable mask */
#define RCC_APB_EPWM3LPEN_M    (0x1UL << 2)     /*!< EPWM3 Low Power enable mask */
#define RCC_APB_EPWM2LPEN_M    (0x1UL << 1)     /*!< EPWM2 Low Power enable mask */
#define RCC_APB_EPWM1LPEN_M    (0x1UL << 0)     /*!< EPWM1 Low Power enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKLPEN2MASKS RCC_PCLKLPEN2 Masks
  * @{
  * @brief  Macro definitions for APB2 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the APB2 bus in sleep mode.
  */
#define RCC_APB_CMPSS4LPEN_M    (0x1UL << 19)    /*!< CMPSS4 Low Power enable mask */
#define RCC_APB_CMPSS3LPEN_M    (0x1UL << 18)    /*!< CMPSS3 Low Power enable mask */
#define RCC_APB_CMPSS2LPEN_M    (0x1UL << 17)    /*!< CMPSS2 Low Power enable mask */
#define RCC_APB_CMPSS1LPEN_M    (0x1UL << 16)    /*!< CMPSS1 Low Power enable mask */
#define RCC_APB_XBARLPEN_M      (0x1UL << 15)    /*!< XBAR Low Power enable mask */
#define RCC_APB_ADCCLPEN_M      (0x1UL << 10)    /*!< ADC C Low Power enable mask */
#define RCC_APB_ADCALPEN_M      (0x1UL << 8)     /*!< ADC A Low Power enable mask */

/**
  * @}
  */

/** @defgroup RCC_PCLKLPEN3MASKS RCC_PCLKLPEN3 Masks
  * @{
  * @brief  Macro definitions for APB3 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the APB3 bus in sleep mode.
  */
#define RCC_APB_ANALOGSSLPEN_M    (0x1UL << 16)    /*!< ANALOGSS low power enable bit */

/**
  * @}
  */

/** @defgroup RCC_PCLKLPEN5MASKS RCC_PCLKLPEN5 Masks
  * @{
  * @brief  Macro definitions for APB5 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the APB5 bus in sleep mode.
  */
#define RCC_APB_DCC1LPEN_M     (0x1UL << 31)    /*!< DCC1 low power enable bit */
#define RCC_APB_WWDGLPEN_M     (0x1UL << 28)    /*!< WWDG low power enable bit */
#define RCC_APB_EPGLPEN_M      (0x1UL << 24)    /*!< EPG low power enable bit */
#define RCC_APB_I2C1LPEN_M     (0x1UL << 16)    /*!< I2C1 low power enable bit */
#define RCC_APB_SPI2LPEN_M     (0x1UL << 9)     /*!< SPI2 low power enable bit */
#define RCC_APB_SPI1LPEN_M     (0x1UL << 8)     /*!< SPI1 low power enable bit */
#define RCC_APB_UART1LPEN_M    (0x1UL << 0)     /*!< UART1 low power enable bit */

/**
  * @}
  */

/** @defgroup RCC_PCLKLPEN6MASKS RCC_PCLKLPEN6 Masks
  * @{
  * @brief  Macro definitions for APB6 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the APB6 bus in sleep mode.
  */
#define RCC_APB_STIM3LPEN_M    (0x1UL << 18)    /*!< STIM3 low power enable bit */
#define RCC_APB_STIM2LPEN_M    (0x1UL << 17)    /*!< STIM2 low power enable bit */
#define RCC_APB_STIM1LPEN_M    (0x1UL << 16)    /*!< STIM1 low power enable bit */

/**
  * @}
  */

/** @defgroup RCC_PCLKLPEN8MASKS RCC_PCLKLPEN8 Masks
  * @{
  * @brief  Macro definitions for APB8 peripheral in sleep mode enable masks.
  * @note   These masks are used to enable various peripherals on the APB8 bus in sleep mode.
  */
#define RCC_APB_AWKLPEN_M      (0x1UL << 6)    /*!< AWK low power enable bit */
#define RCC_APB_LPTIMLPEN_M    (0x1UL << 4)    /*!< LPTIM low power enable bit */
#define RCC_APB_IWDG1LPEN_M    (0x1UL << 1)    /*!< IWDG1 low power enable bit */
#define RCC_APB_PWRLPEN_M      (0x1UL << 0)    /*!< PWR low power enable bit */

/**
  * @}
  */

/** @defgroup RCC_DIVISORMASKS RCC Divisor Masks
  * @{
  * @brief Macro definitions for configuring divisors for various peripherals.
  * @note  These masks are used to set the divisor values for different peripherals.
  */
#define RCC_HXTLAWKDIV_M    (0xFFUL << 16)    /*!< High Speed External Low Amplitude Watchdog divisor mask */
#define RCC_EPWMCLKDIV_M    (0x1UL << 12)     /*!< High Speed External Low Amplitude Watchdog divisor mask */
#define RCC_TRACEDIV_M      (0x7UL << 4)      /*!< Trace interface divisor mask */
#define RCC_FLASHDIV_M      (0x7UL << 0)      /*!< Flash memory interface divisor mask */

/**
  * @}
  */

/** @defgroup RCC_PLLCR4MASKS RCC_PLLCR4 Masks
  * @{
  * @brief Macro definitions for various control settings in RCC.
  * @note  These masks are used to configure different control settings in the RCC module.
  */
#define RCC_PLLCTRL_KEY    (0x5A69UL << 16)    /*!< PLL control key mask */
#define RCC_FLT_CAP_M      (0x7UL << 8)        /*!< filter cap mask */
#define RCC_ICP_SL_M       (0x3UL << 4)        /*!< work current mask */
#define RCC_FLT_RES_M      (0x3UL << 2)        /*!< filter res mask */
#define RCC_VCORNG_M       (0x3UL << 0)        /*!< Voltage control range mask */

/**
  * @}
  */

/** @defgroup RCC_MIRC1CRMASKS RCC_MIRC1CR Masks
  * @{
  * @brief Macro definitions for controlling MIRC1.
  * @note  These masks are used to configure and control the MIRC1 oscillator.
  */
#define RCC_MIRC1CTRL_KEY    (0x5A69UL << 16)    /*!< MIRC1 control key mask */
#define RCC_MIRC1TRIM_M      (0x1FFUL << 0)      /*!< MIRC1 trim mask */

/**
  * @}
  */

/** @defgroup RCC_MIRC2CRMASKS RCC_MIRC2CR Masks
  * @{
  * @brief Macro definitions for controlling MIRC2.
  * @note  These masks are used to configure and control the MIRC2 oscillator.
  */
#define RCC_MIRC2CTRL_KEY    (0x5A69UL << 16)    /*!< MIRC2 control key mask */
#define RCC_MIRC2TRIM_M      (0x1FFUL << 0)      /*!< MIRC2 trim mask */

/**
  * @}
  */

/** @defgroup RCC_HXTLCRMASKS RCC_HXTLCR Masks
  * @{
  * @brief Macro definitions for controlling the High-Frequency Crystal Oscillator (HXTL).
  * @note  These masks are used to configure and control various settings of the HXTL.
  */
#define RCC_HTXLCTRL_KEY     (0x5A69UL << 16)    /*!< HXTL control key mask */
#define RCC_HXTLFLT_EN_M     (0x1UL << 15)       /*!< HXTL filter enable mask */
#define RCC_HXTL_RF_SEL_M    (0x1UL << 13)       /*!< HXTL reference frequency selection mask */
#define RCC_HXTL_RF_EN_M     (0x1UL << 12)       /*!< HXTL reference frequency enable mask */
#define RCC_HXTLSTUP_M       (0x3UL << 8)        /*!< HXTL startup time mask */
#define RCC_HXTLMF_M         (0xFFUL << 0)       /*!< HXTL multiplication factor mask */

/**
  * @}
  */

/** @defgroup RCC_MCDCRMASKS RCC_MCDCR Masks
  * @{
  * @brief Macro definitions for controlling the Main Clock Divider (MCD).
  * @note  These masks are used to configure and control various settings of the MCD.
  */
#define RCC_MCDCTRL_KEY    (0x5A69UL << 16)    /*!< MCD control key mask */
#define RCC_MCDPD_M        (0x7UL << 8)        /*!< MCD prescaler divider mask */
#define RCC_MCDIE_M        (0x1UL << 6)        /*!< MCD interrupt enable mask */
#define RCC_MCDCLR_M       (0x1UL << 5)        /*!< MCD clear flag mask */
#define RCC_MCDFLG_M       (0x1UL << 4)        /*!< MCD flag mask */
#define RCC_MCDEN_M        (0x1UL << 0)        /*!< MCD enable mask */

/**
  * @}
  */

/** @defgroup RCC_RSTCRMASKS RCC_RSTCR Masks
  * @{
  * @brief Macro definitions for controlling system reset operations.
  * @note  These macros define specific keys used for reset and related operations.
  */
#define RCC_CPURST    (0x55AA669AUL)    /*!< CPU reset key */
#define RCC_SIMXRS    (0x55AA6699UL)    /*!< System reset key */

/**
  * @}
  */

/** @defgroup RCC_RSTSRMASKS RCC_RSTSR Masks
  * @{
  * @brief Macro definitions for reset flags and their corresponding masks.
  * @note  These macros define bit masks used to clear or check various reset flags in the system.
  */
#define RCC_RMVF_M           (0x1UL << 31)    /*!< Remove reset flag mask */
#define RCC_RMVST_M          (0x1UL << 30)    /*!< Remove reset flag status mask */
#define RCC_SBYDBGRST_M      (0x1UL << 17)    /*!< Standby debug reset mask */
#define RCC_LPWRERST_M       (0x1UL << 16)    /*!< Low-power reset mask */
#define RCC_NMIWDTRST_M      (0x1UL << 14)    /*!< Non-maskable interrupt watchdog reset mask */
#define RCC_SFTRST_M         (0x1UL << 13)    /*!< Software reset mask */
#define RCC_CPURST_M         (0x1UL << 12)    /*!< CPU reset mask */
#define RCC_LOLRST_M         (0x1UL << 11)    /*!< Loss of lock reset mask */
#define RCC_LOCKUPRST_M      (0x1UL << 10)    /*!< Lockup reset mask */
#define RCC_CLKFAILRST_M     (0x1UL << 9)     /*!< Clock fail mask */
#define RCC_IWDG1RST_M       (0x1UL << 7)     /*!< Independent watchdog 1 reset mask */
#define RCC_WWDGRST_M        (0x1UL << 6)     /*!< Window watchdog reset mask */
#define RCC_SIMXRST_M        (0x1UL << 5)     /*!< System reset mask */
#define RCC_XRST_M           (0x1UL << 4)     /*!< External reset mask */
#define RCC_VDDPORRST_M      (0x1UL << 2)     /*!< VDD power-on reset mask */
#define RCC_VDDIOBORRST_M    (0x1UL << 1)     /*!< VDDIO power-on reset mask */
#define RCC_VDDIOPORRST_M    (0x1UL << 0)     /*!< VDDIOPOR reset mask */

/**
  * @}
  */

/** @defgroup RCC_UNLOCK RCC Lock and Unlock Macros
  * @{
  * @brief Macro definitions for RCC lock and unlock operations.
  * @note These macros are used to enable or disable critical sections in the RCC configuration.
  */
#define RCC_UNLOCK    (0x55AA6699UL)    /*!< Unlock RCC register access */
#define RCC_LOCK      (0x55AA6698UL)    /*!< Lock RCC register access */

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
 * \brief  Enable PLL Loss of Lock Reset
 * \note   This function enables the PLL (Phase-Locked Loop) Loss of Lock Reset by setting the PLLLOL_RST bit in the RCC Control Register (RCC->CR).
 *         When the PLL loses its lock, this feature triggers a system reset.
 */
static inline void RCC_enablePllLolRst (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_PLLLOL_RST_M);
}

/**
 * \brief  Disable PLL Loss of Lock Reset
 * \note   This function disables the PLL (Phase-Locked Loop) Loss of Lock Reset by clearing the PLLLOL_RST bit in the RCC Control Register (RCC->CR).
 *         When the PLL loses its lock, this feature triggers a intterupt.
 */
static inline void RCC_disablePllLolRst (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_PLLLOL_RST_M);
}

/**
 * \brief  Read the PLL Lock Detect Flag Status.
 * \note   This function checks the PLL lock detect bit (PLL_LKDT) in the RCC Control Register (RCC->CR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the PLL Lock Detect Flag.
 *          - 0: The PLL lock detect flag is not set.
 *          - 1: The PLL lock detect flag is set.
 */
static inline uint32_t RCC_readPllLkdtFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_PLL_LKDT_M) ? 1UL : 0UL;
}

/**
 * \brief  Enable PLL
 * \note   This function enables the PLL (Phase-Locked Loop) by setting the PLLEN bit in the RCC Control Register (RCC->CR).
 *         Once enabled, the PLL can be used to generate higher frequency clock signals.
 */
static inline void RCC_enablePll (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_PLLEN_M);
}

/**
 * \brief  Disable PLL
 * \note   This function disables the PLL (Phase-Locked Loop) by clearing the PLLEN bit in the RCC Control Register (RCC->CR).
 *         Once disabled, the PLL will no longer generate higher frequency clock signals.
 */
static inline void RCC_disablePll (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_PLLEN_M);
}

/**
 * \brief  Enable Kernal to Use HXTL (High-Speed External Crystal Oscillator)
 * \note   This function enables the use of the high-speed external crystal oscillator (HXTL) for the kernal
 *         by setting the HXTLKEREN bit in the RCC Control Register (RCC->CR).
 */
static inline void RCC_enableKernalUseHxtl (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_HXTLKEREN_M);
}

/**
 * \brief  Disable Kernal from Using HXTL (High-Speed External Crystal Oscillator)
 * \note   This function disables the use of the high-speed external crystal oscillator (HXTL) for the kernal
 *         by clearing the HXTLKEREN bit in the RCC Control Register (RCC->CR).
 */
static inline void RCC_disableKernalUseHxtl (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_HXTLKEREN_M);
}

/**
 * \brief  Enable HXTL Failure Reset
 * \note   This function enables the reset triggered by a failure of the high-speed external crystal oscillator (HXTL)
 *         by setting the HXTLFAIL_RST bit in the RCC Control Register (RCC->CR).
 *         When the HXTL fail, this feature triggers a system reset.
 */
static inline void RCC_enableHxtlFailureRst (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_HXTLFAIL_RST_M);
}

/**
 * \brief  Disable HXTL Failure Reset
 * \note   This function disables the reset triggered by a failure of the high-speed external crystal oscillator (HXTL)
 *         by clearing the HXTLFAIL_RST bit in the RCC Control Register (RCC->CR).
 *         When the HXTL fail, this feature triggers a intterupt.
 *  */
static inline void RCC_disableHxtlFailureRst (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_HXTLFAIL_RST_M);
}

/**
 * \brief  Enable HXTL Failure Detection
 * \note   This function enables the detection of failures in the high-speed external crystal oscillator (HXTL)
 *         by setting the HXTLDETEN bit in the RCC Control Register (RCC->CR).
 */
static inline void RCC_enableHxtlFailureDetection (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_HXTLDETEN_M);
}

/**
 * \brief  Disable HXTL Failure Detection
 * \note   This function disables the detection of failures in the high-speed external crystal oscillator (HXTL)
 *         by clearing the HXTLDETEN bit in the RCC Control Register (RCC->CR).
 */
static inline void RCC_disableHxtlFailureDetection (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_HXTLDETEN_M);
}

/**
 * \brief  Enable HXTL Bypass Mode
 * \note   This function enables the bypass mode for the high-speed external crystal oscillator (HXTL)
 *         by setting the HXTLBYP bit in the RCC Control Register (RCC->CR).
 *         When enabled, the HXTL input is bypassed, and an external clock signal can be used instead.
 */
static inline void RCC_enableHxtlBypass (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_HXTLBYP_M);
}

/**
 * \brief  Disable HXTL Bypass Mode
 * \note   This function disables the bypass mode for the high-speed external crystal oscillator (HXTL)
 *         by clearing the HXTLBYP bit in the RCC Control Register (RCC->CR).
 *         When disabled, the HXTL operates normally as a crystal oscillator.
 */
static inline void RCC_disableHxtlBypass (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_HXTLBYP_M);
}

/**
 * \brief  Read the High-Speed External Crystal Oscillator Ready Flag Status.
 * \note   This function checks the HXTL_RDY bit in the RCC Control Register (RCC->CR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the High-Speed External Crystal Oscillator Ready Flag.
 *          - 0: The high-speed external crystal oscillator ready flag is not set.
 *          - 1: The high-speed external crystal oscillator ready flag is set.
 */
static inline uint32_t RCC_readHxtlRdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_HXTLRDY_M) ? 1UL : 0UL;
}

/**
 * \brief  Enable HXTL Oscillator
 * \note   This function enables the high-speed external crystal oscillator (HXTL)
 *         by setting the HXTLEN bit in the RCC Control Register (RCC->CR).
 *         When enabled, the HXTL oscillator starts operating.
 */
static inline void RCC_enableHxtl (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_HXTLEN_M);
}

/**
 * \brief  Disable HXTL Oscillator
 * \note   This function disables the high-speed external crystal oscillator (HXTL)
 *         by clearing the HXTLEN bit in the RCC Control Register (RCC->CR).
 *         When disabled, the HXTL oscillator stops operating.
 */
static inline void RCC_disableHxtl (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_HXTLEN_M);
}

/**
 * \brief  Read the Low-Speed Internal RC Oscillator Ready Flag Status.
 * \note   This function checks the LIRC_RDY bit in the RCC Control Register (RCC->CR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Low-Speed Internal RC Oscillator Ready Flag.
 *          - 0: The low-speed internal RC oscillator ready flag is not set.
 *          - 1: The low-speed internal RC oscillator ready flag is set.
 */
static inline uint32_t RCC_readLircRdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_LIRCRDY_M) ? 1UL : 0UL;
}

/**
 * \brief  Enable Low-Speed Internal RC Oscillator (LIRC)
 * \note   This function enables the low-speed internal RC oscillator (LIRC)
 *         by setting the LIRCEN bit in the RCC Control Register (RCC->CR).
 *         When enabled, the LIRC oscillator starts operating.
 */
static inline void RCC_enableLirc (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_LIRCEN_M);
}

/**
 * \brief  Disable Low-Speed Internal RC Oscillator (LIRC)
 * \note   This function disables the low-speed internal RC oscillator (LIRC)
 *         by clearing the LIRCEN bit in the RCC Control Register (RCC->CR).
 *         When disabled, the LIRC oscillator stops operating.
 */
static inline void RCC_disableLirc (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_LIRCEN_M);
}

/**
 * \brief  Enable Kernal Usage of Medium-Speed Internal RC Oscillator 1 (MIRC1)
 * \note   This function enables the kernal to use the Medium-Speed internal RC oscillator 1 (MIRC1)
 *         by setting the MIRC1KEREN bit in the RCC Control Register (RCC->CR).
 *         When enabled, the kernal can utilize MIRC1 as a clock source.
 */
static inline void RCC_enableKernalUseMirc1 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_MIRC1KEREN_M);
}

/**
 * \brief  Disable Kernal Usage of Medium-Speed Internal RC Oscillator 1 (MIRC1)
 * \note   This function disables the kernal from using the Medium-Speed internal RC oscillator 1 (MIRC1)
 *         by clearing the MIRC1KEREN bit in the RCC Control Register (RCC->CR).
 *         When disabled, the kernal will not use MIRC1 as a clock source.
 */
static inline void RCC_disableKernalUseMirc1 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_MIRC1KEREN_M);
}

/**
 * \brief  Read the Medium-Speed Internal RC Oscillator 1 Ready Flag Status.
 * \note   This function checks the MIRC1_RDY bit in the RCC Control Register (RCC->CR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Medium-Speed Internal RC Oscillator 1 Ready Flag.
 *          - 0: The Medium-Speed internal RC oscillator 1 ready flag is not set.
 *          - 1: The Medium-Speed internal RC oscillator 1 ready flag is set.
 */
static inline uint32_t RCC_readMirc1RdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_MIRC1RDY_M) ? 1UL : 0UL;
}

/**
 * \brief  Enable Medium-Speed Internal RC Oscillator 1 (MIRC1)
 * \note   This function enables the Medium-Speed internal RC oscillator 1 (MIRC1)
 *         by setting the MIRC1EN bit in the RCC Control Register (RCC->CR).
 *         When enabled, the MIRC1 oscillator starts operating and can be used as a clock source.
 */
static inline void RCC_enableMirc1 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_MIRC1EN_M);
}

/**
 * \brief  Disable Medium-Speed Internal RC Oscillator 1 (MIRC1)
 * \note   This function disables the medium-speed internal RC oscillator 1 (MIRC1)
 *         by clearing the MIRC1EN bit in the RCC Control Register (RCC->CR).
 *         When disabled, the MIRC1 oscillator stops operating and cannot be used as a clock source.
 */
static inline void RCC_disableMirc1 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_MIRC1EN_M);
}

/**
 * \brief  Enable Kernal Usage of Medium-Speed Internal RC Oscillator 2 (MIRC2)
 * \note   This function enables the Kernal to use the medium-speed internal RC oscillator 2 (MIRC2)
 *         by setting the MIRC2KEREN bit in the RCC Control Register (RCC->CR).
 *         When enabled, the Kernal can utilize MIRC2 as a clock source.
 */
static inline void RCC_enableKernalUseMirc2 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_MIRC2KEREN_M);
}

/**
 * \brief  Disable Kernal Usage of Medium-Speed Internal RC Oscillator 2 (MIRC2)
 * \note   This function disables the kernal from using the medium-speed internal RC oscillator 2 (MIRC2)
 *         by clearing the MIRC2KEREN bit in the RCC Control Register (RCC->CR).
 *         When disabled, the kernal will not use MIRC2 as a clock source.
 */
static inline void RCC_disableKernalUseMirc2 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_MIRC2KEREN_M);
}

/**
 * \brief  Read the Medium-Speed Internal RC Oscillator 2 Ready Flag Status.
 * \note   This function checks the MIRC2_RDY bit in the RCC Control Register (RCC->CR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Medium-Speed Internal RC Oscillator 2 Ready Flag.
 *          - 0: The Medium-Speed internal RC oscillator 2 ready flag is not set.
 *          - 1: The Medium-Speed internal RC oscillator 2 ready flag is set.
 */
static inline uint32_t RCC_readMirc2RdyFlag(void)
{
    return READ_BIT(RCC->CR.WORDVAL, RCC_MIRC2RDY_M) ? 1UL : 0UL;
}

/**
 * \brief  Enable Medium-Speed Internal RC Oscillator 2 (MIRC2)
 * \note   This function enables the medium-speed internal RC oscillator 2 (MIRC2)
 *         by setting the MIRC2EN bit in the RCC Control Register (RCC->CR).
 *         When enabled, the MIRC2 oscillator starts operating and can be used as a clock source.
 */
static inline void RCC_enableMirc2 (void)
{
    SET_BIT(RCC->CR.WORDVAL, RCC_MIRC2EN_M);
}

/**
 * \brief  Disable Medium-Speed Internal RC Oscillator 2 (MIRC2)
 * \note   This function disables the medium-speed internal RC oscillator 2 (MIRC2)
 *         by clearing the MIRC2EN bit in the RCC Control Register (RCC->CR).
 *         When disabled, the MIRC2 oscillator stops operating and cannot be used as a clock source.
 */
static inline void RCC_disableMirc2 (void)
{
    CLEAR_BIT(RCC->CR.WORDVAL, RCC_MIRC2EN_M);
}

/**
 * \brief  Enable Main Clock Output 2 (MCO2)
 * \note   This function enables the main clock output 2 (MCO2)
 *         by setting the MCO2EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
 *         When enabled, the MCO2 signal can be used as an external clock source.
 */
static inline void RCC_enableMco2 (void)
{
    SET_BIT(RCC->MCOCR.WORDVAL, RCC_MCO2EN_M);
}

/**
 * \brief  Disable Main Clock Output 2 (MCO2)
 * \note   This function disables the main clock output 2 (MCO2)
 *         by clearing the MCO2EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
 *         When disabled, the MCO2 signal is not active and cannot be used as an external clock source.
 */
static inline void RCC_disableMco2 (void)
{
    CLEAR_BIT(RCC->MCOCR.WORDVAL, RCC_MCO2EN_M);
}

/**
 * \brief  Select the Source for Main Clock Output 2 (MCO2)
 * \param  mco2OutSel  RCC mco2 output source selection
 *                      This parameter can be any value of @ref RCC_MCOSOURCESEL
 * \note   This function selects the clock source for MCO2 by modifying the MCO2SEL bits
 *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
 */
static inline void RCC_selectMco2OutputSource (RCC_McoSourceSel mco2OutSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCO2SEL_M, (mco2OutSel << RCC_MCO2SEL_S));
}

/**
 * \brief  Select the Division Factor for Main Clock Output 2 (MCO2)
 * \param  mco2DivSel  Specifies the division factor for MCO2.
 *                         This parameter can be any value of @ref RCC_MCODIVSEL
 * \note   This function sets the division factor for MCO2 by modifying the MCO2DIV bits
 *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
 */
static inline void RCC_selectMco2OutputDiv (RCC_McoDivSel mco2DivSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCO2DIV_M, (mco2DivSel << RCC_MCO2DIV_S));
}

/**
 * \brief  Enable Main Clock Output 1 (MCO1)
 * \note   This function enables the main clock output 1 (MCO1)
 *         by setting the MCO1EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
 *         When enabled, the MCO1 signal can be used as an external clock source.
 */
static inline void RCC_enableMco1 (void)
{
    SET_BIT(RCC->MCOCR.WORDVAL, RCC_MCO1EN_M);
}

/**
 * \brief  Disable Main Clock Output 1 (MCO1)
 * \note   This function disables the main clock output 1 (MCO1)
 *         by clearing the MCO1EN bit in the RCC Main Clock Output Control Register (RCC->MCOCR).
 *         When disabled, the MCO1 signal is not active and cannot be used as an external clock source.
 */
static inline void RCC_disableMco1 (void)
{
    CLEAR_BIT(RCC->MCOCR.WORDVAL, RCC_MCO1EN_M);
}

/**
 * \brief  Select the Source for Main Clock Output 1 (MCO1)
 * \note   This function selects the clock source for MCO1 by modifying the MCO1SEL bits
 *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
 * \param  mco1OutSel  RCC mco1 output source selection
 *                      This parameter can be any value of @ref RCC_MCOSOURCESEL
 */
static inline void RCC_selectMco1OutputSource (RCC_McoSourceSel mco1OutSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCO1SEL_M, (mco1OutSel << RCC_MCO1SEL_S));
}

/**
 * \brief  Select the Division Factor for Main Clock Output 1 (MCO1)
 * \note   This function sets the division factor for MCO1 by modifying the MCO1DIV bits
 *         in the RCC Main Clock Output Control Register (RCC->MCOCR).
 * \param  mco1DivSel  Specifies the division factor for MCO1.
 *                      This parameter can be any value of @ref RCC_MCODIVSEL
 */
static inline void RCC_selectMco1OutputDiv (RCC_McoDivSel mco1DivSel)
{
    MODIFY_REG(RCC->MCOCR.WORDVAL, RCC_MCO1DIV_M, (mco1DivSel << RCC_MCO1DIV_S));
}

/**
 * \brief  Select the Division Factor for APB5 Clock Source
 * \note   This function sets the division factor for the APB5 clock source by modifying
 *         the APB5DIV bits in the RCC Configuration Register (RCC->CFGR).
 * \param  apb5ClkSrcDivSel  Specifies the division factor for the APB5 clock source.
 *                            This parameter can be any value of @ref RCC_APB5SRC
 */
static inline void RCC_selectApb5ClkSourceDiv (RCC_Apb5Src apb5ClkSrcDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_APB5DIV_M, (apb5ClkSrcDivSel << RCC_APB5DIV_S));
}

/**
 * \brief  Get the Division Factor for APB5 Clock (APB5CLK)
 * \note   This function retrieves the division factor for the APB5 clock by reading
 *         the APB5DIV bits in the RCC Configuration Register (RCC->CFGR).
 * \return The division factor for the APB5 clock.
 *         This value corresponds to one of the definitions in @ref RCC_APB5SRC
 */
static inline RCC_Apb5Src RCC_getApb5ClkDiv (void)
{
    return (RCC_Apb5Src)(READ_BIT(RCC->CFGR.WORDVAL, RCC_APB5DIV_M) >> RCC_APB5DIV_S);
}

/**
 * \brief  Select the Division Factor for APB2_4 Clock Source
 * \note   This function sets the division factor for the APB2_4 clock source by modifying
 *         the APB2DIV bits in the RCC Configuration Register (RCC->CFGR).
 * \param  apb2ClkSrcDivSel: Specifies the division factor for the APB2_4 clock source.
 *                         This parameter can be any value of @ref RCC_APB2AND4SRC
 */
static inline void RCC_selectApb2ClkSourceDiv (RCC_Apb2And4Src apb2ClkSrcDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_APB2DIV_M, (apb2ClkSrcDivSel << RCC_APB2DIV_S));
}

/**
 * \brief  Get the Division Factor for APB2 Clock (APB2CLK)
 * \note   This function retrieves the division factor for the APB2 clock by reading
 *         the APB2DIV bits in the RCC Configuration Register (RCC->CFGR).
 * \return The division factor for the APB2 clock.
 *         This value corresponds to one of the definitions in @ref RCC_APB2AND4SRC
 */
static inline RCC_Apb2And4Src RCC_getApb2ClkDiv (void)
{
    return (RCC_Apb2And4Src)(READ_BIT(RCC->CFGR.WORDVAL, RCC_APB2DIV_M) >> RCC_APB2DIV_S);
}

/**
 * \brief  Select the Division Factor for APB1_3 Clock Source
 * \note   This function sets the division factor for the APB1_3 clock source by modifying
 *         the APB1DIV bits in the RCC Configuration Register (RCC->CFGR).
 * \param  apb1ClkSrcDivSel: Specifies the division factor for the APB1_3 clock source.
 *                         This parameter can be any value of @ref RCC_APB1AND3SRC
 */
static inline void RCC_selectApb1ClkSourceDiv (RCC_Apb1And3Src apb1ClkSrcDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_APB1DIV_M, (apb1ClkSrcDivSel << RCC_APB1DIV_S));
}

/**
 * \brief  Get the Division Factor for APB1 Clock (APB1CLK)
 * \note   This function retrieves the division factor for the APB1 clock by reading
 *         the APB1DIV bits in the RCC Configuration Register (RCC->CFGR).
 * \return The division factor for the APB1 clock.
 *         This value corresponds to one of the definitions in @ref RCC_APB1AND3SRC
 */
static inline RCC_Apb1And3Src RCC_getApb1ClkDiv (void)
{
    return (RCC_Apb1And3Src)(READ_BIT(RCC->CFGR.WORDVAL, RCC_APB1DIV_M) >> RCC_APB1DIV_S);
}

/**
 * \brief  Select the Division Factor for System Clock (SYSCLK)
 * \note   This function sets the division factor for the system clock by modifying
 *         the SYSDIV bits in the RCC Configuration Register (RCC->CFGR).
 * \param  sysClkDivSel: Specifies the division factor for the system clock.
 *                         This parameter can be any value of @ref RCC_SYSCLKDIVSEL
 */
static inline void RCC_selectSysClkDiv (RCC_SysclkDivSel sysClkDivSel)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_SYSDIV_M, (sysClkDivSel << RCC_SYSDIV_S));
}

/**
 * \brief  Get the Division Factor for System Clock (SYSCLK)
 * \note   This function retrieves the division factor for the system clock by reading
 *         the SYSDIV bits in the RCC Configuration Register (RCC->CFGR).
 * \return The division factor for the system clock.
 *         This value corresponds to one of the definitions in @ref RCC_SYSCLKDIVSEL
 */
static inline RCC_SysclkDivSel RCC_getSysClkDiv (void)
{
    return (RCC_SysclkDivSel)(READ_BIT(RCC->CFGR.WORDVAL, RCC_SYSDIV_M) >> RCC_SYSDIV_S);
}

/**
 * \brief  Select the System Clock Source
 * \note   This function selects the system clock source by modifying
 *         the SWSEL bits in the RCC Configuration Register (RCC->CFGR).
 * \param  sysClkSrc: Specifies the system clock source.
 *                      This parameter can be any value of \e RCC_SysclkSrc
 */
static inline void RCC_selectSystemClock (RCC_SysclkSrc sysClkSrc)
{
    MODIFY_REG(RCC->CFGR.WORDVAL, RCC_SWSEL_M, ((uint32_t)sysClkSrc << RCC_SWSEL_S));
}

/**
 * \brief  Read the System Clock Switch Status.
 * \note   This function reads the SWSTA bit in the RCC Configuration Register (RCC->CFGR)
 *         and returns its value after shifting it right by 4 bits.
 * \return Returns the system clock switch status.
 *          - 0: RCC_SYSCLKSTATUS_MIRC2
 *          - 1: RCC_SYSCLKSTATUS_HXTL
 *          - 2: RCC_SYSCLKSTATUS_PLL
 *          - 3: RCC_SYSCLKSTATUS_MIRC1
 */
static inline uint32_t RCC_readSysClkSwitchStatus (void)
{
    return (READ_BIT(RCC->CFGR.WORDVAL, RCC_SWSTA_M) >> RCC_SWSTA_S);
}

/**
 * \brief  Enable OSCCLK fail detection
 * \note   This function enables the OSCCLK fail detection by setting
 *         the OSCCLKDETEN bit in the RCC PLL controller Register (RCC->PLLCR).
 */
static inline void RCC_enableOscclkFailDetect (void)
{
    SET_BIT(RCC->PLLCR.WORDVAL, RCC_OSCCLKDETEN_M);
}

/**
 * \brief  Disable OSCCLK fail detection
 * \note   This function disables the OSCCLK fail detection by clearing
 *         the OSCCLKDETEN bit in the RCC PLL controller Register (RCC->PLLCR).
 */
static inline void RCC_disableOscclkFailDetect (void)
{
    CLEAR_BIT(RCC->PLLCR.WORDVAL, RCC_OSCCLKDETEN_M);
}

/**
 * \brief  Read OSCCLK fail detection Status.
 * \note   This function reads the OFDRDYS bit in the RCC PLL Configuration Register (RCC->PLLCR)
 * \return Returns the software clock switch status.
 *          - 0: OSCCLK fail
 *          - 1: OSCCLK no fail
 */
static inline uint32_t RCC_readOscclkFailDetectSta (void)
{
    return READ_BIT(RCC->PLLCR.WORDVAL, RCC_OFDRDYS_M)?  1UL : 0UL;
}

/**
 * \brief  Read the Software Clock Switch Status.
 * \note   This function reads the SWSTA bit in the RCC Configuration Register (RCC->CFGR)
 *         and returns its value after shifting it right by 4 bits.
 * \return Returns the software clock switch status.
 *          - 0: RCC_PLLSOURCE_MIRC2
 *          - 1: RCC_PLLSOURCE_HXTL
 *          - 2: RCC_PLLSOURCE_MIRC1
 */
static inline uint32_t RCC_readPllClockSource (void)
{
    return READ_BIT(RCC->PLLCR.WORDVAL, RCC_PLLSRC_M);
}

/**
 * \brief  Select the PLL Clock Source
 * \note   This function selects the clock source for the PLL by modifying
 *         the PLLSRC bits in the PLL Configuration Register (RCC->PLLCR).
 * \param  pllClkSrc  Specifies the clock source for the PLL.
 *                     This parameter can be any value of @ref RCC_PLLSRC
 */
static inline void RCC_selectPllClockSource (RCC_PllSrc pllClkSrc)
{
    MODIFY_REG(RCC->PLLCR.WORDVAL, RCC_PLLSRC_M, pllClkSrc);
}

/**
 * \brief  Enable OSCCLK stop Interrupt
 * \note   This function enables the OSCCLK stop (OSCCLKSTOP) interrupt by setting
 *         the OSCCLKSTOPIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated if the OSCCLK stop.
 */
static inline void RCC_enableOscclkStopInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_PLL_OSCCLKSTOPIE_M);
}

/**
 * \brief  Disable OSCCLK stop Interrupt
 * \note   This function disables the OSCCLK stop (OSCCLKSTOP) interrupt by clearing
 *         the OSCCLKSTOPIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated if the OSCCLK stop.
 */
static inline void RCC_disableOscclkStopInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_PLL_OSCCLKSTOPIE_M);
}

/**
 * \brief  Select the OSCCLK stop Interrupt.
 * \note   This function selects the OSCCLK stop interrupt source in the IER register (RCC->IER).
 * \param  oscclkIntSelection  Specifies the OSCCLK stop interrupt selection.
 *                                 This parameter can be any value of @ref RCC_OSCCLKINTSELECTION
 */
static inline void RCC_selectOscclkStopIntFunc (RCC_OscclkIntSelection oscclkIntSelection)
{
    MODIFY_REG(RCC->IER.WORDVAL, RCC_PLL_OSCCLKSTOPSEL_M, (oscclkIntSelection << RCC_PLL_OSCCLKSTOPSEL_S));
}

/**
 * \brief  Enable PLL Loss of Lock Interrupt
 * \note   This function enables the PLL Loss of Lock (LOL) interrupt by setting
 *         the PLL_LOLIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated if the PLL loses lock.
 */
static inline void RCC_enablePllLolInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_PLL_LOLIE_M);
}

/**
 * \brief  Disable PLL Loss of Lock Interrupt
 * \note   This function disables the PLL Loss of Lock (LOL) interrupt by clearing
 *         the PLL_LOLIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated if the PLL loses lock.
 */
static inline void RCC_disablePllLolInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_PLL_LOLIE_M);
}

/**
 * \brief  Enable PLL Lock Detection Time-out Interrupt
 * \note   This function enables the PLL Lock Detection Time-out (LKDT) interrupt by setting
 *         the PLL_LKDTIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated if the PLL lock detection times out.
 */
static inline void RCC_enablePllLkdtInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_PLL_LKDTIE_M);
}

/**
 * \brief  Disable PLL Lock Detection Time-out Interrupt
 * \note   This function disables the PLL Lock Detection Time-out (LKDT) interrupt by clearing
 *         the PLL_LKDTIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated if the PLL lock detection times out.
 */
static inline void RCC_disablePllLkdtInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_PLL_LKDTIE_M);
}

/**
 * \brief  Enable High-Speed Crystal Oscillator Failure Interrupt
 * \note   This function enables the High-Speed Crystal Oscillator (HXTL) failure interrupt by setting
 *         the HXTLFAILIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated if the high-speed crystal oscillator fails.
 */
static inline void RCC_enableHxtlFailInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_HXTLFAILIE_M);
}

/**
 * \brief  Disable High-Speed Crystal Oscillator Failure Interrupt
 * \note   This function disables the High-Speed Crystal Oscillator (HXTL) failure interrupt by clearing
 *         the HXTLFAILIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated if the high-speed crystal oscillator fails.
 */
static inline void RCC_disableHxtlFailInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_HXTLFAILIE_M);
}

/**
 * \brief  Enable High-Speed Crystal Oscillator Ready Interrupt
 * \note   This function enables the High-Speed Crystal Oscillator (HXTL) ready interrupt by setting
 *         the HXTLRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated when the high-speed crystal oscillator is ready.
 */
static inline void RCC_enableHxtlRdyInt(void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_HXTLRDYIE_M);
}

/**
 * \brief  Disable High-Speed Crystal Oscillator Ready Interrupt
 * \note   This function disables the High-Speed Crystal Oscillator (HXTL) ready interrupt by clearing
 *         the HXTLRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated when the high-speed crystal oscillator is ready.
 */
static inline void RCC_disableHxtlRdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_HXTLRDYIE_M);
}

/**
 * \brief  Enable High-Speed Crystal Oscillator Maskable Interrupt
 * \note   This function enables the High-Speed Crystal Oscillator (HXTL) Maskable Interrupt selection by setting
 *         the HXTLNFSELIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, a maskable interrupt will be generated when HXTL fails.
 */
static inline void RCC_enableHxtlNfSelInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_HXTLNFSEL_M);
}

/**
 * \brief  Disable High-Speed Crystal Oscillator Maskable Interrupt
 * \note   This function disables the High-Speed Crystal Oscillator (HXTL) Maskable Interrupt selection by clearing
 *         the HXTLNFSELIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, a nmi interrupt will be generated when HXTL fails.
 */
static inline void RCC_disableHxtlNfSelInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_HXTLNFSEL_M);
}

/**
 * \brief  Enable Low-Speed Internal RC Oscillator Ready Interrupt
 * \note   This function enables the Low-Speed Internal RC Oscillator (LIRC) ready interrupt by setting
 *         the LIRCRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated when the low-speed internal RC oscillator is ready.
 */
static inline void RCC_enableLircRdyInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_LIRCRDYIE_M);
}

/**
 * \brief  Disable Low-Speed Internal RC Oscillator Ready Interrupt
 * \note   This function disables the Low-Speed Internal RC Oscillator (LIRC) ready interrupt by clearing
 *         the LIRCRDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated when the low-speed internal RC oscillator is ready.
 */
static inline void RCC_disableLircRdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_LIRCRDYIE_M);
}

/**
 * \brief  Enable Medium-Speed Internal RC Oscillator 1 Ready Interrupt
 * \note   This function enables the Medium-Speed Internal RC Oscillator 1 (MIRC1) ready interrupt by setting
 *         the MIRC1RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated when the medium-speed internal RC oscillator 1 is ready.
 */
static inline void RCC_enableMirc1RdyInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_MIRC1RDYIE_M);
}

/**
 * \brief  Disable Medium-Speed Internal RC Oscillator 1 Ready Interrupt
 * \note   This function disables the Medium-Speed Internal RC Oscillator 1 (MIRC1) ready interrupt by clearing
 *         the MIRC1RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated when the medium-speed internal RC oscillator 1 is ready.
 */
static inline void RCC_disableMirc1RdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_MIRC1RDYIE_M);
}

/**
 * \brief  Enable Medium-Speed Internal RC Oscillator 2 Ready Interrupt
 * \note   This function enables the Medium-Speed Internal RC Oscillator 2 (MIRC2) ready interrupt by setting
 *         the MIRC2RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When enabled, an interrupt will be generated when the medium-speed internal RC oscillator 2 is ready.
 */
static inline void RCC_enableMirc2RdyInt (void)
{
    SET_BIT(RCC->IER.WORDVAL, RCC_MIRC2RDYIE_M);
}

/**
 * \brief  Disable Medium-Speed Internal RC Oscillator 2 Ready Interrupt
 * \note   This function disables the Medium-Speed Internal RC Oscillator 2 (MIRC2) ready interrupt by clearing
 *         the MIRC2RDYIE bit in the RCC Interrupt Enable Register (RCC->IER).
 *         When disabled, no interrupt will be generated when the medium-speed internal RC oscillator 2 is ready.
 */
static inline void RCC_disableMirc2RdyInt (void)
{
    CLEAR_BIT(RCC->IER.WORDVAL, RCC_MIRC2RDYIE_M);
}

/**
 * \brief  Read the OSCCLK stop Interrupt Flag.
 * \note   This function checks the OSCCLKSTOPIF bit in the OSCCLK stop Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the OSCCLK stop Interrupt Flag.
 *          - 0: The OSCCLK stop Interrupt Flag is not set.
 *          - 1: The OSCCLK stop Interrupt Flag is set.
 */
static inline uint32_t RCC_readOscclkStopIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_PLL_LOSCCLKSTOPIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the PLL Loss of Lock Interrupt Flag.
 * \note   This function checks the PLL_LOLIF bit in the RCC Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the PLL Loss of Lock Interrupt Flag.
 *          - 0: The PLL Loss of Lock Interrupt Flag is not set.
 *          - 1: The PLL Loss of Lock Interrupt Flag is set.
 */
static inline uint32_t RCC_readPllLolIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_PLL_LOLIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the PLL Lock Detect Interrupt Flag.
 * \note   This function checks the PLL_LKDTIF bit in the RCC Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the PLL Lock Detect Interrupt Flag.
 *          - 0: The PLL Lock Detect Interrupt Flag is not set.
 *          - 1: The PLL Lock Detect Interrupt Flag is set.
 */
static inline uint32_t RCC_readPllLkdtIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_PLL_LKDTIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the HXTL Fail Interrupt Flag.
 * \note   This function checks the HXTLFAILIF bit in the RCC Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the HXTL Fail Interrupt Flag.
 *          - 0: The HXTL Fail Interrupt Flag is not set.
 *          - 1: The HXTL Fail Interrupt Flag is set.
 */
static inline uint32_t RCC_readHxtlFailIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_HXTLFAILIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the HXTL Ready Interrupt Flag.
 * \note   This function checks the HXTLRDYIF bit in the RCC Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the HXTL Ready Interrupt Flag.
 *          - 0: The HXTL Ready Interrupt Flag is not set.
 *          - 1: The HXTL Ready Interrupt Flag is set.
 */
static inline uint32_t RCC_readHxtlRdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_HXTLRDYIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the LIRC Ready Interrupt Flag.
 * \note   This function checks the LIRCRDYIF bit in the RCC Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the LIRC Ready Interrupt Flag.
 *          - 0: The LIRC Ready Interrupt Flag is not set.
 *          - 1: The LIRC Ready Interrupt Flag is set.
 */
static inline uint32_t RCC_readLircRdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_LIRCRDYIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the MIRC1 Ready Interrupt Flag.
 * \note   This function checks the MIRC1RDYIF bit in the RCC Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the MIRC1 Ready Interrupt Flag.
 *          - 0: The MIRC1 Ready Interrupt Flag is not set.
 *          - 1: The MIRC1 Ready Interrupt Flag is set.
 */
static inline uint32_t RCC_readMirc1RdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_MIRC1RDYIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the MIRC2 Ready Interrupt Flag.
 * \note   This function checks the MIRC2RDYIF bit in the RCC Interrupt Flag Register (RCC->IFR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the MIRC2 Ready Interrupt Flag.
 *          - 0: The MIRC2 Ready Interrupt Flag is not set.
 *          - 1: The MIRC2 Ready Interrupt Flag is set.
 */
static inline uint32_t RCC_readMirc2RdyIntFlag (void)
{
    return READ_BIT(RCC->IFR.WORDVAL, RCC_MIRC2RDYIF_M) ? 1UL : 0UL;
}

/**
 * \brief  Clear the OSCCLK stop Interrupt Flag.
 * \note   This function clears the OSCCLKSTOPIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_PLL_OSCCLKSTOPCLR_M bit.
 *         Clearing this flag is necessary after a OSCCLK stop interrupt occurs.
 */
static inline void RCC_clearOscclkStopIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_PLL_OSCCLKSTOPCLR_M);
}

/**
 * \brief  Clear the PLL Loss of Lock (LOL) Interrupt Flag.
 * \note   This function clears the PLL_LOLIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_PLL_LOLCLR_M bit.
 *         Clearing this flag is necessary after a PLL loss of lock interrupt occurs.
 */
static inline void RCC_clearPllLolIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_PLL_LOLCLR_M);
}

/**
 * \brief  Clear the PLL Lock Timer (LKDT) Interrupt Flag.
 * \note   This function clears the PLL_LKDTIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_PLL_LKDTCLR_M bit.
 *         Clearing this flag is necessary after a PLL lock timer interrupt occurs.
 */
static inline void RCC_clearPllLkdtIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_PLL_LKDTCLR_M);
}

/**
 * \brief  Clear the High-Speed External Crystal Oscillator (HXTL) Failure Interrupt Flag.
 * \note   This function clears the HXTLFAILIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_HXTLFAILCLR_M bit.
 *         Clearing this flag is necessary after an external high-speed crystal oscillator failure interrupt occurs.
 */
static inline void RCC_clearHxtlFailIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_HXTLFAILCLR_M);
}

/**
 * \brief  Clear the High-Speed External Crystal Oscillator (HXTL) Ready Interrupt Flag.
 * \note   This function clears the HXTLRDYIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_HXTLRDYCLR_M bit.
 *         Clearing this flag is necessary after an external high-speed crystal oscillator ready interrupt occurs.
 */
static inline void RCC_clearHxtlRdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_HXTLRDYCLR_M);
}

/**
 * \brief  Clear the Low-Speed Internal RC Oscillator (LIRC) Ready Interrupt Flag.
 * \note   This function clears the LIRCRDYIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_LIRCRDYCLR_M bit.
 *         Clearing this flag is necessary after an internal low-speed RC oscillator ready interrupt occurs.
 */
static inline void RCC_clearLircRdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_LIRCRDYCLR_M);
}

/**
 * \brief  Clear the Medium-Speed Internal RC Oscillator 1 (MIRC1) Ready Interrupt Flag.
 * \note   This function clears the MIRC1RDYIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_MIRC1RDYCLR_M bit.
 *         Clearing this flag is necessary after an internal medium-speed RC oscillator 1 ready interrupt occurs.
 */
static inline void RCC_clearMirc1RdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_MIRC1RDYCLR_M);
}

/**
 * \brief  Clear the Medium-Speed Internal RC Oscillator 2 (MIRC2) Ready Interrupt Flag.
 * \note   This function clears the MIRC2RDYIF bit in the RCC Clear Register (RCC->CLR)
 *         by setting the RCC_MIRC2RDYCLR_M bit.
 *         Clearing this flag is necessary after an internal medium-speed RC oscillator 2 ready interrupt occurs.
 */
static inline void RCC_clearMirc2RdyIntFlag (void)
{
    SET_BIT(RCC->CLR.WORDVAL, RCC_MIRC2RDYCLR_M);
}

/**
 * \brief  Enable the Auxiliary Clock Input.
 * \note   This function enables the auxiliary clock input by setting the AUXCLKEN bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Enabling this bit allows the system to use the auxiliary clock source.
 */
static inline void RCC_enableAuxClockIn (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_AUXCLKEN_M);
}

/**
 * \brief  Disable the Auxiliary Clock Input.
 * \note   This function disables the auxiliary clock input by clearing the AUXCLKEN bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Clearing this bit prevents the system from using the auxiliary clock source.
 */
static inline void RCC_disableAuxClockIn (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_AUXCLKEN_M);
}

/**
 * \brief  Select the Auxiliary Clock Input Reset Mode.
 * \note   This function selects the auxiliary clock input reset mode by setting the AUXCLKRST bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Setting this bit configures the system to use the auxiliary clock source in reset mode.
 */
static inline void RCC_selectAuxClockInResetMode (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_AUXCLKRST_M);
}

/**
 * \brief  Select the Auxiliary Clock Input Normal Mode.
 * \note   This function selects the auxiliary clock input normal mode by clearing the AUXCLKRST bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Clearing this bit configures the system to use the auxiliary clock source in normal mode.
 */
static inline void RCC_selectAuxClockInNormalMode (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_AUXCLKRST_M);
}

/**
 * \brief  Enable the DLL Clock.
 * \note   This function enables the DLL clock by setting the DLL_CLKEN bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Enabling this bit allows the system to use the DLL clock source.
 */
static inline void RCC_enableDllClock (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_DLL_CLKEN_M);
}

/**
 * \brief  Disable the DLL Clock.
 * \note   This function disables the DLL clock by clearing the DLL_CLKEN bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Clearing this bit prevents the system from using the DLL clock source.
 */
static inline void RCC_disableDllClock (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_DLL_CLKEN_M);
}

/**
 * \brief  Enable the HRPWM Clock.
 * \note   This function enables the HRPWM clock by setting the HRPWM_CLKEN bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Enabling this bit allows the system to use the HRPWM clock source.
 */
static inline void RCC_enableHrpwmClock (void)
{
    SET_BIT(RCC->IPCLKSEL.WORDVAL, RCC_HRPWM_CLKEN_M);
}

/**
 * \brief  Disable the HRPWM Clock.
 * \note   This function disables the HRPWM clock by clearing the HRPWM_CLKEN bit in the
 *         RCC IP Clock Select Register (RCC->IPCLKSEL).
 *         Clearing this bit prevents the system from using the HRPWM clock source.
 */
static inline void RCC_disableHrpwmClock (void)
{
    CLEAR_BIT(RCC->IPCLKSEL.WORDVAL, RCC_HRPWM_CLKEN_M);
}

/**
 * \brief  Read the CAN1 PCLK Source Status.
 * \note   This function checks the CAN1PCLK_ST bit in the RCC IP Clock Select Register (RCC->IPCLKSEL)
 *         and returns a boolean value indicating the status of the CAN1 peripheral clock source.
 * \return Returns the status of the CAN1 pclock source.
 *          - 0: CAN1 pclock source is OSC (Oscillator)
 *          - 1: CAN1 pclock source is PERIPHERAL (Peripheral clock)
 */
static inline uint32_t RCC_readCan1PclkSourceStatus (void)
{
    return READ_BIT(RCC->IPCLKSEL.WORDVAL, RCC_CAN1_PCLK_ST_M) ? 1UL : 0UL;
}

/**
 * \brief  Select the CAN1 Time Base Clock Division
 * \note   This function selects the division factor for the CAN1 time base clock by modifying
 *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
 * \param  can1TimeClkDiv  Specifies the division factor for the CAN1 time base clock.
 *                          This parameter can be any value of @ref RCC_CAN1TIMECLKDIV
 */
static inline void RCC_selectCan1TimeClkDiv (RCC_Can1TimeclkDiv can1TimeClkDiv)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_CAN1_TIMECLK_DIV_M, (can1TimeClkDiv << RCC_CAN1_TIMECLK_DIV_S));
}

/**
 * \brief  Select the CAN1 Oscillator Clock Source
 * \note   This function selects the clock source for the CAN1 oscillator by modifying
 *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
 * \param  can1OscClk  Specifies the clock source for the CAN1 oscillator.
 *                      This parameter can be any value of @ref RCC_CAN1OSCCLK
 */
static inline void RCC_selectCan1OscClkSource (RCC_Can1OscClk can1OscClk)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_CAN1_OSC_SEL_M, (can1OscClk << RCC_CAN1_OSC_SEL_S));
}

/**
 * \brief  Select the CAN1 Peripheral Clock Source
 * \note   This function selects the clock source for the CAN1 peripheral by modifying
 *         the appropriate bits in the IPCLKSEL register (RCC->IPCLKSEL).
 * \param  can1PeripheralClk  Specifies the clock source for the CAN1 peripheral.
 *                             This parameter can be any value of @ref RCC_CAN1PERIPHERALCLK
 */
static inline void RCC_selectCan1PeripheralClkSource (RCC_Can1PeripheralClk can1PeripheralClk)
{
    MODIFY_REG(RCC->IPCLKSEL.WORDVAL, RCC_CAN1_CLK_SEL_M, (can1PeripheralClk << RCC_CAN1_CLK_SEL_S));
}

/**
 * \brief  Read the PLL Multiplication Factor (PLLM) value.
 * \note   This function reads the PLLM bits in the RCC PLL Configuration Register (RCC->PLLCR1)
 *         and returns their value after shifting it right by 8 bits.
 * \return Returns the PLLM value.
 */
static inline uint32_t RCC_readPllmValue (void)
{
    return (READ_BIT(RCC->PLLCR1.WORDVAL, RCC_PLLM_M) >> RCC_PLLM_S);
}

/**
 * \brief  Select the PLLM Doubling Factor
 * \note   This function selects the PLLM Doubling factor by modifying
 *         the appropriate bits in the PLLCR1 register (RCC->PLLCR1).
 * \param  pllmSelection  Specifies the PLLM Doubling factor.
 *                         This parameter can be any value of @ref RCC_PLLMSELECTION.
 */
static inline void RCC_selectPllm (RCC_PllmSelection pllmSelection)
{
    MODIFY_REG(RCC->PLLCR1.WORDVAL, RCC_PLLM_M, (pllmSelection << RCC_PLLM_S));
}

/**
 * \brief  Read the PLL Division Factor (PLLN) value.
 * \note   This function reads the PLLN bits in the RCC PLL Configuration Register (RCC->PLLCR1)
 *         and returns their value after shifting it right by 4 bits.
 * \return Returns the PLLN value.
 */
static inline uint32_t RCC_readPllnValue (void)
{
    return (READ_BIT(RCC->PLLCR1.WORDVAL, RCC_PLLN_M) >> RCC_PLLN_S);
}

/**
 * \brief  Select the PLLN Division Factor
 * \note   This function selects the PLLN Division factor by modifying
 *         the appropriate bits in the PLLCR1 register (RCC->PLLCR1).
 * \param  pllnSelection  Specifies the PLLN Division factor.
 *                         This parameter can be any value of @ref RCC_PLLNSELECTION
 */
static inline void RCC_selectPlln (RCC_PllnSelection pllnSelection)
{
    MODIFY_REG(RCC->PLLCR1.WORDVAL, RCC_PLLN_M, (pllnSelection << RCC_PLLN_S));
}

/**
 * \brief  Read the PLL Post-Division Factor (PLLP) value.
 * \note   This function reads the PLLP bits in the RCC PLL Configuration Register (RCC->PLLCR1)
 *         and returns their value after shifting it right by 17 bits.
 * \return Returns the PLLP value.
 */
static inline uint32_t RCC_readPllpValue (void)
{
    return (READ_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLP_M) >> RCC_PLLP_S);
}

/**
 * \brief  Select the PLLP Division Factor
 * \note   This function selects the PLLP Division factor by modifying
 *         the appropriate bits in the PLLCR1 register (RCC->PLLCR1).
 * \param  pllpSelection  Specifies the PLLP Division factor.
 *                         This parameter can be any value of @ref RCC_PLLPSELECTION
 */
static inline void RCC_selectPllp (RCC_PllpSelection pllpSelection)
{
    MODIFY_REG(RCC->PLLCR2.WORDVAL, RCC_PLLP_M, (pllpSelection << RCC_PLLP_S));
}

/**
 * \brief  Enable the PLLP Clock Output.
 * \note   This function enables the PLLP clock output by setting the PLLPEN bit in the
 *         RCC PLL Control Register (RCC->PLLCR1).
 *         Enabling this bit allows the system to use the PLLP clock source.
 */
static inline void RCC_enablePllpClockOutput (void)
{
    SET_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLPEN_M);
}

/**
 * \brief  Disable the PLLP Clock Output.
 * \note   This function disables the PLLP clock output by clearing the PLLPEN bit in the
 *         RCC PLL Control Register (RCC->PLLCR1).
 *         Disabling this bit stops the system from using the PLLP clock source.
 */
static inline void RCC_disablePllpClockOutput (void)
{
    CLEAR_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLPEN_M);
}

/**
 * \brief  Select the PLLQ Division Factor
 * \note   This function selects the PLLQ Division factor by modifying
 *         the appropriate bits in the PLLCR1 register (RCC->PLLCR1).
 * \param  pllqSelection  Specifies the PLLQ Division factor.
 *                         This parameter can be any value of @ref RCC_PLLQSELECTION
 */
static inline void RCC_selectPllq (RCC_PllqSelection pllqSelection)
{
    MODIFY_REG(RCC->PLLCR2.WORDVAL, RCC_PLLQ_M, (pllqSelection << RCC_PLLQ_S));
}

/**
 * \brief  Enable the PLLQ Clock Output.
 * \note   This function enables the PLLQ clock output by setting the PLLQEN bit in the
 *         RCC PLL Control Register (RCC->PLLCR1).
 *         Enabling this bit allows the system to use the PLLQ clock source.
 */
static inline void RCC_enablePllqClockOutput (void)
{
    SET_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLQEN_M);
}

/**
 * \brief  Disable the PLLQ Clock Output.
 * \note   This function disables the PLLQ clock output by clearing the PLLQEN bit in the
 *         RCC PLL Control Register (RCC->PLLCR1).
 *         Disabling this bit stops the system from using the PLLQ clock source.
 */
static inline void RCC_disablePllqClockOutput (void)
{
    CLEAR_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLQEN_M);
}

/**
 * \brief  Select the PLLR Division Factor
 * \note   This function selects the PLLR Division factor by modifying
 *         the appropriate bits in the PLLCR1 register (RCC->PLLCR1).
 * \param  pllrSelection  Specifies the PLLR Division factor.
 *                         This parameter can be any value of @ref RCC_PLLRSELECTION
 */
static inline void RCC_selectPllr (RCC_PllrSelection pllrSelection)
{
    MODIFY_REG(RCC->PLLCR2.WORDVAL, RCC_PLLR_M, (pllrSelection << RCC_PLLR_S));
}

/**
 * \brief  Read the the PLLR Division value.
 * \note   This function reads the PLLR bits in the RCC PLL Configuration Register (RCC->PLLCR2)
 *         and returns their value after shifting it right by 1 bits.
 * \return Returns the PLLR value.
 */
static inline uint32_t RCC_readPllrValue (void)
{
    return (READ_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLR_M) >> RCC_PLLR_S);
}

/**
 * \brief  Enable the PLLR Clock Output.
 * \note   This function enables the PLLR clock output by setting the PLLREN bit in the
 *         RCC PLL Control Register (RCC->PLLCR1).
 *         Enabling this bit allows the system to use the PLLR clock source.
 */
static inline void RCC_enablePllrClockOutput (void)
{
    SET_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLREN_M);
}

/**
 * \brief  Disable the PLLR Clock Output.
 * \note   This function disables the PLLR clock output by clearing the PLLREN bit in the
 *         RCC PLL Control Register (RCC->PLLCR1).
 *         Disabling this bit stops the system from using the PLLR clock source.
 */
static inline void RCC_disablePllrClockOutput (void)
{
    CLEAR_BIT(RCC->PLLCR2.WORDVAL, RCC_PLLREN_M);
}

/**
 * \brief  Enable the PLL Force Lock.
 * \note   This function enables the PLL force lock by setting the FORCELKEN bit in the
 *         RCC PLL Control Register (RCC->PLLCR3).
 *         Enabling this bit forces the PLL to lock.
 */
static inline void RCC_enablePllForceLock (void)
{
    SET_BIT(RCC->PLLCR3.WORDVAL, RCC_FORCELKEN_M);
}

/**
 * \brief  Disable the PLL Force Lock.
 * \note   This function disables the PLL force lock by clearing the FORCELKEN bit in the
 *         RCC PLL Control Register (RCC->PLLCR3).
 *         Disabling this bit stops forcing the PLL to lock.
 */
static inline void RCC_disablePllForceLock (void)
{
    CLEAR_BIT(RCC->PLLCR3.WORDVAL, RCC_FORCELKEN_M);
}

/**
 * \brief  Select the PLL Lock Detection Threshold
 * \note   This function selects the PLL lock detection threshold by modifying
 *         the appropriate bits in the PLLCR3 register (RCC->PLLCR3).
 * \param  pllLkdtSelection  Specifies the PLL lock detection threshold.
 *                            This parameter can be any value of @ref RCC_PLLLKDTSELECTION
 */
static inline void RCC_selectPllLdkt (RCC_PllLkdtSelection pllLkdtSelection)
{
    MODIFY_REG(RCC->PLLCR3.WORDVAL, RCC_PLLLKDTSET_M, (pllLkdtSelection << RCC_PLLLKDTSET_S));
}

/**
 * \brief  Read the PLL Lock Over Count.
 * \note   This function reads the value of the PLL Status Register 1 (PLLSR1)
 *         and returns the word value of the register.
 * \return Returns the value of the PLL Status Register 1 (PLLSR1).
 */
static inline uint32_t RCC_readPllLockOverCnt (void)
{
    return READ_REG(RCC->PLLSR.WORDVAL);
}

/**
 * \brief  Reset the GPIOH module.
 * \note   This function resets the GPIOH module by setting the GPIOHRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Resetting this bit allows for a reset of the GPIOH module.
 */
static inline void RCC_resetGpiohModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOHRST_M);
}

/**
 * \brief  Release the reset of the GPIOH module.
 * \note   This function releases the reset of the GPIOH module by clearing the GPIOHRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Clearing this bit allows the GPIOH module to resume normal operation after a reset.
 */
static inline void RCC_releaseGpiohModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOHRST_M);
}

/**
 * \brief  Reset the GPIOC module.
 * \note   This function resets the GPIOC module by setting the GPIOCRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Setting this bit allows for a reset of the GPIOC module.
 */
static inline void RCC_resetGpiocModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOCRST_M);
}

/**
 * \brief  Release the reset of the GPIOC module.
 * \note   This function releases the reset of the GPIOC module by clearing the GPIOCRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Clearing this bit allows the GPIOC module to resume normal operation after a reset.
 */
static inline void RCC_releaseGpiocModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOCRST_M);
}

/**
 * \brief  Reset the GPIOB module.
 * \note   This function resets the GPIOB module by setting the GPIOBRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Setting this bit allows for a reset of the GPIOB module.
 */
static inline void RCC_resetGpiobModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOBRST_M);
}

/**
 * \brief  Release the reset of the GPIOB module.
 * \note   This function releases the reset of the GPIOB module by clearing the GPIOBRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Clearing this bit allows the GPIOB module to resume normal operation after a reset.
 */
static inline void RCC_releaseGpiobModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOBRST_M);
}

/**
 * \brief  Reset the GPIOA module.
 * \note   This function resets the GPIOA module by setting the GPIOARST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Setting this bit allows for a reset of the GPIOA module.
 */
static inline void RCC_resetGpioaModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOARST_M);
}

/**
 * \brief  Release the reset of the GPIOA module.
 * \note   This function releases the reset of the GPIOA module by clearing the GPIOARST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Clearing this bit allows the GPIOA module to resume normal operation after a reset.
 */
static inline void RCC_releaseGpioaModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_GPIOARST_M);
}

/**
 * \brief  Reset the MMATH module.
 * \note   This function resets the MMATH module by setting the MMATHRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Setting this bit allows for a reset of the MMATH module.
 */
static inline void RCC_resetMmathModule (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_MMATHRST_M);
}

/**
 * \brief  Release the reset of the MMATH module.
 * \note   This function releases the reset of the MMATH module by clearing the MMATHRST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Clearing this bit allows the MMATH module to resume normal operation after a reset.
 */
static inline void RCC_releaseMmathModule (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_MMATHRST_M);
}

/**
 * \brief  Reset the EDMA1 module.
 * \note   This function resets the EDMA1 module by setting the EDMA1RST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Setting this bit allows for a reset of the EDMA1 module.
 */
static inline void RCC_resetDma1Module (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_EDMA1RST_M);
}

/**
 * \brief  Release the reset of the EDMA1 module.
 * \note   This function releases the reset of the EDMA1 module by clearing the EDMA1RST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Clearing this bit allows the EDMA1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseDma1Module (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_EDMA1RST_M);
}

/**
 * \brief  Reset the DMAMUX1 module.
 * \note   This function resets the DMAMUX1 module by setting the DMAMUX1RST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Setting this bit allows for a reset of the DMAMUX1 module.
 */
static inline void RCC_resetDmamux1Module (void)
{
    SET_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_DMAMUX1RST_M);
}

/**
 * \brief  Release the reset of the DMAMUX1 module.
 * \note   This function releases the reset of the DMAMUX1 module by clearing the DMAMUX1RST bit in the
 *         RCC AHB1 Reset Register (RCC->AHBRST1).
 *         Clearing this bit allows the DMAMUX1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseDmamux1Module (void)
{
    CLEAR_BIT(RCC->AHBRST1.WORDVAL, RCC_AHB_DMAMUX1RST_M);
}

/**
 * \brief  Reset the CAN1 module.
 * \note   This function resets the CAN1 module by setting the CAN1RST bit in the
 *         RCC AHB2 Reset Register (RCC->AHBRST2).
 *         Setting this bit allows for a reset of the CAN1 module.
 */
static inline void RCC_resetCan1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHB_CAN1RST_M);
}

/**
 * \brief  Release the reset of the CAN1 module.
 * \note   This function releases the reset of the CAN1 module by clearing the CAN1RST bit in the
 *         RCC AHB2 Reset Register (RCC->AHBRST2).
 *         Clearing this bit allows the CAN1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseCan1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHB_CAN1RST_M);
}

/**
 * \brief  Reset the LIN1 module.
 * \note   This function resets the LIN1 module by setting the LIN1RST bit in the
 *         RCC AHB2 Reset Register (RCC->AHBRST2).
 *         Setting this bit allows for a reset of the LIN1 module.
 */
static inline void RCC_resetLin1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHB_LIN1RST_M);
}

/**
 * \brief  Release the reset of the LIN1 module.
 * \note   This function releases the reset of the LIN1 module by clearing the LIN1RST bit in the
 *         RCC AHB2 Reset Register (RCC->AHBRST2).
 *         Clearing this bit allows the LIN1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseLin1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHB_LIN1RST_M);
}

/**
 * \brief  Reset the BGCRC1 module.
 * \note   This function resets the BGCRC1 module by setting the BGCRC1RST bit in the
 *         RCC AHB2 Reset Register (RCC->AHBRST2).
 *         Setting this bit allows for a reset of the BGCRC1 module.
 */
static inline void RCC_resetBgcrc1Module (void)
{
    SET_BIT(RCC->AHBRST2.WORDVAL, RCC_AHB_BGCRC1RST_M);
}

/**
 * \brief  Release the reset of the BGCRC1 module.
 * \note   This function releases the reset of the BGCRC1 module by clearing the BGCRC1RST bit in the
 *         RCC AHB2 Reset Register (RCC->AHBRST2).
 *         Clearing this bit allows the BGCRC1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseBgcrc1Module (void)
{
    CLEAR_BIT(RCC->AHBRST2.WORDVAL, RCC_AHB_BGCRC1RST_M);
}

/**
 * \brief  Reset the EQEP2 module.
 * \note   This function resets the EQEP2 module by setting the EQEP2RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EQEP2 module.
 */
static inline void RCC_resetEqep2Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EQEP2RST_M);
}

/**
 * \brief  Release the reset of the EQEP2 module.
 * \note   This function releases the reset of the EQEP2 module by clearing the EQEP2RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EQEP2 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEqep2Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EQEP2RST_M);
}

/**
 * \brief  Reset the EQEP1 module.
 * \note   This function resets the EQEP1 module by setting the EQEP1RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EQEP1 module.
 */
static inline void RCC_resetEqep1Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EQEP1RST_M);
}

/**
 * \brief  Release the reset of the EQEP1 module.
 * \note   This function releases the reset of the EQEP1 module by clearing the EQEP1RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EQEP1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEqep1Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EQEP1RST_M);
}

/**
 * \brief  Reset the ECAP3 module.
 * \note   This function resets the ECAP3 module by setting the ECAP3RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the ECAP3 module.
 */
static inline void RCC_resetEcap3Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_ECAP3RST_M);
}

/**
 * \brief  Release the reset of the ECAP3 module.
 * \note   This function releases the reset of the ECAP3 module by clearing the ECAP3RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the ECAP3 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEcap3Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_ECAP3RST_M);
}

/**
 * \brief  Reset the ECAP2 module.
 * \note   This function resets the ECAP2 module by setting the ECAP2RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the ECAP2 module.
 */
static inline void RCC_resetEcap2Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_ECAP2RST_M);
}

/**
 * \brief  Release the reset of the ECAP2 module.
 * \note   This function releases the reset of the ECAP2 module by clearing the ECAP2RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the ECAP2 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEcap2Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_ECAP2RST_M);
}

/**
 * \brief  Reset the ECAP1 module.
 * \note   This function resets the ECAP1 module by setting the ECAP1RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the ECAP1 module.
 */
static inline void RCC_resetEcap1Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_ECAP1RST_M);
}

/**
 * \brief  Release the reset of the ECAP1 module.
 * \note   This function releases the reset of the ECAP1 module by clearing the ECAP1RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the ECAP1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEcap1Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_ECAP1RST_M);
}

/**
 * \brief  Reset the EPWM7 module.
 * \note   This function resets the EPWM7 module by setting the EPWM7RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EPWM7 module.
 */
static inline void RCC_resetEpwm7Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM7RST_M);
}

/**
 * \brief  Release the reset of the EPWM7 module.
 * \note   This function releases the reset of the EPWM7 module by clearing the EPWM7RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EPWM7 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpwm7Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM7RST_M);
}

/**
 * \brief  Reset the EPWM6 module.
 * \note   This function resets the EPWM6 module by setting the EPWM6RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EPWM6 module.
 */
static inline void RCC_resetEpwm6Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM6RST_M);
}

/**
 * \brief  Release the reset of the EPWM6 module.
 * \note   This function releases the reset of the EPWM6 module by clearing the EPWM6RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EPWM6 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpwm6Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM6RST_M);
}

/**
 * \brief  Reset the EPWM5 module.
 * \note   This function resets the EPWM5 module by setting the EPWM5RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EPWM5 module.
 */
static inline void RCC_resetEpwm5Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM5RST_M);
}

/**
 * \brief  Release the reset of the EPWM5 module.
 * \note   This function releases the reset of the EPWM5 module by clearing the EPWM5RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EPWM5 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpwm5Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM5RST_M);
}

/**
 * \brief  Reset the EPWM4 module.
 * \note   This function resets the EPWM4 module by setting the EPWM4RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EPWM4 module.
 */
static inline void RCC_resetEpwm4Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM4RST_M);
}

/**
 * \brief  Release the reset of the EPWM4 module.
 * \note   This function releases the reset of the EPWM4 module by clearing the EPWM4RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EPWM4 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpwm4Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM4RST_M);
}

/**
 * \brief  Reset the EPWM3 module.
 * \note   This function resets the EPWM3 module by setting the EPWM3RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EPWM3 module.
 */
static inline void RCC_resetEpwm3Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM3RST_M);
}

/**
 * \brief  Release the reset of the EPWM3 module.
 * \note   This function releases the reset of the EPWM3 module by clearing the EPWM3RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EPWM3 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpwm3Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM3RST_M);
}

/**
 * \brief  Reset the EPWM2 module.
 * \note   This function resets the EPWM2 module by setting the EPWM2RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EPWM2 module.
 */
static inline void RCC_resetEpwm2Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM2RST_M);
}

/**
 * \brief  Release the reset of the EPWM2 module.
 * \note   This function releases the reset of the EPWM2 module by clearing the EPWM2RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EPWM2 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpwm2Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM2RST_M);
}

/**
 * \brief  Reset the EPWM1 module.
 * \note   This function resets the EPWM1 module by setting the EPWM1RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Setting this bit allows for a reset of the EPWM1 module.
 */
static inline void RCC_resetEpwm1Module (void)
{
    SET_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM1RST_M);
}

/**
 * \brief  Release the reset of the EPWM1 module.
 * \note   This function releases the reset of the EPWM1 module by clearing the EPWM1RST bit in the
 *         RCC APB Reset Register 1 (RCC->APBRST1).
 *         Clearing this bit allows the EPWM1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpwm1Module (void)
{
    CLEAR_BIT(RCC->APBRST1.WORDVAL, RCC_APB_EPWM1RST_M);
}

/**
 * \brief  Reset the CMPSS4 module.
 * \note   This function resets the CMPSS4 module by setting the CMPSS4RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Setting this bit allows for a reset of the CMPSS4 module.
 */
static inline void RCC_resetCmpss4Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS4RST_M);
}

/**
 * \brief  Release the reset of the CMPSS4 module.
 * \note   This function releases the reset of the CMPSS4 module by clearing the CMPSS4RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Clearing this bit allows the CMPSS4 module to resume normal operation after a reset.
 */
static inline void RCC_releaseCmpss4Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS4RST_M);
}

/**
 * \brief  Reset the CMPSS3 module.
 * \note   This function resets the CMPSS3 module by setting the CMPSS3RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Setting this bit allows for a reset of the CMPSS3 module.
 */
static inline void RCC_resetCmpss3Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS3RST_M);
}

/**
 * \brief  Release the reset of the CMPSS3 module.
 * \note   This function releases the reset of the CMPSS3 module by clearing the CMPSS3RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Clearing this bit allows the CMPSS3 module to resume normal operation after a reset.
 */
static inline void RCC_releaseCmpss3Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS3RST_M);
}

/**
 * \brief  Reset the CMPSS2 module.
 * \note   This function resets the CMPSS2 module by setting the CMPSS2RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Setting this bit allows for a reset of the CMPSS2 module.
 */
static inline void RCC_resetCmpss2Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS2RST_M);
}

/**
 * \brief  Release the reset of the CMPSS2 module.
 * \note   This function releases the reset of the CMPSS2 module by clearing the CMPSS2RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Clearing this bit allows the CMPSS2 module to resume normal operation after a reset.
 */
static inline void RCC_releaseCmpss2Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS2RST_M);
}

/**
 * \brief  Reset the CMPSS1 module.
 * \note   This function resets the CMPSS1 module by setting the CMPSS1RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Setting this bit allows for a reset of the CMPSS1 module.
 */
static inline void RCC_resetCmpss1Module (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS1RST_M);
}

/**
 * \brief  Release the reset of the CMPSS1 module.
 * \note   This function releases the reset of the CMPSS1 module by clearing the CMPSS1RST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Clearing this bit allows the CMPSS1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseCmpss1Module (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APB_CMPSS1RST_M);
}

/**
 * \brief  Reset the XBAR module.
 * \note   This function resets the XBAR module by setting the XBARRST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Setting this bit allows for a reset of the XBAR module.
 */
static inline void RCC_resetXbarModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APB_XBARRST_M);
}

/**
 * \brief  Release the reset of the XBAR module.
 * \note   This function releases the reset of the XBAR module by clearing the XBARRST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Clearing this bit allows the XBAR module to resume normal operation after a reset.
 */
static inline void RCC_releaseXbarModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APB_XBARRST_M);
}

/**
 * \brief  Reset the ADCC module.
 * \note   This function resets the ADCC module by setting the ADCCRST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Setting this bit allows for a reset of the ADCC module.
 */
static inline void RCC_resetAdccModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APB_ADCCRST_M);
}

/**
 * \brief  Release the reset of the ADCC module.
 * \note   This function releases the reset of the ADCC module by clearing the ADCCRST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Clearing this bit allows the ADCC module to resume normal operation after a reset.
 */
static inline void RCC_releaseAdccModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APB_ADCCRST_M);
}

/**
 * \brief  Reset the ADCA module.
 * \note   This function resets the ADCA module by setting the ADCARST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Setting this bit allows for a reset of the ADCA module.
 */
static inline void RCC_resetAdcaModule (void)
{
    SET_BIT(RCC->APBRST2.WORDVAL, RCC_APB_ADCARST_M);
}

/**
 * \brief  Release the reset of the ADCA module.
 * \note   This function releases the reset of the ADCA module by clearing the ADCARST bit in the
 *         RCC APB Reset Register 2 (RCC->APBRST2).
 *         Clearing this bit allows the ADCA module to resume normal operation after a reset.
 */
static inline void RCC_releaseAdcaModule (void)
{
    CLEAR_BIT(RCC->APBRST2.WORDVAL, RCC_APB_ADCARST_M);
}

/**
 * \brief  Reset the Analogss module.
 * \note   This function resets the Analogss module by setting the CMPSS7RST bit in the
 *         RCC APB Reset Register 3 (RCC->APBRST3).
 *         Setting this bit allows for a reset of the Analogss module.
 */
static inline void RCC_resetAnalogssModule (void)
{
    SET_BIT(RCC->APBRST3.WORDVAL, RCC_APB_ANALOGSSRST_M);
}

/**
 * \brief  Release the reset of the Analogss module.
 * \note   This function releases the reset of the Analogss module by clearing the CMPSS7RST bit in the
 *         RCC APB Reset Register 3 (RCC->APBRST3).
 *         Clearing this bit allows the Analogss module to resume normal operation after a reset.
 */
static inline void RCC_releaseAnalogssModule (void)
{
    CLEAR_BIT(RCC->APBRST3.WORDVAL, RCC_APB_ANALOGSSRST_M);
}

/**
 * \brief  Reset the DCC1 module.
 * \note   This function resets the DCC1 module by setting the DCC1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Setting this bit allows for a reset of the DCC1 module.
 */
static inline void RCC_resetDcc1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APB_DCC1RST_M);
}

/**
 * \brief  Release the reset of the DCC1 module.
 * \note   This function releases the reset of the DCC1 module by clearing the DCC1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Clearing this bit allows the DCC1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseDcc1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APB_DCC1RST_M);
}

/**
 * \brief  Reset the EPG module.
 * \note   This function resets the EPG module by setting the EPGRST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Setting this bit allows for a reset of the EPG module.
 */
static inline void RCC_resetEpgModule (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APB_EPGRST_M);
}

/**
 * \brief  Release the reset of the EPG module.
 * \note   This function releases the reset of the EPG module by clearing the EPGRST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Clearing this bit allows the EPG module to resume normal operation after a reset.
 */
static inline void RCC_releaseEpgModule (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APB_EPGRST_M);
}

/**
 * \brief  Reset the I2C1 module.
 * \note   This function resets the I2C1 module by setting the I2C1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Setting this bit allows for a reset of the I2C1 module.
 */
static inline void RCC_resetI2c1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APB_I2C1RST_M);
}

/**
 * \brief  Release the reset of the I2C1 module.
 * \note   This function releases the reset of the I2C1 module by clearing the I2C1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Clearing this bit allows the I2C1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseI2c1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APB_I2C1RST_M);
}

/**
 * \brief  Reset the SPI2 module.
 * \note   This function resets the SPI2 module by setting the SPI2RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Setting this bit allows for a reset of the SPI2 module.
 */
static inline void RCC_resetSpi2Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APB_SPI2RST_M);
}

/**
 * \brief  Release the reset of the SPI2 module.
 * \note   This function releases the reset of the SPI2 module by clearing the SPI2RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Clearing this bit allows the SPI2 module to resume normal operation after a reset.
 */
static inline void RCC_releaseSpi2Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APB_SPI2RST_M);
}

/**
 * \brief  Reset the SPI1 module.
 * \note   This function resets the SPI1 module by setting the SPI1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Setting this bit allows for a reset of the SPI1 module.
 */
static inline void RCC_resetSpi1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APB_SPI1RST_M);
}

/**
 * \brief  Release the reset of the SPI1 module.
 * \note   This function releases the reset of the SPI1 module by clearing the SPI1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Clearing this bit allows the SPI1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseSpi1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APB_SPI1RST_M);
}

/**
 * \brief  Reset the UART1 module.
 * \note   This function resets the UART1 module by setting the UART1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Setting this bit allows for a reset of the UART1 module.
 */
static inline void RCC_resetUart1Module (void)
{
    SET_BIT(RCC->APBRST5.WORDVAL, RCC_APB_UART1RST_M);
}

/**
 * \brief  Release the reset of the UART1 module.
 * \note   This function releases the reset of the UART1 module by clearing the UART1RST bit in the
 *         RCC APB Reset Register 5 (RCC->APBRST5).
 *         Clearing this bit allows the UART1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseUart1Module (void)
{
    CLEAR_BIT(RCC->APBRST5.WORDVAL, RCC_APB_UART1RST_M);
}

/**
 * \brief  Reset the STIM3 module.
 * \note   This function resets the STIM3 module by setting the STIM3RST bit in the
 *         RCC APB Reset Register 6 (RCC->APBRST6).
 *         Setting this bit allows for a reset of the STIM3 module.
 */
static inline void RCC_resetStim3Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APB_STIM3RST_M);
}

/**
 * \brief  Release the reset of the STIM3 module.
 * \note   This function releases the reset of the STIM3 module by clearing the STIM3RST bit in the
 *         RCC APB Reset Register 6 (RCC->APBRST6).
 *         Clearing this bit allows the STIM3 module to resume normal operation after a reset.
 */
static inline void RCC_releaseStim3Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APB_STIM3RST_M);
}

/**
 * \brief  Reset the STIM2 module.
 * \note   This function resets the STIM2 module by setting the STIM2RST bit in the
 *         RCC APB Reset Register 6 (RCC->APBRST6).
 *         Setting this bit allows for a reset of the STIM2 module.
 */
static inline void RCC_resetStim2Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APB_STIM2RST_M);
}

/**
 * \brief  Release the reset of the STIM2 module.
 * \note   This function releases the reset of the STIM2 module by clearing the STIM2RST bit in the
 *         RCC APB Reset Register 6 (RCC->APBRST6).
 *         Clearing this bit allows the STIM2 module to resume normal operation after a reset.
 */
static inline void RCC_releaseStim2Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APB_STIM2RST_M);
}

/**
 * \brief  Reset the STIM1 module.
 * \note   This function resets the STIM1 module by setting the STIM1RST bit in the
 *         RCC APB Reset Register 6 (RCC->APBRST6).
 *         Setting this bit allows for a reset of the STIM1 module.
 */
static inline void RCC_resetStim1Module (void)
{
    SET_BIT(RCC->APBRST6.WORDVAL, RCC_APB_STIM1RST_M);
}

/**
 * \brief  Release the reset of the STIM1 module.
 * \note   This function releases the reset of the STIM1 module by clearing the STIM1RST bit in the
 *         RCC APB Reset Register 6 (RCC->APBRST6).
 *         Clearing this bit allows the STIM1 module to resume normal operation after a reset.
 */
static inline void RCC_releaseStim1Module (void)
{
    CLEAR_BIT(RCC->APBRST6.WORDVAL, RCC_APB_STIM1RST_M);
}

/**
 * \brief  Reset the LPTIM module.
 * \note   This function resets the LPTIM module by setting the LPTIMRST bit in the
 *         RCC APB Reset Register 8 (RCC->APBRST8).
 *         Setting this bit allows for a reset of the LPTIM module.
 */
static inline void RCC_resetLptimModule (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APB_LPTIMRST_M);
}

/**
 * \brief  Release the reset of the LPTIM module.
 * \note   This function releases the reset of the LPTIM module by clearing the LPTIMRST bit in the
 *         RCC APB Reset Register 8 (RCC->APBRST8).
 *         Clearing this bit allows the LPTIM module to resume normal operation after a reset.
 */
static inline void RCC_releaseLptimModule (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APB_LPTIMRST_M);
}

/**
 * \brief  Reset the PWR module.
 * \note   This function resets the PWR module by setting the PWRRST bit in the
 *         RCC APB Reset Register 8 (RCC->APBRST8).
 *         Setting this bit allows for a reset of the PWR module.
 */
static inline void RCC_resetPwrModule (void)
{
    SET_BIT(RCC->APBRST8.WORDVAL, RCC_APB_PWRRST_M);
}

/**
 * \brief  Release the reset of the PWR module.
 * \note   This function releases the reset of the PWR module by clearing the PWRRST bit in the
 *         RCC APB Reset Register 8 (RCC->APBRST8).
 *         Clearing this bit allows the PWR module to resume normal operation after a reset.
 */
static inline void RCC_releasePwrModule (void)
{
    CLEAR_BIT(RCC->APBRST8.WORDVAL, RCC_APB_PWRRST_M);
}

/**
 * \brief  Enable the GPIOH clock.
 * \note   This function enables the clock for the GPIOH module by setting the GPIOHEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Setting this bit allows the GPIOH module to operate.
 */
static inline void RCC_enableGpiohClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOHEN_M);
}

/**
 * \brief  Disable the GPIOH clock.
 * \note   This function disables the clock for the GPIOH module by clearing the GPIOHEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Clearing this bit stops the GPIOH module from operating.
 */
static inline void RCC_disableGpiohClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOHEN_M);
}

/**
 * \brief  Enable the GPIOC clock.
 * \note   This function enables the clock for the GPIOC module by setting the GPIOCEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Setting this bit allows the GPIOC module to operate.
 */
static inline void RCC_enableGpiocClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOCEN_M);
}

/**
 * \brief  Disable the GPIOC clock.
 * \note   This function disables the clock for the GPIOC module by clearing the GPIOCEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Clearing this bit stops the GPIOC module from operating.
 */
static inline void RCC_disableGpiocClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOCEN_M);
}

/**
 * \brief  Enable the GPIOB clock.
 * \note   This function enables the clock for the GPIOB module by setting the GPIOBEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Setting this bit allows the GPIOB module to operate.
 */
static inline void RCC_enableGpiobClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOBEN_M);
}

/**
 * \brief  Disable the GPIOB clock.
 * \note   This function disables the clock for the GPIOB module by clearing the GPIOBEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Clearing this bit stops the GPIOB module from operating.
 */
static inline void RCC_disableGpiobClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOBEN_M);
}

/**
 * \brief  Enable the GPIOA clock.
 * \note   This function enables the clock for the GPIOA module by setting the GPIOAEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Setting this bit allows the GPIOA module to operate.
 */
static inline void RCC_enableGpioaClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOAEN_M);
}

/**
 * \brief  Disable the GPIOA clock.
 * \note   This function disables the clock for the GPIOA module by clearing the GPIOAEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Clearing this bit stops the GPIOA module from operating.
 */
static inline void RCC_disableGpioaClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_GPIOAEN_M);
}

/**
 * \brief  Enable the MMATH clock.
 * \note   This function enables the clock for the MMATH module by setting the MMATHEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Setting this bit allows the MMATH module to operate.
 */
static inline void RCC_enableMmathClock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_MMATHEN_M);
}

/**
 * \brief  Disable the MMATH clock.
 * \note   This function disables the clock for the MMATH module by clearing the MMATHEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Clearing this bit stops the MMATH module from operating.
 */
static inline void RCC_disableMmathClock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_MMATHEN_M);
}

/**
 * \brief  Enable the EDMA1 clock.
 * \note   This function enables the clock for the EDMA1 module by setting the EDMA1EN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Setting this bit allows the EDMA1 module to operate.
 */
static inline void RCC_enableEDma1Clock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_EDMA1EN_M);
}

/**
 * \brief  Disable the EDMA1 clock.
 * \note   This function disables the clock for the EDMA1 module by clearing the EDMA1EN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Clearing this bit stops the EDMA1 module from operating.
 */
static inline void RCC_disableEDma1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_EDMA1EN_M);
}

/**
 * \brief  Enable the DMAMUX1 clock.
 * \note   This function enables the clock for the DMAMUX1 module by setting the DMAMUX1EN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Setting this bit allows the DMAMUX1 module to operate.
 */
static inline void RCC_enableDmamux1Clock (void)
{
    SET_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_DMAMUX1EN_M);
}

/**
 * \brief  Disable the DMAMUX1 clock.
 * \note   This function disables the clock for the DMAMUX1 module by clearing the DMAMUX1EN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKEN1).
 *         Clearing this bit stops the DMAMUX1 module from operating.
 */
static inline void RCC_disableDmamux1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN1.WORDVAL, RCC_AHB_DMAMUX1EN_M);
}

/**
 * \brief  Enable the CAN1 clock.
 * \note   This function enables the clock for the CAN1 module by setting the CAN1EN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
 *         Setting this bit allows the CAN1 module to operate.
 */
static inline void RCC_enableCan1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_AHB_CAN1EN_M);
}

/**
 * \brief  Disable the CAN1 clock.
 * \note   This function disables the clock for the CAN1 module by clearing the CAN1EN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
 *         Clearing this bit stops the CAN1 module from operating.
 */
static inline void RCC_disableCan1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_AHB_CAN1EN_M);
}

/**
 * \brief  Enable the LIN1 clock.
 * \note   This function enables the clock for the LIN1 module by setting the LIN1EN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
 *         Setting this bit allows the LIN1 module to operate.
 */
static inline void RCC_enableLin1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_AHB_LIN1EN_M);
}

/**
 * \brief  Disable the LIN1 clock.
 * \note   This function disables the clock for the LIN1 module by clearing the LIN1EN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
 *         Clearing this bit stops the LIN1 module from operating.
 */
static inline void RCC_disableLin1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_AHB_LIN1EN_M);
}

/**
 * \brief  Enable the BGCRC1 clock.
 * \note   This function enables the clock for the BGCRC1 module by setting the BGCRC1EN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
 *         Setting this bit allows the BGCRC1 module to operate.
 */
static inline void RCC_enableBgcrc1Clock (void)
{
    SET_BIT(RCC->HCLKEN2.WORDVAL, RCC_AHB_BGCRC1EN_M);
}

/**
 * \brief  Disable the BGCRC1 clock.
 * \note   This function disables the clock for the BGCRC1 module by clearing the BGCRC1EN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKEN2).
 *         Clearing this bit stops the BGCRC1 module from operating.
 */
static inline void RCC_disableBgcrc1Clock (void)
{
    CLEAR_BIT(RCC->HCLKEN2.WORDVAL, RCC_AHB_BGCRC1EN_M);
}

/**
 * \brief  Enable the EQEP2 clock.
 * \note   This function enables the clock for the EQEP2 module by setting the EQEP2EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EQEP2 module to operate.
 */
static inline void RCC_enableEqep2Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EQEP2EN_M);
}

/**
 * \brief  Disable the EQEP2 clock.
 * \note   This function disables the clock for the EQEP2 module by clearing the EQEP2EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EQEP2 module from operating.
 */
static inline void RCC_disableEqep2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EQEP2EN_M);
}

/**
 * \brief  Enable the EQEP1 clock.
 * \note   This function enables the clock for the EQEP1 module by setting the EQEP1EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EQEP1 module to operate.
 */
static inline void RCC_enableEqep1Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EQEP1EN_M);
}

/**
 * \brief  Disable the EQEP1 clock.
 * \note   This function disables the clock for the EQEP1 module by clearing the EQEP1EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EQEP1 module from operating.
 */
static inline void RCC_disableEqep1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EQEP1EN_M);
}

/**
 * \brief  Enable the ECAP3 clock.
 * \note   This function enables the clock for the ECAP3 module by setting the ECAP3EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the ECAP3 module to operate.
 */
static inline void RCC_enableEcap3Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_ECAP3EN_M);
}

/**
 * \brief  Disable the ECAP3 clock.
 * \note   This function disables the clock for the ECAP3 module by clearing the ECAP3EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the ECAP3 module from operating.
 */
static inline void RCC_disableEcap3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_ECAP3EN_M);
}

/**
 * \brief  Enable the ECAP2 clock.
 * \note   This function enables the clock for the ECAP2 module by setting the ECAP2EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the ECAP2 module to operate.
 */
static inline void RCC_enableEcap2Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_ECAP2EN_M);
}

/**
 * \brief  Disable the ECAP2 clock.
 * \note   This function disables the clock for the ECAP2 module by clearing the ECAP2EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the ECAP2 module from operating.
 */
static inline void RCC_disableEcap2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_ECAP2EN_M);
}

/**
 * \brief  Enable the ECAP1 clock.
 * \note   This function enables the clock for the ECAP1 module by setting the ECAP1EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the ECAP1 module to operate.
 */
static inline void RCC_enableEcap1Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_ECAP1EN_M);
}

/**
 * \brief  Disable the ECAP1 clock.
 * \note   This function disables the clock for the ECAP1 module by clearing the ECAP1EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the ECAP1 module from operating.
 */
static inline void RCC_disableEcap1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_ECAP1EN_M);
}

/**
 * \brief  Enable the EPWM7 clock.
 * \note   This function enables the clock for the EPWM7 module by setting the EPWM7EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EPWM7 module to operate.
 */
static inline void RCC_enableEpwm7Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM7EN_M);
}

/**
 * \brief  Disable the EPWM7 clock.
 * \note   This function disables the clock for the EPWM7 module by clearing the EPWM7EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EPWM7 module from operating.
 */
static inline void RCC_disableEpwm7Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM7EN_M);
}

/**
 * \brief  Enable the EPWM6 clock.
 * \note   This function enables the clock for the EPWM6 module by setting the EPWM6EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EPWM6 module to operate.
 */
static inline void RCC_enableEpwm6Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM6EN_M);
}

/**
 * \brief  Disable the EPWM6 clock.
 * \note   This function disables the clock for the EPWM6 module by clearing the EPWM6EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EPWM6 module from operating.
 */
static inline void RCC_disableEpwm6Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM6EN_M);
}

/**
 * \brief  Enable the EPWM5 clock.
 * \note   This function enables the clock for the EPWM5 module by setting the EPWM5EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EPWM5 module to operate.
 */
static inline void RCC_enableEpwm5Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM5EN_M);
}

/**
 * \brief  Disable the EPWM5 clock.
 * \note   This function disables the clock for the EPWM5 module by clearing the EPWM5EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EPWM5 module from operating.
 */
static inline void RCC_disableEpwm5Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM5EN_M);
}

/**
 * \brief  Enable the EPWM4 clock.
 * \note   This function enables the clock for the EPWM4 module by setting the EPWM4EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EPWM4 module to operate.
 */
static inline void RCC_enableEpwm4Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM4EN_M);
}

/**
 * \brief  Disable the EPWM4 clock.
 * \note   This function disables the clock for the EPWM4 module by clearing the EPWM4EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EPWM4 module from operating.
 */
static inline void RCC_disableEpwm4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM4EN_M);
}

/**
 * \brief  Enable the EPWM3 clock.
 * \note   This function enables the clock for the EPWM3 module by setting the EPWM3EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EPWM3 module to operate.
 */
static inline void RCC_enableEpwm3Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM3EN_M);
}

/**
 * \brief  Disable the EPWM3 clock.
 * \note   This function disables the clock for the EPWM3 module by clearing the EPWM3EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EPWM3 module from operating.
 */
static inline void RCC_disableEpwm3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM3EN_M);
}

/**
 * \brief  Enable the EPWM2 clock.
 * \note   This function enables the clock for the EPWM2 module by setting the EPWM2EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EPWM2 module to operate.
 */
static inline void RCC_enableEpwm2Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM2EN_M);
}

/**
 * \brief  Disable the EPWM2 clock.
 * \note   This function disables the clock for the EPWM2 module by clearing the EPWM2EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EPWM2 module from operating.
 */
static inline void RCC_disableEpwm2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM2EN_M);
}

/**
 * \brief  Enable the EPWM1 clock.
 * \note   This function enables the clock for the EPWM1 module by setting the EPWM1EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Setting this bit allows the EPWM1 module to operate.
 */
static inline void RCC_enableEpwm1Clock (void)
{
    SET_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM1EN_M);
}

/**
 * \brief  Disable the EPWM1 clock.
 * \note   This function disables the clock for the EPWM1 module by clearing the EPWM1EN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKEN1).
 *         Clearing this bit stops the EPWM1 module from operating.
 */
static inline void RCC_disableEpwm1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN1.WORDVAL, RCC_APB_EPWM1EN_M);
}

/**
 * \brief  Enable the CMPSS4 clock.
 * \note   This function enables the clock for the CMPSS4 module by setting the CMPSS4EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Setting this bit allows the CMPSS4 module to operate.
 */
static inline void RCC_enableCmpss4Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS4EN_M);
}

/**
 * \brief  Disable the CMPSS4 clock.
 * \note   This function disables the clock for the CMPSS4 module by clearing the CMPSS4EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Clearing this bit stops the CMPSS4 module from operating.
 */
static inline void RCC_disableCmpss4Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS4EN_M);
}

/**
 * \brief  Enable the CMPSS3 clock.
 * \note   This function enables the clock for the CMPSS3 module by setting the CMPSS3EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Setting this bit allows the CMPSS3 module to operate.
 */
static inline void RCC_enableCmpss3Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS3EN_M);
}

/**
 * \brief  Disable the CMPSS3 clock.
 * \note   This function disables the clock for the CMPSS3 module by clearing the CMPSS3EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Clearing this bit stops the CMPSS3 module from operating.
 */
static inline void RCC_disableCmpss3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS3EN_M);
}

/**
 * \brief  Enable the CMPSS2 clock.
 * \note   This function enables the clock for the CMPSS2 module by setting the CMPSS2EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Setting this bit allows the CMPSS2 module to operate.
 */
static inline void RCC_enableCmpss2Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS2EN_M);
}

/**
 * \brief  Disable the CMPSS2 clock.
 * \note   This function disables the clock for the CMPSS2 module by clearing the CMPSS2EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Clearing this bit stops the CMPSS2 module from operating.
 */
static inline void RCC_disableCmpss2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS2EN_M);
}

/**
 * \brief  Enable the CMPSS1 clock.
 * \note   This function enables the clock for the CMPSS1 module by setting the CMPSS1EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Setting this bit allows the CMPSS1 module to operate.
 */
static inline void RCC_enableCmpss1Clock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS1EN_M);
}

/**
 * \brief  Disable the CMPSS1 clock.
 * \note   This function disables the clock for the CMPSS1 module by clearing the CMPSS1EN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Clearing this bit stops the CMPSS1 module from operating.
 */
static inline void RCC_disableCmpss1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_CMPSS1EN_M);
}

/**
 * \brief  Enable the XBAR clock.
 * \note   This function enables the clock for the XBAR module by setting the XBAREN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Setting this bit allows the XBAR module to operate.
 */
static inline void RCC_enableXbarClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_XBAREN_M);
}

/**
 * \brief  Disable the XBAR clock.
 * \note   This function disables the clock for the XBAR module by clearing the XBAREN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Clearing this bit stops the XBAR module from operating.
 */
static inline void RCC_disableXbarClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_XBAREN_M);
}

/**
 * \brief  Enable the ADCC clock.
 * \note   This function enables the clock for the ADCC module by setting the ADCCEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Setting this bit allows the ADCC module to operate.
 */
static inline void RCC_enableAdccClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_ADCCEN_M);
}

/**
 * \brief  Disable the ADCC clock.
 * \note   This function disables the clock for the ADCC module by clearing the ADCCEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Clearing this bit stops the ADCC module from operating.
 */
static inline void RCC_disableAdccClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_ADCCEN_M);
}

/**
 * \brief  Enable the ADCA clock.
 * \note   This function enables the clock for the ADCA module by setting the ADCAEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Setting this bit allows the ADCA module to operate.
 */
static inline void RCC_enableAdcaClock (void)
{
    SET_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_ADCAEN_M);
}

/**
 * \brief  Disable the ADCA clock.
 * \note   This function disables the clock for the ADCA module by clearing the ADCAEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKEN2).
 *         Clearing this bit stops the ADCA module from operating.
 */
static inline void RCC_disableAdcaClock (void)
{
    CLEAR_BIT(RCC->PCLKEN2.WORDVAL, RCC_APB_ADCAEN_M);
}

/**
 * \brief  Enable the AnalogSS clock.
 * \note   This function enables the clock for the AnalogSS module by setting the ANALOGSSEN bit in the
 *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
 *         Setting this bit allows the AnalogSS module to operate.
 */
static inline void RCC_enableAnalogssClock (void)
{
    SET_BIT(RCC->PCLKEN3.WORDVAL, RCC_APB_ANALOGSSEN_M);
}

/**
 * \brief  Disable the AnalogSS clock.
 * \note   This function disables the clock for the AnalogSS module by clearing the ANALOGSSEN bit in the
 *         RCC APB Clock Enable Register 3 (RCC->PCLKEN3).
 *         Clearing this bit stops the AnalogSS module from operating.
 */
static inline void RCC_disableAnalogssClock (void)
{
    CLEAR_BIT(RCC->PCLKEN3.WORDVAL, RCC_APB_ANALOGSSEN_M);
}

/**
 * \brief  Enable the DCC1 clock.
 * \note   This function enables the clock for the DCC1 module by setting the DCC1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Setting this bit allows the DCC1 module to operate.
 */
static inline void RCC_enableDcc1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_DCC1EN_M);
}

/**
 * \brief  Disable the DCC1 clock.
 * \note   This function disables the clock for the DCC1 module by clearing the DCC1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Clearing this bit stops the DCC1 module from operating.
 */
static inline void RCC_disableClkTrimClock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_DCC1EN_M);
}

/**
 * \brief  Enable the WWDGclock.
 * \note   This function enables the clock for the WWDGmodule by setting the WWDGEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Setting this bit allows the WWDGmodule to operate.
 */
static inline void RCC_enableWWDGClock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_WWDGEN_M);
}

/**
 * \brief  Disable the WWDGclock.
 * \note   This function disables the clock for the WWDGmodule by clearing the WWDGEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Clearing this bit stops the WWDGmodule from operating.
 */
static inline void RCC_disableWWDGClock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_WWDGEN_M);
}

/**
 * \brief  Enable the EPG clock.
 * \note   This function enables the clock for the EPG module by setting the EPGEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Setting this bit allows the EPG module to operate.
 */
static inline void RCC_enableEpgClock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_EPGEN_M);
}

/**
 * \brief  Disable the EPG clock.
 * \note   This function disables the clock for the EPG module by clearing the EPGEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Clearing this bit stops the EPG module from operating.
 */
static inline void RCC_disableEpgClock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_EPGEN_M);
}

/**
 * \brief  Enable the I2C1 clock.
 * \note   This function enables the clock for the I2C1 module by setting the I2C1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Setting this bit allows the I2C1 module to operate.
 */
static inline void RCC_enableI2c1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_I2C1EN_M);
}

/**
 * \brief  Disable the I2C1 clock.
 * \note   This function disables the clock for the I2C1 module by clearing the I2C1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Clearing this bit stops the I2C1 module from operating.
 */
static inline void RCC_disableI2c1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_I2C1EN_M);
}

/**
 * \brief  Enable the SPI2 clock.
 * \note   This function enables the clock for the SPI2 module by setting the SPI2EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Setting this bit allows the SPI2 module to operate.
 */
static inline void RCC_enableSpi2Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_SPI2EN_M);
}

/**
 * \brief  Disable the SPI2 clock.
 * \note   This function disables the clock for the SPI2 module by clearing the SPI2EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Clearing this bit stops the SPI2 module from operating.
 */
static inline void RCC_disableSpi2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_SPI2EN_M);
}

/**
 * \brief  Enable the SPI1 clock.
 * \note   This function enables the clock for the SPI1 module by setting the SPI1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Setting this bit allows the SPI1 module to operate.
 */
static inline void RCC_enableSpi1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_SPI1EN_M);
}

/**
 * \brief  Disable the SPI1 clock.
 * \note   This function disables the clock for the SPI1 module by clearing the SPI1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Clearing this bit stops the SPI1 module from operating.
 */
static inline void RCC_disableSpi1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_SPI1EN_M);
}

/**
 * \brief  Enable the UART1 clock.
 * \note   This function enables the clock for the UART1 module by setting the UART1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Setting this bit allows the UART1 module to operate.
 */
static inline void RCC_enableUart1Clock (void)
{
    SET_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_UART1EN_M);
}

/**
 * \brief  Disable the UART1 clock.
 * \note   This function disables the clock for the UART1 module by clearing the UART1EN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKEN5).
 *         Clearing this bit stops the UART1 module from operating.
 */
static inline void RCC_disableUart1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN5.WORDVAL, RCC_APB_UART1EN_M);
}

/**
 * \brief  Enable the STIM3 clock.
 * \note   This function enables the clock for the STIM3 module by setting the STIM3EN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
 *         Setting this bit allows the STIM3 module to operate.
 */
static inline void RCC_enableStim3Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_APB_STIM3EN_M);
}

/**
 * \brief  Disable the STIM3 clock.
 * \note   This function disables the clock for the STIM3 module by clearing the STIM3EN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
 *         Clearing this bit stops the STIM3 module from operating.
 */
static inline void RCC_disableStim3Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_APB_STIM3EN_M);
}

/**
 * \brief  Enable the STIM2 clock.
 * \note   This function enables the clock for the STIM2 module by setting the STIM2EN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
 *         Setting this bit allows the STIM2 module to operate.
 */
static inline void RCC_enableStim2Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_APB_STIM2EN_M);
}

/**
 * \brief  Disable the STIM2 clock.
 * \note   This function disables the clock for the STIM2 module by clearing the STIM2EN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
 *         Clearing this bit stops the STIM2 module from operating.
 */
static inline void RCC_disableStim2Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_APB_STIM2EN_M);
}

/**
 * \brief  Enable the STIM1 clock.
 * \note   This function enables the clock for the STIM1 module by setting the STIM1EN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
 *         Setting this bit allows the STIM1 module to operate.
 */
static inline void RCC_enableStim1Clock (void)
{
    SET_BIT(RCC->PCLKEN6.WORDVAL, RCC_APB_STIM1EN_M);
}

/**
 * \brief  Disable the STIM1 clock.
 * \note   This function disables the clock for the STIM1 module by clearing the STIM1EN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKEN6).
 *         Clearing this bit stops the STIM1 module from operating.
 */
static inline void RCC_disableStim1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN6.WORDVAL, RCC_APB_STIM1EN_M);
}

/**
 * \brief  Enable the AWK clock.
 * \note   This function enables the clock for the AWK module by setting the AWKEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Setting this bit allows the AWK module to operate.
 */
static inline void RCC_enableAwkClock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_AWKEN_M);
}

/**
 * \brief  Disable the AWK clock.
 * \note   This function disables the clock for the AWK module by clearing the AWKEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Clearing this bit stops the AWK module from operating.
 */
static inline void RCC_disableAwkClock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_AWKEN_M);
}

/**
 * \brief  Enable the LPTIM clock.
 * \note   This function enables the clock for the LPTIM module by setting the LPTIMEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Setting this bit allows the LPTIM module to operate.
 */
static inline void RCC_enableLptimClock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_LPTIMEN_M);
}

/**
 * \brief  Disable the LPTIM clock.
 * \note   This function disables the clock for the LPTIM module by clearing the LPTIMEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Clearing this bit stops the LPTIM module from operating.
 */
static inline void RCC_disableLptimClock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_LPTIMEN_M);
}

/**
 * \brief  Enable the IWDG1 clock.
 * \note   This function enables the clock for the IWDG1 module by setting the IWDG1EN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Setting this bit allows the IWDG1 module to operate.
 */
static inline void RCC_enableIwdg1Clock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_IWDG1EN_M);
}

/**
 * \brief  Disable the IWDG1 clock.
 * \note   This function disables the clock for the IWDG1 module by clearing the IWDG1EN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Clearing this bit stops the IWDG1 module from operating.
 */
static inline void RCC_disableIwdg1Clock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_IWDG1EN_M);
}

/**
 * \brief  Enable the PWR clock.
 * \note   This function enables the clock for the PWR module by setting the PWREN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Setting this bit allows the PWR module to operate.
 */
static inline void RCC_enablePwrClock (void)
{
    SET_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_PWREN_M);
}

/**
 * \brief  Disable the PWR clock.
 * \note   This function disables the clock for the PWR module by clearing the PWREN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKEN8).
 *         Clearing this bit stops the PWR module from operating.
 */
static inline void RCC_disablePwrClock (void)
{
    CLEAR_BIT(RCC->PCLKEN8.WORDVAL, RCC_APB_PWREN_M);
}

/**
 * \brief  Enable the GPIOH clock in sleep mode.
 * \note   This function enables the clock for the GPIOH module by setting the GPIOHLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Setting this bit allows the GPIOH module to operate in sleep mode.
 */
static inline void RCC_enableGpiohClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOHLPEN_M);
}

/**
 * \brief  Disable the GPIOH clock in sleep mode.
 * \note   This function disables the clock for the GPIOH module by clearing the GPIOHLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Clearing this bit stops the GPIOH module from operating in sleep mode.
 */
static inline void RCC_disableGpiohClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOHLPEN_M);
}

/**
 * \brief  Enable the GPIOC clock in sleep mode.
 * \note   This function enables the clock for the GPIOC module by setting the GPIOCLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Setting this bit allows the GPIOC module to operate in sleep mode.
 */
static inline void RCC_enableGpiocClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOCLPEN_M);
}

/**
 * \brief  Disable the GPIOC clock in sleep mode.
 * \note   This function disables the clock for the GPIOC module by clearing the GPIOCLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Clearing this bit stops the GPIOC module from operating in sleep mode.
 */
static inline void RCC_disableGpiocClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOCLPEN_M);
}

/**
 * \brief  Enable the GPIOB clock in sleep mode.
 * \note   This function enables the clock for the GPIOB module by setting the GPIOBLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Setting this bit allows the GPIOB module to operate in sleep mode.
 */
static inline void RCC_enableGpiobClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOBLPEN_M);
}

/**
 * \brief  Disable the GPIOB clock in sleep mode.
 * \note   This function disables the clock for the GPIOB module by clearing the GPIOBLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Clearing this bit stops the GPIOB module from operating in sleep mode.
 */
static inline void RCC_disableGpiobClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOBLPEN_M);
}

/**
 * \brief  Enable the GPIOA clock in sleep mode.
 * \note   This function enables the clock for the GPIOA module by setting the GPIOALPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Setting this bit allows the GPIOA module to operate in sleep mode.
 */
static inline void RCC_enableGpioaClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOALPEN_M);
}

/**
 * \brief  Disable the GPIOA clock in sleep mode.
 * \note   This function disables the clock for the GPIOA module by clearing the GPIOALPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Clearing this bit stops the GPIOA module from operating in sleep mode.
 */
static inline void RCC_disableGpioaClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_GPIOALPEN_M);
}

/**
 * \brief  Enable the MMATH clock in sleep mode.
 * \note   This function enables the clock for the MMATH module by setting the MMATHLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Setting this bit allows the MMATH module to operate in sleep mode.
 */
static inline void RCC_enableMmathClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_MMATHLPEN_M);
}

/**
 * \brief  Disable the MMATH clock in sleep mode.
 * \note   This function disables the clock for the MMATH module by clearing the MMATHLPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Clearing this bit stops the MMATH module from operating in sleep mode.
 */
static inline void RCC_disableMmathClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_MMATHLPEN_M);
}

/**
 * \brief  Enable the EDMA1 clock in sleep mode.
 * \note   This function enables the clock for the EDMA1 module by setting the EDMA1LPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Setting this bit allows the EDMA1 module to operate in sleep mode.
 */
static inline void RCC_enableEDma1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_EDMA1LPEN_M);
}

/**
 * \brief  Disable the EDMA1 clock in sleep mode.
 * \note   This function disables the clock for the EDMA1 module by clearing the EDMA1LPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Clearing this bit stops the EDMA1 module from operating in sleep mode.
 */
static inline void RCC_disableEDma1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_EDMA1LPEN_M);
}

/**
 * \brief  Enable the DMAMUX1 clock in sleep mode.
 * \note   This function enables the clock for the DMAMUX1 module by setting the DMAMUX1LPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Setting this bit allows the DMAMUX1 module to operate in sleep mode.
 */
static inline void RCC_enableDmamux1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_DMAMUX1LPEN_M);
}

/**
 * \brief  Disable the DMAMUX1 clock in sleep mode.
 * \note   This function disables the clock for the DMAMUX1 module by clearing the DMAMUX1LPEN bit in the
 *         RCC AHB Clock Enable Register 1 (RCC->HCLKLPEN1).
 *         Clearing this bit stops the DMAMUX1 module from operating in sleep mode.
 */
static inline void RCC_disableDmamux1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN1.WORDVAL, RCC_AHB_DMAMUX1LPEN_M);
}

/**
 * \brief  Enable the CAN1 clock in sleep mode.
 * \note   This function enables the clock for the CAN1 module by setting the CAN1LPEN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
 *         Setting this bit allows the CAN1 module to operate in sleep mode.
 */
static inline void RCC_enableCan1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_AHB_CAN1LPEN_M);
}

/**
 * \brief  Disable the CAN1 clock in sleep mode.
 * \note   This function disables the clock for the CAN1 module by clearing the CAN1LPEN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
 *         Clearing this bit stops the CAN1 module from operating in sleep mode.
 */
static inline void RCC_disableCan1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_AHB_CAN1LPEN_M);
}

/**
 * \brief  Enable the LIN1 clock in sleep mode.
 * \note   This function enables the clock for the LIN1 module by setting the LIN1LPEN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
 *         Setting this bit allows the LIN1 module to operate in sleep mode.
 */
static inline void RCC_enableLin1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_AHB_LIN1LPEN_M);
}

/**
 * \brief  Disable the LIN1 clock in sleep mode.
 * \note   This function disables the clock for the LIN1 module by clearing the LIN1LPEN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
 *         Clearing this bit stops the LIN1 module from operating in sleep mode.
 */
static inline void RCC_disableLin1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_AHB_LIN1LPEN_M);
}

/**
 * \brief  Enable the BGCRC1 clock in sleep mode.
 * \note   This function enables the clock for the BGCRC1 module by setting the BGCRC1LPEN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
 *         Setting this bit allows the BGCRC1 module to operate in sleep mode.
 */
static inline void RCC_enableBcrc1ClockInSleepMode (void)
{
    SET_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_AHB_BGCRC1LPEN_M);
}

/**
 * \brief  Disable the BGCRC1 clock in sleep mode.
 * \note   This function disables the clock for the BGCRC1 module by clearing the BGCRC1LPEN bit in the
 *         RCC AHB Clock Enable Register 2 (RCC->HCLKLPEN2).
 *         Clearing this bit stops the BGCRC1 module from operating in sleep mode.
 */
static inline void RCC_disableBcrc1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->HCLKLPEN2.WORDVAL, RCC_AHB_BGCRC1LPEN_M);
}

/**
 * \brief  Enable the EQEP2 clock in sleep mode.
 * \note   This function enables the clock for the EQEP2 module by setting the EQEP2LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EQEP2 module to operate in sleep mode.
 */
static inline void RCC_enableEqep2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EQEP2LPEN_M);
}

/**
 * \brief  Disable the EQEP2 clock in sleep mode.
 * \note   This function disables the clock for the EQEP2 module by clearing the EQEP2LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EQEP2 module from operating in sleep mode.
 */
static inline void RCC_disableEqep2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EQEP2LPEN_M);
}

/**
 * \brief  Enable the EQEP1 clock in sleep mode.
 * \note   This function enables the clock for the EQEP1 module by setting the EQEP1LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EQEP1 module to operate in sleep mode.
 */
static inline void RCC_enableEqep1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EQEP1LPEN_M);
}

/**
 * \brief  Disable the EQEP1 clock in sleep mode.
 * \note   This function disables the clock for the EQEP1 module by clearing the EQEP1LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EQEP1 module from operating in sleep mode.
 */
static inline void RCC_disableEqep1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EQEP1LPEN_M);
}

/**
 * \brief  Enable the ECAP3 clock in sleep mode.
 * \note   This function enables the clock for the ECAP3 module by setting the ECAP3LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the ECAP3 module to operate in sleep mode.
 */
static inline void RCC_enableEcap3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_ECAP3LPEN_M);
}

/**
 * \brief  Disable the ECAP3 clock in sleep mode.
 * \note   This function disables the clock for the ECAP3 module by clearing the ECAP3LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the ECAP3 module from operating in sleep mode.
 */
static inline void RCC_disableEcap3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_ECAP3LPEN_M);
}

/**
 * \brief  Enable the ECAP2 clock in sleep mode.
 * \note   This function enables the clock for the EQEP5 module by setting the ECAP2LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the ECAP2 module to operate in sleep mode.
 */
static inline void RCC_enableEcap2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_ECAP2LPEN_M);
}

/**
 * \brief  Disable the ECAP2 clock in sleep mode.
 * \note   This function disables the clock for the ECAP2 module by clearing the ECAP2LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the ECAP2 module from operating in sleep mode.
 */
static inline void RCC_disableEcap2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_ECAP2LPEN_M);
}

/**
 * \brief  Enable the ECAP1 clock in sleep mode.
 * \note   This function enables the clock for the ECAP1 module by setting the ECAP1LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the ECAP1 module to operate in sleep mode.
 */
static inline void RCC_enableEcap1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_ECAP1LPEN_M);
}

/**
 * \brief  Disable the ECAP1 clock in sleep mode.
 * \note   This function disables the clock for the ECAP1 module by clearing the ECAP1LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the ECAP1 module from operating in sleep mode.
 */
static inline void RCC_disableEcap1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_ECAP1LPEN_M);
}

/**
 * \brief  Enable the EPWM7 clock in sleep mode.
 * \note   This function enables the clock for the EPWM7 module by setting the EPWM7LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EPWM7 module to operate in sleep mode.
 */
static inline void RCC_enableEpwm7ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM7LPEN_M);
}

/**
 * \brief  Disable the EPWM7 clock in sleep mode.
 * \note   This function disables the clock for the EPWM7 module by clearing the EPWM7LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EPWM7 module from operating in sleep mode.
 */
static inline void RCC_disableEpwm7ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM7LPEN_M);
}

/**
 * \brief  Enable the EPWM6 clock in sleep mode.
 * \note   This function enables the clock for the EPWM6 module by setting the EPWM6LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EPWM6 module to operate in sleep mode.
 */
static inline void RCC_enableEpwm6ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM6LPEN_M);
}

/**
 * \brief  Disable the EPWM6 clock in sleep mode.
 * \note   This function disables the clock for the EPWM6 module by clearing the EPWM6LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EPWM6 module from operating in sleep mode.
 */
static inline void RCC_disableEpwm6ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM6LPEN_M);
}

/**
 * \brief  Enable the EPWM5 clock in sleep mode.
 * \note   This function enables the clock for the EPWM5 module by setting the EPWM5LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EPWM5 module to operate in sleep mode.
 */
static inline void RCC_enableEpwm5ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM5LPEN_M);
}

/**
 * \brief  Disable the EPWM5 clock in sleep mode.
 * \note   This function disables the clock for the EPWM5 module by clearing the EPWM5LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EPWM5 module from operating in sleep mode.
 */
static inline void RCC_disableEpwm5ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM5LPEN_M);
}

/**
 * \brief  Enable the EPWM4 clock in sleep mode.
 * \note   This function enables the clock for the EPWM4 module by setting the EPWM4LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EPWM4 module to operate in sleep mode.
 */
static inline void RCC_enableEpwm4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM4LPEN_M);
}

/**
 * \brief  Disable the EPWM4 clock in sleep mode.
 * \note   This function disables the clock for the EPWM4 module by clearing the EPWM4LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EPWM4 module from operating in sleep mode.
 */
static inline void RCC_disableEpwm4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM4LPEN_M);
}

/**
 * \brief  Enable the EPWM3 clock in sleep mode.
 * \note   This function enables the clock for the EPWM3 module by setting the EPWM3LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EPWM3 module to operate in sleep mode.
 */
static inline void RCC_enableEpwm3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM3LPEN_M);
}

/**
 * \brief  Disable the EPWM3 clock in sleep mode.
 * \note   This function disables the clock for the EPWM3 module by clearing the EPWM3LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EPWM3 module from operating in sleep mode.
 */
static inline void RCC_disableEpwm3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM3LPEN_M);
}

/**
 * \brief  Enable the EPWM2 clock in sleep mode.
 * \note   This function enables the clock for the EPWM2 module by setting the EPWM2LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EPWM2 module to operate in sleep mode.
 */
static inline void RCC_enableEpwm2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM2LPEN_M);
}

/**
 * \brief  Disable the EPWM2 clock in sleep mode.
 * \note   This function disables the clock for the EPWM2 module by clearing the EPWM2LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EPWM2 module from operating in sleep mode.
 */
static inline void RCC_disableEpwm2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM2LPEN_M);
}

/**
 * \brief  Enable the EPWM1 clock in sleep mode.
 * \note   This function enables the clock for the EPWM1 module by setting the EPWM1LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Setting this bit allows the EPWM1 module to operate in sleep mode.
 */
static inline void RCC_enableEpwm1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM1LPEN_M);
}

/**
 * \brief  Disable the EPWM1 clock in sleep mode.
 * \note   This function disables the clock for the EPWM1 module by clearing the EPWM1LPEN bit in the
 *         RCC APB Clock Enable Register 1 (RCC->PCLKLPEN1).
 *         Clearing this bit stops the EPWM1 module from operating in sleep mode.
 */
static inline void RCC_disableEpwm1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN1.WORDVAL, RCC_APB_EPWM1LPEN_M);
}

/**
 * \brief  Enable the CMPSS4 clock in sleep mode.
 * \note   This function enables the clock for the CMPSS4 module by setting the CMPSS4LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Setting this bit allows the CMPSS4 module to operate in sleep mode.
 */
static inline void RCC_enableCmpss4ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS4LPEN_M);
}

/**
 * \brief  Disable the CMPSS4 clock in sleep mode.
 * \note   This function disables the clock for the CMPSS4 module by clearing the CMPSS4LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Clearing this bit stops the CMPSS4 module from operating in sleep mode.
 */
static inline void RCC_disableCmpss4ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS4LPEN_M);
}

/**
 * \brief  Enable the CMPSS3 clock in sleep mode.
 * \note   This function enables the clock for the CMPSS3 module by setting the CMPSS3LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Setting this bit allows the CMPSS3 module to operate in sleep mode.
 */
static inline void RCC_enableCmpss3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS3LPEN_M);
}

/**
 * \brief  Disable the CMPSS3 clock in sleep mode.
 * \note   This function disables the clock for the CMPSS3 module by clearing the CMPSS3LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Clearing this bit stops the CMPSS3 module from operating in sleep mode.
 */
static inline void RCC_disableCmpss3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS3LPEN_M);
}

/**
 * \brief  Enable the CMPSS2 clock in sleep mode.
 * \note   This function enables the clock for the CMPSS2 module by setting the CMPSS2LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Setting this bit allows the CMPSS2 module to operate in sleep mode.
 */
static inline void RCC_enableCmpss2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS2LPEN_M);
}

/**
 * \brief  Disable the CMPSS2 clock in sleep mode.
 * \note   This function disables the clock for the CMPSS2 module by clearing the CMPSS2LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Clearing this bit stops the CMPSS2 module from operating in sleep mode.
 */
static inline void RCC_disableCmpss2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS2LPEN_M);
}

/**
 * \brief  Enable the CMPSS1 clock in sleep mode.
 * \note   This function enables the clock for the CMPSS1 module by setting the CMPSS1LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Setting this bit allows the CMPSS1 module to operate in sleep mode.
 */
static inline void RCC_enableCmpss1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS1LPEN_M);
}

/**
 * \brief  Disable the CMPSS1 clock in sleep mode.
 * \note   This function disables the clock for the CMPSS1 module by clearing the CMPSS1LPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Clearing this bit stops the CMPSS1 module from operating in sleep mode.
 */
static inline void RCC_disableCmpss1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_CMPSS1LPEN_M);
}

/**
 * \brief  Enable the XBAR clock in sleep mode.
 * \note   This function enables the clock for the XBAR module by setting the XBARLPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Setting this bit allows the XBAR module to operate in sleep mode.
 */
static inline void RCC_enableXbarClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_XBARLPEN_M);
}

/**
 * \brief  Disable the XBAR clock in sleep mode.
 * \note   This function disables the clock for the XBAR module by clearing the XBARLPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Clearing this bit stops the XBAR module from operating in sleep mode.
 */
static inline void RCC_disableXbarClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_XBARLPEN_M);
}

/**
 * \brief  Enable the ADCC clock in sleep mode.
 * \note   This function enables the clock for the ADCC module by setting the ADCCLPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Setting this bit allows the ADCC module to operate in sleep mode.
 */
static inline void RCC_enableAdccClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_ADCCLPEN_M);
}

/**
 * \brief  Disable the ADCC clock in sleep mode.
 * \note   This function disables the clock for the ADCC module by clearing the ADCCLPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Clearing this bit stops the ADCC module from operating in sleep mode.
 */
static inline void RCC_disableAdccClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_ADCCLPEN_M);
}

/**
 * \brief  Enable the ADCA clock in sleep mode.
 * \note   This function enables the clock for the ADCA module by setting the ADCALPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Setting this bit allows the ADCA module to operate in sleep mode.
 */
static inline void RCC_enableAdcaClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_ADCALPEN_M);
}

/**
 * \brief  Disable the ADCA clock in sleep mode.
 * \note   This function disables the clock for the ADCA module by clearing the ADCALPEN bit in the
 *         RCC APB Clock Enable Register 2 (RCC->PCLKLPEN2).
 *         Clearing this bit stops the ADCA module from operating in sleep mode.
 */
static inline void RCC_disableAdcaClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN2.WORDVAL, RCC_APB_ADCALPEN_M);
}

/**
 * \brief  Enable the ANALOGSS clock in sleep mode.
 * \note   This function enables the clock for the ANALOGSS module by setting the ANALOGSSLPEN bit in the
 *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
 *         Setting this bit allows the ANALOGSS module to operate in sleep mode.
 */
static inline void RCC_enableAnalogssClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_APB_ANALOGSSLPEN_M);
}

/**
 * \brief  Disable the ANALOGSS clock in sleep mode.
 * \note   This function disables the clock for the ANALOGSS module by clearing the ANALOGSSLPEN bit in the
 *         RCC APB Clock Enable Register 3 (RCC->PCLKLPEN3).
 *         Clearing this bit stops the ANALOGSS module from operating in sleep mode.
 */
static inline void RCC_disableAnalogssClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN3.WORDVAL, RCC_APB_ANALOGSSLPEN_M);
}

/**
 * \brief  Enable the DCC1 clock in sleep mode.
 * \note   This function enables the clock for the DCC1 module by setting the DCC1LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Setting this bit allows the DCC1 module to operate in sleep mode.
 */
static inline void RCC_enableDCC1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_DCC1LPEN_M);
}

/**
 * \brief  Disable the DCC1 clock in sleep mode.
 * \note   This function disables the clock for the DCC1 module by clearing the DCC1LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Clearing this bit stops the DCC1 module from operating in sleep mode.
 */
static inline void RCC_disableDCC1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_DCC1LPEN_M);
}

/**
 * \brief  Enable the WWDG clock in sleep mode.
 * \note   This function enables the clock for the WWDG module by setting the WWDGLPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Setting this bit allows the WWDG module to operate in sleep mode.
 */
static inline void RCC_enableWwdgClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_WWDGLPEN_M);
}

/**
 * \brief  Disable the WWDG clock in sleep mode.
 * \note   This function disables the clock for the WWDG module by clearing the WWDGLPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Clearing this bit stops the WWDG module from operating in sleep mode.
 */
static inline void RCC_disableWwdgClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_WWDGLPEN_M);
}

/**
 * \brief  Enable the EPG clock in sleep mode.
 * \note   This function enables the clock for the EPG module by setting the EPGLPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Setting this bit allows the EPG module to operate in sleep mode.
 */
static inline void RCC_enableEpgClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_EPGLPEN_M);
}

/**
 * \brief  Disable the EPG clock in sleep mode.
 * \note   This function disables the clock for the EPG module by clearing the EPGLPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Clearing this bit stops the EPG module from operating in sleep mode.
 */
static inline void RCC_disableEpgClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_EPGLPEN_M);
}

/**
 * \brief  Enable the I2C1 clock in sleep mode.
 * \note   This function enables the clock for the I2C1 module by setting the I2C1LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Setting this bit allows the I2C1 module to operate in sleep mode.
 */
static inline void RCC_enableI2c1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_I2C1LPEN_M);
}

/**
 * \brief  Disable the I2C1 clock in sleep mode.
 * \note   This function disables the clock for the I2C1 module by clearing the I2C1LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Clearing this bit stops the I2C1 module from operating in sleep mode.
 */
static inline void RCC_disableI2c1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_I2C1LPEN_M);
}

/**
 * \brief  Enable the SPI2 clock in sleep mode.
 * \note   This function enables the clock for the SPI2 module by setting the SPI2LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Setting this bit allows the SPI2 module to operate in sleep mode.
 */
static inline void RCC_enableSpi2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_SPI2LPEN_M);
}

/**
 * \brief  Disable the SPI2 clock in sleep mode.
 * \note   This function disables the clock for the SPI2 module by clearing the SPI2LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Clearing this bit stops the SPI2 module from operating in sleep mode.
 */
static inline void RCC_disableSpi2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_SPI2LPEN_M);
}

/**
 * \brief  Enable the SPI1 clock in sleep mode.
 * \note   This function enables the clock for the SPI1 module by setting the SPI1LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Setting this bit allows the SPI1 module to operate in sleep mode.
 */
static inline void RCC_enableSpi1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_SPI1LPEN_M);
}

/**
 * \brief  Disable the SPI1 clock in sleep mode.
 * \note   This function disables the clock for the SPI1 module by clearing the SPI1LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Clearing this bit stops the SPI1 module from operating in sleep mode.
 */
static inline void RCC_disableSpi1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_SPI1LPEN_M);
}

/**
 * \brief  Enable the UART1 clock in sleep mode.
 * \note   This function enables the clock for the UART1 module by setting the UART1LPEN bit in the
 *         RCC APB Clock Enable Register 5 (RCC->PCLKLPEN5).
 *         Setting this bit allows the UART1 module to operate in sleep mode.
 */
static inline void RCC_enableUart1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN5.WORDVAL, RCC_APB_UART1LPEN_M);
}

/**
 * \brief  Enable the STIM3 clock in sleep mode.
 * \note   This function enables the clock for the STIM3 module by setting the STIM3LPEN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
 *         Setting this bit allows the STIM3 module to operate in sleep mode.
 */
static inline void RCC_enableStim3ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_APB_STIM3LPEN_M);
}

/**
 * \brief  Disable the STIM3 clock in sleep mode.
 * \note   This function disables the clock for the STIM3 module by clearing the STIM3LPEN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
 *         Clearing this bit stops the STIM3 module from operating in sleep mode.
 */
static inline void RCC_disableStim3ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_APB_STIM3LPEN_M);
}

/**
 * \brief  Enable the STIM2 clock in sleep mode.
 * \note   This function enables the clock for the STIM2 module by setting the STIM2LPEN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
 *         Setting this bit allows the STIM2 module to operate in sleep mode.
 */
static inline void RCC_enableStim2ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_APB_STIM2LPEN_M);
}

/**
 * \brief  Disable the STIM2 clock in sleep mode.
 * \note   This function disables the clock for the STIM2 module by clearing the STIM2LPEN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
 *         Clearing this bit stops the STIM2 module from operating in sleep mode.
 */
static inline void RCC_disableStim2ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_APB_STIM2LPEN_M);
}

/**
 * \brief  Enable the STIM1 clock in sleep mode.
 * \note   This function enables the clock for the STIM1 module by setting the STIM1LPEN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
 *         Setting this bit allows the STIM1 module to operate in sleep mode.
 */
static inline void RCC_enableStim1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_APB_STIM1LPEN_M);
}

/**
 * \brief  Disable the STIM1 clock in sleep mode.
 * \note   This function disables the clock for the STIM1 module by clearing the STIM1LPEN bit in the
 *         RCC APB Clock Enable Register 6 (RCC->PCLKLPEN6).
 *         Clearing this bit stops the STIM1 module from operating in sleep mode.
 */
static inline void RCC_disableStim1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN6.WORDVAL, RCC_APB_STIM1LPEN_M);
}

/**
 * \brief  Enable the AWK clock in sleep mode.
 * \note   This function enables the clock for the AWK module by setting the AWKLPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Setting this bit allows the AWK module to operate in sleep mode.
 */
static inline void RCC_enableAwkClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_AWKLPEN_M);
}

/**
 * \brief  Disable the AWK clock in sleep mode.
 * \note   This function disables the clock for the AWK module by clearing the AWKLPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Clearing this bit stops the AWK module from operating in sleep mode.
 */
static inline void RCC_disableAwkClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_AWKLPEN_M);
}

/**
 * \brief  Enable the LPTIM clock in sleep mode.
 * \note   This function enables the clock for the LPTIM module by setting the LPTIMLPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Setting this bit allows the LPTIM module to operate in sleep mode.
 */
static inline void RCC_enableLptimClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_LPTIMLPEN_M);
}

/**
 * \brief  Disable the LPTIM clock in sleep mode.
 * \note   This function disables the clock for the LPTIM module by clearing the LPTIMLPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Clearing this bit stops the LPTIM module from operating in sleep mode.
 */
static inline void RCC_disableLptimClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_LPTIMLPEN_M);
}

/**
 * \brief  Enable the IWDG1 clock in sleep mode.
 * \note   This function enables the clock for the IWDG1 module by setting the IWDG1LPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Setting this bit allows the IWDG1 module to operate in sleep mode.
 */
static inline void RCC_enableIwdg1ClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_IWDG1LPEN_M);
}

/**
 * \brief  Disable the IWDG1 clock in sleep mode.
 * \note   This function disables the clock for the IWDG1 module by clearing the IWDG1LPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Clearing this bit stops the IWDG1 module from operating in sleep mode.
 */
static inline void RCC_disableIwdg1ClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_IWDG1LPEN_M);
}

/**
 * \brief  Enable the PWR clock in sleep mode.
 * \note   This function enables the clock for the PWR module by setting the PWRLPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Setting this bit allows the PWR module to operate in sleep mode.
 */
static inline void RCC_enablePwrClockInSleepMode (void)
{
    SET_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_PWRLPEN_M);
}

/**
 * \brief  Disable the PWR clock in sleep mode.
 * \note   This function disables the clock for the PWR module by clearing the PWRLPEN bit in the
 *         RCC APB Clock Enable Register 8 (RCC->PCLKLPEN8).
 *         Clearing this bit stops the PWR module from operating in sleep mode.
 */
static inline void RCC_disablePwrClockInSleepMode (void)
{
    CLEAR_BIT(RCC->PCLKLPEN8.WORDVAL, RCC_APB_PWRLPEN_M);
}

/**
 * \brief  Select the HXTL AWDK Division Factor
 * \note   This function selects the division factor for the HXTL AWDK clock by modifying
 *         the appropriate bits in the CFGR2 register (RCC->CFGR2).
 * \param  hxtlAwkDiv  Specifies the division factor for the HXTL AWDK clock.
 *                      This parameter can be any value of @ref RCC_HXTLAWKDIVSELECTION
 */
static inline void RCC_selectHxtlAwkDiv (RCC_HxtlAwkDivSelection hxtlAwkDiv)
{
    MODIFY_REG(RCC->CFGR2.WORDVAL, RCC_HXTLAWKDIV_M, (hxtlAwkDiv << 16));
}

/**
 * \brief  Get the Division Factor for HXTLAWK Clock
 * \note   This function retrieves the division factor for the HXTLAWK clock by reading
 *         the HXTLAWKDIV bits in the RCC Configuration Register 2 (RCC->CFGR2).
 * \return The division factor for the HXTLAWK clock.
 *         This value corresponds to one of the definitions in @ref RCC_HXTLAWKDIVSELECTION
 */
static inline RCC_HxtlAwkDivSelection RCC_getHxtlAwkDiv (void)
{
    return (RCC_HxtlAwkDivSelection)(READ_BIT(RCC->CFGR2.WORDVAL, RCC_HXTLAWKDIV_M) >> 16);
}

/**
 * \brief  Enable the EPWMCLKDIV.
 * \note   This function enables the clock for the PWR module by setting the EPWMCLKDIV bit in the
 *         RCC APB Clock Enable Register 8 (RCC->CFGR2).
 *         Setting this bit allows the EPWM module to Enable the Clock frequency division.
 */
static inline void RCC_enableEpwmClkDiv (void)
{
    SET_BIT(RCC->CFGR2.WORDVAL, RCC_EPWMCLKDIV_M);
}

/**
 * \brief  Disable the EPWMCLKDIV.
 * \note   This function Disables the clock for the PWR module by setting the EPWMCLKDIV bit in the
 *         RCC APB Clock Disable Register 8 (RCC->CFGR2).
 *         Setting this bit allows the EPWM module to Disable the Clock frequency division.
 */
static inline void RCC_disableEpwmClkDiv (void)
{
    CLEAR_BIT(RCC->CFGR2.WORDVAL, RCC_EPWMCLKDIV_M);
}

/**
 * \brief  Select the Trace Clock Division Factor
 * \note   This function selects the division factor for the trace clock by modifying
 *         the appropriate bits in the CFGR2 register (RCC->CFGR2).
 * \param  traceClockDiv  Specifies the division factor for the trace clock.
 *                         This parameter can be any value of @ref RCC_TRACECLOCKDIVSELECTION
 */
static inline void RCC_selectTraceClockDiv (RCC_TraceClockDivSelection traceClockDiv)
{
    MODIFY_REG(RCC->CFGR2.WORDVAL, RCC_TRACEDIV_M, (traceClockDiv << 4));
}

/**
 * \brief  Get the Division Factor for Trace Clock
 * \note   This function retrieves the division factor for the Trace clock by reading
 *         the TRACEDIV bits in the RCC Configuration Register 2 (RCC->CFGR2).
 * \return The division factor for the Trace clock.
 *         This value corresponds to one of the definitions in @ref RCC_TRACECLOCKDIVSELECTION
 */
static inline RCC_TraceClockDivSelection RCC_getTraceClockDiv (void)
{
    return (RCC_TraceClockDivSelection)(READ_BIT(RCC->CFGR2.WORDVAL, RCC_TRACEDIV_M) >> 4);
}

/**
 * \brief  Select the Flash Clock Division Factor
 * \note   This function selects the division factor for the flash clock by modifying
 *         the appropriate bits in the CFGR2 register (RCC->CFGR2).
 * \param  flashClockDiv  Specifies the division factor for the flash clock.
 *                         This parameter can be any value of @ref RCC_FLASHCLOCKDIVSELECTION
 */
static inline void RCC_selectFlashClockDiv (RCC_FlashClockDivSelection flashClockDiv)
{
    MODIFY_REG(RCC->CFGR2.WORDVAL, RCC_FLASHDIV_M, flashClockDiv);
}

/**
 * \brief  Get the Division Factor for Flash Clock
 * \note   This function retrieves the division factor for the Flash clock by reading
 *         the FLASHDIV bits in the RCC Configuration Register 2 (RCC->CFGR2).
 * \return The division factor for the Flash clock.
 *         This value corresponds to one of the definitions in @ref RCC_FLASHCLOCKDIVSELECTION
 */
static inline RCC_FlashClockDivSelection RCC_getFlashClockDiv (void)
{
    return (RCC_FlashClockDivSelection)(READ_BIT(RCC->CFGR2.WORDVAL, RCC_FLASHDIV_M));
}

/**
 * \brief  Select the Loop Filter Capacitance Configuration
 * \note   This function configures the loop filter capacitance by modifying the appropriate bits in the PLLCR4 register (RCC->PLLCR4).
 *         It applies a key value for security purposes.
 * \param  lfResSelection  Specifies the loop filter resistor configuration.
 *                          This parameter can be any value of @ref RCC_LOOPFILTERRESSELECTION
 */
static inline void RCC_selectLoopFilterCap (RCC_LoopFilterResSelection lfCapSelection)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_FLT_CAP_M, ((lfCapSelection << 8) | RCC_PLLCTRL_KEY));
}

/**
 * \brief  Select the Charge Pump Current Configuration
 * \note   This function configures the charge pump current by modifying the appropriate bits in the PLLTCR register (RCC->PLLTCR).
 *         It applies a key value for security purposes.
 * \param  cpCurrentSelection  Specifies the charge pump current configuration.
 *                              This parameter can be any value of @ref RCC_CHARGEPUMPCURRENTSELECTION
 */
static inline void RCC_selectChargePumpCurrent (RCC_ChargePumpCurrentSelection cpCurrentSelection)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_ICP_SL_M, ((cpCurrentSelection << 4) | RCC_PLLCTRL_KEY));
}

/**
 * \brief  Select the Loop Filter Resistor Configuration
 * \note   This function configures the loop filter resistor by modifying the appropriate bits in the PLLTCR register (RCC->PLLTCR).
 *         It applies a key value for security purposes.
 * \param  lfResSelection  Specifies the loop filter resistor configuration.
 *                          This parameter can be any value of @ref RCC_LOOPFILTERRESSELECTION
 */
static inline void RCC_selectLoopFilterRes (RCC_LoopFilterResSelection lfResSelection)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_FLT_RES_M, ((lfResSelection << 2) | RCC_PLLCTRL_KEY));
}

/**
 * \brief  Select the VCO Frequency Range Configuration
 * \note   This function configures the VCO (Voltage Controlled Oscillator) frequency range by modifying the appropriate bits in the PLLTCR register (RCC->PLLTCR).
 *         It applies a key value for security purposes.
 * \param  vcoFrequencySelection  Specifies the VCO frequency range configuration.
 *                                 This parameter can be any value of @ref RCC_VCOFREQUENCYSELECTION
 */
static inline void RCC_selectVcoRng (RCC_VcoFrequencySelection vcoFrequencySelection)
{
    MODIFY_REG(RCC->PLLCR4.WORDVAL, RCC_VCORNG_M, (vcoFrequencySelection | RCC_PLLCTRL_KEY));
}

/**
 * \brief  Configure the MIRC1 Trim Value
 * \note   This function configures the trim value for the MIRC1 (Internal High-Speed RC Oscillator)
 *         by modifying the appropriate bits in the MIRC1CR register (RCC->MIRC1CR).
 *         It applies a key value for security purposes.
 * \param  mirc1TrimValue  Specifies the trim value for the MIRC1.
 *                          This parameter can be any value in the range 0 to 0x1FF.
 */
static inline void RCC_configMirc1Trim (uint16_t mirc1TrimValue)
{
    WRITE_REG(RCC->MIRC1CR.WORDVAL, (mirc1TrimValue | RCC_MIRC1CTRL_KEY));
}

/**
 * \brief  Configure the MIRC2 Trim Value
 * \note   This function configures the trim value for the MIRC2 (Internal High-Speed RC Oscillator)
 *         by modifying the appropriate bits in the MIRC2CR register (RCC->MIRC2CR).
 *         It applies a key value for security purposes.
 * \param  mirc2TrimValue  Specifies the trim value for the MIRC2.
 *                          This parameter can be any value in the range 0 to 0x1FF.
 */
static inline void RCC_configMirc2Trim (uint16_t mirc2TrimValue)
{
    WRITE_REG(RCC->MIRC2CR.WORDVAL, (mirc2TrimValue | RCC_MIRC2CTRL_KEY));
}

/**
 * \brief  Enable the HXTL Filter
 * \note   This function enables the HXTL (High-Speed External Crystal Oscillator) filter
 *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_enableHxtlFilter (void)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLFLT_EN_M, (RCC_HXTLFLT_EN_M | RCC_HTXLCTRL_KEY));
}

/**
 * \brief  Disable the HXTL Filter
 * \note   This function disables the HXTL (High-Speed External Crystal Oscillator) filter
 *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_disableHxtlFilter (void)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLFLT_EN_M, RCC_HTXLCTRL_KEY);
}

/**
 * \brief  Select the HXTL RF Setting
 * \note   This function selects the RF setting for the HXTL (High-Speed External Crystal Oscillator)
 *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
 *         It applies a key value for security purposes.
 * \param  hxtlRfSelection  Specifies the RF setting for the HXTL.
 *                           This parameter can be any value of @ref RCC_HXTLRFSELECTION
 */
static inline void RCC_selectHxtlRf (RCC_HxtlRfSelection hxtlRfSelection)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTL_RF_SEL_M, ((hxtlRfSelection << 13) | RCC_HTXLCTRL_KEY));
}

/**
 * \brief  Enable the HXTL RF
 * \note   This function enables the RF for the HXTL (High-Speed External Crystal Oscillator)
 *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_enableHxtlRf (void)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTL_RF_EN_M, (RCC_HXTL_RF_EN_M | RCC_HTXLCTRL_KEY));
}

/**
 * \brief  Disable the HXTL RF
 * \note   This function disables the RF for the HXTL (High-Speed External Crystal Oscillator)
 *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_disableHxtlRf (void)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTL_RF_EN_M, RCC_PLLCTRL_KEY);
}

/**
 * \brief  Select the HXTL Stabilization Time
 * \note   This function selects the stabilization time for the HXTL (High-Speed External Crystal Oscillator)
 *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
 *         It applies a key value for security purposes.
 * \param  hxtlStsSelection  Specifies the stabilization time setting for the HXTL.
 *                            This parameter can be any value of @ref RCC_HXTLSTSSELECTION
 */
static inline void RCC_selectHxtlStabilizationTime (RCC_HxtlStsSelection hxtlStsSelection)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLSTUP_M, ((hxtlStsSelection << 8) | RCC_HTXLCTRL_KEY));
}

/**
 * \brief  Select the HXTL Driver Setting
 * \note   This function selects the driver setting for the HXTL (High-Speed External Crystal Oscillator)
 *         by modifying the appropriate bits in the HXTLCR register (RCC->HXTLCR).
 *         It applies a key value for security purposes.
 * \param  hxtlMfSelection  Specifies the driver setting for the HXTL.
 *                           This parameter can be any value of @ref RCC_HXTLMFSELECTION
 */
static inline void RCC_selectHxtlDriver (RCC_HxtlMfSelection hxtlMfSelection)
{
    MODIFY_REG(RCC->HXTLCR.WORDVAL, RCC_HXTLMF_M, (hxtlMfSelection | RCC_HTXLCTRL_KEY));
}

/**
 * \brief  Select the MIRC1 and MIRC2 Cycle Setting
 * \note   This function selects the cycle setting between MIRC1 and MIRC2
 *         by modifying the appropriate bits in the MCDCR register (RCC->MCDCR).
 *         It applies a key value for security purposes.
 * \param  mirc1Mirc2CycSelection  Specifies the cycle setting between MIRC1 and MIRC2.
 *                                  This parameter can be any value of @ref RCC_MIRC1MIRC2CYCSELECTION
 */
static inline void RCC_selectMirc1Mirc2Cyc (RCC_Mirc1Mirc2CycSelection mirc1Mirc2CycSelection)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDPD_M, ((mirc1Mirc2CycSelection << 8) | RCC_MCDCTRL_KEY));
}

/**
 * \brief  Enable MCD Interrupt
 * \note   This function enables the interrupt for the Main Clock Domain (MCD)
 *         by setting the appropriate bit in the MCDCR register (RCC->MCDCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_enableMcdInt (void)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDIE_M, (RCC_MCDIE_M | RCC_MCDCTRL_KEY));
}

/**
 * \brief  Disable MCD Interrupt
 * \note   This function disables the interrupt for the Main Clock Domain (MCD)
 *         by clearing the appropriate bit in the MCDCR register (RCC->MCDCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_disableMcdInt (void)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDIE_M, RCC_MCDCTRL_KEY);
}

/**
 * \brief  Clear MCD Interrupt Flag
 * \note   This function clears the interrupt flag for the Main Clock Domain (MCD)
 *         by setting the appropriate bit in the MCDCR register (RCC->MCDCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_clearMcdIntFlag (void)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDCLR_M, (RCC_MCDCLR_M | RCC_MCDCTRL_KEY));
}

/**
 * \brief  Read the MCD Interrupt Flag.
 * \note   This function checks the MCD interrupt flag bit in the MCDCR register (RCC->MCDCR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the MCD Interrupt Flag.
 *         - 0: The MCD Interrupt Flag is not set.
 *         - 1: The MCD Interrupt Flag is set.
 */
static inline uint32_t RCC_readMcdIntFlag (void)
{
    return READ_BIT(RCC->MCDCR.WORDVAL, RCC_MCDFLG_M) ? 1UL : 0UL;
}

/**
 * \brief  Enable Miss Clock Detect (MCD)
 * \note   This function enables the Miss Clock Detect (MCD)
 *         by setting the appropriate bit in the MCDCR register (RCC->MCDCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_enableMcd (void)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDEN_M, (RCC_MCDEN_M | RCC_MCDCTRL_KEY));
}

/**
 * \brief  Disable Miss Clock Detect (MCD)
 * \note   This function disables the Miss Clock Detect (MCD)
 *         by clearing the appropriate bit in the MCDCR register (RCC->MCDCR).
 *         It applies a key value for security purposes.
 */
static inline void RCC_disableMcd (void)
{
    MODIFY_REG(RCC->MCDCR.WORDVAL, RCC_MCDEN_M, RCC_MCDCTRL_KEY);
}

/**
 * \brief  Reset the CPU Core
 * \note   This function resets the CPU core by writing the appropriate value to the RSTCR register (RCC->RSTCR).
 *         It applies the CPU core reset bit (RCC_CPURST) to trigger the reset.
 */
static inline void RCC_rstCpuCore (void)
{
    WRITE_REG(RCC->RSTCR.WORDVAL, RCC_CPURST);
}

/**
 * \brief  Reset the MCU
 * \note   This function resets the entire microcontroller (MCU) by writing the appropriate value to the RSTCR register (RCC->RSTCR).
 *         It applies the system reset bit (RCC_SIMXRS) to trigger the reset.
 */
static inline void RCC_rstMcu (void)
{
    WRITE_REG(RCC->RSTCR.WORDVAL, RCC_SIMXRS);
}

/**
 * \brief  Clear Reset Flags
 * \note   This function clears the reset flags by setting the appropriate bit in the RSTSR register (RCC->RSTSR).
 *         It applies the remove reset flag mask (RCC_RMVF_M) to clear the flags.
 */
static inline void RCC_clearChipRstFlag (void)
{
    SET_BIT(RCC->RSTSR.WORDVAL, RCC_RMVF_M);
}

/**
 * \brief  Read the Remove Reset Flag Status.
 * \note   This function checks the RMVST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Remove Reset Flag.
 *          - 0: The reset flag is not being cleared.
 *          - 1: The reset flag is being cleared.
 */
static inline uint32_t RCC_readRemoveRstFlagStatus(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_RMVST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Standby Reset Flag Status.
 * \note   This function checks the SBYDBGRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Standby Reset Flag.
 *          - 0: The standby reset flag is not set.
 *          - 1: The standby reset flag is set.
 */
static inline uint32_t RCC_readStandbyRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_SBYDBGRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Low Power Reset Flag Status.
 * \note   This function checks the LPWRRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Low Power Reset Flag.
 *          - 0: The low power reset flag is not set.
 *          - 1: The low power reset flag is set.
 */
static inline uint32_t RCC_readLowPowerRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_LPWRERST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the NMI Watchdog Reset Flag Status.
 * \note   This function checks the NMIWDTRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the NMI Watchdog Reset Flag.
 *          - 0: The NMI watchdog reset flag is not set.
 *          - 1: The NMI watchdog reset flag is set.
 */
static inline uint32_t RCC_readNmiWdtRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_NMIWDTRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Software Reset Flag Status.
 * \note   This function checks the SFTRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Software Reset Flag.
 *          - 0: The software reset flag is not set.
 *          - 1: The software reset flag is set.
 */
static inline uint32_t RCC_readSoftRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_SFTRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the CPU Reset Flag Status.
 * \note   This function checks the CPURST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the CPU Reset Flag.
 *          - 0: The CPU reset flag is not set.
 *          - 1: The CPU reset flag is set.
 */
static inline uint32_t RCC_readCpuRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_CPURST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Loss of Lock Reset Flag Status.
 * \note   This function checks the LOLRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Loss of Lock Reset Flag.
 *          - 0: The loss of lock reset flag is not set.
 *          - 1: The loss of lock reset flag is set.
 */
static inline uint32_t RCC_readLolRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_LOLRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Lockup Reset Flag Status.
 * \note   This function checks the LOCKUPRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Lockup Reset Flag.
 *          - 0: The lockup reset flag is not set.
 *          - 1: The lockup reset flag is set.
 */
static inline uint32_t RCC_readLockupRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_LOCKUPRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Clock Failure of Reset Flag Status.
 * \note   This function checks the CLKFAILRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Clock failure of Reset Flag.
 *          - 0: The clock failure of clock reset flag is not set.
 *          - 1: The clock failure of clock reset flag is set.
 */
static inline uint32_t RCC_readClockFailRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_CLKFAILRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Independent Watchdog 1 Reset Flag Status.
 * \note   This function checks the IWDG1RST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Independent Watchdog 1 Reset Flag.
 *          - 0: The independent watchdog 1 reset flag is not set.
 *          - 1: The independent watchdog 1 reset flag is set.
 */
static inline uint32_t RCC_readIwdg1RstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_IWDG1RST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the Window Watchdog Reset Flag Status.
 * \note   This function checks the WWDGRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the Window Watchdog Reset Flag.
 *          - 0: The window watchdog reset flag is not set.
 *          - 1: The window watchdog reset flag is set.
 */
static inline uint32_t RCC_readWwdgRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_WWDGRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the SIMX Reset Flag Status.
 * \note   This function checks the SIMXRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the SIMX Reset Flag.
 *          - 0: The SIMX reset flag is not set.
 *          - 1: The SIMX reset flag is set.
 */
static inline uint32_t RCC_readSimxRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_SIMXRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the External Pin Reset Flag Status.
 * \note   This function checks the XRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the External Pin Reset Flag.
 *          - 0: The external pin reset flag is not set.
 *          - 1: The external pin reset flag is set.
 */
static inline uint32_t RCC_readExPinRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_XRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the VDD Power-On Reset Flag Status.
 * \note   This function checks the VDDPORRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the VDD Power-On Reset Flag.
 *          - 0: The VDD power-on reset flag is not set.
 *          - 1: The VDD power-on reset flag is set.
 */
static inline uint32_t RCC_readVddPorRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_VDDPORRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the VDD I/O Brown-Out Reset Flag Status.
 * \note   This function checks the VDDIOBORRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the VDD I/O Brown-Out Reset Flag.
 *          - 0: The VDD I/O brown-out reset flag is not set.
 *          - 1: The VDD I/O brown-out reset flag is set.
 */
static inline uint32_t RCC_readVddIoBorRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_VDDIOBORRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Read the VDD I/O Power-On Reset Flag Status.
 * \note   This function checks the VDDIOPORRST bit in the RCC Reset Status Register (RCC->RSTSR)
 *         and returns a boolean value indicating whether the flag is set.
 * \return Returns the status of the VDD I/O Power-On Reset Flag.
 *          - 0: The VDD I/O power-on reset flag is not set.
 *          - 1: The VDD I/O power-on reset flag is set.
 */
static inline uint32_t RCC_readVddIoPorRstFlag(void)
{
    return READ_BIT(RCC->RSTSR.WORDVAL, RCC_VDDIOPORRST_M) ? 1UL : 0UL;
}

/**
 * \brief  Unlock the RCC Register Access.
 * \note   This function unlocks access to certain RCC registers by writing a specific unlock key
 *         to the UNLOCK register (RCC->UNLOCK). This is necessary before modifying protected RCC registers.
 */
static inline void RCC_unlockRccRegister(void)
{
    WRITE_REG(RCC->UNLOCK.WORDVAL, RCC_UNLOCK);
}

/**
 * \brief  Lock the RCC Register Access.
 * \note   This function locks access to certain RCC registers by writing a specific lock key
 *         to the UNLOCK register (RCC->UNLOCK). This prevents accidental modification of protected RCC registers.
 */
static inline void RCC_lockRccRegister(void)
{
    WRITE_REG(RCC->UNLOCK.WORDVAL, RCC_LOCK);
}

/**
 * \brief  Get the status of a specified RCC interrupt flag.
 * \note   This function reads and returns the status of the specified interrupt flag based on the provided interrupt source.
 * \return Returns the status of the specified interrupt flag.
 *          - RCC_OSC_CLKSTOPIF: Bit 31 set, Oscillator Clock Stop Interrupt Flag is set.
 *          - RCC_PLL_LOLIF:     Bit 29 set, indicating that the PLL Loss of Lock Interrupt Flag is set.
 *          - RCC_PLL_LKDTIF:    Bit 25 set, indicating that the PLL Lock Detect Timeout Interrupt Flag is set.
 *          - RCC_HXTLFAILIF:    Bit 18 set, indicating that the High-speed External Crystal Oscillator Failure Interrupt Flag is set.
 *          - RCC_HXTLRDYIF:     Bit 17 set, indicating that the High-speed External Crystal Oscillator Ready Interrupt Flag is set.
 *          - RCC_LIRCRDYIF:     Bit 15 set, indicating that the Low Internal Reference Clock Ready Interrupt Flag is set.
 *          - RCC_MIRC1RDYIF:    Bit 9 set, indicating that the Main Internal RC Oscillator 1 Ready Interrupt Flag is set.
 *          - RCC_MIRC2RDYIF:    Bit 1 set, indicating that the Main Internal RC Oscillator 2 Ready Interrupt Flag is set.
 */
static inline uint32_t RCC_getIntFlagStatus (void)
{
    return (RCC->IFR.WORDVAL);
}

/**
 * \brief  Get the status of a specified reset flag.
 * \note   This function retrieves the status of a specific reset flag within the RCC register.
 * \return Returns the status of the specified reset flag.
 *          - RCC_RMVF:        Bit 31 set, REMOVE RESET FLAG bit
 *          - RCC_RMVFST:      Bit 30 set, Indicates that in the REMOVE RESET FLAG action.
 *          - RCC_SBYDBGRST:   Bit 17 set, indicating that the Standby Debug Reset has occurred
 *          - RCC_LPWRRST:     Bit 16 set, indicating that the Low-Power Reset has occurred
 *          - RCC_NMIWDTRST:   Bit 14 set, indicating that the Non-Maskable Interrupt Watchdog Reset has occurred
 *          - RCC_SFTRST:      Bit 13 set, indicating that the Software Reset has occurred
 *          - RCC_CPURST:      Bit 12 set, indicating that the CPU Reset has occurred
 *          - RCC_LOLRST:      Bit 11 set, indicating that the Low-power Oscillator Loss Reset has occurred
 *          - RCC_LOCKUPRST:   Bit 10 set, indicating that the Lockup Reset has occurred
 *          - RCC_CLKFAILRST:  Bit 9 set, indicating that the Clock Management Unit Loss of Clock has occurred
 *          - RCC_IWDG1RST:    Bit 7 set, indicating that the Independent Watchdog 1 Reset has occurred
 *          - RCC_WWDGRST:     Bit 6 set, indicating that the Window Watchdog Reset has occurred
 *          - RCC_SIMXRST:     Bit 5 set, indicating that the System Interface Module Reset has occurred
 *          - RCC_XRST:        Bit 4 set, indicating that the External Reset has occurred
 *          - RCC_VDDPORRST:   Bit 2 set, indicating that the VDD Power-On/Power-Off Reset has occurred
 *          - RCC_VDDIOBORRST: Bit 1 set, indicating that the VDDIO Power-On/Brownout Reset has occurred
 *          - RCC_VDDIOPORRST: Bit 0 set, indicating that the VDDIO Power-On Reset has occurred
 */
static inline uint32_t RCC_getRstFlagStatus (void)
{
    return (RCC->RSTSR.WORDVAL);
}

/**
 * \brief  Get the System Clock Frequency.
 * \note   This function determines the current system clock frequency based on the clock source
 *         and PLL configuration. It reads the software clock switch status and calculates the
 *         frequency accordingly.
 * \return Returns the system clock frequency in Hz.
 *          - HXTL_FREQ: If the system clock source is HXTL.
 *          - MIRC1_FREQ: If the system clock source is MIRC1.
 *          - MIRC2_FREQ: If the system clock source is MIRC2.
 *          - Calculated frequency: If the system clock source is PLL,
 *            based on PLLM, PLLN, PLLP, and PLL source.
 */
extern uint32_t RCC_getSysClockFrequency (void);

/**
 * \brief  Get the HCLK (AHB) Clock Frequency.
 * \note   This function determines the current HCLK (AHB) clock frequency based on the system clock frequency
 *         and the AHB prescaler. It reads the system clock frequency and divides it by the AHB prescaler value.
 * \return Returns the HCLK (AHB) clock frequency in Hz.
 */
extern uint32_t RCC_getHclkFrequency (void);

/**
 * \brief  Get the PCLK1 (APB1) Clock Frequency.
 * \note   This function determines the current PCLK1 (APB1) clock frequency based on the HCLK (AHB) clock frequency
 *         and the APB1 prescaler. It reads the HCLK frequency and divides it by the APB1 prescaler value.
 * \return Returns the PCLK1 (APB1) clock frequency in Hz.
 */
extern uint32_t RCC_getPclk1Frequency (void);

/**
 * \brief  Get the PCLK2,4 (APB2,4) Clock Frequency.
 * \note   This function determines the current PCLK2,4 (APB2,4) clock frequency based on the HCLK (AHB)
 *         clock frequency and the APB2,4 prescaler. It reads the HCLK frequency and divides it
 *         by the APB2,4 prescaler value.
 * \return Returns the PCLK2,4 (APB2,4) clock frequency in Hz.
 */
extern uint32_t RCC_getPclk2Frequency (void);

/**
 * \brief  Get the PCLK5 (APB5) Clock Frequency.
 * \note   This function determines the current PCLK5 (APB5) clock frequency based on the HCLK (AHB) clock frequency
 *         and the APB5 prescaler. It reads the HCLK frequency and divides it by the APB5 prescaler value.
 * \return Returns the PCLK5 (APB5) clock frequency in Hz.
 */
extern uint32_t RCC_getPclk5Frequency (void);

/**
 * \brief  Get the EPWM Clock Frequency.
 * \note   This function determines the current EPWM clock frequency based on the HCLK Source clock frequency
 *         and the EPWMCLKDIV prescaler. It reads the HCLK Source frequency and divides it by the HCLK Source prescaler value.
 * \return Returns the EPWM clock frequency in Hz.
 */
extern uint32_t RCC_getEpwmFrequency (void);

/**
 * \brief  Get the Trace Clock Frequency.
 * \note   This function determines the current Trace clock frequency based on the HCLK (AHB) clock frequency
 *         and the Trace prescaler. It reads the HCLK frequency and divides it by the Trace prescaler value.
 * \return Returns the Trace clock frequency in Hz.
 */
extern uint32_t RCC_getTraceClockFrequency (void);

/**
 * \brief  Get the Flash Clock Frequency.
 * \note   This function determines the current Flash clock frequency based on the HCLK (AHB) clock frequency
 *         and the Flash prescaler. It reads the HCLK frequency and divides it by the Flash prescaler value.
 * \return Returns the Flash clock frequency in Hz.
 */
extern uint32_t RCC_getFlashClockFrequency (void);

/**
 * \brief  Configures the system clock source and related clock dividers.
 * \note   Before switching the clock, ensure that the clock source is enabled and ready.
 * \param  sysClockConfig    Specifies the system clock source.
 *                            This parameter can be any value of @ref RCC_SYSCLKSRC
 * \return Returns 0 if the clock configuration is successful, otherwise returns 1.
 */
extern uint32_t RCC_setClock (RCC_SysclkSrc sysClockConfig);

/**
 * \brief  Read the Software Clock Switch Status.
 * \note   This function reads the SWSTA bit in the RCC Configuration Register (RCC->CFGR)
 *         and returns its value after shifting it right by 4 bits.
 * \return Returns the software clock switch status.
 *          - 0: RCC_SYSCLKSTATUS_MIRC2
 *          - 1: RCC_SYSCLKSTATUS_HXTL
 *          - 2: RCC_SYSCLKSTATUS_PLL
 *          - 3: RCC_SYSCLKSTATUS_MIRC1
 */
extern RCC_SysclkStatus RCC_getClockSource (void);

/**
 * \brief  Configures the clock division settings for the Microcontroller Clock Output (MCO).
 * \param  config    Configuration value for clock division settings.
 *                    This parameter can be value of @ref CLOCKDIVCONFIG
 */
extern void RCC_configClockDiv (uint32_t config , uint32_t config2);

/**
 * \brief  Configures the Microcontroller Clock Output 1 (MCO1) settings.
 *
 * \param  mcoSource      Specifies the source for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCOSOURCESEL
 * \param  mcoDiv         Specifies the divider for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCODIVSEL
 * \param  mcoStatus      Specifies whether to enable or disable the MCO output.
 *                         This parameter can be any value of @ref RCC_FUNON
 */
extern void RCC_configMco1 (RCC_McoSourceSel mcoSource, RCC_McoDivSel mcoDiv, RCC_FunOn mcoEnable);

/**
 * \brief  Configures the Microcontroller Clock Output 2 (MCO2) settings.
 *
 * \param  mcoSource      Specifies the source for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCOSOURCESEL
 * \param  mcoDiv         Specifies the divider for the MCO output.
 *                         This parameter can be any value of @ref RCC_MCODIVSEL
 * \param  mcoStatus      Specifies whether to enable or disable the MCO output.
 *                         This parameter can be any value of @ref RCC_FUNON
 */
extern void RCC_configMco2 (RCC_McoSourceSel mcoSource, RCC_McoDivSel mcoDiv, RCC_FunOn mcoEnable);

/**
 * \brief  Set the RCC interrupt enable.
 * 
 * \param  intSource  Specifies the interrupt source to configure.
 *                     This parameter can be any combination of values from @ref RCC_IERMASKS
 *                       RCC_MIRC2RDYIE_M
 *                       RCC_MIRC1RDYIE_M
 *                       RCC_LIRCRDYIE_M
 *                       RCC_HXTLNFSEL_M
 *                       RCC_HXTLRDYIE_M
 *                       RCC_HXTLFAILIE_M
 *                       RCC_PLL_LKDTIE_M
 *                       RCC_PLL_LOLIE_M
 *                       RCC_PLL_OSCCLKSTOPSEL_M
 *                       RCC_PLL_OSCCLKSTOPIE_M
 */
extern void RCC_setInterruptEnable (uint32_t intSource);

/**
 * \brief  Clear the RCC interrupt enable.
 * 
 * \param  intSource  Specifies the interrupt source to configure.
 *                     This parameter can be any combination of values from @ref RCC_IERMASKS
 *                       RCC_MIRC2RDYIE_M
 *                       RCC_MIRC1RDYIE_M
 *                       RCC_LIRCRDYIE_M
 *                       RCC_HXTLNFSEL_M
 *                       RCC_HXTLRDYIE_M
 *                       RCC_HXTLFAILIE_M
 *                       RCC_PLL_LKDTIE_M
 *                       RCC_PLL_LOLIE_M
 *                       RCC_PLL_OSCCLKSTOPSEL_M
 *                       RCC_PLL_OSCCLKSTOPIE_M
 */
extern void RCC_clearInterruptEnable (uint32_t intSource);

/**
 * \brief  Clear the specified RCC interrupt flag.
 * \note   This function clears the specified interrupt flag based on the provided interrupt source.
 * 
 * \param  intSource    Specifies the interrupt source whose flag is to be cleared.
 *                       This parameter can be any combination of values from \e RCC_IntSourceSelection
 *                         RCC_MIRC2RDY
 *                         RCC_MIRC1RDY
 *                         RCC_LIRCRDY
 *                         RCC_HXTLRDY
 *                         RCC_HXTLFAIL
 *                         RCC_PLL_LKDT
 *                         RCC_PLL_LOL
 *                         RCC_OSCCLK_STOP
 */
extern void RCC_clearInterruptFlag (uint32_t intSource);

/**
 * \brief  Enables the MIRC2 oscillator and waits for it to be enabled.
 * \note   This function enables the MIRC2 oscillator and waits until it is fully enabled.
 *         It returns a status indicating success or failure.
 * \return Returns 0 if the MIRC2 oscillator is successfully enabled, otherwise returns 1.
 */
extern uint32_t RCC_enableMirc2Oscillator (void);

/**
 * \brief  Enables the MIRC1 oscillator and waits for it to be enabled.
 * \note   This function enables the MIRC1 oscillator and waits until it is fully enabled.
 *         It returns a status indicating success or failure.
 * \return Returns 0 if the MIRC1 oscillator is successfully enabled, otherwise returns 1.
 */
extern uint32_t RCC_enableMirc1Oscillator (void);

/**
 * \brief  Enables the LIRC oscillator and waits for it to be enabled.
 * \note   This function disables the LIRC oscillator and waits until it is fully enabled.
 *         It returns a status indicating success or failure.
 * \return Returns 0 if the LIRC oscillator is successfully enabled, otherwise returns 1.
 */
extern uint32_t RCC_enableLircOscillator (void);

/**
 * \brief  Disables the MIRC2 oscillator and waits for it to be disabled.
 * \note   This function disables the MIRC2 oscillator and waits until it is fully disabled.
 *         It returns a status indicating success or failure.
 * \return Returns 0 if the MIRC2 oscillator is successfully disabled, otherwise returns 1.
 */
extern uint32_t RCC_disableMirc2Oscillator (void);

/**
 * \brief  Disables the MIRC1 oscillator and waits for it to be disabled.
 * \note   This function disables the MIRC1 oscillator and waits until it is fully disabled.
 *         It returns a status indicating success or failure.
 * \return Returns 0 if the MIRC1 oscillator is successfully disabled, otherwise returns 1.
 */
extern uint32_t RCC_disableMirc1Oscillator (void);

/**
 * \brief  Disables the LIRC oscillator and waits for it to be disabled.
 * \note   This function disables the LIRC oscillator and waits until it is fully disabled.
 *         It returns a status indicating success or failure.
 * \return Returns 0 if the LIRC oscillator is successfully disabled, otherwise returns 1.
 */
extern uint32_t RCC_disableLircOscillator (void);

/**
 * \brief  Configure the PLL with the specified settings.
 * \note   This function configures the PLL based on the provided configuration parameters.
 * \param  pllConfig      Specifies the PLL configuration settings.
 *                         This parameter can include values from @ref PLLCONFIG
 * \param  pllExtConfig   Specifies the PLL configuration settings.
 *                         This parameter can include values from @ref PLLEXTCONFIG
 * \param  pllStatus      Specifies whether to enable or disable the PLL.
 *                         This parameter can be any value of @ref RCC_FUNON
 * \return Returns 0 if the pll configuration is successful, otherwise returns 1.
 */
extern uint32_t RCC_configPll (uint32_t pllConfig, uint32_t pllExtConfig, RCC_FunOn pllStatus);

/**
 * \brief  Reset the specified AHB1 peripheral(s).
 * \note   This function resets one or more AHB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral reset request.
 * \param  peripheral    Specifies the AHB1 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_AHBRST1MASKS
 */
extern void RCC_resetAhb1Peripheral (uint32_t peripheral);

/**
 * \brief  Reset the specified AHB2 peripheral(s).
 * \note   This function resets one or more AHB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral reset request.
 * \param  peripheral    Specifies the AHB2 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_AHBRST2MASKS
 */
extern void RCC_resetAhb2Peripheral (uint32_t peripheral);

/**
 * \brief  Reset the specified APB1 peripheral(s).
 * \note   This function resets one or more APB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral reset request.
 * \param  peripheral    Specifies the APB1 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST1MASKS
 */
extern void RCC_resetApb1Peripheral (uint32_t peripheral);

/**
 * \brief  Reset the specified APB2 peripheral(s).
 * \note   This function resets one or more APB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral reset request.
 * \param  peripheral    Specifies the APB2 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST2MASKS
 */
extern void RCC_resetApb2Peripheral (uint32_t peripheral);

/**
 * \brief  Reset the specified APB3 peripheral(s).
 * \note   This function resets one or more APB3 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral reset request.
 * \param  peripheral    Specifies the APB3 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST3MASKS
 */
extern void RCC_resetApb3Peripheral (uint32_t peripheral);

/**
 * \brief  Reset the specified APB5 peripheral(s).
 * \note   This function resets one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
 * \param  peripheral    Specifies the APB5 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST5MASKS
 */
extern void RCC_resetApb5Peripheral (uint32_t peripheral);

/**
 * \brief  Reset the specified APB6 peripheral(s).
 * \note   This function resets one or more APB6 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
 * \param  peripheral    Specifies the APB6 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST6MASKS
 */
extern void RCC_resetApb6Peripheral (uint32_t peripheral);

/**
 * \brief  Reset the specified APB8 peripheral(s).
 * \note   This function resets one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral reset request.
 * \param  peripheral    Specifies the APB8 peripheral(s) to be reset.
 *                        This parameter is a combination of values from @ref RCC_APBRST8MASKS
 */
extern void RCC_resetApb8Peripheral (uint32_t peripheral);

/**
 * \brief  Enable the specified AHB1 peripheral(s) clock.
 * \note   This function enables the clock for one or more AHB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock enable request.
 * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN1MASKS
 */
extern void RCC_enableAhb1PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified AHB2 peripheral(s) clock.
 * \note   This function enables the clock for one or more AHB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock enable request.
 * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN2MASKS
 */
extern void RCC_enableAhb2PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified APB1 peripheral(s) clock.
 * \note   This function enables the clock for one or more APB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock enable request.
 * \param  peripheral    Specifies the APB1 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN1MASKS
 */
extern void RCC_enableApb1PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified APB2 peripheral(s) clock.
 * \note   This function enables the clock for one or more APB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock enable request.
 * \param  peripheral    Specifies the APB2 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN2MASKS
 */
extern void RCC_enableApb2PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified APB3 peripheral(s) clock.
 * \note   This function enables the clock for one or more APB3 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock enable request.
 * \param  peripheral    Specifies the APB3 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN3MASKS
 */
extern void RCC_enableApb3PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified APB5 peripheral(s) clock.
 * \note   This function enables the clock for one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock enable request.
 * \param  peripheral    Specifies the APB5 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN5MASKS
 */
extern void RCC_enableApb5PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified APB6 peripheral(s) clock.
 * \note   This function enables the clock for one or more APB6 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock enable request.
 * \param  peripheral    Specifies the APB6 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN6MASKS
 */
extern void RCC_enableApb6PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified APB8 peripheral(s) clock.
 * \note   This function enables the clock for one or more APB8 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock enable request.
 * \param  peripheral    Specifies the APB8 peripheral(s) clock to be enabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN8MASKS
 */
extern void RCC_enableApb8PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified AHB1 peripheral(s) clock.
 * \note   This function disables the clock for one or more AHB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock disable request.
 * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN1MASKS
 */
extern void RCC_disableAhb1PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified AHB2 peripheral(s) clock.
 * \note   This function disables the clock for one or more AHB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock disable request.
 * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_HCLKEN2MASKS
 */
extern void RCC_disableAhb2PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified APB1 peripheral(s) clock.
 * \note   This function disables the clock for one or more APB1 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock disable request.
 * \param  peripheral    Specifies the APB1 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN1MASKS
 */
extern void RCC_disableApb1PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified APB2 peripheral(s) clock.
 * \note   This function disables the clock for one or more APB2 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock disable request.
 * \param  peripheral    Specifies the APB2 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN2MASKS
 */
extern void RCC_disableApb2PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified APB3 peripheral(s) clock.
 * \note   This function disables the clock for one or more APB3 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock disable request.
 * \param  peripheral    Specifies the APB3 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN3MASKS
 *                       Possible values include:
 */
extern void RCC_disableApb3PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified APB5 peripheral(s) clock.
 * \note   This function disables the clock for one or more APB5 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock disable request.
 * \param  peripheral    Specifies the APB5 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN5MASKS
 */
extern void RCC_disableApb5PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified APB6 peripheral(s) clock.
 * \note   This function disables the clock for one or more APB6 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock disable request.
 * \param  peripheral    Specifies the APB6 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN6MASKS
 */
extern void RCC_disableApb6PeripheralClock (uint32_t peripheral);

/**
 * \brief  Disable the specified APB8 peripheral(s) clock.
 * \note   This function disables the clock for one or more APB8 peripherals based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock disable request.
 * \param  peripheral    Specifies the APB8 peripheral(s) clock to be disabled.
 *                        This parameter is a combination of values from @ref RCC_PCLKEN8MASKS
 */
extern void RCC_disableApb8PeripheralClock (uint32_t peripheral);

/**
 * \brief  Enable the specified AHB1 peripheral(s) clock in sleep mode.
 * \note   This function enables the clock for one or more AHB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock enable request in sleep mode.
 * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN1MASKS
 */
extern void RCC_enableAhb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Enable the specified AHB2 peripheral(s) clock in sleep mode.
 * \note   This function enables the clock for one or more AHB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock enable request in sleep mode.
 * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN2MASKS
 *                       Possible values include:
 */
extern void RCC_enableAhb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Enable the specified APB1 peripheral(s) clock in sleep mode.
 * \note   This function enables the clock for one or more APB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock enable request in sleep mode.
 * \param  peripheral    Specifies the APB1 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN1MASKS
 */
extern void RCC_enableApb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Enable the specified APB2 peripheral(s) clock in sleep mode.
 * \note   This function enables the clock for one or more APB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock enable request in sleep mode.
 * \param  peripheral    Specifies the APB2 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN2MASKS
 */
extern void RCC_enableApb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Enable the specified APB3 peripheral(s) clock in sleep mode.
 * \note   This function enables the clock for one or more APB3 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock enable request in sleep mode.
 * \param  peripheral    Specifies the APB3 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN3MASKS
 */
extern void RCC_enableApb3PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Enable the specified APB5 peripheral(s) clock in sleep mode.
 * \note   This function enables the clock for one or more APB5 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock enable request in sleep mode.
 * \param  peripheral    Specifies the APB5 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN5MASKS
 */
extern void RCC_enableApb5PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Enable the specified APB6 peripheral(s) clock in sleep mode.
 * \note   This function enables the clock for one or more APB6 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock enable request in sleep mode.
 * \param  peripheral    Specifies the APB6 peripheral(s) clock to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN6MASKS
 */
extern void RCC_enableApb6PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Enable the specified APB8 peripheral(s) in sleep mode.
 * \note   This function enables one or more APB8 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral enable request in sleep mode.
 * \param  peripheral    Specifies the APB8 peripheral(s) to be enabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN8MASKS
 */
extern void RCC_enableApb8PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified AHB1 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more AHB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB1 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the AHB1 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN1MASKS
 */
extern void RCC_disableAhb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified AHB2 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more AHB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific AHB2 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the AHB2 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_HCLKLPEN2MASKS
 *                       Possible values include:
 */
extern void RCC_disableAhb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified APB1 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more APB1 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB1 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the APB1 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN1MASKS
 */
extern void RCC_disableApb1PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified APB2 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more APB2 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB2 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the APB2 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN2MASKS
 */
extern void RCC_disableApb2PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified APB3 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more APB3 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB3 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the APB3 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN3MASKS
 */
extern void RCC_disableApb3PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified APB5 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more APB5 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB5 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the APB5 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN5MASKS
 */
extern void RCC_disableApb5PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified APB6 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more APB6 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB6 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the APB6 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN6MASKS
 */
extern void RCC_disableApb6PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Disable the specified APB8 peripheral(s) clock in sleep mode.
 * \note   This function disables the clock for one or more APB8 peripherals in sleep mode based on the provided bitmask.
 *         Each bit in the bitmask corresponds to a specific APB8 peripheral clock disable request in sleep mode.
 * \param  peripheral    Specifies the APB8 peripheral(s) clock to be disabled in sleep mode.
 *                        This parameter is a combination of values from @ref RCC_PCLKLPEN8MASKS
 */
extern void RCC_disableApb8PeripheralClockInSleepMode (uint32_t peripheral);

/**
 * \brief  Configure the High-Speed External Crystal Oscillator (HXTL) settings.
 * \note   This function configures the HXTL based on the provided configuration parameters.
 *         It ensures that the system clock is not using HXTL before disabling it and re-enabling it with new settings.
 * \param  config        Specifies the configuration settings for the HXTL.
 *                        This parameter is a combination of values from @ref HXTLCONFIG
 * \param  hxtlBypass    Specifies whether to enable or disable the HXTL bypass mode.
 *                        This parameter can be one of the values from @ref RCC_HXTLBYPASSSEL
 * \param  hxtlSts       Specifies whether to enable or disable the HXTL.
 *                        This parameter can be any value of @ref RCC_FUNON
 * \return Returns 0 if the hxtl configuration is successful, otherwise returns 1.
 */
extern uint32_t RCC_configHxtl (uint32_t config, RCC_HxtlBypassSel hxtlBypass, RCC_FunOn hxtlSts);


/**
 * \brief  Configure the MIRC2 Oscillator Stop Detection.
 * \note   This function configures the MIRC2 oscillator stop detection based on the provided status.
 * \param  config    Specifies the configuration settings for the MIRC2.
 *                    This parameter is a combination of values from @ref RCC_MIRC1MIRC2CYCSELECTION.
 * \param  mcdSts    Specifies the enable or disable status of the MCD (Main Clock Divider).
 *                    This parameter can be any value of @ref RCC_FUNON
 */
extern void RCC_configMcd (RCC_Mirc1Mirc2CycSelection config, RCC_FunOn mcdSts);


#ifdef __cplusplus
}
#endif


#endif /* __RCC_H__ */
