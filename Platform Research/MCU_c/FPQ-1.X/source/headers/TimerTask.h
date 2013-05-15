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

bool MaturedTimer( volatile uint24_t *theTimer );
uint24_t CalculateFutureTime( uint8_t theMinutes, uint8_t theSeconds, uint8_t theHalfSeconds );
void Increment_Timer( void );

#endif	/* TIMERTASK_H */
