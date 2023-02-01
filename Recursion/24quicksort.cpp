#include <iostream>
using namespace std;
int partition(int a[], int st, int ed)
{
    int count = 0;
    int x = a[st];
    for (int i = st + 1; i <= ed; i++)
    {
        if (a[i] <= x)
        {
            count++;
        }
    }

    int xindex = count + st;
    int temp = a[st];
    a[st] = a[count + st];
    a[count + st] = temp;
    // cout << "count is " << count << endl;

    int i = st;
    int j = ed;
    while (i < xindex && j > xindex)
    {
        if (a[i] <= x)
        {
            i++;
        }

        else if (a[j] > x)
        {
            j--;
        }

        else
        {
            int temp1 = a[i];
            a[i] = a[j];
            a[j] = temp1;
            i++;
            j--;
        }
    }

    return xindex;
}

void quicksort(int a[], int st, int ed)
{
    if (st >= ed)
    {
        return;
    }

    int c = partition(a, st, ed);

    quicksort(a, st, c - 1);
    quicksort(a, c + 1, ed);
}
int main()
{
    int a[] = {5, 2, 4, 1, 9, 9};
    int n = 6;

    quicksort(a, 0, n - 1);

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}