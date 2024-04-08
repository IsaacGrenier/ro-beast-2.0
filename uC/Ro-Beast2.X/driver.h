/*
 * File:   driver.h
 * Author: Ro-Beast Battle Busters
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DRIVER_H
#define	DRIVER_H

#include <xc.h>

void driverE_Enable(char dir);
void driverA_Enable(char dir);
void driverE_Disable(void);
void driverA_Disable(void);
void driver_Start(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* DRIVER_H */

