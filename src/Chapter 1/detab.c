#include <stdio.h>

#define TABS 8	

/* detab converts every tab in the input into corresponding spaces*/

int main()
{
	int c;
	int posl;	/* position in the current line, 
				 * the first position with the index 0*/
	int dis;	/* distance to the next tab stop*/
	
	posl = -1;	/* right for the initial pos??*/
	while ((c = getchar()) != EOF)
	{
		++posl;	/* get the current position in the line */

		if (c == '\n')
		{
			posl = -1;
			putchar(c);
		}
		else if (c == '\t')
		{
			dis = 8 - posl % 8;
			--posl;
			while(dis-- > 0)
			{
				putchar('*');	/* use '*' instead of spaces for the brivety*/
				++posl;
			}
		}
		else
			putchar(c);
	}
	
	return 0;
}