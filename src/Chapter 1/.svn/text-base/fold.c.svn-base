#include <stdio.h>

#define MAXLINE 80
#define TABS 8

int getline(char[], int);
int getLastToken(char[], int);
void accBuffer(char[], char[], int, int);	
void flushBuffer(char[], int);

/* fold warp long lines in the input into shorter ones, it can also deal with 
 * very long lines that there. 
 * This is the solution for K&R 1-22.
 */
main()
{
	int i;
	int len, max;
	int token_pos;
	char line[MAXLINE + 1];		/* set the length of the line, 1 for the last '\0' */
	char buffer[MAXLINE + 1];	/* the buffer for display */
	
	for (i = 0; i < MAXLINE + 1; ++i)
		buffer[i] = '\0';
	
	while ((len = getline(line, MAXLINE + 1)) > 0)
	{
		if (len == MAXLINE && line[MAXLINE - 1] != '\n')	/* check if longer than the limit */
		{
			max = MAXLINE;
			while(len == max && line[max - 1] != '\n')
			{
				token_pos = getLastToken(line, len);	/* find the pos where we can split the row */
				
				if (token_pos == 0)		/* tackle the only one word situation */
				{
					accBuffer(line, buffer, 0, len - 3);	/* reserve space for '-'&'\n' */
					flushBuffer(buffer, MAXLINE + 1);
					putchar('-');
					putchar('\n');
					
					accBuffer(line, buffer, len - 2, len - 1);
					max = MAXLINE - 2;
				}
				else if(token_pos < len)
				{
				
					accBuffer(line, buffer, 0, token_pos - 1);
					flushBuffer(buffer, MAXLINE + 1);
					putchar('\n');
					
					accBuffer(line, buffer, token_pos, len - 1);
					max = MAXLINE - (len - token_pos);
				}
				else if (token_pos = len)
				{
					accBuffer(line, buffer, 0, len - 2);
					flushBuffer(buffer, MAXLINE + 1);
					putchar('\n');
					
					accBuffer(line, buffer, len - 1, len - 1);
					max = MAXLINE - 1;
				}
				
				len = getline(line, max + 1);
			}
			
			accBuffer(line, buffer, 0, len - 1);
			flushBuffer(buffer, MAXLINE + 1);
			if (line[len - 1] != '\n')	/*fix the problem of no newline at the last of the file.*/
				putchar('\n');
		}
		else
			printf("%s", line);
	}
	
	return 0;
}

/* getline:  read a line into s, return length.
 * NOTE: it's lim-1 not lim the exact largest number of characters you can get 
 * per time. lim accounts for the last '\0' */
int getline(char s[], int lim)
{
	int c;
	int i, j;
	int tabs;
	
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		if (c == '\t')		/* extend the tab into spaces */
		{
			tabs = TABS - i%TABS;
			for(j = 0; j < tabs; ++j)	
				s[i++] = ' ';
			--i;
		}
		else
			s[i] = c;
	
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	return i;
}

/* getLastToken find the last token before the column limit MAXLINE 
 * line[]: the line to process with
 * length: the length of the character array, without the '\0'
 * return value: the initial index in line[] of the last token.
 * ATTENTION: this function may return value that equals to len, if
 * the last character is blank(i.e. spaces or tab).
 */
int getLastToken(char line[], int len) 
{
	 int i, last;
	
	i = len - 1;
	 while (i >= 0 && line[i] != ' ')
		--i;
	
	return i + 1;
}


/* accBuffer set the display buffer push the chars into the display 
 * buffer. Maybe would better done with a stack, but not now */
void accBuffer(char line[], char buffer[], int start, int end)
{
	int i, j;
	
	j = 0;
	while(buffer[j] != '\0')
		++j;
	
	for(i = start; i <= end; ++i, ++j)
	{
		buffer[j] = line[i];
	}
}

/* flushBuffer prints the contents int the buffer and reset the buffer into 
 * null strings. */

void flushBuffer(char buffer[], int bufferLen)
{
	int i;
	
	i = 0;
	while(buffer[i] != '\0')
	{
		putchar(buffer[i]);
		++i;
	}
	
	/* reset the buffer into null */
	
	for(i = 0; i < bufferLen; ++i)
	{
		buffer[i] = '\0';
	}
}
