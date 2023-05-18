#include<iostream>
#include<string.h>
using namespace std;

// void replacechar(string  *s, char org, char rep)
// {
//     if((*s).length()==1)
//     {if(s[0]== org)
//     {
        
//         s[0]=rep;
//     }
//         return;}

    
        
//         replacechar((*s)[].substr(1), org, rep);


// }
void replacechar(char s[], char org, char rep)
{
    if(s[0]=='\0')
    {return;}

    if(s[0]== org)
    {
        
        s[0]=rep;
    }
        
        replacechar(s+1, org, rep);


}

int main()
{
// string s= "hello";
// replacechar(&s,'l', 'w');
// cout<<s<<endl;
char s[]= {"hello"};
replacechar(s,'l', 'w');
cout<<s<<endl;
return 0;
}