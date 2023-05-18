//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>>q;
        int vis[n][m]= {0};
        
        for(int i=0; i<n; i++)
        {
            
            for(int j=0; j<m; j++)
            {
                if(i==0 or j==0 or i==n-1 or j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        
        
        int delrow[]={-1,0,+1,0};
        int delcol[]= {0,+1,0,-1};
        
        while(!q.empty())
        {
            int one= q.front().first;
            int second= q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow= one+ delrow[i];
                int ncol= second+ delcol[i];
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1 
                and vis[nrow][ncol]==0)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    
                }
            }
            
            
        }
        
        int cnt=0; 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends