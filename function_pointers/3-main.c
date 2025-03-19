#include "3-calc.h"

/**
 * main - function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	operation = get_op_func(argv[2]);
	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", operation(num1, num2));

	if (strlen(argv[2]) != 1 ||
			(*argv[2] != '+' && *argv[2] != '-' && *argv[2] != '*' &&
			 *argv[2] != '/' && *argv[2] != '%'))
	{
		printf("Error\n");
		exit(99);
	}

	return (0);
}
