#include <stdio.h>
#include <stdlib.h>

/**
 * main - function
 * @argc: count
 * @argv: array
 *
 * Return: 0 if success, 1 if error
 */
int main(int argc, char **argv)
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (*argv[i] < '0' || *argv[i] > '9')
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
