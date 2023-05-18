#include<iostream>
using namespace std;

void towerofhanoi(int disc, char src, char dest, char help)
{
    if(disc==0)
    {return;}

    towerofhanoi(disc-1, src, help,dest);
    cout<<"move from "<<src<<" to "<<dest<<endl;
    towerofhanoi(disc-1, help,dest,src);
}
int main()
{
towerofhanoi(4,'A', 'C', 'B');
return 0;
}