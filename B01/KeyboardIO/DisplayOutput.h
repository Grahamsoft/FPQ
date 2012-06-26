#pragma once

#include <time.h>

typedef enum
{
	e_InActive,
	e_Active,
	e_Green,
	e_Red,
	e_InQ1,
	e_InQ2,
}t_ButtonSequence;

typedef enum
{
	e_Off,
	e_InQ,
	e_QHead,
}t_ButtonState;


struct AKey
{
	int					Id;
	t_ButtonState		State;
	t_ButtonSequence	Sequence;
	char				Displaying;
	time_t				NextAction;
	time_t				TimeInState;
	int					ScreenPosition;
	bool				FireUpdate;
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
		void SetState( AKey* theKey, t_ButtonState theState );
};
