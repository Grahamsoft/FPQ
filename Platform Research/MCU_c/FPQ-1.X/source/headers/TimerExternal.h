/* 
 * File:   TimerExternal.h
 * Author: David
 *
 * Created on September 8, 2013, 8:14 PM
 */

#ifndef TIMEREXTERNAL_H
#define	TIMEREXTERNAL_H

#include <stdbool.h>       /* For true/false definition */

typedef struct ATimeStruct
{
    volatile uint8_t Millisecond;
    volatile uint8_t Second;
    volatile uint8_t Minute;
    volatile uint8_t Hour;
    volatile uint8_t Day;
}t_ATime;

bool MaturedTimer( volatile t_ATime *theTimer );
void CalculateFutureTime( volatile t_ATime *theTimer, uint8_t theMinutes, uint8_t theSeconds, uint8_t theHalfSeconds );
void GetTime( volatile t_ATime * theTimePointer );

#endif	/* TIMEREXTERNAL_H */

