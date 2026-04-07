/**
 * @file       main.c
 * @author     Haven-X
 * @brief      main function file for NS800RT1xxx.
 *
 * <h2><center>&copy; Copyright (c) 2025 Novosense Limited.
 * All rights reserved.</center></h2>
 */
// #include "MotorInclude.h"
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
#include "f_main.h"
#include "device.h"

extern void ADCOverInterrupt(void);
extern void PWMZeroInterrupt(void);
extern void HardWareErrorDeal(void);

extern void Main2msMotorA(void);
extern void Main2msMotorB(void);
extern void Main2msMotorC(void);
extern void Main2msMotorD(void);

extern void Main05msMotor(void);     
//extern void Main0msMotor(void);

//extern void Main2msFunction(void);
//extern void Main05msFunction(void);     
extern void Main05msFunctionA(void);
extern void Main05msFunctionB(void);
extern void Main05msFunctionC(void);
extern void Main05msFunctionD(void);
extern void Main0msFunction(void);

extern void Board_init();
/***************************************************************
-------------------------主程序部分-----------------------------
****************************************************************/
int main(void)
{	
    
	uint32_t m_BaseTime,m_DetaTime;
	uint16_t  m_LoopFlag;
//   __disable_irq(); //

   	InitSysCtrl();						// Step 1. Initialize System Control
#if 1 // led test
	Board_init();
	#endif
	
    //初始化各接口时钟和各接口外设。PWM,ADC,GPIO.
   	InitPeripherals(); 					// Step 3. Initialize all the Device Peripherals:
   
//   	InitForMotorApp();					// Step 4. User specific code
   	InitForFunctionApp();  // SPI SCI Init

//	EnableDog();                  // d
//	SetInterruptEnable();				// Step 5. enable interrupts:
//   	EINT;    //开所有中断							    
//   	ERTM;   							    
// __enable_irq(); //  //开所有中断	
	m_LoopFlag = 0;
	m_BaseTime = GetTime();
    
  	while(1)							// Step 6. User Application function:
   	{
		m_DetaTime = m_BaseTime - GetTime();		
		if(m_DetaTime >= C_TIME_05MS)	//判断0.5MS周期
        {            
					
			m_BaseTime -= C_TIME_05MS; 
			m_LoopFlag ++;	
// 			KickDog();

//            Main05msMotor();                        // 驱动0.5ms程序          
                    
			if((m_LoopFlag & 0x03) == 0)            // prA
			{         
                Main05msFunctionA(); // 扫描显示数码管
                Main05msFunctionB();	//显示按键功能	参数更新			
			}
            else if((m_LoopFlag & 0x03) == 1)       // prB
            {            


				// 每个0.5ms都调用// 加减速时间计算 145// 上电时间、运行时间统计 100// 定时运行时间统计 65
				// 命令源   1300// 更新功能传递给性能的交互数据  153
				// EEPROM时间处理，判断是否超时  40// 更新errorCode 527
				// AO1  510
				// AO2  530
				// FMP处理 710
                //Main05msFunctionB();
                Main05msFunctionC();
                //Main05msFunctionD();	
            }
			else if((m_LoopFlag & 0x03) == 2)       // prC
			{    
			// 电机温度更新，显示数据更新。
                Main05msFunctionD();
//                Main2msMotorA(); // //从控制板获取参数 0.5MS 2MS数据停机交换数据。

			}
            else if((m_LoopFlag & 0x03) == 3)       // prD
            {             
//                Main2msMotorB(); // f载波处理。等
//                Main2msMotorC();  // 功率、转矩计算	各种保保护检测
//				Main2msMotorD(); 	//电流零漂检测，AD零漂和线性度检测 和把时时数据传给控制面板。
            }

            // 计算cpu忙碌系数1
           // gCpuTime.Det05msClk = __IQsat(m_DetaTime, 65535, C_TIME_05MS);
        }

//		Main0msFunction();				//不等待循环－执行功能部分程序
//		Main0msMotor();					//不等待循环－执行电机控制部分程序
   	}
} 


/***************************************************************
-----------------------中断程序部分-----------------------------
****************************************************************/
/***************************************************************
	EPWM的周期中断，约30us
****************************************************************/
#if 0
void ADC_Over_isr(void)//interrupt
{
//    EALLOW;             //28035改为EALLOW保护
//    ADC_CLEAR_INT_FLAG;
//    EDIS;
//	EINT;
	//gCpuTime.ADCIntBase = GetTime();
	//ADCOverInterrupt();
	gMainCmd.pADCIsr();                         /*修改为函数指针方式执行ADC结束中断程序，默认ADCEndIsr()*/					
//	gCpuTime.ADCInt = gCpuTime.ADCIntBase - GetTime();
//	DINT;
//    EALLOW;
//    ADC_RESET_SEQUENCE;
//   	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Acknowledge this interrupt
//    EDIS;
}
/***************************************************************
	EPWM的过流中断，对硬件过流信号处理
****************************************************************/
 void EPWM1_TZ_isr(void) //interrupt
{
	DisableDrive();								//首先封锁输出
	HardWareErrorDeal();					    //处理硬件故障－电机控制模块处理
                // 
  // 	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	    // Acknowledge this interrupt
}

/***************************************************************
	CBC触发的TZ中断，中断中强制关闭驱动使能信号
****************************************************************/
 void EPWM2_TZ_isr(void) //interrupt
{               
	DisableDrive();								//首先封锁输出,周期中断中开启
    gCBCProtect.CBCIntFlag = 1;  
  // 	PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;	    // Acknowledge this interrupt
}
#endif
/*----------------------------END---------------------------------


****************************************************************/

