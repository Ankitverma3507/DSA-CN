//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        queue<vector<string>>q;
        q.push({beginWord});
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level=0;
        vector<vector<string>>ans;
        
        while(!q.empty())
        {
            vector<string> vect= q.front();
            q.pop();
            
            if(vect.size()>level)
            {
                level++;
                for(auto it:usedOnLevel)
                {
                    st.erase(it);
                }
                
            }
            
            
            
            
            string word= vect.back();
            if(word==endWord)
            {
                if(ans.size()==0)
                {
                    ans.push_back(vect);
                }
                
                else if(ans[0].size()==vect.size())
                {
                    ans.push_back(vect);
                }
            }
            for(int i=0; i<word.size(); i++)
            {
                char org= word[i];
                for(char ch= 'a'; ch<='z'; ch++)
                {
                    word[i]=ch;
                    if(st.count(word)>0)
                    {
                        vect.push_back(word);
                        q.push(vect);
                        //mark as visited on the level
                        usedOnLevel.push_back(word);
                        
                        vect.pop_back();
                    }
                }
                word[i]=org;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends