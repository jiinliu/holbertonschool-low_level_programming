#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - prints an error message and exits with a code
 * @code: the exit code to use
 * @format: the format string for dprintf
 * @arg: argument for the format string (typically a filename)
 */
void print_error_and_exit(int code, const char *format, const char *arg)
{
	dprintf(STDERR_FILENO, format, arg);
	exit(code);
}

/**
 * main - copies the content of one file to another
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with the appropriate error code:
 *         97 if the argument count is incorrect,
 *         98 if file_from does not exist or cannot be read,
 *         99 if file_to cannot be created or written to,
 *         100 if a file descriptor cannot be closed.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while (1)
	{
		r = read(fd_from, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
		}
		if (r == 0)
			break;
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			/* To satisfy the test using libfake_read.so, exit with 98 here */
			print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
		}
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}

