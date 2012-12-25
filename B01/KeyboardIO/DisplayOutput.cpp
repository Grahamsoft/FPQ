#include "DisplayOutput.h"
#include <Windows.h>
#include <stdio.h>

#include <conio.h>


DisplayOutput::DisplayOutput(void)
{
	m_Key[ 0 ].NextAction		= 0;
	m_Key[ 0 ].State			= e_Unallocated;
	m_Key[ 0 ].TimeInState		= 0;
	m_Key[ 0 ].ScreenPosition	= 18;
	m_Key[ 0 ].FireUpdate		= false;
	m_Key[ 1 ].NextAction		= 0;
	m_Key[ 1 ].State			= e_Unallocated;
	m_Key[ 1 ].TimeInState		= 0;
	m_Key[ 1 ].ScreenPosition	= 24;
	m_Key[ 1 ].FireUpdate		= false;
	m_Key[ 2 ].NextAction		= 0;
	m_Key[ 2 ].State			= e_Unallocated;
	m_Key[ 2 ].TimeInState		= 0;
	m_Key[ 2 ].ScreenPosition	= 30;
	m_Key[ 2 ].FireUpdate		= false;
	m_Key[ 3 ].NextAction		= 0;
	m_Key[ 3 ].State			= e_Unallocated;
	m_Key[ 3 ].TimeInState		= 0;
	m_Key[ 3 ].ScreenPosition	= 36;
	m_Key[ 3 ].FireUpdate		= false;


	m_Key[ 4 ].State			= e_Unallocated;
	m_Key[ 4 ].ScreenPosition	= 1;
	m_Key[ 5 ].State			= e_Unallocated;
	m_Key[ 5 ].ScreenPosition	= 2;
	m_Key[ 6 ].State			= e_Unallocated;
	m_Key[ 6 ].ScreenPosition	= 3;
	m_Key[ 7 ].State			= e_Unallocated;
	m_Key[ 7 ].ScreenPosition	= 4;

	m_Key[ 0 ].BeingServedBy	= -1;
	m_Key[ 1 ].BeingServedBy	= -1;
	m_Key[ 2 ].BeingServedBy	= -1;
	m_Key[ 3 ].BeingServedBy	= -1;
	m_Key[ 4 ].BeingServedBy	= -1;
	m_Key[ 5 ].BeingServedBy	= -1;
	m_Key[ 6 ].BeingServedBy	= -1;
	m_Key[ 7 ].BeingServedBy	= -1;

	system("cls");
	printf( "Customers:      [   ] [   ] [   ] [   ]\n" );
	printf( "Staff:\n" );
	printf( "Staff:\n" );
	printf( "Staff:\n" );
	printf( "Staff:\n" );
}

DisplayOutput::~DisplayOutput(void)
{
}

int DisplayOutput::GetButtonId()
{
	int i = 0;
	for( i = 0; i < 8; i++ )
	{
		if ( m_Key[ i ].State == e_Unallocated )
		{
			m_Key[ i ].State = e_Off;
			m_Key[ i ].Id = i;
			break;
		}
	}
	return i;
}

void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}

void DisplayOutput::Update()
{
	for( int i = 0; i < 4; i++ )
	{
		if ( clock() >= m_Key[ i ].NextAction )
		{
			GetNextSequence( &m_Key[ i ] );

			if ( m_Key[ i ].FireUpdate )
			{
				gotoxy( m_Key[ i ].ScreenPosition, 0 );
				printf( "%c", m_Key[ i ].Displaying );
				m_Key[ i ].FireUpdate = false;

				if ( m_Key[ i ].BeingServedBy != -1 )
				{
					gotoxy( 8, m_Key[ m_Key[ i ].BeingServedBy ].ScreenPosition );
					printf( "%i %c", m_Key[ i ].Id, m_Key[ i ].Displaying );

				}
			}
		}
	}

	if ( ( ( ( clock() - m_Key[ 0 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) ||  ( ( ( clock() - m_Key[ 1 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) || ( ( ( clock() - m_Key[ 2 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) || ( ( ( clock() - m_Key[ 3 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) )
	{
		m_Updated = true;
	}
}

char DisplayOutput::GetActivateColour()
{
	return 'R';
}

char DisplayOutput::GetInActivateColour()
{
	return ' ';
}

bool DisplayOutput::Activate( int theKeyId )
{
	if ( m_Key[ theKeyId ].State == e_Off )
	{
		SetState( &m_Key[ theKeyId ], e_InQ );
		return true;
	}
	else
	{
		return false;
	}
}

void DisplayOutput::Next( int theKeyId, int theStaffId )
{
	for( int i = 0; i < 4; i++ )
	{
		if ( ( m_Key[ i ].State == e_QHead) &&( m_Key[ i ].BeingServedBy == theStaffId ) )
		{
 			SetState( &m_Key[ i ], e_Off );
			m_Key[ i ].BeingServedBy = theStaffId = -1;
		}
	}

	if ( theKeyId != -1 )
	{

		m_Key[ theKeyId ].BeingServedBy = theStaffId;
		SetState( &m_Key[ theKeyId ], e_QHead );
	}
}

void DisplayOutput::GetNextSequence( AKey* theKey )
{
	t_ButtonSequence LastSequence	= theKey->Sequence;
	t_ButtonState LastState			= theKey->State;

	switch ( theKey->State )
	{
		case e_Off:
			theKey->Displaying	= GetInActivateColour();
			break;

		case e_InQ:
			theKey->Displaying	= GetActivateColour();

			switch ( theKey->Sequence )
			{
				case e_InQ2:
					theKey->Sequence = 	e_InQ1;
					theKey->NextAction = clock() + CLOCKS_PER_SEC * 0.2;
					theKey->Displaying = ' ';
					break;

				case e_InQ1:
				default:
					theKey->Sequence = 	e_InQ2;
					theKey->NextAction = clock() + CLOCKS_PER_SEC * 2.0;
					theKey->Displaying = GetActivateColour();
					break;
			}

			break;

		case e_QHead:
			switch ( theKey->Sequence )
			{
				case e_Red:
					theKey->Sequence = e_Green;
					theKey->NextAction = clock() + CLOCKS_PER_SEC * 1.0;
					theKey->Displaying = 'R';
					break;

				case e_Green:
				default:
					theKey->Sequence = e_Red;
					theKey->NextAction = clock() + CLOCKS_PER_SEC * 1.0;
					theKey->Displaying = 'G';
					break;
			}
			break;
	}
	if ( LastSequence != theKey->Sequence || LastState != theKey->State )
	{
		theKey->FireUpdate = true;
	}
}

void DisplayOutput::SetState( AKey* theKey, t_ButtonState theState )
{
	theKey->State = theState;
	theKey->FireUpdate = true;
	theKey->NextAction = 0;
	theKey->TimeInState = clock();
}

