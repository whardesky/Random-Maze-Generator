# Random-Maze-Generator
This program will generate a completely random maze with only one valid path from start to finish.

A maze is a puzzle, with starting and ending points, in which a player is tasked to find a path connecting an starting point to an ending point. Many algorithms for automatically generating random mazes have been proposed.

A data structure for representing a maze in memory may be a two dimensional array in which every cell encodes whether each of the 4 walls is closed or open. We can assume each cell has 4 walls: north, south, east, and west.

The algorithm for generating a maze starts with a grid where only 2 walls are removed, north for the starting position, and south for the ending position, as illustrated in the 6x6 grid below.

The file format for saving the maze is just a two dimensional array of integers, where each integer is used to represent a cell and its walls. Each integer in the matrix ranges from 0 to 16. The idea behind this representation is that the walls are encoded using 4 bits, and the ingeters are just their corresponding values in decimal notation.

N = North, S = South, E = East, W = West

BITSTRING: &nbsp; &nbsp; DECIMAL: &nbsp; &nbsp; Walls Present:

N S E W

0 0 0 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (None)

0 0 0 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; W

0 0 1 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; E

0 0 1 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 3 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; E, W

0 1 0 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 4 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; S

0 1 0 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 5 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; E, W

0 1 1 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 6 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; S, E

0 1 1 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 7 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; S, E, W

1 0 0 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 8 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N

1 0 0 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 9 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N, W

1 0 1 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 10 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N, E

1 0 1 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 11 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N, E, W

1 1 0 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 12 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N, S

1 1 0 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 13 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N, S, W

1 1 1 0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 14 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N, S, E

1 1 1 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 16 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; N, S, E, W, (All)
