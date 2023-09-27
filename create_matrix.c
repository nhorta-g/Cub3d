#include "cub3D.h"

int create_matrix_map(t_data data) {
    char map[6][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Define the dimensions of the matrix
    int rows = 6;
    int cols = 8;

    // Dynamically allocate memory for the char** array
    data.map = (char **)malloc(rows * sizeof(char *));
    if (data == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Dynamically allocate memory for each row and copy elements from map
    for (int i = 0; i < rows; i++) {
        data[i] = (char *)malloc(cols * sizeof(char));
        if (data[i] == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }
        for (int j = 0; j < cols; j++) {
            data[i][j] = map[i][j];
        }
    }

    // Access and print elements from data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }


    return 0;
}
