/* 
 * File:   DataCommsExternal.h
 * Author: David
 *
 * Created on September 8, 2013, 2:28 PM
 */

#ifndef DATACOMMSEXTERNAL_H
#define	DATACOMMSEXTERNAL_H

#include "TimerExternal.h"

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

// typedef enum
enum t_CommsDevice
{
    e_CommsDeviceCanTx  = 0,
    e_CommsDeviceCanRx  = 1,
    e_CommsDeviceUartTx = 2,
    e_CommsDeviceUartRx = 3,
    e_CommsDeviceCount  = 4     // Always keep last
};
//} t_CommsDevice;

char UartCharRead ( void );
void UartCharWrite ( char theChar );
void UartStringRead ( char *theStringBuffer,  unsigned char theLength );
void UartStringWrite ( char *theString );

#endif	/* DATACOMMSEXTERNAL_H */

