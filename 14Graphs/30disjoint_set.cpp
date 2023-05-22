#include<bits/stdc++.h>
using namespace std;


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

int main()
{
    Disjoint ds(7);
    ds.unionbySize(1,2);
    ds.unionbySize(2,3);
    ds.unionbySize(4,5);
    ds.unionbySize(6,7);
    ds.unionbySize(5,6);

    if(ds.findUParent(3)== ds.findUParent(7)){cout<<"same";}
    else cout<<"not same";
    ds.unionbySize(3,7);
    if(ds.findUParent(3)== ds.findUParent(7)){cout<<"same";}
    else cout<<"not same";
    
    return 0;
}