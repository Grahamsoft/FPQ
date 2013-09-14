#include "headers/Model.h"
#include "headers/OutputSequences.h"
//#include "headers/DataCommsSend.h"

// Private Function Signatures ---
bool ValidateKeyCountBounds( uint8_t theKeyId );
// -------------------------------

AKey m_Keys[ /*KeyCount*/ 5 ];

s_CommsStatus m_CommsDeviceStatus[ e_CommsDeviceCount ];

volatile uint8_t    m_HeadOfQueue;

void SetKeyState( uint8_t theKeyId, t_ButtonState theState  )
{
    // TODO Too much logic in the model!

    // New to Q
    if( theState == e_BeingServedNo )
    {
        if( m_HeadOfQueue == KeyCount )
        {
            m_HeadOfQueue = theKeyId;
        }
        else
        {
            volatile uint8_t LoopKeyId = m_HeadOfQueue;
            
            while( m_Keys[ LoopKeyId ].NextInQueue != KeyCount )
            {
                LoopKeyId = m_Keys[ LoopKeyId ].NextInQueue;
            }

            m_Keys[ LoopKeyId ].NextInQueue = theKeyId;
        }
    }

    // No Longer in Q
    if( ( theState == e_PressedNo ) && ( m_Keys[ theKeyId ].ButtonState == e_BeingServedYes ) )
    {
        volatile uint8_t OldHeadOfQueue = m_HeadOfQueue;
        m_HeadOfQueue = m_Keys[ m_HeadOfQueue ].NextInQueue;
        m_Keys[ OldHeadOfQueue ].NextInQueue = KeyCount;
    }

    m_Keys[ theKeyId ].ButtonState = theState;
    m_Keys[ theKeyId ].SequenceState = 0;
}

uint8_t GetHeadOfQueue( void )
{
    return m_HeadOfQueue;
}

t_ButtonState GetKeyState( uint8_t theKeyId )
{
    return m_Keys[ theKeyId ].ButtonState;
}

volatile t_ATime* GetKeyTimer( uint8_t theKeyId )
{
    return &m_Keys[ theKeyId ].NextActionTimer;
}

volatile t_ATime* GetKeyInputTimer( uint8_t theKeyId )
{
    return &m_Keys[ theKeyId ].InputTimer;
}

volatile uint8_t* GetSequenceState( uint8_t theKeyId )
{
    return &m_Keys[ theKeyId ].SequenceState;
}


//void SetNextActionTimer( uint8_t theKeyId, uint8_t theNewTime )
//{
//    m_Keys[ theKeyId ].NextActionTimer = theNewTime;
//}

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
            ReturnedSequence = m_Keys[ theKeyId ].SequenceIdBeingServedYes;
            break;
    }

    return ReturnedSequence;
}

uint8_t GetQueuePosition( uint8_t theKeyId )
{
    uint8_t QueuePosition = -1;

    if ( ValidateKeyCountBounds( theKeyId ) )
    {
        QueuePosition = m_Keys[ theKeyId ].QueuePosition;
    }
    
    return QueuePosition;
}

void SetQueuePosition( uint8_t theKeyId, uint8_t thePostion )
{
    if ( ValidateKeyCountBounds( theKeyId ) )
    {
        m_Keys[ theKeyId ].QueuePosition = thePostion;
    }
}

void InitKeys()
{
    m_HeadOfQueue = KeyCount;

    t_ATime KeyTimer;
    KeyTimer.Millisecond  = 0;
    KeyTimer.Second       = 0;
    KeyTimer.Minute       = 0;
    KeyTimer.Hour         = 0;
    KeyTimer.Day          = 0;

    m_Keys[ 0 ].ButtonState                 = e_PressedNo;
    m_Keys[ 0 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 0 ].SequenceIdPressedYes        = e_RapidFlashColourB;
    m_Keys[ 0 ].SequenceIdBeingServedNo     = e_SteadyColourB;
    m_Keys[ 0 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 0 ].SequenceState               = 0;
    m_Keys[ 0 ].NextActionTimer             = KeyTimer;
    m_Keys[ 0 ].InputTimer                  = KeyTimer;
    m_Keys[ 0 ].NextInQueue                 = KeyCount;
    m_Keys[ 0 ].QueuePosition               = e_QPUnassigned;

    m_Keys[ 1 ].ButtonState                 = e_PressedNo;
    m_Keys[ 1 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 1 ].SequenceIdPressedYes        = e_RapidFlashColourB;
    m_Keys[ 1 ].SequenceIdBeingServedNo     = e_SteadyColourB;
    m_Keys[ 1 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 1 ].SequenceState               = 0;
    m_Keys[ 1 ].NextActionTimer             = KeyTimer;
    m_Keys[ 1 ].InputTimer                  = KeyTimer;
    m_Keys[ 1 ].NextInQueue                 = KeyCount;
    m_Keys[ 1 ].QueuePosition               = e_QPUnassigned;

    m_Keys[ 2 ].ButtonState                 = e_PressedNo;
    m_Keys[ 2 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 2 ].SequenceIdPressedYes        = e_RapidFlashColourB;
    m_Keys[ 2 ].SequenceIdBeingServedNo     = e_SteadyColourB;
    m_Keys[ 2 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 2 ].SequenceState               = 0;
    m_Keys[ 2 ].NextActionTimer             = KeyTimer;
    m_Keys[ 2 ].InputTimer                  = KeyTimer;
    m_Keys[ 2 ].NextInQueue                 = KeyCount;
    m_Keys[ 2 ].QueuePosition               = e_QPUnassigned;

    m_Keys[ 3 ].ButtonState                 = e_PressedNo;
    m_Keys[ 3 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 3 ].SequenceIdPressedYes        = e_RapidFlashColourB;
    m_Keys[ 3 ].SequenceIdBeingServedNo     = e_SteadyColourB;
    m_Keys[ 3 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 3 ].SequenceState               = 0;
    m_Keys[ 3 ].NextActionTimer             = KeyTimer;
    m_Keys[ 3 ].InputTimer                  = KeyTimer;
    m_Keys[ 3 ].NextInQueue                 = KeyCount;
    m_Keys[ 3 ].QueuePosition               = e_QPUnassigned;
    
    m_Keys[ 4 ].ButtonState                 = e_PressedNo;
    m_Keys[ 4 ].SequenceIdPressedNo         = e_AllOff;
    m_Keys[ 4 ].SequenceIdPressedYes        = e_RapidFlashColourB;
    m_Keys[ 4 ].SequenceIdBeingServedNo     = e_SteadyColourB;
    m_Keys[ 4 ].SequenceIdBeingServedYes    = e_RedGreenFlash;
    m_Keys[ 4 ].SequenceState               = 0;
    m_Keys[ 4 ].NextActionTimer             = KeyTimer;
    m_Keys[ 4 ].InputTimer                  = KeyTimer;
    m_Keys[ 4 ].NextInQueue                 = KeyCount;
    m_Keys[ 4 ].QueuePosition               = e_QPUnassigned;

    m_CommsDeviceStatus[ e_CommsDeviceCanTx ].CommsState = e_CommsInit;
    m_CommsDeviceStatus[ e_CommsDeviceCanTx ].LastUpdate = KeyTimer;

    m_CommsDeviceStatus[ e_CommsDeviceCanRx ].CommsState = e_CommsInit;
    m_CommsDeviceStatus[ e_CommsDeviceCanRx ].LastUpdate = KeyTimer;

    m_CommsDeviceStatus[ e_CommsDeviceUartTx ].CommsState = e_CommsInit;
    m_CommsDeviceStatus[ e_CommsDeviceUartTx ].LastUpdate = KeyTimer;

    m_CommsDeviceStatus[ e_CommsDeviceUartRx ].CommsState = e_CommsInit;
    m_CommsDeviceStatus[ e_CommsDeviceUartRx ].LastUpdate = KeyTimer;

}

bool ValidateKeyCountBounds( uint8_t theKeyId )
{
    const uint8_t zero = 0;

    if ( ( theKeyId >= zero ) && ( theKeyId < KeyCount ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

s_CommsStatus GetCommsDeviceStatus( uint8_t theCommsDevice )
{
    return m_CommsDeviceStatus[ theCommsDevice ];
}

void SetCommsDeviceState( uint8_t theCommsDevice, t_CommsState theState )
{
    m_CommsDeviceStatus[ theCommsDevice ].CommsState = theState;
    GetTime( &m_CommsDeviceStatus[ theCommsDevice ].LastUpdate );
}