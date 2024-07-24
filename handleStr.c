#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * handleStr - handles strings for _printf
 * @wd: the data structure with the needed data for _printf
 */
void handleStr(workingData *wd)
{
	int i = 0;
	char *str = va_arg(*wd->args, char *);

	if (!str)
		str = "(null)";

	while (str[i])
	{
		wd->outputStr[(*wd->outputPosition)++] = str[i++];
	}
}
