//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n= heights.size();
        int m= heights[0].size();
        int dist[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dist[i][j]=1e9;
            }
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty())
        {
            auto it= pq.top();
            int diff= it.first;
            int r= it.second.first;
            int c= it.second.second;
            pq.pop();
            
            if(r==n-1 and c== m-1) return diff;
            
            for(int i=0; i<4; i++)
            {
                int nrow=r+delrow[i];
                int ncol= c+delcol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m )
                {
                    int maxi= max(diff, abs(heights[r][c]-heights[nrow][ncol]));
                    if(maxi<dist[nrow][ncol])
                    {
                        dist[nrow][ncol]=maxi;
                        pq.push({maxi,{nrow,ncol}});
                    }
                }
            }
            
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends