//
//  main.cpp
//  concern
//
//  Created by XiaoJia Quan on 5/6/18.
//

#include <string>
#include <iostream>
using namespace std;

class Concern
{
public:
    Concern(string s):c_name(s)
    {}
    virtual ~Concern()
    {}
    virtual string description() const = 0;
    string person() const
    {
        return c_name;
    }
     virtual bool possibleFelony() const
    {
        return false;
    }
    
private:
    string c_name;
};

class EthicsMatter : public Concern
{
public:
    EthicsMatter(string name):Concern(name)
    {}
    virtual ~EthicsMatter()
    {cout<<"Destroying "<<person()<<"'s "<<"ethics matter"<<endl;}
    virtual string description() const
    {
        return "An ethics matter";
    }
    
private:
    string e_person;
    
};

class HushPayment : public Concern
{
public:
    HushPayment(string h_name, int i)
    :Concern(h_name), h_amount(i)
    {}
    virtual ~HushPayment()
    {cout<<"Destroying "<<person()<<"'s "<<"hush payment"<<endl;}
    virtual string description() const
    {
        return "A $" + to_string(h_amount) + " payment";
    }
    
private:
    int h_amount;
};

class Investigation : public Concern
{
public:
    Investigation(string n):Concern(n)
    {}
    virtual ~Investigation(){cout<<"Destroying "<<person()<<"'s "<<"investigation"<<endl;};
    virtual string description() const
    {
        return "An investigation";
    }
     virtual bool possibleFelony() const
    {
        return true;
    }
};
