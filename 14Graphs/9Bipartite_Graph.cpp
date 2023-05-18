//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
////////////////////////////------------>>>>>>>>>>>>>BY BFS///////////////////////////
// } Driver Code Ends
class Solution
{

private:
    bool check(int start, int V, vector<int> adj[], int colored[])
    {
        queue<int> q;
        q.push(start);
        colored[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (colored[it] == -1)
                {
                    colored[it] = !colored[node];
                    q.push(it);
                }
                else if (colored[it] == colored[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        int colored[V];
        for (int i = 0; i < V; i++)
            colored[i] = -1;
        for (int i = 0; i < V; i++)
        {
            if (colored[i] == -1)
            {
                if (check(i, V, adj, colored) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

////////////////////////////------------>>>>>>>>>>>>>BY DFS///////////////////////////

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool dfs(int start, int colr, vector<int> adj[], int color[], int V)
    {
        color[start] = colr;
        for (auto it : adj[start])
        {
            if (color[it] == -1)
            {
                if (dfs(it, !colr, adj, color, V) == false)
                    return false;
            }

            else if (color[it] == colr)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, adj, color, V) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends