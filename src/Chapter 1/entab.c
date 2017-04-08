#include <stdio.h>

#define IN 1	/* in a string of spaces */
#define OUT 0	/* out of spaces */
#define TABS 8	/* the spaces for a tab */

/* entab convert the strings of blank into tabs and string
 * with the same spacing.
 * This is the solution for K&R 1-22*/
main()
{
	int c;
	int pos;	/* pos reprensents the position in the current line */	
	int spaces;
	int i;	
	
	pos = -1;	/* set pos to -1 initially, so the index of the first
				 * position is 0 */
	spaces = 0;

	while ((c = getchar()) != EOF)
	{
		++pos;

		if (c == ' ')
		{
			++spaces;
			/* if reache the boundary
			 * of tab stops the shrink the 
			 * blanks into a tab.*/
			if (pos % TABS == TABS - 1)	
			{
				putchar('\t');
				spaces = 0;
				
			}
		}
		else
		{
			if (c == '\t')			/* if encounter a tab, release the spaces and adjust pos*/
			{
				spaces = 0;
				pos += TABS - 1 - pos%TABS;	/* Adjust the pos, attention for pos equal -1*/
			}
			else					/* if no enough spaces to fill 
										the current tab stop, release the spaces*/
				while (spaces > 0)	
				{
					putchar(' ');
					--spaces;
				}

			if (c == '\n')			/* if encounter a tab, reset the pos to -1*/
			{	
				pos = -1;		
			}

			putchar(c);
			
		}
	}
}
