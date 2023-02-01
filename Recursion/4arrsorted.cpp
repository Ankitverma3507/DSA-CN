#include<iostream>
using namespace std;

bool issorted(int a[], int size)
{
    if(size==0 || size==1)
    {
        return true;
    }

    if(a[0]> a[1])
    {
        return false;
    }

    bool issmallersorted= issorted(a+1, size-1);
    return issmallersorted;
}
int main()
{
    int arr[6]={2,3,4,5,8,1};
    cout<<issorted(arr, 6);

return 0;
}