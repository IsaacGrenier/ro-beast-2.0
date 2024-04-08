/*
 * File:   system.c
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#ifndef _XTAL_FREQ
#define _XTAL_FREQ  8000000UL
#endif
#define WDT_CLR_KEY 0x5743

#include "xc.h"
#include "stdint.h"
#include "system_types.h"

#ifndef SYSTEM_H
#define	SYSTEM_H

inline static void SYSTEM_CORCONInitialize()
{
    CORCON = (CORCON & 0x00F2) | CORCON_MODE_PORVALUES;    // POR value
}

inline static void SYSTEM_CORCONModeOperatingSet(SYSTEM_CORCON_MODES modeValue)
{
    CORCON = (CORCON & 0x00F2) | modeValue;
}

inline static void SYSTEM_CORCONRegisterValueSet(uint16_t value)
{
    CORCON = value;
}

inline static uint16_t SYSTEM_CORCONRegisterValueGet(void)
{    
    return CORCON;
}

inline static uint32_t SYSTEM_DeviceIdRegisterAddressGet(void)
{
    return __DEVID_BASE;
}

void SYSTEM_Initialize(void);

#endif	/* SYSTEM_H */

