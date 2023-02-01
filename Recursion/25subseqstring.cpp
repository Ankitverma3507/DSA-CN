#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int subseq(string s, string output[])
{
    if(s.length()==0)
    {output[0]=" "; 
        return 1;}

        int size=subseq(s.substr(1), output);
        for(int i=0; i<size; i++)
        {
            output[i+size]=s[0]+output[i];
        }
        return 2*size;
        
}
int main()
{

string s;
// getline(cin,s);
cin>>s;
int len= s.size();
int arrsize=pow(2,len);
string *output = new string[arrsize];
int count=subseq(s,output);
for(int i=0; i<count; i++)
{
    cout<<output[i]<<endl;
}
return 0;
}