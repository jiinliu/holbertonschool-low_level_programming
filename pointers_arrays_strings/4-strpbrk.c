#include "main.h"
#include <stddef.h>
/**
 * _strpbrk - function
 * @s: string
 * @accept: character
 * Return: pointer
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}
	return (NULL);
}
