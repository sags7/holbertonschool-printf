#include "main.h"
/**
 * handleEscPerc - handles escaped %% for _printf
 * @wd: the data structure with the needed data for _printf
 */
void handleEscPerc(workingData *wd)
{
	wd->outputStr[(*wd->outputPosition)++] = '%';
	(*wd->inputPosition) += 1;
}
