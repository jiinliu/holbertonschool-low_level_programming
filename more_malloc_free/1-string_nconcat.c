#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - function
 * @s1: First string
 * @s2: Second string
 * @n: int
 *
 * Return: tring or NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	if (n > len2)
		n = len2;

	concat = malloc(len1 + n + 1);
	if (!concat)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];

	concat[i + j] = '\0';
	return (concat);
}
