#include <iostream>
#include <string.h>
using namespace std;

bool check(string s)
{
    if (s[0] == 'a')
    {
        if (s[1] == 'a')
        {
            if(s[2]=='b'&& s[3]=='b')
            {return true;}
            else false;
        }

        else if(s[1]=='b' && s[2]=='b')
        {return true;}

        else false;
    }

    else
        return false;

    return check(s.substr(1));
}
int main()
{
    cout << check("aaabb");
    return 0;
}