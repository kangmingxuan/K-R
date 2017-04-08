#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxlength);
void reverse(char sz[]);
int len(char sz[]);

/* reverse the input a line per time
 * This is the solution for the K&R 1-19
 */

main()
{
	char s[MAXLINE];
	
	while(getline(s, MAXLINE) > 0)
	{
		reverse(s);
		printf("%s", s);
	}
	
	return 0;
}

/* getline: read a line into line[], and return its length*/
int getline(char line[], int max)
{
	int c;
	int i; 
	
	c = getchar();
	for(i = 0; i < max - 1 && c != '\n' && c != EOF; ++i)	
	{
		line[i] = c;
		c = getchar();
	}
	
	if(c == '\n')
	{
		line[i] = c;
		++i;
	}
	
	line[i] = '\0';
	
	return i;
	
}
/* reverse the char array sz,
 * ATTENTION: this version reverse only the content of a line, without 
 * newline character '\n'. This implies that every sz this function processed
 * end with a '\n' */
void reverse(char sz[])
{
	int i;
	char c;	/* temporary char for exchange */
	int length;
	
	length = len(sz);
	
	for(i = 0; i < (length - 1) / 2; ++i)	/* length - 1 preclude the '\n'*/
	{
		c = sz[i];
		sz[i] = sz[length - 2 - i];
		sz[length - 2 - i] = c;
	}
	
}
/* len: return the length of the string without the final '\0' */
int len(char sz[])
{
	int i;
	
	i = 0;
	while(sz[i++] != '\0')
		;
		
	return --i;
		
}