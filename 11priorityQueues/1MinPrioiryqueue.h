#include <vector>
#include <iostream>
using namespace std;

class MinpriorityQueues
{
    vector<int> pq;

public:
    MinpriorityQueues()
    {

    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childindex = pq.size() - 1;

        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] < pq[parentindex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;  
        }

        int ans = pq[0];

        pq[0] = pq[pq.size() - 1];

        pq.pop_back();

        // Down Heapify
        int parentIndex = 0;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;

        while (leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < pq.size() and pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            // swap
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }




};