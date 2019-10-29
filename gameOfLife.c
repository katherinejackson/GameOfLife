

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gameOfLife.h"
#include "gridFunctions.h"
#include "IO.h"
#include "update.h"

const int NUM_ROWS = 30;
const int NUM_COLS = 50;


/**
 * Called when user given invalid args, provides info about valid args
 * @return : 0 if successful
 */
int help() {
    printf("You have entered invalid parameter, please try again.\n");
    printf("Option: '-p' : print the state of the grid after every generation.\n");
    printf("Argument 1: a valid .txt file name containing a board.\n");
    printf("Argument 2: integer representing the number of generations the game will run for.\n");
    return 0;
}


/**
 * Checks the arguments provided by the user
 * @param argc : int; number of args given
 * @param argv : char* array of args given
 * @return : 0 if successful, 1 if unsuccessful
 */
int check_args (int argc, char* argv[], char* filename, int* num_gen, int* print) {

    int file_provided = 0;
    if (argc < 3) {
        printf("Not enough arguments.\n");
        help();
        return 1;
    }
    else {
        for (int i = 1; i < argc; i++) {
            // print option
            if (strcmp(argv[i], "-p") == 0) {
                *(print) = 1;
            }

            // num_generations is a number
            else if (atoi(argv[i]) != 0) {
                *(num_gen) = atoi(argv[i]);
            }

            else {
                // file name
                int length = strlen(argv[i]);
                char* file_type = &(argv[i][length-4]);
                if (strcmp(file_type, ".txt") == 0) {
                    strcpy(filename, argv[i]);
                    file_provided = 1;
                }
                else {
                    printf("Unknown argument given.\n");
                    help();
                    return 1;
                }
            }
        }
        if (*(num_gen) == -1) {
            printf("No generation argument given.\n");
            help();
            return 1;
        }
        if (!file_provided) {
            printf("Error: No file provided.\n");
            help();
            return 1;
        }
    }
    return 0;
}


/**
 * Runs Conways Game of life program
 * @param argc : int; number of args given
 * @param argv : char* array of args given
 * @return : 0 if successful, 1 if unsuccessful
 */
int main(int argc, char* argv[]) {
    //initialize vars
    char* filename = malloc(sizeof(char)*50);    //filename should be less than 50 characters
    if (filename == NULL) {
        printf("Failed to allocate memory for string. Aborting.\n");
        return 1;
    }
    int num_gens = -1;
    int print = 0;      // print arg initialized to be false
    int gen = 0;        //current generation

    // validate and assign arguments
    int result = check_args(argc, argv, filename, &num_gens, &print);
    if (result != 0) {
        printf("Check arguments failed\n");
        return 1;       // something went wrong
    }

//    printf("Filename: %s\nNumber of generations: %d\nPrint option: %d\n", filename, num_gens, print);

    // create grid from file
    printf("Creating grid from file %s....\n", filename);
    int** grid = createGrid(NUM_ROWS + 2, NUM_COLS + 2);      // empty rows and cols on the ends
    result = read_file(filename, grid, NUM_ROWS, NUM_COLS);
    if (result != 0) {      // something went wrong
        printf("Failed to read file.\n");
        return 1;
    }

//    printf("Grid read from file (Gen 0): \n");
//    displayGrid(grid, NUM_ROWS, NUM_COLS);

    // preform simulations
    printf("Simulating %d generations...\n", num_gens);
    while (gen < num_gens) {
        // create next generation
        int** new = next_gen(grid, NUM_ROWS + 2, NUM_COLS + 2);
        grid = new;     // new grid becomes current grid
        gen += 1;
        if (print ) {
            printf("Generation %d\n", gen);
            displayGrid(grid, NUM_ROWS, NUM_COLS);
        }

    }

    // write results
    printf("Writing to gameOfLife_output.txt ....\n");
    write_file(grid, NUM_ROWS, NUM_COLS);
//    printf("After %d generations, the grid would look like:\n", num_gens);
//    displayGrid(grid, NUM_ROWS, NUM_COLS);

    

    printf("Simulation completed, thanks for playing!\n");

    return 0;
}