#include <stdio.h>

#define OUT	-1	/* out of comments*/
#define IN 1	/* in comments */
#define QUOTE 2 /* in quotes */


/* decomment removes all the comments in c source code.
 * Attention to the quotes in the source code to be processed.
 * This is the solution for the K&R 1-23 */
int main()
{
	int c; 
	int state;	/* record the status of the process in or out comments or in quotes*/
	char qm;	/* the quote mark of the current quote */
	
	state = OUT; /* initially the state was out of any comments */
	
	while((c = getchar()) != EOF){
		
		/* Chanege the state of processing */
		if (state == OUT){
			if (c == '\'' || c == '\"'){	/* when we met quotes */
				qm = c;
				state = QUOTE;
			}
			else if (c == '/'){
				if ((c = getchar()) == '*')
					state = IN;
				else
					putchar('/');
			}
		}
		else if (state == IN){
			if (c == '*' && (c = getchar()) == '/'){
				c = getchar();
				state = OUT;
			}
		}
		else if (state == QUOTE)
			if (c == '\\'){
				putchar(c);	
				c = getchar();
			}
			else if (c = qm)
				state = OUT;
		
		if (state != IN)	/* remove the contents in the comments */
			putchar(c);			
	}

	return 0;
}
