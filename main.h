#ifndef MAIN_H
#define MAIN_H

void _putchar(char c);

int _printf(const char *format, ...);
void handleChar(workingData *wd, char *flags);
void handleStr(workingData *wd, char *flags);
void handleEscPerc(workingData *wd, char *flags);
void handlePerc(workingData *wd);

/**
 * struct workData - a struct that contains the needed data to work
 * on the _printf function
 * @inputStr: the original format string given to _printf
 * @inputPosition: the element of th e format string currently being worked on
 * @outputStr: the processed string at any given time
 * @outputPosition: the position in the output string
 * @args: the va_list pointer
 *
 * Description: a struct that contains the needed data to work on _printf
 */
typedef struct workData
{
	const char *inputStr;
	int *inputPosition;
	char *outputStr;
	int *outputPosition;
	va_list *args;
} workingData;

/**
 * struct form - a struct that contains the a char representing a datatype
 * and a pointer to the handler
 * @format: the char representing the datatype
 * @handler: the function to print it
 *
 * Description: a struct that contains the a char representing a datatype
 * and a pointer to a function that prints it.
 */
typedef struct form
{
	char format;
	void (*handler)(workingData *wd, char *flags);
} format;

#endif
