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


int intersection(int n, int arr1[], int m, int arr2[])
{
    int final[]={};
int i= arr1[0];
int j=arr2[0];

while (i<n && j<m)
{
    if(arr1[i]>arr2[j])
    {j++;}
    else if(arr1[i]<arr2[j])
    {i++;}
    else
    {final[i]==arr1[i];
    i++;
    j++;}

    for(int i=0; i<3; i++)
    {cout<<final[i]<<" ";}
    return 0;
}


}
int main()
{
    int a[] = {2,6,8,5,4,3};
    merge(a, 0, 5);
    int sortarr1[]={};
    for (int i = 0; i <= 6; i++)
    {
        sortarr1[i] ==a[i] ;
    }

    int b[]={2,3,4,7};
    merge(a, 0, 3);
    int sortarr2[]={};
    for (int i = 0; i <= 6; i++)
    {
        sortarr2[i] ==b[i] ;
    }

    intersection(6,sortarr1,4,sortarr2);
    
return 0;
}