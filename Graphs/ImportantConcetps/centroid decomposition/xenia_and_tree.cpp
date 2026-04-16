#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define m1 cout << "-1" << endl
#define input(arr) for(auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<vi> vvi;
const int SIZE = 1e5 + 5;
const int LOG = 20;
const int BIG = 1e8;
int subSize[SIZE];
int parent[SIZE];
set<int> graph[SIZE]; // using set , needed to remove certain edges and set will give the compleixty of log(n) while the arr will givec t he complexity of O(n)
int up[SIZE][LOG];
int depth[SIZE];
int redNodeDist[SIZE];

int dfs_size(int node, int par){
    subSize[node] = 1;
    for(auto &it : graph[node]){
        if(it != par){ 
            subSize[node] += dfs_size(it, node);
        }
    }
    return subSize[node];
}
int dfs_centroid(int node, int par, int n){
    for(auto &it : graph[node]){
        if(it != par  && subSize[it] > n / 2) {
            return dfs_centroid(it, node, n);
        }
    }
    return node;
}
void decompose(int node, int par){
    int subTreeSize = dfs_size(node, -1);
    int centroid = dfs_centroid(node, par, subTreeSize);

    parent[centroid] = par;
    for(auto &it : graph[centroid]){
        graph[it].erase(centroid);
        decompose(it, centroid);
    }
    graph[centroid].clear();
}

// UPDATES AND QUERIES
void binaryLifting(int src, int par){
    up[src][0] = par;
    for(int i = 1; i < LOG; i ++){
        if(up[src][i - 1] != -1){
            up[src][i] = up[up[src][i-1]] [i-1];
        }else{
            up[src][i] = -1;
        }
    }
    for(auto &it : graph[src]){
        if(it != par){
            binaryLifting(it, src);
        }
    }
}
int lift(int node, int jump){
    for(int i = 0; i < LOG  && node != -1; i ++){
        if(jump & (1 << i)){
            node = up[node][i];
            jump -= (1 << i);
        }
    }
    return node;
}
int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != -1 && up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
int findDist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
void update(int node){
    int curr = node;
    while(curr != -1){
        redNodeDist[curr] = min(redNodeDist[curr], findDist(curr, node));
        curr = parent[curr];
    }
}
int query(int node){
    int curr = node;
    int ans = BIG;
    while(curr != -1){
        ans = min(ans, redNodeDist[curr] + findDist(node, curr));
        curr = parent[curr];
    }
    return ans;
}
void dfs_depth(int node, int par) {
    for (auto &it : graph[node]) {
        if (it != par) {
            depth[it] = depth[node] + 1;
            dfs_depth(it, node);
        }
    }
}

void solve(){
    int n,m, x, y; cin >> n >> m;
    for(int i = 1; i<= n;i++){
        graph[i].clear();
    }
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    memset(depth, 0, sizeof(depth));
    memset(up, -1, sizeof(up));
    memset(redNodeDist, 0x3f, sizeof(redNodeDist));
    memset(parent, -1 , sizeof(parent));

    depth[1] = 0;
    dfs_depth(1, -1);

    binaryLifting(1, -1);

    decompose(1, -1);

    update(1);

    for(int i = 0; i < m; i++){
        int t, v; cin >> t >> v;
        if(t == 1){
            update(v);
        }else{
            cout << query(v) << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}