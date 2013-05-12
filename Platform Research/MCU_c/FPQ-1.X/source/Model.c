#include "Model.h"
#include "OutputSequences.h"

AKey m_Keys[ /*KeyCount*/ 5 ];

void SetKeyState( uint8_t theKeyId, t_ButtonState theState  )
{
    m_Keys[ theKeyId ].ButtonState = theState;
}

t_ButtonState GetKeyState( uint8_t theKeyId )
{
    return m_Keys[ theKeyId ].ButtonState;
}

volatile uint8_t* GetKeyTimer( uint8_t theKeyId )
{
    return &m_Keys[ theKeyId ].NextActionTimer;
}

volatile uint8_t* GetSequenceState( uint8_t theKeyId )
{
    return &m_Keys[ theKeyId ].SequenceState;
}


void SetNextActionTimer( uint8_t theKeyId, uint8_t theNewTime )
{
    m_Keys[ theKeyId ].NextActionTimer = theNewTime;
}

t_Sequences GetSequence( uint8_t theKeyId )
{
    volatile t_Sequences ReturnedSequence = 1;

    switch (  m_Keys[ theKeyId ].ButtonState )
    {
        case e_PressedNo:
            ReturnedSequence =  m_Keys[ theKeyId ].SequenceIdPressedNo;
            break;
        case e_PressedYes:
            ReturnedSequence = m_Keys[ theKeyId ].SequenceIdPressedYes;
            break;
        case e_BeingServedNo:
            ReturnedSequence = m_Keys[ theKeyId ].SequenceIdBeingServedNo;
            break;
        case e_BeingServedYes:
            ReturnedSequence = ( t_Sequences )m_Keys[ theKeyId ].SequenceIdBeingServedYes;
            //ReturnedSequence = 3;
            break;
    }

    return ReturnedSequence;
}

void InitKeys()
{
    m_Keys[ 0 ].ButtonState                 = e_PressedNo;
    m_Keys[ 0 ].SequenceIdPressedNo         = e_Steady;
    m_Keys[ 0 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 0 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 0 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 0 ].SequenceState               = 1;
    m_Keys[ 0 ].NextActionTimer                       = 0;

    m_Keys[ 1 ].ButtonState                 = e_PressedNo;
    m_Keys[ 1 ].SequenceIdPressedNo         = e_RedGreenFlash;
    m_Keys[ 1 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 1 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 1 ].SequenceIdBeingServedYes    = e_AllOff;
    m_Keys[ 1 ].SequenceState               = 1;
    m_Keys[ 1 ].NextActionTimer                       = 0;

    m_Keys[ 2 ].ButtonState                 = e_PressedNo;
    m_Keys[ 2 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 2 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 2 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 2 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 2 ].SequenceState               = 1;
    m_Keys[ 2 ].NextActionTimer                       = 0;

    m_Keys[ 3 ].ButtonState                 = e_PressedNo;
    m_Keys[ 3 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 3 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 3 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 3 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 3 ].SequenceState               = 1;
    m_Keys[ 3 ].NextActionTimer                       = 0;
    
    m_Keys[ 4 ].ButtonState                 = e_PressedNo;
    m_Keys[ 4 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 4 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 4 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 4 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 4 ].SequenceState               = 1;
    m_Keys[ 4 ].NextActionTimer                       = 0;
}