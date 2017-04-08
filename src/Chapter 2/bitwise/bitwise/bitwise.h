/* setbit returns x with n bits that start at p set to the right most
 * n bits of y, leaving other bits unchanged.*/
unsigned setbits(unsigned x, int p, int n, unsigned y);
/* invert returns x with n bits that begin at p inverted, leaving other
 * bits unchanged.*/
unsigned invert(unsigned x, int p, int n);
/* rightrot return the value of integer x rotated to the right by n positions */
unsigned rightrot(unsigned x, int n);
