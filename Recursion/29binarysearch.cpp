#include <iostream>
using namespace std;

int helping(int l, int st, int arr[], int key)
{
    if (l > st)
        {return -1;
        }
    else
    {
        int mid = (l + st) / 2;
        if (key == arr[mid])
        {
            return mid;
        }

        else if (key < arr[mid])
        {
            return helping(0, mid - 1, arr, key);
        }

        else
            return helping(mid + 1, st, arr, key);
    }        
}

int binarysort(int size, int arr[], int key)
{
    int l = 0;
    int st = size-1;
    return helping(l, st, arr, key);
}
int main()
{
    int arr[6] = {2, 3, 4, 5, 6, 8};
    cout << binarysort(6, arr, 8);
    return 0;
}