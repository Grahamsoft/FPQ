/* 
 * File:   OutputSequences.h
 * Author: David
 *
 * Created on April 13, 2013, 6:44 PM
 */

#ifndef OUTPUTSEQUENCES_H
#define	OUTPUTSEQUENCES_H

typedef enum
{
    e_Off,
    e_ColourA,
    e_ColourB
}t_ButtonColour;

typedef enum
{
    e_AllOff,
    e_Steady,
    e_RedGreenFlash
}t_Sequences;

t_ButtonColour GetColour( t_Sequences theSequences, int *theState, int *theTimer );

#endif	/* OUTPUTSEQUENCES_H */