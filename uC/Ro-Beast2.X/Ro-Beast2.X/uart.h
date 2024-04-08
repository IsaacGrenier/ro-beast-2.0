/*
 * File:   uart.h
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#ifndef _UART_H
#define _UART_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

void UART1_Initialize(void);
uint8_t UART1_Read( void);
void UART1_Write( uint8_t byte);
bool UART1_IsRxReady(void);
bool UART1_IsTxReady(void);
bool UART1_IsTxDone(void);

void UART1_SetTxInterruptHandler(void (* interruptHandler)(void));
void UART1_Transmit_CallBack(void);
void UART1_SetRxInterruptHandler(void (* interruptHandler)(void));
void UART1_Receive_CallBack(void);

void Real_Time_Update(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
    
#endif  // _UART_H
