#include "main.h"

/**
 * _strspn - function
 * @s: string
 * @accept: character
 * Return: count
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i;

	while (*s)
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				count++;
				break;
			}
		}
		if (accept[i] == '\0')
			break;
		s++;
	}
	return (count);
}
