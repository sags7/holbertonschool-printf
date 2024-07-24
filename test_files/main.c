#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;
	len1 = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("MyLen: %d\nTheirs: %d\n", len1, len2);
	_printf("%s", "This sentence is retrieved from va_args!\n");
	printf("%s", "This sentence is retrieved from va_args!\n");
	printf("MyLen: %d\n", _printf("%%\n"));
	printf("Theirs: %d\n", printf("%%\n"));
	return (0);
}
