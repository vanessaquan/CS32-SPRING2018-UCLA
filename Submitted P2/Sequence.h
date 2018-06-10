#ifndef Sequence_hpp
#define Sequence_hpp

#include <string>

using ItemType = int;

class Sequence
{
public:
    Sequence();
    Sequence(const Sequence &s);
    ~Sequence();
    Sequence &operator=(const Sequence &src);
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
    
private:
    struct Node
    {
        ItemType value;
        Node *next;
        Node *previous;
    };
    int m_size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_hpp */

