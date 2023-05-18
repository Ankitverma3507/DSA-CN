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