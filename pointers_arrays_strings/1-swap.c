#include "main.h"
/**
 * swap_int - function
 * @a: Pointer to the values of two integers
 * @b: Pointer to the second integer
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;

	*a = *b;

	*b = temp;

}
