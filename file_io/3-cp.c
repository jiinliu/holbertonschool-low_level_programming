#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * error_handler - handles errors with appropriate messages and exit codes
 * @code: exit code
 * @msg: error message format string
 * @arg: argument for the format string
 * @fd1: first file descriptor to close (-1 if none)
 * @fd2: second file descriptor to close (-1 if none)
 * Return: void
 */
void error_handler(int code, char *msg, char *arg, int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_check - checks if closing a file descriptor returns an error
 * @fd: file descriptor to close
 * @fd2: second file descriptor to close if there's an error (-1 if none)
 * Return: void
 */
void close_check(int fd, int fd2)
{
	int err = close(fd);

	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		if (fd2 != -1)
			close(fd2);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
		error_handler(97, "Usage: cp file_from file_to\n", NULL, -1, -1);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_handler(98, "Error: Can't read from file %s\n", argv[1], -1, -1);

	/* First read test before opening destination */
	nchars = read(file_from, buf, 1024);
	if (nchars == -1)
		error_handler(98, "Error: Can't read from file %s\n", argv[1], file_from, -1);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
		error_handler(99, "Error: Can't write to %s\n", argv[2], file_from, -1);

	/* Write first buffer */
	nwr = write(file_to, buf, nchars);
	if (nwr == -1 || nwr != nchars)
		error_handler(99, "Error: Can't write to %s\n", argv[2], file_from, file_to);

	/* Continue reading and writing */
	while ((nchars = read(file_from, buf, 1024)) > 0)
	{
		nwr = write(file_to, buf, nchars);
		if (nwr == -1 || nwr != nchars)
			error_handler(99, "Error: Can't write to %s\n", argv[2], file_from, file_to);
	}

	/* Check if subsequent read failed */
	if (nchars == -1)
		error_handler(98, "Error: Can't read from file %s\n", argv[1], file_from, file_to);

	close_check(file_from, file_to);
	close_check(file_to, -1);
	return (0);
}
