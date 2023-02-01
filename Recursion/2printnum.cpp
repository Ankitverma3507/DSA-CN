#include<iostream>
using namespace std;

void printnum(int n)
{
    if(n>1)
    printnum(n-1);
    cout<<n<<" ";
}
int  main()
{
    int n=10;
    // cout<<"enter the number"<<endl;
    // cin>>n;
    printnum(n);


    return 0;
}