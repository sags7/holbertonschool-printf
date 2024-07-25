#include "main.h"
/**
 * handlePerc - handles formatted inputs with %
 * @wd: the struct with the necessary data to format string
 */
int handlePerc(workingData *wd)
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
		{
			handleEscPerc(wd);
			return (0);
		}
		else if (!(wd->inputStr[*wd->inputPosition + 1]))
			return (0);
	}
	
	while (wd->inputStr[*wd->inputPosition])
	{
		i = 0;
		while (dtypes[i].format)
		{
			if (wd->inputStr[*wd->inputPosition] == dtypes[i].format
				&& dtypes[i].format != '\0')
			{
				dtypes[i].handler(wd);
				return (0);
			}
			i++;
		}
		(*wd->inputPosition)++;
	}
	return (0);
	/*pending logic for when there is no match for %x*/
}
