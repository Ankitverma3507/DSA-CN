// print subsets of array
#include <iostream>
using namespace std;

void helping(int size, int input[], int output[], int newsize)
{
    if (size == 0)
    {
        cout << output << endl;
        return;
    }

    int newoutput[]={};
    int i = 0;
    for (; i < newsize -1; i++)
    {
        newoutput[i + 1] == output[i];
    }
    newoutput[i] == input[0];
    helping(size - 1, input + 1, output, newsize);
    helping(size - 1, input + 1, newoutput, newsize + 1);
}
void subsets(int size, int arr[])
{
    int output[] = {};
    helping(size, arr, output, 0);
}
int main()
{
    int arr[] = {15, 20, 12};
    subsets(3, arr);
    return 0;
}