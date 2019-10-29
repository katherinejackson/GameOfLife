
#include <stdio.h>
#include <stdlib.h>
#include "IO.h"


  /**
  * Reads a text file containing initial grid
  * grid param will be modified to match the file
  * @param filename : name of file to be read
  * @param grid : empty grid to be modified
  * @param num_rows : int, number of rows in grid provided
  * @param num_cols : int, number of columns in grid provided
  * @return : int, 0 if successful, 1 otherwise
  */
int read_file(char filename[], int** grid, int num_rows, int num_cols) {

    FILE *file;
    file = fopen(filename, "r");       // read only
    if (file == NULL) {
        printf("Error when trying to open the file.\n");
        return 1;
    }

    char c = '\0';
    int row = 1;        // starting at 1 bc row 0 is dummy row
    int col = 1;        // starting at 1 bc col 0 is dummy col

    while ( row <= num_rows) {
        col = 1;
        while(col <= num_cols + 1) {    // one extra for new line char
            c = fgetc(file);
            if ((int)c == 42) {         // * character
                grid[row][col] = 1;

            }
            else if ((int)c == 32) {    // space character
                grid[row][col] = 0;
            }
            else if ((int)c == 10){     // new line char \n
                break;
            }
            else if ((int)c == -1) {     // end of file char
                break;
            }
            else {
                printf("Unknown Character in file: %d\n", (int)c);
                return 1;
            }
            col ++;
        }
        row ++;
    }
    if (row != num_rows + 1 || col != num_cols + 1) {       // +1 bc last row/col is added before loop ends
        printf("Warning: The input file does not match expected grid size. ");
        printf("Possible incorrect results may occur.\n");
    }
    fclose(file);
    return 0;
}


/**
 * Writes the grid array to a file
 * Dead cells are represented with a space char,
 * alive cells are represented with a * char
 * @param grid : grid containing current board
 * @param num_rows : int, number of rows in grid provided
 * @param num_cols : int, number of columns in grid provided
 * @return : int 0 if successful, 1 otherwise
 */
int write_file(int** grid, int num_rows, int num_cols) {

    FILE *file;

    file = fopen("gameOfLife_output.txt", "w+");

    for (int i = 1; i <= num_rows ; i++) {
        for (int j = 1; j < num_cols + 1; j ++ ) {
            if (grid[i][j] == 1) {
                fputc('*', file);
            }
            else {
                fputc(' ', file);
            }
        }
        if (i != num_rows) {        //last row doesnt have a new line char attached
            fputc('\n', file);
        }
    }
    fclose(file);
    return 0;
}

