#include "cub3D.h"

int temporary_parser(t_data *d) {
	char map[6][8] = {
		{'1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '1', '0', '0', '1'},
		{'1', '0', '0', '1', '1', '0', '0', '1'},
		{'1', '0', '0', '1', 'N', '0', '0', '1'},
		{'1', '0', '0', '1', '1', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1'}
	};

	int rows = 6; //y
	d->mapY = rows;
	int cols = 8; //x
	d->mapX = cols;

	d->map = (char **)malloc((rows + 1) * sizeof(char *));
	for (int y = 0; y < rows; y++) {
		d->map[y] = (char *)malloc((cols + 1) * sizeof(char));
		for (int x = 0; x < cols; x++) {
			d->map[y][x] = map[y][x];
		}
		d->map[y][cols] = '\0';
	}
	d->map[rows] = '\0';
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			printf(" %c ", d->map[y][x]);
		}
		printf("\n");
	}

	return 1;
}
