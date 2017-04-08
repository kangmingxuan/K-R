#include <stdio.h>

/* copy the input to its out & replace the invisible character '\b', '\t' with
 * \b, \t, and by the way show the '\\' with \\ for unambiguous consideration.
 * this is the solution for the K&R exercise 1-10.
 */
int main()
{
	int c;

	while((c = getchar()) != EOF)
	{	
		if(c == '\b')
			printf("\\b");
		else if(c == '\t')
			printf("\\t");
		else if(c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
	
	return 0;
}