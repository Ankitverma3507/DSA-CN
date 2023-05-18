#include<iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack <char> s1;
        int len=s.length();
        int i=s[0];
        for(int i=0; i<len; i++)
        {
            if(s1.empty())
            {
                s1.push(s[i]);
            }
            else if(s1.top()=='(' && s[i]==')'||
            s1.top()=='[' && s[i]==']' || 
            s1.top()=='{' && s[i]=='}')
            {
                s1.pop();
            }
            else
            {
                s1.push(s[i]);
            }            
        }
        if(s1.empty())
        {return true;}
        else return false;
        
    }
};

int main()
{

return 0;
}