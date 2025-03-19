#include "function_pointers.h"

/**
 * int_index - function
 * @array: integers
 * @size: array
 * @cmp: A pointer to the function used to compare values
 *
 * Return: The index of the first element for which cmp doesn't return 0,
 *         or -1 if no match is found or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && size > 0 && cmp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}
	return (-1);
}
