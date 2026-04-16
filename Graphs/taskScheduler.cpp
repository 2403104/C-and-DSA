# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;
// class Solution {
//     public:
//         bool dfs(int node, vector<bool>& vis, vector<bool>& cycle, vector<int> adj[]) {
//             if (cycle[node]) return true; // Cycle detected
//             if (vis[node]) return false;  // Already processed
    
//             vis[node] = true;
//             cycle[node] = true;
    
//             for (auto ch : adj[node]) {
//                 if (dfs(ch, vis, cycle, adj)) return true; // If cycle found, return true
//             }
    
//             cycle[node] = false; // Backtrack
//             return false;
//         } 
    
//         bool canFinish(int n, vector<vector<int>>& preq) {
//             vector<int> adj[n];
//             for (auto& i : preq) {
//                 adj[i[1]].push_back(i[0]); // Reverse dependency graph
//             }

//             vector<bool> vis(n, false);
//             vector<bool> cycle(n, false);
    
//             for (int i = 0; i < n; i++) {
//                 if (!vis[i] && dfs(i, vis, cycle, adj)) {
//                     return false; // Cycle detected
//                 }
//             }
//             return true; // No cycle found, courses can be finished
//         }
//     };
vector<int> topologicalSort(int n, vector<vector<int>>adj){
    vector<int>indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto it : adj[i]) indeg[it]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++) {
        if(indeg[i]==0) q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    return ans;
}
bool canPerform(int n , vector<pair<int,int>>&preq){
    vector<vector<int>>adj(n);
    for(auto it : preq){
        adj[it.first].push_back(it.second);
    }

    vector<int>topo=topologicalSort(n,adj);
    return topo.size()==n;

}
int main(){

    return 0;
}