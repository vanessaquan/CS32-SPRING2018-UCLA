//
//  Sequence.cpp
//  HW1
//
//  Created by XiaoJia Quan on 4/11/18.
//

#include "Sequence.h"
#include <cstring>
#include <iostream>
using namespace std;

Sequence::Sequence()
{
    Itemsize = 0;// Create an empty sequence (i.e., one with no items)
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
       && size()+1 <= DEFAULT_MAX_ITEMS )
    {
        for(int i = size(); i >= 0; i--)
        {
            if( i > pos )
            {m_string[i] = m_string[i-1];}
            if( i == pos )
            {
                m_string[i] = value;
            }
        }
        Itemsize += 1;
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
    for (; p < size(); p++){
        if( value <= m_string[p])
        {
            insert(p, value);
            return p;
        }
    }
    
    if(size() < DEFAULT_MAX_ITEMS)
    {
        p = size();
        insert(p,value);
        return p;
    }
    return -1;
    
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
                    m_string[j] = m_string[j+1];
                }
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
/*  const int tmpsize = Itemsize;
  ItemType tmp[tmpsize];
  ItemType tmps;
  for(int i = 0; i < tmpsize; i++)
    {
      tmp[i] = this->m_string[i];
    }
    
  for(int k = 0; k < other.Itemsize; k ++)
    {
      this->m_string[k] = other.m_string[k];
    }
  Itemsize = other.Itemsize;

  for(int j = 0; j < tmpsize; j ++)
    {
      other.m_string[j] = tmp[j];
    }
    
  other.Itemsize = tmpsize;
*/
  ItemType tmps[DEFAULT_MAX_ITEMS];
  int tmpsize =0;
  for(int i = 0; i < other.size(); i++)
    {
      tmps[i] = other.m_string[i];
      tmpsize++;
    }
    
  other.Itemsize = 0;
  for (int j =0; j < size(); j++) {
    other.m_string[j] = m_string[j];
    other.Itemsize++;
  }
  Itemsize = tmpsize;
  for (int k = 0; k < Itemsize; k++) {
    m_string[k] = tmps [k];
  }
}

//void Sequence::display()
//{
//  for(int i = 0; i < size(); i++)
//  {
//      cout<<m_string[i]<<endl;
//  }
//}
