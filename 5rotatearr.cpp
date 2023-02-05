#include<iostream>
using namespace std;

void reverse(int arr[], int st, int ed)
{

    while(st<ed)
    {
        int temp= arr[st];
        arr[st]= arr[ed];
        arr[ed]= temp;
        st++;
        ed--;
    }
}

void rotate(int size, int arr[], int d)
{
    reverse(arr,0,size-1);
    reverse(arr,5,6);
    reverse(arr,0,size-1-d);
}

void printarr(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i];
    }
}

int main()
{
    int arr[]={1 ,2 ,3 ,4 ,5 ,6 ,7};
    int size=7;
    rotate(7,arr,2);
    printarr(arr,7);
return 0;
}