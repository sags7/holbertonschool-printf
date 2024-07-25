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
	va_list arguments;
	workingData dataContainer;

	va_start(arguments, format);
	finishedStr = malloc(1024 * sizeof(char));
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
		case '%':
			if (handlePerc(&dataContainer) < 0)
				return (-1);
			i++;
			break;
		default:
			finishedStr[o++] = format[i++];
			break;
		}
	}
	finishedStr[o] = '\0';
	write(1, finishedStr, o);
	va_end(arguments);
	free(finishedStr);
	return (o);
}
