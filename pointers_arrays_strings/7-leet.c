#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: the string to encode
 *
 * Return: the encoded string
 */
char *leet(char *str)
{
	char map[] = "aAeEoOtTlL";
	char repl[] = "4433007711";
	int i = 0, j;

	while (str[i] != '\0')
	{
		for (j = 0; map[j] != '\0'; j++)
		{
			if (str[i] == map[j])
				str[i] = repl[j];
		}
		i++;
	}

	return (str);
}
