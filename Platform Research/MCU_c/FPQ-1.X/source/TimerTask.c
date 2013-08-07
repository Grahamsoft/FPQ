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

const uint8_t c_NoMsecInSec         = 15; //Should be 100, was 15
const uint8_t c_NoSecInMinOrMinInHr = 60;
const uint8_t c_NoHrInDay           = 24;

static t_ATime m_CurrentTime;

static volatile uint8_t m_Ticks = 0;

void InitTime( void )
{
    m_CurrentTime.Day           = 0;
    m_CurrentTime.Hour          = 0;
    m_CurrentTime.Millisecond   = 0;
    m_CurrentTime.Minute        = 0;
    m_CurrentTime.Second        = 0;
}

void Increment_Timer( void )
{
    if( T0IF == 1 )
    {
        m_CurrentTime.Millisecond++;

        if( m_CurrentTime.Millisecond >= c_NoMsecInSec )
        {
            m_CurrentTime.Second++;
            m_CurrentTime.Millisecond = 0;
            if( m_CurrentTime.Second >= c_NoSecInMinOrMinInHr )
            {
                m_CurrentTime.Minute++;
                m_CurrentTime.Second = 0;
                if( m_CurrentTime.Minute >= c_NoSecInMinOrMinInHr )
                {
                    m_CurrentTime.Hour++;
                    m_CurrentTime.Minute = 0;
                    if( m_CurrentTime.Hour >= c_NoHrInDay )
                    {
                        m_CurrentTime.Hour = 0;
                        if( m_CurrentTime.Day < UINT8_MAX )
                        {
                            m_CurrentTime.Day++;
                        }
                    }
                }
            }
        }
    WriteTimer0( 0 );
    T0IF = 0;
    }
}

void CalculateFutureTime( volatile t_ATime *theTimer, uint8_t theMinutes, uint8_t theSeconds, uint8_t theHalfSeconds )
{
    volatile uint8_t CarryOver = 0;

    // ------- Value Checking -------
    //
    if ( theHalfSeconds > c_NoMsecInSec )
    {
        theHalfSeconds = c_NoMsecInSec;
    }

    if ( theSeconds >= c_NoSecInMinOrMinInHr )
    {
        theSeconds = c_NoSecInMinOrMinInHr - 1;
    }

    if ( theMinutes >= c_NoSecInMinOrMinInHr )
    {
        theMinutes = c_NoSecInMinOrMinInHr - 1;
    }

    //------- Calculate Future Time -------
    //
    if( ( theHalfSeconds + m_CurrentTime.Millisecond ) <= c_NoMsecInSec )
    {
        theTimer->Millisecond = theHalfSeconds + m_CurrentTime.Millisecond;
        CarryOver = 0;
    }
    else
    {
        CarryOver = 1;
        theTimer->Millisecond = ( theHalfSeconds + m_CurrentTime.Millisecond ) - c_NoMsecInSec;
    }

    if( ( theSeconds + m_CurrentTime.Second + CarryOver ) < c_NoSecInMinOrMinInHr )
    {
        theTimer->Second = theSeconds + m_CurrentTime.Second + CarryOver;
        CarryOver = 0;
    }
    else
    {
        theTimer->Second = ( theSeconds + m_CurrentTime.Second + CarryOver ) - c_NoSecInMinOrMinInHr;
        CarryOver = 1;       
    }

    if( ( theMinutes + m_CurrentTime.Minute + CarryOver ) < c_NoSecInMinOrMinInHr )
    {
        theTimer->Minute = theMinutes + m_CurrentTime.Minute + CarryOver;
        CarryOver = 0;
    }
    else
    {
        theTimer->Minute = ( theMinutes + m_CurrentTime.Minute + CarryOver ) - c_NoSecInMinOrMinInHr;
        CarryOver = 1;
    }

    if( ( m_CurrentTime.Hour + CarryOver ) < c_NoHrInDay )
    {
        theTimer->Hour = m_CurrentTime.Hour + CarryOver;
        CarryOver = 0;
    }
    else
    {
        if( ( m_CurrentTime.Day + 1 ) < UINT8_MAX )
        {
            theTimer->Day++;
        }
    }
}

bool MaturedTimer( volatile t_ATime *theTimer )
{
    volatile bool ToReturn = false;

    if( m_CurrentTime.Day > theTimer->Day )
    {
        ToReturn = true;
    }
    else if( m_CurrentTime.Day == theTimer->Day )
    {
        if( m_CurrentTime.Hour > theTimer->Hour )
        {
            ToReturn = true;
        }
        else if( m_CurrentTime.Hour == theTimer->Hour )
        {
            if( m_CurrentTime.Minute > theTimer->Minute )
            {
                ToReturn = true;
            }
            else if( m_CurrentTime.Minute == theTimer->Minute )
            {
                if( m_CurrentTime.Second > theTimer->Second )
                {
                    ToReturn = true;
                }
                else if( m_CurrentTime.Second == theTimer->Second )
                {
                    if( m_CurrentTime.Millisecond >= theTimer->Millisecond )
                    {
                        ToReturn = true;
                    }
                }
            }
        }
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


