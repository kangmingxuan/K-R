#include <stdio.h>

int bitcount(unsigned x);

/* bitcount here is a faster version than the one in K&R C 2.10
 * This is the solution to the K&R C 2-9 */

main()
{
	int x = 0xffff88aa;

	printf("The 1-bits in %x is %d.\n", x, bitcount(x));

	return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;

	//for (b = 0; x != 0; x >>= 1)
	//	if ((x&(x - 1)) >> 1 == x >> 1)
	//		++b;

	for (b = 0; x != 0; x &= (x - 1))	/* x &= (x - 1) clear the rightmost 1-bit
										 * in x.*/
		++b;

	return b;
		
}