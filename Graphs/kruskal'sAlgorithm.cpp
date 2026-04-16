#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulpU=findParent(u),ulpV=findParent(v);
        if(ulpU==ulpV) return ; 
        if(rank[ulpV]>rank[ulpU]){
            parent[ulpU]=ulpV;
        }
        else if (rank[ulpU]>rank[ulpV]){
            parent[ulpV]=ulpU;
        }else{
            parent[ulpU]=ulpV;
            rank[ulpV]++;
        }
    }
};
int spanningTree(int n, vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            int nextNode=it[0];
            int wt=it[1];
            edges.push_back({wt,{i,nextNode}});
        }
    }
    sort(edges.begin(),edges.end());
    int mst=0;
    DisjointSet ds(n);

    for(auto it : edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findParent(u)!=ds.findParent(v)){
            mst+=wt;
        }
    }
    return mst;
}
int main(){

    return 0;
}