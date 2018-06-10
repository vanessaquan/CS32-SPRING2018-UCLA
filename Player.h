//
//  Player.hpp
//  CS32-P1
//
//  Created by XiaoJia Quan on 4/4/18.
//
#ifndef Player_h
#define Player_h

#include "globals.h"
class City;
//use safe guard to avoid duplicate functions while compiling
class Player
{
public:
    // Constructor
    Player(City *cp, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    int  health() const;
    bool isPassedOut() const;
    
    // Mutators
    void  preach();
    void  move(int dir);
    void  getGassed();
    
private:
    City* m_city;
    int   m_row;
    int   m_col;
    int   m_health;
    int   m_age;
};

#endif /* Player_hpp */
