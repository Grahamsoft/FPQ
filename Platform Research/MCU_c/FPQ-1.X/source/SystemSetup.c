/******************************************************************************/
/* Pin Diagram                                                                */
/******************************************************************************/
//
// PIC18F2585
//
// 1  MCLR/Vpp/RE3  None                28 RB7           PGD Programming Data
// 2  RA0           Button 1 Switch     27 RB6           PGC Programming
// 3  RA1           Button 1 Colour A   26 RB5           PGM Programming
// 4  RA2           Button 1 Colour B   25 RB4           Button 5 Switch
// 5  RA3           Button 2 Switch     24 RB3           CAN Rx
// 6  RA4           Button 2 Colour A   23 RB2           CAN Tx
// 7  RA5           Button 2 Colour B   22 RB1           ( Int 1 )
// 8  Vss           Earth               21 RB0           ( Int 2 )          A. Button 6 Switch      B. iButton 1-wire   C. Movement Senor
// 9  RA7           Button 3 Switch     20 5v Power
// 10 RA6           Button 3 Colour A   19 Earth
// 11 RC0           Button 3 Colour B   18 RC7           Serial Rx          A. Button 6 Colour A    B. Bell
// 12 RC1           Button 4 Switch     17 RC6           Serial Tx          A. Button 6 Colour B    B. LCD Out
// 13 RC2           Button 4 Colour A   16 RC5           Button 5 Colour A
// 14 RC3           Button 4 Colour B   15 RC4           Button 5 Colour B
//
// MCP2551
//
// 1  Txd           CAN Tx              8  Rs            Slope-Control Input
// 2  Vss           5v Power            7  CANH          CAN High-Level Volt I/O
// 3  Vdd           Earth               6  CANL          CAN Low-Level Volt I/O
// 4  Rxd           CAN Rx              5  Vref          Reference Output Voltage
/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#include <xc.h>         /* XC8 General Include File */
#include <stdint.h>     /* For uint8_t definition */
#include <stdbool.h>    /* For true/false definition */
#include <timers.h>
#include <usart.h>

#include "headers/SystemSetup.h"

void ConfigureHardware()
{
    // Configure Oscillator

    OSCCON = 0b01111110;
   
    // Configure Ports
    
    ADCON1 = 0b00001111;
    TRISA = 0b10001001;
    TRISB = 0b00001000;     // <3> for CAN
    TRISC = 0b00000010;

    PORTA = 0;
    PORTB = 0;
    PORTC = 0;

    // Configure Timer

    //IPEN = 1;

    ei();

    OpenTimer0( TIMER_INT_ON &//Should be ON
    T0_8BIT &
    T0_SOURCE_INT &
    T0_PS_1_64 );

    INTCONbits.TMR0IE 	= 0;	//Enable Timer0 Interrupt

    // Configure Usart

    OpenUSART( USART_TX_INT_OFF &
                       USART_RX_INT_OFF &
                       USART_ASYNCH_MODE &
                       USART_EIGHT_BIT &
                       USART_CONT_RX &
                       USART_BRGH_LOW,
                       12 );
}