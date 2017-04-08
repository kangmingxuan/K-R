#include <stdio.h>
#include "htoi.h"
/* htoi convert hexadecimal values into its integer equivalents.
 * This is the solution to K&R C 2-3 */
main()
{
	char ss1[] = "0xa";	/* hexadecimal literal with 0x */
	char ss2[] = "123456";		/* hexadecimal literal without 0x*/
	int iss1 = htoi(ss1);
	int iss2 = htoi(ss2);

	printf("The value of %s is %d in decimal and %x in hexadecimal.\n", 
		ss1, iss1, iss1);
	printf("The value of %s is %d in decimal and %x in hexadecimal.\n", 
		ss2, iss2, iss2);

	return 0;
}