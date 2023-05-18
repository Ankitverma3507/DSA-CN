#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string word)
{
    int len=word.length();

    for(int i=0; i<len/2; i++)
    {
        if(word[i] != word[len-i-1])
        return false;
    }

    return true;
}

bool palindromePair(vector<string> vect)
{
    for(int i=0; i<vect.size(); i++)
    {
        for(int j=i+1; j<vect.size() ; j++)
        {
            string chk_string= vect[i] + vect[j];

            if(isPalindrome(chk_string))
            return true;

            chk_string= vect[j] + vect[i];
            if(isPalindrome(chk_string))
            return true;
        }
    }
    return false;
}
int main()
{

    // vector<string> vect= {"abc", "def", "ghi",  "cba"};
    vector<string> vect= {"abc" ,"def"};

    cout<<palindromePair(vect);

return 0;
}