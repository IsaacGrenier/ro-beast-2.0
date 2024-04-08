/*
 * File:   driver.c
 * Author: Ro-Beast Battle Busters
 */

#include "xc.h"
#include "pwm.h"
#include "stdio.h"

void driverE_Enable(char dir){
    if (dir == 'u') {
        LATDbits.LATD1 = 0;
    } else if (dir == 'd') {
        LATDbits.LATD1 = 1;
    }
    // DC Brake
    LATBbits.LATB4 = 1;
    // eENABLE
    LATCbits.LATC11 = 0;
    // eSLEEP
    LATDbits.LATD13 = 1;
    // eRES
    LATCbits.LATC0 = 1;
    PWM_Enable();
}

void driverA_Enable(char dir){
    // l = ccw, r = cw (looking down on table)
    if (dir == 'l') {
        LATDbits.LATD1 = 0;
    } else if (dir == 'r') {
        LATDbits.LATD1 = 1;
    }

    // rENABLE
    LATAbits.LATA1 = 0;
    // rSLEEP
    LATAbits.LATA2 = 1;
    // rRES
    LATAbits.LATA3 = 1;
    PWM_Enable();
}

void driverE_Disable(void){
    // eENABLE
    LATCbits.LATC11 = 1;
    // eSLEEP
    LATDbits.LATD13 = 0;
    // eRES
    LATCbits.LATC0 = 0; 
    // DC Brake
    LATBbits.LATB4 = 0;
    PWM_Disable();
}

void driverA_Disable(void){
    // rENABLE
    LATAbits.LATA1 = 1;
    // rSLEEP
    LATAbits.LATA2 = 0;
    // rRES
    LATAbits.LATA3 = 0;

    PWM_Disable();
}

void driver_Start(void){
    driverE_Disable();
    driverA_Disable();
}
