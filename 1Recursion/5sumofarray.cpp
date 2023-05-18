#include<iostream>
using namespace std;

int sumofarr(int a[],int size)
{
    if(size==1)
    {
        return a[0];
    }
    int smallerarr= sumofarr(a, size-1);
    return a[size-1]+ smallerarr;
}
int main()
{
    int arr[5]={2,3,4,5,8};
    cout<<sumofarr(arr, 5);

return 0;
}