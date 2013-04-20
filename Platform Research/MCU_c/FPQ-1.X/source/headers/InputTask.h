/* 
 * File:   InputTask.h
 * Author: David
 *
 * Created on April 13, 2013, 4:54 PM
 */

#ifndef INPUTTASK_H
#define	INPUTTASK_H

#include <stdbool.h>       /* For true/false definition */

void InputTask( void );
void MonitorButton( int theId );
bool ButtonBeingPressed( int theId );

#endif	/* INPUTTASK_H */

