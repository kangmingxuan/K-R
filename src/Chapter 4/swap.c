#include <stdio.h>

#define swap(t, x, y) {t temp; temp = x; x = y; y = temp;}

/* This is the solution to the K&R C 4-14 */
main()
{
	int a = 1;
	int b = 2;
	
	printf("Value before exchange: %d, %d\n", a, b);
	swap(int, a, b);
	printf("Value before exchange: %d, %d\n", a, b);
	
	return 0;
}