#include <stdio.h>

/*print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		/* lower limit of the temp table*/
	upper = 300;	/* upper limit of the temp table*/
	step = 20;		/* step size*/
	
	printf("Fahrenheit-Celsius Table\n");	/* print a head above the table*/
	printf("------------------------\n");		
	printf("FAHR\tCELS\n");
	printf("------------------------\n");	
	
	fahr = lower;
	while(fahr <= upper)
	{
		celsius = 5.0/9.0*(fahr - 32);
		printf("%3.0f\t%6.2f\n", fahr, celsius);
		fahr = fahr + step;
	}
}