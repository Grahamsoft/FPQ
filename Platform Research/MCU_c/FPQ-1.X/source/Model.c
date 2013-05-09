#include "Model.h"

static AKey m_Keys[ /*KeyCount*/ 5 ];

void SetKeyState( int theKeyId, t_ButtonState theState  )
{
    m_Keys[ theKeyId ].ButtonState = theState;
}

t_ButtonState GetKeyState( int theKeyId )
{
    return m_Keys[ theKeyId ].ButtonState;
}

int* GetKeyTimer( int theKeyId )
{
    return &m_Keys[ theKeyId ].Timer;
}

t_Sequences GetSequence( int theKeyId )
{
    t_Sequences ReturnedSequence;

    switch (  m_Keys[ theKeyId ].ButtonState )
    {
        case e_PressedNo:
            return m_Keys[ theKeyId ].SequenceIdPressedNo;
            break;
        case e_PressedYes:
            return m_Keys[ theKeyId ].SequenceIdPressedYes;
            break;
        case e_BeingServedNo:
            return m_Keys[ theKeyId ].SequenceIdBeingServedNo;
            break;
        case e_BeingServedYes:
            return m_Keys[ theKeyId ].SequenceIdBeingServedYes;
            break;
    }

   // return ReturnedSequence;
}

int* GetSequenceState( int theKeyId )
{
    return &m_Keys[ theKeyId ].SequenceState;
}

int* GetTimer( int theKeyId )
{
    return &m_Keys[ theKeyId ].Timer;
}

void InitKeys()
{
    m_Keys[ 0 ].ButtonState                 = e_PressedNo;
    m_Keys[ 0 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 0 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 0 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 0 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 0 ].SequenceState               = 0;
    m_Keys[ 0 ].Timer                       = 0;

    m_Keys[ 1 ].ButtonState                 = e_PressedNo;
    m_Keys[ 1 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 1 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 1 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 1 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 1 ].SequenceState               = 0;
    m_Keys[ 1 ].Timer                       = 0;

    m_Keys[ 2 ].ButtonState                 = e_PressedNo;
    m_Keys[ 2 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 2 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 2 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 2 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 2 ].SequenceState               = 0;
    m_Keys[ 2 ].Timer                       = 0;

    m_Keys[ 3 ].ButtonState                 = e_PressedNo;
    m_Keys[ 3 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 3 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 3 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 3 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 3 ].SequenceState               = 0;
    m_Keys[ 3 ].Timer                       = 0;
    
    m_Keys[ 4 ].ButtonState                 = e_PressedNo;
    m_Keys[ 4 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 4 ].SequenceIdPressedYes        = e_AllOff;
    m_Keys[ 4 ].SequenceIdBeingServedNo     = e_Steady;
    m_Keys[ 4 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 4 ].SequenceState               = 0;
    m_Keys[ 4 ].Timer                       = 0;
}