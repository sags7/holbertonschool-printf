
#include "main.h"
#include <stdarg.h>

/**
 * handleOct - handles b binary format specifier for _putchar
 * @wd: struct with pointers to data needed to process _putchar
 * Return: 0 if successful, negative value if error
 */

int handleOct(workingData *wd)
{
	long int i = 0, num = va_arg(*wd->args, long int);
	int octalNum[64];

	if (num < 0)
	{
		wd->outputStr[(*wd->outputPosition)++] = '-';
		num = -num;
	}

	do {
		octalNum[i++] = num % 8;
		num /= 8;
	} while (num != 0);

	while (--i >= 0)
		wd->outputStr[(*wd->outputPosition)++] = octalNum[i] + '0';
	return (0);
}
