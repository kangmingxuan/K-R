#include <stdio.h>
#define MAXLINE 80   /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line of arbitrary length
 * This is the solution for K&R exercise 1-16*/
main()
{
	int len, curlen;    /* current line length */
	int max;            /* maximum length seen so far */
	char line[MAXLINE];    /* current input line */
	char longest[MAXLINE]; /* longest line saved here */	
	
	max = 0;
	
	while ((curlen = getline(line, MAXLINE)) > 0)
	{
		/* Get the actual length of line longer than MAXLINE-1 */
		len = 0;
		while (curlen == MAXLINE - 1 && line[curlen - 1] != '\n')
		{
			len = len + MAXLINE - 1;
			curlen = getline(line, MAXLINE);
		}
		len = len + curlen;
	
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	
	if (max > 0)  /* there was a line */
	{
		printf("%s", longest);
		printf("The length of the longest line: %d", max);
	}
	return 0;
}
/* getline:  read a line into s, return length  */
int getline(char s[],int lim)
{
	int c, i;
	
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	return i;
}
/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}