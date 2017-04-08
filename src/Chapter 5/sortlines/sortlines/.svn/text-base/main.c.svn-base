#include <stdio.h>

#define MAXLINES 500		/* max lines to be sorted */
#define MAXLEN 500000		/* the max length of all the lines to be sorted */

int readlines(char *lineptr[],  int maxlines, char lines[], int maxlen);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main()
{
	int nlines;
	char *lineptr[MAXLINES];	/* pointers to text lines */
	char lines[MAXLEN];			/* lines to be sorted */

	if ((nlines = readlines(lineptr, MAXLINES, lines, MAXLEN)) >= 0)
	{
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
	}

	return 0;
}


#include <string.h>
#define LINELIM 1000 /* max length of every input line */
int getline(char s[], int lim);

/* readlines: read input lines into lines */
int readlines(char *lineptr[],int maxlines, char lines[], int maxlen)
{
	int i, len, nlines;
	char *p = lines, curline[LINELIM];

	nlines = 0;
	while ((len = getline(curline, LINELIM)) > 0)
	{
		if (nlines >= maxlines || p + len > lines + maxlen)
			return -1;
		else{
			curline[len - 1] = '\0';
			i = 0;
			while (i < len){
				*p++ = curline[i];
				i++;
			}
			lineptr[nlines++] = p - len;
		}
	}

	return nlines;
}	
/* getline: get a line into s, return the num of the chars, 0 means no char*/
int getline(char s[], int lim)
{
	int i, c;

	i = 0;
	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = '\n' ;
	s[i] = '\0';

	return i;
}

void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]~v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);	/* put the pivot first */
	last = left;
	for (i = left + 1; i <= right; i++){
		if (strcmp(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}

	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}
/* swap: swap two elements in s */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

