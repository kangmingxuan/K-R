#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Calc.h"


#define MAXOP 100		/* max size of a operand */

void calcLibFun(char s[]);

/* RPN(Reverse Polish Calculator)
 * These files are the solutions to K&R C 4-3~4-9*/
main()
{
	int type, i;
	double op2, vars[26], ans;
	char s[MAXOP];
	
	ans = 0;
	for (i = 0; i < 26; ++i)
		vars[i] = 0;

	printf("Welcome to RPN Calculator!\nEnter RPN expression and hit enter.\n");

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case LIBFUN:
			calcLibFun(s);
			break;
		case VARS:
			push(vars[s[0] - 'A']);
			break;
		case 'v':
			push(ans);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else{
				printf("error: zero divisor!\n");
			}
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor");
			break;
		case '?':	/* print the top of the stack */
			printf("\t%.8g\n", top());
			while (getch() != '\n')
				;
			break;
		case '#':	/* duplicate the top element of the stack */
			duptop();
			while (getch() != '\n')
				;
			break;
		case '$':
			swtop();
			while (getch() != '\n')
				;
			break;
		case '!':
			clearstack();
			while (getch() != '\n')
				;
			break;
		case '=':
			if(getop(s) != VARS){
				printf("error: assignment without a variable.\n");
				break;
			}
			push(vars[s[0] - 'A'] = pop());
			break;
		case '\n':
			printf("\t%.8g\n", ans = pop());
			break;
		case 'q':
			printf("Bye!");
			return 0;
		default:
			while (getch() != '\n')
				;
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}

void calcLibFun(char s[])
{
	double op2;

	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0){
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("error: unknown command %s\n", s);
}
