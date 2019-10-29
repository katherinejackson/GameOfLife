
#ifndef IO
#define IO

#include <stdio.h>
#include <stdlib.h>

/**
 * Reads a text file containing initial grid
 * Grid param will be modified to match the file
 */
int read_file(char filename[], int** grid, int num_rows, int num_cols);


/**
 * Writes the grid array to a file
 * Dead cells are represented with a space char,
 * alive cells are represented with a * char
 */
int write_file(int** grid, int num_rows, int num_cols);

#endif //IO