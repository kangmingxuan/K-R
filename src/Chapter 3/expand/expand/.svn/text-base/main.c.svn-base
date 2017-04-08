#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

void expand(char s1[], char s2[]);

/* This is the solution to K&R C 3-3 */
main()
{
	char s1[] = "Let's see if 'expand' works: a-c 1-9 -a-d0-7-";
	char s2[MAXLEN];

	expand(s1, s2);
	printf("%s\n%s\n", s1, s2);

	return 0;
}
/* expand expands shorthand notations like a-z in 
 * the string s1 into the equivalent complete list
 * abc...xyz in s2. Suppose that s2 has enough space
 * to store the expanded string */
void expand(char s1[], char s2[])
{
	int i, j;
	char k;

	for (i = 0, j = 0; s1[i] != '\0'; ++i, ++j)
	{
		if ((isalpha(s1[i]) || isdigit(s1[i])) && s1[i + 1] == '-' && s1[i + 2] >= s1[i])
		{
			for(k = s1[i]; k <= s1[i + 2]; ++k)
			{
				s2[j++] = k;
			}
			/* modify the current pointer */
			--j;
			i += 2;
		}
		else
		{
			s2[j] = s1[i];
		}
	}

	s2[j] = '\0';
}