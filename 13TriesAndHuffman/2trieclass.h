#include<iostream>
#include"1Trinode.h"
#include<string>
#include<vector>

using namespace std;
class Trie
{
    TriNode *root;

    public:
    Trie()
    {
        root= new TriNode('\0');
    }

    void insertWord(TriNode*root, string word)
    {
        // Base case
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        // small calc.
        int index= word[0]-'a';
        TriNode *child;
        if(root->children[index] != NULL)
        {
            child= root->children[index];
        }
        else
        child= new TriNode(word[0]);
        root->children[index]=child;

        // recursive call
        insertWord(child,word.substr(1));  //here we want our insert function to have child also so we willmake new helper function
    }


// this is helper function for user 
    void insertWord(string word)
    {
        insertWord(root,word);
    }


//////////////////------>Search


    bool searchWord(TriNode*root, string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }

        int index= word[0]-'a';
        if(root->children[index] != NULL)
        {
            return searchWord(root->children[index],word.substr(1));
        }

        else
        return false;
    }


    bool searchWord(string word)
    {
        return searchWord(root, word);
    }


    



//////////////////------>Remove
    void removeWord(TriNode *root, string word)
    {
        // base case
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }

        //small calc.
        int index= word[0]-'a';
        TriNode *child;
        if(root->children[index] != NULL)
        {
            child= root->children[index];
        }

        else
        // word not found
        return;

        removeWord(child,word.substr(1));

        // check root node if it is useless
        if(child->isTerminal==false)
        {
            for(int i=0; i<26; i++)
            {
                if(child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index]= NULL;
        }



    }

    void removeWord(string word)
    {
        removeWord(root,word);
        return;
    }
    


    bool patternMatching(vector<string> vect, string word)
{
    for(int i=0; i<vect.size(); i++)
    {
        while(vect[i] != "")
        {
            insertWord(vect[i]);
            vect[i]= vect[i].substr(1);
        }
    }

    return searchWord(word);
}

};