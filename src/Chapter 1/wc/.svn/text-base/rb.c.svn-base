#include <stdio.h>

#define NOP 0
#define PRT 1
#define WRD 2

/* copy the input to its out & replace redundant blanks by a single one
 * this is the solution for the K&R exercise 1-9.
 */
int main()
{
	int c;
	int state;
	
	state = WRD;
	while((c = getchar()) != EOF)
	{	
		/* change the state of in or out blanks.
		 * if it's in blanks, check its the first or the remains.
		 */
		if(c == ' ')
		{
			if(state == WRD)
				state = PRT;
			else
				state = NOP;
		}
		else
			state = WRD;

		if(state == WRD || state == PRT)
			putchar(c);
	}
	
	return 0;
}