#include "OutputTask.h"
#include "delays.h"
#include "Model.h"
#include <xc.h>        /* XC8 General Include File */

#include "OutputSequences.h"

// Private Function Signatures ----------------------
void IlluminateButton( uint8_t theId );
void ColourA( uint8_t theId );
void ColourB( uint8_t theId );
void ColourNone( uint8_t theId );
// --------------------------------------------------

void OutputTask()
{
    for( uint8_t i = 0; i < KeyCount; i++ )
    {
        IlluminateButton( i );
    }
}

void IlluminateButton( uint8_t theId )
{
    volatile t_ATime* KeyTimer = GetKeyTimer( theId );
    volatile uint8_t* SequenceState = GetSequenceState( theId );
    
    if ( ( MaturedTimer( KeyTimer ) ) || ( SequenceState == 0 ) )
    {
        volatile t_Sequences Sequence = GetSequence( theId );
        
        switch ( GetColour( Sequence, SequenceState, KeyTimer ) )
        {
            case e_Off:
                ColourNone( theId );
                break;

            case e_ColourA:
                ColourA( theId );
                break;

            case e_ColourB:
                ColourB( theId );
                break;
        }
    }
}

void ColourATest( void )
{
    ColourA( 0 );
    ColourA( 1 );
    ColourA( 2 );
    ColourA( 3 );
    ColourA( 4 );
}

void ColourBTest( void )
{
    ColourB( 0 );
    ColourB( 1 );
    ColourB( 2 );
    ColourB( 3 );
    ColourB( 4 );
}

void ColourA( uint8_t theId )
{
    switch ( theId )
    {
        case 0:
            PORTAbits.RA1 = 0;
            PORTAbits.RA2 = 1;
            break;

        case 1:
            PORTAbits.RA4 = 0;
            PORTAbits.RA5 = 1;
            break;

        case 2:
            PORTAbits.RA6 = 0;
            PORTCbits.RC0 = 1;
            break;

        case 3:
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 1;
            break;

        case 4:
            PORTCbits.RC4 = 1;
            PORTCbits.RC5 = 0;
            break;
    }
}

void ColourB( uint8_t theId )
{
    switch ( theId )
    {
        case 0:
            PORTAbits.RA1 = 1;
            PORTAbits.RA2 = 0;
            break;

        case 1:
            PORTAbits.RA4 = 1;
            PORTAbits.RA5 = 0;
            break;

        case 2:
            PORTAbits.RA6 = 1;
            PORTCbits.RC0 = 0;
            break;

        case 3:
            PORTCbits.RC2 = 1;
            PORTCbits.RC3 = 0;
            break;

        case 4:
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 1;
            break;
    }
}

void ColourNone( uint8_t theId )
{
    switch ( theId )
    {
        case 0:
            PORTAbits.RA1 = 0;
            PORTAbits.RA2 = 0;
            break;

        case 1:
            PORTAbits.RA4 = 0;
            PORTAbits.RA5 = 0;
            break;

        case 2:
            PORTAbits.RA6 = 0;
            PORTCbits.RC0 = 0;
            break;

        case 3:
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            break;

        case 4:
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            break;
    }
}
