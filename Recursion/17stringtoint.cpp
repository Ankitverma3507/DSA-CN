#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int convert(string s)
{
    if(s.length()==0)
    {return 0;}

    double b= s[0]-48;
    double smallerstr= convert(s.substr(1));
    b= smallerstr + (b* pow(10, s.length()-1));
    return int(b);

}
int main()
{
cout<<"string to integer is "<<convert("012337887")<<endl;
return 0;
}