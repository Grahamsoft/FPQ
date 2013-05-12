/* 
 * File:   TimerTask.h
 * Author: David
 *
 * Created on April 8, 2013, 7:53 PM
 */

#ifndef TIMERTASK_H
#define	TIMERTASK_H

#include <stdbool.h>       /* For true/false definition */

typedef struct ATimerStruct
{
    int     Matured;
    int     FutureTime;

}ATimer;

int SetTimer( ATimer *theTimer, int theHours, int theMinutes, int theSeconds, int theHalfSeconds );
void ClearTimer( ATimer *theTimer );
bool MaturedTimer( ATimer *theTimer );
ATimer* GetNewTimerPointer( void );
uint8_t CalculateFutureTime( uint8_t theMinutes, uint8_t theSeconds, uint8_t theHalfSeconds );

#endif	/* TIMERTASK_H */
