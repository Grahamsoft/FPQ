#include "OutputSequences.h"
#include "TimerTask.h"

// ---- Private Sigs
t_ButtonColour RedGreenFlash( volatile uint8_t *theState, volatile uint8_t *theTimer );

t_ButtonColour GetColour( t_Sequences theSequences, volatile uint8_t *theState, volatile uint8_t *theTimer )
{
    t_ButtonColour ReturnColour;

    switch ( theSequences )
    {
        case e_AllOff:
            ReturnColour = e_Off;
            break;

        case e_Steady:
            ReturnColour = e_ColourA;
            break;

        case e_RedGreenFlash:
            ReturnColour = RedGreenFlash( theState, theTimer );
            break;
    }

    return ReturnColour;
}

t_ButtonColour RedGreenFlash( volatile uint8_t *theState, volatile uint8_t *theTimer )
{
    t_ButtonColour ReturnColour = e_Unknown;

    switch( *theState )
    {
        case 1:
            ReturnColour    = e_ColourA;
            *theState       = 2;
            *theTimer       = CalculateFutureTime( 0, 1, 0 );
            break;
        case 2:
            ReturnColour    = e_ColourB;
            *theState       = 1;
            *theTimer       = 0;
            break;
    }
    return ReturnColour;
}