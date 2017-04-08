#include <stdio.h>

void shellsort(int v[], int n);

/* shellsort sort the int array use shell sort algorithm.
 * This is a copy of the shellsort program in K&R C 3.5 */
main()
{
	int values[] = {5, 3, 7, 8, 6, 9, 1, 2, 0, 4};
	int i, n = 10;

	shellsort(values, n);

	for (i = 0; i < n; ++i)
	{
		printf("%6d%c", values[i], (i == 4 || i == n - 1) ? '\n' : ' ');
	}

	return 0;
}


/* shellsort: sort v[0]~v[n-1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	
	for (gap = n / 2; gap > 0; gap /= 2)	/* adjust the sorting gap */
	{
		for (i = gap; i < n; ++i)
		{
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}