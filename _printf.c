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
	workingData dataContainer;

	va_start(arguments, format);
	finishedStr = malloc(2024 * sizeof(char));
	if (!finishedStr)
		return (-1);
	dataContainer.inputStr = format;
	dataContainer.inputPosition = &i;
	dataContainer.outputStr = finishedStr;
	dataContainer.outputPosition = &o;
	dataContainer.args = &arguments;

	while (format[i])
	{
		switch (format[i])
		{
		case '\\':	/* unimplemented */
			i++;
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
	finishedStr[o] = '\0';
	i = 0;
	while (finishedStr[i])
		_putchar(finishedStr[i++]);
	if (finishedStr[0] == '\0')
		i = 2;
	retval = i;
	va_end(arguments);
	free(finishedStr);
	return (retval);
}
