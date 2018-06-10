//
//  Game.hpp
//  CS32-P1
//
//  Created by XiaoJia Quan on 4/4/18.
//



#ifndef Game_h
#define Game_h

class City;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();
    
    // Mutators
    void play();
    
private:
    City* m_city;
};

#endif /* Game_hpp */
