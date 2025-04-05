#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * error_exit - handles error messages and exit codes
 * @code: exit code
 * @message: error message to print
 * @filename: name of the file for the error message
 * @fd: file descriptor to close (if applicable)
 * Return: void
 */
void error_exit(int code, char *message, char *filename, int fd)
{
	if (fd >= 0)
		close(fd);
	
	dprintf(STDERR_FILENO, message, filename);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	/* Check for correct number of arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open source file for reading */
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1], -1);

	/* Open destination file with proper flags and permissions */
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2], file_from);

	/* Read from source and write to destination */
	while ((nchars = read(file_from, buf, 1024)) > 0)
	{
		nwr = write(file_to, buf, nchars);
		if (nwr == -1 || nwr != nchars)
			error_exit(99, "Error: Can't write to %s\n", argv[2],
				   file_from);
	}

	/* Check if read failed */
	if (nchars == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1],
			   file_from);

	/* Close files and check for errors */
	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		close(file_to);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}
