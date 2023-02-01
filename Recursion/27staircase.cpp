#include<iostream>
using namespace std;

int staricase(int n)
{
    if(n==1 )
    return 1;

    else if(n==2)
    {
        return 2;}

    else if(n==3)
    {return 4 ;}



    return staricase(n-1)+ staricase(n-2)+ staricase(n-3);
}
int main()
{
cout<<staricase(5);
return 0;
}