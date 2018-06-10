//
//  Sequence.hpp
//  HW1
//
//  Created by XiaoJia Quan on 4/11/18.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#include <string>

//using ItemType = unsigned long;
using ItemType = std::string;
const int DEFAULT_MAX_ITEMS = 200;

class Sequence
{
    
public:
    Sequence();
    bool empty() const;
    int size() const;
    bool insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    //void display();
    
private:
    int Itemsize;
    ItemType m_string[DEFAULT_MAX_ITEMS];
};

#endif /* Sequence_hpp */
