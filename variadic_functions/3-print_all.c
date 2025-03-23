#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char c;
	int n;
	float f;

	va_start(args, format);
	while (format && format[i])
	{
		if (i > 0 && (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
			printf(", ");
		
		if (format[i] == 'c')
		{
			c = va_arg(args, int);
			printf("%c", c);
		}
		else if (format[i] == 'i')
		{
			n = va_arg(args, int);
			printf("%d", n);
		}
		else if (format[i] == 'f')
		{
			f = va_arg(args, double);
			printf("%f", f);
		}
		else if (format[i] == 's')
		{
			str = va_arg(args, char*);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
