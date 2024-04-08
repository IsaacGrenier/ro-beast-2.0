/*
 * File:   pwm.c
 * Author: Ro-Beast Battle Busters
 */

#include "xc.h"
#include "global_variables.h"
#include "libpic30.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "driver.h"
#include <stdint.h>

void PWM1_Initialize(void){
    /*PWM control register configuration*/
    PCLKCONbits.MCLKSEL = 0;
    PCLKCONbits.DIVSEL = 3;
    PG1CONLbits.CLKSEL = 2; //PWM Generator uses Master clock divided by clock divider circuit
    PG1CONLbits.MODSEL = 0b000; /*Independent edge triggered mode */
    PG1CONH = 0x0000;
    /*PWM Generator outputs operate in Complementary mode*/
    /*PWM Generator controls the PWM1H and PWM1L output pins*/
    /*PWM1H & PWM1L output pins are active high*/
    //PG1IOCONH = 0x000C;
    PG1IOCONH = 0x0008; //only allowing PWM module to control PWM1H. PWMIL to be controlled by GPIO module to reduce EMI.
    TRISBbits.TRISB15 = 1; //for SCCP module for counting
 //   RPINR3bits.ICM1R = 47;          //remapping input pin set by the PWM-Initialize function as a SCCP pin for counting

    /*PWM uses PG1DC, PG1PER, PG1PHASE registers*/
    /*PWM Generator does not broadcast UPDATE status bit state or EOC signal*/
    /*Update the data registers at start of next PWM cycle (SOC) */
    /*PWM Generator operates in Single Trigger mode*/
    /*Start of cycle (SOC) = local EOC*/    
}

void PWM1_Reset(float desired_speed, char speed_type){
    if (speed_type == 'e') {
        end_register_period = round((master_clock/16)/(desired_speed/elevation_step_res) - 1);
    } else if (speed_type == 'a') {
        end_register_period = round(((master_clock/16)*(azimuth_step_res/desired_speed))/2); //(master_clock/16)/(desired_speed/azimuth_step_res*azimuth_driver_mode))-1;
    }
    if (end_register_period < 2000){
        PG1PER = 2000;
    }else{
        PG1PER = end_register_period;
    }
    PG1DC = (int) round((PG1PER*0.5)-1);
    PG1PHASE = 0; /*Phase offset in rising edge of PWM*/
    PG1DTH = 10; /*Dead time on PWMH */
    PG1DTL = 100; /*Dead time on PWML*/
}

void PWM_Enable(void){ 
    /*Enable PWM*/
    PG1CONLbits.ON = 1; /*PWM module is enabled*/
}

void PWM_Disable(void){ 
    /*Enable PWM*/
    PG1CONLbits.ON = 0; /*PWM module is disabled*/
}

void PWM1_Ramp(void){
    if (PG1CONLbits.ON == 1){
        unsigned int temp = PG1PER;
        if(PG1PER>end_register_period){
        PG1STATbits.UPDREQ = 0;
        while(PG1STATbits.UPDATE);
            PG1PER = temp-50;
            temp = PG1PER;
            PG1DC = (int) round((PG1PER*0.5)-1);
            PG1STATbits.UPDREQ = 1;
        }
    }
}

void SCCP_Initialize(void){
    
    CCP1CON1Lbits.T32 = 0;          // Uses 16-bit time base for dual timer, single edge output compare or input capture function
    CCP1CON1Lbits.CCSEL = 1;        // Input Capture mode
    CCP1CON1Lbits.CLKSEL = 2;       // Fosc. Same as PWM clk. 
    CCP1CON1Lbits.MOD = 1;          // Capture every rising edge
    CCP1CON2Hbits.ICSEL = 0;         // Capture rising edge on the Pin
    CCP1CON1Hbits.IOPS = 0;           // Interrupt on every input capture event
    CCP1CON1Lbits.TMRPS = 0;          // Set the clock pre-scaler (1:1)
    CCP1CON2Hbits.ICS = 0;          // SCCP Input Capture x pin (PPS) 
    CCP1STATLbits.ICDIS = 0;        // Event on input capture x pin will generate a capture event
    
    IEC0bits.CCP1IE = 1;            // enabling the CCP1 interrupt flag
    IFS0bits.CCP1IF = 0;            // clear CCP1 interrupt flag
    IPC1bits.CCP1IP = 3;            // Specify priority
        
}

void SCCP_Enable(void){
    CCP1CON1Lbits.CCPON = 1;        // Module is enabled with an operating mode specified by the MOD[3:0] control bits
}

void SCCP_Disable(void){
    CCP1CON1Lbits.CCPON = 0;        // Module is disabled with an operating mode specified by the MOD[3:0] control bits
}

void SCCP_EStopCriteria(float desired_height, float current_height){
    
    if (desired_height > current_height){
        //sccp_stop_criteria = (int) (((desired_height - current_height)*10)/elevation_step_res);
        if((((desired_height - current_height)*10)*166.67) > 65535){
            sccp_stop_criteria_multiple = sccp_stop_criteria_multiple + 1;
            
            if((((desired_height - current_height)*10)*166.67) - 65535 > 65535){
                sccp_stop_criteria_multiple = sccp_stop_criteria_multiple + 1;
                sccp_stop_criteria = (int) ((((desired_height - current_height)*10)*166.67) - 2*65535);
            } else{
                sccp_stop_criteria = (int) (((desired_height - current_height)*10)*166.67) - 65535;
            }
        }
        sccp_stop_criteria = (int) (((desired_height - current_height)*10)*166.67);
    } else if (desired_height <= current_height){
        sccp_stop_criteria = (int) (((current_height - desired_height)*10)*166.67);
    }
    
            
}

void SCCP_AStopCriteria(float desired_azimuth){

    sccp_stop_criteria = (int) ((desired_azimuth)/azimuth_step_res);

}


void VNA_Enable(void){
    TRISBbits.TRISB12 = 0;
    LATBbits.LATB12 = 1;            //setting the limit switch VNA trigger as a HIGH so that it can be triggered on a falling edge
}

void VNA_Reset(void){
    LATBbits.LATB12 = 1;            //resetting the limit switch VNA trigger as a HIGH so that it can be triggered on a falling edge
    LATDbits.LATD8 = 0;
}

void VNA_EMeasurementTriggerCalculation(float sweep_value){
    
    vna_measurement_trigger = (int) sweep_value / elevation_step_res;
    
}


void __attribute__((interrupt(auto_psv))) _CCP1Interrupt(void){    
    sccp_pwm_counts = sccp_pwm_counts + 1;
    
    if(sccp_pwm_counts == 65535){
        sccp_pwm_counts_multiple = sccp_pwm_counts_multiple + 1;
        sccp_pwm_counts = 0;
    }
    
    if((sccp_pwm_counts + sccp_pwm_counts_multiple*65535) == (sccp_stop_criteria + sccp_stop_criteria_multiple*65535)){
        driverE_Disable();
        SCCP_Disable();
        sccp_pwm_counts = 0;
        sccp_pwm_counts_multiple = 0;
        sccp_stop_criteria_multiple = 0;

        curr_height_char[0] = desired_height_char[0];
        curr_height_char[1] = desired_height_char[1];
        curr_height_char[2] = desired_height_char[2];
        curr_height_char[3] = desired_height_char[3];
        curr_height_char[4] = desired_height_char[4];
        current_height = atof(curr_height_char);
    }

    if (robeast_state == robeast_height_sweep){
        if (sccp_pwm_counts % vna_measurement_trigger == 0){
            vna_measurement_trigger_off = (int) (sccp_pwm_counts + (vna_measurement_trigger/2));
            LATBbits.LATB12 = 0; //only want a small falling edge trigger
            LATDbits.LATD8 = 1;
        }
    
        if (vna_measurement_trigger_off == sccp_pwm_counts){
            LATBbits.LATB12 = 1; //set VNA signal as HIGH again
            LATDbits.LATD8 = 0;
        }      
    }  
    
    IFS0bits.CCP1IF = 0;        // clear CCP1 interrupt flag

}

