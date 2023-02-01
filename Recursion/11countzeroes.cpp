#include<iostream>
using namespace std;

int zeroes(int n)
{
    if(n==0)
    {return 1;}

    if(n<10)
    {return 0;}

    
    else if(n%10==0)
    {return 1 + zeroes(n/10);}
    return zeroes(n/10);



}
int main()
{
cout<<"no of zeroes in n "<<zeroes(10000021)<<endl;
return 0;
}