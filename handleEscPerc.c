/**
 * handleEscPerc - handles escaped %% for _printf
 * @wd: the data structure with the needed data for _printf
 * @flags: optional formatting flags
 */
void handleEscPerc(workingData *wd, char *flags)
{
	wd->outputStr[(*wd->outputPosition)++] = '%';
}
