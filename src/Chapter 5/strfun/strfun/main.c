#include <stdio.h>
//#include <string.h>

#define MAXLEN 100

void strcat(char *s, char *t);
int strend(char *s, char *t);
void strncpy(char *s, char *t, int n);
void strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

/* This is the solution to K&R C 5-3, 5-4 and 5-5 */
main()
{
	char s[MAXLEN] = "hello, world";
	char t[MAXLEN] = "hello.";

	//printf("%d\n", strend(s, t));
	//strcat(s, " i am the trailing sentence.\n");
	//printf("%s", s);
	//strncpy(s, t, 5);
	//strncat(s, t, 10);
	printf("%d", strncmp(s, t, 5));

	return 0;
}

/* strlen: return the length of the string */
int strlen(char *s)
{
	char *p = s;
	while (*p != '\0')
		p++;

	return p - s;
}

/* strcat: concatenate t to the end of s; s must be big enough */
void strcat(char *s, char *t)
{
	while (*s++ != '\0')
		;
	s--;
	
	while ((*s++ = *t++) != '\0')
		;
}

/* strend: return 1 if string t occurs at the end of s, otherwise 0 */
int strend(char *s, char *t)
{
	int ls = strlen(s);
	int lt = strlen(t);

	if (ls < lt)	/* just in case that s is shorter than t */
		return 0;
	s = s + ls - lt;

	while(*s == *t && *s != '\0'){
		s++;
		t++;
	}

	if (*s == '\0')
		return 1;
	else
		return 0;
}

/* strncpy: copy at most the first n characters in t to s,
 * pad '\0's if t has not enough characters. */
void strncpy(char *s, char *t, int n)
{
	if (n <= 0)
		return;

	while (n-- && (*s++ = *t++) != '\0')
		;
	if (n > 0)
		while (n--)
			*s++ = '\0';
}

/* strncat: concatenate at most the first n chars of t into s,
 * terminate s with '\0'. */
void strncat(char *s, char *t, int n)
{
	if (n <= 0)
		return;

	while(*s != '\0')
		s++;
	while(n-- && (*s++ = *t++) != '\0')
		;
	if (*(s - 1) != '\0')
		*s = '\0';
}
/* strncmp: compare by at most the first n characters of s and t */
int strncmp(char *s, char *t, int n)
{
	while (n && *s == *t){	/* find the first unmatched character */
		if (*s == '\0')
			return 0;
		n--;
		s++;
		t++;
	}

	if (n == 0)
		return *(s - 1) - *(t - 1);
	else
		return *s - *t;

}