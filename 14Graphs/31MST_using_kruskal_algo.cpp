//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint
{
    vector<int> rank, parent, size;

    public:
    Disjoint(int n)
    {
        rank.resize(n+1, 0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int findUParent(int node)
    {
        ///////////////////--------->>>>>>this is known as path compression
        if(node== parent[node])
        return node;

        else
        return parent[node]= findUParent(parent[node]);
    }


    void unionbyRank(int u, int v)
    {
        int ulp_u= parent[u];
        int ulp_v= parent[v];
        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]> rank[ulp_v])
        {
            parent[ulp_v]= ulp_u;
        }

        else if(rank[ulp_v]> rank[ulp_u])
        {
            parent[ulp_u]= ulp_v;
        }

        else
        {
            parent[ulp_v]= ulp_u;
            rank[ulp_u]++;
        }
    }


    void unionbySize(int u, int v)
    {
        int ulp_u= parent[u];
        int ulp_v= parent[v];
        if(ulp_u==ulp_v) return;

        if(size[ulp_u]< size[ulp_v])
        {
            parent[ulp_u]= ulp_v;
            size[ulp_v]+= size[ulp_u];
        }

        else
        {
            parent[ulp_v]= ulp_u;
            size[ulp_u]+= size[ulp_v];
        }



    }

};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        //kruskals algo
        
        vector<pair<int,pair<int,int>>> edges;
        //TC O(n+e)
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
            {
                int node= i;
                int wt= it[1];
                int adjnode= it[0];
                
                edges.push_back({wt,{node,adjnode}});
            }
        }
        Disjoint ds(V);
        //O(MlogM)
        sort(edges.begin(), edges.end());
        
        int mstWt= 0;
        //M x 4 x alphax2
        for(auto it: edges)
        {
            int wt= it.first;
            int u= it.second.first;
            int v= it.second.second;
            
            if(ds.findUParent(u) != ds.findUParent(v))
            {
                mstWt += wt;
                ds.unionbySize(u,v);
            }
        }
        
        return mstWt;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // priority_queue<pair<int,pair<int,int>>, 
        // vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        // vector<int> vis(V,0);
        // vector<pair<int,int>> mst;
        // int sum=0;
        // pq.push({0,{0,-1}});
        
        // while(!pq.empty())
        // {
        //     auto it= pq.top();
        //     int wt= it.first;
        //     int node= it.second.first;
        //     int parent= it.second.second;
        //     pq.pop();
            
        //     if(vis[node]==1) continue;
        //     vis[node]=1;
        //     sum += wt;
        //     mst.push_back({parent,node});
            
        //     for(auto it: adj[node])
        //     {
        //         int adjwt= it[1];
        //         int adjnode= it[0];
        //         if(!vis[adjnode])
        //         {
        //             pq.push({adjwt,{adjnode,node}});
        //         }
        //     }
        // }
        
        // return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends