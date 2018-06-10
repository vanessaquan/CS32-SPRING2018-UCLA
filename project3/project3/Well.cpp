#include "Well.h"
#include "UserInterface.h"
#include <vector>
#include <queue>
using namespace std;

Well::Well()
{}

Well::Well(int wi, int hi)
:m_w_r(hi), m_w_c(wi)
{
}

void Well::displaycurrWell()//set the well
{
    m_well.clear();
    char c = ' ';
    for (int i = 0; i < m_w_c+2; i++)
    {
        vector<char> temp;
        for (int j = 0; j < m_w_r+1; j++) {
            temp.push_back(c);
        }
        m_well.push_back(temp);
    }
    for (int row = 0; row < m_well.size(); row++)
    {
        m_well[row][m_well[row].size()-1 ] = '@';
    }
    for (int col = 0; col < m_well[m_well.size()-1].size(); col++)
    {
        m_well[m_w_c+1][col] = '@';
        m_well[0][col] = '@';
    }
    
}

void Well::display(Screen& screen, int x, int y) //x is column, y is row
{
    for (int row = 0; row < m_well.size(); row++)
    {
        for (int col = 0; col < m_well[row].size(); col++)
        {
            screen.gotoXY(row+x, col+y);
            screen.printChar(m_well[row][col]);
        }
    }
    
    
}


void Well::toDollar(int x, int y, std::vector< std::vector<int> > vv)
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++) {
            if (vv[i][j] == 1){
                m_well[x+i][y+j] = '$';
//                setChar(x+i, y+j, '$');
            }
        }
    }
}

void Well::toFoam(int r, int c, std::vector< std::vector<int> > vv)
{
    
    for (int row = 0; row < 5; row++)
    {
            for (int col = 0; col < 5; col++)
            {
                    if (vv[row][col] == 3 && m_well[r+row][c+col] == ' ')
                    {
                        m_well[r+row][c+col] = '*';
                    }
               
            }
    }

}

void Well::beVapor(int r, int c, std::vector< std::vector<int> > vv)
{
  int v = 2;
  for (int row = 0; row < 4; row++)
    {
      for (int col = 0; col < 4; col++)
        {
	  if (vv[row][col] == 1) {
	    while (v >= -1) {
	      if (c+col+v< m_w_r+1) {
		if(m_well[r+row][c+col+v]=='$' ||  m_well[r+row][c+col+v]=='*')
		  m_well[r+row][c+col+v] = ' ';
	      }
	      v--;
	    }
	    v = 2;
	  }
            
        }
    }
}

void Well::setChar(int x, int y, char a)
{
    m_well[x][y] = a;
}

char Well::getChar(int x, int y)
{
    char c = m_well[x][y];
    return c;
}

bool Well::isPossibleMove(int x, int y, vector< vector<int> > v)
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0;  j < v[i].size(); j++) {
            if (v[i][j] == 1 && m_well[x+i][y+j+1] != ' ' ){
                return false;
            }
        }
    }
    return true;
}

bool Well::isPossibleMoveR(int x , int y, vector< vector<int> > v)
{
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0;  j < v[i].size(); j++) {
                if (v[i][j] == 1 && m_well[x+i+1][y+j] != ' ') {
                    return false;
                }
            }
        }
    
    return true;
}

bool Well::isPossibleMoveL(int x , int y, vector< vector<int> > v )
{
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0;  j < v[i].size(); j++) {
                if (v[i][j] == 1 && m_well[x+i-1][y+j] != ' ') {
                    return false;
                }
            }
        }
    return true;
}

bool Well::ifRotate(int x, int y, vector< vector<int> > v)
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 1 && (x+i < 0 || y+j > m_w_r || m_well[x+i][y+j] != ' ')) {
                return false;
            }
        }
    }
    
    return true;
}

bool Well::dismissAlevel(int l)
{
       for (int j = l; j > 0; j--)
        {
            for (int i = 1; i < m_well.size(); i++)
            {
                m_well[i][j] = m_well[i][j-1];
            }
        }
    return true;

}


bool Well::deleteNthLine()
{
    for (int j = 0; j < m_w_r; j++)
    {
        int i = 0;
        while (i < m_w_c+2)
        {
            if (m_well[i][j] == ' ')
                break;
            i++;
        }

        if (i == m_w_c+2)
        {
            return dismissAlevel(j);
        }
    }
    return false;
}
