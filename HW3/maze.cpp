//
//  main.cpp
//  maze
//
//  Created by XiaoJia Quan on 5/5/18.
//


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
//    If the start location is equal to the ending location, then we've
    int currR = sr;
    int currC = sc;
    maze[currR][currC] = '@';
    if (currR == er && currC == ec) {
        return true;
    }
    else{
        if (maze[currR-1][currC] == '.') {//north
            if(pathExists(maze, currR-1, currC, er, ec))
                return true;
        }
        
        if (maze[currR][currC-1] == '.') {//west
            if(pathExists(maze, currR, currC-1, er, ec))
                return true;
        }
        
        if (maze[currR+1][currC] == '.') {//south
            if(pathExists(maze, currR+1, currC, er, ec))
                return true;
        }
        
        if (maze[currR][currC+1] == '.') {//east
            if(pathExists(maze, currR, currC+1, er, ec))
                return true;
        }
        
       
        
    }
    return false;
}
