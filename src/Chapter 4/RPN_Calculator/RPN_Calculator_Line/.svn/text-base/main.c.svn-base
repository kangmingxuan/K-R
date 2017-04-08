#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100		/* max size of a operand */
#define NUMBER '0'		/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* RPN(Reverse Polish Calculator)
 * This is the solution to K&R C 4-10 */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
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
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}

#define MAXVAL 100 /*maximum depth of val stack */

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n");
}

/* pop: pop and return the top value of the stack */
double pop(void)

{
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty!\n");
		return 0.0;
	}
}

#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

char line[MAXLINE];
int lp = 0;
int getline(char s[], int lim);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	if (strlen(line) == lp)
		if (getline(line, MAXLINE) == 0)
			return EOF;
		else
			lp = 0;
	while ((s[0] = c = line[lp++]) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;	/* not a number */

	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[lp++]))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = line[lp++]))
			;
	s[i] = '\0';
	
	--lp;

	return NUMBER;
}

/* getline: get a line into s, return the num of the chars, 0 means no char*/
int getline(char s[], int lim)
{
	int i, c;
	
	i = 0;
	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = '\n' ;
	s[i] = '\0';
	
	return i;
}