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
// 8  Vss           Earth               21 RB0           ( Int 2 )
// 9  RA7           Button 3 Switch     20 5v Power
// 10 RA6           Button 3 Colour A   19 Earth
// 11 RC0           Button 3 Colour B   18 RC7           Serial Rx
// 12 RC1           Button 4 Switch     17 RC6           Serial Tx
// 13 RC2           Button 4 Colour A   16 RC5           Button 5 Colour A
// 14 RC3           Button 4 Colour B   15 RC4           Button 5 Colour B
//
/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "timers.h"

#endif

#include "SystemSetup.h"

void ConfigureOscillator()
{
    OSCCON = 0b01111110;
}

void ConfigureTimer( void )
{
    //IPEN = 1;
    
    ei();

    OpenTimer0( TIMER_INT_ON &//Should be ON
    T0_8BIT &
    T0_SOURCE_INT &
    T0_PS_1_256 );

//	RCONbits.IPEN 		= 1;	//Enable Interrupt Priorities
//	INTCONbits.GIEL 	= 1; 	//Enable Low Priority Interrupt
//	INTCON2bits.TMR0IP	= 0;	//TMR0 set to Low Priority Interrupt
//	INTCONbits.GIE 		= 1; 	//Enable GlobalInterrupt
	INTCONbits.TMR0IE 	= 0;	//Enable Timer0 Interrupt

        //T0CONbits.TMR0ON = 1; //Start Timer0
}

void ConfigurePorts( void )
{
    ADCON1 = 0b00001111;
    TRISA = 0b10001001;
    TRISB = 0b00000000;
    TRISC = 0b00000010;

    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
}
