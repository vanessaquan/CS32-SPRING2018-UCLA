//
//  Sequence.cpp
//  HW1
//
//  Created by XiaoJia Quan on 4/11/18.
//

#include "newSequence.h"
#include <cstring>
#include <iostream>
using namespace std;

Sequence::Sequence(int i)
{
    if(i < 0)
    {
        cout<<"Size of Sequence CANNOT be Negative!!!"<<endl;
        exit(0);
    }
    max_size = i;
    m_string = new ItemType[max_size];
}

Sequence::Sequence()
{//empty constructor
    max_size = DEFAULT_MAX_ITEMS;
    m_string = new ItemType[max_size];
}

Sequence::~Sequence()
{
    delete []m_string; //destructor,free memory
}

Sequence& Sequence::operator = (Sequence& src)
{
    if(&src == this)
        return (*this);
    delete []m_string;
    max_size = src.max_size;
    m_string = new ItemType[max_size];
    for (int i = 0; i <  max_size; i++) {
        m_string[i] = src.m_string[i];
    }
    return (*this);
}

bool Sequence::empty() const{
   // Return true if the sequence is empty, otherwise false.
    if(Itemsize == 0)
        return true;
    else
        return false;
}

int Sequence::size() const
{
    // Return the number of items in the sequence.
    return Itemsize;
}


bool Sequence::insert(int pos, const ItemType& value){
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return true if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return false.  Notice that
// if pos is equal to size(), the value is inserted at the end.
   
    if( pos >= 0 && pos <= Itemsize
       && size()+1 <= max_size )
    {
        
        for(int i = size()-1; i >= pos; i--)
            {
                m_string[i+1] = m_string[i];
            }
            m_string[pos] = value;
        Itemsize ++;
        return true;
    }
    
    return false;
}


int Sequence::insert(const ItemType& value){
// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item at position
// p.  The original item at position p and those that follow it end
// up at positions one higher than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).
    int p = 0;
    if(size() == max_size){
        return -1;
    
    }
    for (; p < size(); p++){
        if( value <= m_string[p])
        {
            insert(p, value);
            return p;
        }
    }
    p = size();
    insert(p, value);
    return p;
    
}

bool Sequence::erase(int pos)
{
// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
    if(pos < 0 || pos > size())
        return false;
    else
    {
        for (int i = 0; i <= pos; i++)
        {
            if( i == pos)
            {
                for (int j = pos; j <= size()-1; j++)
                {
                   // ItemType tmp;
                    //tmp = m_string[j];
                    m_string[j] = m_string[j+1];
                    //m_string[j+1] = m_string[j];
                }
                //m_string[size()-1] = "";
                Itemsize --;
            }
        }
    }
        return true;
}


int Sequence::remove(const ItemType& value)
{
    int count = 0;
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).
    for(int j = 0; j < size(); j++)
    {
        if(m_string[j] == value)
        {
            
            erase(j);
            count+=1;
            j--;
        }
    }
    return count;
}


bool Sequence::get(int pos, ItemType& value) const
{
// If 0 <= pos < size(), copy into value the item at position pos
// in the sequence and return true.  Otherwise, leave value unchanged
// and return false.
    if((pos >= 0) && (pos < size()))
    {
        value = m_string[pos];
        return true;
    }
    
    return false;
}

bool Sequence::set(int pos, const ItemType& value)
{
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.

    if(pos >= 0 && pos < size()){
        m_string[pos] = value;
        return  true;
    }
    return false;
}


int Sequence::find(const ItemType& value) const
{
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
    int p;
    for(int i = 0; i < size(); i++)
    {
        if(m_string[i] == value)
        {
            p = i;
            return p;
        }
    }
    return -1;
}

void Sequence::swap(Sequence& other)
{
// Exchange the contents of this sequence with the other one.
    ItemType* tmps;
    int tmpsize;
    int max;
    
    //swap contents
    tmps = m_string;
    m_string = other.m_string;
    other.m_string = tmps;
    
    //swap itemsize
    tmpsize = Itemsize;
    Itemsize = other.Itemsize;
    other.Itemsize = tmpsize;
    
    //swap max size of arr
    max = max_size;
    max_size = other.max_size;
    other.max_size = max;

}

/*void Sequence::display()
{
    for (int i = 0; i < Itemsize; i++) {
        cout<<m_string[i]<<endl;

    }
}*/
