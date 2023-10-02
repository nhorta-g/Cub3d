#include "cub3D.h"

int create_matrix_map(t_data *data)
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

	data->map_x = cols;
	data->map_x = rows;

	data->map = (char **)malloc(rows * sizeof(char *));
	if (data == NULL) {
		perror("Memory allocation failed");
		exit(1);
	}
	for (int i = 0; i < rows; i++)
	{
		data->map[i] = (char *)malloc(cols * sizeof(char));
	if (data->map[i] == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	for (int j = 0; j < cols; j++)
		data->map[i][j] = map[i][j];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d ", data->map[i][j]);
		printf("\n");
	}
	return 0;
}
