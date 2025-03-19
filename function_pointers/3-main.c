#include "3-calc.h"
#include <string.h>

/**
 * is_valid_operator - checks if the operator is valid
 * @op: the operator to check
 *
 * Return: 1 if valid, 0 if not
 */
int is_valid_operator(char *op)
{
	if (strlen(op) != 1)
		return (0);
	if (*op != '+' && *op != '-' && *op != '*' && *op != '/' && *op != '%')
		return (0);
	return (1);
}

/**
 * main - performs simple operations
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

	if (!is_valid_operator(argv[2]))
	{
		printf("Error\n");
		exit(99);
	}

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

	return (0);
}

