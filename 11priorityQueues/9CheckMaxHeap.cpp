#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        int parentIndex = i;
        int LCI = (2 * parentIndex) + 1;
        int RCI = (2 * parentIndex) + 2;

        if ((LCI < a.size() and RCI < a.size()) and (!(a[parentIndex] > a[LCI] and a[parentIndex] > a[RCI])))
        {
            return false;
        }

        else if (LCI < a.size() && !(a[LCI] < a[i]))
            return false;
    }

    return true;
}
int main()
{
    // vector<int> a = {42, 20, 18, 6, 14, 11, 9, 4};
    vector<int> a = {8, 6, 4, 7, 3, 2, 0};
    cout << "ans is " << isMaxHeap(a);

    return 0;
}