//
//  History.cpp
//  CS32-P1
//
//  Created by XiaoJia Quan on 4/4/18.
//

#include "History.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
:R(nRows), C(nCols)
{
    for(int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            historyDisplay[i][j] = '.';
        }
    }
    
}


bool History::record(int r, int c)
{
    if((r<1 ) || (c<1) || (r>MAXROWS) || (c>MAXCOLS))
        return false;
    else
    {
        if(historyDisplay[r][c] == '.')
        {
            historyDisplay[r][c] = 'A';
        }
        else if((historyDisplay[r][c]
                >= 'A') && (historyDisplay[r][c] < 'Z'))
        {
            historyDisplay[r][c] += 1;
        }
        else
        {
            historyDisplay[r][c] = 'Z';
        }
    }
    return true;
}



void History::display() const
{
    clearScreen();
    for(int k = 1; k <= R; k++)
    {
        for (int l = 1; l <= C; l++)
        {
            cout << historyDisplay[k][l];
        }
        cout<<endl;
    }
    cout << endl;
}


