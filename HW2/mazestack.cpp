//
//  mazestack.cpp
//  mazestack
//
//  Created by XiaoJia Quan on 4/27/18.

#ifndef mazestack_hpp
#define mazestack_hpp
#include <iostream>
#include <stack>
using namespace std;

//bool pathExists(char maze[][10], int sr, int sc, int er, int ec);

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
#endif

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack<Coord> coordstack;
    Coord startcoor(sr,sc);
    coordstack.push(startcoor);
    maze[sr][sc] = '@';
    int currR = sr;
    int currC = sc;
    while (!coordstack.empty())
    {
        startcoor = coordstack.top();
        currR = startcoor.r();
        currC = startcoor.c();

        coordstack.pop();
        
        if(currR == er && currC == ec)
            return true;
        
        if(maze[currR-1][currC] == '.')
        {
            Coord newstep(currR-1, currC);
            coordstack.push(newstep);  //push the NORTH possible step to stack
            maze[currR-1][currC] = '@';
        }
        
        
        if(maze[currR][currC-1] == '.')
        {
            Coord newstep(currR, currC-1);
            coordstack.push(newstep);  //push the WEST possible step to stack
            maze[currR][currC-1] = '@';
        }
        
        if(maze[currR+1][currC] == '.')
        {
            Coord newstep(currR+1, currC);
            coordstack.push(newstep);  //push the SOUTH possible step to stack
            maze[currR+1][currC] = '@';
        }
        
        if(maze[currR][currC+1] == '.')
        {
            Coord newstep(currR, currC+1);
            coordstack.push(newstep);  //push the EAST possible step to stack
            maze[currR][currC+1] = '@';
        }
        
    }
    
    return false;

}


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




