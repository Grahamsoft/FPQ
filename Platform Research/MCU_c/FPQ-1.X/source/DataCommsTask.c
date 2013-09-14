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
#include "headers/DataCommsExternal.h"
#include "headers/Model.h"
#include "headers/OutputTask.h"

// Private Function Signatures ---
char GetSerialChar( void );
void CanCommsTask( void );
void UartCommsTask( void );
void UpdateStatus( s_CommsStatus * theCommsStatusStruct, t_CommsState theNewCommsState );
void LoadNextMessage( void );
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

enum DataCommsMessages
{
    e_NullCharacter         = 0,
    e_StartOfHeader         = 1,
    e_StartOfText           = 2,
    e_EndOfText             = 3,
    // 4 to 31 Reserved
    e_AssignQueuePosition   = 32,
    e_GetTime               = 33,
    e_SetTime               = 34
    // 127 Reserved
};

static const char StartChar = 2;
static const char EndChar = 3;
static const char NoRead = 0;

BYTE m_LastCANRead[ 4 ];
BYTE m_NextSendMessage[ 4 ];

static s_CommsStatus m_CANTxStatus;
static s_CommsStatus m_CANRxStatus;
static s_CommsStatus m_UARTTxStatus;
static s_CommsStatus m_UARTRxStatus;

// -----------------------
//
// For DataCommsExternal.h
//
// -----------------------

char UartCharRead ( void )
{
    char ReceivedChar = NoRead;

    if ( ( DataRdyUSART() == 1 ) && ( BusyUSART() == 0 ) )
    {
        GetTime( &m_UARTRxStatus.LastUpdate );
        ReceivedChar = getcUSART();
    }

    return ReceivedChar;
}

void UartCharWrite ( char theChar )
{
    GetTime( &m_UARTTxStatus.LastUpdate );
    WriteUSART ( theChar );
}

void UartStringRead ( char *theStringBuffer,  unsigned char theLength )
{
    *theStringBuffer = NoRead;
    
    if ( ( DataRdyUSART() == 1 ) && ( BusyUSART() == 0 ) )
    {
        GetTime( &m_UARTRxStatus.LastUpdate );
        getsUSART ( theStringBuffer, theLength );
    }
}

void UartStringWrite ( char *theString )
{
    UpdateStatus( &m_UARTTxStatus, e_CommsOK );
    putsUSART ( theString );//
}

// -----------------------
//
// For DataCommsTask.h
//
// -----------------------


void InitDataComms( void )
{
    m_NextSendMessage[ 0 ] = e_NullCharacter;
    m_NextSendMessage[ 0 ] = e_NullCharacter;
    m_NextSendMessage[ 0 ] = e_NullCharacter;
    m_NextSendMessage[ 0 ] = e_NullCharacter;
}


void UpdateStatus( s_CommsStatus * theCommsStatusStruct, t_CommsState theNewCommsState )
{
  //  if( theCommsStatusStruct->CommsState != theNewCommsState )
  //  {
        theCommsStatusStruct->CommsState = theNewCommsState;
        GetTime( &theCommsStatusStruct->LastUpdate );
  //  }
}

void LoadNextMessage( void )
{
    if ( m_NextSendMessage[ 0 ] == e_NullCharacter )
    {
        for( uint8_t i = 0; i < KeyCount; i++ )
        {
            if ( GetQueuePosition( i ) == ( uint8_t )e_QPUnassigned )
            {
                m_NextSendMessage[ 0 ] = e_StartOfText;
                m_NextSendMessage[ 1 ] = e_AssignQueuePosition;
                m_NextSendMessage[ 2 ] = i + 1;
                m_NextSendMessage[ 3 ] = e_EndOfText;

                SetQueuePosition( i, e_QPRequestSent );
                break;
            }
        }
    }
}

int DataCommsTask( void )
{
    LoadNextMessage();
    CanCommsTask();
    UartCommsTask();
    return EXIT_SUCCESS;
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

         //   ECANSetOperationMode(ECAN_OP_MODE_LOOP);
            
            SetCommsDeviceState( e_CommsDeviceCanTx, e_CommsOK );
            SetCommsDeviceState( e_CommsDeviceCanRx, e_CommsOK );

            DataCommsReadState = e_CANWrite;
        }
        break;

        case e_CANRead:
        {
            NodeId              = 0;
            ReadMessage[ 0 ]    = 0;
            ReadMessageLength   = 0;

            ECAN_RX_MSG_FLAGS flags = 0;

            if ( ECANReceiveMessage( &NodeId ,&ReadMessage[ 0 ], &ReadMessageLength, &flags) )
            {
                if ( ReadMessageLength > 0 )
                {
                    strcpy( m_LastCANRead, &ReadMessage[ 0 ] );
                    SetCommsDeviceState( e_CommsDeviceCanRx, e_CommsOK );
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
                if ( m_NextSendMessage[ 0 ] != e_NullCharacter )
                {
                    unsigned long NodeId = 0x128;

                    if ( ! ECANSendMessage( NodeId, &m_NextSendMessage[0], sizeof( m_NextSendMessage[ 0 ] ), ECAN_TX_STD_FRAME) )
                    {
                        SetCommsDeviceState( e_CommsDeviceCanTx, e_CommsError );
                        DataCommsReadState = e_CANWrite;
                    }
                    else
                    {
                        SetCommsDeviceState( e_CommsDeviceCanTx, e_CommsOK );
                    }
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
            SetCommsDeviceState( e_CommsDeviceUartRx, e_CommsOK );
            DataCommsReadState = e_ReadMsg;
            break;
            
        case e_ReadStartChar:

            if( UartCharRead() == StartChar )
            {
                DataCommsReadState = e_ReadMsg;
            }
            break;

        case e_ReadMsg:
            
            Msg = UartCharRead();

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
                    SetCommsDeviceState( e_CommsDeviceUartRx, e_CommsOK );
                    DataCommsReadState = e_DoMsgCommand;
                   break;
            }
            break;

        case e_ReadEndChar:

            switch( UartCharRead() )
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
