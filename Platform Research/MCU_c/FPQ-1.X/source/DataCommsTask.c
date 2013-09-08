/*
 * File:   DataCommsTask.c
 * Author: David Graham
 * 
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/plib/usart.h"

#include "headers/ECAN.h"
#include "headers/DataCommsTask.h"
#include "headers/Model.h"
#include "headers/OutputTask.h"

// Private Function Signatures ---
char GetSerialChar( void );
void CanCommsTask( void );
void UartCommsTask( void );
// -------------------------------

static volatile t_ATime     m_DataWriteTimer;

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

BYTE m_LastCANRead[ 4 ];

static CommsStatus m_CANTxStatus = e_CommsInit;
static CommsStatus m_CANRxStatus = e_CommsInit;
static CommsStatus m_UARTTxStatus = e_CommsInit;
static CommsStatus m_UARTRxStatus = e_CommsInit;

int DataCommsTask( void )
{
    CanCommsTask();
    UartCommsTask();
    return EXIT_SUCCESS;
}

CommsStatus GetCANTxStatus( void )
{
    return m_CANTxStatus;
}

CommsStatus GetCANRxStatus( void )
{
    return m_CANRxStatus;
}

CommsStatus GetUARTTxStatus( void )
{
    return m_UARTTxStatus;
}

CommsStatus GetUARTRxStatus( void )
{
    return m_UARTRxStatus;
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

    unsigned long NodeId;
    BYTE ReadMessage[ 4 ];
    BYTE ReadMessageLength;

    switch( DataCommsReadState )
    {
        case e_CANInit:
        {
            ECANInitialize();

            m_DataWriteTimer.Day            = 0;
            m_DataWriteTimer.Hour           = 0;
            m_DataWriteTimer.Millisecond    = 0;
            m_DataWriteTimer.Minute         = 0;
            m_DataWriteTimer.Second         = 0;

            m_LastCANRead[ 0 ] = 0; // Null the first char

            //ECANSetOperationMode(ECAN_OP_MODE_LOOP);
            m_CANRxStatus = e_CommsOK;
            m_CANTxStatus = e_CommsOK;

            DataCommsReadState = e_CANWrite;
        }
        break;

        case e_CANRead:
        {
            NodeId = 0;
            ReadMessage[ 0 ] = 0;
            ReadMessageLength = 0;

            ECAN_RX_MSG_FLAGS flags = 0;

            if ( ECANReceiveMessage( &NodeId ,&ReadMessage[ 0 ], &ReadMessageLength, &flags) )
            {
                if ( ReadMessageLength > 0 )
                {
                    strcpy( m_LastCANRead, &ReadMessage[ 0 ] );
                }
            }

            DataCommsReadState = e_CANWrite;
        }
        break;

        case e_CANWrite:
        {
            DataCommsReadState = e_CANRead;

            if ( MaturedTimer( &m_DataWriteTimer ) )
            {
                unsigned long NodeId = 0x128;
                ReadMessage[ 0 ] = 'G';
                ReadMessage[ 1 ] = 0;
                ReadMessageLength = sizeof( ReadMessage[ 0 ] );

                if ( ! ECANSendMessage( NodeId, &ReadMessage[0], ReadMessageLength, ECAN_TX_STD_FRAME) )
                {
                    m_CANTxStatus = e_CommsError;
                    DataCommsReadState = e_CANWrite;
                }
                else
                {
                    m_CANTxStatus = e_CommsOK;
                }

                CalculateFutureTime( &m_DataWriteTimer, 0, 3, 0 );
            }
        }
        break;
    }
}

void UartCommsTask( void )
{
    static CommsStateMachine DataCommsReadState = e_DataComsInit;

    static char Msg = 0;

    volatile uint8_t HeadOfQueue;

    switch ( DataCommsReadState )
    {
        case e_DataComsInit:

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
            m_UARTRxStatus = e_CommsOK;
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
