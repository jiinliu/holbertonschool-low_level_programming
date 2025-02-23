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
			if (h * m < 10)
				_putchar('0' + h * m);
			else
			{
				_putchar('0' + h * m / 10);
				_putchar('0' + h * m % 10);
			}

			if (m !=  9)
			{
				if (h * (m + 1) < 10)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
				}
				else
				{
					_putchar(',');
					_putchar(' ');

				}
			}
		}

		_putchar('\n');
	}
}
