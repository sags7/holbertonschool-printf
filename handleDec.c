#include "main.h"
void re_helper(int n, workingData *wd)
{
    if (n / 10 > 0)
        re_helper(n / 10, wd);
    
    wd->outputStr[(*wd->outputPosition)++] = n + '0';
}
/**
 * handleDec - handles decimal values for _printf()
 * @wd: the struct containing the needed data
 */
void handleDec(workingData *wd)
{
	unsigned int n, orig, mag = 1, i = 0; 
    int m = va_arg(*wd->args, int);

	if (m < 0)
	{
		orig = n = (unsigned int) -m;
		wd->outputStr[(*wd->outputPosition)++] = '-';
	}
	else
		orig = n = (unsigned int) m;

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
}
