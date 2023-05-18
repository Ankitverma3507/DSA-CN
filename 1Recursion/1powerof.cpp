#include <iostream>
using namespace std;

int pow(int x, int n)
{
    if(n==0)
    {return 1;}
    else
    return x* pow(x, n-1);
}

int main()
{
    int x=2,n=3;
    cout<<"enter the numbers"<<endl;
    cin>>x>>n;

    cout<<"result is "<<pow(x,n);
    return 0;
}