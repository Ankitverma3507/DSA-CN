#include<iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int > *vp=new vector<int>();//dynamically 

    vector <int>v;//statically

    //we can add element by using functio like this
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.pop_back();//we can also delete the last element from the vector


    //we will not use [] for insertion of element into the vector 
    // v[6]=1023;
    // v[7]=1224;

    //we can treat it like array while printing element of this vector like this

    v[1]=100;
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;

    //we can use v.at() funtion to get the data instead of [] because it is safer

    cout<<v.at(2)<<endl;
    cout<<v.at(6)<<endl;

    //we can also use for loop
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<endl;
    }

return 0;
}