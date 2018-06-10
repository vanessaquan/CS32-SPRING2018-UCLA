//
//  History.hpp
//  CS32-P1
//
//  Created by XiaoJia Quan on 4/4/18.
//
#ifndef History_h
#define History_h
#include "globals.h"

class History
{
    public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
    private:
        char historyDisplay[MAXROWS][MAXCOLS];
        int R;
        int C;
    
};
#endif
 

