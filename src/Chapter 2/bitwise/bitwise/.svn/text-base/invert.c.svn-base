/* invert returns x with n bits that begin at p inverted, leaving other
 * bits unchanged.*/

unsigned invert(unsigned x, int p, int n)
{
	return x ^ ~(~0 << n) << (p + 1 -n);
}