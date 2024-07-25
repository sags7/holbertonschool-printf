#include "main.h"

/**
 * handleNoMatch - handles when no format specifier is found after a %
 * @wd: the struc containg the data relevant to processing _putchar()
 * Return: 0 if successful, negative number if error
 */
int handleNoMatch(workingData *wd)
{
    wd->outputStr[(*wd->outputPosition)++] = '%';
    (*wd->inputPosition)--;
    return (0);
}