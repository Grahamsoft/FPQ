#pragma once

#include <time.h>
#include "DisplayOutput.h"
#include "Queue.h"

class KeyManager
{
public:
	KeyManager( DisplayOutput* theDisplayOutput, char theKeyMonitoring, Queue* theQueue );
	void KeyPress( char theKeyPressed );
	void KeyNotPressed( void );
	void CheckTimers( void );
public:
	~KeyManager( void );

private:
	short	Pressed;
	char	KeyPressed;
	short	NotSet;
	time_t	KeyDownTimer,
			KeyUpTimer;
	DisplayOutput* m_Display;
	Queue* m_Queue;
	bool	m_KeyActive;
	char	m_Key;
};
