

#ifndef GAME_OF_LIFE
#define GAME_OF_LIFE

#include <stdio.h>
#include <stdlib.h>
#include "update.h"
#include "IO.h"
#include "gridFunctions.h"

/**
 * Called when user given invalid args, provides info about valid args
 */
int help();

/**
 * Checks the arguments provided by the user
 */
int check_args (int argc, char* argv[], char* filename, int* num_gen, int* print);



#endif //GAME_OF_LIFE
