/*
 * File:   TimerManager.c
 * Author: David Graham
 *
 */

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#include <stdio.h>
#if defined(__XC) || defined(HI_TECH_C)

//#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "timers.h"
#include "TimerTask.h"

// Private Signatures ----
//void Increment_Timer( void );

static const uint8_t TimersCount = 10;
static volatile uint24_t m_HalfSeconds = 0;
const uint24_t AHourOfHalfSeconds = 72000;

static volatile uint8_t m_Ticks = 0;

void Increment_Timer( void )
{
    if ( T0IF == 1 )
    {
        m_Ticks++;

        if ( m_Ticks == 15 )
        {
            m_Ticks = 1;

            if ( m_HalfSeconds == AHourOfHalfSeconds )	//Hour achived
            {
                m_HalfSeconds = 0;
            }
            else
            {
                m_HalfSeconds++;
            }
        }

        WriteTimer0( 0 );
        T0IF = 0;
    }
}

uint24_t CalculateFutureTime( uint8_t theMinutes, uint8_t theSeconds, uint8_t theHalfSeconds )
{
    volatile uint24_t FutureTime = theHalfSeconds;
    FutureTime += ( theSeconds * 2 );
    FutureTime += ( theMinutes * ( 60 * 2 ) );
    FutureTime += m_HalfSeconds;
    
    if ( FutureTime > AHourOfHalfSeconds )
    {
        FutureTime -= AHourOfHalfSeconds;
    }
       
    return FutureTime;
}

bool MaturedTimer( volatile uint24_t *theTimer )
{
    volatile bool ToReturn = false;

    if ( m_HalfSeconds > *theTimer )
    {
        ToReturn = true;
    }

    return ToReturn;
}

void interrupt low_priority LowPriorityISR( void )
{
    //volatile uint8_t dave = 1;
//    WriteTimer0( 0 );
//    INTCONbits.TMR0IF = 0;
//PORTAbits.RA6 = 1;
//            if ( PORTAbits.RA6 == 1 )
//        {
//            PORTAbits.RA6 = 0;
//            PORTCbits.RC0 = 1;
//        }
//        else
//        {
//            PORTAbits.RA6 = 1;
//            PORTCbits.RC0 = 0;
//        }
}

void interrupt ISR( void )
{
//    PORTAbits.RA6 = 1;
//    if( TMR0IE && TMR0IF )
//    {
//        Increment_Timer();	// Saves the time
//        WriteTimer0( 0 );	// Resets the Timer
//        INTCONbits.TMR0IF = 0;	// Resets the flag
//
//        //PORTBbits.RB1 = 1;
//
//            if ( PORTAbits.RA6 == 1 )
//        {
//            PORTAbits.RA6 = 0;
//            PORTCbits.RC0 = 1;
//        }
//        else
//        {
//            PORTAbits.RA6 = 1;
//            PORTCbits.RC0 = 0;
//        }
//    }
}


