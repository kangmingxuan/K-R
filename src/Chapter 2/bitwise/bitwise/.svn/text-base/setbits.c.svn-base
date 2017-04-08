/* setbit returns x with n bits that start at p set to the right most
 * n bits of y, leaving other bits unchanged.*/

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	y = (y & ~(~0 << n)) << (p + 1 - n) ;	/* get the n rightmost bits in y and 
										     * shift it to p */
	x = x & ~(~(~0 << n) << (p + 1 -n));	/* mask off the n bit begins at p */

	return x | y;
}