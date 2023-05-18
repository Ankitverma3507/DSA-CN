#include<iostream>
using namespace std;

int multiplication(int m , int n)
{
    
    if(n==0)
    return 0;
    

    else
    return m +  multiplication(m,n-1);


}






int main()
{
int m=3, n=5;
// cout<<"enter the numbers"<<endl;
// cin>>m>>n;

int result= multiplication(m,n);
cout<<"the result is "<<result<<endl;
return 0;
}