#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>

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
	int *flags;
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
	void (*handler)(workingData *wd);
} format;

void _putchar(char c);
int _printf(const char *format, ...);
void handleChar(workingData *wd);
void handleStr(workingData *wd);
void handleEscPerc(workingData *wd);
void handlePerc(workingData *wd);

#endif
