#include <stdio.h>

#define BUFSIZE 100

static int buf[BUFSIZE];
static int bufp = 0;

/* getch: get one char from the buffer, if not use getchar[] */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*ungetch: return one char into the buffer */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}