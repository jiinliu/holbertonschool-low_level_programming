#include "main.h"
#include <stddef.h>

/**
 * _strstr - function
 * @haystack: string
 * @needle: substring
 * Return: pointer
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	if (*needle == '\0')
		return (haystack);

	while (*haystack)
	{
		h = haystack;
		n = needle;

		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return (haystack);

		haystack++;
	}
	return (NULL);
}
