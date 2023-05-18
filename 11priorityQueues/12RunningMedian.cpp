#include<iostream>
#include<queue>

using namespace std;

void runningMedian(vector<int> &a)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    for(int i=0; i<a.size(); i++)
    {
        if(i==0)
        {
            maxHeap.push(a[i]);
        }

        else
        {
            if(a[i]<maxHeap.top())
            {
                maxHeap.push(a[i]);
                if(maxHeap.size()- minheap.size()>1)
                {
                    minheap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }

            else
            {
                minheap.push(a[i]);
                if(minheap.size()-maxHeap.size()>1)
                {
                    maxHeap.push(minheap.top());
                    minheap.pop();
                }
            }
        }

        if((i+1)%2==0)
        {
            cout<<(maxHeap.top()+ minheap.top())/2<<" ";
        }

        else if(maxHeap.size()>minheap.size())
        {
            cout<<maxHeap.top()<<" ";
        }

        else
        cout<<minheap.top()<<" ";
    }
    return;
}
int main()
{
    vector<int> arr={6 ,2 ,1 ,3 ,7 ,5};
    runningMedian(arr);


return 0;
}