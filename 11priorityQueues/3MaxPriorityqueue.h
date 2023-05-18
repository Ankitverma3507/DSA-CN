#include<vector>
#include<iostream>
#include <bits/stdc++.h>


using namespace std;

class Maxpriorityqueu 
{
    vector<int> pq;

    public:
    Maxpriorityqueu()
    { }

    bool isEmpty()
    {
        return pq.size()==0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMax()
    {
        if(isEmpty())
        {return 0;}
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childindex= pq.size()-1;

        while(childindex>0)
        {
            int parentIndex= (childindex-1)/2;

            if(pq[parentIndex]< pq[childindex])
            {
                swap(pq[parentIndex], pq[childindex]);
            }

            else{break;}
            childindex=parentIndex;
        }
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return 0;  
        }
        int max= pq[0];

        pq[0]=pq[pq.size()-1];
        pq.pop_back();


        // downheapify
        int parentIndex=0;
        int leftChildIndex= 2*parentIndex +1;
        int rightChildIndex= 2*parentIndex +2;

        while(leftChildIndex < pq.size())
        {
            int maxIndex=parentIndex;
            if(pq[maxIndex]<pq[leftChildIndex])
            {
                maxIndex=leftChildIndex;
            }

            if(rightChildIndex < pq.size() and pq[maxIndex]<pq[rightChildIndex])
            {
                maxIndex=rightChildIndex;
            }

            if(maxIndex==parentIndex){break;}
            swap(pq[maxIndex],pq[parentIndex]);

            parentIndex=maxIndex;
            leftChildIndex= 2*parentIndex +1;
            rightChildIndex= 2*parentIndex +2;
        }
        return max;

    }

};

















// for (int i = 1; i < a.size(); i++)
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