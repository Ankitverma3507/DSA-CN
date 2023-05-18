#include<iostream>
#include<stack>
#include <string.h>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack <char> s1;
    int count=0;
    
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(' or s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')
        {
            s1.push(s[i]);
        }
        else
        {
//        s[i] ya toh closing bracket hai ya phir lower case letter hai
            if(s[i]== ')')
            {
                bool isredundant=true;
              while(s1.top()!= '(')
              {
                  char top=s1.top();
                  if(top=='+' or top=='-' or top=='*' or top=='/')
                  {
                      isredundant=false;
                  }
                  s1.pop();
              }
                if(isredundant==true)
            return true;
            s1.pop();
            }
        }
    }
    return false;
 }

using namespace std;
int main()
{

return 0;
}