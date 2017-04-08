#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int c;
	int nc, nw;
	int nb, nt, nl;
	int state;
	
	nc = nw = nb = nt = nl = 0;	/* initialize the counters*/
	state = OUT;
	
	while((c = getchar()) != EOF)
	{
		++nc;
		
		/* count the blanks*/
		if(c == ' ' || c == '\t' || c == '\n')
		{
			state = OUT;
			if(c == ' ')
				++nb;
			else if(c == '\t')
				++nt;
			else if(c == '\n')
				++nl;
		}
		else
		{
			state = IN;
			++nw;
		}
	}
	printf("nc\tnw\tnb\tnt\tnl\n");
	printf("%d\t%d\t%d\t%d\t%d\n", nc, nw, nb, nt, nl);
	
	return 0;
	
}