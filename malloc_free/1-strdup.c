#include <stdlib.h>

/**
 * _strdup - function
 * @str: string
 *
 * Return: Pointer or NULL
 */
char *_strdup(char *str)
{
	char *dup;
	int i = 0;

	if (!str)
		return (NULL);

	while (str[i])
		i++;

	dup = malloc(i + 1);
	if (!dup)
		return (NULL);

	for (; i >= 0; i--)
		dup[i] = str[i];

	return (dup);
}
