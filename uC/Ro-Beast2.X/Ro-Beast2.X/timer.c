/*
 * File:   timer.c
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#include <stdio.h>
#include <string.h>
#include "timer.h"
#include "system.h"
#include "uart.h"
#include "global_variables.h"
#include "inputs.h"

//timer_struct timer[timer_count];

//void (*TMR1_InterruptHandler)(void) = NULL;
//void TMR1_CallBack(void);
//
//typedef struct _TMR_OBJ_STRUCT
//{
//    /* Timer Elapsed */
//    volatile bool           timerElapsed;
//    /*Software Counter value*/
//    volatile uint8_t        count;
//
//} TMR_OBJ;
//
//static TMR_OBJ tmr1_obj;
//
//void TMR1_Initialize(void)
//{
//    //TMR 0; 
//    TMR1 = 0x00;
//    //Period = 0.1 s; Frequency = 8000000 Hz; PR 6249; 
//    PR1 = 0x30D3;
//    //TCKPS 1:64; PRWIP Write complete; TMWIP Write complete; TON enabled; TSIDL disabled; TCS External; TECS FRC; TSYNC disabled; TMWDIS disabled; TGATE disabled; 
//    T1CON = 0x8322;
//
//    if(TMR1_InterruptHandler == NULL)
//    {
//        TMR1_SetInterruptHandler(&TMR1_CallBack);
//    }
//
//    IFS0bits.T1IF = false;
//    IEC0bits.T1IE = true;
//	
//    tmr1_obj.timerElapsed = false;
//
//}
//
////void Increment_Timers()
////{
////    for(int i = 0; i < timer_count; i++){
////        if(timer[i].enable == 0){
////            timer[i].present_count = 0;
////            timer[i].end = 0;
////        } else {
////            timer[i].present_count = timer[i].present_count + (unsigned long)loop_time;
////            if(timer[i].present_count < timer[i].final_count){
////                timer[i].end = 0;
////            } else {
////                timer[i].present_count = timer[i].final_count;
////                timer[i].end = 1;
////            }
////        }
////    }
////}
//
////void Clear_Timers()
////{
////    for(int i = 0; i < timer_count; i++){
////        timer[i].enable = 0;
////        timer[i].present_count = 0;
////        timer[i].final_count = 0;
////        timer[i].end = 0;
////    }
////}
//
//void __attribute__ ( ( interrupt, no_auto_psv ) ) _T1Interrupt (  )
//{
//
//    //Increment_Timers();
//    read_limit_switches();
//    LATDbits.LATD8 ^= 1;
//
//    // Real-time feedback
//      int i;
////    for (i = 0; i < strlen(curr_height_char); i++) {
////        UART1_Write(curr_height_char[i]);
////    }
////
////    for (i = 0; i < strlen(curr_azimuth_char); i++) {
////        UART1_Write(curr_azimuth_char[i]);
////    }
////
////    for (i = 0; i < strlen(curr_height_interval_char); i++) {
////        UART1_Write(curr_height_interval_char[i]);
////    }
////
////    for (i = 0; i < strlen(curr_azimuth_interval_char); i++) {
////        UART1_Write(curr_azimuth_interval_char[i]);
////    }
//
////    for (i = 0; i < strlen(curr_height_speed_char); i++) {
////        UART1_Write(curr_height_speed_char[i]);
////    }
////
////    for (i = 0; i < strlen(curr_azimuth_speed_char); i++) {
////        UART1_Write(curr_azimuth_speed_char[i]);
////    }
//
//    UART1_Write('G');
//    for (i = 0; i < strlen(curr_tilt_char); i++) {
//        UART1_Write(curr_tilt_char[i]);
//    }
//
////    for (i = 0; i < strlen(curr_height_current_char); i++) {
////        UART1_Write(curr_height_current_char[i]);
////    }
////
////    for (i = 0; i < strlen(curr_azimuth_current_char); i++) {
////        UART1_Write(curr_azimuth_current_char[i]);
////    }
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
//
//void TMR1_Period16BitSet( uint16_t value )
//{
//    /* Update the counter values */
//    PR1 = value;
//    /* Reset the status information */
//    tmr1_obj.timerElapsed = false;
//}
//
//uint16_t TMR1_Period16BitGet( void )
//{
//    return( PR1 );
//}
//
//void TMR1_Counter16BitSet ( uint16_t value )
//{
//    /* Update the counter values */
//    TMR1 = value;
//    /* Reset the status information */
//    tmr1_obj.timerElapsed = false;
//}
//
//uint16_t TMR1_Counter16BitGet( void )
//{
//    return( TMR1 );
//}
//
//
//void __attribute__ ((weak)) TMR1_CallBack(void)
//{
//    // Add your custom callback code here
//}
//
//void  TMR1_SetInterruptHandler(void (* InterruptHandler)(void))
//{ 
//    IEC0bits.T1IE = false;
//    TMR1_InterruptHandler = InterruptHandler; 
//    IEC0bits.T1IE = true;
//}
//
//void TMR1_Start( void )
//{
//    /* Reset the status information */
//    tmr1_obj.timerElapsed = false;
//
//    /*Enable the interrupt*/
//    IEC0bits.T1IE = true;
//
//    /* Start the Timer */
//    T1CONbits.TON = 1;
//}
//
//void TMR1_Stop( void )
//{
//    /* Stop the Timer */
//    T1CONbits.TON = false;
//
//    /*Disable the interrupt*/
//    IEC0bits.T1IE = false;
//}
//
//bool TMR1_GetElapsedThenClear(void)
//{
//    bool status;
//    
//    status = tmr1_obj.timerElapsed;
//
//    if(status == true)
//    {
//        tmr1_obj.timerElapsed = false;
//    }
//    return status;
//}
//
//int TMR1_SoftwareCounterGet(void)
//{
//    return tmr1_obj.count;
//}
//
//void TMR1_SoftwareCounterClear(void)
//{
//    tmr1_obj.count = 0; 
//}
