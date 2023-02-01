#include <iostream>
#include <math.h>
using namespace std;

void sortarr(int a1[], int n, int a2[], int m, int c[])

{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a1[i] > a2[j])
        {
            c[k++] = a2[j++];
        }
        else
        {
            c[k++] = a1[i++];
        }
    }
    while (i < n)
    {
        c[k++] = a1[i++];
    }

    while (j < m)
    {
        c[k++] = a2[j++];
    }
}

void viewarr(int ans[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a1[6] = {1, 4, 9, 10, 12, 45};
    int a2[4] = {2, 3, 5, 6};
    int c[10] = {0};

    sortarr(a1, 6, a2, 4, c);

    viewarr(c, 10);

    return 0;
}