/*
 * File:   clock.h
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include <stdbool.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ  8000000UL
#endif

#define CLOCK_SystemFrequencyGet()        (8000000UL)

#define CLOCK_PeripheralFrequencyGet()    (CLOCK_SystemFrequencyGet() / 2)

#define CLOCK_InstructionFrequencyGet()   (CLOCK_SystemFrequencyGet() / 2)

void CLOCK_Initialize(void);
bool CLOCK_AuxPllLockStatusGet();

#endif	/* CLOCK_H */
