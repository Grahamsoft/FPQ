#include "DisplayOutput.h"
#include <Windows.h>
#include <stdio.h>

#include <conio.h>


DisplayOutput::DisplayOutput(void)
{
	m_Key[ 0 ].NextAction		= 0;
	m_Key[ 0 ].State			= e_Off;
	m_Key[ 0 ].TimeInState		= 0;
	m_Key[ 0 ].ScreenPosition	= 18;
	m_Key[ 0 ].FireUpdate		= false;
	m_Key[ 1 ].NextAction		= 0;
	m_Key[ 1 ].State			= e_Off;
	m_Key[ 1 ].TimeInState		= 0;
	m_Key[ 1 ].ScreenPosition	= 24;
	m_Key[ 1 ].FireUpdate		= false;
	m_Key[ 2 ].NextAction		= 0;
	m_Key[ 2 ].State			= e_Off;
	m_Key[ 2 ].TimeInState		= 0;
	m_Key[ 2 ].ScreenPosition	= 30;
	m_Key[ 2 ].FireUpdate		= false;
	m_Key[ 3 ].NextAction		= 0;
	m_Key[ 3 ].State			= e_Off;
	m_Key[ 3 ].TimeInState		= 0;
	m_Key[ 3 ].ScreenPosition	= 36;
	m_Key[ 3 ].FireUpdate		= false;
//	m_Updated = true;

	system("cls");
	printf( "Customers:      [   ] [   ] [   ] [   ]" );
}

DisplayOutput::~DisplayOutput(void)
{
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
			}


		}
	}

	//	printf( "%d\n", ( ( clock() - m_Key[ 0 ].TimeInState ) % CLOCKS_PER_SEC ) );

	if ( ( ( ( clock() - m_Key[ 0 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) ||  ( ( ( clock() - m_Key[ 1 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) || ( ( ( clock() - m_Key[ 2 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) || ( ( ( clock() - m_Key[ 3 ].TimeInState ) % CLOCKS_PER_SEC ) < 10 ) )
	{
		m_Updated = true;
	}

	if ( m_Updated )
	{
		//gotoxy( 18, 0 );
		//printf( "%c", m_Key[ 0 ].Displaying );

		//gotoxy( 24, 0 );
		//printf( "%c", m_Key[ 1 ].Displaying );


	//	printf( "Customers:      [ %c ] [ %c ] [ %c ] [ %c ]\n", m_Key[ 0 ].Displaying, m_Key[ 1 ].Displaying, m_Key[ 2 ].Displaying, m_Key[ 3 ].Displaying );
	//	m_Updated = false;
		
	//	printf( "%d\n", ( ( clock() - m_Key[ 0 ].TimeInState ) / CLOCKS_PER_SEC ) );
	//	printf( "%d\n", ( ( clock() - m_Key[ 1 ].TimeInState ) / CLOCKS_PER_SEC ) );
	//	printf( "%d\n", ( ( clock() - m_Key[ 2 ].TimeInState ) / CLOCKS_PER_SEC ) );
	//	printf( "%d\n", ( ( clock() - m_Key[ 3 ].TimeInState ) / CLOCKS_PER_SEC ) );

		//gotoxy(10, 10);




	///	printf("Hello");

	//	cprintf("Hello");


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
		//m_Key[ theKeyId ].State = e_InQ;
		//m_Key[ theKeyId ].TimeInState = clock();
		//			m_Updated = true;
		return true;
	}
	else
	{
		return false;
	}
}

void DisplayOutput::Next( int theKeyId )
{
	for( int i = 0; i < 4; i++ )
	{
		if ( m_Key[ i ].State == e_QHead )
		{
//			m_Key[ i ].State = e_Off;
//			m_Key[ i ].NextAction = 0;
//
////			m_Key[ i ].Displaying = GetInActivateColour();
//			m_Updated = true;

 			SetState( &m_Key[ theKeyId ], e_Off );
		}
	}

	if ( theKeyId != -1 )
	{
		SetState( &m_Key[ theKeyId ], e_QHead );
	}
}

//char DisplayOutput::GetNextDisplay( char theCurrentDisplay )
//{
//	switch ( theCurrentDisplay )
//	{
//		case 'R':
//			return 'G';
//			break;
//
//		case 'G':
//		default:
//			return 'R';
//			break;
//	}
//}
//
//time_t DisplayOutput::GetNextAction( char theCurrentDisplay )
//{
//	switch ( theCurrentDisplay )
//	{
//		case 'R':
//			return CLOCKS_PER_SEC * 1;
//			break;
//
//		case 'G':
//		default:
//			return CLOCKS_PER_SEC * 1;
//			break;
//	}
//}

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

