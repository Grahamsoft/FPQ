#include <xc.h>
#include <stdio.h>

#include "../include/plib/usart.h"

#include "headers/TimerTask.h"
#include "headers/Model.h"
#include "headers/DataCommsTask.h"

// Private Function Signatures ---
void ClearTerminal( void );
void EchoTime( t_ATime * TheTime );
void EchokeyState( uint8_t theKeyId );
void EchoCommsStatus( CommsStatus theStatus );
// -------------------------------

void UpdateConsole( void )
{
    char CustomerText[] = "Button";
    char NewLineText[] = "\r\n";
    char TabText[] = "\t";

    ClearTerminal();
    putsUSART( "System Time: " );
    EchoTime( GetTime() );
    putsUSART( NewLineText );
    putsUSART( NewLineText );

    putsUSART( CustomerText );
    putsUSART( TabText );
    putsUSART( "Status" );
    putsUSART( TabText );
    putsUSART( "Action @" );
    putsUSART( TabText );
    putsUSART( "|" );
    putsUSART( TabText );
    putsUSART( "Device" );
    putsUSART( NewLineText );
    putsUSART( NewLineText );

    putsUSART( "1" );
    putsUSART( TabText );
    EchokeyState( 0 );
    putsUSART( TabText );
    EchoTime( GetKeyTimer( 0 ) );
    putsUSART( TabText );
    putsUSART( "|" );
    putsUSART( TabText );
    putsUSART( "UART Rx" );
    putsUSART( TabText );
    EchoCommsStatus( GetUARTRxStatus() );
    putsUSART( NewLineText );

    putsUSART( "2" );
    putsUSART( TabText );
    EchokeyState( 1 );
    putsUSART( TabText );
    EchoTime( GetKeyTimer( 1 ) );
    putsUSART( TabText );
    putsUSART( "|" );
    putsUSART( TabText );
    putsUSART( "UART Tx" );
    putsUSART( TabText );
    EchoCommsStatus( GetUARTTxStatus() );
    putsUSART( NewLineText );

    putsUSART( "3" );
    putsUSART( TabText );
    EchokeyState( 2 );
    putsUSART( TabText );
    EchoTime( GetKeyTimer( 2 ) );
    putsUSART( TabText );
    putsUSART( "|" );
    putsUSART( TabText );
    putsUSART( "CAN Rx" );
    putsUSART( TabText );
    EchoCommsStatus( GetCANRxStatus() );
    putsUSART( NewLineText );

    putsUSART( "4" );
    putsUSART( TabText );
    EchokeyState( 3 );
    putsUSART( TabText );
    EchoTime( GetKeyTimer( 3 ) );
    putsUSART( TabText );
    putsUSART( "|" );
    putsUSART( TabText );
    putsUSART( "CAN Tx" );
    putsUSART( TabText );
    EchoCommsStatus( GetCANTxStatus() );
    putsUSART( NewLineText );

    putsUSART( "5" );
    putsUSART( TabText );
    EchokeyState( 4 );
    putsUSART( TabText );
    EchoTime( GetKeyTimer( 4 ) );
    putsUSART( TabText );
    putsUSART( "|" );
    putsUSART( TabText );
    putsUSART( "-" );
    putsUSART( NewLineText );
}

void ClearTerminal( void )
{
    putsUSART( "\033[2J" );
}


void EchoTime( t_ATime * TheTime )
{
    char str[ 3 ];
    //volatile t_ATime TheTime = GetTime();

    str[ 0 ] = 0;
    sprintf( str, "%2.2d", TheTime->Hour );
    putsUSART( str );

    putsUSART( ":" );
    str[ 0 ] = 0;
    sprintf( str, "%2.2d", TheTime->Minute );
    putsUSART( str );
    putsUSART( ":" );
    str[ 0 ] = 0;
    sprintf( str, "%2.2d", TheTime->Second );
    putsUSART( str );  
}

void EchokeyState( uint8_t theKeyId )
{
   switch ( GetKeyState( theKeyId ) )
   {
        case e_Error:
            putsUSART( "Error" );
            break;
        case e_PressedNo:
            putsUSART( "Idle" );
            break;
        case e_PressedYes:
            putsUSART( "Pressed" );
            break;
        case e_BeingServedNo:
            putsUSART( "Waiting" );
            break;
        case e_BeingServedYes:
            putsUSART( "Serving" );
            break;
   }
}

void EchoCommsStatus( CommsStatus theStatus )
{
    switch( theStatus )
    {
        case e_CommsInit:
            putsUSART( "Init" );
            break;
        case e_CommsOK:
            putsUSART( "OK" );
            break;
        case e_CommsError:
            putsUSART( "Error" );
            break;
        default:
            putsUSART( "Unknown" );
            break;
    }
}