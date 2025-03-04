#include "main.h"

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root of n, or -1 if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	static int guess = 1;

	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	guess++;
	return (_sqrt_recursion(n));
}
