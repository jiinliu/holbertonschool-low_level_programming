#include "main.h"

/**
 * print_most_numbers - function
 *
 *
 *
 * Return: void
 */
void print_most_numbers(void)
{
	int num;

	for (num = '0'; num <= '9'; num++)
		if (num != '4' &&  num != '2')
			_putchar(num);

	_putchar('\n');
}
