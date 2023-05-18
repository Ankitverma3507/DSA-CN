#include<iostream>
#include<queue>

using namespace std;

int buyticket(vector<int> &a, int k)
{
    priority_queue<int> pq;
    int time=0;

    for(int i=0; i<a.size(); i++)
    {
        pq.push(a[i]);
    }

    for(int i=0;  i<a.size(); i++)
    {
        if(a[i]==pq.top() and i!=k)
        {
        // ticket given
            time++;
            pq.pop();
        }

        if(i==k)
        {
            // ticket given to me
            if(a[i]==pq.top())
            {
                time++;
                break;
            }
            else
            continue;
        }

        else if(a[i]<pq.top())
        {
            continue;
        }
    }
    return time;
}
int main()
{


// vector<int> a= {3,9,4};
vector<int> a= {2 ,3 ,2 ,2 ,4};
int k=3;

cout<<buyticket(a,k)<<"sec"<<endl;
return 0;
}