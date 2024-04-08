/*
 * File:   adc.c
 * Author: Ro-Beast Battle Busters
 */

#include "xc.h"
#include "global_variables.h"
#include "math.h"

void ADC_General_Initialize(void){
    ADCON4Hbits.C0CHS = 0;  //Dedicated ADC Core 0 Input Channel Selection bits set to be AN0 (not the alternative pin)
    ADCON4Hbits.C1CHS = 0;  //Dedicated ADC Core 1 Input Channel Selection bits set to be AN1 (not the alternative pin)
        
    // Configure the common ADC clock.
    ADCON3Hbits.CLKSEL = 1; // using FRC oscillator clock
    ADCON3Hbits.CLKDIV = 0; // no clock divider (1:1)
    // Configure the cores? ADC clock.
    ADCORE1Hbits.ADCS = 0; // clock divider (1:2)
    
    // Configure the ADC reference sources.
    ADCON3Lbits.REFSEL = 0; // AVdd as voltage reference
    
    ADCORE1Hbits.RES  = 3; //12 bit resolution ADC
    
    // Configure the integer of fractional output format.
    ADCON1Hbits.FORM = 0; // integer format
    
    ADCON1Hbits.SHRRES = 3; //12-bit resolution
    
    // Set initialization time to maximum
    ADCON5Hbits.WARMTIME = 15;
    // Turn on ADC module
    ADCON1Lbits.ADON = 1;

}

void ADC0_Initialize(void){
    // Turn on analog power for dedicated core 0
    ADCON5Lbits.C0PWR = 1;
    // Wait when the core 0 is ready for operation
    while(ADCON5Lbits.C0RDY == 0);
    // Turn on digital power to enable triggers to the core 0
    ADCON3Hbits.C0EN = 1;
    ADTRIG0Lbits.TRGSRC0 = 1; //software enabled trigger for channel 0

    ANSELAbits.ANSELA0 = 1; 
    TRISAbits.TRISA0 = 1; // AN0/RA0 connected to the dedicated core 0
    // Select single-ended input configuration and unsigned output format.
    ADMOD0Lbits.SIGN0 = 0; 
    ADMOD0Lbits.DIFF0 = 0; 

    
    ADIELbits.IE0 = 1; // enable interrupt for AN0
    _ADCAN0IF = 0; // clear interrupt flag for AN0
    _ADCAN0IE = 1; // enable interrupt for AN0

}

void ADC1_Initialize(void){
    // Turn on analog power for dedicated core 1
    ADCON5Lbits.C1PWR = 1;
    // Wait when the core 1 is ready for operation
    while(ADCON5Lbits.C1RDY == 0);
    // Turn on digital power to enable triggers to the core 1
    ADCON3Hbits.C1EN = 1;
    ADTRIG0Lbits.TRGSRC1 = 1; //software enabled trigger for channel 1
    
    // ADC initialization channel 1
    // Configure the I/O pins to be used as analog inputs.
    ANSELBbits.ANSELB2 = 1; 
    TRISBbits.TRISB2 = 1; // AN1/RB2 connected to the dedicated core 1
    // Select single-ended input configuration and unsigned output format.
    ADMOD0Lbits.SIGN1 = 0;
    ADMOD0Lbits.DIFF1 = 0;
    
    // Configure and enable ADC interrupts for channel 1.
    ADIELbits.IE1 = 1; // enable interrupt for AN1
    _ADCAN1IF = 0; // clear interrupt flag for AN1
    _ADCAN1IE = 1; // enable interrupt for AN1
}

// ADC AN0 ISR
void __attribute__((interrupt, no_auto_psv)) _ADCAN0Interrupt(void){
    r_dataAN0 = ADCBUF0; // read conversion result
    r_voltageAN0 = (r_dataAN0/pow(2,12)) * vref; //calculating voltage at ADC channel 0
    r_currentAN0 = (r_voltageAN0/sense_gain)/sense_r; //calculating current, noting that the gain of 100 from the current sensor must be removed
    _ADCAN0IF = 0; // clear interrupt flag
    LATBbits.LATB14 = 1;//turn on LED to indicate that we arrived in the ISR
}

// ADC AN1 ISR
void __attribute__((interrupt, no_auto_psv)) _ADCAN1Interrupt(void)
{
    e_dataAN1 = ADCBUF1; // read conversion result
    e_voltageAN1 = (e_dataAN1/pow(2,12)) * vref; //calculating voltage at ADC channel 1
    e_currentAN1 = (e_voltageAN1/sense_gain)/sense_r; //calculating current, noting that the gain of 100 from the current sensor must be removed
    _ADCAN1IF = 0; // clear interrupt flag
    LATBbits.LATB14 = 1;//turn on LED to indicate that we arrived in the ISR
}
