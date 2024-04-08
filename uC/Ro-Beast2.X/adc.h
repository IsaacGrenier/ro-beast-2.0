/*
 * File:   adc.h
 * Author: Ro-Beast Battle Busters
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
 
void ADC_General_Initialize(void);
void ADC0_Initialize(void);
void ADC1_Initialize(void);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* ADC_H */

