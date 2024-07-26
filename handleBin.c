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
	int i, j = 0, dec = va_arg(*wd->args, int);
	long int bit = (sizeof(long int) * 8) - 1;
	char bin[(sizeof(long int) * 8)];
	unsigned int mask = 1;

	for (i = 0; i <= bit; i++)
		bin[i] = '0';

	for (i = 0; i <= bit; i++)
	{
		bin[bit - i] = ((dec & mask) ? '1' : '0');
		mask <<= 1;
	}

    j = 0;
    i = 0;
    while(bin[i])
    {
        if (bin[i++] == '0')
            j++;
        else
            for (; j <= bit; j++)
		        wd->outputStr[(*wd->outputPosition)++] = bin[j];
    }

    j = 0;
    i = 0;
    while(bin[i])
    {
        if (bin[i++] == '0')
            j++;
        else
            for (; j <= bit; j++)
		        wd->outputStr[(*wd->outputPosition)++] = bin[j];
    }
	return (0);
}
