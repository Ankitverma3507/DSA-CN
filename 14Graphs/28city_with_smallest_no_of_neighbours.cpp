//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges,
                 int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][via] == INT_MAX or dist[via][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int cntmax = n;
        int cityno = -1;

        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[city][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if (cnt <= cntmax)
            {
                cntmax = cnt;
                cityno = city;
            }
        }
        return cityno;
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
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends