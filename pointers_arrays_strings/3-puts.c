#include "main.h"
/**
 * _puts - function
 * @str: prints a string
 *
 * return: void
 */
void _puts(char *str)
{

	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
