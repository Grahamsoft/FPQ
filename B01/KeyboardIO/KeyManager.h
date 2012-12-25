#pragma once

#include <time.h>
#include "DisplayOutput.h"
#include "Queue.h"

typedef enum
{
	e_Customer,
	e_Staff,
}t_ButtonUse;

class KeyManager
{
public:
	KeyManager( t_ButtonUse theKeyUse, DisplayOutput* theDisplayOutput, char theKeyMonitoring, Queue* theQueue );
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
	int m_DisplayMapping;
	t_ButtonUse m_KeyUse;

};
