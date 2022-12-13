#ifndef maze
#define maze

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <random>

class Maze
{
private:
    int rows;
    int col;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<bool>> tracker;

public:   
    Maze(int N, int M);
    void generateMaze();
    void genarateMazeAlgorythm();
    void saveExport(std::string fname);
};

#endif

//  1  remove top left wall for starting point and bottom right wall for end point
//  2  the very first cell starts as seen
//  3  pick random adjacent cell to current cell and remove wall between previous and new picked cell if new picked cell has
//     not been visited
//  4  mark new picked cell as seen
//  5  only remove wall if next cell has not been seen yet
//  6  repeat until all cells are
