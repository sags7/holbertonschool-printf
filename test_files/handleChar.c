#include "main.h"
/**
 * handleChar - handles Chars for _printf
 * @wd: the struct containing the data needed for _printf
 * @flags: optional formatting flags
 */
void handleChar(workingData *wd)
{
	wd->outputStr[(*wd->outputPosition)++] = va_arg(*wd->args, int);
}
