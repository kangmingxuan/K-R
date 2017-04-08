#include <stdio.h>

#define MAXLEN 1024	/* MAXLEN for the depth of the stack */
#define OUT 0		/* out of spcific constructures */
#define INC 1		/* in comments */
#define INQ 2		/* int quotes */

char paren_stack[MAXLEN];	/* stack for handling the parentheses etc. */
int sp;						/* stack pointer */

char pushp(char paren);
char popp();
char getp();

/* cparser parse the c source code and find 
 * rudimentary syntax errors of unbalanced
 * parentheses, brackets and braces.
 * This it the solution to the K&R 1-24 */
main()
{
	int c;
	char qmark, paren;
	int state;
	int line;	/* the current line num */
	
	state = OUT;
	line = 1;
	sp = -1;	/* initial the stack pointer */
	
	while ((c = getchar()) != EOF){
		if (c == '\n')	/* record the line number */
			++line;
	
		if (state == OUT){
			putchar(c);
			if (c == '\'' || c == '\"'){	/* when we met quotes */
				qmark = c;
				state = INQ;
			}
			else if (c == '/'){				/* when we met comments */
				if ((c = getchar()) == '*')
					state = INC;
			}
			else if (c == '{' || c == '(' || c == '['){
				if (pushp(c) == '\0'){
					printf("Sorry, we can't handle source code contains too" 
					" many brackets.\n");
					return -1;	
				}
			}
			else if (c == '}' || c == ')' || c == ']'){
				paren = getp();
				switch (paren){
					case '{':
						
						if(c == '}')
							popp();
						else
							printf("\nUnbalanced brackets in line %d.\n", line);
						break;
					case '(':
						if(c == ')')
							popp();
						else
							printf("\nUnbalanced parentheses in line %d.\n", line);
						break;
					case '[':
						if(c == ']')
							popp();
						else
							printf("\nUnbalanced braces in line %d.\n", line);
						break;
					default:
						printf("\nUnbalanced %c in line %d.\n", c, line);
				}
			}		
		}
		else if (state == INC){
			if (c == '*' && (c = getchar()) == '/'){
				state = OUT;
			}
		}
		else if (state == INQ){
			putchar(c);
			if (c == '\\'){
				c = getchar();	/* skip the escape seqence */
				putchar(c);
				c = getchar();
				putchar(c);
			}
			if (c == qmark)
				state = OUT;
		}
	}

	return 0;
}

/* "push" push one char into the stack 
 * and modify the stack pointer.
 * If the stack overflow then push returns '\0' */

char pushp(char paren)
{
	sp = sp + 1;

	if (sp < MAXLEN){
		paren_stack[sp] = paren;
		return paren;
	}
	else
		return '\0';
}
/* "pop" pop one char out of the stack, and modify the stack pointer */

char popp()
{
	char paren;
	if (sp > -1){
		paren = paren_stack[sp--];
		return paren;
	}
	else
		return '\0';
}

char getp()
{
	return paren_stack[sp];
}