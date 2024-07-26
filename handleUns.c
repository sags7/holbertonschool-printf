#include "main.h"
#include <stdarg.h>

/**
 * handleUns - handles unsigned ints for _printf()
 * @wd: struc with the pointers to data needed to process _printf
 * Return: 0 if successful, negative number if error.
 */
int handleUns(workingData *wd)
{
	unsigned int orig, mag = 1, i = 0;
	unsigned int n = va_arg(*wd->args, unsigned int);

    orig = n;
	for (i = 0; (n / 10) > 0; i++)
	{
		n /= 10;
		mag *= 10;
	}
	for (; i > 0; i--)
	{
		wd->outputStr[(*wd->outputPosition)++] = '0' + ((orig / mag) % 10);
		mag /= 10;
	}
	wd->outputStr[(*wd->outputPosition)++] = '0' + (orig % 10);
	return (0);
}