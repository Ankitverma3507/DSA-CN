#include<iostream>
using namespace std;

bool key(int a[], int size, int x)
{
    if(x== a[size])
    {return true;}
    
    if(size<0)
    {return false;}
    

    bool issmallerarr= key(a, size-1, x);
    return issmallerarr;

}

int main()
{
int arr[5]={2,3,4,5,8};
    cout<<key(arr, 5,3);
return 0;
}