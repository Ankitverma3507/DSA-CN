#include<iostream>
using namespace std;

int duplicate(int size, int arr[])
{
    int sum=0;
    for(int i=0; i<size; i++)
    {
        sum=sum+arr[i];
    }

    int naturalsum= ((size-2)*(size-1))/2;

    return sum-naturalsum;
}
int main()
{
int arr[]={0 ,7 ,2 ,5 ,4 ,5 ,1 ,3 ,6};
int size=9;
cout<<duplicate(size, arr);
return 0;
}