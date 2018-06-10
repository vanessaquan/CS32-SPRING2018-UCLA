//
//  ScoreList.cpp
//  HW1
//
//  Created by XiaoJia Quan on 4/14/18.
//
#include "ScoreList.h"

ScoreList::ScoreList()
:ScoreL()
{
    // Create an empty score list.
    
}

bool ScoreList::add(unsigned long score)
{
    // If the score is valid (a value from 0 to 100) and the score list
    // has room for it, add it to the score list and return true.
    // Otherwise, leave the score list unchanged and return false.
    if(score <= 100)
    {
        ScoreL.insert(score);
        return true;
    }
    return false;
}

bool ScoreList::remove(unsigned long score){
    // Remove one instance of the specified score from the score list.
    // Return true if a score was removed; otherwise false.
    if(ScoreL.remove(score))
    {
        return true;
    }
    return false;
}

int ScoreList::size() const{ // Return the number of scores in the list.
    
    return ScoreL.size();
}

unsigned long ScoreList::minimum() const{
    // Return the lowest score in the score list.  If the list is
    // empty, return NO_SCORE.
    unsigned long lowestS = 0;
    if(ScoreL.empty())
        return NO_SCORE;
    else
        ScoreL.get(0, lowestS);
    return lowestS;
}

unsigned long ScoreList::maximum() const{
    // Return the highest score in the score list.  If the list is
    // empty, return NO_SCORE.
    unsigned long highestS = 0;
    if(ScoreL.empty())
        return NO_SCORE;
    else
        ScoreL.get(ScoreL.size() - 1, highestS);
    return highestS;
}


