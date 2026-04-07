#ifndef __F_DEBUG_H__
#define __F_DEBUG_H__

#include "TI_type_adapter.h"
#include "SystemDefine.h"
//=====================================================================
#if defined(DSP2803X)
#define DSP_2803X  1      // 28035
#elif 1
#define DSP_2803X  1

#endif
//=====================================================================



//=====================================================================
#if defined(FUNC_DEBUG_RAM)         // 仅调试功能，在CCS的build option中定义的宏
#define F_DEBUG_RAM             1   // 功能在RAM中调试
#elif 1
#define F_DEBUG_RAM             0   // 不在RAM中调试
#endif
//=====================================================================



//=====================================================================
// 专机，MD380M/IS380
#if !defined(ZJ_MD380M)
#define DEBUG_F_POSITION_CTRL   0   // 不包含位置控制
#elif 1
#define DEBUG_F_POSITION_CTRL   1   // 包含位置控制
#endif
//=====================================================================




//=====================================================================
// 注意EEPROM的大小
//#define DEBUG_F_MOTOR_FUNCCODE    0   // 不预留功能码给性能调试
#define DEBUG_F_MOTOR_FUNCCODE    1   // 预留功能码给性能调试
//=====================================================================

#define DEBUG_F_PLC_CTRL          1
#define DEBUG_F_P2P_CTRL          1

//#if F_DEBUG_RAM && (!defined(_lint))
#if 1
#define LOCALF
#define LOCALD extern
#else
#define LOCALF static
#define LOCALD static
#endif
// LOCALD stands for local Declaration.
// LOCALF stands for local deFinition.


//=====================================================================

#if DSP_CLOCK == 200
#define TIME_10US       ((DSP_CLOCK/8) * 10UL)    // 算出来是: 25 * 10 = 250
#define TIME_50US       ((DSP_CLOCK/8) * 50UL)    // 算出来是: 25 * 50 = 1250
#define TIME_100US      ((DSP_CLOCK/8) * 100UL)   // 算出来是: 25 * 100 = 2500 
#define TIME_1MS        ((DSP_CLOCK/8) * 1000UL)  // 算出来是: 25 * 1000 = 25000 

#endif
//=====================================================================

// dest的bit1 = source的bit2
#define BitAssign(source, bit1, dest, bit2)     \
{                                               \
    if ((source) & (0x1UL << (bit1)))           \
        (dest) |= (0x1UL << (bit2));            \
    else                                        \
        (dest) &= (~(0x1UL << (bit2)));         \
}


//void BitAssign(Uint32 source, Uint32 *dest, int16 bit);

Uint16 qsqrt(Uint32 data);


void UniversalDebug(Uint16 sn);  // 通用测试函数


#if F_DEBUG_RAM
void UniversalDebug32(Uint32 a);
void PowerOnDebug(Uint16 value);

extern Uint16 daValue[];
void InitDa(void);
void UpdateDaBuffer(Uint16 port);
void DaOut(Uint16 port);
#endif


#endif  // #ifndef __F_DEBUG_H__



