/*
 * File:   uart.c
 * Author: Ro-Beast Battle Busters (with assistance from the MCC)
 */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "xc.h"
#include "uart.h"
#include "state_select.h"
#include "global_variables.h"
#include "tmr1.h"

static uint8_t * volatile rxTail;
static uint8_t *rxHead;
static uint8_t *txTail;
static uint8_t * volatile txHead;
static bool volatile rxOverflowed;

#define UART1_CONFIG_TX_BYTEQ_LENGTH (8+1)
#define UART1_CONFIG_RX_BYTEQ_LENGTH (8+1)

static uint8_t txQueue[UART1_CONFIG_TX_BYTEQ_LENGTH];
static uint8_t rxQueue[UART1_CONFIG_RX_BYTEQ_LENGTH];

void (*UART1_TxDefaultInterruptHandler)(void);
void (*UART1_RxDefaultInterruptHandler)(void);

void UART1_Initialize(void)
{
    IEC0bits.U1TXIE = 0;
    IEC0bits.U1RXIE = 0;

    // URXEN disabled; RXBIMD RXBKIF flag when Break makes low-to-high transition after being low for at least 23/11 bit periods; UARTEN enabled; MOD Asynchronous 8-bit UART; UTXBRK disabled; BRKOVR TX line driven by shifter; UTXEN disabled; USIDL disabled; WAKE disabled; ABAUD disabled; BRGH enabled; 
    // Data Bits = 8; Parity = None; Stop Bits = 1 Stop bit sent, 1 checked at RX;
    U1MODE = (0x8080 & ~(1<<15));  // disabling UART ON bit
    // STSEL 1 Stop bit sent, 1 checked at RX; BCLKMOD disabled; SLPEN disabled; FLO Off; BCLKSEL FOSC/2; C0EN disabled; RUNOVF disabled; UTXINV disabled; URXINV disabled; HALFDPLX disabled; 
    U1MODEH = 0x00;
    // OERIE disabled; RXBKIF disabled; RXBKIE disabled; ABDOVF disabled; OERR disabled; TXCIE disabled; TXCIF disabled; FERIE disabled; TXMTIE disabled; ABDOVE disabled; CERIE disabled; CERIF disabled; PERIE disabled; 
    U1STA = 0x00;
    // URXISEL RX_ONE_WORD; UTXBE enabled; UTXISEL TX_BUF_EMPTY; URXBE enabled; STPMD disabled; TXWRE disabled; 
    U1STAH = 0x22;
    //U1STAHbits.URXISEL = 5;
    // BaudRate = 9600; Frequency = 4000000 Hz; BRG 103; 
    U1BRG = 0x67;
    // BRG 0; 
    U1BRGH = 0x00;
    // P1 0; 
    U1P1 = 0x00;
    // P2 0; 
    U1P2 = 0x00;
    // P3 0; 
    U1P3 = 0x00;
    // P3H 0; 
    U1P3H = 0x00;
    // TXCHK 0; 
    U1TXCHK = 0x00;
    // RXCHK 0; 
    U1RXCHK = 0x00;
    // T0PD 1 ETU; PTRCL disabled; TXRPT Retransmit the error byte once; CONV Direct logic; 
    U1SCCON = 0x00;
    // TXRPTIF disabled; TXRPTIE disabled; WTCIF disabled; WTCIE disabled; BTCIE disabled; BTCIF disabled; GTCIF disabled; GTCIE disabled; RXRPTIE disabled; RXRPTIF disabled; 
    U1SCINT = 0x00;
    // ABDIF disabled; WUIF disabled; ABDIE disabled; 
    U1INT = 0x00;
    
    txHead = txQueue;
    txTail = txQueue;
    rxHead = rxQueue;
    rxTail = rxQueue;
   
    rxOverflowed = false;

    UART1_SetTxInterruptHandler(&UART1_Transmit_CallBack);

    UART1_SetRxInterruptHandler(&UART1_Receive_CallBack);

    IEC0bits.U1RXIE = 1;
    
    //Make sure to set LAT bit corresponding to TxPin as high before UART initialization
    U1MODEbits.UARTEN = 1;   // enabling UART ON bit
    U1MODEbits.UTXEN = 1;
    U1MODEbits.URXEN = 1;
}

void UART1_SetTxInterruptHandler(void (* interruptHandler)(void))
{
    if(interruptHandler == NULL)
    {
        UART1_TxDefaultInterruptHandler = &UART1_Transmit_CallBack;
    }
    else
    {
        UART1_TxDefaultInterruptHandler = interruptHandler;
    }
} 

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1TXInterrupt ( void )
{
    if(UART1_TxDefaultInterruptHandler)
    {
        UART1_TxDefaultInterruptHandler();
    }
    
    if(txHead == txTail)
    {
        IEC0bits.U1TXIE = 0;
    }
    else
    {
        IFS0bits.U1TXIF = 0;

        while(!(U1STAHbits.UTXBF == 1))
        {
            U1TXREG = *txHead++;

            if(txHead == (txQueue + UART1_CONFIG_TX_BYTEQ_LENGTH))
            {
                txHead = txQueue;
            }

            // Are we empty?
            if(txHead == txTail)
            {
                break;
            }
        }
    }
}

void __attribute__ ((weak)) UART1_Transmit_CallBack ( void )
{ 

}

void UART1_SetRxInterruptHandler(void (* interruptHandler)(void))
{
    if(interruptHandler == NULL)
    {
        UART1_RxDefaultInterruptHandler = &UART1_Receive_CallBack;
    }
    else
    {
        UART1_RxDefaultInterruptHandler = interruptHandler;
    }
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1RXInterrupt( void )
{
    IFS0bits.U1RXIF = 0;
    
//    if(UART1_RxDefaultInterruptHandler)
//    {
//        UART1_RxDefaultInterruptHandler();
//    }

    
    if (rx_msg == 0x00) {
        rx_msg = U1RXREG;
    } else if (rx_msg == 'a'){
        if (uart_index < 5){
            desired_height_char[uart_index] = U1RXREG;
        } else if (uart_index < 10) {
            desired_azimuth_char[uart_index - 5] = U1RXREG;
        }
        uart_index++;
        if (uart_index == 10){
            robeast_state = robeast_position;
            State_Select();    
        }
    } else if (rx_msg == 'b'){
        if (uart_index < 5){
            desired_azimuth_char[uart_index] = U1RXREG;
        } else if (uart_index < 10) {
            desired_azimuth_interval_char[uart_index - 5] = U1RXREG;
        } else if (uart_index < 12) {
            desired_azimuth_speed_char[uart_index - 10] = U1RXREG;
        }
        uart_index++;
        if (uart_index == 12){
            robeast_state = robeast_azimuth_sweep;
            State_Select();    
        }
    } else if (rx_msg == 'c'){
        if (uart_index < 5){
            desired_height_char[uart_index] = U1RXREG;
        } else if (uart_index < 9) {
            desired_height_interval_char[uart_index - 5] = U1RXREG;
        } else if (uart_index < 12) {
            desired_height_speed_char[uart_index - 9] = U1RXREG;
        }
        uart_index++;
        if (uart_index == 12){
            robeast_state = robeast_height_sweep;
            State_Select();    
        }
    } else if (rx_msg == 'd'){
        
    } else if (rx_msg == 'e'){
        robeast_state = robeast_init;
        State_Select();
    }
    
}

void __attribute__ ((weak)) UART1_Receive_CallBack(void)
{

}

uint8_t UART1_Read(void)
{
    uint8_t data = 0;

    while (rxHead == rxTail )
    {
    }
    
    data = *rxHead;

    rxHead++;

    if (rxHead == (rxQueue + UART1_CONFIG_RX_BYTEQ_LENGTH))
    {
        rxHead = rxQueue;
    }
    return data;
}

void UART1_Write( uint8_t byte)
{
    while(UART1_IsTxReady() == 0)
    {
    }

    *txTail = byte;

    txTail++;
    
    if (txTail == (txQueue + UART1_CONFIG_TX_BYTEQ_LENGTH))
    {
        txTail = txQueue;
    }

    IEC0bits.U1TXIE = 1;
}

bool UART1_IsRxReady(void)
{    
    return !(rxHead == rxTail);
}

bool UART1_IsTxReady(void)
{
    uint16_t size;
    uint8_t *snapshot_txHead = (uint8_t*)txHead;
    
    if (txTail < snapshot_txHead)
    {
        size = (snapshot_txHead - txTail - 1);
    }
    else
    {
        size = ( UART1_CONFIG_TX_BYTEQ_LENGTH - (txTail - snapshot_txHead) - 1 );
    }
    
    return (size != 0);
}

bool UART1_IsTxDone(void)
{
    if(txTail == txHead)
    {
        return (bool)U1STAbits.TRMT;
    }
    
    return false;
}

void Real_Time_Update(void){
    int i;
    
    UART1_Write('A');
    for (i = 0; i < strlen(curr_height_char); i++) {
        UART1_Write(curr_height_char[i]);
    }
    
    UART1_Write('B');
    for (i = 0; i < strlen(curr_azimuth_char); i++) {
        UART1_Write(curr_azimuth_char[i]);
    }
    
    UART1_Write('C');
    for (i = 0; i < strlen(curr_height_interval_char); i++) {
        UART1_Write(curr_height_interval_char[i]);
    }
    
    UART1_Write('D');
    for (i = 0; i < strlen(curr_azimuth_interval_char); i++) {
        UART1_Write(curr_azimuth_interval_char[i]);
    }
    
    UART1_Write('E');
    for (i = 0; i < strlen(curr_height_speed_char); i++) {
        UART1_Write(curr_height_speed_char[i]);
    }
    
    UART1_Write('F');
    for (i = 0; i < strlen(curr_azimuth_speed_char); i++) {
        UART1_Write(curr_azimuth_speed_char[i]);
    }

    UART1_Write('G');
    for (i = 0; i < strlen(curr_tilt_char); i++) {
        UART1_Write(curr_tilt_char[i]);
    }
    
    UART1_Write('H');
    for (i = 0; i < strlen(curr_height_current_char); i++) {
        UART1_Write(curr_height_current_char[i]);
    }
    
    UART1_Write('I');
    for (i = 0; i < strlen(curr_azimuth_current_char); i++) {
        UART1_Write(curr_azimuth_current_char[i]);
    }    
    
}



