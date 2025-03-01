#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string (must have enough space).
 * @src: Source string to be appended.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}
