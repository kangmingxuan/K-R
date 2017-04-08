#include <stdio.h>

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int i = 0, c;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
	{
		s[i++] = c;
	}

	if (c == '\n')
	{
		s[i++] = '\n';
	}

	s[i] = '\0';

	return i;
}