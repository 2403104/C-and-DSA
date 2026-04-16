/*
Tree path query
*/
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
const int MAX=1e5+5;
vvi graph;
int n;
vi size,heavy, parent, depth;
vi head,linTree,pos;
int idx;
void dfs(int node){
    int maxSize=0;
    for(auto neb : graph[node]){
        if(neb==parent[node]) continue;
        depth[neb]=depth[node]+1;
        parent[neb]=node;
        dfs(neb);
        size[node]+=size[neb];
        if(size[neb]>maxSize){
            maxSize=size[neb];
            heavy[node]=neb;
        }
    }
}
void dfsHLD(int node, int chain){
    head[node]=chain;
    pos[node]=idx++;
    if(heavy[node]!=-1){//not a leaf node
        dfsHLD(heavy[node],chain);
    }
    for(int neb : graph[node]){
        if(heavy[node]==neb || parent[node]==neb) continue; 
        dfsHLD(neb,neb) ;
    }
}
int findLca(int u, int v){
    while(head[u]!=head[v]){//change path 
        if(depth[head[u]]<depth[head[v]]){
            v=parent[head[v]];
        }else{
            u=parent[head[u]];
        }
    }
    return depth[u]<depth[v]?u:v;//not head[u/v]
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif
    int m;//n nodes, m edges
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    size.resize(n+1,1);
    heavy.resize(n+1,-1);
    parent.resize(n+1,-1);
    depth.resize(n+1,0);
    head.resize(n+1);
    linTree.resize(n+1); 
    pos.resize(n+1);
    parent[1]=-1;
    depth[1]=0;
    idx=0;
    dfs(1);
    dfsHLD(1,1);
    //find Lca
    cout << "LCA of 4 and 5: " << findLca(4, 5) << endl;
    cout << "LCA of 4 and 6: " << findLca(4, 6) << endl;
    cout << "LCA of 6 and 7: " << findLca(6, 7) << endl;
    cout << "LCA of 2 and 7: " << findLca(2, 7) << endl;
    cout << "LCA of 5 and 3: " << findLca(5, 3) << endl;


    return 0;
}
/*
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

*/