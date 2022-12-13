#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <random>
#include "maze.h"

int main(int argc, char* argv[])
{
    int seed = std::stoi(argv[1]);
    int N = std::stoi(argv[2]); // rows
    int M = std::stoi(argv[3]); // col
    std::string fname(argv[4]);

    srand(seed);
   
    Maze* myMaze = new Maze(N, M);

    myMaze->genarateMazeAlgorythm();

    myMaze->saveExport(fname);
}
