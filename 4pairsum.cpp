#include<iostream>
using namespace std;

void mergesort(int arr[], int st, int mid, int ed)
{
    int n1 = mid - st + 1;
    int n2 = ed - mid;

    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[i + st];
    }

    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }

    int k = 0;
    int l = 0;
    int m = st;

    while (k < n1 && l < n2)
    {
        if (arr1[k] < arr2[l])
        {
            arr[m++] = arr1[k++];
        }

        else
        {
            arr[m++] = arr2[l++];
        }
    }

    while (k < n1)
    {
        arr[m++] = arr1[k++];
    }
    while (l < n2)
    {
        arr[m++] = arr2[l++];
    }
}

void merge(int a[], int st, int ed)
{
    if (st < ed)
    {
        int mid = (st + ed) / 2;
        merge(a, st, mid);
        merge(a, mid + 1, ed);

        mergesort(a, st, mid, ed);
    }
}

int pairsum(int size, int arr[], int num)
{
int pair=0;
int i=arr[0];
int j=arr[size];
while(i<j)
{
if (i+j==num)
{
    i++;
    j--;
    pair++;
}
else if(i+j>num)
{j--;}

else
{i++;}

return pair;
}
}
int main()
{
int a[] = {1,3 ,6 ,2 ,5 ,4 ,3, 2, 4};
    merge(a, 0, 8);
    int sortarr1[]={};

    for (int i = 0; i <= 8; i++)
    {
        sortarr1[i]==a[i];
    }

    cout<<pairsum(9,sortarr1,7)<<endl;
return 0;
}