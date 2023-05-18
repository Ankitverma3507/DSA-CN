#include <iostream>
#include "1MinPrioiryqueue.h"
#include <vector>

using namespace std;

void InplaceHeapSort(vector<int> &a)
{
    // insert function is going on
    // int i = 1;
    // int childIndex = i;
    // int ParentIndex = (childIndex - 1) / 2;
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

    //  for (int i = 1; i < a.size(); i++)
    //     {
    //         int childIndex = i;
    //         while (childIndex > 0)
    //         {
    //             int ParentIndex = (childIndex - 1) / 2;
    //             if (a[childIndex] < a[ParentIndex])
    //             {
    //                 swap(a[childIndex], a[ParentIndex]);
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //             childIndex = ParentIndex;
    //         }
    //     }



    // remove min function is going on

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
}
int main()
{

    // vector<int> a = { 2, 6, 8, 5, 4, 3, 9,1,0};
    vector<int> a = { 9 ,4 ,8 ,7 ,11 ,3};
    int k=2;
    InplaceHeapSort(a);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}