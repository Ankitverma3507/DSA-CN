#include<iostream>
#include<string.h>
using namespace std;

void duplicate(char s[])
{
    if(s[0]=='\0')
    {return;}

    if(s[0]!=s[1]){duplicate(s+1);}
    else
    {
        int i=1;
        for(; s[i]!='\0'; i++)
        {
            s[i-1]= s[i];
        }
        s[i-1]=s[i];
        duplicate(s);
    }
    
}
int main()
{
    char s[]= {"aabbbcddett"};
    duplicate(s);
    cout<<s<<endl;

return 0;
}