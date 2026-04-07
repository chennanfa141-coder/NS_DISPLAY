//======================================================================
//
// Time-stamp: <2012-12-20 14:01:46  Shisheng.Zhi, 0354>
//
// UI, user interface
// 目前为 显示处理, 键盘处理
//
//======================================================================
#include "gpio.h"
#include "spi.h"
//#include "TI_type_adapter.h"
#include "f_ui.h"
#include "f_debug.h"
#include "f_menu.h"
#include "f_frqSrc.h"
//#include "f_comm.h"
#include "f_runSrc.h"
#include "f_io.h"
#include "f_error.h"

Uint16 flashMaxSDSD = 10;

#if F_DEBUG_RAM

#define DEBUG_F_KEY_ANIMATE                     0   // 模拟按键调试
#define DEBUG_F_NEWMENU_USE_DOT_REVERSE_DIR     0   // 最右边数码管的小数点，表示设定频率反向；
                                                    // 最左边数码管的小数点，表示瞬时频率反向
#define DEBUG_F_ERROR_INDICATION                1   // 故障指示灯，目前使用tune/tc快速闪烁
#elif 1

#define DEBUG_F_KEY_ANIMATE                     0   // 模拟按键调试
#define DEBUG_F_NEWMENU_USE_DOT_REVERSE_DIR     0

//+=M
#define DEBUG_F_ERROR_INDICATION                1   // 故障指示灯，目前使用tune/tc快速闪烁
#endif

//=============================================================================
//
// 外置/内置键盘判断
//
//=============================================================================
#if DSP_2803X
#define KEY_SEL_TEST_TIME  750   // 350*2ms
Uint16 keySelStatus;
Uint16 keySelType;
Uint16 keySelTypeBak;
Uint16 keyChecking;
#endif

struct SPI_IN_OUT spiData;

const Uint16 dispCodeMenuMode[6][4] = 
{
    {DISPLAY_F,     DISPLAY_u,      DISPLAY_n,      DISPLAY_C},     // Func base
    {DISPLAY_U,     DISPLAY_5,      DISPLAY_E,      DISPLAY_t},     // Uset user
    {DISPLAY_U,     DISPLAY_LINE,   DISPLAY_LINE,   DISPLAY_C},     // U--C --C--
};

Uint16 onQuickTicker;               // 按键QUICK
Uint16 onQuickTickerMax = 1000;     // *2ms

Uint16 onShiftPassViewTicker;
Uint16 onShiftPassViewTickerMax = 1000;

Uint16 factoryPwd = 0;

typedef struct
{
    Uint16 ctrlCnt;     // 上档键的个数
    Uint16 ctrlVal;     // 最后扫描到的上档键的值
    Uint16 funcCnt;     // 功能键的个数
    Uint16 funcVal;     // 最后扫描到的功能键的值
} keyRet;

// 定义显示字符段码
const Uint16 DISPLAY_CODE[DISPLAY_8LED_CODE_NUM]=
{   0xc0,   0xf9,   0xa4,   0xb0,   0x99,   // 0-4
//  0,      1,      2,      3,      4,  
    0x92,   0x82,   0xf8,   0x80,   0x90,   // 5-9
//  5,      6,      7,      8,      9,  
    0x88,   0x83,   0xc6,   0xa1,   0x86,   // 10-14
//  A,      b,      C,      d,      E,
    0x8e,   0x8c,   0x89,   0xf1,   0xc7,   // 15-19
//  F,      P,      H,      J       L,             
    0xAB,   0xaf,   0xc1,   0x91,   0xc2,   // 20-24 
//  n,      r,      U,      y,      G, 
    0x8b,   0xcf,   0xc8,   0xa3,   0x98,   // 25-29   
//  h,      I,      N,      o,      q       
    0xce,   0x87,   0xe3,   0xff,   0xbf,   // 30-34
//  T,      t,      u/v     全灭,   - 
    0x7f,   0x00,   0xa7                    // 35-37
//  小数点, 全亮8.  小写c
};

// LED
const Uint16 LED_CODE[DISPLAY_LED_CODE_NUM] =
{0xBF,   0xDF,  0xEF, 0xF7, 0xFB, 0xFD, 0xFE, 0xFC, 0xF9, 0x80, 0xFF};
//Run,  Local,  Dir,  TUNE,    V,    A,   Hz,  RPM,    %, 全亮, 全灭


// 程序中关于8LED(数码管)的位数：
// 应该统一的!
//
// 数码管:           口口口口口
// displayBuffer:    0 1 2 3 4
// digit:            4 3 2 1 0
// operateDigit:     4 3 2 1 0
// scanStep:         0 1 2 3 4  5
// scanStep为0，扫描显示最左边的数码管
// scanStep为5，扫描显示led灯
// winkFlag:    bit7,数码管左边第1个(最左边); bit3, 数码管左边第5个(最右边)
// winkFlagLed: bit0-Led0;bit1-Led1,...(LED_RUN, ...)
//



Uint16 displayBuffer[DISPLAY_8LED_NUM + 1] = {0xbf, 0x89, 0xBF, 0xC6, 0xbf, 0x80};    // -H-C-, LED全亮

 
Uint16 scanStep;        //  当前扫描,显示第scanStep(0-4)个数码管和LED
// 8LED:        口口口口口 led
// scanStep:    0 1 2 3 4  5
// scanStep为0，扫描显示最左边的数码管
// scanStep为5，扫描显示led灯

Uint16 keyBordTestFlag;     // 键盘测试标志  0-不启动按键测试  1-启动按键测试
Uint16 keyBordValue;        // 记录已按键信息

LOCALF Uint16 keyPreFunc;       // 当前功能键值
Uint16 keyPreCtrl;              // 当前上档键值
Uint16 keyFunc;                 // 

LOCALF Uint16 keyAge;           // 按键年龄，即按键持续的时间
LOCALF Uint16 bKeyEsc;          // 按键释放标志。0--已释放
LOCALF Uint16 bKeyProc;         // 按键有效标志。1--按键执行

enum KEY_STATUS
{
    KEY_STATUS_JITTER_DEAL,     // 去抖阶段
    KEY_STATUS_WAIT_REPEAT,     // 重复前的延缓阶段
    KEY_STATUS_REPEAT,          // 正在重复的阶段
    KEY_STATUS_WAIT_CARRY       // 连击进位的暂停阶段
};
LOCALF enum KEY_STATUS keyStatus;   // 按键状态

//union DI_HW_STATUS diHwStatus;              // DI的硬件状态，瞬时的DI状态
LOCALF Uint16 keyValue;         // 键盘输入

enum EN_FLASH
{
    FLASH_YES,
    FLASH_NO
};
LOCALF enum EN_FLASH bEnflash;         // 允许闪烁总标志。默认为闪烁
LOCALF Uint16 flashTicker[DISPLAY_8LED_NUM];
LOCALF Uint16 bLight[DISPLAY_8LED_NUM];     // 闪烁的亮灭标志。1-亮，0-灭。
LOCALF Uint16 flashTickerLed[DISPLAY_LED_NUM];

#if 0
LOCALF const Uint16 flashTickerMax[DISPLAY_8LED_NUM] = {40, 40, 40, 40, 40}; // 闪烁时间 _ * 6 * 2ms
LOCALF const Uint16 flashTickerLedMax[DISPLAY_LED_NUM] = {45, 45, 45, 45, 45};
#elif 1       // 使用define即可。这里不需要不同的闪烁时间
#define flashTickerMax      42      // 闪烁(一闪一灭)时间，42*6*2*2ms = 1008ms
#define flashTickerLedMax   45      // 闪烁(一闪一灭)时间，45*6*2*2ms = 1080ms
#endif

#define keyAgeMax   20          // 按键的去抖处理延迟时间, *2ms
// 2008-12-26，键盘去抖处理延迟时间改为50ms

#define maxRate     100         // 可以连击的按键重复前的延迟时间, *2ms
#define continueKeyFlag ((1 << KEY_UP) | (1 << KEY_DOWN))   // 定义连击键，对应位为1的是连击键
//#define continueKeyFlag ((1 << KEY_UP) | (1 << KEY_DOWN) | (1 << KEY_QUICK))   // 定义连击键，对应位为1的是连击键

#define ctrlKeyFlag     0           // 定义上档键，对应位为1的是上档键


#define minRatePause    100         //400; // 连击暂停
//LOCALF const Uint16 minRatePause = 250; //400; // 连击暂停
LOCALF const Uint16 minRate[5] = {50, 80, 130, 180, 200};// {80, 90, 120, 100, 110};
LOCALF const Uint16 repeatNumMax[5] = {9, 9, 9, 9, 9};
LOCALF Uint16 repeatNum;    // 在连击时，重复次数
LOCALF Uint16 repeatStep;
LOCALF Uint16 bOnShift;     // 按键shift
Uint16 upDownDelta;         // 键盘UP/DOWN的增量

#if DEBUG_F_KEY_ANIMATE
Uint16 keyAnimateTime = 0;
Uint16 keyAnimateTime1 = 50;
Uint16 keyAnimateTimeAll = 500;
#endif

void UpdateMenuModeDisplayBuffer();


//=====================================================================
//
// 更新显示数据缓冲
//
// 1. RUN, LOCAL/REMOTE灯的更新
// 2. 更新数据缓冲(显示数据,单位,闪烁命令字)
//    仅一遍显示扫描完成(即6*2ms更新一次)，才更新数据
//
//=====================================================================
extern void Menu1OnPrg(void);
extern Uint16 checkMenuModePara;
extern Uint16 checkMenuModeCmd;
extern void DealCheckMenuModeGroupGrade(Uint16 flag);
void UpdateDisplayBuffer(void)
{
	#if 1
// RUN灯的更新
    displayBuffer[5] |= ~LED_CODE[LED_RUN]; // 灭
    if (runFlag.bit.run)    // 应该以此为准。在减速直流制动等待时间，dspStatus.bit.run = 0
    {
        displayBuffer[5] &= LED_CODE[LED_RUN];  // 亮
    }

// LOCAL/REMOTE灯
    menuAttri[menuLevel].winkFlagLed &= ~(0x1U << LED_LOCAL);  // local不闪烁
    if (FUNCCODE_runSrc_DI == runSrc)
    {
        displayBuffer[5] &= LED_CODE[LED_LOCAL];  // 亮
    }
    else if (FUNCCODE_runSrc_COMM == runSrc)
    {
        menuAttri[menuLevel].winkFlagLed |= (0x1U << LED_LOCAL); // local闪烁
    }
    else //if (FUNCCODE_runSrc_PANEL == runSrc) // 面板或自动运行
    {
        displayBuffer[5] |= ~LED_CODE[LED_LOCAL]; // 灭
    }

// FWD/REV灯
    if (runFlag.bit.dirReversing)  // 正反转切换时闪烁
    {
        menuAttri[menuLevel].winkFlagLed |= (0x1U << LED_DIR); // tune闪烁
    }
    else
    {
        displayBuffer[5] |= ~LED_CODE[LED_DIR]; // 灭

        if (REVERSE_DIR == runFlag.bit.dir)
        { 
        displayBuffer[5] &= LED_CODE[LED_DIR];  // 亮 
        }
    }
    
// TUNE/TC灯
    menuAttri[menuLevel].winkFlagLed &= ~(0x1U << LED_TUNE);  // local不闪烁
    if ((tuneCmd)   // 调谐时一直闪烁
#if DEBUG_F_ERROR_INDICATION
        || errorCode
#endif
        )
    {
        menuAttri[menuLevel].winkFlagLed |= (0x1U << LED_TUNE); // tune闪烁
    }
    else if (runMode == RUN_MODE_TORQUE_CTRL)
    {
        displayBuffer[5] &= LED_CODE[LED_TUNE];  // 亮
    }
    else
    {
        displayBuffer[5] |= ~LED_CODE[LED_TUNE]; // 灭
    }
#if 0
    DispDataDeal();         // 每拍都扫描
#endif
    if (checkMenuModeCmd)   // 有check菜单模式的搜索命令
    {
        DealCheckMenuModeGroupGrade(checkMenuModePara);
    }

    //if (errorCodeOld != errorCode)
    if ((!errorCodeOld) 
        && (errorCode)     // 非0级菜单，发生故障时，到0级菜单显示故障
        && ((errAutoRstNum == 0) 
            || (errAutoRstNum == funcCode.code.errAutoRstNumMax) 
            || (funcCode.code.errAutoRstNumMax == 0))  // 故障自动复位次数为0或当前复位次数为0
        )
    {
        Menu1OnPrg();
    }

// 一遍扫描完成，才更新数据缓冲
    if (!scanStep)      // 目前12ms更新一次
    {
// 显示数据，单位的更新
        displayBuffer[5] |= ~LED_CODE[LED_HZ];  // 默认单位灯全灭
        displayBuffer[5] |= ~LED_CODE[LED_A];
        displayBuffer[5] |= ~LED_CODE[LED_V];

        menuAttri[menuLevel].winkFlag = 0;    // 数码管默认不闪烁

        if (MENU_MODE_NONE == menuModeStatus)
        {
            menu[menuLevel].UpdateDisplayBuffer();
        }
        else    // 显示菜单模式
        {
            UpdateMenuModeDisplayBuffer();
        }
    }
		#endif
}


//=====================================================================
//
// LED和数码管的闪烁处理
//
// 1. 根据winkFlag，更新数码管的闪烁
// 2. 根据winkFlagLed，更新LED的闪烁
//
//=====================================================================
void WinkDeal(void)
{
	#if 1
    static Uint16 enflashOld;
    static Uint16 winkFlagOld;
    static Uint16 menuLevelOld;
    static Uint16 winkFlagLedOld;
    Uint16 winkFlag1 = menuAttri[menuLevel].winkFlag;
    Uint16 winkFlagLed1 = menuAttri[menuLevel].winkFlagLed;
    int16 i;

#if DSP_2803X
    if (keyChecking == 1)
    {
        return;
    }
#endif
    
// SPI要发送的数据，包括DO,显示
#if DSP_2803X        // 2803x还是2808平台
    spiData.out.a.bit.dispCode = displayBuffer[scanStep]; // 显示位码更新
#else
    spiData.out.a.bit.doData = (doHwStatus.all);   // 低8位，DO输出，包括继电器
    spiData.out.a.bit.dispCode = displayBuffer[scanStep]; // 显示位码更新
#endif
    

// 闪烁控制
    // 如果闪烁标志(bEnflash,位控制寄存器)改变了，或者菜单级别改变了，闪烁时间和显示状态要重新初始化
    if ((winkFlagOld != winkFlag1)
        || (menuLevelOld != menuLevel)
        || (enflashOld != bEnflash)
        )
    {
        for (i = DISPLAY_8LED_NUM - 1; i >= 0; i--)
        {
            // 闪烁初始为灭1/4正常时间
            if ((bOnShift)       // 按键shift
//                || (!(winkFlag1 & 0x01))
                )
            {
                bLight[i] = 0;
//                flashTicker[i] = flashTickerMax[i] >> 2;
                flashTicker[i] = flashTickerMax >> 2;
            }
            else
            {
                bLight[i] = !0;
//                flashTicker[i] = flashTickerMax[i] >> 2;
                flashTicker[i] = flashTickerMax >> 2;
            }
        }
    }
    
// 某个灯的闪烁改变了，该灯状态置反
// 仅该灯取反，其余灯不必
    if (winkFlagLedOld != winkFlagLed1)
    {
        for (i = DISPLAY_LED_NUM - 1; i >= 0; i--)
        {
            if ((winkFlagLed1 ^ winkFlagLedOld) & (0x01U << i))
            {
                flashTickerLed[i] = 0;
                //displayBuffer[5] &= LED_CODE[i];  // 亮
                displayBuffer[5] ^= ~LED_CODE[i];   // 取反
            }
        }
        
        winkFlagLedOld = winkFlagLed1;
    }

    winkFlagOld = winkFlag1;
    winkFlagLedOld = winkFlagLed1;
    menuLevelOld = menuLevel;
    enflashOld = bEnflash;

    if (scanStep < DISPLAY_8LED_NUM)    // 数码管的闪烁
    {
        if ((FLASH_YES == bEnflash) && (winkFlag1 & (0x01U << (7 - scanStep))))
        {
//            if (++flashTicker[scanStep] >= flashTickerMax[scanStep])
            if (++flashTicker[scanStep] >= flashTickerMax)
            {
                flashTicker[scanStep] = 0;
                bLight[scanStep] = !bLight[scanStep];
            }

            if (!bLight[scanStep])
            {
                spiData.out.a.bit.dispCode = DISPLAY_CODE[DISPLAY_NULL];    // 灭
            }
        }
    }
    else                                // LED灯的闪烁
    {
        Uint16 flashMax;
        
        for (i = DISPLAY_LED_NUM - 1; i >= 0; i--)  // 仅有一个灯需要闪烁，所以这里不需要。除非需要几个灯的闪烁同步。
        {
					#if 1
#if DEBUG_F_ERROR_INDICATION    // 故障提示的闪烁
					
            flashMax = flashTickerLedMax;
            
            if (((i == LED_TUNE)
                && (errorCode))
#if 0   // 命令源自动运行
                || ((i == LED_LOCAL)
                    && (FUNCCODE_runSrc_AUTO_RUN == runSrc))
#endif
                )
            {
                flashMax = flashMaxSDSD;
                
                if (++flashTickerLed[i] >= flashMax)
                {
                    flashTickerLed[i] = 0;
                    displayBuffer[5] ^= ~LED_CODE[i];   //   
                }
            }
            else
#endif

            if (winkFlagLed1 & (0x01U << i))
            {
//                if (++flashTickerLed[i] >= flashTickerLedMax[i])
                if (++flashTickerLed[i] >= flashMax)
                {
                    flashTickerLed[i] = 0;
                    displayBuffer[5] ^= ~LED_CODE[i];   //
                }
            }
						#endif
        }
    }

#if DEBUG_F_NEWMENU_USE_DOT_REVERSE_DIR // 最右边数码管的小数点，表示设定频率反向；最左边数码管的小数点，表示瞬时频率反向
    if (((0 == scanStep) && runFlag.bit.curDir)     // frq, 瞬时频率
        || ((4 == scanStep) && runFlag.bit.dir))    // frqAim, 设定(目标)频率
    {
        spiData.out.a.bit.dispCode &= (DISPLAY_CODE[DISPLAY_DOT]);
    }
#endif
#endif
}



//==========================================================================================================
//
// 显示扫描准备，其实是SPI的接收，以及更新显示段码
//
//              XXXXX led
// scanStep:    01234 5
// scanStep为0，扫描显示最左边的数码管
// scanStep为5，扫描显示led灯
//
// RCK的作用：
// 0 -- input(74HC165):Parallel Load; output(74HC594):Storage register state is not changed
//      input:  DSP接收数据完成(74HC165数据串行发送完成)，74HC165把DI、本机键盘、外引键盘
//              的数据并行load到内部的Q0-Q7，等待/PL(RCK)变成1，把数据串行发送出去。
//      output: DSP发送的数据完成(74HC594内部移位完成)，74HC594的Storage register数据不再改变。
// 1 -- input(74HC165):Serial Shift; output(74HC594):Contents of Shift Register transferred to output latches
//      input:  DSP开始接收74HC165串行发送的数据。3*8 bits
//      output: DSP开始向74HC594发送数据，74HC594开始移位。
//              74HC594把Shift Register传送到Storage register，即把上一次串行接收到的数据并行输出到Q0-Q7。
//
//==========================================================================================================
void DisplayScanPrepare(void)
{
	#if 1
    Uint16 RXFFST;
    int16 i;
    static int16 j;
    static Uint16 tcnt;
    
    RXFFST = SPI_getRxFIFOStatus(SPI1); // orig RXFFST = SpiaRegs.SPIFFRX.bit.RXFFST;
// RCK的切换需要延时一段时间(1us实验OK)，从这里到SPI发送之间的程序也起了延时作用。
    Delay_us(30);
#if DSP_2803X         // 2803x还是2808平台
    RCK_CLR();        // 发送完成，RCK置零
    
#else
    if (RXFFST >= SPI_LENGTH)    // 应该使用中断
    {
        RCK_CLR();        // 发送完成，RCK置零
    }
#endif

// 接收上次SPI通讯的数据。
    for (i = 0; i < RXFFST; i++)    // 接收到多少数据，读取多少数据
    {
      
			spiData.in.all[j] = SPI_readDataNonBlocking(SPI1);
#if DSP_2803X         // 2803x还是2808平台
            j = 0;
#else
        if (++j >= SPI_LENGTH)
            j = 0;
#endif
    }


#if DSP_2803X         // 2803x还是2808平台
    if (!keySelStatus)
    {
         keyValue = spiData.in.key >> 7;      // 键盘输入
    }
    // 2. 更新显示段码 
    spiData.out.a.bit.dispSect = 0x7F & (~(1U << (5 - scanStep)));
#else
    diHwStatus.all = ((spiData.in.c.di & 0x00FF) << 8) + (spiData.in.c.di >> 8); // DI输入，瞬时值
    keyValue = spiData.in.c.key >> 7;      // 键盘输入
    // 2. 更新显示段码
    spiData.out.b.bit.dispSect = 0x7F & (~(1U << (5 - scanStep)));
#endif
  // 段码，显示第i个数码管, JPXY = 1, FAN = 0;


// 外引/内置键盘判断
#if DSP_2803X         // 2803x还是2808平台
    keySelTypeBak = keySelType;
    if (!tcnt)
    {
        keySelType = 1;
        keySelStatus = 1;
    }
    else
    {
        if (keySelStatus)
        {
            (!(spiData.in.key >> 7)) ? (keySelType = 0) : (keySelType = 1);
            keySelStatus = 0;
        }
    }
	(tcnt >= KEY_SEL_TEST_TIME) ? (tcnt = 0) : (tcnt++);

    // 当前为内置键盘时切换判断是否有外引键盘
    // keyChecking为1时,键盘显示状态维持不变(防止内置键盘显示闪烁)
    if ((keySelType == 1) && (keySelTypeBak == 0))
    {
        keyChecking = 1;
    }
    else
    {
        keyChecking = 0;
    }
    
#endif

// 3. 更新scanStep
#if DSP_2803X
	if (!keyChecking)
#endif
	{
	    if (++scanStep >= DISPLAY_8LED_NUM + 1) // 一共有_个数码管，以及led灯
	    {
	        scanStep = 0;
	    }
	}
	#endif
}



//=====================================================================
//
// 发送显示扫描数据，即SPI发送
//
//=====================================================================
void DisplayScan(void)
{
	#if 1
// SPI发送, SPI的字符长度已设置为16，注意SPI是从高位开始发送
    RCK_SET();//orig RCK=1;
#if DSP_2803X               // 2803x还是2808平台
    GPIO_writePin(GPIOA, GPIO_PIN_19, keySelType);//orig KEYSEL = keySelType;    // 键盘选择(0-内置  1-外引)
    SPI_writeDataNonBlocking(SPI1, (~spiData.out.a.all));//orig SpiaRegs.SPITXBUF = ~spiData.out.a.all; //stamp MD380

#else
    SpiaRegs.SPITXBUF = spiData.out.b.all;   // SPI是从高位开始发送，高位为无效数据
    SpiaRegs.SPITXBUF = spiData.out.a.all;
#endif    
	#endif
}



//=====================================================================
//
// 根据接收到的键盘数据，判断是否有按键按下，哪个/哪些按键被按下
// 并判断是否需要调用相应函数
//
// 输入：keyVal -- 键盘值
// 输出：bKeyProc   -- 0，不需要调用相应函数；1，需要调用相应函数
//       keyPreFunc -- 按下的功能键键值
//       keyPreCtrl -- 按下的上档键键值
//
//=====================================================================
void KeyScan(void)
{
	#if 1
    keyRet keyTemp = {0, 0, 0, 0};
    int16 j = 0;
    Uint16 keyValueTmp;
//     static Uint16 repeatNum = 0;
//     static Uint16 repeatStep = 0;
#if DEBUG_F_KEY_ANIMATE
    keyValue = (~((0x1U << (KEY_UP - 1)))) & ((1 << KEY_NUM) - 1);
#endif

    keyValueTmp = ((~keyValue) & ((1 << KEY_NUM) - 1)) << 1;
    if (keyValueTmp)     // 有键按下
    {
        for (j = KEY_NUM; j >= 1; j--)
        {
            if ((keyValueTmp & (0x01U << j)))     // 第j位
            {
                if (((keyValueTmp) & ctrlKeyFlag) && (ctrlKeyFlag == (0x01 << j)))  // 该键是上档键
                {
                    keyTemp.ctrlCnt++;      // 上档键个数加1
                    keyTemp.ctrlVal = j;    // 将键值存入上档键键值缓冲
                }
                else                        // 该键是功能键
                {
                    keyTemp.funcCnt++;      // 功能键个数加1
                    keyTemp.funcVal = j;    // 将键值存入功能键键值缓冲
                }
            }
        }
    }

    if ((!keyTemp.funcCnt) || (keyTemp.ctrlCnt > 1)) // 无功能键按下,或者,同时按下的上档键个数多于1个
    {
        keyPreFunc = 0;
        keyPreCtrl = 0;             // 上次功能键和上次上档键缓冲清零
        keyFunc = 0;                // 这里主要是清点动命令
        keyAge = 0;                 // 按键年龄计数器
        keyStatus = KEY_STATUS_JITTER_DEAL;   // 按键状态
        bKeyEsc = 0;                // 按键释放标志
        bEnflash = FLASH_YES;       // 允许闪烁
#if 1
        accDecFrqPrcFlag = ACC_DEC_FRQ_NONE;
#endif
        upDownDelta = 1;
    }
    else if (!bKeyEsc)                  // 按键已经释放
    {
        if (keyTemp.funcCnt > 1)        // 有多于一个功能键按下，置位按键释放标志
            bKeyEsc = 1;
        else if ((keyTemp.funcVal != keyPreFunc)
                 || ((keyTemp.ctrlVal != keyPreCtrl) && keyPreCtrl)
                 )
                // 本次功能键值与上次不同
                // 或者，本次上档键值和上次不同且上次有上档键
        {
            keyPreFunc = keyTemp.funcVal;   // 用本次键值更新上次键值
            keyPreCtrl = keyTemp.ctrlVal;
            keyAge = 0;                     // 按键年龄清零
        }
        else if ((!keyPreCtrl) && keyTemp.ctrlVal)// 2次功能键相同，上次无上档键本次有
        {
            bKeyEsc = 1;    // 屏蔽: 先按下功能键，再按上档键这种按键组合
        }
        else
        {
            keyAge++;                           // 2次功能键和上档键都相同
            switch (keyStatus)
            {
                case KEY_STATUS_JITTER_DEAL:    // 去抖阶段
                    if (keyAge >= keyAgeMax)    // 完成键盘去抖处理
                    {
                        bKeyProc = 1;           // 进行键值处理
                        if ((((continueKeyFlag) & (0x01U << keyTemp.funcVal)) == 0)  // 或者，该功能键不允许连击
                         // || (keyTemp.ctrlCnt == 1)  // 是一对复合键，
                            )
                            bKeyEsc = 1;
                        else
                        {
                            keyStatus = KEY_STATUS_WAIT_REPEAT;   // 按键状态进入重复前的延缓阶段
                            keyAge = 0;         // 按键年龄清零
                        }
                    }
                    break;

                case KEY_STATUS_WAIT_REPEAT:    // 重复前的延缓阶段
                    if (keyAge >= maxRate)      // 按键年龄达到可以重复的时间
                    {
                        bKeyProc = 1;           // 进行键值处理
                        keyAge = 0;             // 按键年龄清零
                        keyStatus = KEY_STATUS_REPEAT;   // 按键状态进入重复阶段
                        repeatNum = 0;
                        repeatStep = 0;
                    }
                    break;

                case KEY_STATUS_REPEAT:         // 重复阶段
                    if (keyAge >= minRate[repeatStep])      // 按键年龄到
                    {
                        keyAge = 0;             // 按键年龄清零
                        bKeyProc = 1;           // 进行键值处理
                        repeatNum++;
#if 1
                        if (bFrqDigital)
                        {
                            // 在连击次数达到repeatNumMax[]之后，暂停一段时间
                            if (repeatNum >= repeatNumMax[repeatStep]) 
                            {
                                if (repeatStep < 2)
                                {
                                    bKeyProc = 0;           // 不进行键值处理
                                    keyStatus = KEY_STATUS_WAIT_CARRY;   // 按键状态进入连击进位的暂停阶段
                                }
                            }
                        }
#endif
                    }
                    break;

                case KEY_STATUS_WAIT_CARRY:     // 连击进位的暂停阶段
                    if (keyAge >= minRatePause) // 按键年龄到
                    {
                        keyAge = 0;             // 按键年龄清零
                        bKeyProc = 1;           // 进行键值处理
                        keyStatus = KEY_STATUS_REPEAT;   // 按键状态进入重复阶段
                        upDownDelta *= 10;
                        repeatStep++;
                        repeatNum = 0;
                    }
                    break;

                default:
                    break;
            }
        }
    }

#if DEBUG_F_KEY_ANIMATE
    {
        static Uint16 i;
        if (++i >= keyAnimateTime)     // __*2ms
        {
            bKeyProc = 1;
            keyPreFunc = KEY_UP;
            i = 0;
        }
    }
#endif
#endif
}


//=====================================================================
//
// 键盘测试
// 当通讯有指令发送过来时，开始测试每个按键是否均已按下
//
//=====================================================================
void KeyBordTest(void)
{
	#if 1
    // 验证是否按下所有的按键
    if (keyBordTestFlag)
    {
        // 每次有按键时，记录该按键已按下标志
        if (keyPreFunc)
        {
            keyBordValue |= (1<<(keyPreFunc - 1));
        }
    }
    else
    {
        keyBordValue = 0;
    }
	#endif
}

//=====================================================================
//
// 键盘处理函数
// 根据哪一个按键被按下，调用相应函数
// 输入：bKeyProc   -- 是否有按键需要处理。1，有；0，无。若有，调用之后要清零
//       keyPreFunc -- 按键
// 输出：无
//
//=====================================================================
void KeyProcess(void)
{
	#if 1
    KeyBordTest();
    
    if ((KEY_REV_JOG != keyFunc) && (KEY_FWD_JOG != keyFunc))
    {
        keyFunc = 0;        // 每2ms都清零。2ms内没有处理，除非有新的按键，否则不作处理
    }

    if (!bKeyProc)          // 如果没有按键需要处理
    {

        // 菜单模式切换QUICK键处理
        if (MENU_MODE_ON_QUICK == menuModeStatus)
        {
            if (++onQuickTicker >= onQuickTickerMax)
            {
                onQuickTicker = 0;

                menuModeStatus = MENU_MODE_NONE;
                menuModeTmp = menuMode;  // 恢复menuMode
            }
        }

#if DEBUG_RANDOM_FACPASS  
        // 密码明文显示
        if (facPassViewStatus == FAC_PASS_VIEW)
        {
            if (++onShiftPassViewTicker >= onShiftPassViewTickerMax)
            {
                onShiftPassViewTicker = 0;
                facPassViewStatus = FAC_PASS_NONE;
            }
        }
#endif
        
        return;
    }
    
    bKeyProc = 0;
    bOnShift = 0;           // 有新的非shift按键时该标志才清零
    keyFunc = keyPreFunc;

    if ((MENU_MODE_ON_QUICK == menuModeStatus) &&
        (KEY_QUICK != keyPreFunc) && 
        ((KEY_ENTER != keyPreFunc) 
//        || ((KEY_ENTER == keyPreFunc) && (MENU_LEVEL_0 != menuLevel))
        )
        )
    {
        onQuickTicker = 0;

        menuModeStatus = MENU_MODE_NONE;
        menuModeTmp = menuMode;  // 恢复menuMode

        return;
    }

    switch (keyPreFunc)
    {
        case KEY_PRG:                           // 按下PRG键
            menu[menuLevel].onPrgFunc();
            break;
            
        case KEY_UP:                            // 按下UP键
            bEnflash = FLASH_NO;
            menu[menuLevel].onUpFunc();
            break;
            
        case KEY_ENTER:                         // 按下ENTER键
            menu[menuLevel].onEnterFunc();
            break;
            
        case KEY_MFK:                           // 按下MF.K键
            menu[menuLevel].onMfkFunc();
            break;
            
        case KEY_DOWN:                          // 按下DOWN键
            bEnflash = FLASH_NO;
            menu[menuLevel].onDownFunc();
            break;
            
        case KEY_SHIFT:                         // 按下SHIFT键
            bOnShift = 1;
            menu[menuLevel].onShiftFunc();
            break;
            
        case KEY_RUN:                           // 按下RUN键
            menu[menuLevel].onRunFunc();
            break;
            
        case KEY_STOP:                          // 按下STOP键
            menu[menuLevel].onStopFunc();
            break;
            
        case KEY_QUICK:                         // 按下QUICK键
            onQuickTicker = 0;
            menu[menuLevel].onQuickFunc();
            break;

        default:
            break;
    }
		#endif
}




void InitSpiaGpio(void)
{


    /* --- 第一部分：使能 SPI-A 内部上拉 --- */
    // TI: GPAPUD.bit.GPIO16/17/18 = 0 (0表示使能上拉)
    // 根据你的引脚映射：GPIO_16->GPIOB_5, GPIO_17->GPIOA_26, GPIO_18->GPIOA_25
    GPIO_setPadConfig(GPIO_16, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPadConfig(GPIO_17, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPadConfig(GPIO_18, GPIO_PIN_TYPE_PULLUP);

    /* --- 第二部分：设置输入限定模式 (Qualification) --- */
    // TI: GPAQSEL2.bit.GPIO16/17/18 = 3 (异步模式，不采样)
    GPIO_setQualificationMode(GPIO_16, GPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(GPIO_17, GPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(GPIO_18, GPIO_QUAL_ASYNC);

    /* --- 第三部分：配置引脚复用为 SPI 功能 --- */
    // TI: GPAMUX2.bit.GPIO16/17/18 = 1 (1通常是各型号的 SPI 功能位)
    // 注意：NS800RT1xxx_TI_gpio.h 已经定义好了复用宏，直接调用最安全
    GPIO_setPinConfig(GPIO_16_SPI1_SIMO);
    GPIO_setPinConfig(GPIO_17_SPI1_SOMI);
    GPIO_setPinConfig(GPIO_18_SPI1_CLK);

    /* --- 第四部分：针对 2803x 逻辑的特定引脚 (RCK & KEYSEL) --- */
#if DSP_2803X 

   #if 0
    // --- RCK 配置 (对应 GPIO22) ---
    // TI: GPAMUX2.bit.GPIO22 = 0 (GPIO), GPADIR = 1 (Output)
    GPIO_setPinConfig(GPIO_22_GPIO22);             // 复用为普通 GPIO
    GPIO_setDirectionMode(GPIO_22, GPIO_DIR_MODE_OUT); // 设置为输出
    GPIO_writePin(GPIO_22, 0);                     // 初始电平：低 (RCK=0)
#else
	GPIO_setPinConfig(GPIO_22_GPIO22);     // 复用为普通 GPIO
	GPIO_setPadConfig(GPIO_22, GPIO_PIN_TYPE_STD); //推挽输出
    GPIO_setAnalogMode(GPIO_22, GPIO_ANALOG_DISABLED);
    GPIO_setDriveLevel(GPIO_22, GPIO_DRV_HIGH);
    GPIO_setDirectionMode(GPIO_22, GPIO_DIR_MODE_OUT);  // 设置为输出 
#endif

  #if 0
    // --- KEYSEL 配置 (对应 AIO4) --- GP19-GP239通用输入输出
	GPIO_setAnalogMode(GPIO_239, GPIO_ANALOG_DISABLED); 
	// 2. 配置引脚的复用功能为普通的 GPIO239
	GPIO_setPinConfig(GPIO_239_GPIO239); 
	// 3. 设置该引脚的方向为：输出 (Output)
	GPIO_setDirectionMode(GPIO_239, GPIO_DIR_MODE_OUT);
	// 4. 输出高电平 
	GPIO_writePin(GPIO_239, 1);
	#else
    //outkey  对应 AIO4-outkey 
    GPIO_setPinConfig(GPIO_239_GPIO239);
	GPIO_setPadConfig(GPIO_239, GPIO_PIN_TYPE_STD);
    GPIO_setAnalogMode(GPIO_239, GPIO_ANALOG_DISABLED);
    GPIO_setDriveLevel(GPIO_239, GPIO_DRV_HIGH);
    GPIO_setDirectionMode(GPIO_239, GPIO_DIR_MODE_OUT);
	#endif

	GPIO_writePin(GPIO_22, 0);//初始拉低
    GPIO_writePin(GPIO_239, 1);


#endif


}




//=====================================================================
//
// SPIA初始化，显示、DI、DO使用
//
//=====================================================================
void InitSetSpiForFunc(void)
{
    uint32_t targetBaud = 195000; 

    /* -------------------------------------------------------------------------
       1. 核心参数配置
       ------------------------------------------------------------------------- */
    SPI_setConfig(SPI1, 
                  SPI_PROT_POL0PHA1,           // 对应 TI 的 CLKPOLARITY=0, CLK_PHASE=1 (Mode 0)
                  SPI_MASTER_MODE,             // 主机模式
                  SPI_FULL_DUPLEX_COMM_MODE,   // 全双工模式
                  targetBaud,                  // 波特率：195kHz
                  SPI_BIT_WIDTH_16_BITS);      // 16位数据长度

	SPI_disableModule(SPI1);


	SPI_clearInterruptStatus(SPI1,
                             SPI_INT_RX_DATA_TX_EMPTY |
                             SPI_INT_TXEF |
                             SPI_INT_RXFF |
                             SPI_INT_RXFF_OVERFLOW);

	SPI_disableInterrupt(SPI1,
                         SPI_INT_RX_DATA_TX_EMPTY |
                         SPI_INT_TXEF |
                         SPI_INT_RXFF |
                         SPI_INT_RXFF_OVERFLOW);


	SPI_resetFIFO(SPI1);

	SPI_setFIFOInterruptLevel(SPI1, 
                              SPI_TX_INTERRUPT_FIFO_THRESHOLD0,   
                              SPI_RX_INTERRUPT_FIFO_THRESHOLD0);  

	SPI_disableInsertFrameDelay(SPI1);
    SPI_enableTxFIFOTransmitDelay(SPI1, 0U, 0U, 0U);
    SPI_setTxFIFOTransmitDelay(SPI1, 0U, 0U, 0U);

	SPI_enableModule(SPI1);

	#if 0

    /* -------------------------------------------------------------------------
       2. FIFO 中断与标志位安全清理 (对应 TI SPIFFTX 的 0xE040 和 SPIFFRX 的 0x205F)
       使用轮询模式，必须把中断彻底关死，并清除遗留的标志位，防止死机
       ------------------------------------------------------------------------- */
    // 清除 TX、RX 历史中断标志，以及 RX 溢出标志 (对应 TI: TXFFINTCLR=1, RXFFINTCLR=1, RXFFOVFCLR=1)
    SPI_clearInterruptStatus(SPI1, SPI_INT_TXEF | SPI_INT_RXFF | SPI_INT_RXFF_OVERFLOW);
    
    // 强制关闭 TX、RX FIFO 中断使能 (对应 TI: TXFFIENA=0, RXFFIENA=0)
    SPI_disableInterrupt(SPI1, SPI_INT_TXEF | SPI_INT_RXFF);

    /* -------------------------------------------------------------------------
       3. FIFO 阈值配置 
       对应 TI: TXFFIL = 0 (触发级别0)，RXFFIL = 0x1F (最大级别31)
       RX 设为最大是为了避免频繁触发状态标志，与 TI 官方手册建议完全一致
       ------------------------------------------------------------------------- */
    SPI_setFIFOInterruptLevel(SPI1, 
                              SPI_TX_INTERRUPT_FIFO_THRESHOLD0,   // TX 阈值设为最小
                              SPI_RX_INTERRUPT_FIFO_THRESHOLD7);  // RX 阈值设为最大 (新库最大是THRESHOLD7)

    /* -------------------------------------------------------------------------
       4. FIFO 发送延迟配置 (对应 TI 的 SPIFFCT.all = 0x0000)
       确保 16 位数据背靠背连续发送，中间无空闲时钟延迟
       ------------------------------------------------------------------------- */
    SPI_setTxFIFOTransmitDelay(SPI1, 0, 0, 0);

    /* -------------------------------------------------------------------------
       5. 最终使能 SPI 模块 (对应 TI 的 SPISWRESET = 1)
       ------------------------------------------------------------------------- */
    SPI_enableModule(SPI1);
	#endif
}






void UpdateMenuModeDisplayBuffer()
{
	#if 1
    //displayBuffer[0] = DISPLAY_CODE[DISPLAY_q] & DISPLAY_CODE[DISPLAY_DOT];
    displayBuffer[0] = DISPLAY_CODE[DISPLAY_LINE];
    displayBuffer[1] = DISPLAY_CODE[dispCodeMenuMode[menuModeTmp-1][0]];
    displayBuffer[2] = DISPLAY_CODE[dispCodeMenuMode[menuModeTmp-1][1]];
    displayBuffer[3] = DISPLAY_CODE[dispCodeMenuMode[menuModeTmp-1][2]];
    displayBuffer[4] = DISPLAY_CODE[dispCodeMenuMode[menuModeTmp-1][3]];
	#endif
}





