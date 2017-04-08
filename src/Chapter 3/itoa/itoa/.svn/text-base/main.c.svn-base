#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXLEN 1000

void itoa(int num, char str[]);
void itoa3(int num, char str[], int width);
int itob(int num, char str[], int base);
void reverse(char str[]);

/* This is the solution to the K&R C 3-4, 3-5, 3-6. */
main()
{
	int n = INT_MIN;
	char s[MAXLEN];

	itoa(n, s);
	printf("%s\n", s); 

	itob(n, s, 16);
	printf("%s\n", s);

	itoa3(n, s, 6);
	printf("%s\n", s);

	return 0;
}

/* itoa convert n into its corresponding string representation. 
 * This version of ito can handle the value of -(2^(wordlength - 1))
 * in a 2's complement machine. */

void itoa(int n, char s[])
{
	int i, sign;
	
	i = 0;

	sign = n;

	/* handle the INT_MIN*/
	if (n < 0)
	{
		if (n % 10 <= 0)
		{
			s[i++] = -(n % 10) + '0';
		}else
		{
			s[i++] = 10 - n % 10 + '0';
		}
		n /= 10;
	}

	/* record the sign and make n positive*/
	if (sign < 0)
	{
		n = -n;
	}

	while (n != 0)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	} 

	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s);
}

/* itob converts n into base b string representation.
 * Note that if b > 16 then itob can't handle it correctly.*/
int itob(int n, char s[], int b)
{
	int i, sign;
	char digits[] = "0123456789ABCDEF";

	if (b > 16)
		return -1;

	i = 0;
	
	sign = n;

	/* handle the INT_MIN*/
	if (n < 0)
	{
		if (n % b <= 0)
		{
			s[i++] = digits[-(n % b)];
		}else
		{
			s[i++] = digits[b - (n % b)];
		}
		n /= b;
	}

	/* record the sign and make n positive*/
	if (sign < 0)
	{
		n = -n;
	}

	while (n != 0)
	{
		s[i++] = digits[n % b];
		n /= b;
	} 

	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s);

	return 0;
}

/* itoa3 accepts 3 arguments, the third argument specify the 
 * the minimum width of the output string. If no enough charcters, 
 itoa3 pads blanks to the left of the string. */

void itoa3(int n, char s[], int w)
{
	int i, j, len, sign;
	
	i = 0;
	sign = n;

 	if (sign < 0)
	{
		if (n % 10 <= 0)
		{
			s[i++] = -(n % 10) + '0';
		}
		else
		{
			s[i++] = 10 - n % 10 + '0';
		}

		n /= 10;
		n = -n;
	}


	while (n != 0)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	
	len = strlen(s);
	if (len < w)
	{
		for (j = 0; j < w - len; j++)
		{
			s[i++] = ' ';
		}
		s[i] = '\0';
		reverse(s);
	}
	else
	{
		reverse(s);
	}

}

void reverse(char s[])
{
	int i, j;
	char temp;

	for ( i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}