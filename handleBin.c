#include "main.h"
#include <stdarg.h>

/**
 * handleBin - handles b binary format specifier for _putchar
 * @wd: struct with pointers to data needed to process _putchar
 * Return: 0 if successful, negative value if error
 */

int handleBin(workingData *wd)
{
	int i, j = 0, dec = va_arg(*wd->args, int);
	int bit = ((int)sizeof(int) * 8) - 1;
	char bin[(sizeof(int) * 8) + 1];
	unsigned int mask = 1;

	for (i = 0; i <= bit; i++)
		bin[i] = '0';

	bin[bit + 1] = '\0';

	for (i = 0; i <= bit; i++)
	{
		bin[bit - i] = ((dec & mask) ? '1' : '0');
		mask <<= 1;
	}

	for (i = 0; i <= bit; i++)
		if (bin[i] == '0')
			j++;

	for (; j <= bit; j++)
		wd->outputStr[(*wd->outputPosition)++] = bin[j];

	return (0);
}
