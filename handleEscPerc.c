#include "main.h"
/**
 * handleEscPerc - handles escaped %% for _printf
 * @wd: the data structure with the needed data for _printf
 * Return: 0 if successful or -n if not
 */
int handleEscPerc(workingData *wd)
{
	wd->outputStr[(*wd->outputPosition)++] = '%';
	(*wd->inputPosition)++;
	return (0);
}
