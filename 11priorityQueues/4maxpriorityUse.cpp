#include<iostream>
#include"3MaxPriorityqueue.h"
using namespace std;
int main()
{

Maxpriorityqueu  p;
p.insert(100);
p.insert(10);
p.insert(15);
p.insert(4);
p.insert(17);
p.insert(21);
p.insert(67);

cout<<p.getSize()<<endl;
cout<<p.getMax()<<endl;

while(!p.isEmpty())
{
    cout<<p.removeMax()<<" ";
}
cout<<endl; 
return 0;
}