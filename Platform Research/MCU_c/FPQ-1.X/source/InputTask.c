#include "InputTask.h"
#include "Model.h"
#include "TimerTask.h"

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

// Private Function Signatures ---
void MonitorBartenderButton( void );
void MonitorButton( uint8_t theId );
bool ButtonBeingPressed( uint8_t theId );
// -------------------------------

void InputTask( void )
{
    //MonitorBartenderButton();
    
    for( uint8_t i = 0; i < KeyCount; i++ )
    {
        MonitorButton( i );
    }
}

void MonitorBartenderButton( void )
{
   static volatile t_ButtonState BartenderButton = e_PressedNo;
   
    switch( BartenderButton )
    {
        case e_PressedNo:
            if ( PORTCbits.RC1 == 0 )
            {
                BartenderButton = e_PressedYes;
            }
            break;

        case e_PressedYes:
            if ( PORTCbits.RC1 == 1 )
            {
                volatile uint8_t HeadOfQueue = GetHeadOfQueue();

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
                
                BartenderButton = e_PressedNo;
            }
            break;
    }
}

void MonitorButton( uint8_t theId )
{
    volatile t_ATime* KeyTimer = GetKeyInputTimer( theId );

    switch ( GetKeyState( theId ) )
    {
        case e_PressedNo:
            if ( ButtonBeingPressed( theId ) )
            {
                SetKeyState( theId, e_PressedYes );
                CalculateFutureTime( KeyTimer, 0, 1, 0 );
            }
            break;

        case e_PressedYes:
            if ( ButtonBeingPressed( theId ) )
            {
                if ( MaturedTimer( KeyTimer ) )
                {
                    SetKeyState( theId, e_BeingServedNo );
                }
            }
            else
            {
               // CalculateFutureTime( KeyTimer, 0, 0, 0 );
                SetKeyState( theId, e_PressedNo );
            }
            break;

        case e_BeingServedNo:
            break;
            
        case e_BeingServedYes:
            break;
    }
}

bool ButtonBeingPressed( uint8_t theId )
{
    bool BeingPressed = false;

    switch ( theId )
    {
        case 0:
            if ( PORTAbits.RA0 == 0 )
            {
                BeingPressed = true;
            }
            break;

        case 1:
            if ( PORTAbits.RA3 == 0 )
            {
                BeingPressed = true;
            }
            break;

        case 2:
            if ( PORTAbits.RA7 == 0 )
            {
                BeingPressed = true;
            }
            break;

        case 3:
//            if ( PORTCbits.RC1 == 0 )
//            {
//                BeingPressed = true;
//            }
            break;

        case 4:
            if ( PORTBbits.RB4 == 0 )
            {
                BeingPressed = true;
            }
            break;
    }
    
    return BeingPressed;
}
