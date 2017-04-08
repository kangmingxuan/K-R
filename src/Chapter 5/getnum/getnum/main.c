#include <stdio.h>
#include "getnum.h"

#define SIZE 100

/************************************************************************/
/* This is the solution to the K&R C 5-1 and 5-2.                       */
/************************************************************************/
main()
{
	int n, array[SIZE], i, type, tmp;
	float farray[SIZE], ftmp;

	/* test routines for getint and getfloat 
	 * ATTENTION: only one routine allowed per test */
	//for (n = 0; n < SIZE && (type = getint(&tmp)) != EOF; )
	//	if (type > 0)
	//		array[n++] = tmp;
	//	else if (type == 0)
	//		getch();
	//
	//for (i = 0; i < n; i++)
	//	printf("%d%c", array[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');

	for (n = 0; n < SIZE && (type = getfloat(&ftmp)) != EOF; )
		if (type > 0)
			farray[n++] = ftmp;
		else if (type == 0)
			getch();

	for (i = 0; i < n; i++)
		printf("%g%c", farray[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');

	return 0;
}