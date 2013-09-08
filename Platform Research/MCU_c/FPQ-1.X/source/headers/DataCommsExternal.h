/* 
 * File:   DataCommsExternal.h
 * Author: David
 *
 * Created on September 8, 2013, 2:28 PM
 */

#include "TimerTask.h"

#ifndef DATACOMMSEXTERNAL_H
#define	DATACOMMSEXTERNAL_H

typedef enum
{
        e_CommsInit,
        e_CommsOK,
        e_CommsError,
        e_CommsBusy
} t_CommsState;

typedef struct ACommsStatusStruct
{
    volatile t_CommsState  CommsState;
    volatile t_ATime        LastUpdate;
}s_CommsStatus;

s_CommsStatus GetCANTxStatus( void );
s_CommsStatus GetCANRxStatus( void );
s_CommsStatus GetUARTTxStatus( void );
s_CommsStatus GetUARTRxStatus( void );

char UartCharRead ( void );
void UartCharWrite ( char theChar );
void UartStringRead ( char *theStringBuffer,  unsigned char theLength );
void UartStringWrite ( char *theString );

#endif	/* DATACOMMSEXTERNAL_H */

