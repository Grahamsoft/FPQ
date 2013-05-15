/* 
 * File:   InputTask.h
 * Author: David
 *
 * Created on April 13, 2013, 4:54 PM
 */

#ifndef INPUTTASK_H
#define	INPUTTASK_H

#include <stdbool.h>       /* For true/false definition */
#include <stdint.h>        /* For uint8_t definition */

void InputTask( void );
void MonitorButton( uint8_t theId );
bool ButtonBeingPressed( uint8_t theId );

#endif	/* INPUTTASK_H */

