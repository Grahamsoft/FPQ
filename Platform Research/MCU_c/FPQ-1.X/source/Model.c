#include "Model.h"

AKey m_Keys[ /*KeyCount*/ 5 ];

void SetKeyState( int theKeyId, t_ButtonState theState  )
{
    m_Keys[ theKeyId ].State = theState;
}

t_ButtonState GetKeyState( int theKeyId )
{
    return m_Keys[ theKeyId ].State;
}

ATimer* GetKeyTimer( int theKeyId )
{
    return m_Keys[ theKeyId ].Timer;
}

void InitKeys()
{
    InitSequences();

    ASequence *SequencePointer = GetSequencePointer( 0 );

    for( int i = 0; i < KeyCount; i++ )
    {
        //m_Keys[ i ].Sequence    = SequencePointer;
        m_Keys[ i ].State       = e_PressedNo;
    }

    m_Keys [ 0 ].Timer = GetNewTimerPointer();
    m_Keys [ 1 ].Timer = GetNewTimerPointer();
    m_Keys [ 2 ].Timer = GetNewTimerPointer();
    m_Keys [ 3 ].Timer = GetNewTimerPointer();
    m_Keys [ 4 ].Timer = GetNewTimerPointer();
}