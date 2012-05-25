#pragma once

#include <time.h>

typedef enum
{
	e_InActive,
	e_Active,
	e_Green,
	e_Red,
}t_ButtonState;


struct AKey
{
	int				Id;
	t_ButtonState	Sequence;
	char			Displaying;
	time_t			NextAction;
};


class DisplayOutput
{
	public:
		DisplayOutput(void);
		void Update();
		bool Activate( int theKey );
		void Next( int theKeyId );
	public:
		~DisplayOutput(void);
	private:
		AKey m_Key[4];
		bool m_Updated;
//		char GetNextDisplay( char theCurrentDisplay );
//		time_t GetNextAction( char theCurrentDisplay );
		void GetNextSequence( AKey* theKey );
		char GetActivateColour( void );
		char GetInActivateColour( void );
};
