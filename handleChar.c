#include "main.h"
/**
 * handleChar - handles Chars for _printf
 * @wd: the struct containing the data needed for _printf
 * Return: 0 if successful or -n if not
 */
int handleChar(workingData *wd)
{
	wd->outputStr[(*wd->outputPosition)++] = va_arg(*wd->args, int);
	return (0);
}
