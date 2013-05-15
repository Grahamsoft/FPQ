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
    for( uint8_t i = 0; i < KeyCount; i++ )
    {
        MonitorButton( i );
    }
}

void MonitorButton( uint8_t theId )
{
    switch ( GetKeyState( theId ) )
    {
        case e_PressedNo:
            if ( ButtonBeingPressed( theId ) )
            {
                SetKeyState( theId, e_BeingServedYes );
           //     SetTimer( GetKeyTimer( theId ), 0, 0, 1, 0 );
            }
            break;

        case e_PressedYes:
            if ( ButtonBeingPressed( theId ) )
            {
                SetKeyState( theId, e_BeingServedNo );                
                

          //      ClearTimer( GetKeyTimer( theId ) );
            }
            else
            {
                SetKeyState( theId, e_PressedNo );
            }
      //      else if( MaturedTimer( GetKeyTimer( theId ) ) )
      //      {
      //          SetKeyState( theId, e_BeingServedNo );
      //          ClearTimer( GetKeyTimer( theId ) );
        //    }

            break;

        case e_BeingServedNo:
            if ( ButtonBeingPressed( theId ) )
            {
                SetKeyState( theId, e_BeingServedYes );
           //     SetTimer( GetKeyTimer( theId ), 0, 0, 1, 0 );
            }
            break;
            
        case e_BeingServedYes:
            if ( PORTCbits.RC1 == 0 )
            {
                SetKeyState( theId, e_PressedNo );
          //      ClearTimer( GetKeyTimer( theId ) );
            }
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
//            if ( PORTBbits.RB4 == 0 )
//            {
//                BeingPressed = true;
//            }
            break;
    }
    
    return BeingPressed;
}

