#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

int main( int argc, char *argv[] )
{
  short	Pressed = 0;
	char	KeyPressed = 0;
	time_t	KeyDown =0, KeyUp = 0;
	//short	KeyDown = 0;
	int dd = 0;

	while ( 1 )
	{
		//printf( "Hello" );
		if ( KeyDown != 0 )
		{
			if ( clock() >= KeyDown )
			{
				printf("%d\n",dd);
				dd++;
				//printf( "Pressed for 2 seconds" );
				KeyDown = 0;
			}
		}

        if( kbhit() )
        {
			KeyUp = 0;
				KeyPressed = getch();
				if ( KeyDown == 0 )
				{
					KeyDown = clock () + ( 1 * CLOCKS_PER_SEC );
				}
				

			//KeyPressed = getch();
        }
		else
		{
			if( KeyDown != 0 )
			{
				if ( KeyUp == 0 )
				{
					KeyUp = clock() +48;
				}
				else if( clock() >= KeyUp )
				{
					KeyDown = 0;
					KeyUp = 0;
				//	printf("%d",dd);
				//	dd++;
					//printf( "-" );
				}
			}
		}
	}
	
	return 0;

}