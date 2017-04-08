#include <string.h>

/* strrindex: return index of rightmost t in string s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k;
	if (strlen(t))
	{
		for (i = strlen(s) - 1; i >=0 ; i--)
		{
			for (j = i, k = strlen(t) - 1; j >= 0 && k >= 0 && s[j] == t[k] ; j--, k--)
				;
			if (k == -1)
				return (i - strlen(t) + 1);
		}
	}

	return -1;
}