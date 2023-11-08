// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// omap3530/omap3530_drivers/gpio/omap3530_gpio.h
// This file is part of the Beagle Base port
//

#ifndef __OMAP3530_GPIO_H__
#define __OMAP3530_GPIO_H__

#include <assp/omap3530_assp/omap3530_hardware_base.h>
#include <assp/omap3530_assp/omap3530_irqmap.h>
//#include <drivers/gpio.h>

#include <assp/omap3530_assp/gpio.h>
#include <assp.h>

const TUint KGPIO1 = Omap3530HwBase::TVirtual<0x48310000>::Value;
const TUint KGPIO2 = Omap3530HwBase::TVirtual<0x49050000>::Value;
const TUint KGPIO3 = Omap3530HwBase::TVirtual<0x49052000>::Value;
const TUint KGPIO4 = Omap3530HwBase::TVirtual<0x49054000>::Value;
const TUint KGPIO5 = Omap3530HwBase::TVirtual<0x49056000>::Value;
const TUint KGPIO6 = Omap3530HwBase::TVirtual<0x49058000>::Value;

	
const TUint KGPIO_REVISION = 0x000;
const TUint KGPIO_SYSCONFIG = 0x010;
const TUint KGPIO_SYSSTATUS = 0x014;
const TUint KGPIO_IRQSTATUS1 = 0x018;
const TUint KGPIO_IRQENABLE1 = 0x01C;
const TUint KGPIO_WAKEUPENABLE = 0x020;
const TUint KGPIO_IRQSTATUS2 = 0x028;
const TUint KGPIO_IRQENABLE2 = 0x02C;
const TUint KGPIO_CTRL = 0x030;
const TUint KGPIO_OE = 0x034;
const TUint KGPIO_DATAIN = 0x038;
const TUint KGPIO_DATAOUT = 0x03C;
const TUint KGPIO_LEVELDETECT0 = 0x040;
const TUint KGPIO_LEVELDETECT1 = 0x044;
const TUint KGPIO_RISINGDETECT = 0x048;
const TUint KGPIO_FALLINGDETECT = 0x04C;
const TUint KGPIO_DEBOUNCENABLE = 0x050;
const TUint KGPIO_DEBOUNCINGTIME = 0x054;
const TUint KGPIO_CLEARIRQENABLE1 = 0x060;
const TUint KGPIO_SETIRQENABLE1 = 0x064;
const TUint KGPIO_CLEARIRQENABLE2 = 0x070;
const TUint KGPIO_SETIRQENABLE2 = 0x074;
const TUint KGPIO_CLEARWKUENA = 0x080;
const TUint KGPIO_SETWKUENA = 0x084;
const TUint KGPIO_CLEARDATAOUT = 0x090;
const TUint KGPIO_SETDATAOUT = 0x094;

const TUint KGPIO_DEBOUNCE_TIME_MASK = 0xF;


enum TGPIO_InterruptId 
	{
	EGPIOIRQ_FIRST = (EIrqRangeBaseGpio << KIrqRangeIndexShift),
	EGPIOIRQ_PIN_0 = EGPIOIRQ_FIRST,
	EGPIOIRQ_PIN_1,
	EGPIOIRQ_PIN_2,
	EGPIOIRQ_PIN_3,
	EGPIOIRQ_PIN_4,
	EGPIOIRQ_PIN_5,	
	EGPIOIRQ_PIN_6,	
	EGPIOIRQ_PIN_7,	
	EGPIOIRQ_PIN_8,	
	EGPIOIRQ_PIN_9,	
	EGPIOIRQ_PIN_10,
	EGPIOIRQ_PIN_11,
	EGPIOIRQ_PIN_12,
	EGPIOIRQ_PIN_13,
	EGPIOIRQ_PIN_14,
	EGPIOIRQ_PIN_15,	
	EGPIOIRQ_PIN_16,	
	EGPIOIRQ_PIN_17,	
	EGPIOIRQ_PIN_18,	
	EGPIOIRQ_PIN_19,	
	EGPIOIRQ_PIN_20,
	EGPIOIRQ_PIN_21,
	EGPIOIRQ_PIN_22,
	EGPIOIRQ_PIN_23,
	EGPIOIRQ_PIN_24,
	EGPIOIRQ_PIN_25,	
	EGPIOIRQ_PIN_26,	
	EGPIOIRQ_PIN_27,	
	EGPIOIRQ_PIN_28,	
	EGPIOIRQ_PIN_29,	
	EGPIOIRQ_PIN_30,
	EGPIOIRQ_PIN_31,
	EGPIOIRQ_PIN_32,
	EGPIOIRQ_PIN_33,
	EGPIOIRQ_PIN_34,
	EGPIOIRQ_PIN_35,	
	EGPIOIRQ_PIN_36,	
	EGPIOIRQ_PIN_37,	
	EGPIOIRQ_PIN_38,	
	EGPIOIRQ_PIN_39,	
	EGPIOIRQ_PIN_40,
	EGPIOIRQ_PIN_41,
	EGPIOIRQ_PIN_42,
	EGPIOIRQ_PIN_43,
	EGPIOIRQ_PIN_44,
	EGPIOIRQ_PIN_45,	
	EGPIOIRQ_PIN_46,	
	EGPIOIRQ_PIN_47,	
	EGPIOIRQ_PIN_48,	
	EGPIOIRQ_PIN_49,	
	EGPIOIRQ_PIN_50,
	EGPIOIRQ_PIN_51,
	EGPIOIRQ_PIN_52,
	EGPIOIRQ_PIN_53,
	EGPIOIRQ_PIN_54,
	EGPIOIRQ_PIN_55,	
	EGPIOIRQ_PIN_56,	
	EGPIOIRQ_PIN_57,	
	EGPIOIRQ_PIN_58,	
	EGPIOIRQ_PIN_59,	
	EGPIOIRQ_PIN_60,
	EGPIOIRQ_PIN_61,
	EGPIOIRQ_PIN_62,
	EGPIOIRQ_PIN_63,
	EGPIOIRQ_PIN_64,
	EGPIOIRQ_PIN_65,	
	EGPIOIRQ_PIN_66,	
	EGPIOIRQ_PIN_67,	
	EGPIOIRQ_PIN_68,	
	EGPIOIRQ_PIN_69,	
	EGPIOIRQ_PIN_70,
	EGPIOIRQ_PIN_71,
	EGPIOIRQ_PIN_72,
	EGPIOIRQ_PIN_73,
	EGPIOIRQ_PIN_74,
	EGPIOIRQ_PIN_75,	
	EGPIOIRQ_PIN_76,	
	EGPIOIRQ_PIN_77,	
	EGPIOIRQ_PIN_78,	
	EGPIOIRQ_PIN_79,	
	EGPIOIRQ_PIN_80,
	EGPIOIRQ_PIN_81,
	EGPIOIRQ_PIN_82,
	EGPIOIRQ_PIN_83,
	EGPIOIRQ_PIN_84,
	EGPIOIRQ_PIN_85,	
	EGPIOIRQ_PIN_86,	
	EGPIOIRQ_PIN_87,	
	EGPIOIRQ_PIN_88,	
	EGPIOIRQ_PIN_89,	
	EGPIOIRQ_PIN_90,
	EGPIOIRQ_PIN_91,
	EGPIOIRQ_PIN_92,
	EGPIOIRQ_PIN_93,
	EGPIOIRQ_PIN_94,
	EGPIOIRQ_PIN_95,	
	EGPIOIRQ_PIN_96,	
	EGPIOIRQ_PIN_97,	
	EGPIOIRQ_PIN_98,	
	EGPIOIRQ_PIN_99,	
	EGPIOIRQ_PIN_100,
	EGPIOIRQ_PIN_101,
	EGPIOIRQ_PIN_102,
	EGPIOIRQ_PIN_103,
	EGPIOIRQ_PIN_104,
	EGPIOIRQ_PIN_105,	
	EGPIOIRQ_PIN_106,	
	EGPIOIRQ_PIN_107,	
	EGPIOIRQ_PIN_108,	
	EGPIOIRQ_PIN_109,	
	EGPIOIRQ_PIN_110,
	EGPIOIRQ_PIN_111,
	EGPIOIRQ_PIN_112,
	EGPIOIRQ_PIN_113,
	EGPIOIRQ_PIN_114,
	EGPIOIRQ_PIN_115,	
	EGPIOIRQ_PIN_116,	
	EGPIOIRQ_PIN_117,	
	EGPIOIRQ_PIN_118,	
	EGPIOIRQ_PIN_119,	
	EGPIOIRQ_PIN_120,
	EGPIOIRQ_PIN_121,
	EGPIOIRQ_PIN_122,
	EGPIOIRQ_PIN_123,
	EGPIOIRQ_PIN_124,
	EGPIOIRQ_PIN_125,	
	EGPIOIRQ_PIN_126,	
	EGPIOIRQ_PIN_127,	
	EGPIOIRQ_PIN_128,	
	EGPIOIRQ_PIN_129,	
	EGPIOIRQ_PIN_130,
	EGPIOIRQ_PIN_131,
	EGPIOIRQ_PIN_132,
	EGPIOIRQ_PIN_133,
	EGPIOIRQ_PIN_134,
	EGPIOIRQ_PIN_135,	
	EGPIOIRQ_PIN_136,	
	EGPIOIRQ_PIN_137,	
	EGPIOIRQ_PIN_138,	
	EGPIOIRQ_PIN_139,	
	EGPIOIRQ_PIN_140,
	EGPIOIRQ_PIN_141,
	EGPIOIRQ_PIN_142,
	EGPIOIRQ_PIN_143,
	EGPIOIRQ_PIN_144,
	EGPIOIRQ_PIN_145,	
	EGPIOIRQ_PIN_146,	
	EGPIOIRQ_PIN_147,	
	EGPIOIRQ_PIN_148,	
	EGPIOIRQ_PIN_149,	
	EGPIOIRQ_PIN_150,
	EGPIOIRQ_PIN_151,
	EGPIOIRQ_PIN_152,
	EGPIOIRQ_PIN_153,
	EGPIOIRQ_PIN_154,
	EGPIOIRQ_PIN_155,	
	EGPIOIRQ_PIN_156,	
	EGPIOIRQ_PIN_157,	
	EGPIOIRQ_PIN_158,	
	EGPIOIRQ_PIN_159,	
	EGPIOIRQ_PIN_160,
	EGPIOIRQ_PIN_161,
	EGPIOIRQ_PIN_162,
	EGPIOIRQ_PIN_163,
	EGPIOIRQ_PIN_164,
	EGPIOIRQ_PIN_165,	
	EGPIOIRQ_PIN_166,	
	EGPIOIRQ_PIN_167,	
	EGPIOIRQ_PIN_168,	
	EGPIOIRQ_PIN_169,	
	EGPIOIRQ_PIN_170,
	EGPIOIRQ_PIN_171,
	EGPIOIRQ_PIN_172,
	EGPIOIRQ_PIN_173,
	EGPIOIRQ_PIN_174,
	EGPIOIRQ_PIN_175,	
	EGPIOIRQ_PIN_176,	
	EGPIOIRQ_PIN_177,	
	EGPIOIRQ_PIN_178,	
	EGPIOIRQ_PIN_179,	
	EGPIOIRQ_PIN_180,
	EGPIOIRQ_PIN_181,
	EGPIOIRQ_PIN_182,
	EGPIOIRQ_PIN_183,
	EGPIOIRQ_PIN_184,
	EGPIOIRQ_PIN_185,	
	EGPIOIRQ_PIN_186,	
	EGPIOIRQ_PIN_187,	
	EGPIOIRQ_PIN_188,	
	EGPIOIRQ_PIN_189,	
	EGPIOIRQ_PIN_190,
	EGPIOIRQ_PIN_191,

	EGPIOIRQ_END
	};



const TInt32 KHwGpioPinMax		= 192;	// 32*6 pins
const TInt32 KHwGpioPinsPerBank	= 32;
const TInt32 KHwGpioBanks		= KHwGpioPinMax / KHwGpioPinsPerBank ;

// Utility code to convert a pin number to a GPIO bank
const TUint KGPIO_BASE_ADDRESSES[] = { KGPIO1, KGPIO2, KGPIO3, KGPIO4, KGPIO5, KGPIO6 };





inline TUint GPIO_BASE_ADDRESS(TInt aPin) {return KGPIO_BASE_ADDRESSES[(TInt)(aPin/KHwGpioPinsPerBank)];};
#define GPIO_PIN_BANK(aId) ((aId)/KHwGpioPinsPerBank)
#define GPIO_PIN_OFFSET(aId) (1 <<  (aId%KHwGpioPinsPerBank))
#define GPIO_PIN_BOUNDS(aId)((aId > 0) && (aId <KHwGpioPinMax))

class GpioPin
	{
	public:
		GPIO::TGpioMode	iMode;
		TUint iBankAddr;
		TUint iBank;
		SInterruptHandler irq;		
		TUint iIrqVector;
	};

#endif	// __OMAP3530_GPIO_H__


