#include "main.h"

/**
 * puts2 -  prints every other character of a string - function
 * @str: The input string
 *
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)
			_putchar(str[i]);
	}
	_putchar('\n');
}
