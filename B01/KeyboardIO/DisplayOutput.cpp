#include "DisplayOutput.h"
#include <Windows.h>
#include <stdio.h>

DisplayOutput::DisplayOutput(void)
{
	m_Key[ 0 ].Displaying	= GetInActivateColour();
	m_Key[ 0 ].NextAction	= 0;
	m_Key[ 0 ].Sequence		= e_InActive;
	m_Key[ 1 ].Displaying	= GetInActivateColour();
	m_Key[ 1 ].NextAction	= 0;
	m_Key[ 1 ].Sequence		= e_InActive;
	m_Key[ 2 ].Displaying	= GetInActivateColour();
	m_Key[ 2 ].NextAction	= 0;
	m_Key[ 2 ].Sequence		= e_InActive;
	m_Key[ 3 ].Displaying	= GetInActivateColour();
	m_Key[ 3 ].NextAction	= 0;
	m_Key[ 3 ].Sequence		= e_InActive;
	m_Updated = true;
}

DisplayOutput::~DisplayOutput(void)
{
}

void DisplayOutput::Update()
{
	for( int i = 0; i < 4; i++ )
	{
		if ( m_Key[ i ].Sequence == e_InActive )
		{
			continue;
		}

		if ( clock() >= m_Key[ i ].NextAction )
		{
			m_Updated = true;
			GetNextSequence( &m_Key[ i ] );
		}
	}

	if ( m_Updated )
	{
		system("cls");
		printf( "Customers:\t [ %c ] [ %c ] [ %c ] [ %c ]\n", m_Key[ 0 ].Displaying, m_Key[ 1 ].Displaying, m_Key[ 2 ].Displaying, m_Key[ 3 ].Displaying );
		m_Updated = false;
	}
}

char DisplayOutput::GetActivateColour()
{
	return 'R';
}

char DisplayOutput::GetInActivateColour()
{
	return '*';
}

bool DisplayOutput::Activate( int theKeyId )
{
	if ( m_Key[ theKeyId ].Displaying == GetInActivateColour() )
	{
		m_Key[ theKeyId ].Displaying = GetActivateColour();
		m_Updated = true;
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
		if ( m_Key[ i ].Sequence != e_InActive )
		{
			m_Key[ i ].Sequence = e_InActive;

			m_Key[ i ].Displaying = GetInActivateColour();
			m_Updated = true;
		}
	}

	if ( theKeyId != -1 )
	{
		m_Key[ theKeyId ].Sequence = e_Active;
		m_Updated = true;
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
	t_ButtonState LastSequence

	switch ( theKey->Sequence )
	{
		case e_InActive:
			theKey->Sequence = e_InActive;
			theKey->Displaying = ' ';
			break;

		case e_Active:
			theKey->Sequence = e_Green;
			theKey->NextAction = clock();
			break;

		case e_Green:
			theKey->Sequence = e_Red;
			theKey->NextAction = clock() + CLOCKS_PER_SEC * 1.0;
			theKey->Displaying = 'G';
			break;

		case e_Red:
		default:
			theKey->Sequence = e_Green;
			theKey->NextAction = clock() + CLOCKS_PER_SEC * 1.0;
			theKey->Displaying = 'R';
			break;
	}
}

