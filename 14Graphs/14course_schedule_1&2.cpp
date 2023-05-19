//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
///////////////////////////////////////---------->course schedule1/////////////////
class Solution
{
public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> adj[N];

        for (auto it : prerequisites)
        {
            adj[it.first].push_back(it.second);
            // adj[it.second].push_back(it.first);////this is commented coz this is directed graph so we have only
            // one way direction.
        }

        int indegree[N] = {0};
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[front])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (cnt == N)
            return true;
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        // if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        // else
            cout << "No";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

///////////////////////////////////////---------->course schedule2/////////////////

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
    {
        vector<int> adj[V];
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            topo.push_back(front);
            for (auto it : adj[front])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (topo.size() == V)
            return topo;
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            prerequisites.push_back({u, v});
        }

        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);

        Solution obj;
        vector<int> res = obj.findOrder(n, m, prerequisites);
        if (!res.size())
            cout << "No Ordering Possible" << endl;
        else
            cout << check(n, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends
