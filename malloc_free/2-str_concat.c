#include <stdlib.h>

/**
 * str_concat - function
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Pointer or NULL
 */
char *str_concat(char *s1, char *s2)
{
	int len1 = 0, len2 = 0, i;
	char *concat;

	s1 = s1 ? s1 : "";
	s2 = s2 ? s2 : "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	concat = malloc(len1 + len2 + 1);
	if (!concat)
		return (NULL);

	for (i = 0; i < len1 + len2; i++)
		concat[i] = (i < len1) ? s1[i] : s2[i - len1];

	concat[i] = '\0';
	return (concat);
}
