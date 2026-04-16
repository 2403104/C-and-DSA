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
const int SZ = 2e5+5;
ll values[SZ];
vector<int>graph[SZ];
ll seg[4*SZ];
ll subSize[SZ];
ll inTime[SZ];
ll inNode[SZ];
int timer = 0;
void dfs(int node, int par){
    subSize[node] = 1;
    inTime[node] = timer++;
    inNode[inTime[node]] = values[node];
    for(auto &it : graph[node]){
        if(it == par) continue;
        dfs(it, node);
        subSize[node] += subSize[it];
    }
}
 
void build(int idx, int l, int r){
    if(l == r){
        seg[idx] = inNode[l];
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2 + 1, l, mid);
    build(idx * 2 + 2, mid + 1, r);
    seg[idx] = seg[idx * 2 + 1] + seg[idx *  2 + 2];
}
 
void update(int idx, int l, int r, int pos, ll val) {
    if (l == r) {
        seg[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(idx * 2 + 1, l, mid, pos, val);
    else
        update(idx * 2 + 2, mid + 1, r, pos, val);
 
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
}
 
ll query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return seg[idx];
 
    int mid = (l + r) / 2;
    return query(idx * 2 + 1, l, mid, ql, qr) +
           query(idx * 2 + 2, mid + 1, r, ql, qr);
}
 
void solve(){
    int n,q ; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> values[i];
    for(int i = 0; i < n - 1; i ++){
        int u, v; cin >> u >> v; u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, -1);
    build(0, 0, n - 1);
    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int node; ll val;
            cin >> node >> val; node--;
            update(0, 0, n - 1, inTime[node], val);
            inNode[inTime[node]] = val;
        } else {
            int node; cin >> node; node--;
            int l = inTime[node];
            int r = inTime[node] + subSize[node] - 1;
            cout << query(0, 0, n - 1, l, r) << endl;
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
