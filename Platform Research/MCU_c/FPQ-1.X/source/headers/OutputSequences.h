/* 
 * File:   OutputSequences.h
 * Author: David
 *
 * Created on April 13, 2013, 6:44 PM
 */

#ifndef OUTPUTSEQUENCES_H
#define	OUTPUTSEQUENCES_H

#include <stdint.h>        /* For uint8_t definition */
#include "TimerTask.h"

typedef enum
{
    e_Unknown,
    e_Off,
    e_ColourA,
    e_ColourB
}t_ButtonColour;

typedef enum
{
    e_NotSet,
    e_AllOff,
    e_SteadyColourA,
    e_SteadyColourB,
    e_RedGreenFlash,
    e_DimmedColourA
}t_Sequences;

t_ButtonColour GetColour( t_Sequences theSequences, volatile uint8_t *theState, volatile t_ATime *theTimer );

#endif	/* OUTPUTSEQUENCES_H */