#include "main.h"
/**
 * handleStr - handles strings for _printf
 * @wd: the data structure with the needed data for _printf
 * @flags: optional formatting flags
 */
void handleStr(workingData *wd)
{
	int i = 0;
	char *str = va_arg(*wd->args, char *);

	while (*(str + i))
		wd->outputStr[(*wd->outputPosition)++] = str[i++];
}
