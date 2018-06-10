#include "Piece.h"
#include "UserInterface.h"
#include "Well.h"
#include <queue>
#include <vector>
#include <iostream>
using namespace std;


Piece::Piece()
{}

Piece::Piece(int x, int y)
:SXcoor(x), SYcoor(y)
{
}

vector< vector<int> > Piece::PIECE_s(int aNumber)
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[0][2] = 1;
            vec_S[1][2] = 1;
            break;
        case 1:
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[2][2] = 1;
            break;
        case 2:
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[0][2] = 1;
            vec_S[1][2] = 1;
            break;
        case 3:
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[2][2] = 1;
            break;
    }
    return vec_S;
}

vector< vector<int> > Piece::PIECE_i(int aNumber)
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[0][1] = 1;
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[3][1] = 1;
            break;
        case 1:
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[1][3] = 1;
            break;
        case 2:
            vec_S[0][1] = 1;
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[3][1] = 1;
            break;
        case 3:
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[1][3] = 1;
            break;
    }
    return vec_S;
}


vector< vector<int> > Piece::PIECE_l(int aNumber)//done
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[0][1] = 1;
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[0][2] = 1;
            break;
        case 1:
            vec_S[1][0] = 1;
            vec_S[2][0] = 1;
            vec_S[2][1] = 1;
            vec_S[2][2] = 1;
            break;
        case 2:
            vec_S[0][2] = 1;
            vec_S[1][2] = 1;
            vec_S[2][2] = 1;
            vec_S[2][1] = 1;
            break;
        case 3:
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[1][3] = 1;
            vec_S[2][3] = 1;
            break;
    }
    return vec_S;
}



vector< vector<int> > Piece::PIECE_j(int aNumber)//done
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[3][1] = 1;
            vec_S[3][2] = 1;
            break;
        case 1:
            vec_S[1][3] = 1;
            vec_S[2][1] = 1;
            vec_S[2][2] = 1;
            vec_S[2][3] = 1;
            break;
        case 2:
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][2] = 1;
            vec_S[3][2] = 1;
            break;
        case 3:
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][0] = 1;
            break;
    }
    return vec_S;
}


vector< vector<int> > Piece::PIECE_t(int aNumber)//done
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[0][1] = 1;
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            break;
        case 1:
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][1] = 1;
            break;
        case 2:
            vec_S[0][1] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][1] = 1;
            break;
        case 3:
            vec_S[0][1] = 1;
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            break;
    }
    return vec_S;
}

vector< vector<int> > Piece::PIECE_o(int aNumber)
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[0][0] = 1;
            vec_S[0][1] = 1;
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            break;
        case 1:
            vec_S[0][0] = 1;
            vec_S[0][1] = 1;
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            break;
        case 2:
            vec_S[0][0] = 1;
            vec_S[0][1] = 1;
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            break;
        case 3:
            vec_S[0][0] = 1;
            vec_S[0][1] = 1;
            vec_S[1][0] = 1;
            vec_S[1][1] = 1;
            break;
    }
    return vec_S;
}


vector< vector<int> > Piece::PIECE_z(int aNumber)
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[0][1] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][2] = 1;
            break;
        case 1:
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][0] = 1;
            vec_S[2][1] = 1;
            break;
        case 2:
            vec_S[0][1] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][2] = 1;
            break;
        case 3:
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[2][0] = 1;
            vec_S[2][1] = 1;
            break;
    }
    return vec_S;}

vector< vector<int> > Piece::PIECE_vapor(int aNumber)
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[1][0] = 1;
            vec_S[2][0] = 1;
            break;
        case 1:
            vec_S[1][0] = 1;
            vec_S[2][0] = 1;
            break;
        case 2:
            vec_S[1][0] = 1;
            vec_S[2][0] = 1;
            break;
        case 3:
            vec_S[1][0] = 1;
            vec_S[2][0] = 1;
            break;
    }
    return vec_S;
}

vector< vector<int> > Piece::PIECE_foam(int aNumber)
{
    vector< vector<int> > vec_S(5, vector<int>(5, 2));
    switch (aNumber) {
        case 0:
        case 1:
        case 2:
        case 3:
            vec_S[2][2] = 1;
            break;
    }
    return vec_S;
}

vector< vector<int> > Piece::PIECE_crazy(int aNumber)
{
    vector< vector<int> > vec_S(4, vector<int>(4, 0));
    switch (aNumber) {
        case 0:
            vec_S[0][0] = 1;
            vec_S[1][1] = 1;
            vec_S[2][1] = 1;
            vec_S[3][0] = 1;
            break;
        case 1:
            vec_S[3][0] = 1;
            vec_S[2][1] = 1;
            vec_S[2][2] = 1;
            vec_S[3][3] = 1;
            break;
        case 2:
            vec_S[0][3] = 1;
            vec_S[1][2] = 1;
            vec_S[2][2] = 1;
            vec_S[3][3] = 1;
            break;
        case 3:
            vec_S[0][0] = 1;
            vec_S[1][1] = 1;
            vec_S[1][2] = 1;
            vec_S[0][3] = 1;
            break;
    }
    return vec_S;
}


void Piece::pieceDisplay(Screen& S, int r, int c, vector< vector<int> > displayV)////this is only for non-special pieces
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <4; j++)
        {
            if (displayV[i][j] == 1)
            {
                S.gotoXY(i+r, j+c);
                S.printChar('#');/////
                checkX = i+r;
                checkY = j+c;
            }
            else
                S.gotoXY(r, c);
        }
    }
}








