// Dictionary.cpp

// This is a correct but horribly inefficient implementation of Dictionary
// functionality.  Your job is to change DictionaryImpl to a more efficient
// correct implementation.  You can change it any way you like, subject to
// restrictions in the spec (e.g., that the only C++ library container you
// are allowed to use are vector, list, stack, and queue (and string); if you
// want anything fancier, implement it yourself).

#include "Dictionary.h"
#include <string>
#include <list>
#include <cctype>
#include <utility>  // for swap
using namespace std;

const int bucket_size = 50000;
const int primNumSize = 26;
void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);

//use chaning Hash table
struct HashWord
{
    HashWord(int key, string words, unsigned long specialKEY)
    :key(key), words(words), specialKEY(specialKEY), next(nullptr)
    {}
    int key;//key for bucket position
    string words;
    unsigned long specialKEY;  //key for each data
    HashWord* next;
    
};

class DictionaryImpl
{
public:
    DictionaryImpl() {
        m_bucket = new HashWord*[bucket_size];
        for (int i = 0; i < bucket_size; i++) {
            m_bucket[i] = NULL;//initialize buckets to null
        }
    }
    
    ~DictionaryImpl() {
        for (int i = 0; i < bucket_size; ++i) {
            HashWord* node = m_bucket[i];
            while (node != NULL) {
                HashWord* this_node = node;
                node = node->next;
                delete this_node;
            }
        }
        delete[] m_bucket;
    }
    void insertWords(string data);//insert data to hashtable
    void insert(string data);//this function will call insertwords
    int getKey(string data);//calculate the data's key
    void lookup(string letters, void callback(string));
    HashWord** m_bucket;
private:
    unsigned long m_primeNum;
};


int DictionaryImpl::getKey(string data)
{
    removeNonLetters(data);
    int i = 0;
    int primeNum[primNumSize] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    m_primeNum = 1;
    while (i < data.length()) {
         m_primeNum *= primeNum[data[i]-'a'];//each data get a special key number
        i++;
    }
    return (m_primeNum % bucket_size);  //return the pos in bucket
}

void DictionaryImpl::insertWords(string data)
{

    int key = getKey(data);
    HashWord* pre = NULL;
    HashWord* newNode = new HashWord(key, data, m_primeNum);
    HashWord* m_node = m_bucket[key];
    if(m_node == NULL)//if bucket[key] empty, set the new data to its first node
    {
        m_node = newNode;
        m_bucket[key] = m_node;
    }
    else//if not empty then let the data linked to the node
    {
        while (m_node!=NULL) {
            pre = m_node;
            m_node = m_node->next;
        }

        if(m_node == NULL)
        {
            pre->next = newNode;//insert to the end of linked list
        }
    }
    
}



void DictionaryImpl::insert(string word)
{
    removeNonLetters(word);
    if ( ! word.empty())
        insertWords(word); //call inseartword() function
}

void DictionaryImpl::lookup(string letters, void callback(string))
{
    if (callback == nullptr)
        return;

    if (letters.empty())
        return;

    int k = getKey(letters);  //get the key of imput letter
    HashWord* node = m_bucket[k]; //get the node in key's pos in bucket
    const unsigned long skey = m_primeNum; //set the current input data's primenum to skey
    while (node!=NULL)
    {
            if (node->specialKEY == skey)//compare skey to each node's primenum in this bucket
            {
                callback(node->words); //if equal, callback the node's value
            }
            node = node->next;
    }
    
}
    
void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
} 

  // Each successive call to this function generates the next permutation of the
  // characters in the parameter.  For example,
  //    string s = "eel";
  //    generateNextPermutation(s);  // now s == "ele"
  //    generateNextPermutation(s);  // now s == "lee"
  //    generateNextPermutation(s);  // now s == "eel"
  // You don't have to understand this function's implementation.
void generateNextPermutation(string& permutation)
{
    string::iterator last = permutation.end() - 1;
    string::iterator p;

    for (p = last; p != permutation.begin()  &&  *p <= *(p-1); p--)
        ;
    if (p != permutation.begin())
    {
        string::iterator q;
        for (q = p+1; q <= last  &&  *q > *(p-1); q++)
            ;
        swap(*(p-1), *(q-1));
    }
    for ( ; p < last; p++, last--)
        swap(*p, *last);
}

//******************** Dictionary functions ********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code

Dictionary::Dictionary()
{
    m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters,callback);
}
