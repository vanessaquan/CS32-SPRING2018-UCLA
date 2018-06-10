//
//  main.cpp
//  linear
//
//  Created by XiaoJia Quan on 5/5/18.
//


// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n)
{
    if (n <= 0)
        return true;
    if (somePredicate(a[0]) == false) {
        return false;
    }
    return allTrue(a+1, n-1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
    if (n <= 0) {
        return 0;
    }
    int c = countFalse(a+1, n-1);
    if (somePredicate(a[0]) == false) {
        return c + 1;
    }

    return c;
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int n)
{
    if (n<=0) {
        return -1;
    }
    if (somePredicate(a[0])==false)
    {
        return 0;
    }
    else
    {
        int f = firstFalse(a+1, n-1);
        if (f == -1)
            return -1;
        return f+1;
    }
}


// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the array has no elements to examine,
// return -1.
int indexOfLeast(const string a[], int n)
{
    if ( n <= 0 )
        return -1;
    
    int pos = 1 + indexOfLeast(a+1, n-1);
    if (a[0] <= a[pos])
        return 0;
    else
        return pos;
}

bool includes(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 == 0)//if no element in a2
    {
        return true;
    }
    
    if (n1 == 0 && n2 != 0) {
        return false;
    }
    
    if (a1[0] == a2[0]) {
        return includes(a1+1, n1-1, a2+1, n2-1);
    }
    
    return includes(a1+1, n1-1, a2, n2);

}
