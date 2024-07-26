#include "main.h"
#include <stdarg.h>

#include <stdio.h>

/**
 * handleBin - handles b binary format specifier for _putchar
 * @wd: struct with pointers to data needed to process _putchar
 * Return: 0 if successful, negative value if error
 */

int handleBin(workingData *wd)
{
	unsigned int i;
    unsigned int dec = va_arg(*wd->args, unsigned int);
	unsigned int bit = (sizeof(unsigned int) * 8) - 1;
	char bin[(sizeof(unsigned int) * 8)];
	unsigned int mask = 1;

	for (i = 0; i <= bit; i++)
		bin[i] = '0';

	for (i = 0; i <= bit; i++)
	{
		bin[bit - i] = ((dec & mask) ? '1' : '0');
		mask <<= 1;
	}

	bin[(sizeof(unsigned int) * 8)] = '\0';

	i = 0;
	while (i <= bit && bin[i] == '0')
		i++;
	if (i > bit)
		wd->outputStr[(*wd->outputPosition)++] = '0';
	else
		while (i <= bit)
			wd->outputStr[(*wd->outputPosition)++] = bin[i++];
	return (0);
}
