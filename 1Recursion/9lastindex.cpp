#include<iostream>
using namespace std;

int lastindex(int a[], int key, int size)
{
    if(size=0)
    {return 0;}
    if (a[size]==key)
    {return size;}
    
    int smallerarr= lastindex(a, key, size-1);
    return smallerarr;
}
int main()
{

return 0;
}