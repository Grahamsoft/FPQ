// KeyboardIO.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "KeyManager.h"
#include "DisplayOutput.h"
#include "Queue.h"
static int dd = 0;

int main( int argc, char *argv[] )
{
	DisplayOutput *Display = new DisplayOutput();

	Queue *QueueSys = new Queue();

	KeyManager *KM_A = new KeyManager( e_Customer, Display, '1', QueueSys );
	KeyManager *KM_B = new KeyManager( e_Customer, Display, '2', QueueSys );
	KeyManager *KM_C = new KeyManager( e_Customer, Display, '3', QueueSys );
	KeyManager *KM_D = new KeyManager( e_Customer, Display, '4', QueueSys );

	KeyManager *KM_E = new KeyManager( e_Staff, Display, 'q', QueueSys );
	KeyManager *KM_F = new KeyManager( e_Staff, Display, 'w', QueueSys );
	KeyManager *KM_G = new KeyManager( e_Staff, Display, 'e', QueueSys );
	KeyManager *KM_H = new KeyManager( e_Staff, Display, 'r', QueueSys );

	while ( 1 )
	{
		KM_A->CheckTimers();
		KM_B->CheckTimers();
		KM_C->CheckTimers();
		KM_D->CheckTimers();

        if( kbhit() )
        {
			char KeyPressed = getch();
			KM_A->KeyPress( KeyPressed );
			KM_B->KeyPress( KeyPressed );
			KM_C->KeyPress( KeyPressed );
			KM_D->KeyPress( KeyPressed );

			KM_E->KeyPress( KeyPressed );
			KM_F->KeyPress( KeyPressed );
			KM_G->KeyPress( KeyPressed );
			KM_H->KeyPress( KeyPressed );

			//if ( KeyPressed == ' ' )
			//{
			//	Display->Next( QueueSys->Next() );
			//}
        }
		else
		{
			KM_A->KeyNotPressed();
			KM_B->KeyNotPressed();
			KM_C->KeyNotPressed();
			KM_D->KeyNotPressed();
		}

		Display->Update();
	}
	
	return 0;

}

