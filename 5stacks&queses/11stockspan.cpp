#include<iostream>
#include <stack>

using namespace std;
int* stockSpan(int *price, int size)  {
	// Write your code here
    int *output= new int[size];
    stack <int> s;
    s.push(0);
    output[0]=1;
    for (int i=1; i<size; i++)
    {

        while(!s.empty() && price[s.top()]<price[i])
        {
            s.pop();
        }
        if(s.empty ())
        {
            output[i]=i+1;
        }
        else
            output[i]= i-s.top();
        s.push(i);
    }
    return output;
}
int main()
{

return 0;
}