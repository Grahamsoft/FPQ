#include "Queue.h"

short Qu[4];

const short EmptyItem = -1;

Queue::Queue(void)
{
	Qu[0] = EmptyItem;
	Qu[1] = EmptyItem;
	Qu[2] = EmptyItem;
	Qu[3] = EmptyItem;
}

Queue::~Queue(void)
{
}

void Queue::Add( int theKeyId )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( Qu[ i ] == EmptyItem )
		{
			Qu[ i ] = theKeyId;
			break;
		}
	}
}

int Queue::Next()
{
	int Next = Qu[ 0 ];

	for( int i = 1; i < 4; i++ )
	{
		Qu[ i - 1 ] = Qu[ i ];
	}
	Qu[ 3 ] = EmptyItem;

	return Next;
}
