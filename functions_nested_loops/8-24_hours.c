#include "main.h"

/**
 * jack_bauer - function
 *
 *
 *
 * Return: void
 */
void jack_bauer(void)
{
	for (int h = 0; h < 24; h++)
		for (int m = 0; m < 60; m++)
		{
			_putchar('0' + h / 10);
			_putchar('0' + h % 10);
			_putchar(':');
			-putchar('0' + m / 10);
			_putchar('0' + m % 10);
			-putchar('\n');
		}

}
