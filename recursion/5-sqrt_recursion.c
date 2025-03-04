#include "main.h"

/**
 * _sqrt_helper - Helper function
 * @n: n
 * @guess: guess
 *
 * Return: something
 */
int _sqrt_helper(int n, int guess)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - function
 * @n: number
 *
 * Return: something
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 1));
}
