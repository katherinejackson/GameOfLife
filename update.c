
#include <stdio.h>
#include <stdlib.h>

#include "update.h"
#include "gridFunctions.h"


/**
 * Calculates the number of alive neighbours a specific square has
 * @param grid; 2D int array, 0 means dead, 1 mean alive
 * @param row : row of square in question
 * @param col : col of square in question
 * @return : int, number of alive neighbours
 */
int num_neighbours(int** grid, int row, int col) {

    int num = 0;        // number of alive neighbours

    for (int n = -1; n <= 1; n++) {
        for (int m = -1; m <=1; m++) {
            num += grid[row + n][col + m];
        }
    }

    // previous loop counted cell in question, so subtract that back out
    num -= grid[row][col];

    return num;

}


/**
 * Reads the given grid and determines what the next generation would
 * be based on given rules
 * @param grid : 2D int array, 0 means dead, 1 mean alive
 * @return : pointer to new 2D integer array
 */
int** next_gen (int** grid, int num_rows, int num_cols) {
    int** next_gen = createGrid(num_rows + 2, num_cols + 2);
    int num_n = 0;    // number of neighbours
    int state = -1;
    for (int i = 1; i < num_rows -1; i ++) {
        for (int j = 1; j < num_cols -1; j++) {
            num_n = num_neighbours(grid, i, j);
            state = grid[i][j];

            //if cell is dead
            if (state == 0) {
                if (num_n == 3) {
                    next_gen[i][j] = 1;
                }
            }

            // if cell is alive
            else {
                // if less than 2 neighbours, cell will die from loneliness
                if (num_n < 2) {
                    next_gen[i][j] = 0;
                }
                // if 4 or more neighbours, will die from overcrowding
                else if (num_n >= 4) {
                    next_gen[i][j] = 0;
                }
                // if 2 or 3 neighbours, cell will live
                else {
                    next_gen[i][j] = 1;
                }
            }
        }
    }
    return next_gen;
}


//
//int main() {
//
//    int** test1 = createArray(4, 4);
//    test1[1][2] = 1;
//    test1[2][1] = 1;
//    test1[2][2] = 1;
//
//    print_grid(test1, num_rows, num_cols);
//    int** ans = next_gen(test1, num_rows, num_cols);
//
//
//    ans = next_gen(ans, num_rows, num_cols);
//    print_grid(ans, num_rows, num_cols);
//
//}