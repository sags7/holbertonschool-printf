#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * handleStr - handles strings for _printf
 * @wd: the data structure with the needed data for _printf
 * Return: 0 if successful or -n if not
 */
int handleStr(workingData *wd)
{
	int i = 0;
	char *str = va_arg(*wd->args, char *);

	if (!str)
		str = "(null)";

	while (str[i])
	{
		wd->outputStr[(*wd->outputPosition)++] = str[i++];
	}
	return (0);
}
