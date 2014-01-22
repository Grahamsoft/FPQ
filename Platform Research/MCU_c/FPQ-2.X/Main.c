/*
 * File:   Main.c
 * Author: David
 *
 * Created on December 15, 2013, 7:29 PM
 */


#include <xc.h>

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "SystemSetup.h"

int main(void)
{
    ConfigureHardware();

    bool FDetector[ 22 ];

    for( int i = 0; i++; i < 22 )
    {
        FDetector[ i ] = false;
    }

    while( 1 )
    {

        for( int i = 0; i++; i < 22 )
        {
            if ( ( GetIO( i ) == true ) && ( FDetector[ i ] == false ) )
            {
                FDetector[ i ] = true;
                // TODO Send Comms
            }
            else if ( ( GetIO( i ) == false ) && ( FDetector[ i ] == true ) )
            {
                FDetector[ i ] = false;
                // TODO Send Comms
            }
        }
    }
}

bool GetIO( int theIOId )
{
    bool IOState;

    switch( theIOId )
    {
        case 0:
            IOState = ( bool ) PORTAbits.RA0;
            break;
        case 1:
            IOState = ( bool ) PORTAbits.RA1;
            break;
        case 2:
            IOState = ( bool ) PORTAbits.RA2;
            break;
        case 3:
            IOState = ( bool ) PORTAbits.RA3;
            break;
        case 4:
            IOState = ( bool ) PORTAbits.RA4;
            break;
        case 5:
            IOState = ( bool ) PORTAbits.RA5;
            break;
        case 6:
            IOState = ( bool ) PORTAbits.RA7;
            break;
        case 7:
            IOState = ( bool ) PORTAbits.RA6;
            break;


        case 8:
            IOState = ( bool ) PORTCbits.RC0;
            break;
        case 9:
            IOState = ( bool ) PORTCbits.RC1;
            break;
        case 10:
            IOState = ( bool ) PORTCbits.RC2;
            break;
        case 11:
            IOState = ( bool ) PORTCbits.RC3;
            break;
        case 12:
            IOState = ( bool ) PORTCbits.RC4;
            break;
        case 13:
            IOState = ( bool ) PORTCbits.RC5;
            break;
        case 14:
            IOState = ( bool ) false; //PORTCbits.RC6;
            break;
        case 15:
            IOState = ( bool ) false; //PORTCbits.RC7;
            break;


        case 16:
            IOState = ( bool ) PORTBbits.RB0;
            break;
        case 17:
            IOState = ( bool ) PORTBbits.RB1;
            break;
        case 18:
            IOState = ( bool ) PORTBbits.RB4;
            break;
        case 19:
            IOState = ( bool ) false; //PORTBbits.RB5;
            break;
        case 20:
            IOState = ( bool ) false; //PORTBbits.RB6;
            break;
        case 21:
            IOState = ( bool ) false; //PORTBbits.RB7;
            break;
    }

    return IOState;
}
