/* 
 * File:   Model.h
 * Author: David
 *
 * Created on April 13, 2013, 5:24 PM
 */
#include "OutputSequences.h"
#include "TimerTask.h"

#ifndef MODEL_H
#define	MODEL_H

typedef enum
{
    e_PressedNo,
    e_PressedYes,
    e_BeingServedNo,
    e_BeingServedYes
}t_ButtonState;

typedef struct AKeyStruct
{
    t_ButtonState   ButtonState;
    int             Timer;
    t_Sequences     SequenceIdPressedNo;
    t_Sequences     SequenceIdPressedYes;
    t_Sequences     SequenceIdBeingServedNo;
    t_Sequences     SequenceIdBeingServedYes;
    int             SequenceState;
//  char                Displaying;
//  time_t              NextAction;
//  time_t              TimeInState;
//  int                 ScreenPosition;
//  bool                FireUpdate;
//  int                 BeingServedBy;

}AKey;

const int KeyCount = 5;

void InitKeys( void );

t_Sequences GetSequence( int theKeyId );
int* GetSequenceState( int theKeyId );
int* GetTimer( int theKeyId );


void SetKeyState( int theKeyId, t_ButtonState theState );
t_ButtonState GetKeyState( int theKeyId );

#endif	/* MODEL_H */

