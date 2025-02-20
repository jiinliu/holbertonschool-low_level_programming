#include "main.h"

/**
 * print_alphabet_x10 - Entry point
 *
 *
 * Return: Always 0 (Success)
 */
void print_alphabet_x10(void)
{
	int digit = 1;

	while (digit <= 10)
	{
		print_alphabet();
		digit++;
	}

	_putchar('\n');
}
