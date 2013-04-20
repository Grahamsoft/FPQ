#include "OutputTask.h"

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#include "delays.h"
#include "Model.h"

void OutputTask()
{
    for( int i = 0; i < KeyCount; i++ )
    {
        IlluminateButton( i );
    }
}

void IlluminateButton( int theId )
{
    switch ( GetKeyState( theId ) )
    {
        case e_PressedNo:
            ColourA( theId );
            break;

        case e_PressedYes:
            ColourB( theId );
            break;

        case e_BeingServedNo:
            ColourB( theId );
            break;

        case e_BeingServedYes:
            break;
    }
}

void ColourA( int theId )
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
            break;

        case 4:
            break;
    }
}

void ColourB( int theId )
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
            break;

        case 4:
            break;
    }
}

void ColourNone( int theId )
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
            break;

        case 4:
            break;
    }
}
