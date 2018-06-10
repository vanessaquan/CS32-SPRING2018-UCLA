#include "Game.h"
#include "Well.h"
#include "UserInterface.h"
#include "Piece.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;

Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1), m_well(width, height),
m_rowsleft(5), m_scores(0), countL(0), well_r(height), well_c(width)
{
}



void Game::play()
{
    m_screen.clear();
    m_well.displaycurrWell();
    m_well.display(m_screen, WELL_X, WELL_Y);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]

    for(;;)
    {
        if ( ! playOneLevel())
         break;
        
        displayPrompt("Good job!  Press the Enter key to start next level!");
       // waitForEnter();
        m_level++;
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}

void Game::displayStatus()
{
    m_screen.gotoXY(NEXT_PIECE_TITLE_X, NEXT_PIECE_TITLE_Y);
    m_screen.printString(std::string("Next Piece:\n"));
    m_screen.gotoXY(SCORE_X, SCORE_Y);
    m_screen.printString("Score:           "+std::to_string(m_scores)+"\n");
     m_screen.gotoXY(ROWS_LEFT_X, ROWS_LEFT_Y);
    m_screen.printString("Rows left:       "+std::to_string(m_rowsleft)+"\n");
    m_screen.gotoXY(LEVEL_X, LEVEL_Y);
    m_screen.printString("Level:           "+std::to_string(m_level)+"\n");
    m_screen.refresh();
}

bool Game::playOneLevel()
{
    m_well.displaycurrWell();
    displayStatus();  //  score, rows left, level
    Timer timer;
    PieceType firstpiece;
    PieceType secondpiece;
    queue < PieceType > pieceQ;
    
    pieceQ.push(chooseRandomPieceType());
    
    
    while (true) {
        queue<std::vector< std::vector<int> > > pieces;
        std::vector< std::vector<int> > nextpieceshape;
        std::vector< std::vector<int> > firstpieceshape;
        int a = 4, b = 0;
        bool checkMove = true;
        
        pieceQ.push(chooseRandomPieceType());
        
        firstpiece = pieceQ.front();
        secondpiece = pieceQ.back();
        
        rotateSecPiece(secondpiece, 0);
        m_well.display(m_screen, WELL_X, WELL_Y);
        rotatePiece(firstpiece, 0);
        pieces.push(v);
        
        m_screen.clear();
        displayStatus();
        m_well.display(m_screen, WELL_X, WELL_Y);
        nextpieceshape = pieces.front();
        
        int Rotate = 0;
        while (checkMove)
        {
            
            timer.start();
            
            m_screen.gotoXY(a, b);
            m_well.display(m_screen, WELL_X, WELL_Y);
            displayStatus();
            DisplayNextPiece(v1);
            P.pieceDisplay(m_screen, a, b, v);
            
            while (timer.elapsed() < fallingTimer(m_level))
            {
                char ch;
                if (getCharIfAny(ch))
                {
                    if (ch == 'q' || ch == 'Q')
                    {
                        return false;
                    }
                    
                    
                    switch (ch)
                    {
                            
                        case ' '://when tap is pressed
                            while (m_well.isPossibleMove(a, b, v))
                            {
                                m_screen.gotoXY(a, b++);
                            }
                            if (firstpiece == PIECE_FOAM) {
                                for (int ii = 0; ii < 5; ii++) {
                                    for (int jj = 0; jj <5 ; jj++) {
                                        {
                                            if (ii+a > 0 && ii+a < well_r && ii+b <= well_c+1 && ii+b > 0) {
                                                if (m_well.getChar(ii+a, jj+b) == '$' || m_well.getChar(ii+a,jj+b) == '@' || m_well.getChar(ii+a, jj+b)== '*') {
                                                    v[ii][jj] = 9;  //if the corresponding pos in well is a wall, change the value in vector tobe 9
                                                }
                                            }
                                        }
                                    }
                                }
                                checkFoam(2, 2, a, b);
                                m_well.toFoam(a, b, v);
                            }
                            else if(firstpiece == PIECE_VAPOR)//special action for vapor
                            {
                                m_well.beVapor(a, b, v);
                            }
                            else//all other cases for dollar
                            {
                                m_well.toDollar(a, b, v);
                            }
                            m_screen.clear();
                            m_well.display(m_screen, WELL_X, WELL_Y);
                            displayStatus();
                            DisplayNextPiece(v1);
                            P.pieceDisplay(m_screen, a, b, v);
                            m_well.display(m_screen, WELL_X, WELL_Y);//display the most updated well
                            checkMove = false;//set checkmove to false sothat we go to next random piece
                            break;
                            
                        case ARROW_UP:
                            if (Rotate+1 < 4) //counts how many times arrow_up hit
                            {
                                rotatePiece(firstpiece, Rotate+1);//get the next shape
                                if(m_well.ifRotate(a, b, v))
                                {
                                    Rotate++;
                                    m_screen.clear();
                                    m_well.display(m_screen, WELL_X, WELL_Y);
                                    displayStatus();
                                    DisplayNextPiece(v1);
                                    P.pieceDisplay(m_screen, a, b, v);
                                }
                                else
                                {//if not movable, reset v to previous piece shape
                                    rotatePiece(firstpiece, Rotate);
                                    break;
                                }
                            }
                            else
                            {
                                rotatePiece(firstpiece, 0);
                                // if(m_well.isPossibleMoveL(a+1, b, v) && m_well.isPossibleMoveR(a-1, b, v))
                                if(m_well.ifRotate(a, b,v))
                                {
                                    Rotate = 0;
                                    m_screen.clear();
                                    m_well.display(m_screen, WELL_X, WELL_Y);
                                    displayStatus();
                                    DisplayNextPiece(v1);
                                    P.pieceDisplay(m_screen, a, b, v);
                                }
                                else
                                {
                                    rotatePiece(firstpiece, 3);
                                    break;
                                }
                                
                            }
                            
                            break;
                            
                        case ARROW_DOWN:
                            
                            if (m_well.isPossibleMove(a, b, v))//check one level lower
                            {
                                m_screen.clear();
                                m_well.display(m_screen, WELL_X, WELL_Y);
                                //                                m_well.displaycurrWell(m_screen);
                                displayStatus();
                                DisplayNextPiece(v1);
                                P.pieceDisplay(m_screen, a, ++b, v);
                            }
                            else
                            {
                                checkMove = false;
                                // m_well.toDollar(a, b, v);
                                break;
                            }
                            break;
                            
                        case ARROW_LEFT:
                            if (firstpiece == PIECE_CRAZY) {
                                if (m_well.isPossibleMoveR(a, b, v))// check right space with current shape
                                {
                                    m_screen.clear();
                                    m_well.display(m_screen, WELL_X, WELL_Y);
                                    displayStatus();
                                    DisplayNextPiece(v1);
                                    P.pieceDisplay(m_screen, ++a, b, v);//display shape in this pos
                                }
                            }
                            else   //check left space for currnt shape
                            {
                                if (m_well.isPossibleMoveL(a, b, v))
                                {
                                    m_screen.clear();
                                    m_well.display(m_screen, WELL_X, WELL_Y);
                                    displayStatus();
                                    DisplayNextPiece(v1);
                                    P.pieceDisplay(m_screen, --a, b, v);
                                }
                                
                            }
                            break;
                            
                        case ARROW_RIGHT:
                            if (firstpiece == PIECE_CRAZY) {
                                if (m_well.isPossibleMoveL(a, b, v)){
                                    m_screen.clear();
                                    m_well.display(m_screen, WELL_X, WELL_Y);
                                    //                                m_well.displaycurrWell(m_screen);
                                    displayStatus();
                                    DisplayNextPiece(v1);
                                    P.pieceDisplay(m_screen, --a, b, v);
                                }
                                else
                                    break;
                            }
                            else{
                                if (m_well.isPossibleMoveR(a, b, v))// check right space with current shape
                                {
                                    
                                    m_screen.clear();
                                    m_well.display(m_screen, WELL_X, WELL_Y);
                                    //                                m_well.displaycurrWell(m_screen);
                                    displayStatus();
                                    DisplayNextPiece(v1);
                                    P.pieceDisplay(m_screen, ++a, b, v);//display shape in this pos
                                    
                                }
                            }
                            break;
                    }//end of swith shift left/right/up/down
                }//end of if(getcharifany())
            }//end of timer.elapsed()==1000
            
            
            // if no botton hits, we want the piece drop automatically
            if (m_well.isPossibleMove(a, b, v)){
                m_screen.gotoXY(a, b++);
            }
            else{
                if (firstpiece == PIECE_FOAM) {
                    //P.pieceDisplayFoam(m_screen, a, b, v);
                    for (int ii = 0; ii < 5; ii++) {
                        for (int jj = 0; jj <5 ; jj++) {
                            {
                                if (ii+a > 0 && ii+a < well_r && ii+b <= well_c+1 && ii+b > 0) {
                                    if (m_well.getChar(ii+a, jj+b) == '$' || m_well.getChar(ii+a,jj+b) == '@' || m_well.getChar(ii+a, jj+b)== '*') {
                                        v[ii][jj] = 9;  //if the corresponding pos in well is a wall, change the value in vector tobe 9
                                    }
                                }
                            }
                        }
                    }
                    checkFoam(2, 2, a, b);
                    m_well.toFoam(a, b, v);
                }
                else if(firstpiece == PIECE_VAPOR)
                {
                    m_well.beVapor(a, b, v);
                }
                else
                    m_well.toDollar(a, b, v);
                checkMove = false;
            }
            
            if (b==0)
                return false;
            
            m_screen.clear();
            displayStatus();
            DisplayNextPiece(v1);
            m_well.display(m_screen, WELL_X, WELL_Y);
            int nDeletes = 0;
            
            for (int j = 0; j < well_r; j++)
            {
                int i = 0;
                while (i < well_c+2)
                {
                    if (m_well.getChar(i,j) == ' ')
                        break;
                    i++;
                }
                
                if (i == well_c+2)
                {
                    nDeletes++;
                }
            }
            if (nDeletes == m_rowsleft) {
                m_rowsleft = 0;
                calScores(nDeletes);
                m_screen.clear();
                displayStatus();
                DisplayNextPiece(v1);
                m_well.display(m_screen, WELL_X, WELL_Y);
                countL++;
                m_rowsleft = 5 * (m_level+countL);
                displayPrompt("Good job!  Press the Enter key to start next level!");
                waitForEnter();//
                return true;
            }
            else
            {
                while(m_well.deleteNthLine())
                    m_rowsleft--;
                calScores(nDeletes);
            }
            
            m_screen.refresh();//refresh
            
        }
        pieceQ.pop();
    }
}

void Game::DisplayNextPiece(std::vector< std::vector<int> > p)
{//print the next piece
    for (int i = 0;  i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p[i][j] == 1) {
                m_screen.gotoXY(NEXT_PIECE_X+i, NEXT_PIECE_Y+j);
                m_screen.printChar('#');
            }
        }
    }
    
}

void Game::calScores(int n)
{
    if (n == 1) {
        m_scores += 100;//scores increment by 100 when one row deleted at a time
    }
    if (n == 2) {
        m_scores += 200;//scores increment by 200 when two row deleted at a time
    }
    if (n == 3) {
        m_scores += 400;//400 scores incremented when three rows deleted at a time
    }
    if (n == 4) {
        m_scores += 800;//800 scores incremented when 4 rows deleted at a time
    }
    if (n == 5) {
        m_scores += 1600;//1600 scores added when 5 rows deleted at a time
    }
}


int Game::fallingTimer(int level)
{
    int calTimer = 0;
    Timer time;
    calTimer = max(1000-(100*(level-1)),100);
    return calTimer;
}


void Game::rotatePiece(PieceType currPiece, int cUP)
{
    //get first piece
    switch (currPiece) {
        case PIECE_I:
            v = P.PIECE_i(cUP);
            break;
        case PIECE_L:
            v = P.PIECE_l(cUP);
            break;
        case PIECE_J:
            v = P.PIECE_j(cUP);
            break;
        case PIECE_T:
            v = P.PIECE_t(cUP);
            break;
        case PIECE_O:
            v = P.PIECE_o(cUP);
            break;
        case PIECE_S:
            v = P.PIECE_s(cUP);
            break;
        case PIECE_Z:
            v = P.PIECE_z(cUP);
            break;
        case PIECE_VAPOR:
            v = P.PIECE_vapor(cUP);
            break;
        case PIECE_FOAM:
            v = P.PIECE_foam(cUP);
            break;
        case PIECE_CRAZY:
            v = P.PIECE_crazy(cUP);
            break;
        default:
            break;
    }


}





void Game::rotateSecPiece(PieceType currPiece, int cUP)
{
    //find the second piece
    switch (currPiece) {
        case PIECE_I:
            v1 = P.PIECE_i(cUP);
            break;
        case PIECE_L:
            v1 = P.PIECE_l(cUP);
            break;
        case PIECE_J:
            v1 = P.PIECE_j(cUP);
            break;
        case PIECE_T:
            v1 = P.PIECE_t(cUP);
            break;
        case PIECE_O:
            v1 = P.PIECE_o(cUP);
            break;
        case PIECE_S:
            v1 = P.PIECE_s(cUP);
            break;
        case PIECE_Z:
            v1 = P.PIECE_z(cUP);
            break;
        case PIECE_VAPOR:
            v1 = P.PIECE_vapor(cUP);
            break;
        case PIECE_FOAM:
            v1 = P.PIECE_foam(cUP);
            break;
        case PIECE_CRAZY:
            v1 = P.PIECE_crazy(cUP);
            break;
        case NUM_PIECE_TYPES:
            break;
    }


}


void Game::checkFoam(int i, int j, int aa, int bb)
{
    int currR = i;
    int currC = j;
    v[currR][currC] = 3;//set the value of the pos i visited to 3

    
    //only when vector pos value is 2 will get access
    if(currC>=0 && currC < 5 && currR-1 >=0 && v[currR-1][currC] == 2)  //East
    {
        if( m_well.getChar(currR+aa, currC+bb)==' ')
        {
            checkFoam(currR-1, currC, aa, bb);
        }
    }
    
    if(currR >= 0 && currR < 5 && currC-1 >= 0 && v[currR][currC-1] == 2)//north
    {
        if(m_well.getChar(currR+aa, currC+bb-2)==' ')
        {
         checkFoam(currR, currC-1, aa, bb);
        }
    }
    
    if(currC>=0 && currC< 5 && currR+1 < 5 && v[currR+1][currC] == 2)//west
    {
        if(m_well.getChar(currR+aa+1, currC+bb)==' ')
        {
            checkFoam(currR+1, currC, aa, bb);
        }
    }
    
    if(currR>=0 && currC >= 0 && currR < 5 && currC+1 < 5 && v[currR][currC+1] == 2)//south
    {
        if (m_well.getChar(currR+aa, currC+bb+1) == ' ')
        {
           checkFoam(currR, currC+1, aa, bb);
        }
    
    }

}


