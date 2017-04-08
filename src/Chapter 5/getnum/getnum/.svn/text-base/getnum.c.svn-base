#include <stdio.h>
#include <ctype.h>
#include "getnum.h"

/* getint: get the next integet from input into *pn 
 * OUTPUT: EOF for end of file, 0 for non integet, 
 * positive value for a valid number */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))	/* skip the white spaces */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		int d = c;
		if (!isdigit(c = getch())){
			ungetch(c);
			ungetch(d);
			return 0;
		}
	}
	for ( *pn = 0; isdigit(c); c = getch())
		*pn = *pn * 10 + c - '0';
	*pn *= sign;

	ungetch(c);
	return c;
}

/* getfloat: get the next float from input into *pn 
 * OUTPUT: EOF for end of file, 0 for non integet, 
 * positive value for a valid number */
int getfloat(float *pf)
{
	int c;
	double power, sign;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);		/* is not a number */
		return 0;
	}

	sign = (c == '-') ? -1.0 : 1.0;
	if (c == '+' || c == '-'){
		int d = c;
		if (!isdigit(c = getch()) && c != '.'){
			ungetch(c);
			ungetch(d);
			return 0;
		}
	}
	
	for (*pf = 0.0; isdigit(c); c = getch())	
		*pf = *pf * 10.0 + (c - '0');	/* collect the integer part */
	if (c == '.')
		c = getch();
	for(power = 1.0 ; isdigit(c); c = getch()){
		*pf = *pf * 10.0 + (c - '0');	/* collect the float part */
		power *= 10.0;
	}

	*pf = sign * *pf / power;

	if (c != EOF)
		ungetch(c);

	return c;
}