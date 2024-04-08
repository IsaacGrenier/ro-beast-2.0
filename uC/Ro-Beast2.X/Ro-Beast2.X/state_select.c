/*
 * File:   state_select.c
 * Author: Ro-Beast Battle Busters
 */

#include "xc.h"
#include "state_select.h"
#include "global_variables.h"
#include "driver.h"
#include "pwm.h"
#include "stdlib.h"
#include "stddef.h"
#include "qei.h"
#include "tmr1.h"
#include "uart.h"


#define FCY 4000000UL       //FRC/2
#include "libpic30.h"


void State_Select(void)
{
    while(1){
        switch(robeast_state)
        {   
            case robeast_init:
                
                uart_index = 0;
                rx_msg = 0x00; 

                if (elev_1 != 0) {      //elev_1 = bottom limit switch, elev_2 = top limit switch
                    PWM1_Reset(5,'e');
                    driverE_Enable('d');  
                } else {
                    current_height = 104.0;
                }
                
                while (current_height != 104.0) {}

                if (azimuth_home != 0) {
                    PWM1_Reset(30, 'a');
                    driverA_Enable('l');    
                }else {
                    current_azimuth = 0;
                }

                while (current_azimuth != 0) {}

                robeast_state = robeast_standby;

                break;

            case robeast_position:
                
                IEC0bits.INT1IE = 0;
                LATDbits.LATD8 = 0;
                uart_index = 0;
                rx_msg = 0x00;   
                
                current_height = 104.0;
                desired_height = atof(desired_height_char);
                
                current_azimuth = 0;
                desired_azimuth = atof(desired_azimuth_char);
                
                //current_height = atof(curr_height_char);
                               
                VNA_EMeasurementTriggerCalculation(2);
                
                SCCP_EStopCriteria(desired_height, current_height);
                SCCP_Enable();

                if ((int)current_height != (int)desired_height) {
                    PWM1_Reset(10,'e');
                    driverE_Enable('u');    
                }

                while ((int) current_height != (int) desired_height) {}
                VNA_Reset();
                
                

                VNA_AMeasurementTriggerCalculation(5);
                
                if ((int) current_azimuth != (int) desired_azimuth) {
                    PWM1_Reset(30, 'a');
                    driverA_Enable('l');    
                    QEI_Initialize();                               //have to initialize every time direction is changed due to the register values changing for compare registers
                    QEI_CounterClear();
                    QEI_CounterSet(desired_azimuth);
                }
                
                while(current_azimuth != desired_azimuth) {}         
                
                current_azimuth = 0;
                VNA_Reset();                                    //resets VNA signal back to a HIGH

                IEC0bits.INT1IE = 1;
                robeast_state = robeast_standby;
                //robeast_state = robeast_azimuth_sweep;
                
                break;

            case robeast_height_sweep:
                uart_index = 0;
                rx_msg = 0x00; 
                
                desired_height = atof(desired_height_char);
                current_height = atof(curr_height_char); 
                
                desired_height_interval = atof(desired_height_interval_char);
                //desired_height_interval = desired_height_interval*1000;
                desired_height_speed = atof(desired_height_speed_char);
                               
                VNA_EMeasurementTriggerCalculation(desired_height_interval);
                
                SCCP_EStopCriteria(desired_height, current_height);
                SCCP_Enable();

                PWM1_Reset(desired_height_speed,'e');
                driverE_Enable('u');

                while ((int) current_height != (int) desired_height) {}
                VNA_Reset();
                
                robeast_state = robeast_init;
                
                break;

            case robeast_azimuth_sweep:
                uart_index = 0;
                rx_msg = 0x00; 
                
                IEC0bits.INT1IE = 0;
                
                desired_azimuth = atof(desired_azimuth_char);
                current_azimuth = 0; 
                
                desired_azimuth_interval = atof(desired_azimuth_interval_char);
                desired_azimuth_speed = atof(desired_azimuth_speed_char);

                VNA_AMeasurementTriggerCalculation(desired_azimuth_interval);
                
                //VNA_AMeasurementTriggerCalculation(2);
                
                PWM1_Reset(desired_azimuth_speed, 'a');
                //PWM1_Reset(25, 'a');
                driverA_Enable('l');    
                
                QEI_Initialize();                               //have to initialize every time direction is changed due to the register values changing for compare registers
                QEI_CounterClear();
                QEI_CounterSet(desired_azimuth);
                while(current_azimuth != desired_azimuth) {
                    if (POS1CNTL % vna_measurement_trigger == 0){
                        vna_measurement_trigger_off = (int) (POS1CNTL + (vna_measurement_trigger/2));
                        LATBbits.LATB12 = 0; //only want a small falling edge trigger
                        LATDbits.LATD8 = 1;
                    }
                    if (vna_measurement_trigger_off == POS1CNTL){
                        LATBbits.LATB12 = 1; //set VNA signal as HIGH again
                        LATDbits.LATD8 = 0;
                    }   
                }                
                current_azimuth = 0;
                desired_azimuth = atof(desired_azimuth_char);
                VNA_Reset();                                    //resets VNA signal back to a HIGH

                
                PWM1_Reset(30, 'a');
                driverA_Enable('r');                            //moving opposite direction to untangle cables after sweep is complete
                
                QEI_Initialize();                               
                QEI_CounterClear();
                QEI_CounterSet(desired_azimuth);
                while( current_azimuth != desired_azimuth) {}                
                current_azimuth = 0;
                VNA_Reset();                                    //resets VNA signal back to a HIGH

                IEC0bits.INT1IE = 1;
                
                robeast_state = robeast_init;
                
                break;

            case robeast_pause:

            case robeast_cancel:

            case robeast_fault:

            case robeast_standby:
                
                uart_index = 0;
                rx_msg = 0x00; 
                
                LATDbits.LATD8 = 1;
                

                
                while(1){}
                break;

            default:
                robeast_state = robeast_standby;

        }
    }
}