/*
 * File:   interrupt_manager.c
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#include <xc.h>
#include <string.h>
#include "stdlib.h"
#include "global_variables.h"
#include "timer.h"
#include "tmr1.h"
#include "uart.h"
#include "qei.h"
#include "state_select.h"
#include "inputs.h"
#include "driver.h"
#include "pwm.h"

void INTERRUPT_Initialize (void)
{
    //    TI: Timer 1
    //    Priority: 1
        IPC0bits.T1IP = 3;
    //    UEVTI: UART1 Event
    //    Priority: 1
        IPC47bits.U1EVTIP = 1;
    //    UTXI: UART1 TX
    //    Priority: 1
        IPC3bits.U1TXIP = 1;
    //    UEI: UART1 Error
    //    Priority: 1
        IPC12bits.U1EIP = 1;
    //    URXI: UART1 RX
    //    Priority: 1
        IPC2bits.U1RXIP = 1;
        
        //RPINR0bits.INT1R = 35; // a_home (RB3)
        INTCON2bits.INT1EP = 1; // Negative edge
        IPC3bits.INT1IP = 3; // Priority
        IFS0bits.INT1IF = 0; // Clearing flag
        IEC0bits.INT1IE = 1; // Enable
        
        //RPINR1bits.INT2R = 74; // elev_1 (bottom) (RD10)
        INTCON2bits.INT2EP = 1; // Negative edge
        IPC5bits.INT2IP = 7; // Highest priority
        IFS1bits.INT2IF = 0; // Clearing flag
        IEC1bits.INT2IE = 1; // Enable
        
        //RPINR1bits.INT3R = 55; // elev_2 (top) (RC7)
        INTCON2bits.INT3EP = 1; // Negative edge
        IPC6bits.INT3IP = 7; // Highest priority
        IFS1bits.INT3IF = 0; // Clearing flag
        IEC1bits.INT3IE = 1; // Enable        
        
}

void __attribute__((interrupt(auto_psv))) _INT1Interrupt(void){ // a_home
    driverA_Disable();
    SCCP_Disable();
    sccp_pwm_counts = 0;
    
    current_azimuth = 0; 
    
    IFS0bits.INT1IF = 0; // Clearing flag
}

void __attribute__((interrupt(auto_psv))) _INT2Interrupt(void){ // elev_1
    driverE_Disable();
    SCCP_Disable();
    sccp_pwm_counts = 0;
    
    curr_height_char[0] = '1';
    curr_height_char[1] = '0';
    curr_height_char[2] = '4';
    curr_height_char[3] = '.';
    curr_height_char[4] = '0';
    
    current_height = atof(curr_height_char);  
    
    IFS1bits.INT2IF = 0; // Clearing flag
}

void __attribute__((interrupt(auto_psv))) _INT3Interrupt(void){ // elev_2
    driverE_Disable();
    SCCP_Disable();
    sccp_pwm_counts = 0;
    
    curr_height_char[0] = '1';
    curr_height_char[1] = '9';
    curr_height_char[2] = '3';
    curr_height_char[3] = '.';
    curr_height_char[4] = '0';
    
    current_height = atof(curr_height_char);  
    
    IFS1bits.INT3IF = 0; // Clearing flag
}

//void __attribute__ ( ( interrupt, no_auto_psv ) ) _T1Interrupt (  )
//{
//
//    Increment_Timers();
//
//    // Real-time feedback
//    int i;
//    for (i = 0; i < strlen(curr_height_char); i++) {
//        UART1_Write(curr_height_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_azimuth_char); i++) {
//        UART1_Write(curr_azimuth_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_height_interval_char); i++) {
//        UART1_Write(curr_height_interval_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_azimuth_interval_char); i++) {
//        UART1_Write(curr_azimuth_interval_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_height_speed_char); i++) {
//        UART1_Write(curr_height_speed_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_azimuth_speed_char); i++) {
//        UART1_Write(curr_azimuth_speed_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_tilt_char); i++) {
//        UART1_Write(curr_tilt_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_height_current_char); i++) {
//        UART1_Write(curr_height_current_char[i]);
//    }
//
//    for (i = 0; i < strlen(curr_azimuth_current_char); i++) {
//        UART1_Write(curr_azimuth_current_char[i]);
//    }
//
//    read_limit_switches();
//
//    if(TMR1_InterruptHandler) 
//    { 
//           TMR1_InterruptHandler(); 
//    }
//
//    tmr1_obj.count++;
//    tmr1_obj.timerElapsed = true;
//    IFS0bits.T1IF = false;
//}

//void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1RXInterrupt( void )
//{
//    if(UART1_RxDefaultInterruptHandler)
//    {
//        UART1_RxDefaultInterruptHandler();
//    }
//    
//    char rx_msg = UART1_Read();
//
//    if (rx_msg == 0x61) {
//        
//        robeast_state = robeast_none;
//        State_Select();
//        
//        desired_height_char[0] = (char)UART1_Read();
//        desired_height_char[1] = (char)UART1_Read();
//        desired_height_char[2] = (char)UART1_Read();
//        desired_height_char[3] = (char)UART1_Read();
//        desired_height_char[4] = (char)UART1_Read();
//        
//        desired_azimuth_char[0] = (char)UART1_Read();
//        desired_azimuth_char[1] = (char)UART1_Read();
//        desired_azimuth_char[2] = (char)UART1_Read();
//        desired_azimuth_char[3] = (char)UART1_Read();
//        desired_azimuth_char[4] = (char)UART1_Read();
//
//        //State_Select();
//        
//    } else if (rx_msg == 0x62) {
//        
//        robeast_state = robeast_none;
//        State_Select();
//        robeast_state = robeast_height_sweep;
//        State_Select();
//        
//    } else if (rx_msg == 0x63) {
//
//        robeast_state = robeast_none;
//        State_Select();
//        robeast_state = robeast_azimuth_sweep;
//        State_Select();
//        
//    } else if (rx_msg == 0x64) {
//        robeast_state = robeast_none;
//        State_Select();
//        robeast_state = robeast_pause;
//        State_Select();
//    
//    } else if (rx_msg == 0x65) {
//        robeast_state = robeast_none;
//        State_Select();
//        robeast_state = robeast_cancel;
//        State_Select();
//    }
//
//    IFS0bits.U1RXIF = 0;
//
//    while(!(U1STAHbits.URXBE == 1))
//    {
//        *rxTail = U1RXREG;
//
//        // Will the increment not result in a wrap and not result in a pure collision?
//        // This is most often condition so check first
//        if ( ( rxTail    != (rxQueue + UART1_CONFIG_RX_BYTEQ_LENGTH-1)) &&
//             ((rxTail+1) != rxHead) )
//        {
//            rxTail++;
//        } 
//        else if ( (rxTail == (rxQueue + UART1_CONFIG_RX_BYTEQ_LENGTH-1)) &&
//                  (rxHead !=  rxQueue) )
//        {
//            // Pure wrap no collision
//            rxTail = rxQueue;
//        } 
//        else // must be collision
//        {
//            rxOverflowed = true;
//        }
//    }
//}

//void __attribute__((__interrupt__,no_auto_psv)) _QEI1Interrupt(void){
//    LATBbits.LATB14 = 1;
//    qei_counter_clear(); //reset the counter registers
//    IFS3bits.QEI1IF = 0; //clear interrupt flag
//}