//#include "Piece.h"
#include <vector>
#ifndef WELL_INCLUDED
#define WELL_INCLUDED
using namespace std;

class Screen;
class Piece;
class Well
{
  public:
    Well();
    Well(int wi, int hi);
    void displaycurrWell();
    void display(Screen& screen, int x, int y);
    void setChar(int x, int y, char c);
    char getChar(int x, int y);
    bool isPossibleMove(int x, int y, vector< vector<int> > v);
    bool isPossibleMoveR(int i , int j, vector< vector<int> > v);
    bool isPossibleMoveL(int i , int j, vector< vector<int> > v);
    bool ifRotate(int x, int y,vector< vector<int> > v);
    bool dismissAlevel(int l);
    bool deleteNthLine();
    void toDollar(int x, int y, std::vector< std::vector<int> > vv);
    void toFoam(int r, int c, std::vector< std::vector<int> > vv);
    void beVapor(int r, int c, std::vector< std::vector<int> > vv);
    
private:
    std::vector< std::vector<char> > m_well;
    int m_w_r;
    int m_w_c;
};

#endif // WELL_INCLUDED
