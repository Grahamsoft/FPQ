#include "OutputSequences.h"

// ---- Private Sigs
t_ButtonColour RedGreenFlash( int *theState, int *theTimer );

t_ButtonColour GetColour( t_Sequences theSequences, int *theState, int *theTimer )
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

t_ButtonColour RedGreenFlash( int *theState, int *theTimer )
{
    t_ButtonColour ReturnColour;

    switch( *theState )
    {
        case 0:
            ReturnColour    = e_ColourA;
            *theState       = 1;
            *theTimer       = 0;
            break;
        case 1:
            ReturnColour    = e_ColourB;
            *theState       = 0;
            *theTimer       = 0;
            break;
    }
    return ReturnColour;
}