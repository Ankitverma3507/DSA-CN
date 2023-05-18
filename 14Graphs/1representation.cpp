#include<iostream>
#include<vector>
#include<queue>
using namespace std;
////////////////////////////////BFS Of Graphs\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

vector<int> bfsOfGraph(int nodes, vector<int> adj[])
{
    int vis[nodes]= {0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while(!q.empty())
    {
        int node= q.front();
        q.pop();

        bfs.push_back(node);

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;

}


////////////////////////////////DFS Of Graphs\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
class Solution {
    
    private:
    void dfs(int node, vector<int>adj[], int vis[], vector<int>&ls)
    {
       vis[node]=1;
       ls.push_back(node);
       
       for(auto it: adj[node])
       {
           if(!vis[it])
           {
               dfs(it,adj,vis,ls);
           }
       }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]= {0};
        int start=0;
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls;
    }
};



int main()
{
////////////////////////////////Mtrix Way Representation Of Graphs\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
int nodes, edges;
cin>>nodes>>edges;

int adj[nodes +1][nodes +1];

for(int i=0; i<edges; i++)
{
    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
}



////////////////////////////////List Way Representation Of Graphs\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
int nodes, edges;
cin>>nodes>>edges;

vector<int> adj1[nodes+1];  //this is array of vectors
for(int i=0; i<edges; i++)
{
    int u,v;
    cin>>u>>v;
    adj1[u].push_back(v);
    adj1[v].push_back(u);   //if this is the directed graphs then we dont need this line as v is only neighbour of u and vice a versa is not true.
}
return 0;
}