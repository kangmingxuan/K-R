#include <ctype.h>

/* htoi converts a string of hexadecimal digits(including an optional 0x or
 * 0X) into its equivalent integer values. */
int htoi(char s[])
{
	int i;
	int n;	/* n hold the result value of the conversion */
	char curr;

	i = 0;
	/* test if there is a optional ox or 0X */
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		i = 2;
	}

	n = 0;
	while (s[i] != '\0')
	{
		curr = s[i];
		if (isalpha(curr))
		{
			curr = tolower(curr) - 'a' + 10;
		}
		else if (isdigit(curr))
		{
			curr = curr - '0';
		}

		n = n * 0x10 + curr;

		++i;
	}

	return n;
}