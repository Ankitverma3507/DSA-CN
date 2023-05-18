#include<iostream>
#include<vector>
using namespace std;



int findKthLargest(vector<int>& a, int k) {

        for(int i=1; i<a.size(); i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
        int ParentIndex = (childIndex - 1) / 2;

            if (a[childIndex] < a[ParentIndex])
            {
                swap(a[childIndex], a[ParentIndex]);
            }
            else
            {
                break;
            }
            childIndex = ParentIndex;
        }
        // i++;
        
    }




    int j = a.size();

    while (j > 1)
    {
        swap(a[0], a[j - 1]);
        j--;

        int parentIndex = 0;
        int LCI = (2 * parentIndex) + 1;
        int RCI = (2 * parentIndex) + 2;
        while (LCI < j)
        {
            int minIndex = parentIndex;
            if (a[minIndex] > a[LCI])
            {
                minIndex = LCI;
            }

            if (RCI < j and a[minIndex] > a[RCI])
            {
                minIndex = RCI;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            swap(a[minIndex], a[parentIndex]);

            parentIndex = minIndex;
            LCI = (2 * parentIndex) + 1;
            RCI = (2 * parentIndex) + 2;
        }

    }

    return a[k-1];
        
    }

int main()
{
vector<int> a = { 9 ,4 ,8 ,7 ,11 ,3};
    cout<<findKthLargest(a,2);

return 0;
}