/*
 * File:   DataCommsTask.c
 * Author: David Graham
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <usart.h>
#include "headers/J1939.H"

#include "DataCommsTask.h"
#include "DataCommsSend.h"
#include "Model.h"


// Private Function Signatures ---
char GetSerialChar( void );
void CanCommsTask( void );
void UartCommsTask( void );
// -------------------------------

typedef enum
{
        e_DataComsInit,
        e_ReadStartChar,
        e_ReadMsg,
        e_ReadEndChar,
        e_DoMsgCommand
} CommsStateMachine;

typedef enum
{
        e_CANInit,
        e_CANRead,
        e_CANWrite
} CanCommsStateMachine;

static const char StartChar = 2;
static const char EndChar = 3;
static const char NoRead = 0;

static char InitText[] = "Hello World. Data Comms Init.... Done\n";

static char c_CustomerWating[]          = "Customer Wating: \r\n";
static char c_CustomerBeingServed[]     = "Customer Being Served: \r\n";

J1939_MESSAGE CanMessage;

#define OTHER_NODE      129
#define TURN_ON_LED     92
#define TURN_OFF_LED    94

int DataCommsTask( void )
{
    CanCommsTask();
    UartCommsTask();
    return EXIT_SUCCESS;
}

char GetSerialChar( void )
{
    char ReceivedChar = NoRead;
    
    if ( ( DataRdyUSART() == 1 ) && ( BusyUSART() == 0 ) )
    {
        ReceivedChar = getcUSART();
    }

    return ReceivedChar;
}

void CanCommsTask( void )
{
    static CanCommsStateMachine DataCommsReadState = e_CANInit;

    switch( DataCommsReadState )
    {
        case e_CANInit:
            while ( J1939_Flags.WaitingForAddressClaimContention )
            {
                J1939_Poll( 5 );
            }
            DataCommsReadState = e_CANRead;
            break;

        case e_CANRead:
            while ( RXQueueCount > 0 )
            {
                J1939_DequeueMessage( &CanMessage );

                if ( CanMessage.PDUFormat == TURN_ON_LED )
                {
                        putsUSART( "CAN Command: ON" );
                }
                else if ( CanMessage.PDUFormat == TURN_OFF_LED )
                {
                        putsUSART( "CAN Command: OFF" );
                }
            }
            J1939_Poll( 20 );
            break;

        case e_CANWrite:
            // NEVER USED ATM

            CanMessage.DataPage             = 0;
            CanMessage.Priority             = J1939_CONTROL_PRIORITY;
            CanMessage.DestinationAddress   = OTHER_NODE;
            CanMessage.DataLength           = 0;
            CanMessage.PDUFormat            = TURN_ON_LED;

            while ( J1939_EnqueueMessage( &CanMessage ) != RC_SUCCESS )
            {
                J1939_Poll( 5 );
            }
            break;
    }
}

void UartCommsTask( void )
{
    //static CommsStateMachine DataCommsReadState = e_ReadMsg;
    static CommsStateMachine DataCommsReadState = e_DataComsInit;

    //CANReceiveMessage();

    static char Msg = 0;

    volatile uint8_t HeadOfQueue;

    switch ( DataCommsReadState )
    {
        case e_DataComsInit:
            
            putsUSART( InitText );
            DataCommsReadState = e_ReadMsg;
            break;
            
        case e_ReadStartChar:
            if( GetSerialChar() == StartChar )
            {
                DataCommsReadState = e_ReadMsg;
            }

            break;

        case e_ReadMsg:
            Msg = GetSerialChar();

            switch( Msg )
            {
               // case StartChar:
               // case NoRead:
                case 0:
                    break;

                // case EndChar:
                case 3:
                    DataCommsReadState = e_ReadStartChar;
                    break;

                default:
                   // DataCommsReadState = e_ReadEndChar;
                   DataCommsReadState = e_DoMsgCommand;
            }
            break;

        case e_ReadEndChar:

            switch( GetSerialChar() )
            {

                default:
                    DataCommsReadState = e_ReadStartChar;
            }
            break;

        case e_DoMsgCommand:
            
            switch( Msg )
            {
                case 'a':

                    HeadOfQueue = GetHeadOfQueue();

                    if ( HeadOfQueue != KeyCount )
                    {
                        if ( GetKeyState( HeadOfQueue ) == e_BeingServedYes )
                        {
                            SetKeyState( HeadOfQueue, e_PressedNo );
                        }

                        HeadOfQueue = GetHeadOfQueue();

                        if( HeadOfQueue != KeyCount )
                        {
                            SetKeyState( HeadOfQueue, e_BeingServedYes );
                        }
                    }

                    break;

                case 'b':
                    break;
            }
            //DataCommsReadState = e_ReadStartChar;
            DataCommsReadState = e_ReadMsg;
            break;
    }
}

void CustomerWating( uint8_t theKeyId )
{
    putsUSART( c_CustomerWating );
}
void CustomerBeingServed( uint8_t theKeyId )
{
    putsUSART( c_CustomerBeingServed );
}
