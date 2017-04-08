#include <stdio.h>

#define FST 0
#define REM 1
#define WRD 2

#define MAXINPUT 80

/* This program draw the horizotal and vertical histogram of the length of words
 * in the input.
 * This is the solution for K&R excercise 1-13 & 1-14 
 */
 
int main()
{
	int c;	 /* lc for the length of the words */
	int state;
	
	int hist[MAXINPUT];	/* Set aside a array to store the length of the words*/
	int chars[54];	/* Set aside a arrary to store the frequency of each characters
					     * 0~51 for latin characters, 52 for the blanks,
						 * 53 for the other characters.
						 */
	int i, j, wc;	
	int max, maxi;
	
	state = FST; /* Set the initial state. */ 	

	/* Obtain the length of every word in the input */
	
	for(i = 0; i < MAXINPUT; ++i)
	{
		hist[i] = 0;
	}
	for(i = 0; i < 54; ++i)
	{
		chars[i] = 0;
	}
	i = 0;
	
	while((c = getchar()) != EOF)
	{
		
		/* Check if there is too many inputs */
		if(i > MAXINPUT - 1)
		{
			printf("\n\n\nToo many words!\n");
			printf("Only the number of words less than 80 is permitted!\n");
			
			return 1;
		}
		
		if(c == ' ' || c == '\t' || c == '\n')
		{
			++chars[52];
			if(state == WRD)
			{
				state = FST;
				++i;
			}
			else
				state = REM;
		}
		else
		{
			state = WRD;
			++hist[i];
			if(c >= 'a' && c <= 'z')
				++chars[c - 'a'];
			else if(c >= 'A' && c <= 'Z')
				++chars[c - 'A' + 26];
			else
				++chars[53];
			
		}
		
	}
	
	wc = i;	/* wc store the number of the words*/

	/* Draw the vertical historam of the length in the input*/

	/* Find the longest word and its index in the array hist */
	max = 0;
	maxi = 0;
	for(i = 0; i < wc; ++i)
	{
		if(hist[i] > max)
		{
			max = hist[i];
			maxi = i;
		}
	}	
	
	printf("\n\n--------------------------------------VERTICAL----------------------------------\n\n");
	for(i = 0; i < max; ++i)
	{
		for(j = 0; j < wc; ++j)
		{
			if(hist[j] >= max - i)
				putchar('#');
			else
				putchar(' ');
		}
		
		putchar('\n');
	}
	printf("\n--------------------------------------------------------------------------------\n");
	printf("%d words processed.\n", wc);
	
	system("pause");	
	
	/* Draw the vertical histogram of the character numbers*/
	max = 0;
	maxi = 0;
	for(i = 0; i < 54; ++i)
	{	
		if(chars[i] > max)
		{
			max = chars[i];
			maxi = i;
		}
	}
	
	printf("\n\n--------------------------------------CHARS-------------------------------------\n\n");
	for(i = 0; i < max; ++i)
	{
		for(j = 0; j < 54; ++j)
		{
			if(chars[j] >= max - i)
				putchar('#');
			else
				putchar(' ');
		}
		
		putchar('\n');
	}
	printf("\n\n--------------------------------------------------------------------------------\n\n");

	return 0;
}