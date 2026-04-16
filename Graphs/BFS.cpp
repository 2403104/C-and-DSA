// Breadth-First Search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
// It starts at the tree root (or an arbitrary node of a graph, sometimes referred to as a 'search key'), 
// and explores the neighbor nodes at the present depth prior to moving on to nodes at the next depth level.

// The following code demonstrates the BFS algorithm in C++:


#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n , vector<int>adj[]){
    vector<int>vis(n,0);
    vector<int>ans;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            queue<int>q;
            vis[i]=1;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
    }

    return ans;
}

const int N=1e5+2;
vector<int>adj[N];
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans=bfs(n,adj);
    // vector<int>ans=dfsOfGraph(n,adj);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}













// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <map>
// #include <unordered_map>
// #include <queue>
// #include <stack>
// using namespace std;

// #define vi vector<int>;
// #define pii pair<int, int>
// #define vii vector<pii>
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define ff first
// #define ss second

// const int N = 1e5 + 2;
// bool vis[N]; // visited
// vector<int> adj[N];

// int main()
// {

//     for (int i = 0; i < N; i++)
//     {
//         vis[i] = 0;
//     }
//     int n, m;
//     cin >> n >> m;
//     int x, y;

//     for (int i = 0; i < m; i++)
//     {
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     queue<int> q;
//     q.push(1);
//     vis[1] = true;
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();

//         cout << node << " ";

//         vector<int>::iterator it;
//         for (it = adj[node].begin(); it != adj[node].end(); it++)
//         {
//             if (!vis[*it])
//             {
//                 vis[*it] = 1;
//                 q.push(*it);
//             }
//         }
//     }


//     return 0;
// }
