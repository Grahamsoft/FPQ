/******************************************************************************/
/* Pin Diagram                                                                */
/******************************************************************************/
//
//
// PIC18F2585 Rev2 Step Detection A - 32 In
//
// 1  MCLR/Vpp/RE3  None                28 RB7           PGD Programming Data
// 2  RA0           4x4 Button 1 Col 4  27 RB6           PGC Programming
// 3  RA1           4x4 Button 1 Col 3  26 RB5           PGM Programming
// 4  RA2           4x4 Button 1 Col 2  25 RB4
// 5  RA3           4x4 Button 1 Col 1  24 RB3           CAN Rx
// 6  RA4           4x4 Button 1 Row 4  23 RB2           CAN Tx
// 7  RA5           4x4 Button 1 Row 3  22 RB1 Int 1
// 8  Vss           Earth               21 RB0 Int 2
// 9  RA7           4x4 Button 1 Row 1  20 5v Power
// 10 RA6           4x4 Button 1 Row 2  19 Earth
// 11 RC0           4x4 Button 2 Col 4  18 RC7           4x4 Button 2 Row 1
// 12 RC1           4x4 Button 2 Col 3  17 RC6           4x4 Button 2 Row 2
// 13 RC2           4x4 Button 2 Col 2  16 RC5           4x4 Button 2 Row 3
// 14 RC3           4x4 Button 2 Col 1  15 RC4           4x4 Button 2 Row 4
//
// PIC18F2585 Rev2 Step Detection B - 22 In
//
// 1  MCLR/Vpp/RE3  None                28 RB7 PGD       Button 22
// 2  RA0           Button 1            27 RB6 PGC       Button 21
// 3  RA1           Button 2            26 RB5 PGM       Button 20
// 4  RA2           Button 3            25 RB4           Button 19
// 5  RA3           Button 4            26 RB3 CAN Rx
// 6  RA4           Button 5            23 RB2 CAN Tx
// 7  RA5           Button 6            22 RB1 Int 1     Button 18
// 8  Vss           Earth               21 RB0 Int 2     Button 17
// 9  RA7           Button 7            20 5v Power
// 10 RA6           Button 8            19 Earth
// 11 RC0           Button 9            18 RC7 Serial Rx Button 16
// 12 RC1           Button 10           17 RC6 Serial Tx Button 15
// 13 RC2           Button 11           16 RC5           Button 14
// 14 RC3           Button 12           15 RC4           Button 13
//
/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#include <xc.h>         /* XC8 General Include File */
#include <stdint.h>     /* For uint8_t definition */
#include <stdbool.h>    /* For true/false definition */
#include <timers.h>
#include <usart.h>

#include "SystemSetup.h"

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