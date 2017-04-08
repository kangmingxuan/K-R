/* rightrot return the value of integer x rotated to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
	int i;
	for (i = 0; (~(~0 << n) << i & ~(~0u >> n)) >> i != ~(~0 << n); ++i)
		;

	return (x & ~(~0 << n)) << i | x >> n;
}