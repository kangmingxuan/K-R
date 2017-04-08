#include <stdio.h>
/* binsearch: find x in v[0]~v[n-1], 
 * version 2 uses only one test inside the loop
 * This is the solution to the K&R C 3-1. */
main()
{
	int v[] = {0, 1, 2, 4, 6, 11, 23, 24, 34};
	int x = 0;
	
	printf("The location of x: %d in v[] is %d.\n", x, binsearch(x, v, 9));
	
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	
	while (low < high){
		mid = (low + high) / 2;
		if (x <= v[mid])
			high = mid;		/* unlike the original edition, we set high to mid here*/
		else
			low = mid + 1;
	}
	/* when the loop above terminates, low equals to high, 
	 * whether we find x or not depends on if v[low] equals to x */
	if (v[low] == x)
		return low;
	else
		return -1;
}