#include <stdio.h>
#include "bitwise.h"
/* bitwise is a collection of bitwise functions. 
 * This is the solution to K&R C 2-6, 2-7, 2-8.*/
main()
{
	int x = 0x8f223344;
	int y = 0xadfe;

	printf("%x\n", setbits(x, 15, 8, y));
	printf("%x\n", invert(x, 15, 8));
	printf("%x\n", rightrot(x, 8));

	return 0;
}