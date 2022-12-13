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

Maze::Maze(int N, int M) {
    rows = N;
    col = M;

    this->generateMaze();

    matrix[0][0] = 7;
    matrix[rows - 1][col - 1] = 11;

    if ((matrix[0].size() == 1) && (matrix.size() == 1))
    {
        matrix[0][0] = 3;
    }

    tracker[0][0] = true;
}

void Maze::generateMaze()
{
    for (int i = 0; i < rows; i++)
    {
        std::vector<int> temp1D1;
        std::vector<bool> temp1D2;

        for (int j = 0; j < col; j++)
        {
            temp1D1.push_back(15);
            temp1D2.push_back(false);
        }

        matrix.push_back(temp1D1);
        tracker.push_back(temp1D2);
    }
}

void Maze::genarateMazeAlgorythm()
{
    /*create empty dynamic array `A`
        mark cell[0, 0] as visited
        insert cell[0, 0] at the end of `A`
        while `A` is not empty
            `current` < -remove last element from `A`
            `neighbors` < -`current`'s neighbors not visited yet
            if `neighbors` is not empty
                insert `current` at the end of `A`
                `neigh` < -pick a random neighbor from `neighbors`
                remove the wall between `current` and `neigh`
                mark `neigh` as visited
                insert `neigh` at the end of `A`
                endif
                endwhile*/
    
    std::vector<std::pair<int, int>> A = { {0,0} };
    while (A.size() != 0)
    {
        std::pair<int, int> current;
        std::vector<std::pair<int, int>> neighbors;
        std::pair<int, int> neigh;

        current = A.back();
        A.pop_back();
        
        if ((current.first - 1 >= 0) && (current.first - 1 < rows) && (current.second >= 0) && (current.second < col)
            && (tracker[current.first - 1][current.second] == false))
            neighbors.emplace_back(current.first - 1, current.second);  //  north

        if ((current.first + 1 >= 0) && (current.first + 1 < rows) && (current.second >= 0) && (current.second < col)
            && (tracker[current.first + 1][current.second] == false))
            neighbors.emplace_back(current.first + 1, current.second);  //  south

        if ((current.first >= 0) && (current.first < rows) && (current.second + 1 >= 0) && (current.second + 1 < col)
            && (tracker[current.first][current.second + 1] == false))
            neighbors.emplace_back(current.first, current.second + 1);  //  east

        if ((current.first >= 0) && (current.first < rows) && (current.second - 1 >= 0) && (current.second - 1 < col)
            && (tracker[current.first][current.second - 1] == false))
            neighbors.emplace_back(current.first, current.second - 1);  //  west

        if (neighbors.size() != 0)
        {
            A.emplace_back(current);
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            neigh = neighbors[idx];

            if (neigh.first < current.first)  //  if getting rid of north wall on current cell
            {
                matrix[current.first][current.second] = matrix[current.first][current.second] - 8;
                matrix[neigh.first][neigh.second] = matrix[neigh.first][neigh.second] - 4;
            }

            if (neigh.first > current.first)  //  if getting rid of south wall on current cell
            {
                matrix[current.first][current.second] = matrix[current.first][current.second] - 4;
                matrix[neigh.first][neigh.second] = matrix[neigh.first][neigh.second] - 8;
            }

            if (neigh.second > current.second)  //  if getting rid of east wall on current cell
            {
                matrix[current.first][current.second] = matrix[current.first][current.second] - 2;
                matrix[neigh.first][neigh.second] = matrix[neigh.first][neigh.second] - 1;
            }

            if (neigh.second < current.second)  //  if getting rid of west wall on current cell
            {
                matrix[current.first][current.second] = matrix[current.first][current.second] - 1;
                matrix[neigh.first][neigh.second] = matrix[neigh.first][neigh.second] - 2;
            }

            tracker[neigh.first][neigh.second] = true;
            A.emplace_back(neigh.first, neigh.second);
        }
    }
}

void Maze::saveExport(std::string fname)
{
    std::ofstream outFile(fname);

    for (std::vector<std::vector<int>>::const_iterator i = matrix.begin(); i != matrix.end(); ++i)
    {
        for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
        {
            outFile << *j << " ";
        }

        outFile << "\n";
    }
}
