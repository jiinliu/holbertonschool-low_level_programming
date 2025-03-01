#include "main.h"

/**
 * _strncat - Concatenates two strings up to n bytes from src.
 * @dest: Destination string.
 * @src: Source string.
 * @n: Maximum number of bytes to append.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0, i = 0;

	while (dest[dest_len] != '\0')
		dest_len++;
	while (i < n && src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
