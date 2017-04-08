#include <stdio.h>

#define LOWER -20
#define UPPER 200
#define STEP 20

main()
{
	float celsius;
	
	for(celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
		printf("%3.0f\t%6.1f\n", celsius, 9.0/5.0*celsius + 32.0);
	
}
