#include<iostream>
using namespace std;

string removex(string s, char x)
{
    if(s.length()==0)
    {return " ";}

    else if(s[0]==x)
    {return removex(s.substr(1),x);}

    return s[0]+removex(s.substr(1), x); 
}
int main()
{
cout<<"modified string is "<<removex("xxabxx", 'x');
return 0;
}