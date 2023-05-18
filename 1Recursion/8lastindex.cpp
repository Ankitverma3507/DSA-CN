#include<iostream>
using namespace std;

int lastindex(int a[], int size, int key)
{
    if(key== a[size])
    {return size;}
    if(size<0)
    {return -1;}

    int smallerarr= lastindex(a, size-1, key);
    return smallerarr;
}
int main()
{
int arr[6]={1,3,6,3,3,9};
cout<<lastindex(arr,6 , 3);
return 0;
}