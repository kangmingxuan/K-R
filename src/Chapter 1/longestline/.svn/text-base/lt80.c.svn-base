#include <stdio.h>

#define MAXLINE 1000   /* maximum input line length */
#define THRESHOLD 80

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print any line longer than 80
 * This is the solution for K&R 1-17
 */
main()
{
	int len, curlen;    /* current line length */
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
		
		/* Print any line longer than THRESHOLD */
		if (len > THRESHOLD) {
			printf("%s", line);
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
/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}