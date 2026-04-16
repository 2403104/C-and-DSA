#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;

/*
SPANNING TREE
tree that includes all the vertices of the graph 
acyclic
connected 
with exactly v-1 edges, v=no of vertices
all nodes are reachable from each node

A Minimum Spanning Tree (MST) of a connected, weighted, undirected graph is:
A spanning tree (i.e., connects all vertices without cycles) with the minimum possible 
total edge weight.(tree with least sum of edge weight)
*/
class DisjointSet{
    vi rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        rep(i,0,n) parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulpu=findParent(u);
        int ulpv=findParent(v);
        if(ulpu==ulpv) return;
        if(rank[ulpu]>rank[ulpv]){
            parent[ulpv]=ulpu;
        }else if(rank[ulpu]<rank[ulpv]){
            parent[ulpu]=ulpv;
        }else{
            parent[ulpv]=ulpu;
            rank[ulpu]++;
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
    int mst=0;
    DisjointSet ds(n);
    sort(all(edges));
    for(auto it : edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findParent(u)!=ds.findParent(v)){
            ds.unionByRank(u,v);
            mst+=wt;
        }
    }
    return mst;
}
int spanningTree(int n, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n, 0);
    int sum = 0;
    pq.push({0, 0});  // {weight, node}
        
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if (vis[node]) continue;
        
        // Add to the MST
        vis[node] = true;
        sum += wt;
        
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWt = it[1]; 
            if (!vis[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int n = 4;
    vector<vector<int>> adj[n];
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});
    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 3});
    adj[3].push_back({1, 3});
    adj[2].push_back({3, 5});
    adj[3].push_back({2, 5});

    cout << "MST Weight: " << spanningTree(n, adj) << endl;
    return 0;
}
