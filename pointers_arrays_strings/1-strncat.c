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
	int i, dest_len;

	dest_len = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
