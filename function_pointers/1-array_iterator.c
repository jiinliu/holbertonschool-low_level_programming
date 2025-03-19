#include "function_pointers.h"

/**
 * array_iterator - function
 * @array: integers
 * @size: array
 * @action: A pointer to the function to apply on each element
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array != NULL && action != NULL)
	{
		for (i = 0; i < size; i++)
			action(array[i]);
	}
}
