#include<iostream>
#include <stack>
using namespace std;

int countRev (string s)
{
    // your code here
    stack <char> st;
    int count=0;
    if(s.length()%2==0)
    {
        for (int i=0; i<s.length(); i++)
        {
            if(s[i]=='{')
            {
                st.push(s[i]);
            }
            
            else
            {
                if(st.empty())
                {st.push(s[i]);}
                
                else if (!st.empty() and st.top()=='{')
                {st.pop();}
                
                else if (!st.empty() and st.top()=='}')
                {st.push(s[i]);}
                
               
            }
             
        }
        
        while(!st.empty())
        {
        char c1=st.top();
                st.pop();
                char c2= st.top();
                st.pop();
                if(c1==c2)
                {
                    count++;
                }
                else 
                {
                    count=count+2;
                }
        }
        return count;
    }
    else 
    {return -1;}
}
int main()
{

return 0;
}