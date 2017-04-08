#define NUMBER '0'		/* signal that a number was found */
#define LIBFUN '1'		/* signal that a math libarary function was typed*/
#define VARS '2'		/* signal that a calculator variable was typed */

/* token splitting function*/
int getop(char []);

/* stack functions */
void push(double);
double pop(void);
double top(void);
void duptop(void);
void swtop(void);
void clearstack(void);

/* char get functions */
int getch(void);
void ungetch(int);