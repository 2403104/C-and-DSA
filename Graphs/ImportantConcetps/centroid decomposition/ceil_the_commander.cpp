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
const int SIZE = 1e5+5;
set<int> graph[SIZE];
int subSize[SIZE];
int parent[SIZE];
set<int> centroid_tree[SIZE];
int dfs_size(int node, int par){
    subSize[node] = 1;
    for(auto &it : graph[node]){
        if(it != par){            
            subSize[node] += dfs_size(it, node);
            // depth[it] = depth[node] + 1;
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
    if(par != -1) {
        centroid_tree[par].insert(centroid);
        centroid_tree[centroid].insert(par);
    }    
    for(auto &it : graph[centroid]){
        graph[it].erase(centroid);
        decompose(it, centroid);
    }
}
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int u, v; cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    decompose(1, -1);
    vector<char> ans(n+1);
    // vi indeg(n+1 , 0);
    int root = -1;
    for(int i = 1; i<= n;i++){
        if(parent[i] == -1){
            root = i;
            break;
        }
    }
    queue<int>q;
    q.push(root);
    char st = 'A';
    while(!q.empty()){
        int t = q.size();
        for(int i = 0; i < t; i++){
            int nd = q.front(); q.pop();
            ans[nd] = st;
            for(auto &it : centroid_tree[nd]){
                if(it == parent[nd]) continue;
                q.push(it);
            }
        }
        st++;
    }
    for(int i = 1; i<= n;i++){
        cout << ans[i] << ' ';
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}