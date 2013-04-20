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

void InputTask( void )
{
    for( int i = 0; i < KeyCount; i++ )
    {
        MonitorButton( i );
    }
}

void MonitorButton( int theId )
{
    switch ( GetKeyState( theId ) )
    {
        case e_PressedNo:
            if ( ButtonBeingPressed( theId ) )
            {
                SetKeyState( theId, e_PressedYes );
                SetTimer( GetKeyTimer( theId ), 0, 0, 1, 0 );
            }
            break;

        case e_PressedYes:
            if ( ! ButtonBeingPressed( theId ) )
            {
                SetKeyState( theId, e_PressedNo );
                ClearTimer( GetKeyTimer( theId ) );
            }
            else if( MaturedTimer( GetKeyTimer( theId ) ) )
            {
                SetKeyState( theId, e_BeingServedNo );
                ClearTimer( GetKeyTimer( theId ) );
            }

            break;

        case e_BeingServedNo:
            break;
            
        case e_BeingServedYes:
            break;
    }
}

bool ButtonBeingPressed( int theId )
{
    bool BeingPressed = false;

    switch ( theId )
    {
        case 0:
            BeingPressed = PORTAbits.RA0;
            break;

        case 1:
            BeingPressed = PORTAbits.RA3;
            break;

        case 2:
            BeingPressed = PORTAbits.RA7;
            break;

        case 3:
            BeingPressed = PORTCbits.RC1;
            break;

        case 4:
            BeingPressed = PORTBbits.RB4;
            break;
    }
    
    return BeingPressed;
}

