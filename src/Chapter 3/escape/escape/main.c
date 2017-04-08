#include <stdio.h>
#include "escape.h"

#define MAXLEN 1000

/* escape: copy t[] to s[] and converts characters 
 * with a escape sequence  representation like
 * newline, tab etc into visible ones. 
 * rescape do exactly the same thing in different 
 * direction.
 * This is the solution to the K&R C 3-2. */

main()
{
	char t[] = "I		am the	test sentence.\n";
	char s[MAXLEN];
	
	printf("%s", t);

	escape(s, t);
	printf("%s", s);

	putchar('\n');

	rescape(t, s);
	printf("%s", t);

	return 0;
}