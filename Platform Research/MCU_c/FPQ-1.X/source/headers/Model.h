/* 
 * File:   Model.h
 * Author: David
 *
 * Created on April 13, 2013, 5:24 PM
 */
#include "OutputSequences.h"
#include "TimerTask.h"

#include <stdint.h>        /* For uint8_t definition */

#ifndef MODEL_H
#define	MODEL_H

typedef enum
{
    e_Error,    //temp
    e_PressedNo,
    e_PressedYes,
    e_BeingServedNo,
    e_BeingServedYes
}t_ButtonState;

typedef struct AKeyStruct
{
    volatile t_ButtonState  ButtonState;
    volatile uint8_t        NextActionTimer;
    volatile t_Sequences    SequenceIdPressedNo;
    volatile t_Sequences    SequenceIdPressedYes;
    volatile t_Sequences    SequenceIdBeingServedNo;
    volatile t_Sequences    SequenceIdBeingServedYes;
    volatile uint8_t        SequenceState;
//  char                Displaying;
//  time_t              NextAction;
//  time_t              TimeInState;
//  int                 ScreenPosition;
//  bool                FireUpdate;
//  int                 BeingServedBy;

}AKey;

const int KeyCount = 5;

void InitKeys( void );

t_Sequences GetSequence( uint8_t theKeyId );
volatile uint8_t* GetSequenceState( uint8_t theKeyId );
volatile uint8_t* GetKeyTimer( uint8_t theKeyId );


void SetKeyState( uint8_t theKeyId, t_ButtonState theState );
t_ButtonState GetKeyState( uint8_t theKeyId );

#endif	/* MODEL_H */
