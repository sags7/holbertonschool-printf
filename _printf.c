#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - emulates printf frm stdio.h
 * @format: the string containing the format and content to print
 * Return: printed string length
 */
int _printf(const char *format, ...)
{
	int i = 0, o = 0;
	char *finishedStr = NULL;
	int retval = 0;
	va_list arguments;
	workingData dataContainer = {format, &i,  NULL, &o, &arguments};

	va_start(arguments, format);
	finishedStr = malloc(1024);
	if (!finishedStr)
		return (-1);
	dataContainer.outputStr = finishedStr;

	while (format[i])
	{
		switch (format[i])
		{
		case '\\':
			/* unimplemented i++*/
			break;
		case '%':
			handlePerc(&dataContainer);
			i++;
			break;
		default:
			finishedStr[o++] = format[i++];
			break;
		}
	}
	finishedStr[i] = '\0';
	i = 0;
	while (finishedStr[i])
		_putchar(finishedStr[i++]);
	_putchar('\n');
	retval = i;
	va_end(arguments);
	free(finishedStr);
	return (retval);
}
