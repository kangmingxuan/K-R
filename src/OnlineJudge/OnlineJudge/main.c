#include <stdio.h>

int josephus(int n, int m);

/* solution to the BNU OJ 1007 */
int main()
{
	int n, m;

	scanf("%d", &n);
	while (n != 0){
		m = 1;
		while ((josephus(n-1, m) + 2) != 2)
			m++;
		printf("%d\n", m);
		scanf("%d", &n);
	}
	return 0;
}

/* josephus: return the last counted number in a Josuphus Ring */
int josephus(int n, int m)
{
	if (n == 2){
		if (m % 2 == 1)	/* if m is odd */
			return 1;
		else
			return 0;
	}
	else if (n > 2){
		int k = (m - 1) % n;
		return ((josephus(n - 1, m) + k + 1) % n);
	}
}

