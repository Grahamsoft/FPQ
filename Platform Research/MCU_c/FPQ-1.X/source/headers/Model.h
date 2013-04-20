/* 
 * File:   Model.h
 * Author: David
 *
 * Created on April 13, 2013, 5:24 PM
 */

#ifndef MODEL_H
#define	MODEL_H

#include "OutputSequences.h"
#include "TimerTask.h"

typedef enum
{
    e_PressedNo,
    e_PressedYes,
    e_BeingServedNo,
    e_BeingServedYes
}t_ButtonState;

typedef struct AKeyStruct
{
    int                 Id;
    t_ButtonState	State;
    ASequence*          Sequence;
    ATimer*             Timer;
//  char                Displaying;
//  time_t              NextAction;
//  time_t              TimeInState;
//  int                 ScreenPosition;
//  bool                FireUpdate;
//  int                 BeingServedBy;

}AKey;

const int KeyCount = 5;

void InitKeys( void );
void SetKeyState( int theKeyId, t_ButtonState theState );
t_ButtonState GetKeyState( int theKeyId );
ATimer* GetKeyTimer( int theKeyId );

#endif	/* MODEL_H */

