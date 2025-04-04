#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on format
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char current_format;
	int print_separator = 0;

	va_start(args, format);
	while (format && format[i])
	{
		current_format = format[i];
		if (print_separator)
			printf(", ");

		switch (current_format)
		{
			case 'c':
				printf("%c", va_arg(args, int));
				print_separator = 1;
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				print_separator = 1;
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				print_separator = 1;
				break;
			case 's':
				str = va_arg(args, char *);
				printf("%s", str ? str : "(nil)");
				print_separator = 1;
				break;
			default:
				print_separator = 0;
				break;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
