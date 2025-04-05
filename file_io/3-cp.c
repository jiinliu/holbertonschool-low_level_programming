#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * error_file - checks if files can be opened and handles errors
 * @file_from: file descriptor for source file
 * @file_to: file descriptor for destination file
 * @argv: arguments vector
 * Return: void
 */
void error_file(int file_from, int file_to, char *argv[])
{
    if (file_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    if (file_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
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
    
    /* Open destination file for writing, create if it doesn't exist, truncate if it does */
    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    
    /* Check if files were opened successfully */
    error_file(file_from, file_to, argv);

    /* Read from source and write to destination */
    nchars = 1024;
    while (nchars == 1024)
    {
        /* Read up to 1024 bytes from source file */
        nchars = read(file_from, buf, 1024);
        if (nchars == -1)
            error_file(-1, 0, argv);
            
        /* Write read bytes to destination file */
        nwr = write(file_to, buf, nchars);
        if (nwr == -1)
            error_file(0, -1, argv);
    }

    /* Close files and check for errors */
    err_close = close(file_from);
    if (err_close == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
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
