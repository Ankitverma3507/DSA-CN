#include<iostream>
#include<queue>
void copy(queue <int> &q, stack <int> &s1)
{
   while(!q.empty())
   {
    int a = q.front();
       q.pop();
    s1.push(a);
   }
    
}
void reverse(queue < int > & q) {
    // Write your code here.
       stack <int> s1;
       copy(q,s1);
    
    while(!s1.empty())
        
    {
        int ans=s1.top();
        s1.pop();
        q.push(ans);
    }
    
}
using namespace std;
int main()
{

return 0;
}