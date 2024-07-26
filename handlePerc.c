#include "main.h"
/**
 * getHandler - helper func that gets the correct handler function
 * @wd: the struct with the neccesary data * to process _printf()
 * Return: a pointer to the correct handler function
 */
int (*getHandler(workingData * wd))(workingData * wd)
{
	format dtypes[] = {
		{'s', handleStr},
		{'c', handleChar},
		{'d', handleDec},
		{'i', handleDec},
		{'b', handleBin},
		{'\0', NULL}};
	int i = 0;

	if (wd->inputStr[*wd->inputPosition] == '%')
	{
		if (wd->inputStr[*wd->inputPosition + 1] == '%')
			return (&handleEscPerc);
		else if (!(wd->inputStr[*wd->inputPosition + 1]))
			return (NULL);
	}
	++(*wd->inputPosition);
	while (dtypes[i].format)
	{
		if (wd->inputStr[*wd->inputPosition] == dtypes[i].format
			&& dtypes[i].format != '\0')
			return (dtypes[i].handler);
		i++;
	}
	return (NULL);
}

/**
 * handlePerc - handles formatted inputs with %
 * @wd: the struct with the necessary data to format string
 * Return: 0 if successful or -n if not
 */
int handlePerc(workingData *wd)
{
	int (*handler)(workingData *wd) = getHandler(wd);

	if (handler && handler(wd) < 0)
		return (-1);
	if (!handler)
		handleNoMatch(wd);
	return (0);
}
