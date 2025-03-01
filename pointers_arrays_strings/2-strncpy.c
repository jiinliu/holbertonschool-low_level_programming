#include "main.h"

/**
 * _strncpy - Copies a string up to n characters.
 * @dest: Destination buffer.
 * @src: Source string to copy from.
 * @n: Number of characters to copy.
 *
 * Return: Pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
