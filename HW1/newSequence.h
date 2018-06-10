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
    Sequence(int i);
    Sequence();// Create an empty sequence (i.e., one with no items)
    ~Sequence();//add a destructor to avoid memory leaking
    Sequence& operator = (Sequence &src);//add assignment operator
    
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.
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
    int Itemsize = 0;
    int max_size;
    ItemType* m_string;
};

#endif /* Sequence_hpp */
