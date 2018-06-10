#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "Piece.h"
#include "UserInterface.h"
#include <string>
#include <queue>
// [Add other #include directives as necessary.]


class Game
{
  public:
    Game(int width, int height);
    void     play();
    bool     playOneLevel();
    void     displayPrompt(std::string s);
    void     displayStatus();
    void     DisplayNextPiece(std::vector< std::vector<int> > p);   //display the next piece
    void     pieceDisplay(int r, int c, vector< vector<int> > displayV);
    void     rotatePiece(PieceType currPiece,int cUP);//get the first piece
    void     rotateSecPiece(PieceType currPiece, int cUP);//get the second piece
    int      fallingTimer(int level);//the time for user to press any key
    void     calScores(int n); //increment scores of user
    void     checkFoam(int currR, int currC, int aa, int bb); //a recursive function to limit the path of foam piece
    
  private:
    Screen  m_screen;
    int     m_level = 0;//level
    Well    m_well;   
    Piece   P;
    int     m_rowsleft = 0;//rows left
    int     m_scores=0;
    int     countL=0;//count the levels finished
    int     well_r = 0;//row of well
    int     well_c = 0;//col of well
    std::vector< std::vector<int> > v;//for first piece
    std::vector< std::vector<int> > v1;//for second piece
};



#endif // GAME_INCLUDED
