#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define NUMBER '0'
#define OPERATOR '+'
#define INVALID  'N'

int exp_type(char *s, double *value, char *op);

/* expr evaluate a reverse Polish expression from the command line per time. 
 * This is the solution to K&R C 5-10 */
int main(int argc, char* argv[])
{
	double value;
	char op;
	double opr2;

	if (argc == 1)
	{
		printf("Please input the RPN expression!\n");
		return -1;
	}
	while (--argc > 0)
	{
		switch (exp_type(*++argv, &value, &op))
		{
		case NUMBER:
			push(value);
			break;
		case OPERATOR:
			if (op == '+')
				push(pop() + pop());
			else if (op == '-'){
				opr2 = pop();
				push(pop() - opr2);
			}
			else if (op == '*')
			{
				push(pop() * pop());
			}
			else if (op == '/')
			{
				opr2 = pop();
				push(pop() / opr2);
			}
			else{
				clearstack();
				printf("Invalid RPN expression!\n");
				return -1;
			}
			break;
		default:
			clearstack();
			printf("Invalid RPN expression!\n");
			return -1;
		}
	}
    
	printf("%g", pop());
	return 0;
}
/* exp_type: identify the type of tokens in a RPN expression */
int exp_type(char *s, double *value, char *op)
{
	int len = strlen(s);
	char *endp;

	*value = strtod(s, &endp);	/* check if it's a number */
	if (*endp == '\0')
		return NUMBER;
	else if (strlen(endp) == 1)
	{
		switch (*s)
		{
		case '+':
			*op = '+';
			return OPERATOR;
		case '-':
			*op = '-';
			return OPERATOR;
		case '*':
			*op = '*';
			return OPERATOR;
		case '/':
			*op = '/';
			return OPERATOR;
		default:
			return INVALID;
		}
	}
	else
		return INVALID;
}