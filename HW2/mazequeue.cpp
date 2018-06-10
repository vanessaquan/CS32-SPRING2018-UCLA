////
////  mazequeue.cpp
////  mazestack
////
////  Created by XiaoJia Quan on 4/28/18.
#ifndef mazequeue
#define mazequeue
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{

    queue<Coord> coordqueue;
    Coord startcoor(sr,sc);
    coordqueue.push(startcoor);
    maze[sr][sc] = '@';
    int currR = sr;
    int currC = sc;
    while (!coordqueue.empty())
    {
        startcoor = coordqueue.front();
        currR = startcoor.r();
        currC = startcoor.c();
        coordqueue.pop();
        if(currR == er && currC == ec)
            return true;

        if(maze[currR-1][currC] == '.')
        {
            Coord newstep(currR-1, currC);
            coordqueue.push(newstep);  //push the NORTH possible step to stack
            maze[currR-1][currC] = '@';
        }


        if(maze[currR][currC-1] == '.')
        {
            Coord newstep(currR, currC-1);
            coordqueue.push(newstep);  //push the WEST possible step to stack
            maze[currR][currC-1] = '@';
        }

        if(maze[currR+1][currC] == '.')
        {
            Coord newstep(currR+1, currC);
            coordqueue.push(newstep);  //push the SOUTH possible step to stack
            maze[currR+1][currC] = '@';
        }

        if(maze[currR][currC+1] == '.')
        {
            Coord newstep(currR, currC+1);
            coordqueue.push(newstep);  //push the EAST possible step to stack
            maze[currR][currC+1] = '@';
        }
    }

    return false;

}

#endif

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','X','X','X','X','.','X','.','X','X' },
        { 'X','.','.','.','X','.','X','.','.','X' },
        { 'X','.','X','.','.','.','X','.','.','X' },
        { 'X','.','X','X','X','.','X','X','X','X' },
        { 'X','X','X','.','.','.','.','X','.','X' },
        { 'X','.','X','X','.','X','X','X','.','X' },
        { 'X','.','.','.','.','X','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };

    if (pathExists(maze, 6,5, 1,8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;


}
