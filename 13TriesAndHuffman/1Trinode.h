#include<iostream>

using namespace std;
class TriNode
{
    public:
    char data;
    TriNode ** children;
    bool isTerminal;

    TriNode(char data)
    {
        this->data= data;
        children= new TriNode*[26];   //here we are assuming that only lower case alphabets will be insert into trie and
        for(int i=0 ; i<26; i++)               //at 0th index we will store a and so on.
        {
            children[i]= NULL;
        }
        isTerminal=false;
    }
};