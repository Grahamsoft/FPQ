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

typedef struct SequencePhaseStruct
{
    int             NextActionTime;
    t_ButtonColour  CurrentColour;
}SequencePhase;

typedef struct ASequenceStruct
{
    SequencePhase	*Sequence; // Array of
    int                 Size;
    int                 Current;
}ASequence;

void InitSequences( void );
ASequence* GetSequencePointer( int theId );

#endif	/* OUTPUTSEQUENCES_H */