#include<iostream>
using namespace std;

int sumofdigit(int n)
{
    if(n<10)
    {return n;}

    int rem= n%10;
    return rem + sumofdigit(n/10);
}
int main()
{
 cout<<"sum of digits is "<<sumofdigit(123456);
return 0;
}