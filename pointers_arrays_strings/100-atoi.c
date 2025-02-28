#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	int found_number = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			found_number = 1;

			/* Prevent overflow: Check against 2147483647 and -2147483648 */
			if (result > 214748364 || (result == 214748364 && (*s - '0') > 7))
			{
				return (sign == 1 ? 2147483647 : -2147483648);
			}

			result = result * 10 + (*s - '0');
		}
		else if (found_number)
			break;

		s++;
	}

	return (sign * result);
}
