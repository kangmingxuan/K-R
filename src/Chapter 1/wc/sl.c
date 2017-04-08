#include <stdio.h>

#define FST 0
#define REM 1
#define WRD 2

/* This program split the input into one word per line.
 * This is the solution for excercise 1-12.
 */

int main()
{
	int c;
	int state;
	
	state = FST; /* Set the initial state. */
	
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			if(state == WRD)
			{
				state = FST;
				putchar('\n');
			}
			else
				state = REM;
		}
		else
		{
			state = WRD;
			putchar(c);
		}
	}
	
	return 0;
}