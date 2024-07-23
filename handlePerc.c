/**
 * handlePerc - handles formatted inputs with %
 * @wd: the struct with the necessary data to format string
 */
void handlePerc(workingData *wd)
{
	format dtypes[] = {
		{'c', handleChar},
		{'s', handleStr},
		{'\0', NULL}};
	int i = 0;

	while (wd->inputStr[*wd->inputPosition])
	{
		i = 0;
		while (dtypes[i].format)
		{
			if (wd->inputStr[*wd->inputPosition] == dtypes[i].format
				&& dtypes[i].format != '\0')
			{
				dtypes[i].handler(wd, NULL);
				return;
			}
			i++;
		}
		(*wd->inputPosition)++;
	}
	if (wd->inputStr[*wd->inputPosition] == '%')
		handleEscPerc(wd, NULL);
	/*pending logic for when there is no match for %x*/
}
