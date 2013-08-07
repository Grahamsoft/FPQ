///******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <xc.h>        /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "SystemSetup.h"
#include "TaskManager.h"

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main()
{
    ConfigureHardware();
    
    while( 1 )
    {
        TaskManager();
    }
}