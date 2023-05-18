#include<iostream>
#include<iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include<vector>
using namespace std;

int absolute(int num)
{
    if (num<0)
    {
        return num*(-1);
    }
    else 
    return num;
}

int getPairsWithDifferenceK(int *input, int n, int k)
{
    // Write your code here
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
        m[input[i]]++;
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m.count(input[i] - k) > 0)
                count = count + m[input[i] - k];
                m[input[i]]--;
        }
    }
    else if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m.count(input[i]) > 0)
            {
                count = count + m[input[i]];
                m[input[i]]--;
            }
            count--;
        }
    }
    return count;
}


int main()
{
    // int a[]= {5 ,1, 2, 4};
    int a[]= {10 ,1 ,3 ,12 ,16 ,6 ,6};
    int size=7;
    int k=10;

    cout<<"ans is "<<getPairsWithDifferenceK(a,size,k);
return 0;
}