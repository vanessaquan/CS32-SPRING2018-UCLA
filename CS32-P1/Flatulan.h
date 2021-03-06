//
//  Flatulan.hpp
//  CS32-P1
//
//  Created by XiaoJia Quan on 4/4/18.
//

#ifndef Flatulan_h
#define Flatulan_h


class City;

class Flatulan
{
public:
    // Constructor
    Flatulan(City* cp, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    
    // Mutators
    void move();
    bool possiblyGetConverted();
    
private:
    City* m_city;
    int   m_row;
    int   m_col;
};
#endif /* Flatulan_hpp */
