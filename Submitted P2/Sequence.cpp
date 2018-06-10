//
//  Sequence.cpp
//  project 2
//
//  Created by XiaoJia Quan on 4/20/18.
//

#include "Sequence.h"


Sequence::Sequence()
{
    
}

Sequence::Sequence(const Sequence &other)
{
    for (int i = 0; i < other.size(); i++) {
        ItemType V;
        other.get(i, V);
        insert(i, V);
    }
}

Sequence::~Sequence()
{
    Node *tmp = head;
    Node *d = nullptr;
    while(tmp != nullptr){
        d = tmp;
        tmp = tmp->next;
        delete d;
    }
    head = nullptr;
    tail = nullptr;
    delete tmp;
}

Sequence & Sequence::operator=(const Sequence &src)
{
    
    if(this != &src){
        Sequence s(src);
        swap(s);
    }
    return *this;
}

inline
bool Sequence::empty() const
{
    if(m_size == 0)
        return true;
    return false;
}

inline
int Sequence:: size() const{
    return m_size;
}

bool Sequence::insert(int pos, const ItemType& value)//checked
{
    if(pos<0 || pos > size())
        return false;
    
    else{
        Node *node = new Node;
        node->value = value;
        if (empty() && pos ==0)//if list empty, insert to head
        {
            node->previous = nullptr;
            node->next = nullptr;
            head = node;
            tail = node;
            m_size++;
            return true;
        }
        else if ( pos == 0 && !empty())//is list not empty, insert to head
        {
            
            node->next = head;
            head->previous = node;
            node->previous = nullptr;
            head = node;
            m_size++;
            return true;
        }
        
        else if(pos > 0 && pos <= size())//insert to middle or to the end
        {
            
            
            Node *curr = head;
            Node *pre = nullptr;
            int i = 0;
            while (i!=pos)
            {
                if(curr!=nullptr)
                {   i++;
                    pre = curr;
                    curr = curr->next;
                }
                else
                    break;
            }
            if(pos > 0 && pos < size())//insert to middle
            {
                node->next = curr;
                node->previous = pre;
                curr->previous = node;
                pre->next = node;
                m_size++;
                return true;
            }
            else//insert to end
            {
                pre->next = node;
                node->previous = pre;
                node->next = nullptr;
                tail = node;
                m_size++;
                return true;
            }
        }
        
        
    }
    
    return false;
    
}

int Sequence::insert(const ItemType& value)//checked
{
    const int s = size();
    if(!empty())
    {
        Node *n = head;
        for(int i = 0; i < s; i++)
        {
            
            if(value <= n->value)
            {
                insert(i, value); //insert before n
                return i;
            }
            else
            {
                if(n->next == nullptr)//if n is the last node and its value is less than value
                    break;//break from the look
                n = n->next;
                
            }
        }
    }
    insert(s, value);//no elements greater than value, insert to the end
    return s;
}

bool Sequence::erase(int pos)
{
    
    if(!empty() && pos >=0 && pos < size())
    {
        Node *h = head;
	for(int i = 0; i != pos; h = h->next, i++)
	  ;
        if(pos == 0 && size() == 1)//if only one node, delete it
        {
            head = nullptr;
            delete h;
            m_size--;
            return true;
        }
        else if (pos == 0 && size()>1)//if list has at least two nodes, delete head
        {
            head = h->next;
            h->next->previous = head;
            h->previous = nullptr;
            delete h;
            m_size--;
            return true;
        }
        else if (pos == size()-1 && size()>1)//list has at least two node, delete tail
        {
            tail = h->previous;
            h->previous->next = nullptr;
            delete h;
            m_size--;
            return true;
        }
        else{//delete form the middle
            h->next->previous = h->previous;
            h->previous->next = h->next;
            delete h;
            m_size--;
            return true;
        }
    }
    
    return false;
    
}

int Sequence::remove(const ItemType& value)
{
    int count = 0;
    Node *curr = nullptr;
    if(!empty())
    {
        for (curr = head; curr != nullptr ; )
        {
            if ( curr->value == value)
            {
                if(curr == head && size()==1){
                    //if only one node
                    delete curr;
                    head = nullptr;
                    tail = nullptr;
                    count++;
                    m_size--;
                    return count;
                }
                else if(curr == head && size()>1)
                {//if more than one node in list, remove head
                    head = head->next;
		    curr->next->previous = nullptr;
                    delete curr;
                    curr = head;
                    m_size--;
                    count++;
                }
                else if(curr->next != nullptr)
                {//remove in middle of list
		  Node *tmp = curr->next;
		    curr->previous->next = curr->next;
                    curr->next->previous = curr->previous;
                    delete curr;
                    m_size--;
                    count++;
                    curr = tmp;
                }
                else if (curr->next == nullptr && size()>1)
                {//remove tail
		  tail = curr->previous;
		  tail->next = nullptr;
		  delete curr;
		  m_size--;
		  count++;
		  return count;
                }
                
            }else//not match value, go to the next node
            {
                curr = curr->next;
            }
            
        }
        
        return count;
        
    }
    return 0;
}

bool Sequence::get(int pos, ItemType& value) const
{
    if(pos < 0 || pos >= size())
        return false;
    
    Node *p = head;
    for(int i = 0; i < m_size; i++ )
    {
        if(i == pos)
        {
            value = p->value;  //copy current value to value
            return true;
        }
        p = p->next;
    }
    //delete p;
    return false;
}

bool Sequence::set(int pos, const ItemType& value) //checked
{
    Node *curr = nullptr;
    
    if(pos >= 0 || pos < size())
    {
        curr = head;
        for(int i = 0; i < m_size; i++ )
        {
            if(i == pos)
            {
                curr->value = value;  //replace current value with value
                return true;
            }
            curr = curr->next;
        }
    }
    return false;
}

int Sequence::find(const ItemType& value) const //checked
{
    Node *f = head;
    int c = 0;
    while (f!=nullptr && c<size())
    {
        if(f->value == value)
        {
            return c;  //return value's first occurance position
        }
        c++;
        f = f->next;
    }
    return -1;
}


void Sequence::swap(Sequence& other)  //checked
{
    //swap heads
    Node *s1 = head;
    Node *s2 = other.head;
    head = s2;
    other.head = s1;
    
    //swap size
    int tmpsize = m_size;
    m_size = other.size();
    other.m_size = tmpsize;
}


int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    ItemType v1, v2, vtmp;
    int size2 = seq2.size();
    int initialpos = 0;
    Sequence tmp;
    
    seq2.get(0, v2);
    ItemType s2;
    s2 = v2;
    
    if(seq2.size()==0 || seq2.size() > seq1.size())
        return -1;
    //search where seq2 occurs in seq1
    for (int i = 0; i < seq1.size(); i++)
    {
        seq1.get(i, v1);
        if(i+size2-1 >= seq1.size())
            return -1;
        
        if(v1 == s2)//if value in seq1 in position i equals to head of seq2, do the following
        {
            initialpos = i;//record start of subsequence's position in seq1 to initialpos
            int postmp=0;
            size2 = seq2.size();
            
            while(!tmp.empty())//if tmp is not empty, empty it
            {
                tmp.erase(0);
            }
            
            for(int k = i; size2 != 0; k++)//add the same # of element start at position i to tmp sequence
            {
                seq1.get(k, v1);
                tmp.insert(postmp, v1);
                postmp++;
                size2--;
            }
        }
        
        //compare the tmp sequence with seq2
        for(int j = 0; j < seq2.size(); j++)
        {
            seq2.get(j, v2);
            tmp.get(j, vtmp);
            if(v2 != vtmp)//if the order of values not identical with seq2, break
            {
                break;
            }
            if(v2 == vtmp && j == tmp.size()-1)//if reach the end of tmp sequence, return initialpos
            {
                return initialpos;
            }
            //else do nothing and continuing compare with each elements
        }
    }
    return -1;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    ItemType tmpr1;
    ItemType tmpr2;
    int k = 0;
    
    if(seq1.empty() && !seq2.empty())//if seq1 is empty, copy seq2 to result
        result = seq2;
    if(!seq1.empty() && seq2.empty())//if seq2 is empty, copy seq1 to result
        result = seq1;
    if(!seq1.empty() && !seq2.empty())//if both not empty, find subseq
    {
        for (int i = 0; i < seq1.size(); i++) {
            //put seq1 into result first
            seq1.get(i, tmpr1);
            result.insert(i, tmpr1);
        }
        
        for (int j = 1; k<seq2.size(); j+=2) {
            //insert to in between two seq2 elements.
            seq2.get(k, tmpr2);
            if(j>result.size())
            {
                result.insert(result.size(), tmpr2);
            }
            else
                result.insert(j, tmpr2);
            k++;
        }
    }
    
}
