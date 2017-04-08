#include <stdio.h>
#include <string.h>

void reverse(char[], int, int);
void reverse_p(char *left, char *right);
/* This is the solution to the K&R C 4-13  and 5-6 */
main()
{
	char s[] = "I am the object to reverse.";
	
	reverse(s, 0, strlen(s) - 1);
	printf("%s\n", s);

	reverse(s, 0, strlen(s) - 1);
	printf("%s\n", s);

	reverse_p(s, s + strlen(s) - 1);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[], int left, int right)
{
	int temp;

	if (left >= right)
	{
		return;
	}
	else
	{
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;

		reverse(s, left + 1, right - 1);

	}
}
/* reverse_p: reverse routine implemented by pointers */
void reverse_p(char *left, char *right)
{
	int temp;

	if (left >= right)
	{
		return;
	}
	else
	{
		temp = *left;
		*left = *right;
		*right = temp;

		reverse_p(left + 1, right - 1);

	}
}