//Name: Aastha Lamichhane
//File: main.cpp

#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
#include "maze.h"

bool find(const std::vector<PunchedWall> & v, PunchedWall p0)
{
    for (int i = 0; i < v.size(); ++i)
    {
        PunchedWall p = v.at(i);
        if (p0 == p) return true;
    }
    return false;
}

void printMaze(int n, const std::vector<PunchedWall> & v, const std::stack <Cell> & path)
{
    char string[n * 2 + 2];
    Cell c = path.top();
    for (int i = 0; i < 2 * n; i += 2)
    {
        string[i] = '+';
        string[i + 1] = '-';
    }
    string[n * 2] = '+';
    string[n* 2 + 1] = '\0';
    int count = 0;
    
    for (int i = 0; i < 2 * n; ++i)
    {
        if (i % 2 != 0) std::cout << "|";
        else std::cout << "+";
        for (int j = 0; j < n; ++j)
        {
            if (i % 2 != 0)
            {
                if (j == 0) ++count;
                Cell c0(i - count, j);
                Cell c1(i - count, j + 1);
                PunchedWall p1(c0, c1);
                //if v contains p1 then print "  ", else print "| "
                if (find(v, p1))
                {
                    std::cout << ((c == c0) ? "X " : "  ");
                }
                else
                {
                    std::cout << ((c == c0) ? "X|" : " |");
                }
            }
            else
            {
                Cell c0(i - count - 1, j);
                Cell c1(i - count, j);
                PunchedWall p1 (c0, c1);
                std::cout << ((find(v, p1)) ? " +" : "-+");
            }
        }
        std::cout << "\n";
    }
    std::cout << string << "\n";
}


std::vector<Cell> findPath(int n, Cell & c0, const bool* visited)
{
    std::vector<Cell> v0;
    int r = c0.getR();
    int c = c0.getC();
    if ((r + 1 < n) && (c < n) && visited[(r + 1) * n + c] == false)
    {
        Cell c1(r + 1, c);
        v0.push_back(c1);
    }
    if ((r - 1 >= 0) && (c < n) && visited[(r - 1) * n + c] == false)
    {
        Cell c1(r - 1, c);
        v0.push_back(c1);
    }
    if ((r < n) && (c + 1 < n) && visited[r * n + (c + 1)] == false)
    {
        Cell c1(r, c + 1);
        v0.push_back(c1);
    }
    if ((r < n) && (c - 1 >= 0) && visited[r * n + (c - 1)] == false)
    {
        Cell c1(r, c - 1);
        v0.push_back(c1);
    }
    
    return v0;
}


bool findUnVisited(const bool* visited, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            //means there are cells remaining to visit.
            if (visited[i * n + j] == false) return true;
        }   
    }
    //all cells are visited
    return false;
}


int main()
{
    srand((unsigned int) time(NULL));
    //n = size of maze; r = row of X; c = column of X
    int n, r, c;
    //to track the visited cells
    bool* visited = new bool[n * n];
    //to track the path
    std::stack<Cell> path;
    //to track the punched walls
    std::vector<PunchedWall> pWall;
    
    std::cin >> n >> r >> c;
    Cell c0(r, c);
    path.push(c0);
    visited[r * n + c] = true;

    while (findUnVisited(visited, n) == true)
    {
        std::cout << "\n";
        printMaze(n, pWall, path);
        Cell c1 = path.top();
        //finds all the available path
        std::vector <Cell> availablePath = findPath(n, c1, visited);
        int size = availablePath.size();

        if (size > 0)
        {
            //to get a random index
            int index = rand() % size;
            Cell c2 = availablePath[index];
            //pushes the path at the index into path
            path.push(c2);
            visited[c2.getR()* n + c2.getC()] = true;
            //to remove the path so that we do not use that route again
            availablePath.erase(availablePath.begin() + index);
            //storing the punched walls
            PunchedWall p0(c1, c2);
            PunchedWall p1(c2, c1);
            pWall.push_back(p0);
            pWall.push_back(p1);
        }
        else
        {
            path.pop();
        }
    }
    delete [] visited;
    return 0;
}
