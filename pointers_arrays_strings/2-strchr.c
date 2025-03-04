#include "main.h"
#include <stddef.h>

/**
 * _strchr - function
 * @s: string
 * @c: character
 *
 * Return: s or NULL
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
