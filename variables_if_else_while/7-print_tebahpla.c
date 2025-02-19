#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints the alphabet in lowercase followed by a new line.
 *              Only the putchar function is used (twice).
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'z';

	while (letter >= 'a')
	{
		putchar(letter);
		letter--;
	}

	putchar('\n');

	return (0);
}
