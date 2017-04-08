/* itoa: convert interger into its corresponding string. 
 * NOTE: this version is a recursive implementation 
 * ****************************************************
 * INPUT
 * n: the number to be converted
 * s: the string which hold the converted number
 * ind: the initial position of the convert in the string s
 * ****************************************************
 * OUTPUT
 * the end position of the convert process
 * ****************************************************/

int itoa(int n, char s[], int ind)
{
	if (n < 0)				/* handle the negative sign */
	{
		s[ind++] = '-';
		n = -n;
	}

	if (n / 10)				/* handle the part which larger than 10*/
	{
		ind = itoa(n / 10, s, ind);
	}

	s[ind] = n % 10 + '0';	/* print the last digit */
	
	s[++ind] = '\0';		

	return ind;
}