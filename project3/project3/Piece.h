
#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
#include <vector>
#include "Well.h"
#include "UserInterface.h"

using namespace std;


enum PieceType{
PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();

class Piece
{
public:
    Piece();
    Piece(int x, int y);
    vector< vector<int> > PIECE_i(int aNumber);
    vector< vector<int> > PIECE_l(int aNumber);
    vector< vector<int> > PIECE_j(int aNumber);
    vector< vector<int> > PIECE_t(int aNumber);
    vector< vector<int> > PIECE_o(int aNumber);
    vector< vector<int> > PIECE_s(int aNumber);
    vector< vector<int> > PIECE_z(int aNumber);
    vector< vector<int> > PIECE_vapor(int aNumber);
    vector< vector<int> > PIECE_foam(int aNumber);
    vector< vector<int> > PIECE_crazy(int aNumber);
    vector< vector<int> > NUM_PIECE_types(int aNumber);
    void pieceDisplay(Screen& pieceS, int r, int c, vector< vector<int> > displayV);
    
    int r() const {return SXcoor;}
    int c() const {return SYcoor;}
    
private:
    Well w;
    int checkX, checkY;
    int SXcoor, SYcoor;
};

#endif // PIECE_INCLUDED
