#include <stdio.h>

#define MAXLINE 1000

int strrindex(char str[], char pattern[]);
int	strindex(char str[], char patter[]);
int getline(char source[], int max);

/* This is the solution to the K&R C 4-1. */
main()
{
	int found = 0;
	char pattern[] = "hat";
	char line[MAXLINE];

	while (getline(line, MAXLINE) > 0)
	{
		if (strrindex(line, pattern) >= 0)
		{
			printf("%s%d\n", line, strrindex(line, pattern));
			++found;
		}
	}

	return found;
}
