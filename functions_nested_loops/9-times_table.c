#include "main.h"

/**
 * times_table - function
 *
 *
 *
 * Return: void
 */
void times_table(void)
{
	int h;
	int m;

	for (h = 0; h < 10; h++)
	{
		for (m = 0; m < 10; m++)
		{
			_putchar(h * m + '0');
			_putchar(',');
			_putchar('  ');
		}

		_putchar('\n');
	}
}
