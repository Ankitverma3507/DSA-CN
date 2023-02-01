#include<iostream>
#include<string.h>
using namespace std;
bool helper(string s, int start, int end)
{
    if(start>=end)
    {return true;}

    if(s[start]!=s[end])
    {return false;}

    return helper(s, start+1, end-1);
}

bool isPalindrome(string s)
{
    return helper(s,0, s.size()-1);
}
using namespace std;
int main()
{
cout<<isPalindrome("mooom");
return 0;
}