#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints all the numbers of base 16 in lowercase.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int digit = 0;

	while (digit <= 15)
	{
		if (digit < 10)
			putchar(digit + '0');
		else
			putchar(digit - 10 + 'a');

		digit++;
	}

	putchar('\n');

	return (0);
}
