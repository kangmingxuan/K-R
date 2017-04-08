#include <string.h>

/* squeeze removes character sequences in s1 wherever it matches s2 */
void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = j = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] == s2[0])	/* check if there is pattern s2 in s1 */
		{
			k = 0;
			while (s1[i] != '\0' && s2[k] != '\0' && s1[i++] == s2[k++])	
				;

			if (k != strlen(s2))	/* when pattern in s1 don't match s2*/
				i -= k;
		}

		s1[j++] = s1[i];
	}

	s1[j] = '\0';

	return;
}