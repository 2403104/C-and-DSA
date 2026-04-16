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
vvi graph;
vi parent;
void assignParent(int node, int par){
    parent[node]=par;
    for(auto c : graph[node]){
        if(c==par) continue;
        assignParent(c,node);
    }
}
void reroot(int oldRoot,int newRoot){
    assignParent(oldRoot,-1);
    int curr=newRoot;
    while(curr!=-1){
        int par=parent[curr];
        if(par!=-1){
            graph[par].erase(remove(graph[par].begin(),graph[par].end(),curr),graph[par].end());
            graph[curr].push_back(par);
        }
        curr=par;
    }
}
void printTree(int node, int par,vb &vis) {
    cout << "Parent of " << node << " is " << par << "\n";
    vis[node]=true;
    for (int child : graph[node]) {
        if (!vis[child])
            printTree(child, node,vis);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    int n,m;
    cin>>n>>m;
    graph.resize(n);
    parent.resize(n);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int oldRoot = 0;
    int newRoot;
    cin >> newRoot;

    reroot(oldRoot, newRoot);
    vb vis(n,false);
    cout << "Tree after rerooting at " << newRoot << ":\n";
    printTree(newRoot, -1,vis);

    return 0;
}