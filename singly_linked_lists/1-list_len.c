#include "lists.h"
#include <stddef.h>

/**
 * list_len - function
 * @h: Pointer to the head of the list.
 *
 * Return: Number of elements in the list.
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
