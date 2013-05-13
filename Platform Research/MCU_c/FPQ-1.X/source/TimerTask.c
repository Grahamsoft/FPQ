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

#if defined(__XC) || defined(HI_TECH_C)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include "timers.h"

#endif

#include "TimerTask.h"

// Private Signatures ----
//void Increment_Timer( void );

static const uint8_t TimersCount = 10;
ATimer Timers[ 10 ];
static volatile uint8_t m_HalfSeconds = 0;
const uint8_t AHour = 72000;

static unsigned int m_Ticks = 0;

void Increment_Timer( void )
{
    if ( T0IF == 1 )
    {
        m_Ticks++;

        if ( m_Ticks == 15 )
        {
            m_Ticks = 1;

            m_HalfSeconds++;
            if ( m_HalfSeconds == AHour )	//Hour achived
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

uint8_t CalculateFutureTime( uint8_t theMinutes, uint8_t theSeconds, uint8_t theHalfSeconds )
{
    uint8_t FutureTime = theHalfSeconds;
    FutureTime =+ ( theSeconds * 2 );
    FutureTime =+ ( theMinutes * ( 60 * 2 ) );
    FutureTime =+ m_HalfSeconds;
    
    if ( FutureTime > AHour )
    {
        FutureTime =- AHour;
    }
    
    return FutureTime;
}

uint8_t GetCurrentTime( void )
{
    return m_HalfSeconds;
}

ATimer* GetNewTimerPointer( void )
{
    static int TimersAllocated = 0;

    ATimer *TimerPointer = 0;

    if ( TimersAllocated < TimersCount )
    {
        TimerPointer = &Timers[ TimersAllocated ];
        TimersAllocated++;
    }

    return TimerPointer;
}

int SetTimer( ATimer *theTimer, int theHours, int theMinutes, int theSeconds, int theHalfSeconds )
{
    int FutureTime = theHalfSeconds;
    FutureTime =+ ( theSeconds * 2 );
    FutureTime =+ ( theMinutes * ( 60 * 2 ) );
    FutureTime =+ ( theHours * ( 60 * ( 60 * 2 ) ) );

    theTimer->FutureTime = FutureTime;
    theTimer->Matured = false;
}

void ClearTimer( ATimer *theTimer )
{
    theTimer->FutureTime = 0;
    theTimer->Matured = false;
}

bool MaturedTimer( ATimer *theTimer )
{
    return theTimer->Matured;
}

void interrupt low_priority LowPriorityISR( void )
{
    //volatile uint8_t dave = 1;
    WriteTimer0( 0 );
    INTCONbits.TMR0IF = 0;
PORTAbits.RA6 = 1;
            if ( PORTAbits.RA6 == 1 )
        {
            PORTAbits.RA6 = 0;
            PORTCbits.RC0 = 1;
        }
        else
        {
            PORTAbits.RA6 = 1;
            PORTCbits.RC0 = 0;
        }
}

void interrupt ISR( void )
{
    PORTAbits.RA6 = 1;
    if( TMR0IE && TMR0IF )
    {        
        Increment_Timer();	// Saves the time
        WriteTimer0( 0 );	// Resets the Timer
        INTCONbits.TMR0IF = 0;	// Resets the flag
        
        //PORTBbits.RB1 = 1;

            if ( PORTAbits.RA6 == 1 )
        {
            PORTAbits.RA6 = 0;
            PORTCbits.RC0 = 1;
        }
        else
        {
            PORTAbits.RA6 = 1;
            PORTCbits.RC0 = 0;
        }
    }
}


