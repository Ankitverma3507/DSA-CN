#include<iostream>
using namespace std;

int firstindex(int a[], int key, int size)
{
    if(key==a[0])
    {return 0;}
    if(size=0)
    {return -1;}

    int first= firstindex(a+1, key, size-1);
    return 1+ first;
}
int main()
{
int arr[6]={1,3,6,3,2,9};
cout<<firstindex(arr,3 , 6);
return 0;
}