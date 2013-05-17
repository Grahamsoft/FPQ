/* 
 * File:   TimerTask.h
 * Author: David
 *
 * Created on April 8, 2013, 7:53 PM
 */
#if defined(__XC) || defined(HI_TECH_C)
#include <stdlib.h>
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#endif

#ifndef TIMERTASK_H
#define	TIMERTASK_H

typedef struct ATimeStruct
{
    volatile uint8_t Millisecond;
    volatile uint8_t Second;
    volatile uint8_t Minute;
    volatile uint8_t Hour;
    volatile uint8_t Day;
}t_ATime;

void InitTime( void );
bool MaturedTimer( volatile t_ATime *theTimer );
void CalculateFutureTime( volatile t_ATime *theTimer, uint8_t theMinutes, uint8_t theSeconds, uint8_t theHalfSeconds );
void Increment_Timer( void );

#endif	/* TIMERTASK_H */
