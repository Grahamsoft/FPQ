#include <xc.h>
#include <stdio.h>

#include "headers/TimerTask.h"
#include "headers/Model.h"
#include "headers/DataCommsExternal.h"

// Private Function Signatures ---
void ClearTerminal( void );
void EchoTime( t_ATime * TheTime );
void EchokeyState( uint8_t theKeyId );
void EchoCommsStatus( t_CommsState theState );
// -------------------------------

void UpdateConsole( void )
{
    char CustomerText[] = "Button";
    char NewLineText[] = "\r\n";
    char TabText[] = "\t";

    ClearTerminal();
    UartStringWrite( "System Time: " );

    volatile t_ATime theTime;
    GetTime( &theTime );
    EchoTime( &theTime );
    UartStringWrite( NewLineText );
    UartStringWrite( NewLineText );

    UartStringWrite( CustomerText );
        UartStringWrite( TabText );
    UartStringWrite( "Status" );
        UartStringWrite( TabText );
    UartStringWrite( "@ Time" );
        UartStringWrite( TabText );
    UartStringWrite( "|" );
        UartStringWrite( TabText );
    UartStringWrite( "Device" );
        UartStringWrite( TabText );
    UartStringWrite( "@ Time" );
        UartStringWrite( NewLineText );
        UartStringWrite( NewLineText );

    UartStringWrite( "1" );
        UartStringWrite( TabText );
    EchokeyState( 0 );
        UartStringWrite( TabText );
    EchoTime( GetKeyTimer( 0 ) );
        UartStringWrite( TabText );
    UartStringWrite( "|" );
        UartStringWrite( TabText );
    UartStringWrite( "UART Rx" );
        UartStringWrite( TabText );

    s_CommsStatus CommsStatus = GetUARTRxStatus();
    EchoCommsStatus( CommsStatus.CommsState );
        UartStringWrite( TabText );
    EchoTime( &CommsStatus.LastUpdate );
        UartStringWrite( NewLineText );

    UartStringWrite( "2" );
        UartStringWrite( TabText );
    EchokeyState( 1 );
        UartStringWrite( TabText );
    EchoTime( GetKeyTimer( 1 ) );
        UartStringWrite( TabText );
    UartStringWrite( "|" );
        UartStringWrite( TabText );
    UartStringWrite( "UART Tx" );
        UartStringWrite( TabText );
    CommsStatus = GetUARTTxStatus();
    EchoCommsStatus( CommsStatus.CommsState );
        UartStringWrite( TabText );
    EchoTime( &CommsStatus.LastUpdate );
        UartStringWrite( NewLineText );

    UartStringWrite( "3" );
        UartStringWrite( TabText );
    EchokeyState( 2 );
        UartStringWrite( TabText );
    EchoTime( GetKeyTimer( 2 ) );
        UartStringWrite( TabText );
    UartStringWrite( "|" );
        UartStringWrite( TabText );
    UartStringWrite( "CAN Rx" );
        UartStringWrite( TabText );
    CommsStatus = GetCANRxStatus();
    EchoCommsStatus( CommsStatus.CommsState );
        UartStringWrite( TabText );
    EchoTime( &CommsStatus.LastUpdate );
        UartStringWrite( NewLineText );

    UartStringWrite( "4" );
        UartStringWrite( TabText );
    EchokeyState( 3 );
        UartStringWrite( TabText );
    EchoTime( GetKeyTimer( 3 ) );
        UartStringWrite( TabText );
    UartStringWrite( "|" );
        UartStringWrite( TabText );
    UartStringWrite( "CAN Tx" );
        UartStringWrite( TabText );
    CommsStatus = GetCANTxStatus();
    EchoCommsStatus( CommsStatus.CommsState );
        UartStringWrite( TabText );
    EchoTime( &CommsStatus.LastUpdate );
        UartStringWrite( NewLineText );

    UartStringWrite( "5" );
    UartStringWrite( TabText );
    EchokeyState( 4 );
    UartStringWrite( TabText );
    EchoTime( GetKeyTimer( 4 ) );
    UartStringWrite( TabText );
    UartStringWrite( "|" );
    UartStringWrite( TabText );
    UartStringWrite( "-" );
    UartStringWrite( TabText );
    UartStringWrite( "-" );
    UartStringWrite( NewLineText );
}

void ClearTerminal( void )
{
    UartStringWrite( "\033[2J" );
}


void EchoTime( t_ATime * TheTime )
{
    char str[ 3 ];
    //volatile t_ATime TheTime = GetTime();

    str[ 0 ] = 0;
    sprintf( str, "%2.2d", TheTime->Hour );
    UartStringWrite( str );

    UartStringWrite( ":" );
    str[ 0 ] = 0;
    sprintf( str, "%2.2d", TheTime->Minute );
    UartStringWrite( str );
    UartStringWrite( *":" );
    str[ 0 ] = 0;
    sprintf( str, "%2.2d", TheTime->Second );
    UartStringWrite( str );
}

void EchokeyState( uint8_t theKeyId )
{
   switch ( GetKeyState( theKeyId ) )
   {
        case e_Error:
            UartStringWrite( "Error" );
            break;
        case e_PressedNo:
            UartStringWrite( "Idle" );
            break;
        case e_PressedYes:
            UartStringWrite( "Pressed" );
            break;
        case e_BeingServedNo:
            UartStringWrite( "Waiting" );
            break;
        case e_BeingServedYes:
            UartStringWrite( "Serving" );
            break;
   }
}

void EchoCommsStatus( t_CommsState theState )
{
    switch( theState )
    {
        case e_CommsInit:
            UartStringWrite( "Init" );
            break;
        case e_CommsOK:
            UartStringWrite( "OK" );
            break;
        case e_CommsError:
            UartStringWrite( "Error" );
            break;
        default:
            UartStringWrite( "Unknown" );
            break;
    }
}