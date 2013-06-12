/* 
 * File:   DataCommsTask.h
 * Author: David
 *
 * Created on April 8, 2013, 7:38 PM
 */

#ifndef DATACOMMSTASK_H
#define	DATACOMMSTASK_H

#include <stdbool.h>       /* For true/false definition */
#include <stdint.h>        /* For uint8_t definition */

void ConfigureUsart( void );
int DataCommsTask( void );
void CustomerWating( uint8_t theKeyId );
void CustomerBeingServed( uint8_t theKeyId );

#endif	/* DATACOMMSTASK_H */