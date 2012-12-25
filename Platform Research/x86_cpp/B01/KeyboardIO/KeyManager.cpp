#include "KeyManager.h"
#include <Windows.h>

const double m_DelayInSeconds = 0.1;

KeyManager::KeyManager( t_ButtonUse theKeyUse, DisplayOutput* theDisplayOutput, char theKeyMonitoring, Queue* theQueue )
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
	m_KeyUse = theKeyUse;


//	if ( m_KeyUse == e_Customer )
//	{
		m_DisplayMapping = theDisplayOutput->GetButtonId();
//	}

}

KeyManager::~KeyManager(void)
{
}

void KeyManager::KeyPress( char theKeyPressed )
{
	if( theKeyPressed == m_Key )
	{
		switch( m_KeyUse )
		{
			case e_Customer:

					KeyUpTimer = NotSet;	// The key is not up so cancel and timers.

					if ( KeyDownTimer == NotSet )
					{
						KeyDownTimer = clock () + ( m_DelayInSeconds * CLOCKS_PER_SEC );
					}

				break;
			case e_Staff:
				m_Display->Next( m_Queue->Next(), m_DisplayMapping );
				break;
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
			if ( m_Display->Activate( m_DisplayMapping ) )
			{
				m_Queue->Add( m_DisplayMapping );
			}
			KeyDownTimer = NotSet;
		}
	}
}

