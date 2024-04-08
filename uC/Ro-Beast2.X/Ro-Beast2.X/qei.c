/*
 * File:   qei.c
 * Author: Ro-Beast Battle Busters
 */

#include "xc.h"
#include "qei.h"
#include "global_variables.h"
#include "math.h"
#include "stdlib.h"
#include "pwm.h"
#include "driver.h"

void QEI_Initialize(void){
    QEI1CONbits.QEIEN = 0; //disable QEI module while modifying parameters

    //Setting up global interrupt
    IEC3bits.QEI1IE = 1; //enable QEI1 register
    IFS3bits.QEI1IF = 0; //clear interrupt flag
    IPC12bits.QEI1IP = 3; //high priority interrupt
    
    if (PORTDbits.RD1 == 0){
        QEI1STATbits.PCHEQIEN = 1; //enabling Position Counter Greater Than Compare bits interrupt (disable if counting the other way)
        QEI1STATbits.PCLEQIEN = 0; //disabling Position Counter Less Than Compare bits  (enable if counting the other way)
        QEI1IOCbits.SWPAB = 0;
    } else if (PORTDbits.RD1 == 1){
        //QEI1STATbits.PCHEQIEN = 0; //disabling Position Counter Greater Than Compare bits interrupt (disable if counting the other way)
        //QEI1STATbits.PCLEQIEN = 1; //enabling Position Counter Less Than Compare bits  (enable if counting the other way) 
        //maybe uncomment above later
        QEI1STATbits.PCHEQIEN = 1; //enabling Position Counter Greater Than Compare bits interrupt (disable if counting the other way)
        QEI1STATbits.PCLEQIEN = 0; //disabling Position Counter Less Than Compare bits  (enable if counting the other way)
        QEI1IOCbits.SWPAB = 1; 
    }
    
    QEI1CONbits.CCM = 0; //set module to QEI mode
    QEI1CONbits.QEIEN = 1; //enable QEI module
    
    //setting the QEI pins as inputs
    TRISCbits.TRISC12 = 1;
    TRISCbits.TRISC13 = 1;
    
}

void QEI_CounterClear(void){
    //reset the counter registers
    if (PORTDbits.RD1 == 0){
        encoder_starting_value = 0x0000;
    } else if (PORTDbits.RD1 == 1){
//        encoder_starting_value = 0xFFFF;  
        //maybe unccoment above later
        encoder_starting_value = 0x0000;
    }
    POS1CNTL = encoder_starting_value;  
    POS1CNTH = 0x0000;
}

void QEI_CounterSet(float range){
    int encoder_ending_value_calculation = (int) (44800.0/360.0)*range;
    if (PORTDbits.RD1 == 0){
        //encoder_ending_value = 44800;
        encoder_ending_value = encoder_ending_value_calculation;
        QEI1GECL = encoder_ending_value; 
        QEI1GECH = 0; //only need the lower 16 bit word for the counter in this situation
    } else if (PORTDbits.RD1 == 1){
        //encoder_ending_value = 20735;
//        encoder_ending_value = 0xFFFF - encoder_ending_value_calculation;
//        QEI1LECL = encoder_ending_value; //these are the registers for starting at 0xFFFF
//        QEI1LECH = 0;  
        //maybe uncomment above later
        encoder_ending_value = encoder_ending_value_calculation;
        QEI1GECL = encoder_ending_value; 
        QEI1GECH = 0; //only need the lower 16 bit word for the counter in this situation
    }
}

void QEI_Feedback(void){
    // Encoder calculation algorithm
    curr_pos_cnt = POS1CNTL;
    encoder_freq = (float) abs((curr_pos_cnt - prev_pos_cnt))*0.32;

    prev_pos_cnt = curr_pos_cnt;
    //a_speed = (float) (encoder_freq*encoder_res)/4; // N - angular speed [degrees/second]
    encoder_speed = (float) encoder_freq/4;

    //a_position = (float) abs(((int)(curr_pos_cnt-starting_value)))*encoder_res/4; // a_position - angular position [degrees]
    if(PORTDbits.RD1 == 0){
        encoder_position = (float) (curr_pos_cnt-encoder_starting_value)*encoder_res/4; // a_position - angular position [degrees]
    }
    else {
        //encoder_position = (float) (encoder_starting_value-curr_pos_cnt)*encoder_res/4; // a_position - angular position [degrees]
        encoder_position = (float) (curr_pos_cnt-encoder_starting_value)*encoder_res/4; // a_position - angular position [degrees]
    }
}

void vreg_5V_enable(void){
    TRISCbits.TRISC5 = 0;
    LATCbits.LATC5 = 1;
}

void vreg_5V_disable(void){
    LATCbits.LATC5 = 0;
}

void VNA_AMeasurementTriggerCalculation(float sweep_value){
    vna_measurement_trigger = (int) (44800.0/360.0)*sweep_value;
}

void __attribute__((__interrupt__,no_auto_psv)) _QEI1Interrupt(void){
    driverA_Disable();
    SCCP_Disable();
    sccp_pwm_counts = 0;
    
    curr_azimuth_char[0] = desired_azimuth_char[0];
    curr_azimuth_char[1] = desired_azimuth_char[1];
    curr_azimuth_char[2] = desired_azimuth_char[2];
    curr_azimuth_char[3] = desired_azimuth_char[3];
    curr_azimuth_char[4] = desired_azimuth_char[4];
    current_azimuth = atof(curr_azimuth_char);
    
    QEI_CounterClear(); //reset the counter registers
    IFS3bits.QEI1IF = 0; //clear interrupt flag
}