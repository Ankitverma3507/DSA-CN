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

void printarr(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i];
    }
}
int main()
{
int arr[]={1,3,4,6,8,7,5};
int st=0;
int ed=7;
reverse(arr,0,ed-1);
printarr(arr,7);
return 0;
}