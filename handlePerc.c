#include "main.h"
/* int (*)(workingData *wd) */
int (*getHandler(workingData *wd))(workingData *wd)
{
	format dtypes[] = {
		{'s', handleStr},
		{'c', handleChar},
		{'d', handleDec},
		{'i', handleDec},
		{'\0', NULL}};
	int i = 0;

	
	if (wd->inputStr[*wd->inputPosition] == '%') 
	{
		if (wd->inputStr[*wd->inputPosition + 1] == '%')
			return(&handleEscPerc);
		else if (!(wd->inputStr[*wd->inputPosition + 1]))
			return (NULL);
	}
	
	while (wd->inputStr[*wd->inputPosition])
	{
		i = 0;
		while (dtypes[i].format)
		{
			if (wd->inputStr[*wd->inputPosition] == dtypes[i].format
				&& dtypes[i].format != '\0')
			{
				return(dtypes[i].handler);
			}
			i++;
		}
		(*wd->inputPosition)++;
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
	
	if (handler(wd) < 0 )
		return(-1);
		
	return (0);
	/*pending logic for when there is no match for %x*/
}
