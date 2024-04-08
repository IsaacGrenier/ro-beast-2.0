/*
 * File:   inputs.c
 * Author: Ro-Beast Battle Busters
 */

#include "xc.h"
#include "inputs.h"
#include "global_variables.h"

void Read_Limit_Switches(void) {
    int tilt_1 = PORTCbits.RC1;
    int tilt_2 = PORTCbits.RC2;
    int tilt_3 = PORTCbits.RC6;
    int tilt_4 = PORTCbits.RC3;
    int tilt_5 = PORTBbits.RB0;
    int tilt_6 = PORTBbits.RB1;
    
    elev_1 = PORTDbits.RD10;
    elev_2 = PORTCbits.RC7;
    azimuth_home = PORTBbits.RB3;

    if ((tilt_1 + tilt_2 + tilt_3 + tilt_4 + tilt_5 + tilt_6) < 5) {
        // tilt fault
        curr_tilt_char[0] = '9';
        curr_tilt_char[1] = '9';
    }

    curr_tilt_char[0] = '0';
    curr_tilt_char[1] = '0';
    if (tilt_1 == 0) {
        curr_tilt_char[0] = '1';
        curr_tilt_char[1] = '5';
    } else if (tilt_2 == 0) {
        curr_tilt_char[0] = '3';
        curr_tilt_char[1] = '0';
    } else if (tilt_3 == 0) {
        curr_tilt_char[0] = '4';
        curr_tilt_char[1] = '5';
    } else if (tilt_4 == 0) {
        curr_tilt_char[0] = '6';
        curr_tilt_char[1] = '0';
    } else if (tilt_5 == 0) {
        curr_tilt_char[0] = '7';
        curr_tilt_char[1] = '5';
    } else if (tilt_6 == 0) {
        curr_tilt_char[0] = '9';
        curr_tilt_char[1] = '0';
    }

    if (elev_1 == 0) {
        curr_height_char[0] = '1';
        curr_height_char[1] = '0';
        curr_height_char[2] = '4';
        curr_height_char[3] = '.';
        curr_height_char[4] = '0';
    }
    
    if (elev_2 == 0) {
        curr_height_char[0] = '2';
        curr_height_char[1] = '0';
        curr_height_char[2] = '0';
        curr_height_char[3] = '.';
        curr_height_char[4] = '0';
    }
    
    if (azimuth_home == 0) {
        curr_azimuth_char[0] = '0';
        curr_azimuth_char[1] = '0';
        curr_azimuth_char[2] = '0';
        curr_azimuth_char[3] = '.';
        curr_azimuth_char[4] = '0';
        
    }
}