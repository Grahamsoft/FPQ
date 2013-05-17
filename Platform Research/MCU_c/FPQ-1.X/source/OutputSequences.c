#include "OutputSequences.h"
#include "TimerTask.h"

// ---- Private Sigs
t_ButtonColour RedGreenFlash( volatile uint8_t *theState, volatile t_ATime *theTimer );

t_ButtonColour GetColour( t_Sequences theSequences, volatile uint8_t *theState, volatile t_ATime *theTimer )
{
    t_ButtonColour ReturnColour;

    switch ( theSequences )
    {
        case e_AllOff:
            ReturnColour    = e_Off;
            CalculateFutureTime( theTimer, 0, 0, 0 );
            break;

        case e_SteadyColourA:
            ReturnColour    = e_ColourA;
            CalculateFutureTime( theTimer, 0, 0, 0 );
            break;

        case e_SteadyColourB:
            ReturnColour    = e_ColourB;
            CalculateFutureTime( theTimer, 0, 0, 0 );
            break;

        case e_RedGreenFlash:
            ReturnColour = RedGreenFlash( theState, theTimer );
            break;
    }

    return ReturnColour;
}

t_ButtonColour RedGreenFlash( volatile uint8_t *theState, volatile t_ATime *theTimer )
{
    t_ButtonColour ReturnColour = e_Unknown;


    switch( *theState )
    {
        case 0:
        case 1:
            ReturnColour    = e_ColourA;
            CalculateFutureTime( theTimer, 0, 2, 0 );
            *theState       = 2;
            break;
        case 2:
            ReturnColour    = e_ColourB;
            CalculateFutureTime( theTimer, 0, 2, 0 );
            *theState       = 1;
            break;
    }
    return ReturnColour;
}