/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "timers.h"

#endif

#include "SystemSetup.h"

void ConfigureOscillator()
{
    OSCCON = 0b01111110;
}

void ConfigureTimer( void )
{
    OpenTimer0( TIMER_INT_ON &//Should be ON
    T0_8BIT &
    T0_SOURCE_INT &
    T0_PS_1_256 );

    ei();
}
