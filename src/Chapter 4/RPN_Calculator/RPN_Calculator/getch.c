#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/* getch: get one char from the buffer, if not use getchar[] */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
	//return (bufp > 0) ? buf[0] : getchar();	/* solution to the 4-8 */
}

/*ungetch: return one char into the buffer */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
		//buf[0] = c;	/* solutions to the 4-8 */
}

/* ungets: return the s strings into the buffer */
void ungets(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
	{
		ungetch(s[i]);
	}
}