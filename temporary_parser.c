#include "cub3D.h"

int temporary_parser(t_data *data) {
	char map[6][8] = {
		{'1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '1', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '1', '1', '1', 'N', '1', '1', '1'},
		{'1', '0', '0', '1', '1', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1'}
	};

	int rows = 6;
	int cols = 8;
	data->map_x = cols;
	data->map_y = rows;

	data->map = (char **)malloc(rows * sizeof(char *));
	for (int i = 0; i < rows; i++) {
		data->map[i] = (char *)malloc(cols * sizeof(char));
		for (int j = 0; j < cols; j++) {
			data->map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%c ", data->map[i][j]);
		}
		printf("\n");
	}
	data->mmap.texture[0] = "./textures/bricks.xpm";
	data->mmap.texture[1] = "./textures/blank";
	data->mmap.texture[2] = "./textures/blank";
	data->mmap.texture[3] = "./textures/blank";
	return 0;
}
