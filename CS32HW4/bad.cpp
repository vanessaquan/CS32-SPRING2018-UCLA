//
//  bad.cpp
//  hw4-3
//
//  Created by XiaoJia Quan on 5/29/18.
//
//
//Q3-b
void removeBad(list<Movie*>& li)
{
    list<Movie*>::iterator templi = li.begin();
    for(; templi!=li.end();){
        if ((*templi)->rating() < 50) {
            destroyedOnes.push_back((*templi)->rating());
            
            templi = li.erase(templi);
        }
        else
            ++templi;
    }
}
