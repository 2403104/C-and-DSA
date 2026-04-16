/*
valid only for directed graph
Strongly Connected Components (SCC) – Theory

A Strongly Connected Component of a directed graph is a maximal subset of vertices such that every vertex is reachable from every other vertex in the subset.

Formally, a directed graph G = (V, E) is strongly connected if for every pair of vertices u and v, there is:

* a path from u to v, and
* a path from v to u.

A graph may have multiple SCCs, and each node belongs to exactly one SCC.

Applications of SCCs:

* Analyzing networks (e.g., social networks, control flow in programs)
* Optimizing compilers (e.g., for detecting unreachable code)
* Solving 2-SAT problems

Algorithms to Find SCCs:

1. **Kosaraju's Algorithm** (Time Complexity: O(V + E))

   * Step 1: Do a DFS to get the finish time order of nodes (push to stack).
   * Step 2: Transpose the graph (reverse all edges).
   * Step 3: Do DFS in the order of decreasing finish time on the transposed graph. Each DFS tree gives one SCC.

2. **Tarjan's Algorithm** (Time Complexity: O(V + E))

   * Uses a single DFS.
   * Maintains an index and low-link value for each node.
   * When a node's low-link equals its index, it is the root of an SCC.
   * Uses a stack to track the current path.

3. **Kosaraju vs. Tarjan**

   * Kosaraju is easier to implement conceptually.
   * Tarjan is more efficient in practice due to a single DFS pass.

Example Use-case:
If you want to find all parts of a system where every component is mutually dependent on each other, SCCs are the perfect tool.

*/
#include <bits/stdc++.h>
using namespace std;

//USING KOSARAJU METHOD
class Solution {
public:
    void dfs1(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it])
                dfs1(it, adj, vis, st);
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& vis){
        vis[node] = true;
        for(auto it : revAdj[node]){
            if(!vis[it])
                dfs2(it, revAdj, vis);
        }
    }

    int kosaraju(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(!vis[i]) dfs1(i, adj, vis, st);
        }

        vector<vector<int>> revAdj(n);
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                revAdj[it].push_back(i);
            }
        }

        fill(vis.begin(), vis.end(), false);
        int sccCount = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                sccCount++;
                dfs2(node, revAdj, vis);
            }
        }

        return sccCount;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution sol;
    cout << sol.kosaraju(adj) << "\n";

    return 0;
}
