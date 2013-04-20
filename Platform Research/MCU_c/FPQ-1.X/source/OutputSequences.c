#include "OutputSequences.h"

const int SequencesCount = 5;
ASequence Sequences[ /*SequencesCount*/ 5  ];

const int RedGreenPhases = 2;
SequencePhase RedGreenSequence[ /*RedGreenPhases*/ 2 ];


void InitSequences()
{
    RedGreenSequence[ 0 ].CurrentColour = e_ColourA;
    RedGreenSequence[ 0 ].NextActionTime = 10;
    RedGreenSequence[ 1 ].CurrentColour = e_ColourB;
    RedGreenSequence[ 1 ].NextActionTime = 10;

    Sequences[ 0 ].Sequence = &RedGreenSequence[ 0 ];
    Sequences[ 0 ].Size = RedGreenPhases;
    Sequences[ 0 ].Current = 0;
}

ASequence* GetSequencePointer( int theId )
{
    ASequence *SequencePointer;

    if ( ( theId >= 0 ) && ( theId <= SequencesCount ) )
    {
        SequencePointer = &Sequences[ theId ];
    }

    return SequencePointer;
}