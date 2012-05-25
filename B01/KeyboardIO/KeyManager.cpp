#include "KeyManager.h"
#include <Windows.h>

const double m_DelayInSeconds = 0.1;

KeyManager::KeyManager( DisplayOutput* theDisplayOutput, char theKeyMonitoring, Queue* theQueue )
{
	m_KeyActive		= false;
	Pressed			= 0;
	KeyPressed		= 0;
	NotSet			= 0;
	KeyDownTimer	= 0;
	KeyUpTimer		= 0;
	m_Display		= theDisplayOutput;
	m_Key			= theKeyMonitoring;
	m_Queue			= theQueue;
}

KeyManager::~KeyManager(void)
{
}

void KeyManager::KeyPress( char theKeyPressed )
{
	if( theKeyPressed == m_Key )
	{
		KeyUpTimer = NotSet;	// The key is not up so cancel and timers.

		if ( KeyDownTimer == NotSet )
		{
			KeyDownTimer = clock () + ( m_DelayInSeconds * CLOCKS_PER_SEC );
		}
	}
}

void KeyManager::KeyNotPressed()
{
	if( KeyDownTimer != NotSet && !m_KeyActive )
	{
		if ( KeyUpTimer == NotSet )
		{
//printf( "." );
			KeyUpTimer = clock() +48;
		}
		if( clock() >= KeyUpTimer )
		{
			KeyDownTimer = NotSet;
			KeyUpTimer = NotSet;
		//	printf("%d",dd);
		//	dd++;
			//printf( "-" );
		}
	}
}

void KeyManager::CheckTimers()
{
		// CHECK TIMERS
		if ( KeyDownTimer != NotSet )
		{
			if ( clock() >= KeyDownTimer )
			{	
				switch( KeyManager::m_Key )
				{
					case '1':
						if ( m_Display->Activate( 0 ) )
						{
							m_Queue->Add( 0 );
						}
						break;
					case '2':
						if ( m_Display->Activate( 1 ) )
						{
							m_Queue->Add( 1 );
						}
						break;
					case '3':
						if ( m_Display->Activate( 2 ) )
						{
							m_Queue->Add( 2 );
						}
						break;
					case '4':
						if ( m_Display->Activate( 3 ) )
						{
							m_Queue->Add( 3 );
						}
						break;
				}
				KeyDownTimer = NotSet;
			}
		}
}

