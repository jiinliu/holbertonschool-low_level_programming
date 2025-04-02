#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * list_len - function
 * @h: Pointer to head
 *
 * Return: Number of elements
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

/**
 * add_node - function
 * @head: Pointer to head
 * @str: String to duplicate
 *
 * Return: Address of new node or NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	if (!str)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	new->len = strlen(new->str);
	new->next = *head;
	*head = new;

	return (new);
}
