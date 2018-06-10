//
//  main.cpp
//  hw4-3
//
//  Created by XiaoJia Quan on 5/27/18.
//


//Q3-a
void removeOdds(vector<int>& v)
{
    for (int i = 0;  i < v.size(); i++) {
        if (v[i]%2 != 0) {
            v.erase(v.begin()+i);
            i--;
        }
    }
}
