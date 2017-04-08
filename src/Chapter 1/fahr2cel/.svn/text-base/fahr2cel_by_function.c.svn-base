#include <stdio.h>

#define LOWER 0		/* lower limit of the temp table*/
#define UPPER 300	/* upper limit of the temp table*/
#define STEP 20	/* step size*/

float fahr2cel(float);

/* Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300.
 * This is the solution for K&R 1-15.*/
main()
{
	float fahr;
	
	printf("Fahrenheit-Celsius Table\n");	/* print a head above the table*/
	printf("------------------------\n");		
	printf("%4s\t%6s\n","FAHR","CELS");
	printf("------------------------\n");	
	
	fahr = LOWER;
	while(fahr <= UPPER)
	{
		printf("%4.0f\t%6.1f\n", fahr, fahr2cel(fahr));
		fahr = fahr + STEP;
	}
}

/* fahr2cel converts Fahrenheith into Celsius
 * */
float fahr2cel(float fahr)
{
	float celsius;
	
	celsius = 5.0/9.0*(fahr - 32.0);
	
	return celsius;
}