# Random-Maze-Generator
This program will generate a completely random maze with only one valid path from start to finish.

A maze is a puzzle, with starting and ending points, in which a player is tasked to find a path connecting an starting point to an ending point. Many algorithms for automatically generating random mazes have been proposed.

A data structure for representing a maze in memory may be a two dimensional array in which every cell encodes whether each of the 4 walls is closed or open. We can assume each cell has 4 walls: north, south, east, and west.

The algorithm for generating a maze starts with a grid where only 2 walls are removed, north for the starting position, and south for the ending position, as illustrated in the 6x6 grid below.

The file format for saving the maze is just a two dimensional array of integers, where each integer is used to represent a cell and its walls. Each integer in the matrix ranges from 0 to 16. The idea behind this representation is that the walls are encoded using 4 bits, and the ingeters are just their corresponding values in decimal notation.

N = North

S = South

E = East

W = West

BITSTRING:      DECIMAL:      Walls Present:

N S E W

0 0 0 0         0             (None)

0 0 0 1         1             W

0 0 1 0         2             E

0 0 1 1         3             E, W

0 1 0 0         4             S

0 1 0 1         5             E, W

0 1 1 0         6             S, E

0 1 1 1         7             S, E, W

1 0 0 0         8             N

1 0 0 1         9             N, W

1 0 1 0         10            N, E

1 0 1 1         11            N, E, W

1 1 0 0         12            N, S

1 1 0 1         13            N, S, W

1 1 1 0         14            N, S, E

1 1 1 1         16            N, S, E, W, (All)
