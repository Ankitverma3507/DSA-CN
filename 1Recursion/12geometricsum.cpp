#include<iostream>
#include<math.h>
using namespace std;

float geo(int k)
{
    if ((k==0))
    {return 1;}

    return geo(k-1) + 1/pow(2,k);
    
}
int main()
{
    cout<<"result is "<<geo(3)<<endl;

return 0;
}