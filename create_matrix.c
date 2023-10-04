#include "cub3D.h"

int create_matrix_map(t_data *d)
{
	char map[6][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};
	int rows = 6;
	int cols = 8;

	d->map_x = cols;
	d->map_x = rows;

	d->map = (char **)malloc(rows * sizeof(char *));
	if (d == NULL) {
		perror("Memory allocation failed");
		exit(1);
	}
	for (int i = 0; i < rows; i++)
	{
		d->map[i] = (char *)malloc(cols * sizeof(char));
	if (d->map[i] == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	for (int j = 0; j < cols; j++)
		d->map[i][j] = map[i][j];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d ", d->map[i][j]);
		printf("\n");
	}
	return 0;
}
