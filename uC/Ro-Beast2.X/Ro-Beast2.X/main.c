/*
 * File:   main.c
 * Author: Ro-Beast Battle Busters
 */

#include "system.h"
#include "state_select.h"
#include "global_variables.h"
#include "timer.h"
#include "tmr1.h"
#include "driver.h"
#include "pwm.h"

int main(void)
{
    SYSTEM_Initialize();
    driver_Start();
    TMR1_Start();
    elev_1 = PORTDbits.RD10;
    elev_2 = PORTCbits.RC7;
    azimuth_home = PORTBbits.RB3;
    VNA_Enable();
    robeast_state = robeast_init;
    State_Select();
    return 1; 
}
