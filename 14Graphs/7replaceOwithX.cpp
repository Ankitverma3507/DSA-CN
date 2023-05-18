//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
private:
void dfs(int row, int col, vector<vector<char>>&mat, vector<vector<int>>&vis, int delrow[], int delcol[])
{
    vis[row][col]=1;
    
    int n= mat.size();
    int m= mat[0].size();
    
    for(int i=0; i<4; i++)
    {
        int nrow= row+ delrow[i];
        int ncol= col+ delcol[i];
        
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and mat[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,mat,vis,delrow,delcol);
        }
    }
    return;
}
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m,0));
        int delrow[]= {-1,0,+1,0};
        int delcol[]= {0,+1,0,-1};
        // for 1st row and last row
        for(int i=0; i<m; i++)
        {
            if(!vis[0][i] and mat[0][i]=='O')
            {
                dfs(0,i,mat,vis,delrow,delcol);
            }
            
            if(!vis[n-1][i] and mat[n-1][i]=='O')
            {
                dfs(n-1,i,mat,vis,delrow,delcol);
            }
        }
        
        // for 1st col and last col
        for(int j=0; j<n; j++)
        {
            if(!vis[j][0] and mat[j][0]=='O')
            {
                dfs(j,0,mat,vis,delrow,delcol);
            }
            
            if(!vis[j][m-1] and mat[j][m-1]=='O')
            {
                dfs(j,m-1,mat,vis,delrow,delcol);
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m;  j++)
            {
                if(!vis[i][j] and mat[i][j]=='O')
                {
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends














