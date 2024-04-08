/*
 * File:   pin_manager.c
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x0011;
    TRISB = 0x0B6D;
    TRISC = 0x37DE;
    TRISD = 0x0400;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPDA = 0x0000;
    CNPDB = 0x0000;
    CNPDC = 0x0000;
    CNPDD = 0x0000;
    CNPUA = 0x0000;
    CNPUB = 0x0000;
    CNPUC = 0x0000;
    CNPUD = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x0000;
    ANSELB = 0x0000;
    ANSELC = 0x0000;
    ANSELD = 0x0000;
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_RPCON(0x0000); // unlock PPS

    RPINR18bits.U1RXR = 0x002B;    //RB11->UART1:U1RX
    RPOR5bits.RP42R = 0x0001;    //RB10->UART1:U1TX

    RPINR3bits.ICM1R = 47;          //remapping input pin set by the PWM-Initialize function as a SCCP pin for counting
    
    //using PPS to set pin 60 and 61 to QEIA and QEI respectively
    RPINR14bits.QEIA1R = 60;
    RPINR14bits.QEIB1R = 61;

    
    RPINR0bits.INT1R = 35; // a_home (RB3)
    RPINR1bits.INT2R = 74; // elev_1 (bottom) (RD10)
    RPINR1bits.INT3R = 55; // elev_2 (top) (RC7)

            
    __builtin_write_RPCON(0x0800); // lock PPS
}
