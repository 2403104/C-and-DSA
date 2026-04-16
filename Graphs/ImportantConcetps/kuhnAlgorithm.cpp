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
int n, m; 
vvi graph;
vb vis;
vi occupName;
bool DFS(int node){
    for(int i = 0; i < graph[node].size(); i++){
        if(graph[node][i] && !vis[i]){
            vis[i] = true;
            if(occupName[i] == -1 || DFS(occupName[i])){
                occupName[i] = node;
                return true;
            }
        }
    }
    return false;
}
void solve(){
    cin >> n >> m;
    graph.resize(n, vi(m));;
    for(auto &it : graph) input(it);
    int mx = max(n, m);
    vis.resize(mx, false);
    occupName.resize(mx,-1);
    int ans = 0;
    for(int i = 0; i < m; i ++){
        if(DFS(i)) ans++;
    }
    cout << ans << endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}