#include "main.h"

/**
 * print_triangle - Prints a triangle using the '#' character
 * @size: The size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int i, j, spaces;

	if (size <= 0)
	{
		_putchar('\n');
	}

	for (i = 1; i <= size; i++)
	{
		for (spaces = size - i; spaces > 0; spaces--)
			_putchar(' ');
		for (j = 0; j < i; j++)
			_putchar('#');
		_putchar('\n');

	}
}
