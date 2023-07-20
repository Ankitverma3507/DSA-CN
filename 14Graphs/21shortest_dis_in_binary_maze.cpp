//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> destination)
    {
        // code here
        if (src.first == destination.first && src.second == destination.second)
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        int dist[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dist[i][j] = 1e9;
            }
        }

        dist[src.first][src.second] = 0;
        q.push({0, {src.first, src.second}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int lvl = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1 and
                    dist[nrow][ncol] > lvl + 1)
                {
                    dist[nrow][ncol] = lvl + 1;
                    if (nrow == destination.first and ncol == destination.second)
                        return lvl + 1;
                    q.push({lvl + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends







