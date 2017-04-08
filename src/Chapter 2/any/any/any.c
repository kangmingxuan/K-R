#include <string.h>

/* any returns the first occurrence of s2 in s1. When s1 contains no s2, 
 * any returns -1. */
int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i] != '\0' && s2[j] != '\0' && s1[i++] == s2[j++])
				;

			if (j == strlen(s2))
				return i - j;
			else
				i -= j;
		}
	}

	return -1;
}