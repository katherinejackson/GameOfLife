

#ifndef UPDATE
#define UPDATE

#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the number of alive neighbours a specific square has
 */
int num_neighbours(int** grid, int row, int col);


/**
 * Reads the given grid and determines what the next generation would
 * be based on given rules
 */
int** next_gen (int** grid, int num_rows, int num_cols);


/**
 * Print grid to console
 */
void print_grid(int** grid, int num_rows, int num_cols);

#endif //UPDATE