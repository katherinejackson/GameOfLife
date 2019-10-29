

#ifndef GRID_FUNCTIONS
#define GRID_FUNCTIONS

/**
 * Create a grid with m rows and n columns, initialized to 0
 */
int** createGrid(int m, int n);


/**
 * Print grid to console as is, used for testing
 */
void print_grid(int** grid, int num_rows, int num_cols);


/**
 * Converts numbers to characters and prints grid
 * without dummy first and last row and col
 */
void displayGrid(int** grid, int num_rows, int num_cols);

#endif //GRID_FUNCTIONS

