#include "main.h"

/**
 * _isdigit  - function
 * @c: digit
 *
 *
 * Return: 1 if c is a digit 0 otherwise
 */
int _isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}
