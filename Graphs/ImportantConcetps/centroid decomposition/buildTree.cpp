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
            depth[it] = depth[node] + 1;
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
    for(int i = 0; i < LOG; i ++){
        if(jump >= (1 << i)){
            node = up[node][i];
            jump -= (1 << i);
        }
    }
    return node;
}
int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    u = lift(u, abs(depth[u] - depth[v]));
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
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
void solve(){
    int n, x, y; cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    memset(depth, 0, sizeof(depth));
    binaryLifting(1, -1);
    decompose(1, -1);
    memset(redNodeDist, 0x3f, sizeof(redNodeDist));

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}








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
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<vi> vvi;

const int SIZE = 1e5 + 5;
const int LOG = 20;
const int BIG = 1e9;

int subSize[SIZE];
int parent[SIZE];
set<int> graph[SIZE]; // adjacency as set for fast erase
int up[SIZE][LOG];
int depth[SIZE];
int redNodeDist[SIZE];

// Calculate subtree sizes and depth
int dfs_size(int node, int par) {
    subSize[node] = 1;
    for (auto &it : graph[node]) {
        if (it != par) {
            depth[it] = depth[node] + 1;
            subSize[node] += dfs_size(it, node);
        }
    }
    return subSize[node];
}

// Find centroid of current subtree
int dfs_centroid(int node, int par, int n) {
    for (auto &it : graph[node]) {
        if (it != par && subSize[it] > n / 2) {
            return dfs_centroid(it, node, n);
        }
    }
    return node;
}

// Decompose tree into centroid tree
void decompose(int node, int par) {
    int subTreeSize = dfs_size(node, -1);
    int centroid = dfs_centroid(node, -1, subTreeSize);
    parent[centroid] = par;

    vector<int> toRecurse;
    for (auto &it : graph[centroid]) {
        toRecurse.push_back(it);
        graph[it].erase(centroid);
    }
    graph[centroid].clear();

    for (auto &it : toRecurse) {
        decompose(it, centroid);
    }
}

// Binary lifting preprocessing for LCA
void binaryLifting(int src, int par) {
    up[src][0] = par;
    for (int i = 1; i < LOG; i++) {
        if (up[src][i - 1] != -1) {
            up[src][i] = up[up[src][i - 1]][i - 1];
        } else {
            up[src][i] = -1;
        }
    }
    for (auto &it : graph[src]) {
        if (it != par) {
            binaryLifting(it, src);
        }
    }
}

// Lift node by jump steps upwards
int lift(int node, int jump) {
    for (int i = 0; i < LOG && node != -1; i++) {
        if (jump & (1 << i)) {
            node = up[node][i];
        }
    }
    return node;
}

// Lowest Common Ancestor
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != -1 && up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

// Distance between two nodes
int findDist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

// Update function for red nodes
void update(int node) {
    int curr = node;
    while (curr != -1) {
        redNodeDist[curr] = min(redNodeDist[curr], findDist(curr, node));
        curr = parent[curr];
    }
}

// Query function to find closest red node distance
int query(int node) {
    int curr = node;
    int ans = BIG;
    while (curr != -1) {
        ans = min(ans, redNodeDist[curr] + findDist(node, curr));
        curr = parent[curr];
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) graph[i].clear();
    memset(depth, 0, sizeof(depth));
    memset(up, -1, sizeof(up));
    memset(parent, -1, sizeof(parent));
    memset(redNodeDist, 0x3f, sizeof(redNodeDist));

    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    // Preprocessing for LCA - need actual tree edges, not centroid tree
    // So build a separate adjacency for LCA or use graph directly before decomposition
    // Let's keep graph as it is and build LCA before decomposition

    // We need to create a separate adjacency for LCA since graph will be modified by decomposition
    // So let's copy graph into another adjacency list for LCA:

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto &v : graph[i]) {
            adj[i].push_back(v);
        }
    }

    // Build LCA on original tree
    // So override graph to be the original adjacency before decomposition for LCA purpose
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        for (auto &v : adj[i]) graph[i].insert(v);
    }

    // Run dfs_size to get depths
    depth[1] = 0;
    dfs_size(1, -1);

    binaryLifting(1, -1);

    // Now decompose on original graph
    decompose(1, -1);

    // Initially, node 1 is red
    update(1);

    for (int i = 0; i < m; i++) {
        int t, v; cin >> t >> v;
        if (t == 1) {
            update(v);
        } else {
            cout << query(v) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
