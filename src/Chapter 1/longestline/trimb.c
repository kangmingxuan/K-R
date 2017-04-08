#include <stdio.h>

#define MAXLINE 80   /* maximum input line length */

int getline(char line[], int maxline);

/* Reomove trailing blanks in the input line.
 * This is the solution for K&R 1-18
 */
main()
{
	int len, curlen;    /* current line length */
	int i;
	char line[MAXLINE];    /* current input line */
	
	
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
		
		
		if (len > 1)		/* Skip blank line */
		{
			/* Remove trailing blanks */
			for(i = curlen - 2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i)
				line[i] = '\0';
			
			if(i >= 0)		/* Skip blank line */
			{
				line[++i] = '\n';
				printf("%s", line);
			}
		}

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
