#include<iostream>
#include<string.h>
using namespace std;

void helper(char s[], int start)
{
    if(s[start]=='\0')
    {return ;}



    if(s[start]==s[start+1])
    {
        for(int i=strlen(s); i>=start+1; i-- )
        {
            s[i]=s[i-1];

            s[i]='*';
        }
        
    } 

    helper(s+1, start);

}

void pairstar(char s[])
{
    helper( s,0);
}
int main()
{
    char s[]={"hello"};
pairstar(s);
cout<<s<<endl;
return 0;
}