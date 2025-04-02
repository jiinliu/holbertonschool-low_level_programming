#include <stdlib.h>

/**
 * my_strlen - Custom function to calculate string length
 * @str: String to calculate the length of
 *
 * Return: Length of the string
 */
size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * list_len - Counts elements in a linked list
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
 * add_node - Adds a new node at the beginning
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

	new->len = my_strlen(new->str);
	new->next = *head;
	*head = new;

	return (new);
}
