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

typedef enum
{
        e_CommsInit,
        e_CommsOK,
        e_CommsError
} CommsStatus;

void ConfigureUsart( void );
int DataCommsTask( void );

CommsStatus GetCANTxStatus( void );
CommsStatus GetCANRxStatus( void );
CommsStatus GetUARTTxStatus( void );
CommsStatus GetUARTRxStatus( void );

#endif	/* DATACOMMSTASK_H */