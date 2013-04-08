/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "System.h"        /* System funct/params, like osc/peripheral config */
#include "User.h"          /* User funct/params, such as InitApp */
#include "TaskManager.h"

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    ConfigureOscillator();
    InitApp();

    while(1)
    {
        TaskManager();
    }
}

