
Conway's Game of Life

	Welcome to Conway's Game of Life.  This is a game that simulates an
ecosystem using a grid of cells.  As time moves forward, a cell can either live
or die based on the number of neighbours it has.  The rules for living or dying
are as follows:

1) If a cell is currently dead, and it has exactly 3 living neighbours, it will
be alive in the next time step.  

2) If a cell is currently alive and has fewer than 2 living neighbours, it will 
die in in the next time step from loneliness.

3) If a cell is currently alive and has 2 or 3 living neighbours, it will be
alive in the next time step.  

4) If a cell is currently alive and has 4 or more living neighbours, it will die 
in the next time step from overcrowding.

	Your job is to provide an initial grid and a number of generations, and
the program will simulate what the ecosystem would look like after that number
of generations.  The finished simulation will print to an output file titled
"gameOfLife_output.txt".  You can also chose to provide a '-p' option which will
print what the ecosystem looks like after each generation.  

Have fun and happy simulating!



