/*
 * File:   DataCommsTask.c
 * Author: David Graham
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <usart.h>

#include "DataCommsTask.h"
#include "Model.h"

// Private Function Signatures ---
char GetSerialChar( void );
// -------------------------------

typedef enum
{
        e_ReadStartChar,
        e_ReadMsg,
        e_ReadEndChar,
        e_DoMsgCommand
} CommsStateMachine;

static const char StartChar = 2;
static const char EndChar = 3;
static const char NoRead = 0;

char GetSerialChar( void )
{
    char ReceivedChar = NoRead;
    
    if ( ( DataRdyUSART() == 1 ) && ( BusyUSART() == 0 ) )
    {
        ReceivedChar = getcUSART();
    }

    return ReceivedChar;
}

int DataCommsTask( void )
{
    //static CommsStateMachine DataCommsReadState = e_ReadMsg;
    static CommsStateMachine DataCommsReadState = e_ReadMsg;

    static char Msg = 0;

    volatile uint8_t HeadOfQueue;

    switch ( DataCommsReadState )
    {
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
    return ( EXIT_SUCCESS );
}
