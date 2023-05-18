#include<iostream>
using namespace std;


int digit(int n )
{
    static int sum=0;
    if(n>0 && n<10)
    {
        sum = sum+1;
    }
    else
    {
    sum =sum +1;
    digit(n/10);
    
    
    }
    
    return sum;}

int main()
{
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    cout<< digit(n)<<endl;

return 0;
}