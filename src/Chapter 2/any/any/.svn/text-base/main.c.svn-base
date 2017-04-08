#include <stdio.h>
#include "any.h"
/* any returns the first occurrence of s2 in s1. When s1 contains no s2, 
 * any returns -1. 
 * This is the solution to K&R C 2-5.*/
main()
{
	char s1[] = "I am what I am.";
	char s2[] = "what I am. is not your business";
	char s3[] = "where";
	char s4[] = "what";
	char s5[] = "";

	printf("The location of \"%s\" in \"%s\" is %d.\n", s2, s1, any(s1, s2));
	printf("The location of \"%s\" in \"%s\" is %d.\n", s3, s1, any(s1, s3));
	printf("The location of \"%s\" in \"%s\" is %d.\n", s4, s1, any(s1, s4));
	printf("The location of \"%s\" in \"%s\" is %d.\n", s5, s1, any(s1, s5));

	return 0;
}