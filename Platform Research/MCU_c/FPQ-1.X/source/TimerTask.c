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

static const int TimersCount = 10;
ATimer Timers[ 10 ];


static unsigned int m_HalfSeconds = 0;

void Increment_Timer( void )
{
    if ( m_HalfSeconds == 72000 )	//Hour achived
    {
        m_HalfSeconds = 0;
    }
    else
    {
        m_HalfSeconds++;
    }
}

ATimer* GetNewTimerPointer( void )
{
    static int TimersAllocated = 0;

    ATimer *TimerPointer;

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

void interrupt ISR (void)
{
    if(TMR0IE && TMR0IF)
    {
        INTCONbits.TMR0IF = 0;	// Resets the flag
        Increment_Timer();	// Saves the time
        WriteTimer0( 0 );	// Resets the Timer
        PORTBbits.RB1 = 1;

    }
    else
    {
        PORTBbits.RB3 = 1;
    }
}