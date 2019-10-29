
#include <stdio.h>
#include <stdlib.h>
#include "gridFunctions.h"

/**
 * Create a grid with m rows and n columns, initialized to 0
 * @param m : num rows
 * @param n : num cols
 * @return : new array
 */
int** createGrid(int m, int n) {
    int* new_row;
    int **rows = malloc(m * (sizeof(int *)));
    if (rows == NULL) {
        printf("Failed to allocate memory. Aborting.\n");
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        new_row = calloc(n, sizeof(int));
        if (new_row == NULL) {
            printf("Failed to allocate memory. Aborting.\n");
            return NULL;
        }
        rows[i] = new_row;
    }

    return rows;
}


/**
 * Print grid to console as is, used for testing
 * @param grid : 2D int array to be printed
 */
void print_grid(int** grid, int num_rows, int num_cols) {

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j ++ ) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Converts numbers to characters and prints grid
 * without dummy first and last row and col
 * @param grid : grid to be printed
 * @param num_rows : int, number of rows
 * @param num_cols : int, number of columns
 */
void displayGrid(int** grid, int num_rows, int num_cols) {
    for (int i = 1; i < num_rows + 1; i++) {
        for (int j = 1; j < num_cols + 1; j ++ ) {
            if (grid[i][j] == 1) {
                printf("%c", '*');
            }
            else {
                printf("%c", ' ');
            }
        }
        printf("\n");
    }
    printf("\n");
}