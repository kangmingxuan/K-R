#include <stdio.h>
#include <limits.h>
#include <float.h>


/* tplimits prints the ranges of the c basic types char, short, int, and
 * long variables both signed and unsigned.
 * This is the solution to the K&R C 2-1.*/

main()
{
	printf("Integer value ranges:\n");
	printf("The range of char is %d to %d.\n", CHAR_MIN, CHAR_MAX);
	printf("The range of unsigned char is %d to %d.\n", 0, UCHAR_MAX);
	printf("The range of signed char is %d to %d.\n", SCHAR_MIN, SCHAR_MAX);

	printf("The range of unsigned short is %d to %d.\n", 0, USHRT_MAX);
	printf("The range of short is %d to %d.\n", SHRT_MIN, SHRT_MAX);

	printf("The range of unsigned int is %u to %u.\n", 0, UINT_MAX);
	printf("The range of int is %d to %d.\n", INT_MIN, INT_MAX);

	printf("The range of unsigned long is %u to %u.\n", 0, ULONG_MAX);
	printf("The range of long is %ld to %ld.\n", LONG_MIN, LONG_MAX);

	printf("\nFloat value ranges:\n");
	printf("The range of double is %e to %e, \nwith the precision %e.\n", DBL_MIN, DBL_MAX, DBL_EPSILON);
	printf("The range of float is %e to %e, \nwith the precision %e.\n", FLT_MIN, FLT_MAX, FLT_EPSILON);
	printf("The range of long double is %e to %e, \nwith the precision %e.\n", LDBL_MIN, LDBL_MAX, LDBL_EPSILON);

	system("pause");
	return 0;
}