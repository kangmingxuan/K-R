#include <stdio.h>

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
		printf("error: stack empty, can't pop\n");
		return 0.0;
	}
}

/* top: return the top element of the stack */
double top(void)
{	
	if (sp > 0)
		return val[sp - 1];
	else{
		printf("error: stack empty, no top element!\n");
		return 0.0;
	}
}

/* duptop: dup the top element of the stack */
void duptop(void)
{
	if (sp == 0){
		printf("error: stack empty, can't duplicate!\n");
		return;
	}
	if (sp == MAXVAL){
		printf("error: stack full, can't duplicate %g\n", top());
		return;
	}

	push(top());
}

/* swtop: swap the top 2 elements of the stack */
void swtop(void)
{
	double temp;
	if (sp > 1){
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
	else
		printf("error: no enough elements to perform swap.\n");
}

/* clearstack: clear the stack. This maybe useful when the 
 * the status of the calculator is in chaos. */
void clearstack(void)
{
	sp = 0;
}













































