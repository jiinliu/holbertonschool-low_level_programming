#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints all possible combinations of single-digit numbers,
 *              separated by a comma and a space, in ascending order.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int digit = 0;

	while (digit <= 9)
	{
		putchar(digit + '0');	/* Print the current digit */
		if (digit != 9)	/* Don't print comma and space after the last digit */
		{
			putchar(',');	/* Print the comma */
			putchar(' ');	/* Print the space */
		}
		digit++;
	}

	putchar('\n');	/* Print a newline at the end */

	return (0);
}

