#include<iostream>
#include<queue>

using namespace std;


void KsortedArr(int *a, int size, int k)
{
    priority_queue<int> pq;
    for(int i=0; i<k; i++)
    {
        pq.push(a[i]);
    }

    int j=0;
    for(int i=k; i<size; i++)
    {
        a[j]= pq.top();
        pq.pop();
        pq.push(a[i]);
        j++;
    }

    while(!pq.empty())
    {
        a[j]=pq.top();
        pq.pop();
        j++;
    }
}
int main()
{

int a[]={10,12,6,7,9};
int size=5;
int k=3;

KsortedArr(a,size,k);

for(int i=0; i<size; i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;
return 0;
}