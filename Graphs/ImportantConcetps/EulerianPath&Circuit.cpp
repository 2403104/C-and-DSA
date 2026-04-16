#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define m1 cout << "-1" << endl
#define nline cout <<'\n'
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)     \
    for (auto it : arr) \
        cout << it << " ";\
        cout<<endl;
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
/*
A graph is said to be Eulerian if it contains an Eulerian Cycle, a cycle that visits 
every edge exactly once and starts and ends at the same vertex.

If a graph contains an Eulerian Path, a path that visits every edge exactly once but 
starts and ends at different vertices, it is called Semi-Eulerian.

A graph is called eulerian path if and only if both two conditions are true:
(1). All vertices with non zero indegree must belong to the same component
(2). Exactly two or zero vertices with odd degrees
    - if zero then a eulerian circuit exist
    - if two then eulerian path exists
    - Not possible
*/

void dfs(int node, vb &vis, vvi &adj){
    vis[node] = true;
    for(auto &it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
}

int isEulerian_UNDIRECTED(int n, vvi & adj){
    vb vis(n,false);
    int st = -1;
    for(int i = 0; i < n; i++){
        if(adj[i].size()>0){
            st = i;
            break;
        }
    }
    if(st == -1){
        return 2;// not possible
    }
    dfs(st, vis, adj);
    for(int i = 0; i < n; i++){
        if(adj[i].size()>0 && !vis[i]) return 0; // not connected
    }
    int odd = 0;
    for(int i = 0; i < n; i ++){
        if(adj[i].size()%2) odd++;
    }
    if(odd > 2 || odd == 1) return 0;
    else if(odd == 2) return 1; // eulerian path exist
    else if (odd == 0) return 1; // eulerian cicuit exist
    
}
void solve(){
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}