#include <stdlib.h>

/**
 * alloc_grid - function
 * @width: width
 * @height: height
 *
 * Return: Pointer or NULL
 */
int **alloc_grid(int width, int height)
{
	int **grid, i;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));
	if (!grid)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = calloc(width, sizeof(int));
		if (!grid[i])
		{
			while (i--)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
	}

	return (grid);
}
