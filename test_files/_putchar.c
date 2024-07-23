#include <unistd.h>
/**
 * _putchar - prints a char to stdout
 * @c: the char to output
 */
void _putchar(char c)
{
	write(1, &c, 1);
}
