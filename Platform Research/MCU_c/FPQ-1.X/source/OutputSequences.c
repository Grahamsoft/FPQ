#include "headers/OutputSequences.h"
#include "headers/TimerTask.h"

// Private Function Signatures ---
t_ButtonColour RedGreenFlash( volatile uint8_t *theState, volatile t_ATime *theTimer );
t_ButtonColour DimmedColourA( volatile uint8_t *theState, volatile t_ATime *theTimer );
t_ButtonColour RapidFlashColourB( volatile uint8_t *theState, volatile t_ATime *theTimer );
t_ButtonColour ColourMix( volatile uint8_t *theState, volatile t_ATime *theTimer );
// -------------------------------

t_ButtonColour GetColour( t_Sequences theSequences, volatile uint8_t *theState, volatile t_ATime *theTimer )
{
    t_ButtonColour ReturnColour;

    switch ( theSequences )
    {
        case e_AllOff:
            ReturnColour    = e_Off;
            break;

        case e_SteadyColourA:
            ReturnColour    = e_ColourA;
            break;

        case e_SteadyColourB:
            ReturnColour    = e_ColourB;
            break;

        case e_RedGreenFlash:
            ReturnColour = RedGreenFlash( theState, theTimer );
            break;

        case e_DimmedColourA:
            ReturnColour = DimmedColourA( theState, theTimer );
            break;

        case e_RapidFlashColourB:
            ReturnColour = RapidFlashColourB( theState, theTimer );
            break;

        case e_ColourMix:
            ReturnColour = ColourMix( theState, theTimer );
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

t_ButtonColour DimmedColourA( volatile uint8_t *theState, volatile t_ATime *theTimer )
{
    t_ButtonColour ReturnColour = e_Unknown;


    switch( *theState )
    {
        case 0:
        case 1:
            ReturnColour    = e_ColourA;
            CalculateFutureTime( theTimer, 0, 0, 1 );
            *theState       = 2;
            break;
        case 2:
            ReturnColour    = e_Off;
            CalculateFutureTime( theTimer, 0, 0, 2 );
            *theState       = 1;
            break;
    }
    return ReturnColour;
}

t_ButtonColour RapidFlashColourB( volatile uint8_t *theState, volatile t_ATime *theTimer )
{
    t_ButtonColour ReturnColour = e_Unknown;

    switch( *theState )
    {
        case 0:
        case 1:
            ReturnColour    = e_ColourB;
            CalculateFutureTime( theTimer, 0, 0, 10 );
            *theState       = 2;
            break;
        case 2:
            ReturnColour    = e_Off;
            CalculateFutureTime( theTimer, 0, 0, 50 );
            *theState       = 1;
            break;
    }
    return ReturnColour;
}

t_ButtonColour ColourMix( volatile uint8_t *theState, volatile t_ATime *theTimer )
{
    t_ButtonColour ReturnColour = e_Unknown;

    switch( *theState )
    {
        case 0:
        case 1:
            ReturnColour    = e_ColourA;
            CalculateFutureTime( theTimer, 0, 0, 0 );
            *theState       = 2;
            break;
        case 2:
            ReturnColour    = e_ColourB;
            CalculateFutureTime( theTimer, 0, 0, 0 );
            *theState       = 1;
            break;
    }
    return ReturnColour;
}